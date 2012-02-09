#include "StdAfx.h"
#include "Texture.h"

namespace Aurora
{
	Texture::Texture(TextureType type)
		: m_eType(type)
	{
	}

	Texture::~Texture(void)
	{
	}

	bool Texture::Load( String& path, const String& name )
	{
		return __super::Load(path, name);
	}

	void Texture::UnLoad()
	{
		__super::UnLoad();
	}

}