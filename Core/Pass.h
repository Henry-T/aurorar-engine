/********************************************************************
	创建时间:	17:2:2012   8:20
	文件名	:	Pass
	创建者:		丁亮
	
	文件作用:	渲染一次
*********************************************************************/
#pragma once

#include "Prerequisites.h"
#include "RenderState.h"

namespace Aurora
{
	class CORE_API Pass : public ResourceAllocatedObject
	{
	public:
		enum ShaderMode
		{
			SM_VS_1_0 = 1 << 0,
			SM_VS_2_0 = 1 << 1,
			SM_VS_3_0 = 1 << 2,
			SM_VS_4_0 = 1 << 3,

			SM_PS_1_0 = 1 << 4,
			SM_PS_2_0 = 1 << 5,
			SM_PS_3_0 = 1 << 6,
			SM_PS_4_0 = 1 << 7,

			SM_NOT_SUPPORT
		};
		Pass(void);
		~Pass(void);

		bool		UpdateGPURenderState();

	private:
		ShaderMode	m_eSM;

		RenderState	m_RS;
	};
}
