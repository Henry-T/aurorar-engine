#include "StdAfx.h"
#include "Resource.h"

namespace Aurora
{
	Resource::Resource(void)
	{
	}

	Resource::~Resource(void)
	{
	}

	const String& Aurora::Resource::GetName() const
	{
		return m_szName;
	}

}