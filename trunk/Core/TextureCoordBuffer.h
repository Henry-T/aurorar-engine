/********************************************************************
	����ʱ��:	8:1:2012   19:46
	�ļ���: 	f:\Aurorar\Core\TextureCoordBuffer.h
	������:		
	
	�ļ�����:	�������껺���� ����GPU GEMS2�еĶ���
*********************************************************************/

#pragma once
#include "Prerequisites.h"
#include "Vector2.h"

namespace Aurora
{
	class CORE_API TextureCoordBuffer : public GeneralAllocatedObject
	{
	public:
		TextureCoordBuffer(void);
		~TextureCoordBuffer(void);

		typedef vector<Vector2>::type		UVList;

		bool				IsLightMapUVUsed() const;

		void				Clear();

		// ���ݾ�������� ������������
		void				MakeDeclaration();

	protected:
		UVList				m_vecObjectUV;			// ����UV
		UVList				m_vecLightMapUV;		// ����ͼUV
		bool				m_bUseLightMapUV;
	};

	

}
