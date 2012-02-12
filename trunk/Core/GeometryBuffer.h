/********************************************************************
	创建时间:	8:1:2012   19:30
	文件名: 	f:\Aurorar\Core\GeometryBuffer.h
	创建者:		丁亮
	
	文件作用:	几何缓冲区 参照GPU GEMS2中的多流
*********************************************************************/

#pragma once
#include "Prerequisites.h"
#include "../Math/Vector3.h"
#include "ColourValue.h"


namespace Aurora
{
	class CORE_API GeometryBuffer : public ResourceAllocatedObject
	{
	public:
		GeometryBuffer(void);
		virtual ~GeometryBuffer(void);

		typedef vector<Vector3>::type		PositionList,		NormalList;
		
		typedef vector<ColourValue>::type	DiffuseColorList,	SpecularColorList;

		bool				HasNormal() const;

		bool				IsDiffuseColorUsed() const;

		bool				IsSpecularColorUsed() const;

		void				Clear();

	protected:
		PositionList		m_vecPos;				// 坐标

		NormalList			m_vecNormal;			// 法线
		bool				m_bHasNormal;

		DiffuseColorList	m_vecDiffuseColor;		// 顶点色
		bool				m_bUseDiffuseColor;
		SpecularColorList	m_vecSpecularColor;
		bool				m_bUseSpecularColor;

	};

	
	
}

