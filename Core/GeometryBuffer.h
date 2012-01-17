/********************************************************************
	����ʱ��:	8:1:2012   19:30
	�ļ���: 	f:\Aurorar\Core\GeometryBuffer.h
	������:		����
	
	�ļ�����:	���λ����� ����GPU GEMS2�еĶ���
*********************************************************************/

#pragma once
#include "Prerequisites.h"
#include "../Math/Vector3.h"
#include "ColourValue.h"


namespace Aurora
{
	class CORE_API GeometryBuffer : public GeneralAllocatedObject
	{
	public:
		GeometryBuffer(void);
		virtual ~GeometryBuffer(void);

		typedef vector<Vector3>::type		PositionList,		NormalList;
		
		typedef vector<ColourValue>::type	DiffuseColorList,	SpecularColorList;

		bool				HasNormal() const;

		bool				IsDiffuseColorUsed() const;

		bool				IsSpecularColorUsed() const;

		void				Clear();

		// ���ݾ�������� ������������
		void				MakeDeclaration();

	protected:
		PositionList		m_vecPos;				// ����

		NormalList			m_vecNormal;			// ����
		bool				m_bHasNormal;

		DiffuseColorList	m_vecDiffuseColor;		// ����ɫ
		bool				m_bUseDiffuseColor;
		SpecularColorList	m_vecSpecularColor;
		bool				m_bUseSpecularColor;


		boost::shared_ptr<VertexDeclaration>	m_pVD;

	};

}

