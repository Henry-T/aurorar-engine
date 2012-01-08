/********************************************************************
	创建时间:	8:1:2012   20:25
	文件名: 	f:\Aurorar\Core\MultiStream.h
	创建者:		丁亮
	
	文件作用:	用于多流的一些声明
*********************************************************************/
#pragma once

namespace Aurora
{
	// 对应于SetStreamSource的ID
	enum CORE_API StreamChannel
	{
		SC_GEOMETRY,
		SC_TEXTURECOORD,
		SC_BONEWEIGHT,
		SC_INSTANCING,
		SC_MAX
	};
}