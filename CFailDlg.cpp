// CFailDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Escape.h"
#include "afxdialogex.h"
#include "CFailDlg.h"


// CFailDlg 대화 상자

IMPLEMENT_DYNAMIC(CFailDlg, CDialogEx)

CFailDlg::CFailDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FAIL_DIALOG, pParent)
{

}

CFailDlg::~CFailDlg()
{
}

void CFailDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFailDlg, CDialogEx)
	ON_BN_CLICKED(IDC_RETRY_BUTTON, &CFailDlg::OnClickedRetryButton)
	ON_BN_CLICKED(IDC_EXIT_BUTTON, &CFailDlg::OnClickedExitButton)
END_MESSAGE_MAP()


// CFailDlg 메시지 처리기

void CFailDlg::OnClickedRetryButton()
{
	// 다시하기 버튼 : 다시하기를 누르면 처음 StartDlg로
	CWnd* pMain = AfxGetMainWnd();
	if (pMain && pMain != this) {
		pMain->PostMessageW(WM_CLOSE);
	}
	EndDialog(IDOK);
    CStartDlg startDlg;
	startDlg.DoModal();
}

void CFailDlg::OnClickedExitButton()
{
	// 종료 버튼 : F받기 누르면 프로그램 종료
	AfxGetMainWnd()->PostMessage(WM_CLOSE);
}
