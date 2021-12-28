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

		// The GCPvEShootN2P net event handler uses EDX as first argument.
		// EDX is actually set in the previous function (the net event handler).
		// However, EDX is not omitted in this scenario, so we can grab it here.
		void* _edx = nullptr;
		__asm {
			mov _edx, edx;
		}

		features::masterLogActAsShootN2PPacket(_edx, packet);
		return 0;
	}
}