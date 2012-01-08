/********************************************************************
	创建时间:	8:1:2012   19:46
	文件名: 	f:\Aurorar\Core\TextureCoordBuffer.h
	创建者:		
	
	文件作用:	纹理坐标缓冲区 参照GPU GEMS2中的多流
*********************************************************************/

#pragma once
#include "Prerequisites.h"
#include "Vector2.h"

namespace Aurora
{
	class CORE_API TextureCoordBuffer : public GeneralAllocatedObject
	{
	public:
		TextureCoordBuffer(void);
		~TextureCoordBuffer(void);

		typedef vector<Vector2>::type		UVList;

		bool				IsLightMapUVUsed() const;

		void				Clear();

		// 根据具体的数据 创建顶点声明
		void				MakeDeclaration();

	protected:
		UVList				m_vecObjectUV;			// 自身UV
		UVList				m_vecLightMapUV;		// 光照图UV
		bool				m_bUseLightMapUV;
	};

	

}
