
// ModelViewerView.h : CModelViewerView 类的接口
//


#pragma once


class CModelViewerView : public CView
{
protected: // 仅从序列化创建
	CModelViewerView();
	DECLARE_DYNCREATE(CModelViewerView)

// 属性
public:
	CModelViewerDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CModelViewerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ModelViewerView.cpp 中的调试版本
inline CModelViewerDoc* CModelViewerView::GetDocument() const
   { return reinterpret_cast<CModelViewerDoc*>(m_pDocument); }
#endif

