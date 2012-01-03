/********************************************************************
	����ʱ��:	4:1:2012   0:58
	�ļ���	:	MemoryAllocatorConfig
	������:		����
	
	�ļ�����:	�й��ڴ��������һЩ����
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



