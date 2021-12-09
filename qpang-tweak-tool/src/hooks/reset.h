#pragma once

#include "render/ui.h"

namespace hooks {
	typedef HRESULT(__stdcall* tReset)(IDirect3DDevice9*, D3DPRESENT_PARAMETERS*);
	inline tReset oReset = nullptr;

	HRESULT __stdcall hkReset(IDirect3DDevice9* device, D3DPRESENT_PARAMETERS* pPresentationParameters) {
		if (ui::didInit) {
			ImGui_ImplDX9_InvalidateDeviceObjects();
			auto retVal = oReset(device, pPresentationParameters);
			ImGui_ImplDX9_CreateDeviceObjects();
			return retVal;
		}

		return oReset(device, pPresentationParameters);
	}
}