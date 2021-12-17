#pragma once

#include "features/gui.h"

namespace hooks {
	typedef bool(__thiscall* tElementShouldDraw)(UIElement*);
	inline tElementShouldDraw oElementShouldDraw = nullptr;

	bool __fastcall hkElementShouldDraw(UIElement* _this, void*) {
		if (globals::currentUiState == eUIState::GAME || globals::currentUiState == eUIState::SQUARE) {
			if (features::hideUiEnabled)
				return false;
		}

		return oElementShouldDraw(_this);
	}
}