#pragma once

namespace features {
	inline bool higherFov = false;
	inline bool sensitivityEnabled = false;
	inline float sensitivityValue = 50.f;

	void setHighFov();
	void sensitivity();
	void restoreSensitivity();
}