#include "StdAfx.h"
#include "Model.h"

namespace Aurora
{
	Model::Model(void)
		: m_bIsStatic(false)/*, m_bLightAffect(true)*/
	{
	}

	Model::~Model(void)
	{
	}

	__forceinline bool Model::IsStatic() const
	{
		return m_bIsStatic;
	}

	__forceinline bool Model::IsLightMapUsed() const
	{
		return m_bIsStatic && m_bStaticLightAffect ? true : false;
	}

	__forceinline bool Model::IsNextGen() const
	{
		return m_bIsNextGenModel;
	}

}