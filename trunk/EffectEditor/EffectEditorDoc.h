
// EffectEditorDoc.h : CEffectEditorDoc ��Ľӿ�
//


#pragma once


class CEffectEditorDoc : public CDocument
{
protected: // �������л�����
	CEffectEditorDoc();
	DECLARE_DYNCREATE(CEffectEditorDoc)

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
	virtual ~CEffectEditorDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


