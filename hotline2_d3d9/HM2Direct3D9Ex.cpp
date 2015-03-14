#include "HM2Direct3D9Ex.h"
#include "HM2Direct3DDevice9Ex.h"
#include <Shlwapi.h>

HRESULT CHM2Direct3D9Ex::RegisterSoftwareDevice(void *pInitializeFunction)
{
	return pWrappedInterface->RegisterSoftwareDevice(pInitializeFunction);
}

UINT CHM2Direct3D9Ex::GetAdapterCount()
{
	return pWrappedInterface->GetAdapterCount();
}

HRESULT CHM2Direct3D9Ex::GetAdapterIdentifier(UINT Adapter, DWORD Flags, D3DADAPTER_IDENTIFIER9* pIdentifier)
{
	return pWrappedInterface->GetAdapterIdentifier(Adapter, Flags, pIdentifier);
}

UINT CHM2Direct3D9Ex::GetAdapterModeCount(UINT Adapter, D3DFORMAT Format)
{
	return pWrappedInterface->GetAdapterModeCount(Adapter, Format);
}

HRESULT CHM2Direct3D9Ex::EnumAdapterModes(UINT Adapter, D3DFORMAT Format, UINT Mode, D3DDISPLAYMODE* pMode)
{
	return pWrappedInterface->EnumAdapterModes(Adapter, Format, Mode, pMode);
}

HRESULT CHM2Direct3D9Ex::GetAdapterDisplayMode(UINT Adapter, D3DDISPLAYMODE* pMode)
{
	return pWrappedInterface->GetAdapterDisplayMode(Adapter, pMode);
}

HRESULT CHM2Direct3D9Ex::CheckDeviceType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT DisplayFormat, D3DFORMAT BackBufferFormat, BOOL Windowed)
{
	return pWrappedInterface->CheckDeviceType(Adapter, DeviceType, DisplayFormat, BackBufferFormat, Windowed);
}

HRESULT CHM2Direct3D9Ex::CheckDeviceFormat(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat)
{
	return pWrappedInterface->CheckDeviceFormat(Adapter, DeviceType, AdapterFormat, Usage, RType, CheckFormat);
}

HRESULT CHM2Direct3D9Ex::CheckDeviceMultiSampleType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType, DWORD* pQualityLevels)
{
	return pWrappedInterface->CheckDeviceMultiSampleType(Adapter, DeviceType, SurfaceFormat, Windowed, MultiSampleType, pQualityLevels);
}

HRESULT CHM2Direct3D9Ex::CheckDepthStencilMatch(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat)
{
	return pWrappedInterface->CheckDepthStencilMatch(Adapter, DeviceType, AdapterFormat, RenderTargetFormat, DepthStencilFormat);
}

HRESULT CHM2Direct3D9Ex::CheckDeviceFormatConversion(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SourceFormat, D3DFORMAT TargetFormat)
{
	return pWrappedInterface->CheckDeviceFormatConversion(Adapter, DeviceType, SourceFormat, TargetFormat);
}

HRESULT CHM2Direct3D9Ex::GetDeviceCaps(UINT Adapter, D3DDEVTYPE DeviceType, D3DCAPS9* pCaps)
{
	return pWrappedInterface->GetDeviceCaps(Adapter, DeviceType, pCaps);
}

HMONITOR CHM2Direct3D9Ex::GetAdapterMonitor(UINT Adapter)
{
	return pWrappedInterface->GetAdapterMonitor(Adapter);
}

HRESULT CHM2Direct3D9Ex::CreateDevice(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DDevice9** ppReturnedDeviceInterface)
{
	return pWrappedInterface->CreateDevice(Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, ppReturnedDeviceInterface);
}

UINT CHM2Direct3D9Ex::GetAdapterModeCountEx(UINT Adapter, const D3DDISPLAYMODEFILTER* pFilter)
{
	return pWrappedInterface->GetAdapterModeCount(Adapter, pFilter->Format);
}


HRESULT CHM2Direct3D9Ex::QueryInterface(REFIID iid, void** ppvObject)
{
	if ( ppvObject == nullptr )
		return E_POINTER;

	if ( iid == __uuidof(IUnknown) || iid == __uuidof(IDirect3D9) || iid == __uuidof(IDirect3D9Ex) )
	{
		*ppvObject = static_cast<IUnknown*>(this);
		AddRef();
		return S_OK;
	}
	return E_NOINTERFACE;
}

ULONG CHM2Direct3D9Ex::AddRef()
{
	return InterlockedIncrement(&nRefcount);
}

ULONG CHM2Direct3D9Ex::Release()
{
	 ULONG ref = InterlockedDecrement(&nRefcount);
	 if ( ref == 0 )
		 delete this;
	 return ref;
}

HRESULT CHM2Direct3D9Ex::EnumAdapterModesEx(UINT Adapter, const D3DDISPLAYMODEFILTER *pFilter, UINT Mode, D3DDISPLAYMODEEX *pMode)
{
	D3DDISPLAYMODE dummyRetMode;

	HRESULT hResult = pWrappedInterface->EnumAdapterModes(Adapter, pFilter->Format, Mode, &dummyRetMode);
	pMode->Width = dummyRetMode.Width;
	pMode->Height = dummyRetMode.Height;
	pMode->RefreshRate = dummyRetMode.RefreshRate;
	pMode->Format = dummyRetMode.Format;
	pMode->ScanLineOrdering = D3DSCANLINEORDERING_PROGRESSIVE;

	return hResult;
}

HRESULT CHM2Direct3D9Ex::GetAdapterDisplayModeEx(UINT Adapter, D3DDISPLAYMODEEX* pMode, D3DDISPLAYROTATION* pRotation)
{
	D3DDISPLAYMODE	dummyRetMode;
	HRESULT hResult = pWrappedInterface->GetAdapterDisplayMode(Adapter, &dummyRetMode);
	pMode->Width = dummyRetMode.Width;
	pMode->Height = dummyRetMode.Height;
	pMode->RefreshRate = dummyRetMode.RefreshRate;
	pMode->Format = dummyRetMode.Format;
	pMode->ScanLineOrdering = D3DSCANLINEORDERING_PROGRESSIVE;

	if ( pRotation != NULL )
		*pRotation = D3DDISPLAYROTATION_IDENTITY;

	return hResult;
}

HRESULT CHM2Direct3D9Ex::CreateDeviceEx(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* pPresentationParameters,  D3DDISPLAYMODEEX* pFullscreenDisplayMode, IDirect3DDevice9Ex** ppReturnedDeviceInterface)
{
	// Force windowed mode
	pPresentationParameters->Windowed = TRUE;
	*ppReturnedDeviceInterface = new CHM2Direct3DDevice9Ex(this, Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters);
	return S_OK;
}

HRESULT CHM2Direct3D9Ex::GetAdapterLUID(UINT Adapter, LUID* pLUID)
{
	// This probs won't work
	return S_OK;
}

IDirect3D9*		(WINAPI *pDirect3DCreate9)(UINT SDKVersion);
HMODULE			hD3DLib;

CHM2Direct3D9Ex::CHM2Direct3D9Ex()
{
	if ( pDirect3DCreate9 == nullptr )
	{
		// Initialize the Direct3DCreate9 pointer (safer to do here than in DllMain)
		wchar_t		wcSystemPath[MAX_PATH];
		GetSystemDirectoryW(wcSystemPath, MAX_PATH);
		PathAppendW(wcSystemPath, L"d3d9.dll");

		hD3DLib = LoadLibraryW(wcSystemPath);
		pDirect3DCreate9 = (IDirect3D9*(WINAPI*)(UINT))GetProcAddress(hD3DLib, "Direct3DCreate9");
	}

	nRefcount = 1;
	pWrappedInterface = pDirect3DCreate9(D3D_SDK_VERSION);
}

CHM2Direct3D9Ex::~CHM2Direct3D9Ex()
{
	pWrappedInterface->Release();
	pWrappedInterface = nullptr;
}


HRESULT WINAPI Direct3DCreate9Ex(UINT SDKVersion, IDirect3D9Ex **ppD3D)
{
	*ppD3D = new CHM2Direct3D9Ex();
	return S_OK;	// Might not be enough, but Hotline never checks for this
}