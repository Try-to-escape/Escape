#pragma once
#include "afxdialogex.h"


// CHintDlg 대화 상자

class CHintDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CHintDlg)

public:
	CHintDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CHintDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HintDlg};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CImage m_imgHint[3];
	virtual BOOL OnInitDialog();
	//나가기 버튼
	CButton m_btnOut;
	//화면 출력 이미지
	CImage* m_pCurrentImage;
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButtonOut();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int m_nCurrentImageIndex;
	CImage m_imgHintFail;
};
