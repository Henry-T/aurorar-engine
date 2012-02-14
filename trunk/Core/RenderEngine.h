/********************************************************************
	创建时间:	4:1:2012   1:20
	文件名	:	RenderEngine
	创建者:		丁亮
	
	文件作用:	渲染功能接口，具体实现在API插件的派生类中
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
 
 
 		// 初始化渲染设备
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

