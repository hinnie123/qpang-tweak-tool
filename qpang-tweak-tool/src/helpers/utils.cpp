#pragma once

#include "utils.h"

#include <d3d9types.h>

#include "globals.h"

#include "sdk/guimanager.h"
#include "sdk/lua.h"

namespace utils {
	bool setUiColor(DWORD dwColor) {
		auto uiManager = GUIManager::getInstance();
		if (!uiManager)
			return false;

		if (uiManager->getNumElements() == 0)
			return false;

		uiManager->setGlobalColor(dwColor);
		return true;
	}

	bool setUiColor(float color[4]) {
		int r = color[0] * 255.f;
		int g = color[1] * 255.f;
		int b = color[2] * 255.f;
		int a = color[3] * 255.f;

		DWORD dwColor = D3DCOLOR_RGBA(r, g, b, a);
		return setUiColor(dwColor);
	}

	void callLua(std::string luaFn) {
		auto luaState = LuaState::getInstance();
		if (!luaState)
			return;

		luaState->call(luaFn.c_str());
	}
}