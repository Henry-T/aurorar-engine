// FBXLoader.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "String.h"
#include "../Core/Prerequisites.h"




void FBXLOADER_DLL LoadModel( String modelName, GeometryBuffer* pGeometryBuffer)
{
	Loader loader;
	loader.LoadFile( modelName, pGeometryBuffer);
}