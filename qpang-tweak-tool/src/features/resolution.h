#pragma once

#include <string>

namespace features {
	inline int targetWidth = 0;
	inline int targetHeight = 0;
	inline bool fullScreen = false;

	void fixCursorBounds(void* unknownPointer);
	void fixWorldToScreen(void* unknownPointer);
	void fixResolution(void* unknownPointer);
	void fixStretch();

	wchar_t* fixCmdLineW();
	char* fixCmdLineA();

	void beforeFixQuitMessage(wchar_t* message);
	void fixQuitMessage(float* pos);

	void positionUiElements();
}