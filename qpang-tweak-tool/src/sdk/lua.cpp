#include "lua.h"

LuaState* LuaState::getInstance() {
#ifdef V2013
	static const auto getLuaStateFn = (LuaState**(*)())(0x421f30);
#else
	static const auto getLuaStateFn = (LuaState**(*)())(0x421cb0);
#endif

	auto stateWrapper = getLuaStateFn();
	if (stateWrapper) {
		return stateWrapper[1];
	}

	return nullptr;
}

int LuaState::call(const char* luaFn) {
#ifdef V2013
	static const auto luaTinkerCallFn = (int(__cdecl*)(void*, const char*))(0x421e10);
#else
	static const auto luaTinkerCallFn = (int(__cdecl*)(void*, const char*))(0x421b90);
#endif
	
	return luaTinkerCallFn(this, luaFn);
}