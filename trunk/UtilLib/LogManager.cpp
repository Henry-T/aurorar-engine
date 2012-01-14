#include "stdafx.h"
#include "LogManager.h"
#include "Exception.h"
#include <algorithm>

namespace Aurora 
{

    //-----------------------------------------------------------------------
    template<> LogManager* Singleton<LogManager>::ms_Singleton = 0;
    LogManager* LogManager::getSingletonPtr(void)
    {
        return ms_Singleton;
    }
    LogManager& LogManager::getSingleton(void)
    {  
        assert( ms_Singleton );  return ( *ms_Singleton );  
    }
    //-----------------------------------------------------------------------
    LogManager::LogManager()
    {
        mDefaultLog = NULL;
    }
    //-----------------------------------------------------------------------
    LogManager::~LogManager()
    {
        LogList::iterator i;
        for (i = mLogs.begin(); i != mLogs.end(); ++i)
        {
            NED_DELETE i->second;
        }
    }
    //-----------------------------------------------------------------------
    Log* LogManager::createLog( const String& name, bool defaultLog, bool debuggerOutput, 
		bool suppressFileOutput)
    {
        Log* newLog = NED_NEW Log(name, debuggerOutput, suppressFileOutput);

        if( !mDefaultLog || defaultLog )
        {
            mDefaultLog = newLog;
        }

        mLogs.insert( LogList::value_type( name, newLog ) );

        return newLog;
    }
    //-----------------------------------------------------------------------
    Log* LogManager::getDefaultLog()
    {
        return mDefaultLog;
    }
    //-----------------------------------------------------------------------
    Log* LogManager::setDefaultLog(Log* newLog)
    {
        Log* oldLog = mDefaultLog;
        mDefaultLog = newLog;
        return oldLog;
    }
    //-----------------------------------------------------------------------
    Log* LogManager::getLog( const String& name)
    {
        LogList::iterator i = mLogs.find(name);
        if (i != mLogs.end())
            return i->second;
        else
		{
            AURORA_EXCEPT(Exception::ERR_INVALIDPARAMS, "Log not found. ", "LogManager::getLog");
		}


    }
	//-----------------------------------------------------------------------
	void LogManager::destroyLog(const String& name)
	{
		LogList::iterator i = mLogs.find(name);
		if (i != mLogs.end())
		{
			if (mDefaultLog == i->second)
			{
				mDefaultLog = 0;
			}
			NED_DELETE i->second;
			mLogs.erase(i);
		}

		// Set another default log if this one removed
		if (!mDefaultLog && !mLogs.empty())
		{
			mDefaultLog = mLogs.begin()->second;
		}
	}
	//-----------------------------------------------------------------------
	void LogManager::destroyLog(Log* log)
	{
		destroyLog(log->getName());
	}
    //-----------------------------------------------------------------------
    void LogManager::logMessage( const String& message, LogMessageLevel lml, bool maskDebug)
    {
		if (mDefaultLog)
		{
			mDefaultLog->logMessage(message, lml, maskDebug);
		}
    }
    //-----------------------------------------------------------------------
    void LogManager::setLogDetail(LoggingLevel ll)
    {
		if (mDefaultLog)
		{
	        mDefaultLog->setLogDetail(ll);
		}
    }
	//---------------------------------------------------------------------
	Log::Stream LogManager::stream(LogMessageLevel lml, bool maskDebug)
	{
		if (mDefaultLog)
			return mDefaultLog->stream(lml, maskDebug);
		else
		{
			AURORA_EXCEPT(Exception::ERR_INVALIDPARAMS, "Default log not found. ", "LogManager::stream");
		}

	}
}
