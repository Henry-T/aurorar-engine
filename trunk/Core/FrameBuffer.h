/********************************************************************
	创建时间:	6:1:2012   20:03
	文件名: 	f:\Aurorar\Core\FrameBuffer.h
	创建者:		丁亮
	
	文件作用:	帧缓存
*********************************************************************/
#pragma once

class FrameBuffer
{
public:
	enum FrameBufferType 
	{
		FBT_COLOUR  = 0x1,
		FBT_DEPTH   = 0x2,
		FBT_STENCIL = 0x4
	};


	FrameBuffer(void);
	~FrameBuffer(void);
};
