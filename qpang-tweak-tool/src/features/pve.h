#pragma once

namespace features {
	void masterLogActAsPveSpecialAttack(void* packet);
	void masterLogActAsPveScoreResult(void* packet);
	void masterLogActAsShootN2PPacket(void* packet);

	void setTweakToolIdentifiers(void* packet);
}