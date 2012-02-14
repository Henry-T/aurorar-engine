#include "StdAfx.h"
#include "ResourceFactory.h"

namespace Aurora
{
	template<> ResourceFactory* Singleton<ResourceFactory>::ms_Singleton = 0;
	ResourceFactory* ResourceFactory::getSingletonPtr(void)
	{
		return ms_Singleton;
	}
	ResourceFactory& ResourceFactory::getSingleton(void)
	{  
		assert( ms_Singleton );  return ( *ms_Singleton );  
	}

	ResourceFactory::ResourceFactory(void)
	{
	}

	ResourceFactory::~ResourceFactory(void)
	{
	}

	Aurora::ResourcePtr ResourceFactory::CreateResource( ResourceType type, const String& path, const String& filename )
	{
		switch(type)
		{
		case RT_MESH:
			{
				return CreateMesh(path, filename);
			}
		case RT_TEXTURE:
			{
				return CreateTexture(path, filename);
			}
		case RT_SHADER:
			{
				return CreateShader(path, filename);
			}
		case RT_VERTEX_DECL:
			{
				return CreateVertexDeclaration(path, filename);
			}
		case RT_MATERIAL:
			{
				return CreateEffect(path, filename);
			}
		default:
			{
				assert(false && "未知的资源类型 @ ResourceFactory::CreateResource");
				ResourcePtr res;
				res.reset();
				return res;
			}
		}
	}

}
