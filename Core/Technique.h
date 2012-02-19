/********************************************************************
	����ʱ��:	17:2:2012   8:20
	�ļ���	:	Technique
	������:		����
	
	�ļ�����:	
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
