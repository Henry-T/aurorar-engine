/********************************************************************
	创建时间:	9:2:2012   1:09
	文件名	:	Model
	创建者:		丁亮
	
	文件作用:	模型
*********************************************************************/
#pragma once

#include "Prerequisites.h"
#include "Renderable.h"
#include "..\Math\Vector2.h"

namespace Aurora
{
	struct CORE_API NextGenTextureDesc
	{
		TexturePtr	NormalMap;
		bool		bUseNomalMap;

		TexturePtr	SpecularMap;
		bool		bUseSepcularMap;

		TexturePtr	EmissiveMap;
		bool		bUseEmissiveMap;
	};

	struct CORE_API LightMapDesc
	{
		TexturePtr	LightMap;
		bool		bUseLightMap;

		Vector2		Offset;
	};

	class CORE_API Model : public IRenderable
	{
	public:
		Model(void);
		~Model(void);

		virtual bool		Render() { return true; }

	protected:

		bool				m_bIsStatic;

		MeshPtr				m_pMesh;

		TexturePtr			m_pColorTex;

		NextGenTextureDesc	m_NextGen;

		bool				m_bIsNextGenModel;

		bool				m_bLightAffect;

		LightMapDesc		m_LightMap;
	};
}

