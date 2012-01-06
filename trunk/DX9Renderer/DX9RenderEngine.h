/********************************************************************
	����ʱ��:	4:1:2012   1:21
	�ļ���	:	DX9RenderEngine
	������:		����
	
	�ļ�����:	��Ⱦ���ܾ���ʵ�� DX9�汾
*********************************************************************/
#pragma once
#include "..\Core\RenderEngine.h"

namespace Aurora
{
	class DX9RENDERER_API DX9RenderEngine : public RenderEngine
	{
	public:
		DX9RenderEngine(void);
		~DX9RenderEngine(void);

		virtual bool			InitRenderDeivce(RenderSettings& settings);

		const D3DCAPS9&			GetRenderDeviceCaps() const { return m_Caps; }

		bool					BeginFrame();

		bool					EndFrame();

		bool					RenderOneFrame();

		

	private:

		bool					_DoRender();



		LPDIRECT3D9				m_pD3D;
		LPDIRECT3DDEVICE9		m_pDevice;
		DWORD					m_dwBehaviorFlags;
		D3DCAPS9				m_Caps;
		D3DADAPTER_IDENTIFIER9	m_AdapterIdentifier;

		D3DPRESENT_PARAMETERS   m_PresentationParams;
		D3DDISPLAYMODE			m_DsiplayMode;
		UINT					m_dwAdapterNumber;
		D3DDEVTYPE				m_DeviceType;

		D3DDEVICE_CREATION_PARAMETERS	m_CreationParams;

	};

}
