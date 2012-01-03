#include "MemoryNedPooling.h"
#include "MemoryTracker.h"
#include "nedmalloc.c"

namespace Aurora
{
	namespace _NedPoolingIntern
	{
		const size_t s_poolCount = 14; 
		void* s_poolFootprint = reinterpret_cast<void*>(0xBB1AA45A);
		nedalloc::nedpool* s_pools[s_poolCount + 1] = { 0 };
		nedalloc::nedpool* s_poolsAligned[s_poolCount + 1] = { 0 };

		size_t poolIDFromSize(size_t a_reqSize)
		{
			size_t poolID = 0;

			if (a_reqSize > 0)
			{
				if (a_reqSize <= 16)
				{
					poolID = (a_reqSize - 1) >> 2;
				}
				else
				{
					poolID = std::min<size_t>(((a_reqSize - 1) >> 4) + 3, s_poolCount);
				}
			}

			return poolID;
		}

		void* internalAlloc(size_t a_reqSize)
		{
			size_t poolID = poolIDFromSize(a_reqSize);
			nedalloc::nedpool* pool(0); 

			if (poolID < s_poolCount)
			{
				if (s_pools[poolID] == 0)
				{
					s_pools[poolID] = nedalloc::nedcreatepool(0, 8);
					nedalloc::nedpsetvalue(s_pools[poolID], s_poolFootprint);
				}

				pool = s_pools[poolID];
			}

			return nedalloc::nedpmalloc(pool, a_reqSize);
		}

		void* internalAllocAligned(size_t a_align, size_t a_reqSize)
		{
			size_t poolID = poolIDFromSize(a_reqSize);
			nedalloc::nedpool* pool(0);

			if (poolID < s_poolCount)
			{
				if (s_poolsAligned[poolID] == 0)
				{
					// Init pool if first use

					s_poolsAligned[poolID] = nedalloc::nedcreatepool(0, 8);
					nedalloc::nedpsetvalue(s_poolsAligned[poolID], s_poolFootprint);
				}

				pool = s_poolsAligned[poolID];
			}

			return nedalloc::nedpmemalign(pool, a_align, a_reqSize);
		}

		void internalFree(void* a_mem)
		{
			if (a_mem)
			{
				nedalloc::nedpool* pool(0);
				void* footprint = nedalloc::nedgetvalue(&pool, a_mem);

				if (footprint == s_poolFootprint)
				{
					nedalloc::nedpfree(pool, a_mem);
				}
				else
				{
					nedalloc::nedfree(a_mem);
				}
			}
		}
	}

	//---------------------------------------------------------------------
	void* NedPoolingImpl::allocBytes(size_t count, const char* file, int line, const char* func)
	{
		void* ptr = _NedPoolingIntern::internalAlloc(count);
#if MEMORY_TRACKER
		MemoryTracker::get()._recordAlloc(ptr, count, 0, file, line, func);
#else
		// 避免未使用的变量警告
		file = func = "";
		line = 0;
#endif
		return ptr;
	}
	//---------------------------------------------------------------------
	void NedPoolingImpl::deallocBytes(void* ptr)
	{
		if (!ptr)
			return;
#if MEMORY_TRACKER
		MemoryTracker::get()._recordDealloc(ptr);
#endif
		_NedPoolingIntern::internalFree(ptr);
	}
	//---------------------------------------------------------------------
	void* NedPoolingImpl::allocBytesAligned(size_t align, size_t count, 
		const char* file, int line, const char* func)
	{
		void* ptr =  align ? _NedPoolingIntern::internalAllocAligned(align, count)
			: _NedPoolingIntern::internalAllocAligned(SIMD_ALIGNMENT, count);
#if MEMORY_TRACKER
		MemoryTracker::get()._recordAlloc(ptr, count, 0, file, line, func);
#else
		// 避免未使用的变量警告
		file = func = "";
		line = 0;
#endif
		return ptr;
	}
	//---------------------------------------------------------------------
	void NedPoolingImpl::deallocBytesAligned(size_t align, void* ptr)
	{
		if (!ptr)
			return;
#if MEMORY_TRACKER
		MemoryTracker::get()._recordDealloc(ptr);
#endif
		_NedPoolingIntern::internalFree(ptr);
	}
}