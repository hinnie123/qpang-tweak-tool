#pragma once

namespace features {
	inline int targetWidth = 0;
	inline int targetHeight = 0;
	inline bool fullScreen = false;

	void fixCursorBounds(void* unknownPointer);
	void fixWorldToScreen(void* unknownPointer);
	void fixResolution(void* unknownPointer);
	void fixStretch();

	void beforeFixQuitMessage(wchar_t* message);
	void fixQuitMessage(float* pos);
}