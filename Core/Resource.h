/********************************************************************
	����ʱ��:	8:1:2012   21:48
	�ļ���: 	f:\Aurorar\Core\Resource.h
	������:		����
	
	�ļ�����:	��Դ���� ���е���Դ�������Ա���
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


		// �豸��ʧ
		virtual void    OnDeviceLost() = 0;

		// ͨ���ϲ������ ������Ӧ��API����Դ���� ����ָ����API����������
		virtual bool	MakeAPIObject() = 0;

		// Unload
		// ���������ڴ��Ĭ�ϲ���
		static  bool	LessFunctionInMemory(const Resource& e1, const Resource& e2);

		// ����������ٻ����Ĭ�ϲ���
		static  bool	LessFunctionInCache(const Resource& e1, const Resource& e2);


		DWORD			GetState() const { return  (DWORD)m_eState; }

	protected:

		String			m_szName;

		
		ResourceHandle	m_hHandle;

		// �ڴ�ά���õ�������
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
