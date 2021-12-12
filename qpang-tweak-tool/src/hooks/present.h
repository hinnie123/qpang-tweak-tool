#pragma once

#include "render/ui.h"

#include "features/gui.h"

namespace hooks {
	typedef HRESULT(__stdcall* tPresent)(IDirect3DDevice9*, const RECT*, const RECT*, HWND, const RGNDATA*);
	inline tPresent oPresent = nullptr;

	HRESULT __stdcall hkPresent(IDirect3DDevice9* device, const RECT* pSourceRect, const RECT* pDestRect, HWND hDestWindowOverride, const RGNDATA* pDirtyRegion) {
		if (!ui::didInit) {
			ui::init(device);
			ui::didInit = true;
		}

		ui::begin();
		ui::render();
		ui::end(device);

		features::fixStretch();
		features::rainbowUi();

		return oPresent(device, pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
	}
}
