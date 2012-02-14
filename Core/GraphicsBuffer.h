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
	class CORE_API GraphicsBuffer : public ResourceAllocatedObject
	{
	public:
		GraphicsBuffer(void);
		virtual ~GraphicsBuffer(void);

		// 根据具体的数据 创建顶点声明
		virtual void			MakeDeclaration() = 0;

		virtual void			CreateDeviceBuffer()=0;

	protected:
		GeometryBufferPtr		m_pGeoBuf;
		TextureCoordBufferPtr	m_pTexCoordBuf;
		BoneWeightBufferPtr		m_pBoneWeightBuf;

		VertexDeclarationPtr	m_pVD;
	};
}