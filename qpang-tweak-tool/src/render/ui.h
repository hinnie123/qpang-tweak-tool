#pragma once

#include "imgui.h"
#include "imgui/backends/imgui_impl_dx9.h"
#include "imgui/backends/imgui_impl_win32.h"

#include <d3d9.h>
#include <tchar.h>

namespace ui
{
	inline bool didInit = false;
	inline bool renderWindow = false;

	inline int width = 400;
	inline int height = 300;

	void init(IDirect3DDevice9* device);

	void begin();
	void render();
	void end(IDirect3DDevice9* device);
};