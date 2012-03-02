#include "stdafx.h"
#include "DX9GraphicsBuffer.h"
#include "DX9VertexDeclaration.h"


namespace Aurora
{
	DX9GraphicsBuffer::~DX9GraphicsBuffer()
	{
		delete m_pVD;
	}

	void DX9GraphicsBuffer::MakeDeclaration()
	{
		m_pVD = NED_NEW DX9VertexDeclaration;

		m_nGeoVertexSize = 0;

		// Position
		m_pVD->AddElement( 0, 0, VET_FLOAT3, VES_POSITION, 0 );
		m_nGeoVertexSize += VertexElement.GetTypeSize(VET_FLOAT3);
		// Normal
		if(m_pGeoBuf->HasNormal())
		{
			m_pVD->AddElement( 0,m_nGeoVertexSize, VET_FLOAT3, VES_NORMAL, 0 );
			m_nGeoVertexSize += VertexElement.GetTypeSize(VET_FLOAT3);
		}
		// Diffuse
		if(m_pGeoBuf->IsDiffuseColorUsed())
		{
			m_pVD->AddElement( 0, m_nGeoVertexSize, VET_FLOAT2, VES_DIFFUSE, 0 );
			m_nGeoVertexSize += VertexElement.GetTypeSize(VET_FLOAT4);
		}
		// Specular
		if(m_pGeoBuf->IsSpecularColorUsed())
		{
			m_pVD->AddElement( 0, m_nGeoVertexSize, VET_FLOAT2, VES_SPECULAR, 0 );
		}



		m_pVD->MakeAPIObject();

		DX9VertexDeclaration* pDX9VD = (DX9VertexDeclaration*)m_pVD;
		pDX9VD->MakeAPIObject();
	}

	void DX9GraphicsBuffer::CreateDeviceBuffer()
	{
		// TODO 获取真实设备
		DX9RenderEngine* pDx9RE = NULL;




		pDx9RE->m_pDevice->CreateVertexBuffer(
			sizeof(Vector3) + sizeof(Vector3) + sizeof(Vector2),
			0,
			0,
			D3DPOOL_DEFAULT,
			&m_pDX9VB,
			NULL);

		void* buf;
		m_pDX9VB->Lock( 0, m_pGeoBuf->PositionList.size()*m_nGeoVertexSize, &buf, D3DLOCK_DISCARD);

		int offsetInVert = 0;

		// 写入Position
		for (int i = 0; i < m_pGeoBuf->GetCount() ; i++)
		{
			(float*)buf[ m_nGeoVertexSize * i + 0] = m_pGeoBuf->PositionList[i].x;
			(float*)buf[ m_nGeoVertexSize * i + 1] = m_pGeoBuf->PositionList[i].y;
			(float*)buf[ m_nGeoVertexSize * i + 2] = m_pGeoBuf->PositionList[i].z;
		}
		offsetInVert += 3;

		// 写入Normal
		if(m_pGeoBuf->HasNormal())
		{
			for (int i = 0; i < m_pGeoBuf->GetCount() ; i++)
			{
				(float*)buf[ m_nGeoVertexSize * i + offsetInVert + 0] = m_pGeoBuf->NormalList[i].x;
				(float*)buf[ m_nGeoVertexSize * i + offsetInVert + 1] = m_pGeoBuf->NormalList[i].y;
				(float*)buf[ m_nGeoVertexSize * i + offsetInVert + 2] = m_pGeoBuf->NormalList[i].z;
			}
			offsetInVert += 3;
		}

		// 写入Diffuse
		if(m_pGeoBuf->IsDiffuseColorUsed())
		{
			for (int i = 0; i < m_pGeoBuf->GetCount() ; i++)
			{
				(float*)buf[ m_nGeoVertexSize * i + offsetInVert + 0] = m_pGeoBuf->DiffuseColorList[i].a;
				(float*)buf[ m_nGeoVertexSize * i + offsetInVert + 1] = m_pGeoBuf->DiffuseColorList[i].r;
				(float*)buf[ m_nGeoVertexSize * i + offsetInVert + 2] = m_pGeoBuf->DiffuseColorList[i].g;
				(float*)buf[ m_nGeoVertexSize * i + offsetInVert + 3] = m_pGeoBuf->DiffuseColorList[i].b;
			}
			offsetInVert += 4;
		}

		// 写入Specular
		if(m_pGeoBuf->IsSpecularColorUsed())
		{
			for (int i = 0; i < m_pGeoBuf->GetCount() ; i++)
			{
				(float*)buf[ m_nGeoVertexSize * i + offsetInVert + 0] = m_pGeoBuf->SpecularColorList[i].a;
				(float*)buf[ m_nGeoVertexSize * i + offsetInVert + 1] = m_pGeoBuf->SpecularColorList[i].r;
				(float*)buf[ m_nGeoVertexSize * i + offsetInVert + 2] = m_pGeoBuf->SpecularColorList[i].g;
				(float*)buf[ m_nGeoVertexSize * i + offsetInVert + 3] = m_pGeoBuf->SpecularColorList[i].b;
			}
			offsetInVert += 4;
		}

		// 
	}
}

