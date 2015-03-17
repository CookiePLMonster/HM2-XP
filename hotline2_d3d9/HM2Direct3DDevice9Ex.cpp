/*
 *  Hotline Miami 2: Wrong Number XP Support Patch
 *	IDirect3DDevice9Ex -> IDirect3DDevice9 wrapper
 *      Created by Silent <zdanio95@gmail.com>
 */


#include "HM2Direct3DDevice9Ex.h"


HRESULT CHM2Direct3DDevice9Ex::TestCooperativeLevel(void)
{
	return pWrappedInterface->TestCooperativeLevel();
}

UINT CHM2Direct3DDevice9Ex::GetAvailableTextureMem(void)
{
	return pWrappedInterface->GetAvailableTextureMem();
}

HRESULT CHM2Direct3DDevice9Ex::EvictManagedResources(void)
{
	return pWrappedInterface->EvictManagedResources();
}

HRESULT CHM2Direct3DDevice9Ex::GetDirect3D(IDirect3D9** ppD3D9)
{
	return pWrappedInterface->GetDirect3D(ppD3D9);
}

HRESULT CHM2Direct3DDevice9Ex::GetDeviceCaps(D3DCAPS9* pCaps)
{
	return pWrappedInterface->GetDeviceCaps(pCaps);
}

HRESULT CHM2Direct3DDevice9Ex::GetDisplayMode(UINT iSwapChain,D3DDISPLAYMODE* pMode)
{
	return pWrappedInterface->GetDisplayMode(iSwapChain, pMode);
}

HRESULT CHM2Direct3DDevice9Ex::GetCreationParameters(D3DDEVICE_CREATION_PARAMETERS *pParameters)
{
	return pWrappedInterface->GetCreationParameters(pParameters);
}

HRESULT CHM2Direct3DDevice9Ex::SetCursorProperties(UINT XHotSpot,UINT YHotSpot,IDirect3DSurface9* pCursorBitmap)
{
	return pWrappedInterface->SetCursorProperties(XHotSpot, YHotSpot, pCursorBitmap);
}

void CHM2Direct3DDevice9Ex::SetCursorPosition(int X,int Y,DWORD Flags)
{
	pWrappedInterface->SetCursorPosition(X, Y, Flags);
}

BOOL CHM2Direct3DDevice9Ex::ShowCursor(BOOL bShow)
{
	return pWrappedInterface->ShowCursor(bShow);
}

HRESULT CHM2Direct3DDevice9Ex::CreateAdditionalSwapChain(D3DPRESENT_PARAMETERS* pPresentationParameters,IDirect3DSwapChain9** pSwapChain)
{
	return pWrappedInterface->CreateAdditionalSwapChain(pPresentationParameters, pSwapChain);
}

HRESULT CHM2Direct3DDevice9Ex::GetSwapChain(UINT iSwapChain,IDirect3DSwapChain9** pSwapChain)
{
	return pWrappedInterface->GetSwapChain(iSwapChain, pSwapChain);
}

UINT CHM2Direct3DDevice9Ex::GetNumberOfSwapChains(void)
{
	return pWrappedInterface->GetNumberOfSwapChains();
}

HRESULT CHM2Direct3DDevice9Ex::Reset(D3DPRESENT_PARAMETERS* pPresentationParameters)
{
	return pWrappedInterface->Reset(pPresentationParameters);
}

HRESULT CHM2Direct3DDevice9Ex::Present(CONST RECT* pSourceRect,CONST RECT* pDestRect,HWND hDestWindowOverride,CONST RGNDATA* pDirtyRegion)
{
	return pWrappedInterface->Present(pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
}

HRESULT CHM2Direct3DDevice9Ex::GetBackBuffer(UINT iSwapChain,UINT iBackBuffer,D3DBACKBUFFER_TYPE Type,IDirect3DSurface9** ppBackBuffer)
{
	return pWrappedInterface->GetBackBuffer(iSwapChain, iBackBuffer, Type, ppBackBuffer);
}

HRESULT CHM2Direct3DDevice9Ex::GetRasterStatus(UINT iSwapChain,D3DRASTER_STATUS* pRasterStatus)
{
	return pWrappedInterface->GetRasterStatus(iSwapChain, pRasterStatus);
}

HRESULT CHM2Direct3DDevice9Ex::SetDialogBoxMode(BOOL bEnableDialogs)
{
	return pWrappedInterface->SetDialogBoxMode(bEnableDialogs);
}

void CHM2Direct3DDevice9Ex::SetGammaRamp(UINT iSwapChain,DWORD Flags,CONST D3DGAMMARAMP* pRamp)
{
	pWrappedInterface->SetGammaRamp(iSwapChain, Flags, pRamp);
}

void CHM2Direct3DDevice9Ex::GetGammaRamp(UINT iSwapChain,D3DGAMMARAMP* pRamp)
{
	pWrappedInterface->GetGammaRamp(iSwapChain, pRamp);
}

HRESULT CHM2Direct3DDevice9Ex::CreateTexture(UINT Width,UINT Height,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DTexture9** ppTexture,HANDLE* pSharedHandle)
{
	return pWrappedInterface->CreateTexture(Width, Height, Levels, Usage, Format, Pool, ppTexture, pSharedHandle);
}

HRESULT CHM2Direct3DDevice9Ex::CreateVolumeTexture(UINT Width,UINT Height,UINT Depth,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DVolumeTexture9** ppVolumeTexture,HANDLE* pSharedHandle)
{
	return pWrappedInterface->CreateVolumeTexture(Width, Height, Depth, Levels, Usage, Format, Pool, ppVolumeTexture, pSharedHandle);
}

HRESULT CHM2Direct3DDevice9Ex::CreateCubeTexture(UINT EdgeLength,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DCubeTexture9** ppCubeTexture,HANDLE* pSharedHandle)
{
	return pWrappedInterface->CreateCubeTexture(EdgeLength, Levels, Usage, Format, Pool, ppCubeTexture, pSharedHandle);
}

HRESULT CHM2Direct3DDevice9Ex::CreateVertexBuffer(UINT Length,DWORD Usage,DWORD FVF,D3DPOOL Pool,IDirect3DVertexBuffer9** ppVertexBuffer,HANDLE* pSharedHandle)
{
	return pWrappedInterface->CreateVertexBuffer(Length, Usage, FVF, Pool, ppVertexBuffer, pSharedHandle);
}

HRESULT CHM2Direct3DDevice9Ex::CreateIndexBuffer(UINT Length,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DIndexBuffer9** ppIndexBuffer,HANDLE* pSharedHandle)
{
	return pWrappedInterface->CreateIndexBuffer(Length, Usage, Format, Pool, ppIndexBuffer, pSharedHandle);
}

HRESULT CHM2Direct3DDevice9Ex::CreateRenderTarget(UINT Width,UINT Height,D3DFORMAT Format,D3DMULTISAMPLE_TYPE MultiSample,DWORD MultisampleQuality,BOOL Lockable,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle)
{
	return pWrappedInterface->CreateRenderTarget(Width, Height, Format, MultiSample, MultisampleQuality, Lockable, ppSurface, pSharedHandle);
}

HRESULT CHM2Direct3DDevice9Ex::CreateDepthStencilSurface(UINT Width,UINT Height,D3DFORMAT Format,D3DMULTISAMPLE_TYPE MultiSample,DWORD MultisampleQuality,BOOL Discard,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle)
{
	return pWrappedInterface->CreateDepthStencilSurface(Width, Height, Format, MultiSample, MultisampleQuality, Discard, ppSurface, pSharedHandle);
}

HRESULT CHM2Direct3DDevice9Ex::UpdateSurface(IDirect3DSurface9* pSourceSurface,CONST RECT* pSourceRect,IDirect3DSurface9* pDestinationSurface,CONST POINT* pDestPoint)
{
	return pWrappedInterface->UpdateSurface(pSourceSurface, pSourceRect, pDestinationSurface, pDestPoint);
}

HRESULT CHM2Direct3DDevice9Ex::UpdateTexture(IDirect3DBaseTexture9* pSourceTexture,IDirect3DBaseTexture9* pDestinationTexture)
{
	return pWrappedInterface->UpdateTexture(pSourceTexture, pDestinationTexture);
}

HRESULT CHM2Direct3DDevice9Ex::GetRenderTargetData(IDirect3DSurface9* pRenderTarget,IDirect3DSurface9* pDestSurface)
{
	return pWrappedInterface->GetRenderTargetData(pRenderTarget, pDestSurface);
}

HRESULT CHM2Direct3DDevice9Ex::GetFrontBufferData(UINT iSwapChain,IDirect3DSurface9* pDestSurface)
{
	return pWrappedInterface->GetFrontBufferData(iSwapChain, pDestSurface);
}

HRESULT CHM2Direct3DDevice9Ex::StretchRect(IDirect3DSurface9* pSourceSurface,CONST RECT* pSourceRect,IDirect3DSurface9* pDestSurface,CONST RECT* pDestRect,D3DTEXTUREFILTERTYPE Filter)
{
	return pWrappedInterface->StretchRect(pSourceSurface, pSourceRect, pDestSurface, pDestRect, Filter);
}

HRESULT CHM2Direct3DDevice9Ex::ColorFill(IDirect3DSurface9* pSurface,CONST RECT* pRect,D3DCOLOR color)
{
	return pWrappedInterface->ColorFill(pSurface, pRect, color);
}

HRESULT CHM2Direct3DDevice9Ex::CreateOffscreenPlainSurface(UINT Width,UINT Height,D3DFORMAT Format,D3DPOOL Pool,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle)
{
	return pWrappedInterface->CreateOffscreenPlainSurface(Width, Height, Format, Pool, ppSurface, pSharedHandle);
}

HRESULT CHM2Direct3DDevice9Ex::SetRenderTarget(DWORD RenderTargetIndex,IDirect3DSurface9* pRenderTarget)
{
	return pWrappedInterface->SetRenderTarget(RenderTargetIndex, pRenderTarget);
}

HRESULT CHM2Direct3DDevice9Ex::GetRenderTarget(DWORD RenderTargetIndex,IDirect3DSurface9** ppRenderTarget)
{
	return pWrappedInterface->GetRenderTarget(RenderTargetIndex, ppRenderTarget);
}

HRESULT CHM2Direct3DDevice9Ex::SetDepthStencilSurface(IDirect3DSurface9* pNewZStencil)
{
	return pWrappedInterface->SetDepthStencilSurface(pNewZStencil);
}

HRESULT CHM2Direct3DDevice9Ex::GetDepthStencilSurface(IDirect3DSurface9** ppZStencilSurface)
{
	return pWrappedInterface->GetDepthStencilSurface(ppZStencilSurface);
}

HRESULT CHM2Direct3DDevice9Ex::BeginScene(void)
{
	return pWrappedInterface->BeginScene();
}

HRESULT CHM2Direct3DDevice9Ex::EndScene(void)
{
	return pWrappedInterface->EndScene();
}

HRESULT CHM2Direct3DDevice9Ex::Clear(DWORD Count,CONST D3DRECT* pRects,DWORD Flags,D3DCOLOR Color,float Z,DWORD Stencil)
{
	return pWrappedInterface->Clear(Count, pRects, Flags, Color, Z, Stencil);
}

HRESULT CHM2Direct3DDevice9Ex::SetTransform(D3DTRANSFORMSTATETYPE State,CONST D3DMATRIX* pMatrix)
{
	return pWrappedInterface->SetTransform(State, pMatrix);
}

HRESULT CHM2Direct3DDevice9Ex::GetTransform(D3DTRANSFORMSTATETYPE State,D3DMATRIX* pMatrix)
{
	return pWrappedInterface->GetTransform(State, pMatrix);
}

HRESULT CHM2Direct3DDevice9Ex::MultiplyTransform(D3DTRANSFORMSTATETYPE Transform,CONST D3DMATRIX* pMatrix)
{
	return pWrappedInterface->MultiplyTransform(Transform, pMatrix);
}

HRESULT CHM2Direct3DDevice9Ex::SetViewport(CONST D3DVIEWPORT9* pViewport)
{
	return pWrappedInterface->SetViewport(pViewport);
}

HRESULT CHM2Direct3DDevice9Ex::GetViewport(D3DVIEWPORT9* pViewport)
{
	return pWrappedInterface->GetViewport(pViewport);
}

HRESULT CHM2Direct3DDevice9Ex::SetMaterial(CONST D3DMATERIAL9* pMaterial)
{
	return pWrappedInterface->SetMaterial(pMaterial);
}

HRESULT CHM2Direct3DDevice9Ex::GetMaterial(D3DMATERIAL9* pMaterial)
{
	return pWrappedInterface->GetMaterial(pMaterial);
}

HRESULT CHM2Direct3DDevice9Ex::SetLight(DWORD Index,CONST D3DLIGHT9* pLight)
{
	return pWrappedInterface->SetLight(Index, pLight);
}

HRESULT CHM2Direct3DDevice9Ex::GetLight(DWORD Index,D3DLIGHT9* pLight)
{
	return pWrappedInterface->GetLight(Index, pLight);
}

HRESULT CHM2Direct3DDevice9Ex::LightEnable(DWORD Index,BOOL Enable)
{
	return pWrappedInterface->LightEnable(Index,Enable);
}

HRESULT CHM2Direct3DDevice9Ex::GetLightEnable(DWORD Index,BOOL* pEnable)
{
	return pWrappedInterface->GetLightEnable(Index, pEnable);
}

HRESULT CHM2Direct3DDevice9Ex::SetClipPlane(DWORD Index,CONST float* pPlane)
{
	return pWrappedInterface->SetClipPlane(Index, pPlane);
}

HRESULT CHM2Direct3DDevice9Ex::GetClipPlane(DWORD Index,float* pPlane)
{
	return pWrappedInterface->GetClipPlane(Index, pPlane);
}

HRESULT CHM2Direct3DDevice9Ex::SetRenderState(D3DRENDERSTATETYPE State,DWORD Value)
{
	return pWrappedInterface->SetRenderState(State,Value);
}

HRESULT CHM2Direct3DDevice9Ex::GetRenderState(D3DRENDERSTATETYPE State,DWORD* pValue)
{
	return pWrappedInterface->GetRenderState(State, pValue);
}

HRESULT CHM2Direct3DDevice9Ex::CreateStateBlock(D3DSTATEBLOCKTYPE Type,IDirect3DStateBlock9** ppSB)
{
	return pWrappedInterface->CreateStateBlock(Type, ppSB);
}

HRESULT CHM2Direct3DDevice9Ex::BeginStateBlock(void)
{
	return pWrappedInterface->BeginStateBlock();
}

HRESULT CHM2Direct3DDevice9Ex::EndStateBlock(IDirect3DStateBlock9** ppSB)
{
	return pWrappedInterface->EndStateBlock(ppSB);
}

HRESULT CHM2Direct3DDevice9Ex::SetClipStatus(CONST D3DCLIPSTATUS9* pClipStatus)
{
	return pWrappedInterface->SetClipStatus(pClipStatus);
}

HRESULT CHM2Direct3DDevice9Ex::GetClipStatus(D3DCLIPSTATUS9* pClipStatus)
{
	return pWrappedInterface->GetClipStatus(pClipStatus);
}

HRESULT CHM2Direct3DDevice9Ex::GetTexture(DWORD Stage,IDirect3DBaseTexture9** ppTexture)
{
	return pWrappedInterface->GetTexture(Stage, ppTexture);
}

HRESULT CHM2Direct3DDevice9Ex::SetTexture(DWORD Stage,IDirect3DBaseTexture9* pTexture)
{
	return pWrappedInterface->SetTexture(Stage, pTexture);
}

HRESULT CHM2Direct3DDevice9Ex::GetTextureStageState(DWORD Stage,D3DTEXTURESTAGESTATETYPE Type,DWORD* pValue)
{
	return pWrappedInterface->GetTextureStageState(Stage, Type, pValue);
}

HRESULT CHM2Direct3DDevice9Ex::SetTextureStageState(DWORD Stage,D3DTEXTURESTAGESTATETYPE Type,DWORD Value)
{
	return pWrappedInterface->SetTextureStageState(Stage, Type, Value);
}

HRESULT CHM2Direct3DDevice9Ex::GetSamplerState(DWORD Sampler,D3DSAMPLERSTATETYPE Type,DWORD* pValue)
{
	return pWrappedInterface->GetSamplerState(Sampler, Type, pValue);
}

HRESULT CHM2Direct3DDevice9Ex::SetSamplerState(DWORD Sampler,D3DSAMPLERSTATETYPE Type,DWORD Value)
{
	return pWrappedInterface->SetSamplerState(Sampler, Type, Value);
}

HRESULT CHM2Direct3DDevice9Ex::ValidateDevice(DWORD* pNumPasses)
{
	return pWrappedInterface->ValidateDevice(pNumPasses);
}

HRESULT CHM2Direct3DDevice9Ex::SetPaletteEntries(UINT PaletteNumber,CONST PALETTEENTRY* pEntries)
{
	return pWrappedInterface->SetPaletteEntries(PaletteNumber, pEntries);
}

HRESULT CHM2Direct3DDevice9Ex::GetPaletteEntries(UINT PaletteNumber,PALETTEENTRY* pEntries)
{
	return pWrappedInterface->GetPaletteEntries(PaletteNumber,pEntries);
}

HRESULT CHM2Direct3DDevice9Ex::SetCurrentTexturePalette(UINT PaletteNumber)
{
	return pWrappedInterface->SetCurrentTexturePalette(PaletteNumber);
}

HRESULT CHM2Direct3DDevice9Ex::GetCurrentTexturePalette(UINT *PaletteNumber)
{
	return pWrappedInterface->GetCurrentTexturePalette(PaletteNumber);
}

HRESULT CHM2Direct3DDevice9Ex::SetScissorRect(CONST RECT* pRect)
{
	return pWrappedInterface->SetScissorRect(pRect);
}

HRESULT CHM2Direct3DDevice9Ex::GetScissorRect(RECT* pRect)
{
	return pWrappedInterface->GetScissorRect(pRect);
}

HRESULT CHM2Direct3DDevice9Ex::SetSoftwareVertexProcessing(BOOL bSoftware)
{
	return pWrappedInterface->SetSoftwareVertexProcessing(bSoftware);
}

BOOL CHM2Direct3DDevice9Ex::GetSoftwareVertexProcessing(void)
{
	return pWrappedInterface->GetSoftwareVertexProcessing();
}

HRESULT CHM2Direct3DDevice9Ex::SetNPatchMode(float nSegments)
{
	return pWrappedInterface->SetNPatchMode(nSegments);
}

float CHM2Direct3DDevice9Ex::GetNPatchMode(void)
{
	return pWrappedInterface->GetNPatchMode();
}

HRESULT CHM2Direct3DDevice9Ex::DrawPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount)
{
	return pWrappedInterface->DrawPrimitive(PrimitiveType, StartVertex, PrimitiveCount);
}

HRESULT CHM2Direct3DDevice9Ex::DrawIndexedPrimitive(D3DPRIMITIVETYPE PrimitiveType,INT BaseVertexIndex,UINT MinVertexIndex,UINT NumVertices,UINT startIndex,UINT primCount)
{
	return pWrappedInterface->DrawIndexedPrimitive(PrimitiveType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
}

HRESULT CHM2Direct3DDevice9Ex::DrawPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType,UINT PrimitiveCount,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride)
{
	return pWrappedInterface->DrawPrimitiveUP(PrimitiveType, PrimitiveCount, pVertexStreamZeroData, VertexStreamZeroStride);
}

HRESULT CHM2Direct3DDevice9Ex::DrawIndexedPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType,UINT MinVertexIndex,UINT NumVertices,UINT PrimitiveCount,CONST void* pIndexData,D3DFORMAT IndexDataFormat,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride)
{
	return pWrappedInterface->DrawIndexedPrimitiveUP(PrimitiveType, MinVertexIndex, NumVertices, PrimitiveCount, pIndexData, IndexDataFormat, pVertexStreamZeroData, VertexStreamZeroStride);
}

HRESULT CHM2Direct3DDevice9Ex::ProcessVertices(UINT SrcStartIndex,UINT DestIndex,UINT VertexCount,IDirect3DVertexBuffer9* pDestBuffer,IDirect3DVertexDeclaration9* pVertexDecl, DWORD Flags)
{
	return pWrappedInterface->ProcessVertices(SrcStartIndex, DestIndex, VertexCount, pDestBuffer, pVertexDecl, Flags);
}

HRESULT CHM2Direct3DDevice9Ex::CreateVertexDeclaration(CONST D3DVERTEXELEMENT9* pVertexElements,IDirect3DVertexDeclaration9** ppDecl)
{
	return pWrappedInterface->CreateVertexDeclaration(pVertexElements, ppDecl);
}

HRESULT CHM2Direct3DDevice9Ex::SetVertexDeclaration(IDirect3DVertexDeclaration9* pDecl)
{
	return pWrappedInterface->SetVertexDeclaration(pDecl);
}

HRESULT CHM2Direct3DDevice9Ex::GetVertexDeclaration(IDirect3DVertexDeclaration9** ppDecl)
{
	return pWrappedInterface->GetVertexDeclaration(ppDecl);
}

HRESULT CHM2Direct3DDevice9Ex::SetFVF(DWORD FVF)
{
	return pWrappedInterface->SetFVF(FVF);
}

HRESULT CHM2Direct3DDevice9Ex::GetFVF(DWORD* pFVF)
{
	return pWrappedInterface->GetFVF(pFVF);
}

HRESULT CHM2Direct3DDevice9Ex::CreateVertexShader(CONST DWORD* pFunction,IDirect3DVertexShader9** ppShader)
{
	return pWrappedInterface->CreateVertexShader(pFunction, ppShader);
}

HRESULT CHM2Direct3DDevice9Ex::SetVertexShader(IDirect3DVertexShader9* pShader)
{
	return pWrappedInterface->SetVertexShader(pShader);
}

HRESULT CHM2Direct3DDevice9Ex::GetVertexShader(IDirect3DVertexShader9** ppShader)
{
	return pWrappedInterface->GetVertexShader(ppShader);
}

HRESULT CHM2Direct3DDevice9Ex::SetVertexShaderConstantF(UINT StartRegister,CONST float* pConstantData, UINT Vector4fCount)
{
	return pWrappedInterface->SetVertexShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

HRESULT CHM2Direct3DDevice9Ex::GetVertexShaderConstantF(UINT StartRegister,float* pConstantData,UINT Vector4fCount)
{
	return pWrappedInterface->GetVertexShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

HRESULT CHM2Direct3DDevice9Ex::SetVertexShaderConstantI(UINT StartRegister,CONST int* pConstantData,UINT Vector4iCount)
{
	return pWrappedInterface->SetVertexShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

HRESULT CHM2Direct3DDevice9Ex::GetVertexShaderConstantI(UINT StartRegister,int* pConstantData,UINT Vector4iCount)
{
	return pWrappedInterface->GetVertexShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

HRESULT CHM2Direct3DDevice9Ex::SetVertexShaderConstantB(UINT StartRegister,CONST BOOL* pConstantData,UINT  BoolCount)
{
	return pWrappedInterface->SetVertexShaderConstantB(StartRegister, pConstantData,  BoolCount);
}

HRESULT CHM2Direct3DDevice9Ex::GetVertexShaderConstantB(UINT StartRegister,BOOL* pConstantData,UINT BoolCount)
{
	return pWrappedInterface->GetVertexShaderConstantB(StartRegister, pConstantData, BoolCount);
}

HRESULT CHM2Direct3DDevice9Ex::SetStreamSource(UINT StreamNumber,IDirect3DVertexBuffer9* pStreamData,UINT OffsetInBytes,UINT Stride)
{
	return pWrappedInterface->SetStreamSource(StreamNumber, pStreamData, OffsetInBytes, Stride);
}

HRESULT CHM2Direct3DDevice9Ex::GetStreamSource(UINT StreamNumber,IDirect3DVertexBuffer9** ppStreamData,UINT* pOffsetInBytes,UINT* pStride)
{
	return pWrappedInterface->GetStreamSource(StreamNumber, ppStreamData, pOffsetInBytes, pStride);
}

HRESULT CHM2Direct3DDevice9Ex::SetStreamSourceFreq(UINT StreamNumber,UINT Setting)
{
	return pWrappedInterface->SetStreamSourceFreq(StreamNumber, Setting);
}

HRESULT CHM2Direct3DDevice9Ex::GetStreamSourceFreq(UINT StreamNumber,UINT* pSetting)
{
	return pWrappedInterface->GetStreamSourceFreq(StreamNumber, pSetting);
}

HRESULT CHM2Direct3DDevice9Ex::SetIndices(IDirect3DIndexBuffer9* pIndexData)
{
	return pWrappedInterface->SetIndices(pIndexData);
}

HRESULT CHM2Direct3DDevice9Ex::GetIndices(IDirect3DIndexBuffer9** ppIndexData)
{
	return pWrappedInterface->GetIndices(ppIndexData);
}

HRESULT CHM2Direct3DDevice9Ex::CreatePixelShader(CONST DWORD* pFunction,IDirect3DPixelShader9** ppShader)
{
	return pWrappedInterface->CreatePixelShader(pFunction, ppShader);
}

HRESULT CHM2Direct3DDevice9Ex::SetPixelShader(IDirect3DPixelShader9* pShader)
{
	return pWrappedInterface->SetPixelShader(pShader);
}

HRESULT CHM2Direct3DDevice9Ex::GetPixelShader(IDirect3DPixelShader9** ppShader)
{
	return pWrappedInterface->GetPixelShader( ppShader);
}

HRESULT CHM2Direct3DDevice9Ex::SetPixelShaderConstantF(UINT StartRegister,CONST float* pConstantData, UINT Vector4fCount)
{
	return pWrappedInterface->SetPixelShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

HRESULT CHM2Direct3DDevice9Ex::GetPixelShaderConstantF(UINT StartRegister,float* pConstantData,UINT Vector4fCount)
{
	return pWrappedInterface->GetPixelShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

HRESULT CHM2Direct3DDevice9Ex::SetPixelShaderConstantI(UINT StartRegister,CONST int* pConstantData,UINT Vector4iCount)
{
	return pWrappedInterface->SetPixelShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

HRESULT CHM2Direct3DDevice9Ex::GetPixelShaderConstantI(UINT StartRegister,int* pConstantData,UINT Vector4iCount)
{
	return pWrappedInterface->GetPixelShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

HRESULT CHM2Direct3DDevice9Ex::SetPixelShaderConstantB(UINT StartRegister,CONST BOOL* pConstantData,UINT  BoolCount)
{
	return pWrappedInterface->SetPixelShaderConstantB(StartRegister, pConstantData,  BoolCount);
}

HRESULT CHM2Direct3DDevice9Ex::GetPixelShaderConstantB(UINT StartRegister,BOOL* pConstantData,UINT BoolCount)
{
	return pWrappedInterface->GetPixelShaderConstantB(StartRegister, pConstantData, BoolCount);
}

HRESULT CHM2Direct3DDevice9Ex::DrawRectPatch(UINT Handle,CONST float* pNumSegs,CONST D3DRECTPATCH_INFO* pRectPatchInfo)
{
	return pWrappedInterface->DrawRectPatch(Handle, pNumSegs, pRectPatchInfo);
}

HRESULT CHM2Direct3DDevice9Ex::DrawTriPatch(UINT Handle,CONST float* pNumSegs,CONST D3DTRIPATCH_INFO* pTriPatchInfo)
{
	return pWrappedInterface->DrawTriPatch(Handle, pNumSegs, pTriPatchInfo);
}

HRESULT CHM2Direct3DDevice9Ex::DeletePatch(UINT Handle)
{
	return pWrappedInterface->DeletePatch(Handle);
}

HRESULT CHM2Direct3DDevice9Ex::CreateQuery(D3DQUERYTYPE Type,IDirect3DQuery9** ppQuery)
{
	return pWrappedInterface->CreateQuery(Type, ppQuery);
}


HRESULT CHM2Direct3DDevice9Ex::QueryInterface(REFIID iid, void** ppvObject)
{
	if ( ppvObject == nullptr )
		return E_POINTER;

	if ( iid == __uuidof(IUnknown) || iid == __uuidof(IDirect3DDevice9) || iid == __uuidof(IDirect3DDevice9Ex) )
	{
		*ppvObject = static_cast<IUnknown*>(this);
		AddRef();
		return S_OK;
	}
	return E_NOINTERFACE;
}

ULONG CHM2Direct3DDevice9Ex::AddRef()
{
	return InterlockedIncrement(&nRefcount);
}

ULONG CHM2Direct3DDevice9Ex::Release()
{
	 ULONG ref = InterlockedDecrement(&nRefcount);
	 if ( ref == 0 )
		 delete this;
	 return ref;
}

HRESULT CHM2Direct3DDevice9Ex::SetConvolutionMonoKernel(UINT width,UINT height,float* rows,float* columns)
{
	// Unsupported
	return D3D_OK;
}

HRESULT CHM2Direct3DDevice9Ex::ComposeRects(IDirect3DSurface9* pSrc,IDirect3DSurface9* pDst,IDirect3DVertexBuffer9* pSrcRectDescs,UINT NumRects,IDirect3DVertexBuffer9* pDstRectDescs,D3DCOMPOSERECTSOP Operation,int Xoffset,int Yoffset)
{
	// Unsupported
	return D3D_OK;
}

HRESULT CHM2Direct3DDevice9Ex::PresentEx(CONST RECT* pSourceRect,CONST RECT* pDestRect,HWND hDestWindowOverride,CONST RGNDATA* pDirtyRegion,DWORD dwFlags)
{
	return pWrappedInterface->Present(pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
}

HRESULT CHM2Direct3DDevice9Ex::GetGPUThreadPriority(INT* pPriority)
{
	// Unsupported
	return D3D_OK;
}

HRESULT CHM2Direct3DDevice9Ex::SetGPUThreadPriority(INT Priority)
{
	// Unsupported
	return D3D_OK;
}

HRESULT CHM2Direct3DDevice9Ex::WaitForVBlank(UINT iSwapChain)
{
	// Unsupported
	return D3D_OK;
}

HRESULT CHM2Direct3DDevice9Ex::CheckResourceResidency(IDirect3DResource9** pResourceArray,UINT32 NumResources)
{
	// Unsupported
	return S_OK;
}

HRESULT CHM2Direct3DDevice9Ex::SetMaximumFrameLatency(UINT MaxLatency)
{
	// Unsupported
	return D3D_OK;
}

HRESULT CHM2Direct3DDevice9Ex::GetMaximumFrameLatency(UINT* pMaxLatency)
{
	// Unsupported
	return D3D_OK;
}

HRESULT CHM2Direct3DDevice9Ex::CheckDeviceState(HWND hDestinationWindow)
{
	return pWrappedInterface->TestCooperativeLevel();
}

HRESULT CHM2Direct3DDevice9Ex::CreateRenderTargetEx(UINT Width,UINT Height,D3DFORMAT Format,D3DMULTISAMPLE_TYPE MultiSample,DWORD MultisampleQuality,BOOL Lockable,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle,DWORD Usage)
{
	return pWrappedInterface->CreateRenderTarget(Width, Height, Format, MultiSample, MultisampleQuality, Lockable, ppSurface, pSharedHandle);
}

HRESULT CHM2Direct3DDevice9Ex::CreateOffscreenPlainSurfaceEx(UINT Width,UINT Height,D3DFORMAT Format,D3DPOOL Pool,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle,DWORD Usage)
{
	return pWrappedInterface->CreateOffscreenPlainSurface(Width, Height, Format, Pool, ppSurface, pSharedHandle);
}

HRESULT CHM2Direct3DDevice9Ex::CreateDepthStencilSurfaceEx(UINT Width,UINT Height,D3DFORMAT Format,D3DMULTISAMPLE_TYPE MultiSample,DWORD MultisampleQuality,BOOL Discard,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle,DWORD Usage)
{
	return pWrappedInterface->CreateDepthStencilSurface(Width, Height, Format, MultiSample, MultisampleQuality, Discard, ppSurface, pSharedHandle);
}

HRESULT CHM2Direct3DDevice9Ex::ResetEx(D3DPRESENT_PARAMETERS* pPresentationParameters,D3DDISPLAYMODEEX *pFullscreenDisplayMode)
{
	// Broken!
	return pWrappedInterface->Reset(pPresentationParameters);
}

HRESULT CHM2Direct3DDevice9Ex::GetDisplayModeEx(UINT iSwapChain,D3DDISPLAYMODEEX* pMode,D3DDISPLAYROTATION* pRotation)
{
	D3DDISPLAYMODE dummyRetMode;

	HRESULT hResult = pWrappedInterface->GetDisplayMode(iSwapChain, &dummyRetMode);
	pMode->Width = dummyRetMode.Width;
	pMode->Height = dummyRetMode.Height;
	pMode->RefreshRate = dummyRetMode.RefreshRate;
	pMode->Format = dummyRetMode.Format;
	pMode->ScanLineOrdering = D3DSCANLINEORDERING_PROGRESSIVE;

	return hResult;
}

CHM2Direct3DDevice9Ex::CHM2Direct3DDevice9Ex(IDirect3D9* pCreator, UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* pPresentationParameters)
{
	nRefcount = 1;
	pCreator->CreateDevice(Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, &pWrappedInterface);
}

CHM2Direct3DDevice9Ex::~CHM2Direct3DDevice9Ex()
{
	pWrappedInterface->Release();
	pWrappedInterface = nullptr;
}