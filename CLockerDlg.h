#pragma once
#include "afxdialogex.h"


// CLockerDlg 대화 상자

class CLockerDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLockerDlg)

private:
	// 기본 금고 이미지
	CImage m_imgLocker;
	// 암호 성공시 금고 열림 이미지
	CImage m_imgLockerOpen;
	// 암호 실패시 금고 경보 이미지
	CImage m_imgLockerAlert;
	// 시험지 상세 이미지
	CImage m_imgTestPaper;

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
	// 암호 입력창
	CEdit m_editInput;
	//버튼 클릭시 함수
	afx_msg void OnBnClickedButton(UINT nID);
	// 암호 정답값
	CString m_strPassword;
	CButton m_btn1;
	CButton m_btn2;
	CButton m_btn3;
	CButton m_btn4;
	CButton m_btn5;
	CButton m_btn6;
	CButton m_btn7;
	CButton m_btn8;
	CButton m_btn9;
private:
	// 현제 화면에 출력할 이미지 포인터
	CImage* m_pCurrentImage;
public:
	afx_msg void OnBnClickedButton1();
	CButton n_btnOk;
};
