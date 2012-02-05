/********************************************************************
	创建时间:	8:1:2012   21:48
	文件名: 	f:\Aurorar\Core\Resource.h
	创建者:		丁亮
	
	文件作用:	资源基类 所有的资源都派生自本类
*********************************************************************/

#pragma once
#include "Prerequisites.h"

namespace Aurora
{
	class CORE_API Resource : public ResourceAllocatedObject
	{
	public:
		Resource(void);
		virtual ~Resource(void);

		typedef unsigned long long int ResourceHandle;


		class LoadingListener
		{
		public:
			virtual ~LoadingListener() {}

			virtual void PreparingComplete(Resource*)	{  }

			virtual void LoadingComplete(Resource*)		{  }

			virtual void UnLoadingComplete(Resource*)	{  }
		};

		enum LoadingState
		{
			LS_UNLOADED,
			
			LS_PREPARING,
			LS_PREPARED,

			LS_LOADING,
			LS_LOADED,

			LS_UNLOADING,

			LS_MAX
		};

		virtual bool	Load() = 0;

		virtual void	UnLoad() = 0;


		// 设备丢失
		virtual void    OnDeviceLost() = 0;

		// 通过上层的数据 构建相应的API层资源对象 对象指针由API层子类声明
		virtual bool	MakeAPIObject() = 0;

		// Unload
		// 用于排序内存的默认策略
		static  bool	LessFunctionInMemory(const Resource& e1, const Resource& e2);

		// 用于排序高速缓存的默认策略
		static  bool	LessFunctionInCache(const Resource& e1, const Resource& e2);


		DWORD			GetState() const { return  (DWORD)m_eState; }

	protected:

		String			m_szName;

		
		ResourceHandle	m_hHandle;

		// 内存维护用到的属性
		DWORD			m_dwUseTimeInCache;
		DWORD			m_dwUseTimeInMemory;
		DWORD			m_dwTimeStamp;

		LoadingState	m_eState;

		bool			m_bIsCatched;

		typedef list<LoadingListener*>::type ListenerList;
		ListenerList m_lstListener;
	};

	typedef boost::shared_ptr<Resource> ResourcePtr;
	
}
