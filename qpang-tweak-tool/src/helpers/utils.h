#pragma once

#include <Windows.h>
#include <string>

namespace utils {
	bool setUiColor(DWORD dwColor);
	bool setUiColor(float color[4]);

	void callLua(std::string luaFn);
}