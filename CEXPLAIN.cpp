// CEXPLAIN.cpp: 구현 파일
//

#include "pch.h"
#include "Escape.h"
#include "afxdialogex.h"
#include "CEXPLAIN.h"


// CEXPLAIN 대화 상자

IMPLEMENT_DYNAMIC(CExplainDlg, CDialogEx)

CExplainDlg::CExplainDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_EXPLAIN, pParent)
{

}

CExplainDlg::~CExplainDlg()
{
}

void CExplainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CExplainDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CEXPLAIN 메시지 처리기

BOOL CExplainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_bmpExplain.LoadBitmap(IDB_EXPLAIN);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CExplainDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.

    CDC memDC;
    memDC.CreateCompatibleDC(&dc);

    BITMAP bm;
    m_bmpExplain.GetBitmap(&bm);

    CBitmap* pOldBitmap = memDC.SelectObject(&m_bmpExplain);

    CRect rect;
    GetClientRect(&rect);

    dc.StretchBlt(
        0, 0,
        rect.Width(),
        rect.Height(),
        &memDC,
        0, 0,
        bm.bmWidth,
        bm.bmHeight,
        SRCCOPY
    );

    memDC.SelectObject(pOldBitmap);
}
