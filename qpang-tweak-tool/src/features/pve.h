#pragma once

namespace features {
	void masterLogActAsPveScoreResult(void* packet);
	void masterLogActAsShootN2PPacket(void* edx, void* packet);
	void setTweakToolIdentifiers(void* packet);
}