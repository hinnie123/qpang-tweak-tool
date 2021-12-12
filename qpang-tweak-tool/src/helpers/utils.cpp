#pragma once

#include "utils.h"

#include <d3d9types.h>

#include "globals.h"

namespace utils {
	bool setUiColor(DWORD dwColor) {
		uintptr_t unknownInstance = (uintptr_t)globals::qpangModule + 0x3c4860;
		if (!*(int*)(unknownInstance + 0x4)) {
			return false;
		}

		static auto setUiColorFn = (DWORD*(__thiscall*)(void*, DWORD))((uintptr_t)globals::qpangModule + 0x1cd560);
		setUiColorFn((void*)unknownInstance, dwColor);
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
}