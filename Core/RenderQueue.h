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
	class CORE_API RenderQueue : public boost::enable_shared_from_this<RenderQueue>, public RenderSysAllocatedObject
	{
	public:
		RenderQueue(void);
		~RenderQueue(void);

		class RenderQueueListener
		{
		public:
			virtual void BeginFrame(RenderQueuePtr rq) {}

			virtual void EndFrame(RenderQueuePtr rq)   {}
		};

		typedef boost::shared_ptr<RenderQueue::RenderQueueListener>	RenderQueueListenerPtr;

		typedef vector<IRenderablePtr>::type RenderableList;

		typedef vector<RenderQueueListenerPtr>::type		 ListenerList;

		bool			RenderOneFrame();

		void			AddListener(RenderQueueListenerPtr listener);

		void			RemoveListener(RenderQueueListenerPtr listener);

		void			RemoveAllListeners();

		void			AddRenderable(IRenderablePtr renderable);

		void			RemoveRenderable(IRenderablePtr renderable);

		void			RemoveAllRenderables();

	private:

		void			_BeginFrame();

		void			_Render();

		void			_EndFrame();

		RenderableList	m_vecRenderable;

		ListenerList	m_vecListener;

		bool			m_bNeedZSort;
	};

}

