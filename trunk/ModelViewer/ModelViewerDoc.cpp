
// ModelViewerDoc.cpp : CModelViewerDoc ���ʵ��
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


// CModelViewerDoc ����/����

CModelViewerDoc::CModelViewerDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CModelViewerDoc::~CModelViewerDoc()
{
}

BOOL CModelViewerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CModelViewerDoc ���л�

void CModelViewerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CModelViewerDoc ���

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


// CModelViewerDoc ����
