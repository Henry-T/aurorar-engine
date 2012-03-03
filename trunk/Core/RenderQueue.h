/********************************************************************
	����ʱ��:	14:2:2012   20:59
	�ļ���	:	RenderQueue
	������:		����
	
	�ļ�����:	��Ⱦ���� ��ͬ���͵�Renderable�����ڲ�ͬ����Ⱦ������
*********************************************************************/

#pragma once

#include "Prerequisites.h"

namespace Aurora
{
	class CORE_API RenderQueue : public RenderSysAllocatedObject
	{
	public:
		RenderQueue(void);
		~RenderQueue(void);

		typedef vector<IRenderablePtr>::type RenderableList;

		void			AddRenderable(IRenderablePtr renderable);

		void			RemoveRenderable(IRenderablePtr renderable);

		void			RemoveAllRenderables();

	private:

		RenderableList	m_vecRenderable;
	};

}

