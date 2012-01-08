#include "StdAfx.h"
#include "BoneWeightBuffer.h"

namespace Aurora
{
	BoneWeightBuffer::BoneWeightBuffer(void)
	{
		Clear();
	}

	BoneWeightBuffer::~BoneWeightBuffer(void)
	{
		Clear();
	}

	void BoneWeightBuffer::Clear()
	{
		m_vecBoneWeight.clear();
		m_bUseWeight = false;
	}

	__forceinline bool BoneWeightBuffer::HasWeight() const
	{
		return m_bUseWeight && m_vecBoneWeight.size() > 0 ? true : false;
	}


	__forceinline ushort BoneWeightBuffer::GetWeightCountPerVertex() const
	{
		return HasWeight() ? m_vecBoneWeight.size() : 0;
	}

}