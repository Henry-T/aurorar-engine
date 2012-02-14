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
	class CORE_API GraphicsBuffer : public ResourceAllocatedObject
	{
	public:
		GraphicsBuffer(void);
		virtual ~GraphicsBuffer(void);

		// ���ݾ�������� ������������
		virtual void			MakeDeclaration() = 0;

		virtual void			CreateDeviceBuffer()=0;

	protected:
		GeometryBufferPtr		m_pGeoBuf;
		TextureCoordBufferPtr	m_pTexCoordBuf;
		BoneWeightBufferPtr		m_pBoneWeightBuf;

		VertexDeclarationPtr	m_pVD;
	};
}