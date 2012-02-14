#include "stdafx.h"
#include "DX9GraphicsBuffer.h"


namespace Aurora
{
	DX9GraphicsBuffer::~DX9GraphicsBuffer()
	{
		NED_DELETE(m_pVD);
	}

	void DX9GraphicsBuffer::MakeDeclaration()
	{
		m_pVD = NED_NEW VertexDeclaration;

		// Position
		m_pVD->AddElement( 0, 0, VET_FLOAT3, VES_POSITION, 0 );
		// Normal
		m_pVD->AddElement( 0, VertexElement.GetTypeSize(VET_FLOAT3), VET_FLOAT3, VES_NORMAL, 0 );
		// UV
		m_pVD->AddElement( 0, VertexElement.GetTypeSize(VET_FLOAT3) * 2, VET_FLOAT2, VES_TEXTURE_COORDINATES, 0 );
	}

	void DX9GraphicsBuffer::CreateDeviceBuffer()
	{
		// TODO 获取真实设备
		DX9RenderEngine* pDx9RE = NULL;

		pDx9RE->m_pDevice->CreateVertexBuffer( )
		
	}
}

