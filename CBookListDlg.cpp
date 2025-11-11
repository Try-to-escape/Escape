// CBookListDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Escape.h"
#include "afxdialogex.h"
#include "CBookListDlg.h"
#include "CBookDlg.h"

// CBookListDlg 대화 상자

IMPLEMENT_DYNAMIC(CBookListDlg, CDialogEx)

CBookListDlg::CBookListDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_BOOKLIST, pParent)
{

}

CBookListDlg::~CBookListDlg()
{
}

void CBookListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CBookListDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_WBOOK, &CBookListDlg::OnBnClickedButtonWbook)
	ON_BN_CLICKED(IDC_BUTTON_FBOOK, &CBookListDlg::OnBnClickedButtonFbook)
END_MESSAGE_MAP()


// CBookListDlg 메시지 처리기

void CBookListDlg::OnBnClickedButtonWbook()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    CBookDlg dlg;
    dlg.m_nBookType = 0;
    dlg.DoModal();
}

void CBookListDlg::OnBnClickedButtonFbook()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CBookDlg dlg;
	dlg.m_nBookType = 1;
	dlg.DoModal();
}
