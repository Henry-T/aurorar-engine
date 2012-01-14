/********************************************************************
	创建时间:	8:1:2012   21:48
	文件名: 	f:\Aurorar\Core\Resource.h
	创建者:		丁亮
	
	文件作用:	资源基类 所有的资源都派生自本类
				极光引擎资源加载策略:
				第一阶段：预备 只告诉Resource类要加载的资源在磁盘上
						  的位置
				第二阶段：装载 将资源加入到资源加载队列
				第三阶段：加载 真正加载资源数据到内存
				第四阶段：渲染时 将已加载的资源插入到高速缓存

				极光引擎资源逆加载策略:
				第一阶段：将资源指针从高速缓存中移除
				第二阶段：将资源从内存中卸载 只保留资源名
				第三阶段：将资源对象删除

				极光引擎内存维护策略:
				当内存不足(如何判断由资源管理器规定)时 根据时间戳排序 
				时间戳相同的 根据使用计数排序 根据使用次数排序 
				UnLoad一定数目的资源对象(具体数字由资源管理器规定)
				高速缓存计数器在UnCache时会清零 而内存计数器在UnLoad之
				后依然保留 用作ReSetup时决定插入位置(上次加载之后使用
				的次数越多则入队位置越靠前)
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

		// 设备丢失
		virtual void    OnDeviceLost() = 0;

		// 通过上层的数据 构建相应的API层资源对象 对象指针由API层子类声明
		virtual bool	MakeAPIObject() = 0;

		// 用于排序内存的默认策略
		static  bool	LessFunctionInMemory(const Resource& e1, const Resource& e2);

		// 用于排序高速缓存的默认策略
		static  bool	LessFunctionInCache(const Resource& e1, const Resource& e2);

	protected:

		// 要找到文件：m_szPath + "/" + m_szFileName + "." + m_szFileExt
		String			m_szFileName;	// 文件名 不包括扩展名
		String			m_szFileExt;	// 扩展名
		String			m_szPath;		// 路径 不包括文件名和扩展名

		DWORD			m_dwUseTimeInCache;
		DWORD			m_dwUseTimeInMemory;
		DWORD			m_dwTimeStamp;
	};
}
