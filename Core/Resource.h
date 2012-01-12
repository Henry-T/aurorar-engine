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
				���ڴ治��(����ж�����Դ�������涨)ʱ ����ʹ�ô�����
				�� UnLoadһ����Ŀ����Դ����(������������Դ�������涨)
				���ٻ���ʹ����ͬ���� ����������ͬ ���ٻ����������UnCache
				ʱ������ ���ڴ��������UnLoad֮����Ȼ���� ����ReSetup
				ʱ��������λ��(�ϴμ���֮��ʹ�õĴ���Խ�������λ��Խ
				��ǰ)
*********************************************************************/

#pragma once
#include "Prerequisites.h"

namespace Aurora
{
	class CORE_API Resource : public GeneralAllocatedObject
	{
	public:
		Resource(void);
		virtual ~Resource(void);

		virtual void	OnPrepare(const String& szFile) {}

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

	protected:

		// Ҫ�ҵ��ļ���m_szPath + "/" + m_szFileName + "." + m_szFileExt
		String			m_szFileName;	// �ļ��� ��������չ��
		String			m_szFileExt;	// ��չ��
		String			m_szPath;		// ·�� �������ļ�������չ��

		DWORD			m_dwUseTimeInCache;
		DWORD			m_dwUseTimeInMemory;
	};
}
