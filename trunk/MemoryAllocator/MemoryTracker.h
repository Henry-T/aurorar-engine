/********************************************************************
	����ʱ��:	4:1:2012   0:59
	�ļ���	:	MemoryTracker
	������:		����
	
	�ļ�����:	�ڴ�׷�� ���ڵ����ڴ�й¶ Ĭ�Ϲر�
				��Ҫ���� ��MemoryNedPooling.h�ļ��е�MEMORY_TRACKER
				�ĳ�1���±���
*********************************************************************/
#pragma once
#include <string>
#include <hash_map>
#include <vector>

namespace Aurora
{
	class MemoryTracker
	{
	protected:
		struct Alloc
		{
			size_t bytes;
			unsigned int pool;
			std::string filename;
			size_t line;
			std::string function;

			Alloc() :bytes(0), line(0) {}
			Alloc(size_t sz, unsigned int p, const char* file, size_t ln, const char* func)
				:bytes(sz), pool(p), line(ln)
			{
				if (file)
					filename = file;
				if (func)
					function = func;
			}
		};

		std::string mLeakFileName;
		bool mDumpToStdOut;
		typedef stdext::hash_map<void*, Alloc> AllocationMap;
		AllocationMap mAllocations;

		size_t mTotalAllocations;
		typedef std::vector<size_t> AllocationsByPool;
		AllocationsByPool mAllocationsByPool;

		void reportLeaks();

		// protected ctor
		MemoryTracker()
			: mLeakFileName("AuroraLeaks.log"), mDumpToStdOut(true),
			mTotalAllocations(0)
		{
		}
	public:

		/** Set the name of the report file that will be produced on exit. */
		void setReportFileName(const std::string& name)
		{
			mLeakFileName = name;
		}
		/// Return the name of the file which will contain the report at exit
		const std::string& getReportFileName() const
		{
			return mLeakFileName;
		}
		/// Sets whether the memory report should be sent to stdout
		void setReportToStdOut(bool rep)
		{
			mDumpToStdOut = rep;
		}
		/// Gets whether the memory report should be sent to stdout
		bool getReportToStdOut() const
		{
			return mDumpToStdOut;
		}

		/// Get the total amount of memory allocated currently.
		size_t getTotalMemoryAllocated() const;
		/// Get the amount of memory allocated in a given pool
		size_t getMemoryAllocatedForPool(unsigned int pool) const;


		/** Record an allocation that has been made. Only to be called by
		the memory management subsystem.
		@param ptr The pointer to the memory
		@param sz The size of the memory in bytes
		@param pool The memory pool this allocation is occurring from
		@param file The file in which the allocation is being made
		@param ln The line on which the allocation is being made
		@param func The function in which the allocation is being made
		*/
		void _recordAlloc(void* ptr, size_t sz, unsigned int pool = 0,
			const char* file = 0, size_t ln = 0, const char* func = 0);
		/** Record the deallocation of memory. */
		void _recordDealloc(void* ptr);

		~MemoryTracker()
		{
			reportLeaks();
		}

		/// Static utility method to get the memory tracker instance
		static MemoryTracker& get();
	};
}
