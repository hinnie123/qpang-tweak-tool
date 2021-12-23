#pragma once

#include <cstdint>

namespace hooks {
	typedef void(__thiscall* tHandleGCJoin)(void*, void*);
	inline tHandleGCJoin oHandleGCJoin = nullptr;

	void __fastcall hkHandleGCJoin(void* _this, void*, void* packet) {
		// Is the packet id GCJoin (116) ?
		if (*(int*)((uintptr_t)packet + 20) != 116)
			return oHandleGCJoin(_this, packet);

		// If we have coins, set the packet value to 0
		// Under the hood it's actually actionId in the packet that we're setting the coins to on the server.
		// actionId should always be 0.
		uint32_t coins = *(uint32_t*)((uintptr_t)packet + 248);
		if (coins != 0)
			*(uint32_t*)((uintptr_t)packet + 248) = 0;

		// Handle the GCJoin packet as normal
		oHandleGCJoin(_this, packet);

		// Now write the coins value to the player
		auto player = **(uintptr_t**)((uintptr_t)_this + 464);
		*(uint32_t*)(player + 2772) = coins;
	}
}