#pragma once

#include <Windows.h>
#include <string>

namespace utils {
	bool setUiColor(DWORD dwColor);
	bool setUiColor(float color[4]);

	float randomFloat(float min, float max);

	void replaceAll(std::string& str, const std::string& from, const std::string& to);
}