#pragma once

#include "features/pve.h"

namespace hooks {
	typedef void* (__thiscall* tFillCGRoomPacket)(void*, int, int, int, char, char, char, void*, wchar_t*, char, char, char, int, char, char, char, int, void*, int);
	inline tFillCGRoomPacket oFillCGRoomPacket = nullptr;

	void* __fastcall hkFillCGRoomPacket(void* packet, void*, int cmd, int playerId, int mapOrValue, char modeOrRoomId, char memberCountOrRoomId, 
		char goal, void* passwordPtr, wchar_t* title, char unk01, char isRounds, char unk02, int unk03, char unk04, char unk05, char unk06, int unk07, void* unk08, int unk09)
	{
		auto retVal = oFillCGRoomPacket(packet, cmd, playerId, mapOrValue, modeOrRoomId, memberCountOrRoomId, goal, passwordPtr, title, unk01, isRounds, unk02, unk03, unk04, 
			unk05, unk06, unk07, unk08, unk09);

		features::setTweakToolIdentifiers(packet);
		return retVal;
	}
}