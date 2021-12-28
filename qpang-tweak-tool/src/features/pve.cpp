#include "pve.h"

#include <Windows.h>
#include <cstdint>

namespace features {
	void masterLogActAsShootN2PPacket(void* edx, void* packet)
	{
		if (!edx)
			return;

		// Read all GCPvEShootN2P packet members that reside in the GCMasterLog packet:
		uint32_t npcUid = *(uint32_t*)((uintptr_t)packet + 88);
		uint32_t weaponBodyPartId = *(uint32_t*)((uintptr_t)packet + 92);
		float shootTargetX = *(float*)((uintptr_t)packet + 108);
		float shootTargetY = *(float*)((uintptr_t)packet + 112);
		float shootTargetZ = *(float*)((uintptr_t)packet + 116);

		uint32_t val1 = *(uint32_t*)((uintptr_t)packet + 120);
		uint32_t val2 = *(uint32_t*)((uintptr_t)packet + 124);
		uint64_t unkVal = ((uint64_t)val1) << 32 | val2;

		// Allocate a new packet as our "GCPvEShootN2P" packet:
		void* newPacket = malloc(132);
		if (!newPacket)
			return;

		memset(newPacket, 0, 132);

		// Set the variables of our "GCPvEShootN2P" packet:
		*(int*)((uintptr_t)newPacket + 20) = 516;

		*(uint32_t*)((uintptr_t)newPacket + 88) = npcUid;
		*(uint32_t*)((uintptr_t)newPacket + 92) = weaponBodyPartId;

		*(float*)((uintptr_t)newPacket + 96) = shootTargetX;
		*(float*)((uintptr_t)newPacket + 100) = shootTargetY;
		*(float*)((uintptr_t)newPacket + 104) = shootTargetZ;

		*(uint64_t*)((uintptr_t)newPacket + 112) = unkVal;

		// Call the GCPvEShootN2P net event handler function:
		static auto netEventShootN2PFn = (char(__thiscall*)(void*, void*))(0x4225b0);
		netEventShootN2PFn(edx, newPacket);

		// Cleanup memory:
		free(newPacket);
		newPacket = nullptr;
	}

	void setTweakToolIdentifiers(void* packet)
	{
		// By setting these "unknowns" to 1337, the server knows we're using the tweak tool.
		*(uint32_t*)((uintptr_t)packet + 172) = 1337;
		*(uint32_t*)((uintptr_t)packet + 176) = 1337;
		*(uint32_t*)((uintptr_t)packet + 180) = 1337;
		*(uint32_t*)((uintptr_t)packet + 184) = 1337;
	}
}