#pragma once

#include "features/resolution.h"

namespace hooks {
	typedef int(__thiscall* tSetUnknownPosition)(void*, float*);
	inline tSetUnknownPosition oSetUnknownPosition = nullptr;

	int __fastcall hkSetUnknownPosition(void* _this, void*, float* pos) {
		features::fixQuitMessage(pos);
		return oSetUnknownPosition(_this, pos);
	}
}