
// EffectEditorDoc.cpp : CEffectEditorDoc ���ʵ��
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


// CEffectEditorDoc ����/����

CEffectEditorDoc::CEffectEditorDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CEffectEditorDoc::~CEffectEditorDoc()
{
}

BOOL CEffectEditorDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CEffectEditorDoc ���л�

void CEffectEditorDoc::Serialize(CArchive& ar)
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


// CEffectEditorDoc ���

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


// CEffectEditorDoc ����
