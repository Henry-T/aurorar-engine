/********************************************************************
	创建时间:	9:2:2012   0:32
	文件名	:	Mesh
	创建者:		丁亮
	
	文件作用:	网格
*********************************************************************/
#pragma once

#include "Prerequisites.h"
#include "Resource.h"

namespace Aurora
{
	// 去掉了SubMesh的概念 现在Mesh为最小的网格单位
	// 多个SubMesh实现的效果（角色换装）改为一个专用
	// 的模型类里面包含多个Model
	class CORE_API Mesh : public Resource
	{
	public:
		Mesh(void);
		virtual ~Mesh(void);

		virtual bool		Load(String& path, const String& name);

		virtual void		UnLoad();

	protected:
		GraphicsBufferPtr   m_pVB;

		IndexBufferPtr		m_pIB;

	};
}
