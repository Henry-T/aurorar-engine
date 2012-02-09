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

	bool Resource::Load( String& path, const String& name )
	{
		if (path.rfind('\\') != 0 || path.rfind('/') != 0)
		{
			path = path + "\\";
		}

		bool ret = MakeAPIObject(path + name);
		if (ret)
		{
			m_szName = name;
		}
		return ret;
	}

	void Resource::UnLoad()
	{
		ReleaseAPIObject();
	}

}