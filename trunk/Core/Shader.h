/********************************************************************
	创建时间:	15:2:2012   8:28
	文件名	:	Shader
	创建者:		丁亮
	
	文件作用:	可编程着色器
				
				在欧若拉中 不再采取Ogre那种对材质与Shader概念模糊的
				处理方式 而是严格区分两者的含义。

				欧若拉的材质不再与渲染状态有任何关联 而只负责记录用
				于描述物件表面的参数 是属于物件的一个成员属性
				Shader的含义将完全吻合于真正的渲染API中的Shader 是一
				个全局概念

				渲染时以Shader为单位 用到同一个Shader的物件分同到一个
				组里一起画 保证渲染状态切换的次数最少
				同组之内 根据材质中的纹理排序 保证向GPU传送纹理数据的
				次数最少

				欧若拉的定位为最符合国内网游市场的次世代渲染引擎 因此
				将不考虑不支持Shader的显卡 同时为了更加符合DX10之后的
				渲染器设计 欧若拉将完全抛弃固定功能流水线 所有的渲染操
				作都将由Shader完成
*********************************************************************/
#pragma once
#include "Prerequisites.h"

namespace Aurora
{
	class CORE_API Shader : public Resource
	{
	public:
		Shader(void);
		virtual ~Shader(void);

		virtual bool	Load(String& path, const String& name);

		virtual void	UnLoad();

		void			EnableTechnique(const String& name, bool enable);

		void			EnableTechnique(uint8 index, bool enable);

		virtual void	BeginFrame();

		virtual void	EndFrame();

		typedef vector<TechniquePtr>::type TechniqueList;

	protected:
		TechniqueList	m_vecTechnique;
	};
}

