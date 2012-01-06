/********************************************************************
	创建时间:	4:1:2012   0:58
	文件名	:	MemoryAllocatorConfig
	创建者:		丁亮
	
	文件作用:	有关内存分配器的一些定义
*********************************************************************/
#pragma once

#include "AllocatedObject.h"
#include "MemoryNedPooling.h"

namespace Aurora
{
	enum MemoryCategory
	{
		/// General purpose
		MEMCATEGORY_GENERAL = 0,
		MEMCATEGORY_GEOMETRY = 1, 
		MEMCATEGORY_ANIMATION = 2, 
		MEMCATEGORY_SCENE_CONTROL = 3,
		MEMCATEGORY_SCENE_OBJECTS = 4,
		MEMCATEGORY_RESOURCE = 5,
		MEMCATEGORY_SCRIPTING = 6,
		MEMCATEGORY_RENDERSYS = 7,

		// sentinel value, do not use 
		MEMCATEGORY_COUNT = 8
	};

	template <MemoryCategory Cat> class CategorisedAllocPolicy : public NedPoolingPolicy{};
	template <MemoryCategory Cat, size_t align = 0> class CategorisedAlignAllocPolicy : public NedPoolingAlignedPolicy<align>{};

	// Useful shortcuts
	typedef CategorisedAllocPolicy<Aurora::MEMCATEGORY_GENERAL>			GeneralAllocPolicy;
	typedef CategorisedAllocPolicy<Aurora::MEMCATEGORY_GEOMETRY>		GeometryAllocPolicy;
	typedef CategorisedAllocPolicy<Aurora::MEMCATEGORY_ANIMATION>		AnimationAllocPolicy;
	typedef CategorisedAllocPolicy<Aurora::MEMCATEGORY_SCENE_CONTROL>	SceneCtlAllocPolicy;
	typedef CategorisedAllocPolicy<Aurora::MEMCATEGORY_SCENE_OBJECTS>	SceneObjAllocPolicy;
	typedef CategorisedAllocPolicy<Aurora::MEMCATEGORY_RESOURCE>		ResourceAllocPolicy;
	typedef CategorisedAllocPolicy<Aurora::MEMCATEGORY_SCRIPTING>		ScriptingAllocPolicy;
	typedef CategorisedAllocPolicy<Aurora::MEMCATEGORY_RENDERSYS>		RenderSysAllocPolicy;

	// Now define all the base classes for each allocation
	typedef AllocatedObject<GeneralAllocPolicy>							GeneralAllocatedObject;
	typedef AllocatedObject<GeometryAllocPolicy>						GeometryAllocatedObject;
	typedef AllocatedObject<AnimationAllocPolicy>						AnimationAllocatedObject;
	typedef AllocatedObject<SceneCtlAllocPolicy>						SceneCtlAllocatedObject;
	typedef AllocatedObject<SceneObjAllocPolicy>						SceneObjAllocatedObject;
	typedef AllocatedObject<ResourceAllocPolicy>						ResourceAllocatedObject;
	typedef AllocatedObject<ScriptingAllocPolicy>						ScriptingAllocatedObject;
	typedef AllocatedObject<RenderSysAllocPolicy>						RenderSysAllocatedObject;

	template<typename T>
	T* constructN(T* basePtr, size_t count)
	{
		for (size_t i = 0; i < count; ++i)
		{
			new ((void*)(basePtr+i)) T();
		}
		return basePtr;
	}
}

#ifdef _DEBUG
#	define NED_MALLOC(bytes, category)									::Aurora::CategorisedAllocPolicy<category>::allocateBytes(bytes, __FILE__, __LINE__, __FUNCTION__)
#	define NED_ALLOC_T(T, count, category)								static_cast<T*>(::Aurora::CategorisedAllocPolicy<category>::allocateBytes(sizeof(T)*(count), __FILE__, __LINE__, __FUNCTION__))
#	define NED_FREE(ptr, category)										::Aurora::CategorisedAllocPolicy<category>::deallocateBytes((void*)ptr)

#	define NED_NEW_T(T, category)										new (::Aurora::CategorisedAllocPolicy<category>::allocateBytes(sizeof(T), __FILE__, __LINE__, __FUNCTION__)) T
#	define NED_NEW_ARRAY_T(T, count, category)							::Aurora::constructN(static_cast<T*>(::Aurora::CategorisedAllocPolicy<category>::allocateBytes(sizeof(T)*(count), __FILE__, __LINE__, __FUNCTION__)), count) 
#	define NED_DELETE_T(ptr, T, category)								if(ptr){(ptr)->~T(); ::Aurora::CategorisedAllocPolicy<category>::deallocateBytes((void*)ptr);}
#	define NED_DELETE_ARRAY_T(ptr, T, count, category)					if(ptr){for (size_t b = 0; b < count; ++b) { (ptr)[b].~T();} ::Aurora::CategorisedAllocPolicy<category>::deallocateBytes((void*)ptr);}

#	define NED_MALLOC_SIMD(bytes, category)								::Aurora::CategorisedAlignAllocPolicy<category>::allocateBytes(bytes, __FILE__, __LINE__, __FUNCTION__)
#	define NED_MALLOC_ALIGN(bytes, category, align)						::Aurora::CategorisedAlignAllocPolicy<category, align>::allocateBytes(bytes, __FILE__, __LINE__, __FUNCTION__)
#	define NED_ALLOC_T_SIMD(T, count, category)							static_cast<T*>(::Aurora::CategorisedAlignAllocPolicy<category>::allocateBytes(sizeof(T)*(count), __FILE__, __LINE__, __FUNCTION__))
#	define NED_ALLOC_T_ALIGN(T, count, category, align)					static_cast<T*>(::Aurora::CategorisedAlignAllocPolicy<category, align>::allocateBytes(sizeof(T)*(count), __FILE__, __LINE__, __FUNCTION__))
#	define NED_FREE_SIMD(ptr, category)									::Aurora::CategorisedAlignAllocPolicy<category>::deallocateBytes(ptr)
#	define NED_FREE_ALIGN(ptr, category, align)							::Aurora::CategorisedAlignAllocPolicy<category, align>::deallocateBytes(ptr)

#	define NED_NEW_T_SIMD(T, category)									new (::Aurora::CategorisedAlignAllocPolicy<category>::allocateBytes(sizeof(T), __FILE__, __LINE__, __FUNCTION__)) T
#	define NED_NEW_ARRAY_T_SIMD(T, count, category)						::Aurora::constructN(static_cast<T*>(::Aurora::CategorisedAlignAllocPolicy<category>::allocateBytes(sizeof(T)*(count), __FILE__, __LINE__, __FUNCTION__)), count) 
#	define NED_DELETE_T_SIMD(ptr, T, category)							if(ptr){(ptr)->~T(); ::Aurora::CategorisedAlignAllocPolicy<category>::deallocateBytes(ptr);}
#	define NED_DELETE_ARRAY_T_SIMD(ptr, T, count, category)				if(ptr){for (size_t b = 0; b < count; ++b) { (ptr)[b].~T();} ::Aurora::CategorisedAlignAllocPolicy<category>::deallocateBytes(ptr);}
#	define NED_NEW_T_ALIGN(T, category, align)							new (::Aurora::CategorisedAlignAllocPolicy<category, align>::allocateBytes(sizeof(T), __FILE__, __LINE__, __FUNCTION__)) T
#	define NED_NEW_ARRAY_T_ALIGN(T, count, category, align)				::Aurora::constructN(static_cast<T*>(::Aurora::CategorisedAlignAllocPolicy<category, align>::allocateBytes(sizeof(T)*(count), __FILE__, __LINE__, __FUNCTION__)), count) 
#	define NED_DELETE_T_ALIGN(ptr, T, category, align)					if(ptr){(ptr)->~T(); ::Aurora::CategorisedAlignAllocPolicy<category, align>::deallocateBytes(ptr);}
#	define NED_DELETE_ARRAY_T_ALIGN(ptr, T, count, category, align)		if(ptr){for (size_t _b = 0; _b < count; ++_b) { (ptr)[_b].~T();} ::Aurora::CategorisedAlignAllocPolicy<category, align>::deallocateBytes(ptr);}

#	define NED_NEW														new (__FILE__, __LINE__, __FUNCTION__)
#	define NED_DELETE													delete
#else
#	define NED_MALLOC(bytes, category)									::Aurora::CategorisedAllocPolicy<category>::allocateBytes(bytes)
#	define NED_ALLOC_T(T, count, category)								static_cast<T*>(::Aurora::CategorisedAllocPolicy<category>::allocateBytes(sizeof(T)*(count)))
#	define NED_FREE(ptr, category)										::Aurora::CategorisedAllocPolicy<category>::deallocateBytes((void*)ptr)

#	define NED_NEW_T(T, category)										new (::Aurora::CategorisedAllocPolicy<category>::allocateBytes(sizeof(T))) T
#	define NED_NEW_ARRAY_T(T, count, category)							::Aurora::constructN(static_cast<T*>(::Aurora::CategorisedAllocPolicy<category>::allocateBytes(sizeof(T)*(count))), count) 
#	define NED_DELETE_T(ptr, T, category)								if(ptr){(ptr)->~T(); ::Aurora::CategorisedAllocPolicy<category>::deallocateBytes((void*)ptr);}
#	define NED_DELETE_ARRAY_T(ptr, T, count, category)					if(ptr){for (size_t b = 0; b < count; ++b) { (ptr)[b].~T();} ::Aurora::CategorisedAllocPolicy<category>::deallocateBytes((void*)ptr);}

#	define NED_MALLOC_SIMD(bytes, category)								::Aurora::CategorisedAlignAllocPolicy<category>::allocateBytes(bytes)
#	define NED_MALLOC_ALIGN(bytes, category, align)						::Aurora::CategorisedAlignAllocPolicy<category, align>::allocateBytes(bytes)
#	define NED_ALLOC_T_SIMD(T, count, category)							static_cast<T*>(::Aurora::CategorisedAlignAllocPolicy<category>::allocateBytes(sizeof(T)*(count)))
#	define NED_ALLOC_T_ALIGN(T, count, category, align)					static_cast<T*>(::Aurora::CategorisedAlignAllocPolicy<category, align>::allocateBytes(sizeof(T)*(count)))
#	define NED_FREE_SIMD(ptr, category)									::Aurora::CategorisedAlignAllocPolicy<category>::deallocateBytes((void*)ptr)
#	define NED_FREE_ALIGN(ptr, category, align)							::Aurora::CategorisedAlignAllocPolicy<category, align>::deallocateBytes((void*)ptr)

#	define NED_NEW_T_SIMD(T, category)									new (::Aurora::CategorisedAlignAllocPolicy<category>::allocateBytes(sizeof(T))) T
#	define NED_NEW_ARRAY_T_SIMD(T, count, category)						::Aurora::constructN(static_cast<T*>(::Aurora::CategorisedAlignAllocPolicy<category>::allocateBytes(sizeof(T)*(count))), count) 
#	define NED_DELETE_T_SIMD(ptr, T, category) if(ptr){(ptr)->~T();		::Aurora::CategorisedAlignAllocPolicy<category>::deallocateBytes((void*)ptr);}
#	define NED_DELETE_ARRAY_T_SIMD(ptr, T, count, category)				if(ptr){for (size_t b = 0; b < count; ++b) { (ptr)[b].~T();} ::Aurora::CategorisedAlignAllocPolicy<category>::deallocateBytes((void*)ptr);}
#	define NED_NEW_T_ALIGN(T, category, align)							new (::Aurora::CategorisedAlignAllocPolicy<category, align>::allocateBytes(sizeof(T))) T
#	define NED_NEW_ARRAY_T_ALIGN(T, count, category, align)				::Aurora::constructN(static_cast<T*>(::Aurora::CategorisedAlignAllocPolicy<category, align>::allocateBytes(sizeof(T)*(count))), count) 
#	define NED_DELETE_T_ALIGN(ptr, T, category, align)					if(ptr){(ptr)->~T(); ::Aurora::CategorisedAlignAllocPolicy<category, align>::deallocateBytes((void*)ptr);}
#	define NED_DELETE_ARRAY_T_ALIGN(ptr, T, count, category, align)		if(ptr){for (size_t _b = 0; _b < count; ++_b) { (ptr)[_b].~T();} ::Aurora::CategorisedAlignAllocPolicy<category, align>::deallocateBytes((void*)ptr);}


#	define NED_NEW														new 
#	define NED_DELETE													delete
#endif



