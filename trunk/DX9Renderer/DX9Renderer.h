#pragma once

#ifdef DX9RENDERER_EXPORTS
#define DX9RENDERER_API __declspec(dllexport)
#else
#define DX9RENDERER_API __declspec(dllimport)
#endif

#include "../Dependencies/dxsdk/Include/d3d9.h"
#include "../Dependencies/dxsdk/Include/d3dx9.h"
#include "../Dependencies/dxsdk/Include/DxErr.h"