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

		// This member is set to 1337 if the server sent a PveScoreResult packet.
		if (*(uint32_t*)((uintptr_t)packet + 128) == 1337)
			features::masterLogActAsPveScoreResult(packet);
		else
		{
			// The GCPvEShootN2P net event handler uses EDX as first argument.
			// EDX is actually set in the previous function (the net event handler).
			// However, EDX is not omitted in this scenario, so we can grab it here.
			void* _edx = nullptr;
			__asm {
				mov _edx, edx;
			}

			features::masterLogActAsShootN2PPacket(_edx, packet);
		}

		return 0;
	}
}