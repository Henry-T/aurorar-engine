/********************************************************************
	创建时间:	4:1:2012   0:59
	文件名	:	MemoryNedPooling
	创建者:		丁亮
	
	文件作用:	基于nedmalloc的内存池具体实现
*********************************************************************/
#pragma once

#ifdef max
#undef max
#endif
#include <limits>

#define MEMORY_TRACKER 0
#define SIMD_ALIGNMENT 16

namespace Aurora
{
	namespace _NedPoolingIntern
	{
		size_t poolIDFromSize(size_t a_reqSize);
		void*  internalAlloc(size_t a_reqSize);
		void*  internalAllocAligned(size_t a_align, size_t a_reqSize);
		void   internalFree(void* a_mem);
	}
	class NedPoolingImpl
	{
	public:
		static void* allocBytes(size_t count, const char* file, int line, const char* func);
		static void  deallocBytes(void* ptr);
		static void* allocBytesAligned(size_t align, size_t count, const char* file, int line, const char* func);
		static void  deallocBytesAligned(size_t align, void* ptr);
	};

	class NedPoolingPolicy
	{
	public:
		static inline void* allocateBytes(size_t count, const char* file = 0, int line = 0, const char* func = 0)
		{
			return NedPoolingImpl::allocBytes(count, file, line, func);
		}
		static inline void deallocateBytes(void* ptr)
		{
			NedPoolingImpl::deallocBytes(ptr);
		}
		static inline size_t getMaxAllocationSize()
		{
			return std::numeric_limits<size_t>::max();
		}

	private:
		NedPoolingPolicy() {}
	};

	template <size_t Alignment = 0>
	class NedPoolingAlignedPolicy
	{
	public:
		typedef int IsValidAlignment[Alignment <= 128 && ((Alignment & (Alignment-1)) == 0) ? +1 : -1];

		static inline void* allocateBytes(size_t count, const char* file = 0, int line = 0, const char* func = 0)
		{
			return NedPoolingImpl::allocBytesAligned(Alignment, count, file, line, func);
		}

		static inline void deallocateBytes(void* ptr)
		{
			NedPoolingImpl::deallocBytesAligned(Alignment, ptr);
		}

		static inline size_t getMaxAllocationSize()
		{
			return std::numeric_limits<size_t>::max();
		}
	private:
		NedPoolingAlignedPolicy() {}
	};
}