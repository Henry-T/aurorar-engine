/********************************************************************
	����ʱ��:	9:2:2012   0:32
	�ļ���	:	Mesh
	������:		����
	
	�ļ�����:	����
*********************************************************************/
#pragma once

#include "Prerequisites.h"
#include "Resource.h"

namespace Aurora
{
	// ȥ����SubMesh�ĸ��� ����MeshΪ��С������λ
	// ���SubMeshʵ�ֵ�Ч������ɫ��װ����Ϊһ��ר��
	// ��ģ��������������Model
	class CORE_API Mesh : public Resource
	{
	public:
		Mesh(void);
		virtual ~Mesh(void);

		virtual bool		Load(String& path, const String& name);

		virtual void		UnLoad();

	protected:
		GraphicsBufferPtr   m_pVB;

		IndexBufferPtr		m_pIB;

	};
}
