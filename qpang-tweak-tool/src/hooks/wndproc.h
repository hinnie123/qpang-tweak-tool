#pragma once

#include "render/ui.h"

#include <windowsx.h>

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

namespace hooks {
	inline WNDPROC oWndProc = nullptr;
	LRESULT __stdcall wndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
		if (uMsg == WM_KEYDOWN && wParam == VK_HOME)
			ui::renderWindow = !ui::renderWindow;

		if (ui::renderWindow) {
			if (ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam)) {
				return true;
			}
		}

		return CallWindowProcA(oWndProc, hWnd, uMsg, wParam, lParam);
	}
}
