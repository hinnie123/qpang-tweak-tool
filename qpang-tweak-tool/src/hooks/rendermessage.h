#pragma once

#include "features/resolution.h"

namespace hooks {
	typedef int(__thiscall* tRenderMessage)(void*, int, wchar_t*, int, int, int, int, bool, bool);
	inline tRenderMessage oRenderMessage = nullptr;

	int __fastcall hkRenderMessage(void* _this, void*, int a2, wchar_t* message, int a4, int a5, int a6, int a7, bool a8, bool a9) {
		features::beforeFixQuitMessage(message);
		return oRenderMessage(_this, a2, message, a4, a5, a6, a7, a8, a9);
	}
}