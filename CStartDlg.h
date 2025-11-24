#pragma once
#include "afxdialogex.h"


// CStartDlg 대화 상자

class CStartDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CStartDlg)

public:
	CStartDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CStartDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_START };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
	CBitmap m_bmpStart;
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
