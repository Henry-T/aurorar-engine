#pragma once

#ifdef DX9RENDERER_EXPORTS
#define DX9RENDERER_API __declspec(dllexport)
#else
#define DX9RENDERER_API __declspec(dllimport)
#endif
