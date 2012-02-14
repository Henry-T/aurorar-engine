// FBXLoader.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "String.h"
#include "../Core/Prerequisites.h"




void FBXLOADER_DLL LoadModel( String modelName, GeometryBuffer* pGeometryBuffer)
{
	Loader loader;
	loader.LoadFile( modelName, pGeometryBuffer);
}