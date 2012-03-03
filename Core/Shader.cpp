#include "StdAfx.h"
#include "Shader.h"

namespace Aurora
{
	Shader::Shader(void)
	{
	}

	Shader::~Shader(void)
	{
	}

	bool Shader::Load( String& path, const String& name )
	{
		return __super::Load(path, name);
	}

	void Shader::UnLoad()
	{
		__super::UnLoad();
	}

	void Shader::BeginFrame()
	{

	}

	void Shader::EndFrame()
	{

	}

}
