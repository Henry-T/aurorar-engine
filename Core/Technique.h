/********************************************************************
	创建时间:	17:2:2012   8:20
	文件名	:	Technique
	创建者:		丁亮
	
	文件作用:	
*********************************************************************/
#pragma once

#include "Prerequisites.h"

namespace Aurora
{
	class CORE_API Technique : public ResourceAllocatedObject
	{
	public:
		Technique(void);
		~Technique(void);

		typedef vector<PassPtr>::type	PassList;

		void		AddPass(PassPtr pass);

		void		RemovePass(const String& passName);

	private:
		String		m_szName;

		PassList	m_vecPass;

		uint8		m_nID;
	};

}
