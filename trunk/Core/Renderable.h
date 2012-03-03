/********************************************************************
	创建时间:	9:2:2012   1:19
	文件名	:	Renderable
	创建者:		丁亮
	
	文件作用:	渲染对象接口
*********************************************************************/

#pragma once

#include "Prerequisites.h"

namespace Aurora
{
	interface CORE_API IRenderable : public RenderSysAllocatedObject
	{
		virtual bool	Render() = 0;

		virtual bool	IsTransparent() const = 0;
	};
}
