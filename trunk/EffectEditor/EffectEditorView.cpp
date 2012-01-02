
// EffectEditorView.cpp : CEffectEditorView 类的实现
//

#include "stdafx.h"
#include "EffectEditor.h"

#include "EffectEditorDoc.h"
#include "EffectEditorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEffectEditorView

IMPLEMENT_DYNCREATE(CEffectEditorView, CView)

BEGIN_MESSAGE_MAP(CEffectEditorView, CView)
END_MESSAGE_MAP()

// CEffectEditorView 构造/析构

CEffectEditorView::CEffectEditorView()
{
	// TODO: 在此处添加构造代码

}

CEffectEditorView::~CEffectEditorView()
{
}

BOOL CEffectEditorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEffectEditorView 绘制

void CEffectEditorView::OnDraw(CDC* /*pDC*/)
{
	CEffectEditorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CEffectEditorView 诊断

#ifdef _DEBUG
void CEffectEditorView::AssertValid() const
{
	CView::AssertValid();
}

void CEffectEditorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEffectEditorDoc* CEffectEditorView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEffectEditorDoc)));
	return (CEffectEditorDoc*)m_pDocument;
}
#endif //_DEBUG


// CEffectEditorView 消息处理程序
