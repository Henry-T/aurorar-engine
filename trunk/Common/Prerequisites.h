/********************************************************************
	创建时间:	6:1:2012   0:31
	文件名	:	Prerequisites
	创建者:		丁亮
	
	文件作用:	一些STL容器相关的类型定义 宽窄字符定义 所有类的前置声明
*********************************************************************/
#pragma once

#include "StdHeaders.h"
#include "..\MemoryAllocator\MemoryAllocatorConfig.h"
#include "..\MemoryAllocator\STLAllocator.h"
#include "Platform.h"
#include "boost/shared_ptr.hpp"

#define USE_NED_MEM_ALLOC 1

#define interface struct

namespace Aurora
{
#if USE_NED_MEM_ALLOC
#	if UNICODE
		typedef std::basic_string<wchar_t, std::char_traits<wchar_t>, STLAllocator<wchar_t,GeneralAllocPolicy > >	_StringBase;
		typedef std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,STLAllocator<wchar_t,GeneralAllocPolicy >> _StringStreamBase;
#	else
		typedef std::basic_string<char, std::char_traits<char>, STLAllocator<char,GeneralAllocPolicy > >	_StringBase;
		typedef std::basic_stringstream<char,std::char_traits<char>,STLAllocator<char,GeneralAllocPolicy > > _StringStreamBase;
#	endif


#	define StdStringT(T) std::basic_string<T, std::char_traits<T>, std::allocator<T> >	
#	define CustomMemoryStringT(T) std::basic_string<T, std::char_traits<T>, STLAllocator<T,GeneralAllocPolicy> >	

	template<typename T>
	bool operator <(const CustomMemoryStringT(T)& l,const StdStringT(T)& o)
	{
		return l.compare(0,l.length(),o.c_str(),o.length())<0;
	}
	template<typename T>
	bool operator <(const StdStringT(T)& l,const CustomMemoryStringT(T)& o)
	{
		return l.compare(0,l.length(),o.c_str(),o.length())<0;
	}
	template<typename T>
	bool operator <=(const CustomMemoryStringT(T)& l,const StdStringT(T)& o)
	{
		return l.compare(0,l.length(),o.c_str(),o.length())<=0;
	}
	template<typename T>
	bool operator <=(const StdStringT(T)& l,const CustomMemoryStringT(T)& o)
	{
		return l.compare(0,l.length(),o.c_str(),o.length())<=0;
	}
	template<typename T>
	bool operator >(const CustomMemoryStringT(T)& l,const StdStringT(T)& o)
	{
		return l.compare(0,l.length(),o.c_str(),o.length())>0;
	}
	template<typename T>
	bool operator >(const StdStringT(T)& l,const CustomMemoryStringT(T)& o)
	{
		return l.compare(0,l.length(),o.c_str(),o.length())>0;
	}
	template<typename T>
	bool operator >=(const CustomMemoryStringT(T)& l,const StdStringT(T)& o)
	{
		return l.compare(0,l.length(),o.c_str(),o.length())>=0;
	}
	template<typename T>
	bool operator >=(const StdStringT(T)& l,const CustomMemoryStringT(T)& o)
	{
		return l.compare(0,l.length(),o.c_str(),o.length())>=0;
	}

	template<typename T>
	bool operator ==(const CustomMemoryStringT(T)& l,const StdStringT(T)& o)
	{
		return l.compare(0,l.length(),o.c_str(),o.length())==0;
	}
	template<typename T>
	bool operator ==(const StdStringT(T)& l,const CustomMemoryStringT(T)& o)
	{
		return l.compare(0,l.length(),o.c_str(),o.length())==0;
	}

	template<typename T>
	bool operator !=(const CustomMemoryStringT(T)& l,const StdStringT(T)& o)
	{
		return l.compare(0,l.length(),o.c_str(),o.length())!=0;
	}
	template<typename T>
	bool operator !=(const StdStringT(T)& l,const CustomMemoryStringT(T)& o)
	{
		return l.compare(0,l.length(),o.c_str(),o.length())!=0;
	}

	template<typename T>
	CustomMemoryStringT(T) operator +=(const CustomMemoryStringT(T)& l,const StdStringT(T)& o)
	{
		return CustomMemoryStringT(T)(l)+=o.c_str();
	}
	template<typename T>
	CustomMemoryStringT(T) operator +=(const StdStringT(T)& l,const CustomMemoryStringT(T)& o)
	{
		return CustomMemoryStringT(T)(l.c_str())+=o.c_str();
	}

	template<typename T>
	CustomMemoryStringT(T) operator +(const CustomMemoryStringT(T)& l,const StdStringT(T)& o)
	{
		return CustomMemoryStringT(T)(l)+=o.c_str();
	}

	template<typename T>
	CustomMemoryStringT(T) operator +(const StdStringT(T)& l,const CustomMemoryStringT(T)& o)
	{
		return CustomMemoryStringT(T)(l.c_str())+=o.c_str();
	}

	template<typename T>
	CustomMemoryStringT(T) operator +(const T* l,const CustomMemoryStringT(T)& o)
	{
		return CustomMemoryStringT(T)(l)+=o;
	}

#	undef StdStringT
#	undef CustomMemoryStringT

#else
#	if UNICODE
		typedef std::wstring _StringBase;
		typedef std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > _StringStreamBase;
#	else
		typedef std::string _StringBase;
		typedef std::basic_stringstream<char,std::char_traits<char>,std::allocator<char> > _StringStreamBase;
#	endif
#endif

	typedef _StringBase String;
	typedef _StringStreamBase StringStream;
	typedef StringStream stringstream;
}


namespace Aurora
{
	template <typename T, typename A = STLAllocator<T, GeneralAllocPolicy> > 
	struct deque 
	{ 
#if USE_NED_MEM_ALLOC
		typedef typename std::deque<T, A> type;    
#else
		typedef typename std::deque<T> type;    
#endif
	}; 

	template <typename T, typename A = STLAllocator<T, GeneralAllocPolicy> > 
	struct vector 
	{ 
#if USE_NED_MEM_ALLOC
		typedef typename std::vector<T, A> type;    
#else
		typedef typename std::vector<T> type;    
#endif
	}; 

	template <typename T, typename A = STLAllocator<T, GeneralAllocPolicy> > 
	struct list 
	{ 
#if USE_NED_MEM_ALLOC
		typedef typename std::list<T, A> type;    
#else
		typedef typename std::list<T> type;    
#endif
	}; 

	template <typename T, typename P = std::less<T>, typename A = STLAllocator<T, GeneralAllocPolicy> > 
	struct set 
	{ 
#if USE_NED_MEM_ALLOC
		typedef typename std::set<T, P, A> type;    
#else
		typedef typename std::set<T, P> type;    
#endif
	}; 

	template <typename K, typename V, typename P = std::less<K>, typename A = STLAllocator<std::pair<const K, V>, GeneralAllocPolicy> > 
	struct map 
	{ 
#if USE_NED_MEM_ALLOC
		typedef typename std::map<K, V, P, A> type; 
#else
		typedef typename std::map<K, V, P> type; 
#endif
	}; 

	template <typename K, typename V, typename P = std::less<K>, typename A = STLAllocator<std::pair<const K, V>, GeneralAllocPolicy> > 
	struct multimap 
	{ 
#if USE_NED_MEM_ALLOC
		typedef typename std::multimap<K, V, P, A> type; 
#else
		typedef typename std::multimap<K, V, P> type; 
#endif
	}; 

}

namespace Aurora
{
	class Log;
	class LogManager;
	class Exception;
	class ExceptionFactory;
	class StringUtil;
	class Bitwise;
	class Timer;
}

namespace Aurora
{
	typedef boost::shared_ptr<Log>				LogPtr;
	typedef boost::shared_ptr<LogManager>		LogManagerPtr;
	typedef boost::shared_ptr<Exception>		ExceptionPtr;
	typedef boost::shared_ptr<ExceptionFactory> ExceptionFactoryPtr;
	typedef boost::shared_ptr<StringUtil>		StringUtilPtr;
	typedef boost::shared_ptr<Bitwise>			BitwisePtr;
	typedef boost::shared_ptr<Timer>			TimerPtr;
}

