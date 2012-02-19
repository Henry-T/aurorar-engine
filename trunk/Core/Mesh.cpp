#include "StdAfx.h"
#include "Mesh.h"

namespace Aurora
{
	Mesh::Mesh(void)
	{
	}

	Mesh::~Mesh(void)
	{
	}

	bool Mesh::Load( String& path, const String& name )
	{
		return __super::Load(path, name);
	}

	void Mesh::UnLoad()
	{
		return __super::UnLoad();
	}

}
