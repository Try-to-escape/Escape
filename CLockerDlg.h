#pragma once
#include "afxdialogex.h"


// CLockerDlg 대화 상자

class CLockerDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLockerDlg)

private:
	CImage m_imgLocker;

public:
	CLockerDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CLockerDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LockerDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	// 암호 입력창 제어 변수
	CString m_strEditInput;
	// 1번 버튼
	CButton m_btnOne;
	CButton m_btnTwo;
	CButton m_btnThree;
	CButton m_btnFour;
	CButton m_btnFive;
	CButton m_btnSix;
	CButton m_btnSeven;
	CButton m_btnEight;
	CButton m_btnNine;
};
