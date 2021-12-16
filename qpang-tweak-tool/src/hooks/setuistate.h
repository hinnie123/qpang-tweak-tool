#pragma once

#include "helpers/globals.h"

namespace hooks {
	typedef int(__cdecl* tSetUiState)(eUIState);
	inline tSetUiState oSetUiState = nullptr;

	int __cdecl hkSetUiState(eUIState newState) {
		globals::previousUiState = globals::currentUiState;
		globals::currentUiState = newState;

		return oSetUiState(newState);
	}
}