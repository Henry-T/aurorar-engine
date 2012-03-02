#include "StdAfx.h"
#include "GeometryBuffer.h"

namespace Aurora
{
	GeometryBuffer::GeometryBuffer(void)
	{
		Clear();
	}

	GeometryBuffer::~GeometryBuffer(void)
	{
		Clear();
	}

	void GeometryBuffer::Clear()
	{
		
		m_bUseDiffuseColor	= false;
		m_bUseSpecularColor = false;
		m_bHasNormal = false;

		m_vecPos.clear();
		m_vecNormal.clear();
	
		m_vecDiffuseColor.clear();
		m_vecSpecularColor.clear();
	}

	__forceinline bool GeometryBuffer::HasNormal() const
	{
		return m_bHasNormal && m_vecNormal.size() ? true : false;
	}

	__forceinline bool GeometryBuffer::IsDiffuseColorUsed() const
	{
		return m_bUseDiffuseColor && m_vecDiffuseColor.size() > 0 ? true : false;
	}


	__forceinline bool GeometryBuffer::IsSpecularColorUsed() const
	{
		return m_bUseSpecularColor && m_vecSpecularColor.size() > 0 ? true : false;
	}


	__forceinline int GeometryBuffer::GetCount() const
	{
		return m_vecSize;
	}

	__forceinline void	GeometryBuffer::SetCount( int size)
	{
		m_vecSize = size;
	}

}