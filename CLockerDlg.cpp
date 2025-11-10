// CLockerDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Escape.h"
#include "afxdialogex.h"
#include "CLockerDlg.h"


// CLockerDlg 대화 상자

IMPLEMENT_DYNAMIC(CLockerDlg, CDialogEx)

CLockerDlg::CLockerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LockerDlg, pParent)
{

}

CLockerDlg::~CLockerDlg()
{
}

void CLockerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLockerDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()



//초기화
BOOL CLockerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	HRESULT hr = m_imgLocker.Load(L"res/locker.bmp");
	if (FAILED(hr))
	{
		CString msg;
		msg.Format(L"이미지 로드 실패! HRESULT=0x%08X", hr);
		AfxMessageBox(msg);
	}
	Invalidate();

	return TRUE;
	
}

//화면 출력
void CLockerDlg::OnPaint()
{
	CPaintDC dc(this);

	//금고 이미지 출력
	if (m_imgLocker) {
		m_imgLocker.Draw(dc, 0, 0);
	}

}
