/*
 * WIN32 clipboard implementation
 *
 * Copyright 1994 Martin Ayotte
 *	     1996 Alex Korobka
 *	     1999 Noel Borthwick
 *	     2003 Ulrich Czekalla for CodeWeavers
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 *
 * NOTES:
 *    This file contains the implementation for the WIN32 Clipboard API
 * and Wine's internal clipboard cache.
 * The actual contents of the clipboard are held in the clipboard cache.
 * The internal implementation talks to a "clipboard driver" to fill or
 * expose the cache to the native device. (Currently only the X11 and
 * TTY clipboard  driver are available)
 */

#include "config.h"
#include "wine/port.h"

#include <stdarg.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#ifdef HAVE_UNISTD_H
# include <unistd.h>
#endif
#include <string.h>

#include "windef.h"
#include "winbase.h"
#include "wingdi.h"
#include "winuser.h"
#include "winerror.h"
#include "user_private.h"
#include "win.h"

#include "wine/debug.h"
#include "wine/unicode.h"
#include "wine/server.h"

WINE_DEFAULT_DEBUG_CHANNEL(clipboard);

#define  CF_REGFORMATBASE  0xC000

typedef struct
{
    HWND hWndOpen;
    HWND hWndOwner;
    UINT flags;
} CLIPBOARDINFO, *LPCLIPBOARDINFO;

/*
 * Indicates if data has changed since open.
 */
static BOOL bCBHasChanged = FALSE;


/**************************************************************************
 *                      CLIPBOARD_GetClipboardInfo
 */
static BOOL CLIPBOARD_GetClipboardInfo(LPCLIPBOARDINFO cbInfo)
{
    BOOL bRet;

    SERVER_START_REQ( set_clipboard_info )
    {
        req->flags = 0;

        if (((bRet = !wine_server_call_err( req ))))
        {
            cbInfo->hWndOpen = wine_server_ptr_handle( reply->old_clipboard );
            cbInfo->hWndOwner = wine_server_ptr_handle( reply->old_owner );
            cbInfo->flags = reply->flags;
        }
    }
    SERVER_END_REQ;

    return bRet;
}


/**************************************************************************
 *	CLIPBOARD_ReleaseOwner
 */
void CLIPBOARD_ReleaseOwner( HWND hwnd )
{
    SERVER_START_REQ( set_clipboard_info )
    {
        req->flags = SET_CB_RELOWNER | SET_CB_SEQNO;
        req->owner = wine_server_user_handle( hwnd );
        wine_server_call( req );
    }
    SERVER_END_REQ;
}


/**************************************************************************
 *		CLIPBOARD_SetClipboardViewer
 */
static HWND CLIPBOARD_SetClipboardViewer( HWND hWnd )
{
    HWND hwndPrev = 0;

    SERVER_START_REQ( set_clipboard_info )
    {
        req->flags = SET_CB_VIEWER;
        req->viewer = wine_server_user_handle( hWnd );
        if (!wine_server_call_err( req ))
            hwndPrev = wine_server_ptr_handle( reply->old_viewer );
    }
    SERVER_END_REQ;

    return hwndPrev;
}

/**************************************************************************
 *                WIN32 Clipboard implementation
 **************************************************************************/

/**************************************************************************
 *		RegisterClipboardFormatW (USER32.@)
 */
UINT WINAPI RegisterClipboardFormatW( LPCWSTR name )
{
    return GlobalAddAtomW( name );
}


/**************************************************************************
 *		RegisterClipboardFormatA (USER32.@)
 */
UINT WINAPI RegisterClipboardFormatA( LPCSTR name )
{
    return GlobalAddAtomA( name );
}


/**************************************************************************
 *		GetClipboardFormatNameW (USER32.@)
 */
INT WINAPI GetClipboardFormatNameW(UINT wFormat, LPWSTR retStr, INT maxlen)
{
    if (wFormat < MAXINTATOM) return 0;
    return GlobalGetAtomNameW( wFormat, retStr, maxlen );
}


/**************************************************************************
 *		GetClipboardFormatNameA (USER32.@)
 */
INT WINAPI GetClipboardFormatNameA(UINT wFormat, LPSTR retStr, INT maxlen)
{
    if (wFormat < MAXINTATOM) return 0;
    return GlobalGetAtomNameA( wFormat, retStr, maxlen );
}


/**************************************************************************
 *		OpenClipboard (USER32.@)
 *
 * Note: Netscape uses NULL hWnd to open the clipboard.
 */
BOOL WINAPI OpenClipboard( HWND hWnd )
{
    BOOL bRet;

    TRACE("(%p)...\n", hWnd);

    SERVER_START_REQ( set_clipboard_info )
    {
        req->flags = SET_CB_OPEN;
        req->clipboard = wine_server_user_handle( hWnd );
        bRet = !wine_server_call( req );
    }
    SERVER_END_REQ;

    TRACE(" returning %i\n", bRet);

    return bRet;
}


/**************************************************************************
 *		CloseClipboard (USER32.@)
 */
BOOL WINAPI CloseClipboard(void)
{
    HWND viewer = 0;
    BOOL ret;

    TRACE("() Changed=%d\n", bCBHasChanged);

    SERVER_START_REQ( set_clipboard_info )
    {
        req->flags = SET_CB_CLOSE;
        if (bCBHasChanged) req->flags |= SET_CB_SEQNO;
        if ((ret = !wine_server_call_err( req )))
            viewer = wine_server_ptr_handle( reply->old_viewer );
    }
    SERVER_END_REQ;

    if (!ret) return FALSE;

    if (bCBHasChanged)
    {
        USER_Driver->pEndClipboardUpdate();
        bCBHasChanged = FALSE;
        if (viewer) SendNotifyMessageW(viewer, WM_DRAWCLIPBOARD, (WPARAM) GetClipboardOwner(), 0);
    }
    return TRUE;
}


/**************************************************************************
 *		EmptyClipboard (USER32.@)
 * Empties and acquires ownership of the clipboard
 */
BOOL WINAPI EmptyClipboard(void)
{
    BOOL ret;
    HWND owner = GetClipboardOwner();

    TRACE("()\n");

    if (owner) SendMessageTimeoutW( owner, WM_DESTROYCLIPBOARD, 0, 0, SMTO_ABORTIFHUNG, 5000, NULL );

    SERVER_START_REQ( empty_clipboard )
    {
        ret = !wine_server_call_err( req );
    }
    SERVER_END_REQ;

    if (ret)
    {
        USER_Driver->pEmptyClipboard();
        bCBHasChanged = TRUE;
    }
    return ret;
}


/**************************************************************************
 *		GetClipboardOwner (USER32.@)
 *  FIXME: Can't return the owner if the clipboard is owned by an external X-app
 */
HWND WINAPI GetClipboardOwner(void)
{
    HWND hWndOwner = 0;

    SERVER_START_REQ( set_clipboard_info )
    {
        req->flags = 0;
        if (!wine_server_call_err( req )) hWndOwner = wine_server_ptr_handle( reply->old_owner );
    }
    SERVER_END_REQ;

    TRACE(" hWndOwner(%p)\n", hWndOwner);

    return hWndOwner;
}


/**************************************************************************
 *		GetOpenClipboardWindow (USER32.@)
 */
HWND WINAPI GetOpenClipboardWindow(void)
{
    HWND hWndOpen = 0;

    SERVER_START_REQ( set_clipboard_info )
    {
        req->flags = 0;
        if (!wine_server_call_err( req )) hWndOpen = wine_server_ptr_handle( reply->old_clipboard );
    }
    SERVER_END_REQ;

    TRACE(" hWndClipWindow(%p)\n", hWndOpen);

    return hWndOpen;
}


/**************************************************************************
 *		SetClipboardViewer (USER32.@)
 */
HWND WINAPI SetClipboardViewer( HWND hWnd )
{
    HWND hwndPrev = CLIPBOARD_SetClipboardViewer(hWnd);

    if (hWnd)
        SendNotifyMessageW(hWnd, WM_DRAWCLIPBOARD, (WPARAM) GetClipboardOwner(), 0);
    TRACE("(%p): returning %p\n", hWnd, hwndPrev);

    return hwndPrev;
}


/**************************************************************************
 *              GetClipboardViewer (USER32.@)
 */
HWND WINAPI GetClipboardViewer(void)
{
    HWND hWndViewer = 0;

    SERVER_START_REQ( set_clipboard_info )
    {
        req->flags = 0;
        if (!wine_server_call_err( req )) hWndViewer = wine_server_ptr_handle( reply->old_viewer );
    }
    SERVER_END_REQ;

    TRACE(" hWndViewer=%p\n", hWndViewer);

    return hWndViewer;
}


/**************************************************************************
 *              ChangeClipboardChain (USER32.@)
 */
BOOL WINAPI ChangeClipboardChain(HWND hWnd, HWND hWndNext)
{
    BOOL bRet = TRUE;
    HWND hWndViewer = GetClipboardViewer();

    if (hWndViewer)
    {
        if (WIN_GetFullHandle(hWnd) == hWndViewer)
            CLIPBOARD_SetClipboardViewer(WIN_GetFullHandle(hWndNext));
        else
            bRet = !SendMessageW(hWndViewer, WM_CHANGECBCHAIN, (WPARAM)hWnd, (LPARAM)hWndNext);
    }
    else
        ERR("hWndViewer is lost\n");

    return bRet;
}


/**************************************************************************
 *		SetClipboardData (USER32.@)
 */
HANDLE WINAPI SetClipboardData(UINT wFormat, HANDLE hData)
{
    CLIPBOARDINFO cbinfo;
    HANDLE hResult = 0;

    TRACE("(%04X, %p) !\n", wFormat, hData);

    if (!wFormat)
    {
        SetLastError( ERROR_CLIPBOARD_NOT_OPEN );
        return 0;
    }

    /* If it's not owned, data can only be set if the format isn't
       available and its rendering is not delayed */
    if (!CLIPBOARD_GetClipboardInfo(&cbinfo) ||
       (!(cbinfo.flags & CB_OWNER) && !hData))
    {
        WARN("Clipboard not owned by calling task. Operation failed.\n");
        return 0;
    }

    if (USER_Driver->pSetClipboardData(wFormat, hData, cbinfo.flags & CB_OWNER))
    {
        hResult = hData;
        bCBHasChanged = TRUE;
    }

    return hResult;
}


/**************************************************************************
 *		CountClipboardFormats (USER32.@)
 */
INT WINAPI CountClipboardFormats(void)
{
    INT count = USER_Driver->pCountClipboardFormats();
    TRACE("returning %d\n", count);
    return count;
}


/**************************************************************************
 *		EnumClipboardFormats (USER32.@)
 */
UINT WINAPI EnumClipboardFormats(UINT wFormat)
{
    CLIPBOARDINFO cbinfo;

    TRACE("(%04X)\n", wFormat);

    if (!CLIPBOARD_GetClipboardInfo(&cbinfo) ||
        (~cbinfo.flags & CB_OPEN))
    {
        WARN("Clipboard not opened by calling task.\n");
        SetLastError(ERROR_CLIPBOARD_NOT_OPEN);
        return 0;
    }
    return USER_Driver->pEnumClipboardFormats(wFormat);
}


/**************************************************************************
 *		IsClipboardFormatAvailable (USER32.@)
 */
BOOL WINAPI IsClipboardFormatAvailable(UINT wFormat)
{
    BOOL bret = USER_Driver->pIsClipboardFormatAvailable(wFormat);
    TRACE("%04x, returning %d\n", wFormat, bret);
    return bret;
}


/**************************************************************************
 *		GetClipboardData (USER32.@)
 */
HANDLE WINAPI GetClipboardData(UINT wFormat)
{
    HANDLE hData = 0;
    CLIPBOARDINFO cbinfo;

    TRACE("%04x\n", wFormat);

    if (!CLIPBOARD_GetClipboardInfo(&cbinfo) ||
        (~cbinfo.flags & CB_OPEN))
    {
        WARN("Clipboard not opened by calling task.\n");
        SetLastError(ERROR_CLIPBOARD_NOT_OPEN);
        return 0;
    }

    hData = USER_Driver->pGetClipboardData( wFormat );

    TRACE("returning %p\n", hData);
    return hData;
}


/**************************************************************************
 *		GetPriorityClipboardFormat (USER32.@)
 */
INT WINAPI GetPriorityClipboardFormat(UINT *list, INT nCount)
{
    int i;

    TRACE("()\n");

    if(CountClipboardFormats() == 0)
        return 0;

    for (i = 0; i < nCount; i++)
        if (IsClipboardFormatAvailable(list[i]))
            return list[i];

    return -1;
}


/**************************************************************************
 *		GetClipboardSequenceNumber (USER32.@)
 * Supported on Win2k/Win98
 * MSDN: Windows clipboard code keeps a serial number for the clipboard
 * for each window station.  The number is incremented whenever the
 * contents change or are emptied.
 * If you do not have WINSTA_ACCESSCLIPBOARD then the function returns 0
 */
DWORD WINAPI GetClipboardSequenceNumber(VOID)
{
    DWORD seqno = 0;

    SERVER_START_REQ( set_clipboard_info )
    {
        req->flags = 0;
        if (!wine_server_call_err( req )) seqno = reply->seqno;
    }
    SERVER_END_REQ;

    TRACE("returning %x\n", seqno);
    return seqno;
}

/**************************************************************************
 *		AddClipboardFormatListener (USER32.@)
 */
BOOL WINAPI AddClipboardFormatListener(HWND hwnd)
{
    FIXME("%p: stub\n", hwnd);
    return TRUE;
}

/**************************************************************************
 *		RemoveClipboardFormatListener (USER32.@)
 */
BOOL WINAPI RemoveClipboardFormatListener(HWND hwnd)
{
    FIXME("%p: stub\n", hwnd);
    return TRUE;
}
