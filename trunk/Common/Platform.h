/********************************************************************
	创建时间:	4:1:2012   22:38
	文件名	:	Platform
	创建者:		丁亮
	
	文件作用:	CPU架构相关的定义 不要太繁琐 尽量简洁
*********************************************************************/
#pragma once

#define ARCHITECTURE_32 1
#define ARCHITECTURE_64 2

#if defined(__x86_64__) || defined(_M_X64) || defined(__powerpc64__) || defined(__alpha__) || defined(__ia64__) || defined(__s390__) || defined(__s390x__)
#   define ARCH_TYPE ARCHITECTURE_64
#else
#   define ARCH_TYPE ARCHITECTURE_32
#endif

#if ARCH_TYPE == ARCHITECTURE_32
	typedef float Real;
#elif ARCH_TYPE == ARCHITECTURE_64
	typedef double Real;
#endif

typedef unsigned int		uint32;
typedef unsigned short		uint16;
typedef unsigned char		uint8;
typedef int					int32;
typedef short				int16;
typedef char				int8;
typedef unsigned __int64	uint64;
typedef __int64				int64;

typedef unsigned char		uchar;
typedef unsigned short		ushort;
typedef unsigned int		uint;
typedef unsigned long		ulong;

#define ENDIAN_LITTLE 1
#define ENDIAN_BIG 2

#ifdef CONFIG_BIG_ENDIAN
#    define ENDIAN ENDIAN_BIG
#else
#    define ENDIAN ENDIAN_LITTLE
#endif


#define USE_NED_MEM_ALLOC 1
