/********************************************************************
	创建时间:	4:1:2012   0:56
	文件名	:	AllocatedObject
	创建者:		丁亮
	
	文件作用:	用于派生不同的内存分配方案 目前只使用默认方案
				定义于MemoryAllocatorConfig.h文件中
*********************************************************************/
#pragma once

namespace Aurora
{
	template <class Alloc>
	class AllocatedObject
	{
	public:
		explicit AllocatedObject()
		{ }

		~AllocatedObject()
		{ }

		void* operator new(size_t sz, const char* file, int line, const char* func)
		{
			return Alloc::allocateBytes(sz, file, line, func);
		}

		void* operator new(size_t sz)
		{
			return Alloc::allocateBytes(sz);
		}

		void* operator new(size_t sz, void* ptr)
		{
			(void) sz;
			return ptr;
		}

		void* operator new[] ( size_t sz, const char* file, int line, const char* func )
		{
			return Alloc::allocateBytes(sz, file, line, func);
		}

		void* operator new[] ( size_t sz )
		{
			return Alloc::allocateBytes(sz);
		}

		void operator delete( void* ptr )
		{
			Alloc::deallocateBytes(ptr);
		}

		void operator delete( void* ptr, void* )
		{
			Alloc::deallocateBytes(ptr);
		}

		void operator delete( void* ptr, const char* , int , const char*  )
		{
			Alloc::deallocateBytes(ptr);
		}

		void operator delete[] ( void* ptr )
		{
			Alloc::deallocateBytes(ptr);
		}


		void operator delete[] ( void* ptr, const char* , int , const char*  )
		{
			Alloc::deallocateBytes(ptr);
		}
	};
}