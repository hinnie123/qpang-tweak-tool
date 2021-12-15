#pragma once

#include "defs.h"

class LuaState {
public:
	static LuaState* getInstance();
	int call(const char* luaFn);
};