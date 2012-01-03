/********************************************************************
	创建时间:	4:1:2012   0:58
	文件名	:	MemoryAllocatorConfig
	创建者:		丁亮
	
	文件作用:	有关内存分配器的一些定义
*********************************************************************/
#pragma once

#include "AllocatedObject.h"
#include "MemoryNedPooling.h"

namespace Aurora
{
	typedef AllocatedObject<NedPoolingPolicy> DefaultAlloc;
}

#ifdef _DEBUG
#	define NED_NEW		new (__FILE__, __LINE__, __FUNCTION__)
#	define NED_DELETE	delete
#else
#	define NED_NEW		new 
#	define NED_DELETE	delete
#endif



