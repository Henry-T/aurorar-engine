/********************************************************************
	����ʱ��:	4:1:2012   1:21
	�ļ���	:	DX9RenderEngine
	������:		����
	
	�ļ�����:	��Ⱦ���ܾ���ʵ�� DX9�汾
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
