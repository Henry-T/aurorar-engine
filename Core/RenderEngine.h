/********************************************************************
	����ʱ��:	4:1:2012   1:20
	�ļ���	:	RenderEngine
	������:		����
	
	�ļ�����:	��Ⱦ���ܽӿڣ�����ʵ����API�������������
*********************************************************************/
#pragma once
#include "..\MemoryAllocator\MemoryAllocatorConfig.h"
#include "RenderDeviceCaps.h"

namespace Aurora
{
	class CORE_API RenderEngine : public GeneralAllocatedObject
	{
	public:
		RenderEngine(void);
		virtual ~RenderEngine(void);


		// ��ʼ����Ⱦ�豸
		virtual bool InitRenderDeivce(HWND hWnd) = 0;

		// ͨ������ĵײ�API ��ȡ��Ⱦ�豸��������
		virtual void GetRenderDeviceCaps() = 0;



	protected:
		RenderDeviceCaps m_Caps;
	};
}

