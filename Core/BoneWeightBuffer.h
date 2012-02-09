/********************************************************************
	创建时间:	8:1:2012   19:54
	文件名: 	f:\Aurorar\Core\BoneWeightBuffer.h
	创建者:		丁亮
	
	文件作用:	骨骼权重缓冲区 参照GPU GEMS2中的多流
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

		// 根据具体的数据 创建顶点声明
		void				MakeDeclaration();

	protected:
		BoneWeightList		m_vecBoneWeight;

		bool				m_bUseWeight;
	};

	
	


}