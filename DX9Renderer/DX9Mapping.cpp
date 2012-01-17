#include "StdAfx.h"
#include "DX9Mapping.h"
#include "..\Math\Matrix4.h"

namespace Aurora
{


	PixelFormat DX9Mapping::MappingPF( D3DFORMAT apiPF )
	{
		switch(apiPF)
		{
		case D3DFMT_A8:
			return PF_A8;
		case D3DFMT_L8:
			return PF_L8;
		case D3DFMT_L16:
			return PF_L16;
		case D3DFMT_A4L4:
			return PF_A4L4;
		case D3DFMT_A8L8:
			return PF_BYTE_LA;	// Assume little endian here
		case D3DFMT_R3G3B2:
			return PF_R3G3B2;
		case D3DFMT_A1R5G5B5:
			return PF_A1R5G5B5;
		case D3DFMT_A4R4G4B4:
			return PF_A4R4G4B4;
		case D3DFMT_R5G6B5:
			return PF_R5G6B5;
		case D3DFMT_R8G8B8:
			return PF_R8G8B8;
		case D3DFMT_X8R8G8B8:
			return PF_X8R8G8B8;
		case D3DFMT_A8R8G8B8:
			return PF_A8R8G8B8;
		case D3DFMT_X8B8G8R8:
			return PF_X8B8G8R8;
		case D3DFMT_A8B8G8R8:
			return PF_A8B8G8R8;
		case D3DFMT_A2R10G10B10:
			return PF_A2R10G10B10;
		case D3DFMT_A2B10G10R10:
			return PF_A2B10G10R10;
		case D3DFMT_R16F:
			return PF_FLOAT16_R;
		case D3DFMT_A16B16G16R16F:
			return PF_FLOAT16_RGBA;
		case D3DFMT_R32F:
			return PF_FLOAT32_R;
		case D3DFMT_G32R32F:
			return PF_FLOAT32_GR;
		case D3DFMT_A32B32G32R32F:
			return PF_FLOAT32_RGBA;
		case D3DFMT_G16R16F:
			return PF_FLOAT16_GR;
		case D3DFMT_A16B16G16R16:
			return PF_SHORT_RGBA;
		case D3DFMT_G16R16:
			return PF_SHORT_GR;
		case D3DFMT_DXT1:
			return PF_DXT1;
		case D3DFMT_DXT2:
			return PF_DXT2;
		case D3DFMT_DXT3:
			return PF_DXT3;
		case D3DFMT_DXT4:
			return PF_DXT4;
		case D3DFMT_DXT5:
			return PF_DXT5;
		case D3DFMT_D16_LOCKABLE:
			return PF_D16_LOCKABLE;
		case D3DFMT_D32:
			return PF_D32;
		case D3DFMT_D15S1:
			return PF_D15S1;
		case D3DFMT_D24X8:
			return PF_D24X8;
		case D3DFMT_D24X4S4:
			return PF_D24X4S4;
		case D3DFMT_D16:
			return PF_D16;
		case D3DFMT_D24S8:
			return PF_D24S8;
		case D3DFMT_D32F_LOCKABLE:
			return PF_D32F_LOCKABLE;
		case D3DFMT_D24FS8:
			return PF_D24FS8;
		default:
			return PF_UNKNOWN;
		}

	}

	D3DFORMAT DX9Mapping::MappingPF( PixelFormat enginePF )
	{
		switch(enginePF)
		{
		case PF_L8:
			return D3DFMT_L8;
		case PF_L16:
			return D3DFMT_L16;
		case PF_A8:
			return D3DFMT_A8;
		case PF_A4L4:
			return D3DFMT_A4L4;
		case PF_BYTE_LA:
			return D3DFMT_A8L8; // Assume little endian here
		case PF_R3G3B2:
			return D3DFMT_R3G3B2;
		case PF_A1R5G5B5:
			return D3DFMT_A1R5G5B5;
		case PF_R5G6B5:
			return D3DFMT_R5G6B5;
		case PF_A4R4G4B4:
			return D3DFMT_A4R4G4B4;
		case PF_R8G8B8:
			return D3DFMT_R8G8B8;
		case PF_A8R8G8B8:
			return D3DFMT_A8R8G8B8;
		case PF_A8B8G8R8:
			return D3DFMT_A8B8G8R8;
		case PF_X8R8G8B8:
			return D3DFMT_X8R8G8B8;
		case PF_X8B8G8R8:
			return D3DFMT_X8B8G8R8;
		case PF_A2B10G10R10:
			return D3DFMT_A2B10G10R10;
		case PF_A2R10G10B10:
			return D3DFMT_A2R10G10B10;
		case PF_FLOAT16_R:
			return D3DFMT_R16F;
		case PF_FLOAT16_GR:
			return D3DFMT_G16R16F;
		case PF_FLOAT16_RGBA:
			return D3DFMT_A16B16G16R16F;
		case PF_FLOAT32_R:
			return D3DFMT_R32F;
		case PF_FLOAT32_GR:
			return D3DFMT_G32R32F;
		case PF_FLOAT32_RGBA:
			return D3DFMT_A32B32G32R32F;
		case PF_SHORT_RGBA:
			return D3DFMT_A16B16G16R16;
		case PF_SHORT_GR:
			return D3DFMT_G16R16;
		case PF_DXT1:
			return D3DFMT_DXT1;
		case PF_DXT2:
			return D3DFMT_DXT2;
		case PF_DXT3:
			return D3DFMT_DXT3;
		case PF_DXT4:
			return D3DFMT_DXT4;
		case PF_DXT5:
			return D3DFMT_DXT5;
		case PF_D16_LOCKABLE:
			return D3DFMT_D16_LOCKABLE;
		case PF_D32:
			return D3DFMT_D32;
		case PF_D15S1:
			return D3DFMT_D15S1;
		case PF_D24X8:
			return D3DFMT_D24X8;
		case PF_D24X4S4:
			return D3DFMT_D24X4S4;
		case PF_D16:
			return D3DFMT_D16;
		case PF_D24S8:
			return D3DFMT_D24S8;
		case PF_D32F_LOCKABLE:
			return D3DFMT_D32F_LOCKABLE;
		case PF_D24FS8:
			return D3DFMT_D24FS8;
		case PF_UNKNOWN:
		default:
			return D3DFMT_UNKNOWN;
		}
	}

	DWORD DX9Mapping::Mapping( ShadeOptions so )
	{
		switch( so )
		{
		case SO_FLAT:
			return D3DSHADE_FLAT;
		case SO_GOURAUD:
			return D3DSHADE_GOURAUD;
		case SO_PHONG:
			return D3DSHADE_PHONG;
		}
		return 0;
	}

	DWORD DX9Mapping::Mapping( CompareFunction cf )
	{
		switch( cf )
		{
		case CMPF_ALWAYS_FAIL:
			return D3DCMP_NEVER;
		case CMPF_ALWAYS_PASS:
			return D3DCMP_ALWAYS;
		case CMPF_LESS:
			return D3DCMP_LESS;
		case CMPF_LESS_EQUAL:
			return D3DCMP_LESSEQUAL;
		case CMPF_EQUAL:
			return D3DCMP_EQUAL;
		case CMPF_NOT_EQUAL:
			return D3DCMP_NOTEQUAL;
		case CMPF_GREATER_EQUAL:
			return D3DCMP_GREATEREQUAL;
		case CMPF_GREATER:
			return D3DCMP_GREATER;
		};
		return 0;
	}

	DWORD DX9Mapping::Mapping( CullingMode cm, bool flip )
	{
		switch( cm )
		{
		case CULL_NONE:
			return D3DCULL_NONE;
		case CULL_CLOCKWISE:
			if( flip )
				return D3DCULL_CCW;
			else
				return D3DCULL_CW;
		case CULL_ANTICLOCKWISE:
			if( flip )
				return D3DCULL_CW;
			else
				return D3DCULL_CCW;
		}
		return 0;
	}

	D3DFOGMODE DX9Mapping::Mapping( FogMode fm )
	{
		switch( fm )
		{
		case FOG_EXP:
			return D3DFOG_EXP;
		case FOG_EXP2:
			return D3DFOG_EXP2;
		case FOG_LINEAR:
			return D3DFOG_LINEAR;
		}
		return D3DFOG_FORCE_DWORD;
	}

	D3DFILLMODE DX9Mapping::Mapping( PolygonMode level )
	{
		switch(level)
		{
		case PM_POINTS:
			return D3DFILL_POINT;
		case PM_WIREFRAME:
			return D3DFILL_WIREFRAME;
		case PM_SOLID:
			return D3DFILL_SOLID;
		}
		return D3DFILL_FORCE_DWORD;
	}

	DWORD DX9Mapping::Mapping( StencilOperation op, bool invert /*= false*/ )
	{
		switch(op)
		{
		case SOP_KEEP:
			return D3DSTENCILOP_KEEP;
		case SOP_ZERO:
			return D3DSTENCILOP_ZERO;
		case SOP_REPLACE:
			return D3DSTENCILOP_REPLACE;
		case SOP_INCREMENT:
			return invert? D3DSTENCILOP_DECRSAT : D3DSTENCILOP_INCRSAT;
		case SOP_DECREMENT:
			return invert? D3DSTENCILOP_INCRSAT : D3DSTENCILOP_DECRSAT;
		case SOP_INCREMENT_WRAP:
			return invert? D3DSTENCILOP_DECR : D3DSTENCILOP_INCR;
		case SOP_DECREMENT_WRAP:
			return invert? D3DSTENCILOP_INCR : D3DSTENCILOP_DECR;
		case SOP_INVERT:
			return D3DSTENCILOP_INVERT;
		}
		return 0;
	}

	D3DSAMPLERSTATETYPE DX9Mapping::Mapping( FilterType ft )
	{
		switch (ft)
		{
		case FT_MIN:
			return D3DSAMP_MINFILTER;
			break;
		case FT_MAG:
			return D3DSAMP_MAGFILTER;
			break;
		case FT_MIP:
			return D3DSAMP_MIPFILTER;
			break;
		}

		// to keep compiler happy
		return D3DSAMP_MINFILTER;
	}

	DWORD DX9Mapping::Mapping( FilterType ft, FilterOptions fo, const D3DCAPS9& devCaps, eD3DTexType texType )
	{
		// Assume normal
		DWORD capsType = devCaps.TextureFilterCaps;

		switch( texType )
		{
		case D3D_TEX_TYPE_NORMAL:
			capsType = devCaps.TextureFilterCaps;
			break;
		case D3D_TEX_TYPE_CUBE:
			capsType = devCaps.CubeTextureFilterCaps;
			break;
		case D3D_TEX_TYPE_VOLUME:
			capsType = devCaps.VolumeTextureFilterCaps;
			break;
		}

		switch (ft)
		{
		case FT_MIN:
			switch( fo )
			{
				// NOTE: Fall through if device doesn't support requested type
			case FO_ANISOTROPIC:
				if( capsType & D3DPTFILTERCAPS_MINFANISOTROPIC )
				{
					return D3DTEXF_ANISOTROPIC;
					break;
				}
			case FO_LINEAR:
				if( capsType & D3DPTFILTERCAPS_MINFLINEAR )
				{
					return D3DTEXF_LINEAR;
					break;
				}
			case FO_POINT:
			case FO_NONE:
				return D3DTEXF_POINT;
				break;
			}
			break;
		case FT_MAG:
			switch( fo )
			{
				// NOTE: Fall through if device doesn't support requested type
			case FO_ANISOTROPIC:
				if( capsType & D3DPTFILTERCAPS_MAGFANISOTROPIC )
				{
					return D3DTEXF_ANISOTROPIC;
					break;
				}
			case FO_LINEAR:
				if( capsType & D3DPTFILTERCAPS_MAGFLINEAR )
				{
					return D3DTEXF_LINEAR;
					break;
				}
			case FO_POINT:
			case FO_NONE:
				return D3DTEXF_POINT;
				break;
			}
			break;
		case FT_MIP:
			switch( fo )
			{
			case FO_ANISOTROPIC:
			case FO_LINEAR:
				if( capsType & D3DPTFILTERCAPS_MIPFLINEAR )
				{
					return D3DTEXF_LINEAR;
					break;
				}
			case FO_POINT:
				if( capsType & D3DPTFILTERCAPS_MIPFPOINT )
				{
					return D3DTEXF_POINT;
					break;
				}
			case FO_NONE:
				return D3DTEXF_NONE;
				break;
			}
			break;
		}

		// should never get here
		return 0;
	}

	DX9Mapping::eD3DTexType DX9Mapping::Mapping( TextureType engineTexType )
	{
		switch( engineTexType )
		{
		case TEX_TYPE_1D :
		case TEX_TYPE_2D :
			return DX9Mapping::D3D_TEX_TYPE_NORMAL;
		case TEX_TYPE_CUBE_MAP :
			return DX9Mapping::D3D_TEX_TYPE_CUBE;
		case TEX_TYPE_3D :
			return DX9Mapping::D3D_TEX_TYPE_VOLUME;
		}
		return DX9Mapping::D3D_TEX_TYPE_NONE;
	}

	D3DTEXTUREADDRESS DX9Mapping::Mapping( TextureAddressingMode tam, const D3DCAPS9& devCaps )
	{
		switch( tam )
		{
		case TAM_WRAP:
			return D3DTADDRESS_WRAP;
		case TAM_MIRROR:
			return D3DTADDRESS_MIRROR;
		case TAM_CLAMP:
			return D3DTADDRESS_CLAMP;
		case TAM_BORDER:
			if (devCaps.TextureAddressCaps & D3DPTADDRESSCAPS_BORDER)
				return D3DTADDRESS_BORDER;
			else
				return D3DTADDRESS_CLAMP;
		}
		return D3DTADDRESS_FORCE_DWORD;
	}

	D3DTEXTURESTAGESTATETYPE DX9Mapping::Mapping( LayerBlendType lbt )
	{
		switch( lbt )
		{
		case LBT_COLOUR:
			return D3DTSS_COLOROP;
		case LBT_ALPHA:
			return D3DTSS_ALPHAOP;
		}
		return  D3DTSS_FORCE_DWORD;
	}

	DWORD DX9Mapping::Mapping( LayerBlendSource lbs, bool perStageConstants )
	{
		switch( lbs )
		{
		case LBS_CURRENT:
			return D3DTA_CURRENT;
		case LBS_TEXTURE:
			return D3DTA_TEXTURE;
		case LBS_DIFFUSE:
			return D3DTA_DIFFUSE;
		case LBS_SPECULAR:
			return D3DTA_SPECULAR;
		case LBS_MANUAL:
			return perStageConstants ? D3DTA_CONSTANT : D3DTA_TFACTOR;
		}
		return 0;
	}

	DWORD DX9Mapping::Mapping( LayerBlendOperation lbo, const D3DCAPS9& devCaps )
	{
		switch( lbo )
		{
		case LBX_SOURCE1:
			return D3DTOP_SELECTARG1;
		case LBX_SOURCE2:
			return D3DTOP_SELECTARG2;
		case LBX_MODULATE:
			return D3DTOP_MODULATE;
		case LBX_MODULATE_X2:
			return D3DTOP_MODULATE2X;
		case LBX_MODULATE_X4:
			return D3DTOP_MODULATE4X;
		case LBX_ADD:
			return D3DTOP_ADD;
		case LBX_ADD_SIGNED:
			return D3DTOP_ADDSIGNED;
		case LBX_ADD_SMOOTH:
			return D3DTOP_ADDSMOOTH;
		case LBX_SUBTRACT:
			return D3DTOP_SUBTRACT;
		case LBX_BLEND_DIFFUSE_ALPHA:
			return D3DTOP_BLENDDIFFUSEALPHA;
		case LBX_BLEND_TEXTURE_ALPHA:
			return D3DTOP_BLENDTEXTUREALPHA;
		case LBX_BLEND_CURRENT_ALPHA:
			return D3DTOP_BLENDCURRENTALPHA;
		case LBX_BLEND_MANUAL:
			return D3DTOP_BLENDFACTORALPHA;
		case LBX_DOTPRODUCT:
			if (devCaps.TextureOpCaps & D3DTEXOPCAPS_DOTPRODUCT3)
				return D3DTOP_DOTPRODUCT3;
			else
				return D3DTOP_MODULATE;
		case LBX_BLEND_DIFFUSE_COLOUR:
			if (devCaps.TextureOpCaps & D3DTEXOPCAPS_LERP)
				return D3DTOP_LERP;
			else
				return D3DTOP_MODULATE;
		}
		return 0;
	}

	D3DBLEND DX9Mapping::Mapping( SceneBlendFactor sbf )
	{
		switch( sbf )
		{
		case SBF_ONE:
			return D3DBLEND_ONE;
		case SBF_ZERO:
			return D3DBLEND_ZERO;
		case SBF_DEST_COLOUR:
			return D3DBLEND_DESTCOLOR;
		case SBF_SOURCE_COLOUR:
			return D3DBLEND_SRCCOLOR;
		case SBF_ONE_MINUS_DEST_COLOUR:
			return D3DBLEND_INVDESTCOLOR;
		case SBF_ONE_MINUS_SOURCE_COLOUR:
			return D3DBLEND_INVSRCCOLOR;
		case SBF_DEST_ALPHA:
			return D3DBLEND_DESTALPHA;
		case SBF_SOURCE_ALPHA:
			return D3DBLEND_SRCALPHA;
		case SBF_ONE_MINUS_DEST_ALPHA:
			return D3DBLEND_INVDESTALPHA;
		case SBF_ONE_MINUS_SOURCE_ALPHA:
			return D3DBLEND_INVSRCALPHA;
		}
		return D3DBLEND_FORCE_DWORD;
	}

	D3DBLENDOP DX9Mapping::Mapping( SceneBlendOperation sbo )
	{
		switch(sbo)
		{
		case SBO_ADD:
			return D3DBLENDOP_ADD;
		case SBO_SUBTRACT:
			return D3DBLENDOP_SUBTRACT;
		case SBO_REVERSE_SUBTRACT:
			return D3DBLENDOP_REVSUBTRACT;
		case SBO_MIN:
			return D3DBLENDOP_MIN;
		case SBO_MAX:
			return D3DBLENDOP_MAX;
		}

		return D3DBLENDOP_FORCE_DWORD;
	}

	D3DXMATRIX DX9Mapping::MakeD3DXMatrix( const Matrix4& mat )
	{
		// Transpose matrix
		// D3D9 uses row vectors i.e. V*M
		// Ogre, OpenGL and everything else uses column vectors i.e. M*V
		return D3DXMATRIX(
			mat[0][0], mat[1][0], mat[2][0], mat[3][0],
			mat[0][1], mat[1][1], mat[2][1], mat[3][1],
			mat[0][2], mat[1][2], mat[2][2], mat[3][2],
			mat[0][3], mat[1][3], mat[2][3], mat[3][3]);
	}

	Aurora::Matrix4 DX9Mapping::ConvertD3DXMatrix( const D3DXMATRIX& mat )
	{
		return Matrix4(
			mat.m[0][0], mat.m[1][0], mat.m[2][0], mat.m[3][0],
			mat.m[0][1], mat.m[1][1], mat.m[2][1], mat.m[3][1],
			mat.m[0][2], mat.m[1][2], mat.m[2][2], mat.m[3][2],
			mat.m[0][3], mat.m[1][3], mat.m[2][3], mat.m[3][3]);
	}

}