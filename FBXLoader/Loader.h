#pragma once

#include "String.h"
class KFbxScene;
class KFbxImporter;
class KFbxNode;

namespace FBXLoader
{
class Loader
{
public:
	 const KFbxScene * GetScene() const { return scene; }
	 bool LoadFile();
	 bool LoadFile(String modelName, GeometryBuffer* pGeometryBuffer, IndexBuffer* pIndexBuffer, TextureCoordBuffer* pTextureBuf);

	 
	
private:
	const char* fileName;
	KFbxScene* scene;
	KFbxImporter* importer;

	KFbxNode* selNode;
};
}