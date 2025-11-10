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
	, m_strEditInput(_T(""))
{

}

CLockerDlg::~CLockerDlg()
{
}

void CLockerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_INPUT, m_strEditInput);
	DDX_Control(pDX, IDC_BUTTON_ONE, m_btnOne);
	DDX_Control(pDX, IDC_BUTTON_TWO, m_btnTwo);
	DDX_Control(pDX, IDC_BUTTON_THREE, m_btnThree);
	DDX_Control(pDX, IDC_BUTTON_FOUR, m_btnFour);
	DDX_Control(pDX, IDC_BUTTON_FIVE, m_btnFive);
	DDX_Control(pDX, IDC_BUTTON_SIX, m_btnSix);
	DDX_Control(pDX, IDC_BUTTON_SEVEN, m_btnSeven);
	DDX_Control(pDX, IDC_BUTTON_EIGHT, m_btnEight);
	DDX_Control(pDX, IDC_BUTTON_NINE, m_btnNine);
}


BEGIN_MESSAGE_MAP(CLockerDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()



//초기화
BOOL CLockerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_imgLocker.Load(L"res/locker.bmp");
	if (m_imgLocker)
	{
		// 이미지 크기 불러오기
		int imgWidth = m_imgLocker.GetWidth();
		int imgHeight = m_imgLocker.GetHeight();

		// 현재 윈도우 크기와 클라이언트 영역 크기 가져오기
		CRect rcWnd, rcClient;
		GetWindowRect(&rcWnd);
		GetClientRect(&rcClient);

		int frameWidth = (rcWnd.Width() - rcClient.Width());
		int frameHeight = (rcWnd.Height() - rcClient.Height());

		// 이미지 크기에 맞춰 대화상자 크기 조정
		MoveWindow(rcWnd.left, rcWnd.top, imgWidth + frameWidth, imgHeight + frameHeight);
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
