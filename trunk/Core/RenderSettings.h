/********************************************************************
	创建时间:	6:1:2012   14:52
	文件名: 	f:\Aurorar\Core\RenderSettings.h
	创建者:		丁亮
	
	文件作用:	引擎的初始化设置参数
*********************************************************************/
#pragma once
#include "PixelFormat.h"

namespace Aurora
{
	struct RenderSettings
	{
		bool			full_screen;
		unsigned int	left, top, width, height;
		unsigned int	sample_count;
		unsigned int	sample_quality;
		unsigned int	sync_interval;

		PixelFormat		color_fmt;
		PixelFormat		depth_stencil_fmt;

		void			SetToDefault()
		{
			full_screen			= false;
			left = top			= 0;
			width				= 800;
			height				= 600;
			sample_count		= 1;
			sample_quality		= 0;
			sync_interval		= 0;
			color_fmt			= PF_A8R8G8B8;
			depth_stencil_fmt	= PF_D24S8;
		}
	};
}