
// ModelViewerDoc.h : CModelViewerDoc ��Ľӿ�
//


#pragma once


class CModelViewerDoc : public CDocument
{
protected: // �������л�����
	CModelViewerDoc();
	DECLARE_DYNCREATE(CModelViewerDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CModelViewerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


