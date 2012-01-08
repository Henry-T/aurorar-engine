/********************************************************************
	����ʱ��:	8:1:2012   21:48
	�ļ���: 	f:\Aurorar\Core\Resource.h
	������:		����
	
	�ļ�����:	��Դ����
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
