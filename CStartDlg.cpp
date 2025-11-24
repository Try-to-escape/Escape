// CStartDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Escape.h"
#include "afxdialogex.h"
#include "CStartDlg.h"
#include "EscapeDlg.h"
#include "CEXPLAIN.h"

IMPLEMENT_DYNAMIC(CStartDlg, CDialogEx)

CStartDlg::CStartDlg(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_DIALOG_START, pParent)
{
}

CStartDlg::~CStartDlg()
{
}

void CStartDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CStartDlg, CDialogEx)
    ON_WM_PAINT()
    ON_WM_MOUSEMOVE()
    ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


BOOL CStartDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    m_bmpStart.LoadBitmap(IDB_START);

    return TRUE;
}

void CStartDlg::OnPaint()
{
    CPaintDC dc(this); // device context for painting
    // TODO: 여기에 메시지 처리기 코드를 추가합니다.
    // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.

 CDC memDC;
    memDC.CreateCompatibleDC(&dc);

    BITMAP bm;
    m_bmpStart.GetBitmap(&bm);

    CBitmap* pOldBitmap = memDC.SelectObject(&m_bmpStart);

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

void CStartDlg::OnMouseMove(UINT nFlags, CPoint point)
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    /*
    CString msg;
    msg.Format(_T("X: %d, Y: %d"), point.x, point.y);

    SetDlgItemText(IDC_STATIC, msg);
    CDialogEx::OnMouseMove(nFlags, point);*/
}

void CStartDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    CRect startbtn(498, 374, 1090, 514);
    CRect explainbtn(497, 548, 1089, 679);
    if (startbtn.PtInRect(point))
    {

        //MessageBox(L"책장");

        CEscapeDlg dlg;
        dlg.DoModal();
    }
    else if (explainbtn.PtInRect(point))
    {
        CExplainDlg dlg;
        dlg.DoModal();
    }
    CDialogEx::OnLButtonDown(nFlags, point);


}
