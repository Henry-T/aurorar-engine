/********************************************************************
	创建时间:	14:2:2012   20:59
	文件名	:	RenderQueue
	创建者:		丁亮
	
	文件作用:	渲染队列 不同类型的Renderable保存在不同的渲染队列中
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

