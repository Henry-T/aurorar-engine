/********************************************************************
	����ʱ��:	6:1:2012   17:58
	�ļ���: 	f:\Aurorar\Core\TextureRenderState.h
	������:		����
	
	�ļ�����:	�������Ⱦ״̬
*********************************************************************/
#pragma once

namespace Aurora
{
	enum FilterType
	{
		FT_MIN,
		FT_MAG,
		FT_MIP
	};

	enum FilterOptions
	{
		FO_NONE,
		FO_POINT,
		FO_LINEAR,
		FO_ANISOTROPIC
	};

	enum TextureAddressingMode
	{
		/// Texture wraps at values over 1.0
		TAM_WRAP,
		/// Texture mirrors (flips) at joins over 1.0
		TAM_MIRROR,
		/// Texture clamps at 1.0
		TAM_CLAMP,
		/// Texture coordinates outside the range [0.0, 1.0] are set to the border colour
		TAM_BORDER
	};

}
