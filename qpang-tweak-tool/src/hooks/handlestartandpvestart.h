#pragma once

#include "features/resolution.h"

namespace hooks {
	typedef void(__thiscall* tHandleStartAndPveStart)(void*, void*);
	inline tHandleStartAndPveStart oHandleStartAndPveStart = nullptr;

	void __fastcall hkHandleStartAndPveStart(void* _this, void*, void* packet) {
		// If gamemode is PVE, set packet id to GC_PVE_START
		if (*(uint16_t*)((uintptr_t)packet + 106) == 9)
			*(int*)((uintptr_t)packet + 20) = 501;

		return oHandleStartAndPveStart(_this, packet);
	}
}