/********************************************************************
	����ʱ��:	8:1:2012   21:48
	�ļ���: 	f:\Aurorar\Core\Resource.h
	������:		����
	
	�ļ�����:	��Դ���� ���е���Դ�������Ա���
				����������Դ���ز���:
				��һ�׶Σ�Ԥ�� ֻ����Resource��Ҫ���ص���Դ�ڴ�����
						  ��λ��
				�ڶ��׶Σ�װ�� ����Դ���뵽��Դ���ض���
				�����׶Σ����� ����������Դ���ݵ��ڴ�
				���Ľ׶Σ���Ⱦʱ ���Ѽ��ص���Դ���뵽���ٻ���

				����������Դ����ز���:
				��һ�׶Σ�����Դָ��Ӹ��ٻ������Ƴ�
				�ڶ��׶Σ�����Դ���ڴ���ж�� ֻ������Դ��
				�����׶Σ�����Դ����ɾ��

				���������ڴ�ά������:
				���ڴ治��(����ж�����Դ�������涨)ʱ ����ʱ������� 
				ʱ�����ͬ�� ����ʹ�ü������� ����ʹ�ô������� 
				UnLoadһ����Ŀ����Դ����(������������Դ�������涨)
				���ٻ����������UnCacheʱ������ ���ڴ��������UnLoad֮
				����Ȼ���� ����ReSetupʱ��������λ��(�ϴμ���֮��ʹ��
				�Ĵ���Խ�������λ��Խ��ǰ)
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

		typedef void	(*NotifyFunction)();

		virtual void	OnPrepare(const String& szFile);

		virtual void	OnSetup() = 0;

		virtual void	OnReSetup() = 0;

		virtual bool	OnLoad() = 0;

		virtual void	OnReLoad() = 0;

		virtual void	OnUnLoad() = 0;

		virtual void	OnCache() = 0;

		virtual void	OnUnCache() = 0;

		virtual void	OnReCache() = 0;

		virtual void	OnRelease() = 0;

		// �豸��ʧ
		virtual void    OnDeviceLost() = 0;

		// ͨ���ϲ������ ������Ӧ��API����Դ���� ����ָ����API����������
		virtual bool	MakeAPIObject() = 0;

		// ���������ڴ��Ĭ�ϲ���
		static  bool	LessFunctionInMemory(const Resource& e1, const Resource& e2);

		// ����������ٻ����Ĭ�ϲ���
		static  bool	LessFunctionInCache(const Resource& e1, const Resource& e2);

	protected:

		// Ҫ�ҵ��ļ���m_szPath + "/" + m_szFileName + "." + m_szFileExt
		String			m_szFileName;	// �ļ��� ��������չ��
		String			m_szFileExt;	// ��չ��
		String			m_szPath;		// ·�� �������ļ�������չ��

		DWORD			m_dwUseTimeInCache;
		DWORD			m_dwUseTimeInMemory;
		DWORD			m_dwTimeStamp;
	};
}
