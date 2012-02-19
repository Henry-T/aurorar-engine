/********************************************************************
	����ʱ��:	15:2:2012   8:28
	�ļ���	:	Shader
	������:		����
	
	�ļ�����:	�ɱ����ɫ��
				
				��ŷ������ ���ٲ�ȡOgre���ֶԲ�����Shader����ģ����
				����ʽ �����ϸ��������ߵĺ��塣

				ŷ�����Ĳ��ʲ�������Ⱦ״̬���κι��� ��ֻ�����¼��
				�������������Ĳ��� �����������һ����Ա����
				Shader�ĺ��彫��ȫ�Ǻ�����������ȾAPI�е�Shader ��һ
				��ȫ�ָ���

				��Ⱦʱ��ShaderΪ��λ �õ�ͬһ��Shader�������ͬ��һ��
				����һ�� ��֤��Ⱦ״̬�л��Ĵ�������
				ͬ��֮�� ���ݲ����е��������� ��֤��GPU�����������ݵ�
				��������

				ŷ�����Ķ�λΪ����Ϲ��������г��Ĵ�������Ⱦ���� ���
				�������ǲ�֧��Shader���Կ� ͬʱΪ�˸��ӷ���DX10֮���
				��Ⱦ����� ŷ��������ȫ�����̶�������ˮ�� ���е���Ⱦ��
				��������Shader���
*********************************************************************/
#pragma once
#include "Prerequisites.h"

namespace Aurora
{
	class CORE_API Shader : public Resource
	{
	public:
		Shader(void);
		virtual ~Shader(void);

		virtual bool	Load(String& path, const String& name);

		virtual void	UnLoad();

		void			EnableTechnique(const String& name, bool enable);

		void			EnableTechnique(uint8 index, bool enable);

		virtual void	BeginFrame();

		virtual void	EndFrame();

		typedef vector<TechniquePtr>::type TechniqueList;

	protected:
		TechniqueList	m_vecTechnique;
	};
}

