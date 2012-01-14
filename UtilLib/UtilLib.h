/********************************************************************
创建时间:	6:1:2012   0:31
文件名	:	UtilLib
创建者:		丁亮

文件作用:	一些STL容器相关的类型定义 宽窄字符定义 所有类的前置声明
*********************************************************************/
#pragma once
#ifdef UTILLIB_EXPORTS
#define UTILLIB_API  __declspec(dllexport)
#else
#define UTILLIB_API  __declspec(dllimport)
#endif

namespace Aurora
{
	class Exception;
	class ExceptionFactory;
	class StringUtil;
	class Bitwise;
	class Timer;
}
