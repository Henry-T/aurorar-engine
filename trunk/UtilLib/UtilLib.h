/********************************************************************
����ʱ��:	6:1:2012   0:31
�ļ���	:	UtilLib
������:		����

�ļ�����:	һЩSTL������ص����Ͷ��� ��խ�ַ����� �������ǰ������
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
