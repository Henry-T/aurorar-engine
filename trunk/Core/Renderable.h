/********************************************************************
	����ʱ��:	9:2:2012   1:19
	�ļ���	:	Renderable
	������:		����
	
	�ļ�����:	��Ⱦ����ӿ�
*********************************************************************/

#pragma once

#include "Prerequisites.h"

namespace Aurora
{
	interface CORE_API IRenderable : public RenderSysAllocatedObject
	{
		virtual bool	Render() = 0;

		virtual bool	IsTransparent() const = 0;
	};
}
