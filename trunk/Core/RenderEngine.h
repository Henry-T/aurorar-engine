/********************************************************************
	����ʱ��:	4:1:2012   1:20
	�ļ���	:	RenderEngine
	������:		����
	
	�ļ�����:	��Ⱦ���ܽӿڣ�����ʵ����API�������������
*********************************************************************/
#pragma once
#include "..\MemoryAllocator\MemoryAllocatorConfig.h"

namespace Aurora
{
	class CORE_API RenderEngine : public GeneralAllocatedObject
	{
	public:
		RenderEngine(void);
		virtual ~RenderEngine(void);
	};
}

