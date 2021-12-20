#pragma once

#include "features/resolution.h"

namespace hooks {
	typedef void(__thiscall* tClientGameCGMove)(void*, int*);
	inline tClientGameCGMove oClientGameCGMove = nullptr;

	void __fastcall hkClientGameCGMove(void* _this, void*, int* a2)
	{
		// Don't delay CGMoveReport packets
		*(uint8_t*)((uintptr_t)_this + 664 + 8) = 0;
		*(int32_t*)((uintptr_t)_this + 664 + 4) = 0;

		return oClientGameCGMove(_this, a2);
	}
}