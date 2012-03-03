/********************************************************************
	创建时间:	21:2:2012   8:45
	文件名	:	RenderableManager
	创建者:		丁亮
	
	文件作用:	管理所有的渲染物件 并按其分类保存为不同的渲染队列
				不透明物件：Shader-->RenderableManager-->Renderable
				队列并不直接用于渲染 只用作全局的Renderable容器 真
				正渲染的是Shader中的小队列
				半透明物件：RenderableManager-->Renderable-->Shader
				队列直接用于渲染
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
