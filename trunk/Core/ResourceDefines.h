/********************************************************************
	创建时间:	14:2:2012   19:50
	文件名	:	ResourceDefines
	创建者:		丁亮	
	
	文件作用:	资源相关的一些枚举 宏定义 常量
*********************************************************************/
#pragma once

namespace Aurora
{
	enum CORE_API ResourceType
	{
		RT_SHADER,
		RT_VERTEX_DECL,
		RT_MESH,
		RT_MATERIAL,
		RT_EFFECT,
		RT_TEXTURE,

		RT_MAX
	};
}