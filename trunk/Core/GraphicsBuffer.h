/********************************************************************
	创建时间:	8:1:2012   19:20
	文件名: 	f:\Aurorar\Core\GraphicsBuffer.h
	创建者:		丁亮
	
	文件作用:	顶点缓冲区
*********************************************************************/

#pragma once
#include "Prerequisites.h"

namespace Aurora
{
	class CORE_API GraphicsBuffer : public GeometryAllocatedObject
	{
	public:
		GraphicsBuffer(void);
		virtual ~GraphicsBuffer(void);

	protected:
		GeometryBufferPtr		m_pGeoBuf;
		TextureCoordBufferPtr	m_pTexCoordBuf;
		BoneWeightBufferPtr		m_pBoneWeightBuf;
	};
}