#pragma once

#include "features/gui.h"

#include "sdk/guimanager.h"

namespace hooks {
	typedef bool(__thiscall* tElementShouldDraw)(void*);
	inline tElementShouldDraw oElementShouldDraw = nullptr;

	bool __fastcall hkElementShouldDraw(UIElement* _this, void*) {
		if (features::hideUiEnabled) {
			return false;
		}

		return oElementShouldDraw(_this);
	}
}