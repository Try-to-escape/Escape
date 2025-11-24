#pragma once
#include "afxdialogex.h"


// CPictureDlg 대화 상자

class CPictureDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPictureDlg)

public:
	CPictureDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CPictureDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PICTURE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedPpictureTemp1();
	CBitmap m_bmpPicture;
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	int m_selectedPictureRadio;
	afx_msg void OnBnClickedRadioPictureFail2();
	afx_msg void OnClickedRadioSuccess();
	afx_msg void OnClickedRadioFail1();
	afx_msg void OnClickedRadioFail2();
	afx_msg void OnClickedButtonSubmit();
};
