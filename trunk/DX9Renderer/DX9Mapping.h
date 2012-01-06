/********************************************************************
	创建时间:	6:1:2012   15:41
	文件名: 	f:\Aurorar\DX9Renderer\DX9Mapping.h
	创建者:		丁亮
	
	文件作用:	引擎与DX9的数据映射
*********************************************************************/
#pragma once
#include "..\Core\PixelFormat.h"
#include "..\Core\RenderState.h"
#include "..\Core\Texture.h"
#include "..\Core\TextureRenderState.h"
#include "..\Core\BlendMode.h"

namespace Aurora
{
	
	class DX9RENDERER_API DX9Mapping
	{
	public:

		enum eD3DTexType
		{
			/// standard texture
			D3D_TEX_TYPE_NORMAL,
			/// cube texture
			D3D_TEX_TYPE_CUBE,
			/// volume texture
			D3D_TEX_TYPE_VOLUME,
			/// just to have it...
			D3D_TEX_TYPE_NONE
		};

		// 映射像素格式
		static PixelFormat					MappingPF(D3DFORMAT apiPF);
		static D3DFORMAT					MappingPF(PixelFormat enginePF);

		// RenderState

		// 映射着色模式(管线)
		static DWORD						Mapping(ShadeOptions so);

		// 映射比较函数(Depth Test,Alpha Test)
		static DWORD						Mapping(CompareFunction cf);

		// 映射背面剔除
		static DWORD						Mapping(CullingMode cm, bool flip);

		// 映射雾类型(管线)
		static D3DFOGMODE					Mapping(FogMode fm);

		// 映射渲染模式(点 线框 实体)
		static D3DFILLMODE					Mapping(PolygonMode level);

		// 映射模板比较函数
		static DWORD						Mapping(StencilOperation op, bool invert = false);

		// TextureRenderState

		// 映射多重采样类型
		static D3DSAMPLERSTATETYPE			Mapping(FilterType ft);

		// 映射纹理过滤类型
		static DWORD						Mapping(FilterType ft, FilterOptions fo, const D3DCAPS9& devCaps, eD3DTexType texType);
		static eD3DTexType					Mapping(TextureType engineTexType);

		// 映射纹理寻址模式
		static D3DTEXTUREADDRESS			Mapping(TextureAddressingMode tam, const D3DCAPS9& devCaps);

		// BlendMode

		// 映射纹理混合类型
		static D3DTEXTURESTAGESTATETYPE		Mapping(LayerBlendType lbt);

		// 映射纹理混合参数
		static DWORD						Mapping(LayerBlendSource lbs, bool perStageConstants);
		
		// 映射纹理混合操作
		static DWORD						Mapping(LayerBlendOperation lbo, const D3DCAPS9& devCaps);
		
		// 映射场景混合参数
		static D3DBLEND						Mapping(SceneBlendFactor sbf);
		
		// 映射场景混合操作
		static D3DBLENDOP					Mapping(SceneBlendOperation sbo);

		// 矩阵

		// Convert matrix to D3D style
		static 	D3DXMATRIX					MakeD3DXMatrix( const Matrix4& mat );
		// Convert matrix from D3D style
		static Matrix4						ConvertD3DXMatrix( const D3DXMATRIX& mat );

	
	};

}