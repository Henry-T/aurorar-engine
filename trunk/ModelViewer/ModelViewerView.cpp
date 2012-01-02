
// ModelViewerView.cpp : CModelViewerView 类的实现
//

#include "stdafx.h"
#include "ModelViewer.h"

#include "ModelViewerDoc.h"
#include "ModelViewerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CModelViewerView

IMPLEMENT_DYNCREATE(CModelViewerView, CView)

BEGIN_MESSAGE_MAP(CModelViewerView, CView)
END_MESSAGE_MAP()

// CModelViewerView 构造/析构

CModelViewerView::CModelViewerView()
{
	// TODO: 在此处添加构造代码

}

CModelViewerView::~CModelViewerView()
{
}

BOOL CModelViewerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CModelViewerView 绘制

void CModelViewerView::OnDraw(CDC* /*pDC*/)
{
	CModelViewerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CModelViewerView 诊断

#ifdef _DEBUG
void CModelViewerView::AssertValid() const
{
	CView::AssertValid();
}

void CModelViewerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CModelViewerDoc* CModelViewerView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CModelViewerDoc)));
	return (CModelViewerDoc*)m_pDocument;
}
#endif //_DEBUG


// CModelViewerView 消息处理程序
