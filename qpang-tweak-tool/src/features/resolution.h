#pragma once

namespace features {
	void fixCursorBounds(void* unknownPointer);
	void fixWorldToScreen(void* unknownPointer);
	void fixResolution(void* unknownPointer);
	void fixStretch();

	void beforeFixQuitMessage(wchar_t* message);
	void fixQuitMessage(float* pos);
}