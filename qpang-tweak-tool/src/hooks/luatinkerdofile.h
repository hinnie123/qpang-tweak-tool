#pragma once

#include <iostream>
#include <fstream>

#include "helpers/globals.h"

#include "lua/login.h"
#include "lua/squareinit.h"
#include "lua/ingameinit.h"
#include "lua/loadinglua.h"
#include "lua/waitroom.h"

#include "features/resolution.h"
#include "sdk/lua.h"

#define REPLACE_UI_LUA(name, lua) if (strstr(filename, name)) { executeUiLua(lua); return; }

namespace hooks {
	void replaceAll(std::string& str, const std::string& from, const std::string& to) {
		if (from.empty())
			return;

		size_t startPos = 0;
		while ((startPos = str.find(from, startPos)) != std::string::npos) {
			str.replace(startPos, from.length(), to);
			startPos += to.length();
		}
	}

	void executeUiLua(std::string lua) {
		replaceAll(lua, "$SCREEN_WIDTH", std::to_string(features::targetWidth));
		replaceAll(lua, "$SCREEN_HEIGHT", std::to_string(features::targetHeight));

		LuaState::getInstance()->doString(lua);
	}

	typedef void(__cdecl* tLuaTinkerDoFile)(LuaState*, const char*);
	inline tLuaTinkerDoFile oLuaTinkerDoFile = nullptr;

	void __cdecl hkLuaTinkerDoFile(LuaState* lua_state, const char* filename) {
#ifdef _DEBUG
		std::cout << filename << std::endl;
#endif

		REPLACE_UI_LUA("login", lua::loginLua)
		REPLACE_UI_LUA("loading0", lua::loadingLua)
		REPLACE_UI_LUA("loading1", lua::loadingLua)
		REPLACE_UI_LUA("square_init", lua::squareInitLua)
		REPLACE_UI_LUA("WaitRoom", lua::waitRoomLua)
		REPLACE_UI_LUA("ingame_init", lua::ingameInitLua)

		oLuaTinkerDoFile(lua_state, filename);
	}
}