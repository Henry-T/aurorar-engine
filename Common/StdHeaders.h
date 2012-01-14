/********************************************************************
	创建时间:	6:1:2012   0:33
	文件名	:	StdHeaders
	创建者:		丁亮
	
	文件作用:	所有STL的头文件写在这里
*********************************************************************/
#pragma once

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstdarg>
#include <cmath>

#include <vector>
#include <map>
#include <string>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <bitset>

#include <hash_set>
#include <hash_map>

#include <algorithm>
#include <functional>
#include <limits>

#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>

extern "C" 
{
#include <sys/types.h>
#include <sys/stat.h>
}

#undef min
#undef max


#include "..\MemoryAllocator\MemoryAllocatorConfig.h"
#include "..\MemoryAllocator\STLAllocator.h"
#include "boost/shared_ptr.hpp"

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


