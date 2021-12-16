#pragma once

namespace features {
	inline bool sensitivityEnabled = false;
	inline float sensitivityValue = 50.f;
	void sensitivity();
	void restoreSensitivity();
}