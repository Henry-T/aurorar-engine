#include "stdafx.h"
#include "DX9Model.h"
#include "DX9RenderEngine.h"
#include "DX9GraphicsBuffer.h"
#include "Mesh.h"


namespace Aurora
{
	bool DX9Model::Render()
	{
		// TODO »ñµÃRenderEngine
		DX9RenderEngine* pDx9RE = NULL;


		DX9GraphicsBuffer* pGemBuf = (DX9GraphicsBuffer*)m_pMesh->m_pVB->m_pGeoBuf;

		
		LPDIRECT3DDEVICE9 pDevice = pDx9RE->GetDevice();
		// pDevice->CreateVertexBuffer( 

		

		return true;
	}
}