/********************************************************************
	创建时间:	8:1:2012   21:48
	文件名: 	f:\Aurorar\Core\Resource.h
	创建者:		丁亮
	
	文件作用:	资源基类
*********************************************************************/

#pragma once
#include "Prerequisites.h"

namespace Aurora
{
	class Resource : public GeneralAllocatedObject
	{
	public:
		Resource(void);
		virtual ~Resource(void);

		const String&	GetName() const;

		virtual bool	Load(const String& szFileName) = 0;

	protected:
		String			m_szName;
	};
}
