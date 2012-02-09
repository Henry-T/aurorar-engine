/********************************************************************
	����ʱ��:	8:1:2012   19:54
	�ļ���: 	f:\Aurorar\Core\BoneWeightBuffer.h
	������:		����
	
	�ļ�����:	����Ȩ�ػ����� ����GPU GEMS2�еĶ���
*********************************************************************/

#pragma once
#include "Prerequisites.h"
#include "../Math/Vector4.h"

namespace Aurora
{
	class CORE_API BoneWeightBuffer : public GeneralAllocatedObject
	{
	public:
		BoneWeightBuffer(void);
		virtual ~BoneWeightBuffer(void);

		typedef vector<Vector4>::type	BoneWeightList;

		void				Clear();
	
		bool				HasWeight() const;

		ushort				GetWeightCountPerVertex() const;

		// ���ݾ�������� ������������
		void				MakeDeclaration();

	protected:
		BoneWeightList		m_vecBoneWeight;

		bool				m_bUseWeight;
	};

	
	


}