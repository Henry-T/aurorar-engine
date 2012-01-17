#include "stdafx.h"
#include "Log.h"
#include "LogManager.h"
#include "String.h"
#include <iostream>
#include <algorithm>
#include <time.h>
#include <iomanip>

namespace Aurora
{

    //-----------------------------------------------------------------------
    Log::Log( const String& name, bool debuggerOuput, bool suppressFile ) : 
        mLogLevel(LL_NORMAL), mDebugOut(debuggerOuput),
        mSuppressFile(suppressFile), mTimeStamp(true), mLogName(name)
    {
		if (!mSuppressFile)
		{
			mfpLog.open(name.c_str());
		}
    }
    //-----------------------------------------------------------------------
    Log::~Log()
    {
		if (!mSuppressFile)
		{
	        mfpLog.close();
		}
    }
    //-----------------------------------------------------------------------
    void Log::logMessage( const String& message, LogMessageLevel lml, bool maskDebug )
    {
        if ((mLogLevel + lml) >= LOG_THRESHOLD)
        {
            for( mtLogListener::iterator i = mListeners.begin(); i != mListeners.end(); ++i )
                (*i)->messageLogged( message, lml, maskDebug, mLogName );

			if (mDebugOut && !maskDebug)
                std::cerr << message << std::endl;

            // Write time into log
			if (!mSuppressFile)
			{
				if (mTimeStamp)
			    {
                    struct tm *pTime = NULL;
                    time_t ctTime; time(&ctTime);
                    localtime_s( pTime, &ctTime );
                    mfpLog << std::setw(2) << std::setfill('0') << pTime->tm_hour
                        << ":" << std::setw(2) << std::setfill('0') << pTime->tm_min
                        << ":" << std::setw(2) << std::setfill('0') << pTime->tm_sec
                        << ": ";
                }
                mfpLog << message << std::endl;

				// Flush stcmdream to ensure it is written (incase of a crash, we need log to be up to date)
				mfpLog.flush();
			}
        }
    }
    
    //-----------------------------------------------------------------------
    void Log::setTimeStampEnabled(bool timeStamp)
    {
        mTimeStamp = timeStamp;
    }

    //-----------------------------------------------------------------------
    void Log::setDebugOutputEnabled(bool debugOutput)
    {
        mDebugOut = debugOutput;
    }

	//-----------------------------------------------------------------------
    void Log::setLogDetail(LoggingLevel ll)
    {
        mLogLevel = ll;
    }

    //-----------------------------------------------------------------------
    void Log::addListener(LogListener* listener)
    {
        mListeners.push_back(listener);
    }

    //-----------------------------------------------------------------------
    void Log::removeListener(LogListener* listener)
    {
        mListeners.erase(std::find(mListeners.begin(), mListeners.end(), listener));
    }
	//---------------------------------------------------------------------
	Log::Stream Log::stream(LogMessageLevel lml, bool maskDebug) 
	{
		return Stream(this, lml, maskDebug);

	}
}
