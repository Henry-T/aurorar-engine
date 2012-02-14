#include "StdAfx.h"
#include "RenderQueue.h"
#include "Renderable.h"

namespace Aurora
{
	RenderQueue::RenderQueue(void)
		: m_bNeedZSort(false)
	{
	}

	RenderQueue::~RenderQueue(void)
	{
	}

	bool RenderQueue::RenderOneFrame()
	{
		_BeginFrame();

		_Render();

		_EndFrame();

		return true;
	}

	void RenderQueue::_BeginFrame()
	{
		ListenerList::const_iterator iEnd = m_vecListener.end();
		for (ListenerList::const_iterator it = m_vecListener.begin(); it != iEnd; ++it)
		{
			(*it)->BeginFrame(this->shared_from_this());
		}
	}

	void RenderQueue::_Render()
	{
		RenderableList::const_iterator iEnd = m_vecRenderable.end();
		for (RenderableList::const_iterator it = m_vecRenderable.begin(); it != iEnd; ++it)
		{
			assert((*it)->Render() && "äÖÈ¾Îï¼þÊ§°Ü @ RenderQueue::_Render");
		}
	}

	void RenderQueue::_EndFrame()
	{
		ListenerList::const_iterator iEnd = m_vecListener.end();
		for (ListenerList::const_iterator it = m_vecListener.begin(); it != iEnd; ++it)
		{
			(*it)->EndFrame(this->shared_from_this());
		}
	}

}