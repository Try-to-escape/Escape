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
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CFailDlg 메시지 처리기

BOOL CFailDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_bmpFailPicture.LoadBitmap(IDB_BITMAP_FAIL);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

BOOL CFailDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CDC dcMemory;
	dcMemory.CreateCompatibleDC(pDC);



	BITMAP bm;
	m_bmpFailPicture.GetBitmap(&bm);

	CBitmap* pOldBitmap = dcMemory.SelectObject(&m_bmpFailPicture);
	CRect rect;
	GetClientRect(&rect);

	pDC->StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMemory, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);
	dcMemory.SelectObject(pOldBitmap);

	return TRUE;


}


void CFailDlg::OnClickedRetryButton()
{
	// 다시하기 버튼 : 다시하기를 누르면 처음 StartDlg로
	CWnd* pMain = AfxGetMainWnd();
	if (pMain && pMain != this) {
		pMain->PostMessageW(WM_CLOSE);
	}
	EndDialog(IDOK);
	//CStartDlg startDlg;
	//startDlg.DoModal();
}

void CFailDlg::OnClickedExitButton()
{
	// 종료 버튼 : F받기 누르면 프로그램 종료
	::PostQuitMessage(0);
}
