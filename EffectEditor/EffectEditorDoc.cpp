
// EffectEditorDoc.cpp : CEffectEditorDoc 类的实现
//

#include "stdafx.h"
#include "EffectEditor.h"

#include "EffectEditorDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEffectEditorDoc

IMPLEMENT_DYNCREATE(CEffectEditorDoc, CDocument)

BEGIN_MESSAGE_MAP(CEffectEditorDoc, CDocument)
END_MESSAGE_MAP()


// CEffectEditorDoc 构造/析构

CEffectEditorDoc::CEffectEditorDoc()
{
	// TODO: 在此添加一次性构造代码

}

CEffectEditorDoc::~CEffectEditorDoc()
{
}

BOOL CEffectEditorDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CEffectEditorDoc 序列化

void CEffectEditorDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CEffectEditorDoc 诊断

#ifdef _DEBUG
void CEffectEditorDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEffectEditorDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CEffectEditorDoc 命令
