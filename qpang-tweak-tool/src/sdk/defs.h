#pragma once

#include <Windows.h>

template<typename t>
__forceinline static t GetVirtualFunc(void* _this, int index)
{
    void** vtable = *(void***)_this;
    return (t)(vtable[index]);
}

#define GEN_COMBINE(x, y, z, i) x ## y ## z ## i
#define COMBINE(x, y, z, i) GEN_COMBINE(x, y, z, i)

#define PAD(bytes) private: char COMBINE(__pad_, __COUNTER__, _, __LINE__)[bytes]; public: