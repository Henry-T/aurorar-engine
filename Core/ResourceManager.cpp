#include "StdAfx.h"
#include "ResourceManager.h"

namespace Aurora
{
	template<> ResourceManager* Singleton<ResourceManager>::ms_Singleton = 0;
	ResourceManager* ResourceManager::getSingletonPtr(void)
	{
		return ms_Singleton;
	}
	ResourceManager& ResourceManager::getSingleton(void)
	{  
		assert( ms_Singleton );  return ( *ms_Singleton );  
	}

	ResourceManager::ResourceManager(void)
	{
		Init();
	}

	ResourceManager::~ResourceManager(void)
	{
	}

	void ResourceManager::Init()
	{
		m_mapPath.clear();
		m_mapLoadingDeque.clear();

		for (int i = RT_MESH; i < RT_MAX; ++i)
		{
			m_mapPath.insert(PathMap::value_type(i, StringVector()));
		}

		for (int i = RT_MESH; i < RT_MAX; ++i)
		{
			m_mapLoadingDeque.insert(LoadingDequeMap::value_type(i, LoadingDeque()));
		}
	}

	void ResourceManager::Release()
	{
		for (PathMap::iterator it = m_mapPath.begin(); it != m_mapPath.end(); ++it)
		{
			m_mapPath.erase(it);
		}
		for (LoadingDequeMap::iterator it = m_mapLoadingDeque.begin(); it != m_mapLoadingDeque.end(); ++it)
		{
			m_mapLoadingDeque.erase(it);
		}

		m_mapLoadingDeque.clear();
		m_mapPath.clear();
	}


	

}