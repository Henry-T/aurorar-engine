/********************************************************************
	创建时间:	6:1:2012   15:38
	文件名: 	f:\Aurorar\Core\PixelFormat.h
	创建者:		丁亮
	
	文件作用:	像素格式
*********************************************************************/
#pragma once

namespace Aurora
{

	enum PixelFormat
	{
		/// Unknown pixel format.
		PF_UNKNOWN = 0,
		/// 8-bit pixel format, all bits luminance.
		PF_L8,
		/// 16-bit pixel format, all bits luminance.
		PF_L16,
		/// 8-bit pixel format, all bits alpha.
		PF_A8,
		/// 8-bit pixel format, 4 bits alpha, 4 bits luminance.
		PF_A4L4,
		/// 2 byte pixel format, 1 byte luminance, 1 byte alpha
		PF_BYTE_LA,
		/// 16-bit pixel format, 5 bits red, 6 bits green, 5 bits blue.
		PF_R5G6B5,
		/// 8-bit pixel format, 2 bits blue, 3 bits green, 3 bits red.
		PF_R3G3B2,
		/// 16-bit pixel format, 4 bits for alpha, red, green and blue.
		PF_A4R4G4B4,
		/// 16-bit pixel format, 5 bits for blue, green, red and 1 for alpha.
		PF_A1R5G5B5,
		/// 24-bit pixel format, 8 bits for red, green and blue.
		PF_R8G8B8,
		/// 32-bit pixel format, 8 bits for alpha, red, green and blue.
		PF_A8R8G8B8,
		/// 32-bit pixel format, 8 bits for blue, green, red and alpha.
		PF_A8B8G8R8,
		/// 32-bit pixel format, 8 bits for red, 8 bits for green, 8 bits for blue
		/// like PF_A8R8G8B8, but alpha will get discarded
		PF_X8R8G8B8,
		/// 32-bit pixel format, 8 bits for blue, 8 bits for green, 8 bits for red
		/// like PF_A8B8G8R8, but alpha will get discarded
		PF_X8B8G8R8,
		/// 32-bit pixel format, 2 bits for alpha, 10 bits for red, green and blue.
		PF_A2R10G10B10,
		/// 32-bit pixel format, 10 bits for blue, green and red, 2 bits for alpha.
		PF_A2B10G10R10,
		/// DDS (DirectDraw Surface) DXT1 format
		PF_DXT1,
		/// DDS (DirectDraw Surface) DXT2 format
		PF_DXT2,
		/// DDS (DirectDraw Surface) DXT3 format
		PF_DXT3,
		/// DDS (DirectDraw Surface) DXT4 format
		PF_DXT4,
		/// DDS (DirectDraw Surface) DXT5 format
		PF_DXT5,
		// 16-bit pixel format, 16 bits (float) for red
		PF_FLOAT16_R,
		// 64-bit pixel format, 16 bits (float) for red, 16 bits (float) for green, 16 bits (float) for blue, 16 bits (float) for alpha
		PF_FLOAT16_RGBA,
		// 32-bit pixel format, 32 bits (float) for red
		PF_FLOAT32_R,
		// 128-bit pixel format, 32 bits (float) for red, 32 bits (float) for green, 32 bits (float) for blue, 32 bits (float) for alpha
		PF_FLOAT32_RGBA,
		// 32-bit, 2-channel s10e5 floating point pixel format, 16-bit green, 16-bit red
		PF_FLOAT16_GR,
		// 64-bit, 2-channel floating point pixel format, 32-bit green, 32-bit red
		PF_FLOAT32_GR,
		// 64-bit pixel format, 16 bits for red, green, blue and alpha
		PF_SHORT_RGBA,
		// 32-bit pixel format, 16-bit green, 16-bit red
		PF_SHORT_GR,
		// 48-bit pixel format, 16 bits for red, green and blue

		// 增加深度/模板格式
		PF_D16_LOCKABLE,
		PF_D32,
		PF_D15S1,
		PF_D24X8,
		PF_D24X4S4,
		PF_D16,
		PF_D24S8,
		PF_D32F_LOCKABLE,
		PF_D24FS8,

		PF_COUNT,

		PF_BYTE_L = PF_L8,
		PF_SHORT_L = PF_L16,
		PF_BYTE_A = PF_A8,
	};

	/**
	* Flags defining some on/off properties of pixel formats
	*/
	enum PixelFormatFlags 
	{
		// This format has an alpha channel
		PFF_HASALPHA        = 0x00000001,      
		// This format is compressed. This invalidates the values in elemBytes,
		// elemBits and the bit counts as these might not be fixed in a compressed format.
		PFF_COMPRESSED    = 0x00000002,
		// This is a floating point format
		PFF_FLOAT           = 0x00000004,         
		// This is a depth format (for depth textures)
		PFF_DEPTH           = 0x00000008,
		// Format is in native endian. Generally true for the 16, 24 and 32 bits
		// formats which can be represented as machine integers.
		PFF_NATIVEENDIAN    = 0x00000010,
		// This is an intensity format instead of a RGB one. The luminance
		// replaces R,G and B. (but not A)
		PFF_LUMINANCE       = 0x00000020
	};

	/** Pixel component format */
	enum PixelComponentType
	{
		PCT_BYTE = 0,    /// Byte per component (8 bit fixed 0.0..1.0)
		PCT_SHORT = 1,   /// Short per component (16 bit fixed 0.0..1.0))
		PCT_FLOAT16 = 2, /// 16 bit float per component
		PCT_FLOAT32 = 3, /// 32 bit float per component
		PCT_COUNT = 4    /// Number of pixel types
	};

}