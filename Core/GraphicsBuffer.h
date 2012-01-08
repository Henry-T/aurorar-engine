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
	class CORE_API GraphicsBuffer : public GeneralAllocatedObject
	{
	public:
		GraphicsBuffer(void);
		virtual ~GraphicsBuffer(void);

	protected:
		boost::shared_ptr<GeometryBuffer>		m_pGeoBuf;
		boost::shared_ptr<TextureCoordBuffer>	m_pTexCoordBuf;
		boost::shared_ptr<BoneWeightBuffer>		m_pBoneWeightBuf;
	};
}