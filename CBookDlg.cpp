// CBookDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Escape.h"
#include "afxdialogex.h"
#include "CBookDlg.h"


// CBookDlg 대화 상자

IMPLEMENT_DYNAMIC(CBookDlg, CDialogEx)

CBookDlg::CBookDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_BOOK, pParent)
	, m_nBookType(0)
{

}

CBookDlg::~CBookDlg()
{
}

void CBookDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CBookDlg, CDialogEx)
END_MESSAGE_MAP()


// CBookDlg 메시지 처리기

BOOL CBookDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_bmpImage.LoadBitmap(m_nBookType);

	CStatic* pStaticImage = (CStatic*)GetDlgItem(IDD_DIALOG_BOOK);

	if (pStaticImage)
	{
		pStaticImage->SetBitmap(m_bmpImage);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
