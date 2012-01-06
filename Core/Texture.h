/********************************************************************
	创建时间:	6:1:2012   18:04
	文件名: 	f:\Aurorar\Core\Texture.h
	创建者:		丁亮
	
	文件作用:	纹理
*********************************************************************/
#pragma once

#include "Prerequisites.h"

namespace Aurora
{
	enum TextureType
	{
		/// 1D texture, used in combination with 1D texture coordinates
		TEX_TYPE_1D = 1,
		/// 2D texture, used in combination with 2D texture coordinates (default)
		TEX_TYPE_2D = 2,
		/// 3D volume texture, used in combination with 3D texture coordinates
		TEX_TYPE_3D = 3,
		/// 3D cube map, used in combination with 3D texture coordinates
		TEX_TYPE_CUBE_MAP = 4,
		/// 2D texture array
		TEX_TYPE_2D_ARRAY = 5
	};

	class CORE_API Texture
	{
	public:

		Texture(void);
		virtual ~Texture(void);
	};

}