/********************************************************************
	创建时间:	4:1:2012   1:21
	文件名	:	DX9RenderEngine
	创建者:		丁亮
	
	文件作用:	渲染功能具体实现 DX9版本
*********************************************************************/
#pragma once
#include "..\Core\RenderEngine.h"

namespace Aurora
{
	class DX9RENDERER_API DX9RenderEngine : public RenderEngine
	{
	public:
		DX9RenderEngine(void);
		~DX9RenderEngine(void);

		virtual bool InitRenderDeivce(HWND hWnd) { return true; }

		virtual void GetRenderDeviceCaps() {}
	};

}
