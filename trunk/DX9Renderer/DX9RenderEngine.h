/********************************************************************
	创建时间:	4:1:2012   1:21
	文件名	:	DX9RenderEngine
	创建者:		丁亮
	
	文件作用:	渲染功能具体实现 DX9版本
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
