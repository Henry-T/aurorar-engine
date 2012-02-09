/********************************************************************
	创建时间:	9:2:2012   23:51
	文件名	:	IndexBuffer
	创建者:		丁亮
	
	文件作用:	索引缓冲区
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


