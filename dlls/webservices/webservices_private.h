/*
 * Copyright 2015 Hans Leidekker for CodeWeavers
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
 */

struct xmlbuf
{
    WS_HEAP *heap;
    void    *ptr;
    SIZE_T   size_allocated;
    SIZE_T   size;
};

void *ws_alloc( WS_HEAP *, SIZE_T ) DECLSPEC_HIDDEN;
void *ws_realloc( WS_HEAP *, void *, SIZE_T ) DECLSPEC_HIDDEN;
void ws_free( WS_HEAP *, void * ) DECLSPEC_HIDDEN;
const char *debugstr_xmlstr( const WS_XML_STRING * ) DECLSPEC_HIDDEN;
WS_XML_STRING *alloc_xml_string( const unsigned char *, ULONG ) DECLSPEC_HIDDEN;
WS_XML_UTF8_TEXT *alloc_utf8_text( const unsigned char *, ULONG ) DECLSPEC_HIDDEN;
HRESULT append_attribute( WS_XML_ELEMENT_NODE *, WS_XML_ATTRIBUTE * ) DECLSPEC_HIDDEN;
void free_attribute( WS_XML_ATTRIBUTE * ) DECLSPEC_HIDDEN;
struct node *find_parent_element( struct node *, const WS_XML_STRING *,
                                  const WS_XML_STRING * ) DECLSPEC_HIDDEN;

struct node
{
    WS_XML_ELEMENT_NODE hdr;
    struct list         entry;
    struct node        *parent;
    struct list         children;
};

struct node *alloc_node( WS_XML_NODE_TYPE ) DECLSPEC_HIDDEN;
void free_node( struct node * ) DECLSPEC_HIDDEN;
void destroy_nodes( struct node * ) DECLSPEC_HIDDEN;

static inline void *heap_alloc( SIZE_T size )
{
    return HeapAlloc( GetProcessHeap(), 0, size );
}

static inline void *heap_alloc_zero( SIZE_T size )
{
    return HeapAlloc( GetProcessHeap(), HEAP_ZERO_MEMORY, size );
}

static inline void *heap_realloc( void *mem, SIZE_T size )
{
    return HeapReAlloc( GetProcessHeap(), 0, mem, size );
}

static inline BOOL heap_free( void *mem )
{
    return HeapFree( GetProcessHeap(), 0, mem );
}
