#pragma once

#include "render/ui.h"

#include "features/ingame.h"
#include "features/gui.h"
#include "features/loginscreensaver.h"

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
		features::sensitivity();
		features::setHighFov();

		//features::positionUiElements();
		features::loginScreenSaver();

		return oPresent(device, pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
	}
}
