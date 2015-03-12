#pragma once

#include <d3d9.h>

class CHM2Direct3D9Ex : public IDirect3D9Ex
{
public:
	virtual HRESULT STDMETHODCALLTYPE		QueryInterface(REFIID iid, void** ppvObject);
	virtual ULONG STDMETHODCALLTYPE 		AddRef();
	virtual ULONG STDMETHODCALLTYPE 		Release();

	virtual HRESULT STDMETHODCALLTYPE		RegisterSoftwareDevice(void* pInitializeFunction);
	virtual UINT STDMETHODCALLTYPE			GetAdapterCount();
	virtual HRESULT STDMETHODCALLTYPE		GetAdapterIdentifier(UINT Adapter, DWORD Flags, D3DADAPTER_IDENTIFIER9* pIdentifier);
	virtual UINT STDMETHODCALLTYPE			GetAdapterModeCount(UINT Adapter, D3DFORMAT Format);
	virtual HRESULT STDMETHODCALLTYPE		EnumAdapterModes(UINT Adapter, D3DFORMAT Format, UINT Mode, D3DDISPLAYMODE* pMode);
	virtual HRESULT STDMETHODCALLTYPE		GetAdapterDisplayMode(UINT Adapter, D3DDISPLAYMODE* pMode);
	virtual HRESULT STDMETHODCALLTYPE		CheckDeviceType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT DisplayFormat, D3DFORMAT BackBufferFormat, BOOL Windowed);
	virtual HRESULT STDMETHODCALLTYPE		CheckDeviceFormat(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat);
	virtual HRESULT STDMETHODCALLTYPE		CheckDeviceMultiSampleType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType, DWORD* pQualityLevels);
	virtual HRESULT STDMETHODCALLTYPE		CheckDepthStencilMatch(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat);
	virtual HRESULT STDMETHODCALLTYPE		CheckDeviceFormatConversion(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SourceFormat, D3DFORMAT TargetFormat);
	virtual HRESULT STDMETHODCALLTYPE		GetDeviceCaps(UINT Adapter, D3DDEVTYPE DeviceType, D3DCAPS9* pCaps);
	virtual HMONITOR STDMETHODCALLTYPE		GetAdapterMonitor(UINT Adapter);
	virtual HRESULT STDMETHODCALLTYPE		CreateDevice(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DDevice9** ppReturnedDeviceInterface);

	virtual UINT STDMETHODCALLTYPE			GetAdapterModeCountEx(UINT Adapter, const D3DDISPLAYMODEFILTER* pFilter);
	virtual HRESULT STDMETHODCALLTYPE		EnumAdapterModesEx(UINT Adapter, const D3DDISPLAYMODEFILTER *pFilter, UINT Mode, D3DDISPLAYMODEEX* pMode);
	virtual HRESULT STDMETHODCALLTYPE		GetAdapterDisplayModeEx(UINT Adapter, D3DDISPLAYMODEEX* pMode, D3DDISPLAYROTATION* pRotation);
	virtual HRESULT STDMETHODCALLTYPE		CreateDeviceEx(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* pPresentationParameters,  D3DDISPLAYMODEEX* pFullscreenDisplayMode, IDirect3DDevice9Ex** ppReturnedDeviceInterface);
	virtual HRESULT STDMETHODCALLTYPE		GetAdapterLUID(UINT Adapter, LUID* pLUID);

public:
	CHM2Direct3D9Ex(UINT SDKVersion);
	virtual ~CHM2Direct3D9Ex();

private:
	unsigned int			nRefcount;
	IDirect3D9*				pWrappedInterface;
};