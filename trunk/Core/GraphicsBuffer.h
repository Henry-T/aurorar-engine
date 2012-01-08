/********************************************************************
	����ʱ��:	8:1:2012   19:20
	�ļ���: 	f:\Aurorar\Core\GraphicsBuffer.h
	������:		����
	
	�ļ�����:	���㻺����
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