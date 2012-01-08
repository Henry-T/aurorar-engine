#include "StdAfx.h"
#include "TextureCoordBuffer.h"

namespace Aurora
{
	TextureCoordBuffer::TextureCoordBuffer(void)
	{
		Clear();
	}

	TextureCoordBuffer::~TextureCoordBuffer(void)
	{
		Clear();
	}

	void TextureCoordBuffer::Clear()
	{
		m_bUseLightMapUV	= false;
		m_vecObjectUV.clear();
		m_vecLightMapUV.clear();
	}

	__forceinline bool TextureCoordBuffer::IsLightMapUVUsed() const
	{
		return m_bUseLightMapUV && m_vecLightMapUV.size() > 0 ? true : false;
	}

}