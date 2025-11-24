
// EscapeDlg.h: 헤더 파일
//

#pragma once


// CEscapeDlg 대화 상자
class CEscapeDlg : public CDialogEx
{
// 생성입니다.
public:
	CEscapeDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ESCAPE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void OnStnClickedBooklist();
	CStatic m_boollist;

	//afx_msg void OnBnClickedButtonBooklist();
	//afx_msg void OnBnClickedButtonPicture();
	//afx_msg void OnBnClickedButtonLocker();
	//afx_msg void OnBnClickedButtonStand();
	
	CBitmap m_bmpBackground;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedHide();
	afx_msg void OnBnClickedOut();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int m_seconds = 0;
	CFont m_fontTimer;
};
