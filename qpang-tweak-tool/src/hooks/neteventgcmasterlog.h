#pragma once

#include <intrin.h>

#include "features/pve.h"

namespace hooks {
	typedef int(__stdcall* tNetEventGCMasterLog)(void*);
	inline tNetEventGCMasterLog oNetEventGCMasterLog = nullptr;

	int __stdcall hkNetEventGCMasterLog(void* packet) {
		uintptr_t retAddr = (uintptr_t)_ReturnAddress();
		uintptr_t netEventHandlerRetAddr = 0x42ce6e;

		if (retAddr != netEventHandlerRetAddr)
			return 0;

		switch (*(uint32_t*)((uintptr_t)packet + 128))
		{
		case 1337:
			features::masterLogActAsPveScoreResult(packet);
			break;
		case 1338:
			features::masterLogActAsPveSpecialAttack(packet);
			break;
		default:
			features::masterLogActAsShootN2PPacket(packet);
			break;
		}

		return 0;
	}
}