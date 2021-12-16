#pragma once

#include "features/gui.h"

namespace hooks {
	typedef bool(__thiscall* tElementShouldDraw)(void*);
	inline tElementShouldDraw oElementShouldDraw = nullptr;

	bool __fastcall hkElementShouldDraw(void* _this, void*) {
		if (features::hideUiEnabled)
			return false;

		return oElementShouldDraw(_this);
	}
}