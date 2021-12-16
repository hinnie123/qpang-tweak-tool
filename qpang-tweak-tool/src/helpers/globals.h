#pragma once

#include <Windows.h>

#include "sdk/guimanager.h"

namespace globals {
	inline eUIState currentUiState = eUIState::UNKNOWN;
	inline eUIState previousUiState = eUIState::UNKNOWN;

	inline HWND qpangWindow = nullptr;
	inline HMODULE qpangModule = nullptr;

	inline uintptr_t* onnetRenderSystem = nullptr;
}