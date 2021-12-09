#pragma once

#include <iostream>
#include <fstream>

#include "helpers/globals.h"

#include "lua/squareinit.h"

namespace hooks {
	typedef int(__cdecl* tLuaTinkerDoFile)(DWORD*, const char*);
	inline tLuaTinkerDoFile oLuaTinkerDoFile = nullptr;

	void replaceAll(std::string& str, const std::string& from, const std::string& to) {
		if (from.empty())
			return;

		size_t start_pos = 0;
		while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
			str.replace(start_pos, from.length(), to);
			start_pos += to.length();
		}
	}

	int __cdecl hkLuaTinkerDoFile(DWORD* lua_state, const char* filename) {
		if (strstr(filename, "square_init")) {
			std::string squareInitLua = lua::squareInitLua;
			replaceAll(squareInitLua, "$SCREEN_WIDTH", std::to_string(globals::targetWidth));
			replaceAll(squareInitLua, "$SCREEN_HEIGHT", std::to_string(globals::targetHeight));

			std::string path = std::tmpnam(nullptr);

			std::ofstream out(path);
			out << squareInitLua;
			out.close();

			return oLuaTinkerDoFile(lua_state, path.c_str());
		} else if (strstr(filename, "ingame_init")) {

		}

		return oLuaTinkerDoFile(lua_state, filename);
	}
}