/********************************************************************
	创建时间:	14:1:2012   13:19
	文件名	:	ResourceManager
	创建者:		丁亮
	
	文件作用:	资源管理器 用于统一管理所有的资源 每个资源只保留一份
				数据
*********************************************************************/

#pragma once
#include "Prerequisites.h"

namespace Aurora
{

	class ResourceManager : public ResourceAllocatedObject
	{
	public:
		ResourceManager(void);
		~ResourceManager(void);
	};

}

