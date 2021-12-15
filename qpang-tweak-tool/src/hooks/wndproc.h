#pragma once

#include "render/ui.h"

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

namespace hooks {
	inline WNDPROC oWndProc = nullptr;
	LRESULT __stdcall wndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
		if (uMsg == WM_KEYDOWN && wParam == VK_F11) {
			ui::renderWindow = !ui::renderWindow;
			if (ui::renderWindow) {
				SetCursorPos(features::targetWidth / 2, features::targetHeight / 2);
			}
		}
		else if (uMsg == WM_KEYDOWN && wParam == VK_ESCAPE && ui::renderWindow) {
			ui::renderWindow = false;
		}

		if (ui::renderWindow) {
			ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);
			return true;
		}

		return CallWindowProcA(oWndProc, hWnd, uMsg, wParam, lParam);
	}
}
