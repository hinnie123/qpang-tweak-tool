#pragma once

#include "helpers/globals.h"

namespace hooks {
	typedef void(__thiscall* tSendsPveRoundStartFn)(void*, int);
	inline tSendsPveRoundStartFn oSendsPveRoundStartFn = nullptr;

	void __fastcall hkSendsPveRoundStartFn(void* _this, void*, int a2) {
		if (globals::shouldSendStartRound && a2 == 9) {

			// Normally, the game now sends pve round start in this function, but we're going to do this ourselves.

#ifdef V2013
			auto createPveRoundStartPacketFn = (void*(__fastcall*)(void*, int))(0x647690);
			auto udpSendFn = (void*(__thiscall*)(void*, void*))(0x63f240);
			auto freeNetEventFn = (void*(__thiscall*)(void*))(0x68ac10);
#else
			auto createPveRoundStartPacketFn = (void* (__fastcall*)(void*, int))(0x645a50);
			auto udpSendFn = (void* (__thiscall*)(void*, void*))(0x63d640);
			auto freeNetEventFn = (void* (__thiscall*)(void*))(0x687720);
#endif

			// Allocating 22 * 4 bytes.
			int packet[22] = { 0 };

			createPveRoundStartPacketFn(packet, 0);
			udpSendFn(*(void**)((uintptr_t)_this + 508), packet);
			freeNetEventFn(packet);

			globals::shouldSendStartRound = false;
		}

		return oSendsPveRoundStartFn(_this, a2);
	}
}