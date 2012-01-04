/********************************************************************
	创建时间:	4:1:2012   11:23
	文件名: 	f:\Aurorar\Core\LogManager.h
	创建者:		丁亮
	
	文件作用:	统一管理日志
*********************************************************************/
#pragma once

#include "Prerequisites.h"
#include "Log.h"
#include "Singleton.h"
#include "String.h"

namespace Aurora
{
    class LogManager : public Singleton<LogManager>, public DefaultAlloc
    {
	protected:
		typedef map<String, Log*>::type	LogList;

        LogList mLogs;

        Log* mDefaultLog;

    public:

        LogManager();
        ~LogManager();

        Log* createLog( const String& name, bool defaultLog = false, bool debuggerOutput = true, bool suppressFileOutput = false);

        Log* getLog( const String& name);

        Log* getDefaultLog();

		void destroyLog(const String& name);

		void destroyLog(Log* log);

        Log* setDefaultLog(Log* newLog);

        void logMessage( const String& message, LogMessageLevel lml = LML_NORMAL, bool maskDebug = false);

        void logMessage( LogMessageLevel lml, const String& message,  bool maskDebug = false) { logMessage(message, lml, maskDebug); }

		Log::Stream stream(LogMessageLevel lml = LML_NORMAL, bool maskDebug = false);

        void setLogDetail(LoggingLevel ll);

        static LogManager& getSingleton(void);

        static LogManager* getSingletonPtr(void);

    };

}