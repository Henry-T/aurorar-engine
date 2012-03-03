/********************************************************************
	����ʱ��:	21:2:2012   8:45
	�ļ���	:	RenderableManager
	������:		����
	
	�ļ�����:	�������е���Ⱦ��� ��������ౣ��Ϊ��ͬ����Ⱦ����
				��͸�������Shader-->RenderableManager-->Renderable
				���в���ֱ��������Ⱦ ֻ����ȫ�ֵ�Renderable���� ��
				����Ⱦ����Shader�е�С����
				��͸�������RenderableManager-->Renderable-->Shader
				����ֱ��������Ⱦ
*********************************************************************/

#pragma once

#include "Prerequisites.h"
#include "RenderQueue.h"

namespace Aurora
{
	class CORE_API RenderableManager
	{
	public:
		RenderableManager(void);
		~RenderableManager(void);

		void			AddRenderable(bool transparent);

		RenderQueue		m_SemiTransparentQueue;
		RenderQueue		m_OpaqueQueue;
	};
}
