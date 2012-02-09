/********************************************************************
	����ʱ��:	9:2:2012   23:51
	�ļ���	:	IndexBuffer
	������:		����
	
	�ļ�����:	����������
*********************************************************************/
#pragma once

#include "Prerequisites.h"

namespace Aurora
{
	class CORE_API IndexBuffer : public GeometryAllocatedObject
	{
	public:
		IndexBuffer(void);
		~IndexBuffer(void);

		typedef vector<uint32>::type IndexList;

	private:
		IndexList	m_vecIndex;
	};
}


