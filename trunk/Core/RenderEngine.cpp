#include "StdAfx.h"
#include "RenderEngine.h"

namespace Aurora
{
	template<> RenderEngine* Singleton<RenderEngine>::ms_Singleton = 0;
	RenderEngine* RenderEngine::getSingletonPtr(void)
	{
		return ms_Singleton;
	}
	RenderEngine& RenderEngine::getSingleton(void)
	{  
		assert( ms_Singleton );  return ( *ms_Singleton );  
	}

 	RenderEngine::RenderEngine(void) : m_bNvPerfHUDEnabled(false)
 	{
 	}
 
 	RenderEngine::~RenderEngine(void)
 	{
 	}
}

