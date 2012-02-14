/********************************************************************
	创建时间:	14:2:2012   20:50
	文件名	:	ResourceFactory
	创建者:		丁亮
	
	文件作用:	资源工厂 创建所有类型的资源
*********************************************************************/
#pragma once

#include "Prerequisites.h"
#include "..\Common\Singleton.h"
#include "ResourceDefines.h"

namespace Aurora
{
	class CORE_API ResourceFactory : public Singleton<ResourceFactory>, public ResourceAllocatedObject
	{
	public:
		ResourceFactory(void);
		virtual ~ResourceFactory(void);

		static ResourceFactory& getSingleton(void);

		static ResourceFactory* getSingletonPtr(void);

		ResourcePtr				CreateResource(ResourceType type, const String& path, const String& filename);

	protected:

		virtual ResourcePtr		CreateMesh(const String& path, const String& filename) = 0;

		virtual ResourcePtr		CreateTexture(const String& path, const String& filename) = 0;

		virtual ResourcePtr		CreateShader(const String& path, const String& filename) = 0;

		virtual ResourcePtr		CreateVertexDeclaration(const String& path, const String& filename) = 0;

		virtual ResourcePtr		CreateMaterial(const String& path, const String& filename) = 0;

		virtual	ResourcePtr		CreateEffect(const String& path, const String& filename) = 0;
	};
}
