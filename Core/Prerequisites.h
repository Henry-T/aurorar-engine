/********************************************************************
	创建时间:	6:1:2012   0:31
	文件名	:	Prerequisites
	创建者:		丁亮
	
	文件作用:	一些STL容器相关的类型定义 宽窄字符定义 所有类的前置声明
*********************************************************************/
#pragma once

#include "../Common/Prerequisites.h"
#include "../Math/Prerequisites.h"



namespace Aurora
{
	class RenderEngine;
	class ColourValue;
	struct RenderSettings;
	class GeometryBuffer;
	class TextureCoordBuffer;
	class BoneWeightBuffer;
	class GraphicsBuffer;
	class VertexDeclaration;
	class Resource;
	class ResourceManager;
	class Texture;
	class SubMesh;
	class Mesh;

	class Model;
	struct NextGenTextureDesc;
	struct LightMapDesc;

	interface IRenderable;

	interface IMovable;

	class IndexBuffer;
}

namespace Aurora
{
	typedef boost::shared_ptr<RenderEngine>			RenderEnginePtr;
	typedef boost::shared_ptr<ColourValue>			ColourValuePtr;
	typedef boost::shared_ptr<RenderSettings>		RenderSettingsPtr;
	typedef boost::shared_ptr<GeometryBuffer>		GeometryBufferPtr;
	typedef boost::shared_ptr<TextureCoordBuffer>	TextureCoordBufferPtr;
	typedef boost::shared_ptr<BoneWeightBuffer>		BoneWeightBufferPtr;
	typedef boost::shared_ptr<GraphicsBuffer>		GraphicsBufferPtr;
	typedef boost::shared_ptr<VertexDeclaration>	VertexDeclarationPtr;
	typedef boost::shared_ptr<Resource>				ResourcePtr;
	typedef boost::shared_ptr<ResourceManager>		ResourceManagerPtr;
	typedef boost::shared_ptr<Texture>				TexturePtr;
	typedef boost::shared_ptr<SubMesh>				SubMeshPtr;
	typedef boost::shared_ptr<Mesh>					MeshPtr;

	typedef boost::shared_ptr<Model>				ModelPtr;
	typedef boost::shared_ptr<NextGenTextureDesc>	NextGenTextureDescPtr;
	typedef boost::shared_ptr<LightMapDesc>			LightMapDescPtr;

	typedef boost::shared_ptr<IRenderable>			IRenderablePtr;
	typedef boost::shared_ptr<IMovable>				IMovablePtr;

	typedef boost::shared_ptr<IndexBuffer>			IndexBufferPtr;
}
