/********************************************************************
	创建时间:	6:1:2012   0:33
	文件名	:	Timer
	创建者:		丁亮
	
	文件作用:	定时器
*********************************************************************/
#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#	define WIN32_LEAN_AND_MEAN
#endif
#if !defined(NOMINMAX) && defined(_MSC_VER)
#	define NOMINMAX // required to stop windows.h messing up std::min
#endif
#include <windows.h>
#include <time.h>
#include "UtilLib.h"
#include "StdHeaders.h"

namespace Aurora
{

	class /*UTILLIB_API*/ Timer/* : public GeneralAllocatedObject*/
    {
    private:
		clock_t mZeroClock;

        DWORD mStartTick;
		LONGLONG mLastTime;
        LARGE_INTEGER mStartTime;
        LARGE_INTEGER mFrequency;

		DWORD_PTR mTimerMask;
    public:

		Timer();

		~Timer();

        bool setOption( const String& strKey, const void* pValue );

		void reset();

		unsigned long getMilliseconds();

		unsigned long getMicroseconds();

		unsigned long getMillisecondsCPU();

		unsigned long getMicrosecondsCPU();
    };

}
