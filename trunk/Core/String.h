/********************************************************************
	创建时间:	4:1:2012   2:02
	文件名	:	String
	创建者:		丁亮
	
	文件作用:	字符串相关的实用工具
*********************************************************************/
#pragma once
#include "Prerequisites.h"
#include <xhash>

namespace Aurora 
{
	typedef vector<String>::type StringVector;

    class StringUtil
    {
	public:
		typedef StringStream StrStreamType;

        static void trim( String& str, bool left = true, bool right = true );

		static vector< String >::type split( const String& str, const String& delims = "\t\n ", unsigned int maxSplits = 0);

		static vector< String >::type tokenise( const String& str, const String& delims = "\t\n ", const String& doubleDelims = "\"", unsigned int maxSplits = 0);

        static void toLowerCase( String& str );

        static void toUpperCase( String& str );
      
        static bool startsWith(const String& str, const String& pattern, bool lowerCase = true);

        static bool endsWith(const String& str, const String& pattern, bool lowerCase = true);

        static String standardisePath( const String &init);

        static void splitFilename(const String& qualifiedName, String& outBasename, String& outPath);

		static void splitFullFilename(const Aurora::String& qualifiedName, Aurora::String& outBasename, Aurora::String& outExtention, Aurora::String& outPath);

		static void splitBaseFilename(const Aurora::String& fullName, Aurora::String& outBasename, Aurora::String& outExtention);

        static bool match(const String& str, const String& pattern, bool caseSensitive = true);

		static const String replaceAll(const String& source, const String& replaceWhat, const String& replaceWithWhat);

        static const String BLANK;
    };

	typedef stdext::hash_compare< _StringBase, std::less< _StringBase > > _StringHash;


} 
