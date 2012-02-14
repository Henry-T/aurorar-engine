#include "stdafx.h"

#include "Loader.h"
#include "fbxsdk.h"
#include "GeometryBuffer.h"

namespace FBXLoader
{
// Triangulate all NURBS, patch and mesh under this node recursively.
void TriangulateRecursive(KFbxNode* pNode)
{
	KFbxNodeAttribute* lNodeAttribute = pNode->GetNodeAttribute();

	if (lNodeAttribute)
	{
		if (lNodeAttribute->GetAttributeType() == KFbxNodeAttribute::eMESH ||
			lNodeAttribute->GetAttributeType() == KFbxNodeAttribute::eNURB ||
			lNodeAttribute->GetAttributeType() == KFbxNodeAttribute::eNURBS_SURFACE ||
			lNodeAttribute->GetAttributeType() == KFbxNodeAttribute::ePATCH)
		{
			KFbxGeometryConverter lConverter(pNode->GetFbxSdkManager());
			lConverter.TriangulateInPlace(pNode);
		}
	}

	const int lChildCount = pNode->GetChildCount();
	for (int lChildIndex = 0; lChildIndex < lChildCount; ++lChildIndex)
	{
		TriangulateRecursive(pNode->GetChild(lChildIndex));
	}
}

// Bake node attributes and materials under this node recursively.
// Currently only mesh, light and material.
void LoadCacheRecursive(KFbxNode * pNode, GeometryBuffer* pGeometryBuffer, IndexBuffer pIndexBuffer, TextureCoordBuffer* pTextureBuf)
{
	KFbxNodeAttribute* lNodeAttribute = pNode->GetNodeAttribute();
	if (lNodeAttribute)
	{
		// 将Node数据信息分类存入多流结构当中
		if (lNodeAttribute->GetAttributeType() == KFbxNodeAttribute::eMESH)
		{
			KFbxMesh * lMesh = pNode->GetMesh();
			// 

			if ( lMesh && !lMesh->GetUserDataPtr())
			{
				// 直接写入GeometryBuffer
				int polyCount = lMesh->GetPolygonCount();
				int normalCount = lMesh->GetElementNormalCount();
				int uvCount = lMesh->GetElementUVCount();

				const KFbxVector4 * lControlPoints = lMesh->GetControlPoints();
				const KFbxGeometryElementNormal * lNormalElement =  = lMesh->GetElementNormal(0);
				const KFbxGeometryElementUV * lUVElement =  = lMesh->GetElementUV(0);


				//float * lVertices = new float[polyCount * 4];
				//unsigned int * lIndices = new unsigned int[polyCount * 6];
				//float * lNormals = new float[polyCount * 3];
				//float * lUVs = new float[polyCount * 2];

				int curVertexCnt = 0;

				for (int i = 0; i < polyCount ; i++)
				{
					for (int j = 0; j < 3 ; j++)
					{
						const int lControlPointIndex = lMesh->GetPolygonVertex(i, j);
						KFbxVector4 lCurrentVertex = lControlPoints[lControlPointIndex];


						//lIndices[polyCount * 6 + j] = static_cast<unsigned int>(curVertexCnt);

						//lVertices[curVertexCnt * 4 ] = static_cast<unsigned int>(lCurrentVertex[0]);
						//lVertices[curVertexCnt * 4 +1 ] = static_cast<unsigned int>(lCurrentVertex[1]);
						//lVertices[curVertexCnt * 4 +2] = static_cast<unsigned int>(lCurrentVertex[2]);
						//lVertices[curVertexCnt * 4 +3] = 1;

						Vector3 position(lCurrentVertex[0], lCurrentVertex[1], lCurrentVertex[2]);
						pGeometryBuffer->PositionList.push_back( position);

						// Normal
						int lNormalIndex = i;
						if (lNormalElement->GetReferenceMode() == KFbxLayerElement::eINDEX_TO_DIRECT)
						{
							lNormalIndex = lNormalElement->GetIndexArray().GetAt(i);
						}
						KFbxVector4 lCurrentNormal = lNormalElement->GetDirectArray().GetAt(lNormalIndex);
// 						lNormals[i * 3] = static_cast<float>(lCurrentNormal[0]);
// 						lNormals[i * 3 + 1] = static_cast<float>(lCurrentNormal[1]);
// 						lNormals[i * 3 + 2] = static_cast<float>(lCurrentNormal[2]);

						Vector3 normal(lCurrentNormal[0], lCurrentNormal[1], lCurrentNormal[2]);
						pGeometryBuffer->NormalList.push_back(normal);

						// UV
						int lUVIndex = i;
						if (lUVElement->GetReferenceMode() == KFbxLayerElement::eINDEX_TO_DIRECT)
						{
							lUVIndex = lUVElement->GetIndexArray().GetAt(i);
						}
						KFbxVector2 lCurrentUV = lUVElement->GetDirectArray().GetAt(lUVIndex);
// 						lUVs[i * 2] = static_cast<float>(lCurrentUV[0]);
// 						lUVs[i * 2 + 1] = static_cast<float>(lCurrentUV[1]);

						Vector2 uv(lCurrentUV[0],lCurrentUV[1]);
						pTextureBuf->UVList.push_back(uv);

						curVertexCnt++;
					}
				}

			}
		}
	}

	const int lChildCount = pNode->GetChildCount();
	for (int lChildIndex = 0; lChildIndex < lChildCount; ++lChildIndex)
	{
		LoadCacheRecursive(pNode->GetChild(lChildIndex));
	}
}

// Bake node attributes and materials for this scene and load the textures.
void LoadCacheRecursive(KFbxScene * pScene, const char * pFbxFileName, GeometryBuffer* pGeometryBuffer, IndexBuffer* pIndexBuffer, TextureCoordBuffer* pTextureBuf)
{
	// TODO 载入贴图
	// * 通知资源系统调用专门的Loader载入

	LoadCacheRecursive(pScene->GetRootNode(), pGeometryBuffer, pIndexBuffer);
}

bool Loader::LoadFile(String modelName, GeometryBuffer* pGeometryBuffer, IndexBuffer* pIndexBuffer, TextureCoordBuffer* pTextureBuf)
{
	// 载入静态模型时的方式
	// 遍历所有Node，将所有的Mesh信息合并到一个GeometryBuffer当中
	// * 保存顶点位置信息
	// * 保存法线
	// * 保存UI
	// TODO
	// * Texture
	// * 子材质

	if(!importer->Import(scene))
		return false;

	// TODO 坐标系配置
	KFbxAxisSystem SceneAxisSystem = scene->GetGlobalSettings().GetAxisSystem();
	KFbxAxisSystem OurAxisSystem(KFbxAxisSystem::YAxis, KFbxAxisSystem::ParityOdd, KFbxAxisSystem::RightHanded);
	if( SceneAxisSystem != OurAxisSystem )
		OurAxisSystem.ConvertScene(scene);

	// TODO 单位配置
	KFbxSystemUnit SceneSystemUnit = scene->GetGlobalSettings().GetSystemUnit();
	if( SceneSystemUnit.GetScaleFactor() != 1.0 )
		KFbxSystemUnit::cm.ConvertScene(scene);

	// Convert mesh, NURBS and patch into triangle mesh
	TriangulateRecursive(scene->GetRootNode());

	// 将mesh信息存入缓冲
	LoadCacheRecursive(scene, fileName, pGeometryBuffer, pIndexBuffer);

	importer->Destroy();
	importer = NULL;
}
}