/*
 * Copyright 2016 Axel Davy
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

#include "config.h"
#include "wine/port.h"
#include "wine/debug.h"

WINE_DEFAULT_DEBUG_CHANNEL(d3dadapter);

#include <d3d9.h>

#include "device_wrap.h"

struct IDirect3DDevice9Ex_Minor1
{
        IDirect3DDevice9ExVtbl *lpVtbl;
        IDirect3DDevice9ExVtbl *lpVtbl_internal;
};

struct IDirect3DSwapChain9Ex_Minor1
{
        IDirect3DSwapChain9ExVtbl *lpVtbl;
        IDirect3DSwapChain9ExVtbl *lpVtbl_internal;
};

typedef struct IDirect3DDevice9Ex_Minor1 IDirect3DDevice9Ex_Minor1;
typedef struct IDirect3DSwapChain9Ex_Minor1 IDirect3DSwapChain9Ex_Minor1;

#define SWAPCHAIN_WRAP0(ret, func)  \
    ret WINAPI WineNineSwapChain9_ ## func(IDirect3DSwapChain9Ex *This) \
    { \
        return ((IDirect3DSwapChain9Ex_Minor1 *)This)->lpVtbl_internal->func(This); \
    }

#define SWAPCHAIN_WRAP1(ret, func, type1)  \
    ret WINAPI WineNineSwapChain9_ ## func(IDirect3DSwapChain9Ex *This, type1 arg1) \
    { \
        return ((IDirect3DSwapChain9Ex_Minor1 *)This)->lpVtbl_internal->func(This, arg1); \
    }

#define SWAPCHAIN_WRAP2(ret, func, type1, type2)  \
    ret WINAPI WineNineSwapChain9_ ## func(IDirect3DSwapChain9Ex *This, type1 arg1, type2 arg2) \
    { \
        return ((IDirect3DSwapChain9Ex_Minor1 *)This)->lpVtbl_internal->func(This, arg1, arg2); \
    }

#define SWAPCHAIN_WRAP3(ret, func, type1, type2, type3)  \
    ret WINAPI WineNineSwapChain9_ ## func(IDirect3DSwapChain9Ex *This, type1 arg1, type2 arg2, type3 arg3) \
    { \
        return ((IDirect3DSwapChain9Ex_Minor1 *)This)->lpVtbl_internal->func(This, arg1, arg2, arg3); \
    }

#define SWAPCHAIN_H_WRAP5(ret, func, type1, type2, type3, type4, type5)  \
    ret WINAPI DECLSPEC_HOTPATCH WineNineSwapChain9_ ## func(IDirect3DSwapChain9Ex *This, type1 arg1, type2 arg2, type3 arg3, type4 arg4, type5 arg5) \
    { \
        return ((IDirect3DSwapChain9Ex_Minor1 *)This)->lpVtbl_internal->func(This, arg1, arg2, arg3, arg4, arg5); \
    }

#define DEVICE_WRAP0(ret, func)  \
    ret WINAPI WineNineDevice9_ ## func(IDirect3DDevice9Ex *This) \
    { \
        return ((IDirect3DDevice9Ex_Minor1 *)This)->lpVtbl_internal->func(This); \
    }

#define DEVICE_WRAP1(ret, func, type1)  \
    ret WINAPI WineNineDevice9_ ## func(IDirect3DDevice9Ex *This, type1 arg1) \
    { \
        return ((IDirect3DDevice9Ex_Minor1 *)This)->lpVtbl_internal->func(This, arg1); \
    }

#define DEVICE_WRAP2(ret, func, type1, type2)  \
    ret WINAPI WineNineDevice9_ ## func(IDirect3DDevice9Ex *This, type1 arg1, type2 arg2) \
    { \
        return ((IDirect3DDevice9Ex_Minor1 *)This)->lpVtbl_internal->func(This, arg1, arg2); \
    }

#define DEVICE_WRAP3(ret, func, type1, type2, type3)  \
    ret WINAPI WineNineDevice9_ ## func(IDirect3DDevice9Ex *This, type1 arg1, type2 arg2, type3 arg3) \
    { \
        return ((IDirect3DDevice9Ex_Minor1 *)This)->lpVtbl_internal->func(This, arg1, arg2, arg3); \
    }

#define DEVICE_WRAP4(ret, func, type1, type2, type3, type4)  \
    ret WINAPI WineNineDevice9_ ## func(IDirect3DDevice9Ex *This, type1 arg1, type2 arg2, type3 arg3, type4 arg4) \
    { \
        return ((IDirect3DDevice9Ex_Minor1 *)This)->lpVtbl_internal->func(This, arg1, arg2, arg3, arg4); \
    }

#define DEVICE_WRAP5(ret, func, type1, type2, type3, type4, type5)  \
    ret WINAPI WineNineDevice9_ ## func(IDirect3DDevice9Ex *This, type1 arg1, type2 arg2, type3 arg3, type4 arg4, type5 arg5) \
    { \
        return ((IDirect3DDevice9Ex_Minor1 *)This)->lpVtbl_internal->func(This, arg1, arg2, arg3, arg4, arg5); \
    }

#define DEVICE_WRAP6(ret, func, type1, type2, type3, type4, type5, type6)  \
    ret WINAPI WineNineDevice9_ ## func(IDirect3DDevice9Ex *This, type1 arg1, type2 arg2, type3 arg3, type4 arg4, type5 arg5, type6 arg6) \
    { \
        return ((IDirect3DDevice9Ex_Minor1 *)This)->lpVtbl_internal->func(This, arg1, arg2, arg3, arg4, arg5, arg6); \
    }

#define DEVICE_WRAP7(ret, func, type1, type2, type3, type4, type5, type6, type7)  \
    ret WINAPI WineNineDevice9_ ## func(IDirect3DDevice9Ex *This, type1 arg1, type2 arg2, type3 arg3, type4 arg4, type5 arg5, type6 arg6, type7 arg7) \
    { \
        return ((IDirect3DDevice9Ex_Minor1 *)This)->lpVtbl_internal->func(This, arg1, arg2, arg3, arg4, arg5, arg6, arg7); \
    }

#define DEVICE_WRAP8(ret, func, type1, type2, type3, type4, type5, type6, type7, type8)  \
    ret WINAPI WineNineDevice9_ ## func(IDirect3DDevice9Ex *This, type1 arg1, type2 arg2, type3 arg3, type4 arg4, type5 arg5, type6 arg6, type7 arg7, type8 arg8) \
    { \
        return ((IDirect3DDevice9Ex_Minor1 *)This)->lpVtbl_internal->func(This, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8); \
    }

#define DEVICE_WRAP9(ret, func, type1, type2, type3, type4, type5, type6, type7, type8, type9)  \
    ret WINAPI WineNineDevice9_ ## func(IDirect3DDevice9Ex *This, type1 arg1, type2 arg2, type3 arg3, type4 arg4, type5 arg5, type6 arg6, type7 arg7, type8 arg8, type9 arg9) \
    { \
        return ((IDirect3DDevice9Ex_Minor1 *)This)->lpVtbl_internal->func(This, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9); \
    }

#define DEVICE_H_WRAP0(ret, func)  \
    ret WINAPI DECLSPEC_HOTPATCH WineNineDevice9_ ## func(IDirect3DDevice9Ex *This) \
    { \
        return ((IDirect3DDevice9Ex_Minor1 *)This)->lpVtbl_internal->func(This); \
    }

#define DEVICE_H_WRAP1(ret, func, type1)  \
    ret WINAPI DECLSPEC_HOTPATCH WineNineDevice9_ ## func(IDirect3DDevice9Ex *This, type1 arg1) \
    { \
        return ((IDirect3DDevice9Ex_Minor1 *)This)->lpVtbl_internal->func(This, arg1); \
    }

#define DEVICE_H_WRAP2(ret, func, type1, type2)  \
    ret WINAPI DECLSPEC_HOTPATCH WineNineDevice9_ ## func(IDirect3DDevice9Ex *This, type1 arg1, type2 arg2) \
    { \
        return ((IDirect3DDevice9Ex_Minor1 *)This)->lpVtbl_internal->func(This, arg1, arg2); \
    }

#define DEVICE_H_WRAP3(ret, func, type1, type2, type3)  \
    ret WINAPI DECLSPEC_HOTPATCH WineNineDevice9_ ## func(IDirect3DDevice9Ex *This, type1 arg1, type2 arg2, type3 arg3) \
    { \
        return ((IDirect3DDevice9Ex_Minor1 *)This)->lpVtbl_internal->func(This, arg1, arg2, arg3); \
    }

#define DEVICE_H_WRAP4(ret, func, type1, type2, type3, type4)  \
    ret WINAPI DECLSPEC_HOTPATCH WineNineDevice9_ ## func(IDirect3DDevice9Ex *This, type1 arg1, type2 arg2, type3 arg3, type4 arg4) \
    { \
        return ((IDirect3DDevice9Ex_Minor1 *)This)->lpVtbl_internal->func(This, arg1, arg2, arg3, arg4); \
    }

#define DEVICE_H_WRAP5(ret, func, type1, type2, type3, type4, type5)  \
    ret WINAPI DECLSPEC_HOTPATCH WineNineDevice9_ ## func(IDirect3DDevice9Ex *This, type1 arg1, type2 arg2, type3 arg3, type4 arg4, type5 arg5) \
    { \
        return ((IDirect3DDevice9Ex_Minor1 *)This)->lpVtbl_internal->func(This, arg1, arg2, arg3, arg4, arg5); \
    }

SWAPCHAIN_WRAP2(HRESULT, QueryInterface, REFIID, void **)
SWAPCHAIN_WRAP0(ULONG, AddRef)
SWAPCHAIN_WRAP0(ULONG, Release)
SWAPCHAIN_H_WRAP5(HRESULT, Present, const RECT *, const RECT *, HWND, const RGNDATA *, DWORD)
SWAPCHAIN_WRAP1(HRESULT, GetFrontBufferData, IDirect3DSurface9 *)
SWAPCHAIN_WRAP3(HRESULT, GetBackBuffer, UINT, D3DBACKBUFFER_TYPE, IDirect3DSurface9 **)
SWAPCHAIN_WRAP1(HRESULT, GetRasterStatus, D3DRASTER_STATUS *)
SWAPCHAIN_WRAP1(HRESULT, GetDisplayMode, D3DDISPLAYMODE *)
SWAPCHAIN_WRAP1(HRESULT, GetDevice, IDirect3DDevice9 **)
SWAPCHAIN_WRAP1(HRESULT, GetPresentParameters, D3DPRESENT_PARAMETERS *)
SWAPCHAIN_WRAP1(HRESULT, GetLastPresentCount, UINT *)
SWAPCHAIN_WRAP1(HRESULT, GetPresentStats, D3DPRESENTSTATS *)
SWAPCHAIN_WRAP2(HRESULT, GetDisplayModeEx, D3DDISPLAYMODEEX *, D3DDISPLAYROTATION *)

DEVICE_WRAP2(HRESULT, QueryInterface, REFIID, void **)
DEVICE_WRAP0(ULONG, AddRef)
DEVICE_H_WRAP0(ULONG, Release)
DEVICE_WRAP0(HRESULT, TestCooperativeLevel)
DEVICE_WRAP0(UINT, GetAvailableTextureMem)
DEVICE_WRAP0(HRESULT, EvictManagedResources)
DEVICE_WRAP1(HRESULT, GetDirect3D, IDirect3D9 **)
DEVICE_WRAP1(HRESULT, GetDeviceCaps, D3DCAPS9 *)
DEVICE_WRAP2(HRESULT, GetDisplayMode, UINT, D3DDISPLAYMODE*)
DEVICE_WRAP1(HRESULT, GetCreationParameters, D3DDEVICE_CREATION_PARAMETERS *)
DEVICE_WRAP3(HRESULT, SetCursorProperties, UINT, UINT, IDirect3DSurface9 *)
DEVICE_WRAP3(void, SetCursorPosition, int, int, DWORD)
DEVICE_WRAP1(BOOL, ShowCursor, BOOL)
/*DEVICE_H_WRAP2(HRESULT, CreateAdditionalSwapChain, D3DPRESENT_PARAMETERS *, IDirect3DSwapChain9 **)*/
/*DEVICE_H_WRAP2(HRESULT, GetSwapChain, UINT, IDirect3DSwapChain9 **)*/
DEVICE_WRAP0(UINT, GetNumberOfSwapChains)
DEVICE_H_WRAP1(HRESULT, Reset, D3DPRESENT_PARAMETERS *)
DEVICE_H_WRAP4(HRESULT, Present, const RECT *, const RECT *, HWND, const RGNDATA *)
DEVICE_WRAP4(HRESULT, GetBackBuffer, UINT, UINT, D3DBACKBUFFER_TYPE, IDirect3DSurface9 **)
DEVICE_WRAP2(HRESULT, GetRasterStatus, UINT, D3DRASTER_STATUS *)
DEVICE_WRAP1(HRESULT, SetDialogBoxMode, BOOL)
DEVICE_H_WRAP3(void, SetGammaRamp, UINT, DWORD, const D3DGAMMARAMP *)
DEVICE_WRAP2(void, GetGammaRamp, UINT, D3DGAMMARAMP *)
DEVICE_WRAP8(HRESULT, CreateTexture, UINT, UINT, UINT, DWORD, D3DFORMAT, D3DPOOL, IDirect3DTexture9 **, HANDLE *)
DEVICE_WRAP9(HRESULT, CreateVolumeTexture, UINT, UINT, UINT, UINT, DWORD, D3DFORMAT, D3DPOOL, IDirect3DVolumeTexture9 **, HANDLE *)
DEVICE_WRAP7(HRESULT, CreateCubeTexture, UINT, UINT, DWORD, D3DFORMAT, D3DPOOL, IDirect3DCubeTexture9 **, HANDLE *)
DEVICE_WRAP6(HRESULT, CreateVertexBuffer, UINT, DWORD, DWORD, D3DPOOL, IDirect3DVertexBuffer9 **, HANDLE *)
DEVICE_WRAP6(HRESULT, CreateIndexBuffer, UINT, DWORD, D3DFORMAT, D3DPOOL, IDirect3DIndexBuffer9 **, HANDLE *)
DEVICE_WRAP8(HRESULT, CreateRenderTarget, UINT, UINT, D3DFORMAT, D3DMULTISAMPLE_TYPE, DWORD, BOOL, IDirect3DSurface9 **, HANDLE *)
DEVICE_WRAP8(HRESULT, CreateDepthStencilSurface, UINT, UINT, D3DFORMAT, D3DMULTISAMPLE_TYPE, DWORD, BOOL, IDirect3DSurface9 **, HANDLE *)
DEVICE_WRAP4(HRESULT, UpdateSurface, IDirect3DSurface9 *, const RECT *, IDirect3DSurface9 *, const POINT *)
DEVICE_WRAP2(HRESULT, UpdateTexture, IDirect3DBaseTexture9 *, IDirect3DBaseTexture9 *)
DEVICE_WRAP2(HRESULT, GetRenderTargetData, IDirect3DSurface9 *, IDirect3DSurface9 *)
DEVICE_WRAP2(HRESULT, GetFrontBufferData, UINT, IDirect3DSurface9 *)
DEVICE_WRAP5(HRESULT, StretchRect, IDirect3DSurface9 *, const RECT *, IDirect3DSurface9 *, const RECT *, D3DTEXTUREFILTERTYPE)
DEVICE_WRAP3(HRESULT, ColorFill, IDirect3DSurface9 *, const RECT *, D3DCOLOR)
DEVICE_WRAP6(HRESULT, CreateOffscreenPlainSurface, UINT, UINT, D3DFORMAT, D3DPOOL, IDirect3DSurface9 **, HANDLE *)
DEVICE_WRAP2(HRESULT, SetRenderTarget, DWORD, IDirect3DSurface9 *)
DEVICE_WRAP2(HRESULT, GetRenderTarget, DWORD, IDirect3DSurface9 **)
DEVICE_WRAP1(HRESULT, SetDepthStencilSurface, IDirect3DSurface9 *)
DEVICE_WRAP1(HRESULT, GetDepthStencilSurface, IDirect3DSurface9 **)
DEVICE_WRAP0(HRESULT, BeginScene)
DEVICE_H_WRAP0(HRESULT, EndScene)
DEVICE_WRAP6(HRESULT, Clear, DWORD, const D3DRECT *, DWORD, D3DCOLOR, float, DWORD)
DEVICE_WRAP2(HRESULT, SetTransform, D3DTRANSFORMSTATETYPE, const D3DMATRIX *)
DEVICE_WRAP2(HRESULT, GetTransform, D3DTRANSFORMSTATETYPE, D3DMATRIX *)
DEVICE_WRAP2(HRESULT, MultiplyTransform, D3DTRANSFORMSTATETYPE, const D3DMATRIX *)
DEVICE_WRAP1(HRESULT, SetViewport, const D3DVIEWPORT9 *)
DEVICE_WRAP1(HRESULT, GetViewport, D3DVIEWPORT9 *)
DEVICE_WRAP1(HRESULT, SetMaterial, const D3DMATERIAL9 *)
DEVICE_WRAP1(HRESULT, GetMaterial, D3DMATERIAL9 *)
DEVICE_WRAP2(HRESULT, SetLight, DWORD, const D3DLIGHT9 *)
DEVICE_WRAP2(HRESULT, GetLight, DWORD, D3DLIGHT9 *)
DEVICE_WRAP2(HRESULT, LightEnable, DWORD, BOOL)
DEVICE_WRAP2(HRESULT, GetLightEnable, DWORD, BOOL *)
DEVICE_WRAP2(HRESULT, SetClipPlane, DWORD, const float *)
DEVICE_WRAP2(HRESULT, GetClipPlane, DWORD, float *)
DEVICE_H_WRAP2(HRESULT, SetRenderState, D3DRENDERSTATETYPE, DWORD)
DEVICE_WRAP2(HRESULT, GetRenderState, D3DRENDERSTATETYPE, DWORD *)
DEVICE_WRAP2(HRESULT, CreateStateBlock, D3DSTATEBLOCKTYPE, IDirect3DStateBlock9 **)
DEVICE_WRAP0(HRESULT, BeginStateBlock)
DEVICE_WRAP1(HRESULT, EndStateBlock, IDirect3DStateBlock9 **)
DEVICE_WRAP1(HRESULT, SetClipStatus, const D3DCLIPSTATUS9 *)
DEVICE_WRAP1(HRESULT, GetClipStatus, D3DCLIPSTATUS9 *)
DEVICE_WRAP2(HRESULT, GetTexture, DWORD, IDirect3DBaseTexture9 **)
DEVICE_WRAP2(HRESULT, SetTexture, DWORD, IDirect3DBaseTexture9 *)
DEVICE_WRAP3(HRESULT, GetTextureStageState, DWORD, D3DTEXTURESTAGESTATETYPE, DWORD *)
DEVICE_WRAP3(HRESULT, SetTextureStageState, DWORD, D3DTEXTURESTAGESTATETYPE, DWORD)
DEVICE_WRAP3(HRESULT, GetSamplerState, DWORD, D3DSAMPLERSTATETYPE, DWORD *)
DEVICE_H_WRAP3(HRESULT, SetSamplerState, DWORD, D3DSAMPLERSTATETYPE, DWORD)
DEVICE_WRAP1(HRESULT, ValidateDevice, DWORD *)
DEVICE_WRAP2(HRESULT, SetPaletteEntries, UINT, const PALETTEENTRY *)
DEVICE_WRAP2(HRESULT, GetPaletteEntries, UINT, PALETTEENTRY *)
DEVICE_WRAP1(HRESULT, SetCurrentTexturePalette, UINT)
DEVICE_WRAP1(HRESULT, GetCurrentTexturePalette, UINT *)
DEVICE_WRAP1(HRESULT, SetScissorRect, const RECT *)
DEVICE_WRAP1(HRESULT, GetScissorRect, RECT *)
DEVICE_WRAP1(HRESULT, SetSoftwareVertexProcessing, BOOL)
DEVICE_WRAP0(BOOL, GetSoftwareVertexProcessing)
DEVICE_WRAP1(HRESULT, SetNPatchMode, float)
DEVICE_WRAP0(float, GetNPatchMode)
DEVICE_WRAP3(HRESULT, DrawPrimitive, D3DPRIMITIVETYPE, UINT, UINT)
DEVICE_WRAP6(HRESULT, DrawIndexedPrimitive, D3DPRIMITIVETYPE, INT, UINT, UINT, UINT, UINT)
DEVICE_WRAP4(HRESULT, DrawPrimitiveUP, D3DPRIMITIVETYPE, UINT, const void *, UINT)
DEVICE_WRAP8(HRESULT, DrawIndexedPrimitiveUP, D3DPRIMITIVETYPE, UINT, UINT, UINT, const void *, D3DFORMAT, const void *, UINT)
DEVICE_WRAP6(HRESULT, ProcessVertices, UINT, UINT, UINT, IDirect3DVertexBuffer9 *, IDirect3DVertexDeclaration9 *, DWORD)
DEVICE_WRAP2(HRESULT, CreateVertexDeclaration, const D3DVERTEXELEMENT9 *, IDirect3DVertexDeclaration9 **)
DEVICE_WRAP1(HRESULT, SetVertexDeclaration, IDirect3DVertexDeclaration9 *)
DEVICE_WRAP1(HRESULT, GetVertexDeclaration, IDirect3DVertexDeclaration9 **)
DEVICE_WRAP1(HRESULT, SetFVF, DWORD)
DEVICE_WRAP1(HRESULT, GetFVF, DWORD *)
DEVICE_WRAP2(HRESULT, CreateVertexShader, const DWORD *, IDirect3DVertexShader9 **)
DEVICE_WRAP1(HRESULT, SetVertexShader, IDirect3DVertexShader9 *)
DEVICE_WRAP1(HRESULT, GetVertexShader, IDirect3DVertexShader9 **)
DEVICE_WRAP3(HRESULT, SetVertexShaderConstantF, UINT, const float *, UINT)
DEVICE_WRAP3(HRESULT, GetVertexShaderConstantF, UINT, float *, UINT)
DEVICE_WRAP3(HRESULT, SetVertexShaderConstantI, UINT, const int *, UINT)
DEVICE_WRAP3(HRESULT, GetVertexShaderConstantI, UINT, int *, UINT)
DEVICE_WRAP3(HRESULT, SetVertexShaderConstantB, UINT, const BOOL *, UINT)
DEVICE_WRAP3(HRESULT, GetVertexShaderConstantB, UINT, BOOL *, UINT)
DEVICE_WRAP4(HRESULT, SetStreamSource, UINT, IDirect3DVertexBuffer9 *, UINT, UINT)
DEVICE_WRAP4(HRESULT, GetStreamSource, UINT, IDirect3DVertexBuffer9 **, UINT *, UINT *)
DEVICE_WRAP2(HRESULT, SetStreamSourceFreq, UINT, UINT)
DEVICE_WRAP2(HRESULT, GetStreamSourceFreq, UINT, UINT *)
DEVICE_WRAP1(HRESULT, SetIndices, IDirect3DIndexBuffer9 *)
DEVICE_WRAP1(HRESULT, GetIndices, IDirect3DIndexBuffer9 **)
DEVICE_WRAP2(HRESULT, CreatePixelShader, const DWORD *, IDirect3DPixelShader9 **)
DEVICE_WRAP1(HRESULT, SetPixelShader, IDirect3DPixelShader9 *)
DEVICE_WRAP1(HRESULT, GetPixelShader, IDirect3DPixelShader9 **)
DEVICE_WRAP3(HRESULT, SetPixelShaderConstantF, UINT, const float *, UINT)
DEVICE_WRAP3(HRESULT, GetPixelShaderConstantF, UINT, float *, UINT)
DEVICE_WRAP3(HRESULT, SetPixelShaderConstantI, UINT, const int *, UINT)
DEVICE_WRAP3(HRESULT, GetPixelShaderConstantI, UINT, int *, UINT)
DEVICE_WRAP3(HRESULT, SetPixelShaderConstantB, UINT, const BOOL *, UINT)
DEVICE_WRAP3(HRESULT, GetPixelShaderConstantB, UINT, BOOL *, UINT)
DEVICE_WRAP3(HRESULT, DrawRectPatch, UINT, const float *, const D3DRECTPATCH_INFO *)
DEVICE_WRAP3(HRESULT, DrawTriPatch, UINT, const float *, const D3DTRIPATCH_INFO *)
DEVICE_WRAP1(HRESULT, DeletePatch, UINT)
DEVICE_WRAP2(HRESULT, CreateQuery, D3DQUERYTYPE, IDirect3DQuery9 **)
DEVICE_WRAP4(HRESULT, SetConvolutionMonoKernel, UINT, UINT, float *, float *)
DEVICE_WRAP8(HRESULT, ComposeRects, IDirect3DSurface9 *, IDirect3DSurface9 *, IDirect3DVertexBuffer9 *, UINT, IDirect3DVertexBuffer9 *, D3DCOMPOSERECTSOP, int, int)
DEVICE_H_WRAP5(HRESULT, PresentEx, const RECT *, const RECT *, HWND, const RGNDATA *, DWORD)
DEVICE_WRAP1(HRESULT, GetGPUThreadPriority, INT *)
DEVICE_WRAP1(HRESULT, SetGPUThreadPriority, INT)
DEVICE_WRAP1(HRESULT, WaitForVBlank, UINT)
DEVICE_WRAP2(HRESULT, CheckResourceResidency, IDirect3DResource9 **, UINT32)
DEVICE_WRAP1(HRESULT, SetMaximumFrameLatency, UINT)
DEVICE_WRAP1(HRESULT, GetMaximumFrameLatency, UINT *)
DEVICE_WRAP1(HRESULT, CheckDeviceState, HWND)
DEVICE_WRAP9(HRESULT, CreateRenderTargetEx, UINT, UINT, D3DFORMAT, D3DMULTISAMPLE_TYPE, DWORD, BOOL, IDirect3DSurface9 **, HANDLE *, DWORD)
DEVICE_WRAP7(HRESULT, CreateOffscreenPlainSurfaceEx, UINT, UINT, D3DFORMAT, D3DPOOL, IDirect3DSurface9 **, HANDLE *, DWORD)
DEVICE_WRAP9(HRESULT, CreateDepthStencilSurfaceEx, UINT, UINT, D3DFORMAT, D3DMULTISAMPLE_TYPE, DWORD, BOOL, IDirect3DSurface9 **, HANDLE *, DWORD)
DEVICE_H_WRAP2(HRESULT, ResetEx, D3DPRESENT_PARAMETERS *, D3DDISPLAYMODEEX *)
DEVICE_WRAP3(HRESULT, GetDisplayModeEx, UINT, D3DDISPLAYMODEEX *, D3DDISPLAYROTATION *)

IDirect3DSwapChain9ExVtbl WineNineSwapChain9Ex_vtable = {
    WineNineSwapChain9_QueryInterface,
    WineNineSwapChain9_AddRef,
    WineNineSwapChain9_Release,
    WineNineSwapChain9_Present,
    WineNineSwapChain9_GetFrontBufferData,
    WineNineSwapChain9_GetBackBuffer,
    WineNineSwapChain9_GetRasterStatus,
    WineNineSwapChain9_GetDisplayMode,
    WineNineSwapChain9_GetDevice,
    WineNineSwapChain9_GetPresentParameters,
    WineNineSwapChain9_GetLastPresentCount,
    WineNineSwapChain9_GetPresentStats,
    WineNineSwapChain9_GetDisplayModeEx
};

HRESULT WINAPI DECLSPEC_HOTPATCH WineNineDevice9_CreateAdditionalSwapChain(IDirect3DDevice9Ex *This, D3DPRESENT_PARAMETERS *pPresentationParameters, IDirect3DSwapChain9 **pSwapChain)
{
    HRESULT hr;

    hr = ((IDirect3DDevice9Ex_Minor1 *)This)->lpVtbl_internal->CreateAdditionalSwapChain(This, pPresentationParameters, pSwapChain);
    if (FAILED(hr))
        return hr;

    (*pSwapChain)->lpVtbl = (IDirect3DSwapChain9Vtbl *)&WineNineSwapChain9Ex_vtable;

    return hr;
}

HRESULT WINAPI DECLSPEC_HOTPATCH WineNineDevice9_GetSwapChain(IDirect3DDevice9Ex *This, UINT iSwapChain, IDirect3DSwapChain9 **pSwapChain)
{
    HRESULT hr;

    hr = ((IDirect3DDevice9Ex_Minor1 *)This)->lpVtbl_internal->GetSwapChain(This, iSwapChain, pSwapChain);
    if (FAILED(hr))
        return hr;

    (*pSwapChain)->lpVtbl = (IDirect3DSwapChain9Vtbl *)&WineNineSwapChain9Ex_vtable;

    return hr;
}


IDirect3DDevice9ExVtbl WineNineDevice9_vtable = {
    WineNineDevice9_QueryInterface,
    WineNineDevice9_AddRef,
    WineNineDevice9_Release,
    WineNineDevice9_TestCooperativeLevel,
    WineNineDevice9_GetAvailableTextureMem,
    WineNineDevice9_EvictManagedResources,
    WineNineDevice9_GetDirect3D,
    WineNineDevice9_GetDeviceCaps,
    WineNineDevice9_GetDisplayMode,
    WineNineDevice9_GetCreationParameters,
    WineNineDevice9_SetCursorProperties,
    WineNineDevice9_SetCursorPosition,
    WineNineDevice9_ShowCursor,
    WineNineDevice9_CreateAdditionalSwapChain,
    WineNineDevice9_GetSwapChain,
    WineNineDevice9_GetNumberOfSwapChains,
    WineNineDevice9_Reset,
    WineNineDevice9_Present,
    WineNineDevice9_GetBackBuffer,
    WineNineDevice9_GetRasterStatus,
    WineNineDevice9_SetDialogBoxMode,
    WineNineDevice9_SetGammaRamp,
    WineNineDevice9_GetGammaRamp,
    WineNineDevice9_CreateTexture,
    WineNineDevice9_CreateVolumeTexture,
    WineNineDevice9_CreateCubeTexture,
    WineNineDevice9_CreateVertexBuffer,
    WineNineDevice9_CreateIndexBuffer,
    WineNineDevice9_CreateRenderTarget,
    WineNineDevice9_CreateDepthStencilSurface,
    WineNineDevice9_UpdateSurface,
    WineNineDevice9_UpdateTexture,
    WineNineDevice9_GetRenderTargetData,
    WineNineDevice9_GetFrontBufferData,
    WineNineDevice9_StretchRect,
    WineNineDevice9_ColorFill,
    WineNineDevice9_CreateOffscreenPlainSurface,
    WineNineDevice9_SetRenderTarget,
    WineNineDevice9_GetRenderTarget,
    WineNineDevice9_SetDepthStencilSurface,
    WineNineDevice9_GetDepthStencilSurface,
    WineNineDevice9_BeginScene,
    WineNineDevice9_EndScene,
    WineNineDevice9_Clear,
    WineNineDevice9_SetTransform,
    WineNineDevice9_GetTransform,
    WineNineDevice9_MultiplyTransform,
    WineNineDevice9_SetViewport,
    WineNineDevice9_GetViewport,
    WineNineDevice9_SetMaterial,
    WineNineDevice9_GetMaterial,
    WineNineDevice9_SetLight,
    WineNineDevice9_GetLight,
    WineNineDevice9_LightEnable,
    WineNineDevice9_GetLightEnable,
    WineNineDevice9_SetClipPlane,
    WineNineDevice9_GetClipPlane,
    WineNineDevice9_SetRenderState,
    WineNineDevice9_GetRenderState,
    WineNineDevice9_CreateStateBlock,
    WineNineDevice9_BeginStateBlock,
    WineNineDevice9_EndStateBlock,
    WineNineDevice9_SetClipStatus,
    WineNineDevice9_GetClipStatus,
    WineNineDevice9_GetTexture,
    WineNineDevice9_SetTexture,
    WineNineDevice9_GetTextureStageState,
    WineNineDevice9_SetTextureStageState,
    WineNineDevice9_GetSamplerState,
    WineNineDevice9_SetSamplerState,
    WineNineDevice9_ValidateDevice,
    WineNineDevice9_SetPaletteEntries,
    WineNineDevice9_GetPaletteEntries,
    WineNineDevice9_SetCurrentTexturePalette,
    WineNineDevice9_GetCurrentTexturePalette,
    WineNineDevice9_SetScissorRect,
    WineNineDevice9_GetScissorRect,
    WineNineDevice9_SetSoftwareVertexProcessing,
    WineNineDevice9_GetSoftwareVertexProcessing,
    WineNineDevice9_SetNPatchMode,
    WineNineDevice9_GetNPatchMode,
    WineNineDevice9_DrawPrimitive,
    WineNineDevice9_DrawIndexedPrimitive,
    WineNineDevice9_DrawPrimitiveUP,
    WineNineDevice9_DrawIndexedPrimitiveUP,
    WineNineDevice9_ProcessVertices,
    WineNineDevice9_CreateVertexDeclaration,
    WineNineDevice9_SetVertexDeclaration,
    WineNineDevice9_GetVertexDeclaration,
    WineNineDevice9_SetFVF,
    WineNineDevice9_GetFVF,
    WineNineDevice9_CreateVertexShader,
    WineNineDevice9_SetVertexShader,
    WineNineDevice9_GetVertexShader,
    WineNineDevice9_SetVertexShaderConstantF,
    WineNineDevice9_GetVertexShaderConstantF,
    WineNineDevice9_SetVertexShaderConstantI,
    WineNineDevice9_GetVertexShaderConstantI,
    WineNineDevice9_SetVertexShaderConstantB,
    WineNineDevice9_GetVertexShaderConstantB,
    WineNineDevice9_SetStreamSource,
    WineNineDevice9_GetStreamSource,
    WineNineDevice9_SetStreamSourceFreq,
    WineNineDevice9_GetStreamSourceFreq,
    WineNineDevice9_SetIndices,
    WineNineDevice9_GetIndices,
    WineNineDevice9_CreatePixelShader,
    WineNineDevice9_SetPixelShader,
    WineNineDevice9_GetPixelShader,
    WineNineDevice9_SetPixelShaderConstantF,
    WineNineDevice9_GetPixelShaderConstantF,
    WineNineDevice9_SetPixelShaderConstantI,
    WineNineDevice9_GetPixelShaderConstantI,
    WineNineDevice9_SetPixelShaderConstantB,
    WineNineDevice9_GetPixelShaderConstantB,
    WineNineDevice9_DrawRectPatch,
    WineNineDevice9_DrawTriPatch,
    WineNineDevice9_DeletePatch,
    WineNineDevice9_CreateQuery,
    WineNineDevice9_SetConvolutionMonoKernel,
    WineNineDevice9_ComposeRects,
    WineNineDevice9_PresentEx,
    WineNineDevice9_GetGPUThreadPriority,
    WineNineDevice9_SetGPUThreadPriority,
    WineNineDevice9_WaitForVBlank,
    WineNineDevice9_CheckResourceResidency,
    WineNineDevice9_SetMaximumFrameLatency,
    WineNineDevice9_GetMaximumFrameLatency,
    WineNineDevice9_CheckDeviceState,
    WineNineDevice9_CreateRenderTargetEx,
    WineNineDevice9_CreateOffscreenPlainSurfaceEx,
    WineNineDevice9_CreateDepthStencilSurfaceEx,
    WineNineDevice9_ResetEx,
    WineNineDevice9_GetDisplayModeEx
};

IDirect3DDevice9ExVtbl *get_device_vtable()
{
    return &WineNineDevice9_vtable;
}
