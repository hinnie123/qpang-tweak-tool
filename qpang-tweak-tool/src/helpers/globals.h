#pragma once

#include <Windows.h>

namespace globals {
	inline HWND qpangWindow = nullptr;
	inline HMODULE qpangModule = nullptr;

	inline uintptr_t* onnetRenderSystem = nullptr;

	inline int targetWidth = GetSystemMetrics(SM_CXSCREEN);
	inline int targetHeight = GetSystemMetrics(SM_CYSCREEN);
	inline bool fullScreen = false;
}