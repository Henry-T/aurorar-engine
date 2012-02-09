/********************************************************************
	����ʱ��:	14:1:2012   13:19
	�ļ���	:	ResourceManager
	������:		����
	
	�ļ�����:	��Դ������ ����ͳһ�������е���Դ ÿ����Դֻ����һ��
				����

				����������Դ���ز���:
				��һ�׶Σ�Ԥ�� Ϊ��Դ��������ڴ�
				�ڶ��׶Σ����� ����������Դ���ݵ��ڴ�
				�����׶Σ���Ⱦʱ ���Ѽ��ص���Դ���뵽���ٻ���

				����������Դ����ز���:
				��һ�׶Σ�����Դָ��Ӹ��ٻ������Ƴ�
				�ڶ��׶Σ�����Դ���ڴ���ж��

				���������ڴ�ά������:
				���ڴ治��(����ж�����Դ�������涨)ʱ ����ʱ������� 
				ʱ�����ͬ�� ����ʹ�ü������� ����ʹ�ô������� 
				UnLoadһ����Ŀ����Դ����(������������Դ�������涨)
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

		// Prepare֮�� Load֮ǰ ������ ���ھ�������˳��
		void						PreLoadingSort();

		// Load֮�� ���ھ���ж��˳��
		void						PostLoadingSort();

	private:
		deque<ResourcePtr>::type	m_dqPrepared;

		ResourceMap					m_mapLoaded;		// ���������Ķ�ȡ���������Դ����
		ResourceHandleMap			m_mapLoadedHandle;		
		
		ResourceMap					m_mapCatched;		// ���ٻ���
		ResourceHandleMap			m_mapCatchedHandle;		
	};

	class CORE_API ResourceManager : public ResourceAllocatedObject, public Singleton<ResourceManager>
	{
	public:
		ResourceManager(void);
		~ResourceManager(void);

		// ˳��������� ��ʱ���Դ�˳����Ϊ�������ȼ�
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

