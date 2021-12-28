#include "pve.h"

#include <Windows.h>
#include <cstdint>

namespace features {
	void masterLogActAsPveScoreResult(void* packet)
	{
		void* newPacket = malloc(1000);
		if (!newPacket)
			return;

		memset(newPacket, 0, 1000);

		// Set the variables of our "GCPvEScoreResult" packet:
		*(int*)((uintptr_t)newPacket + 20) = 534;

		*(uint32_t*)((uintptr_t)newPacket + 88) = *(uint32_t*)((uintptr_t)packet + 88); // playerId
		*(uint32_t*)((uintptr_t)newPacket + 92) = 0;
		*(uint32_t*)((uintptr_t)newPacket + 96) = 0;
		*(uint32_t*)((uintptr_t)newPacket + 100) = 0;
		*(uint32_t*)((uintptr_t)newPacket + 104) = 0;
		*(uint32_t*)((uintptr_t)newPacket + 108) = 0;
		*(uint32_t*)((uintptr_t)newPacket + 112) = *(uint32_t*)((uintptr_t)packet + 112); // prev/best time left in ms
		*(uint32_t*)((uintptr_t)newPacket + 116) = *(uint32_t*)((uintptr_t)packet + 92); // gold coins
		*(uint32_t*)((uintptr_t)newPacket + 120) = *(uint32_t*)((uintptr_t)packet + 96); // silver coins
		*(uint32_t*)((uintptr_t)newPacket + 124) = *(uint32_t*)((uintptr_t)packet + 108); // bronze coins
		*(uint32_t*)((uintptr_t)newPacket + 128) = 0;
		*(uint32_t*)((uintptr_t)newPacket + 132) = 0;
		*(uint32_t*)((uintptr_t)newPacket + 136) = 0;
		*(uint32_t*)((uintptr_t)newPacket + 140) = *(uint32_t*)((uintptr_t)packet + 116); // current time left in ms

		*(uint8_t*)((uintptr_t)newPacket + 144) = *(uint8_t*)((uintptr_t)packet + 104); // didSucceed

		*(uint16_t*)((uintptr_t)newPacket + 146) = 0;
		*(uint16_t*)((uintptr_t)newPacket + 148) = 0;

		// Call the GCPvEScoreResult net event handler function:
		static auto netEventPveScoreResultFn = (void* (__thiscall*)(void*, void*))(0x429f30);
		netEventPveScoreResultFn(*(void**)0x7c109c, newPacket);

		// Cleanup memory:
		free(newPacket);
		newPacket = nullptr;
	}

	void masterLogActAsShootN2PPacket(void* packet)
	{
		auto ptr = *(void**)0x7c109c;
		if (!ptr)
			return;

		ptr = *(void**)((uintptr_t)ptr + 976);
		if (!ptr)
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
		netEventShootN2PFn(ptr, newPacket);

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