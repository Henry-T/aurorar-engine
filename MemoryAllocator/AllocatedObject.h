/********************************************************************
	����ʱ��:	4:1:2012   0:56
	�ļ���	:	AllocatedObject
	������:		����
	
	�ļ�����:	����������ͬ���ڴ���䷽�� Ŀǰֻʹ��Ĭ�Ϸ���
				������MemoryAllocatorConfig.h�ļ���
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