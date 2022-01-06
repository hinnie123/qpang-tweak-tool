#pragma once

#include <cstdint>
#include <thread>

#include "helpers/globals.h"

namespace hooks {
	typedef char(__thiscall* tHandleJoinsAndRoundEnd)(void*, void*);
	inline tHandleJoinsAndRoundEnd oHandleJoinsAndRoundEnd = nullptr;

	char __fastcall hkHandleJoinsAndRoundEnd(void* _this, void*, void* packet) {
		if (*(int*)((uintptr_t)packet + 20) == 526) { // GC_PVE_ROUND_END

			*(byte*)(*(uintptr_t*)((uintptr_t)_this + 412) + 1029) = 1; // if this is not 1, nothing will happen
			*(int*)(*(uintptr_t*)((uintptr_t)_this + 412) + 1032) = 0; // something with time, related to the countdown
			*(int*)(*(uintptr_t*)((uintptr_t)_this + 412) + 1036) = 5; // countdown before client sends CG_PVE_ROUND_START

			globals::shouldSendStartRound = true;
			return 0;
		}

		return oHandleJoinsAndRoundEnd(_this, packet);
	}
}