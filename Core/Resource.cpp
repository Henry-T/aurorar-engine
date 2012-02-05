#include "StdAfx.h"
#include "Resource.h"

namespace Aurora
{
	Resource::Resource(void)
		: m_bIsCatched(false)
	{
	}

	Resource::~Resource(void)
	{
	}

	bool Resource::LessFunctionInMemory( const Resource& e1, const Resource& e2 )
	{
		return true;
	}

	bool Resource::LessFunctionInCache( const Resource& e1, const Resource& e2 )
	{
		return true;
	}

}