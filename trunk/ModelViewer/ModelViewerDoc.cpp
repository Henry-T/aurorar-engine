
// ModelViewerDoc.cpp : CModelViewerDoc 类的实现
//

#include "stdafx.h"
#include "ModelViewer.h"

#include "ModelViewerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CModelViewerDoc

IMPLEMENT_DYNCREATE(CModelViewerDoc, CDocument)

BEGIN_MESSAGE_MAP(CModelViewerDoc, CDocument)
END_MESSAGE_MAP()


// CModelViewerDoc 构造/析构

CModelViewerDoc::CModelViewerDoc()
{
	// TODO: 在此添加一次性构造代码

}

CModelViewerDoc::~CModelViewerDoc()
{
}

BOOL CModelViewerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CModelViewerDoc 序列化

void CModelViewerDoc::Serialize(CArchive& ar)
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


// CModelViewerDoc 诊断

#ifdef _DEBUG
void CModelViewerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CModelViewerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CModelViewerDoc 命令
