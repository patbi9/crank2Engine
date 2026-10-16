#include "Rendering/Device.h"

HRESULT 
Device::CreateRenderTargetView(
	ID3D11Resource* pResource,
	const D3D11_RENDER_TARGET_VIEW_DESC* pDesc, 
	ID3D11RenderTargetView** ppRTView
	) {

	if (ppRTView == nullptr) {
		ERROR("Device", "CreateRenderTargetView", "Output pointer is null.");
		return E_POINTER;
	}

	*ppRTView = nullptr; //Initialize the output pointer to nullptr

	if (m_device == nullptr || pResource == nullptr) {
		ERROR("Device", "CreateRenderTargetView", "Device or resouce pointer is null.");
		return E_INVALIDARG; //Device not initialized
	}

	HRESULT result = m_device->CreateRenderTargetView(pResource, pDesc, ppRTView);

	if (FAILED(result)) {
		ERROR(
			"Device",
			"CreateRenderTargetView",
			("Failed to create render target view. HRESULT: "
				+ std::to_string(result)).c_str()
		);
		return result;
	}

	MESSAGE("Device", "CreateRenderTargetView", "SUCCESS");
	return result;
}
