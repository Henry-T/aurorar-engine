/********************************************************************
	创建时间:	4:1:2012   1:20
	文件名	:	RenderEngine
	创建者:		丁亮
	
	文件作用:	渲染功能接口，具体实现在API插件的派生类中
*********************************************************************/
#pragma once
#include "..\MemoryAllocator\MemoryAllocatorConfig.h"

namespace Aurora
{
	class CORE_API RenderEngine : public GeneralAllocatedObject
	{
	public:
		RenderEngine(void);
		virtual ~RenderEngine(void);
	};
}

