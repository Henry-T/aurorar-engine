// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 DX9RENDERER_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// DX9RENDERER_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef DX9RENDERER_EXPORTS
#define DX9RENDERER_API __declspec(dllexport)
#else
#define DX9RENDERER_API __declspec(dllimport)
#endif

// 此类是从 DX9Renderer.dll 导出的
class DX9RENDERER_API CDX9Renderer {
public:
	CDX9Renderer(void);
	// TODO: 在此添加您的方法。
};

extern DX9RENDERER_API int nDX9Renderer;

DX9RENDERER_API int fnDX9Renderer(void);
