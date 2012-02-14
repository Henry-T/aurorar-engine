/********************************************************************
	����ʱ��:	4:1:2012   1:20
	�ļ���	:	RenderEngine
	������:		����
	
	�ļ�����:	��Ⱦ���ܽӿڣ�����ʵ����API�������������
*********************************************************************/
#pragma once
#include "Prerequisites.h"
#include "RenderSettings.h"
#include "..\Common\Singleton.h"

namespace Aurora
{
 	class CORE_API RenderEngine : public Singleton<RenderEngine>, public RenderSysAllocatedObject
 	{
 	public:
 		RenderEngine(void);
 		virtual ~RenderEngine(void);

		static RenderEngine& getSingleton(void);

		static RenderEngine* getSingletonPtr(void);
 
 
 		// ��ʼ����Ⱦ�豸
 		virtual bool	InitRenderDeivce(RenderSettings& settings) = 0;
 		
 		virtual bool	RenderOneFrame() = 0;
 
 		bool			IsNvPerfHUDEnable() const { return m_bNvPerfHUDEnabled; }
 
 		void			SetNvPerfHUDEnable(bool enable) { m_bNvPerfHUDEnabled = enable; }
 
 	protected:
 
 		virtual bool	_BeginFrame() = 0;
 
 		virtual bool	_EndFrame() = 0;
 
 		bool			m_bNvPerfHUDEnabled;
 
 		RenderSettings	m_Settings;
 	};
}

