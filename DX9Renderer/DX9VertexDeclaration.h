/********************************************************************
	创建时间:	12:1:2012   23:55
	文件名	:	DX9VertexDeclaration
	创建者:		丁亮
	
	文件作用:	DX9顶点声明
*********************************************************************/
#pragma once
#include "..\Core\VertexDeclaration.h"

namespace Aurora
{
	class DX9RENDERER_API DX9VertexDeclaration : public VertexDeclaration
	{
	public:
		DX9VertexDeclaration(void);
		~DX9VertexDeclaration(void);

		virtual bool					MakeAPIObject();

	private:
		LPDIRECT3DVERTEXDECLARATION9	m_pDX9Decl;

		static int GetDX9Type( int baseType);

	    static int GetDX9Usage( int baseSemantic);

		Vector3 position;
		Vector3 normal;
	};
}
