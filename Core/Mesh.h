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
	class CORE_API SubMesh
	{
	public:
		friend class Mesh;

	private:
		GraphicsBufferPtr   m_pVB;

		IndexBufferPtr		m_pIB;
	};

	class CORE_API Mesh : public Resource
	{
	public:
		Mesh(void);
		virtual ~Mesh(void);

		virtual bool	Load(String& path, const String& name);

		virtual void	UnLoad();

	protected:
		typedef vector<SubMesh>::type SubMeshList;

		SubMeshList	m_vecSubMesh;

	};
}
