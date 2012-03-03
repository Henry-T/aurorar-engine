/********************************************************************
	����ʱ��:	9:2:2012   1:09
	�ļ���	:	Model
	������:		����
	
	�ļ�����:	ģ��
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

		virtual bool		Render()				{ return true; }

		virtual bool		IsTransparent() const	{ return true; }

		bool				IsStatic() const;

		bool				IsLightMapUsed() const;

		bool				IsNextGen() const;

	protected:

		bool				m_bIsStatic;

		MeshPtr				m_pMesh;

		TexturePtr			m_pColorTex;

		NextGenTextureDesc	m_NextGen;

		bool				m_bIsNextGenModel;

		bool				m_bDynamicLightAffect;		// �Ƿ���ܶ�̬����

		bool				m_bStaticLightAffect;		// �Ƿ����ɹ���ͼ

		LightMapDesc		m_LightMap;
	};
}

