/********************************************************************
	����ʱ��:	6:1:2012   20:03
	�ļ���: 	f:\Aurorar\Core\FrameBuffer.h
	������:		����
	
	�ļ�����:	֡����
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
