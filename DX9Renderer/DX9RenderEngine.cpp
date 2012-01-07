#include "StdAfx.h"
#include "DX9RenderEngine.h"
#include "DX9Mapping.h"

namespace Aurora
{
	DX9RenderEngine::DX9RenderEngine(void) : m_dwBehaviorFlags(0)
	{
		ZeroMemory( &m_Caps, sizeof(m_Caps) );
		ZeroMemory( &m_AdapterIdentifier, sizeof(m_AdapterIdentifier) );
		ZeroMemory( &m_PresentationParams, sizeof(m_PresentationParams) );
		ZeroMemory( &m_DsiplayMode, sizeof(m_DsiplayMode) );
	}

	DX9RenderEngine::~DX9RenderEngine(void)
	{
	}

	bool DX9RenderEngine::InitRenderDeivce( RenderSettings& settings )
	{
		if( NULL == (m_pD3D = Direct3DCreate9(D3D_SDK_VERSION)) )
			return false;


		m_PresentationParams.Windowed                     = !settings.full_screen;
		m_PresentationParams.SwapEffect                   = D3DSWAPEFFECT_DISCARD;
		m_PresentationParams.BackBufferFormat             = DX9Mapping::MappingPF(settings.color_fmt);
		m_PresentationParams.BackBufferWidth              = settings.width;
		m_PresentationParams.BackBufferHeight             = settings.height;
		m_PresentationParams.BackBufferCount              = 1;
		m_PresentationParams.MultiSampleType              = (D3DMULTISAMPLE_TYPE)settings.sample_count;
		m_PresentationParams.MultiSampleQuality           = settings.sample_quality;
		m_PresentationParams.hDeviceWindow                = settings.hWnd;
		m_PresentationParams.EnableAutoDepthStencil       = TRUE;
		m_PresentationParams.AutoDepthStencilFormat       = DX9Mapping::MappingPF(settings.depth_stencil_fmt);
		m_PresentationParams.Flags                        = D3DPRESENTFLAG_DISCARD_DEPTHSTENCIL;
		m_PresentationParams.FullScreen_RefreshRateInHz   = D3DPRESENT_RATE_DEFAULT;
		m_PresentationParams.PresentationInterval         = D3DPRESENT_INTERVAL_IMMEDIATE;


		m_dwAdapterNumber  = D3DADAPTER_DEFAULT;
		m_DeviceType	   = D3DDEVTYPE_HAL;						


		if (IsNvPerfHUDEnable())
		{
			int x = m_pD3D->GetAdapterCount();
			for (UINT adapter=0; adapter < m_pD3D->GetAdapterCount(); ++adapter)
			{
				m_pD3D->GetAdapterIdentifier( adapter, 0, &m_AdapterIdentifier );

				if(strstr(m_AdapterIdentifier.Description, "PerfHUD") != NULL)
				{
					m_dwAdapterNumber	= adapter;
					m_DeviceType		= D3DDEVTYPE_REF;
					break;
				}
			}	
		}

		m_pD3D->GetAdapterDisplayMode( m_dwAdapterNumber, &m_DsiplayMode );

		HRESULT     hr;

		m_dwBehaviorFlags |= D3DCREATE_HARDWARE_VERTEXPROCESSING;

		hr = m_pD3D->CreateDevice(m_dwAdapterNumber, m_DeviceType, m_PresentationParams.hDeviceWindow,
			m_dwBehaviorFlags, &m_PresentationParams, &m_pDevice);

		if (FAILED(hr))
		{
			hr = m_pD3D->CreateDevice(m_dwAdapterNumber, m_DeviceType, m_PresentationParams.hDeviceWindow,
				m_dwBehaviorFlags, &m_PresentationParams, &m_pDevice);
		}

		if( FAILED( hr ) )
		{
			// Try to create the device with mixed vertex processing.
			m_dwBehaviorFlags &= ~D3DCREATE_HARDWARE_VERTEXPROCESSING;
			m_dwBehaviorFlags |= D3DCREATE_MIXED_VERTEXPROCESSING;

			hr = m_pD3D->CreateDevice(m_dwAdapterNumber, m_DeviceType, m_PresentationParams.hDeviceWindow,
				m_dwBehaviorFlags, &m_PresentationParams, &m_pDevice);
		}

		if( FAILED( hr ) )
		{
			// try to create the device with software vertex processing.
			m_dwBehaviorFlags &= ~D3DCREATE_MIXED_VERTEXPROCESSING;
			m_dwBehaviorFlags |= D3DCREATE_SOFTWARE_VERTEXPROCESSING;
			hr = m_pD3D->CreateDevice(m_dwAdapterNumber, m_DeviceType, m_PresentationParams.hDeviceWindow,
				m_dwBehaviorFlags, &m_PresentationParams, &m_pDevice);
		}

		if ( FAILED( hr ) )
		{
			// try reference device
			m_DeviceType = D3DDEVTYPE_REF;
			hr = m_pD3D->CreateDevice(m_dwAdapterNumber, m_DeviceType, m_PresentationParams.hDeviceWindow,
				m_dwBehaviorFlags, &m_PresentationParams, &m_pDevice);

			return false;
		}

		hr = m_pDevice->GetDeviceCaps(&m_Caps);
		hr = m_pDevice->GetCreationParameters(&m_CreationParams);
		hr = m_pDevice->SetRenderState(D3DRS_SPECULARENABLE, TRUE);

		m_Settings = settings;

		return true;

	}

	bool DX9RenderEngine::_BeginFrame()
	{
		if (FAILED(m_pDevice->BeginScene()))
		{
			return false;
		}
		return true;
	}

	bool DX9RenderEngine::_EndFrame()
	{
		if (FAILED(m_pDevice->EndScene()))
		{
			return false;
		}
		return true;
	}

	bool DX9RenderEngine::RenderOneFrame()
	{
		if (!_BeginFrame())
		{
			return false;
		}

		if (!_DoRender())
		{
			return false;
		}

		if (!_EndFrame())
		{
			return false;
		}


		return true;
	}

	bool DX9RenderEngine::_DoRender()
	{
		return true;
	}

}


