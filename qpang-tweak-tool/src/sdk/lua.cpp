#include "lua.h"

LuaState* LuaState::getInstance() {
	static const auto getLuaStateFn = (LuaState**(*)())(0x421cb0);
	auto stateWrapper = getLuaStateFn();
	if (stateWrapper) {
		return stateWrapper[1];
	}

	return nullptr;
}

int LuaState::call(const char* luaFn) {
	static const auto luaTinkerCallFn = (int(__cdecl*)(void*, const char*))(0x421b90);
	return luaTinkerCallFn(this, luaFn);
}