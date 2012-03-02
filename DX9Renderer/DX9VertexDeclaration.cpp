#include "StdAfx.h"
#include "DX9VertexDeclaration.h"
#include "DX9RenderEngine.h"

namespace Aurora
{
	DX9VertexDeclaration::DX9VertexDeclaration(void)
	{
	}

	DX9VertexDeclaration::~DX9VertexDeclaration(void)
	{
	}

	bool DX9VertexDeclaration::MakeAPIObject()
	{
		// TODO
		DX9RenderEngine* pDX9RE = NULL;

		int eleCnt = mElementList.size();

		D3DVERTEXELEMENT9* pDX9VE = NED_ALLOC_T(D3DVERTEXELEMENT9*, eleCnt, MEMCATEGORY_GENERAL);

		for (int i = 0; i < eleCnt ; i++)
		{
			pDX9VE[i].Stream = mElementList[i].mSource;
			pDX9VE[i].Offset = mElementList[i].mOffset;
			pDX9VE[i].Type = GetDX9Type(mElementList[i].mType);
			pDX9VE[i].Method = D3DDECLMETHOD_DEFAULT;
			pDX9VE[i].Usage = GetDX9Usage(mElementList[i].mSemantic);
			pDX9VE[i].UsageIndex = mElementList[i].mIndex;
		}

		LPDIRECT3DDEVICE9 pDevice = pDX9RE->m_pDevice;
		pDevice->CreateVertexDeclaration( pDX9VE, &m_pDX9Decl );
		return true;
	}


	int DX9VertexDeclaration::GetDX9Type( int baseType)
	{
		switch ( baseType)
		{
		case VET_FLOAT1:
			return D3DDECLTYPE_FLOAT1;
		case VET_FLOAT2:
			return D3DDECLTYPE_FLOAT2;
		case VET_FLOAT3:
			return D3DDECLTYPE_FLOAT3;
		case VET_FLOAT4:
			return D3DDECLTYPE_FLOAT4;
		case VET_COLOUR:
			return D3DDECLTYPE_D3DCOLOR;
		case VET_SHORT1:
			return 0;
		case VET_SHORT2:
			return D3DDECLTYPE_SHORT2;
		case VET_SHORT3:
			return 0;
		case VET_SHORT4:
			return D3DDECLTYPE_SHORT4;
		case VET_UBYTE4:
			return D3DDECLTYPE_UBYTE4;
		default:
			return D3DDECLTYPE_FLOAT1;
		}
	}

	int DX9VertexDeclaration::GetDX9Usage( int baseSemantic)
	{
		switch(baseSemantic)
		{
		case VES_POSITION:
			return D3DDECLUSAGE_POSITION;
		case VES_BLEND_WEIGHTS:
			return D3DDECLUSAGE_BLENDWEIGHT;
		case VES_BLEND_INDICES:
			return D3DDECLUSAGE_BLENDINDICES;
		case VES_NORMAL:
			return D3DDECLUSAGE_NORMAL;
		case VES_DIFFUSE:
			return D3DDECLUSAGE_COLOR;
		case VES_SPECULAR:
			return D3DDECLUSAGE_COLOR;
		case VES_TEXTURE_COORDINATES:
			return D3DDECLUSAGE_TEXCOORD;
		case VES_BINORMAL:
			return D3DDECLUSAGE_BINORMAL;
		case VES_TANGENT:
			return D3DDECLUSAGE_TANGENT;
		default:
			return D3DDECLUSAGE_POSITION;
		}
	}

}