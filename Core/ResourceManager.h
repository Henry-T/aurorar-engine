/********************************************************************
	创建时间:	14:1:2012   13:19
	文件名	:	ResourceManager
	创建者:		丁亮
	
	文件作用:	资源管理器 用于统一管理所有的资源 每个资源只保留一份
				数据

				极光引擎资源加载策略:
				第一阶段：预备 为资源对象分配内存
				第二阶段：加载 真正加载资源数据到内存
				第三阶段：渲染时 将已加载的资源插入到高速缓存

				极光引擎资源逆加载策略:
				第一阶段：将资源指针从高速缓存中移除
				第二阶段：将资源从内存中卸载

				极光引擎内存维护策略:
				当内存不足(如何判断由资源管理器规定)时 根据时间戳排序 
				时间戳相同的 根据使用计数排序 根据使用次数排序 
				UnLoad一定数目的资源对象(具体数字由资源管理器规定)
*********************************************************************/

#pragma once
#include "Prerequisites.h"
#include "..\Common\Singleton.h"
#include "Resource.h"
#include "..\Common\String.h"

namespace Aurora
{
	class LoadingDeque
	{
	public:
		LoadingDeque() {}
		typedef stdext::hash_map<String, ResourcePtr>			ResourceMap;
		typedef stdext::hash_map<Resource::ResourceHandle, ResourcePtr>	ResourceHandleMap;

		friend class ResourceManager;

		// Prepare之后 Load之前 的排序 用于决定加载顺序
		void						PreLoadingSort();

		// Load之后 用于决定卸载顺序
		void						PostLoadingSort();

	private:
		deque<ResourcePtr>::type	m_dqPrepared;

		ResourceMap					m_mapLoaded;		// 经过真正的读取操作后的资源对象
		ResourceHandleMap			m_mapLoadedHandle;		
		
		ResourceMap					m_mapCatched;		// 高速缓存
		ResourceHandleMap			m_mapCatchedHandle;		
	};

	class CORE_API ResourceManager : public ResourceAllocatedObject, public Singleton<ResourceManager>
	{
	public:
		ResourceManager(void);
		~ResourceManager(void);

		// 顺序不能随意改 暂时先以此顺序作为加载优先级
		enum ResourceType
		{
			RT_SHADER,
			RT_VERTEX_DECL,
			RT_MESH,
			RT_MATERIAL,
			RT_EFFECT,
			RT_TEXTURE,
			
			RT_MAX
		};

		static ResourceManager& getSingleton(void);

		static ResourceManager* getSingletonPtr(void);

		void		Init();

		void		Release();

		ResourcePtr	Prepare(ResourceType type, const String& fileName);

		bool		Load(ResourcePtr res);

		void		Catch(ResourcePtr res);

		bool		UnLoad(ResourcePtr res);


	private:

		typedef map<int, LoadingDeque>::type LoadingDequeMap;

		LoadingDequeMap	m_mapLoadingDeque;
		

		typedef map<int, StringVector>::type PathMap;

		PathMap m_mapPath;


	};

}

