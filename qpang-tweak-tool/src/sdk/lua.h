#pragma once

#include "defs.h"

#include <string_view>

class LuaState {
public:
	static LuaState* getInstance();
	int call(const char* luaFn);
	void doString(std::string_view buffer);
};