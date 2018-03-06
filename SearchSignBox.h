#pragma once
#include "Resource.h"
#include "afxcmn.h"
#include <list>
#include "arxHeaders.h"

using std::list;

// SearchSignBox �Ի���

class SearchSignBox : public CAcUiDialog
{
	DECLARE_DYNAMIC(SearchSignBox)

public:
	SearchSignBox(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~SearchSignBox();

	// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SEARCHSIGNBOX };
#endif

private:
	typedef struct SignBoxInfo
	{
		CString title;
		CString blockName;
		CString origin;
	}SignBoxInfo;

	list<SignBoxInfo> m_searchedSignBoxList;
	CListCtrl m_listCtrl;

protected:
	DECLARE_MESSAGE_MAP()
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	BOOL OnInitDialog();
	void RefreshListCtrl();
	afx_msg void OnBnClickedButtonStartsearch();
	afx_msg LRESULT OnAcadKeepFocus(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnBnClickedButtonHelp();
};
