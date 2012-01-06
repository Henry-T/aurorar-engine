/********************************************************************
	����ʱ��:	6:1:2012   15:41
	�ļ���: 	f:\Aurorar\DX9Renderer\DX9Mapping.h
	������:		����
	
	�ļ�����:	������DX9������ӳ��
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

		// ӳ�����ظ�ʽ
		static PixelFormat					MappingPF(D3DFORMAT apiPF);
		static D3DFORMAT					MappingPF(PixelFormat enginePF);

		// RenderState

		// ӳ����ɫģʽ(����)
		static DWORD						Mapping(ShadeOptions so);

		// ӳ��ȽϺ���(Depth Test,Alpha Test)
		static DWORD						Mapping(CompareFunction cf);

		// ӳ�䱳���޳�
		static DWORD						Mapping(CullingMode cm, bool flip);

		// ӳ��������(����)
		static D3DFOGMODE					Mapping(FogMode fm);

		// ӳ����Ⱦģʽ(�� �߿� ʵ��)
		static D3DFILLMODE					Mapping(PolygonMode level);

		// ӳ��ģ��ȽϺ���
		static DWORD						Mapping(StencilOperation op, bool invert = false);

		// TextureRenderState

		// ӳ����ز�������
		static D3DSAMPLERSTATETYPE			Mapping(FilterType ft);

		// ӳ�������������
		static DWORD						Mapping(FilterType ft, FilterOptions fo, const D3DCAPS9& devCaps, eD3DTexType texType);
		static eD3DTexType					Mapping(TextureType engineTexType);

		// ӳ������Ѱַģʽ
		static D3DTEXTUREADDRESS			Mapping(TextureAddressingMode tam, const D3DCAPS9& devCaps);

		// BlendMode

		// ӳ������������
		static D3DTEXTURESTAGESTATETYPE		Mapping(LayerBlendType lbt);

		// ӳ�������ϲ���
		static DWORD						Mapping(LayerBlendSource lbs, bool perStageConstants);
		
		// ӳ�������ϲ���
		static DWORD						Mapping(LayerBlendOperation lbo, const D3DCAPS9& devCaps);
		
		// ӳ�䳡����ϲ���
		static D3DBLEND						Mapping(SceneBlendFactor sbf);
		
		// ӳ�䳡����ϲ���
		static D3DBLENDOP					Mapping(SceneBlendOperation sbo);

		// ����

		// Convert matrix to D3D style
		static 	D3DXMATRIX					MakeD3DXMatrix( const Matrix4& mat );
		// Convert matrix from D3D style
		static Matrix4						ConvertD3DXMatrix( const D3DXMATRIX& mat );

	
	};

}