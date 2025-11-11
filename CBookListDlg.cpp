// CBookListDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Escape.h"
#include "afxdialogex.h"
#include "CBookListDlg.h"


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
END_MESSAGE_MAP()


// CBookListDlg 메시지 처리기
