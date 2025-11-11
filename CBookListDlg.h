#pragma once
#include "afxdialogex.h"


// CBookListDlg 대화 상자

class CBookListDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBookListDlg)

public:
	CBookListDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CBookListDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_BOOKLIST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonWbook();
	afx_msg void OnBnClickedButtonFbook();
};
