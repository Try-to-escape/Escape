// CHintDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Escape.h"
#include "afxdialogex.h"
#include "CHintDlg.h"


// CHintDlg 대화 상자

IMPLEMENT_DYNAMIC(CHintDlg, CDialogEx)

CHintDlg::CHintDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_HINT, pParent)
{

}

CHintDlg::~CHintDlg()
{
}

void CHintDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_OUT, m_btnOut);
}


BEGIN_MESSAGE_MAP(CHintDlg, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_OUT, &CHintDlg::OnBnClickedButtonOut)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CHintDlg 메시지 처리기

BOOL CHintDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//1. 이미지들 불러오기
	m_imgHint[0].Load(L"res/image/EscapeMainPageAttack.bmp");
	m_imgHint[1].Load(L"res/image/EscapeMainPageHide.bmp");
	m_imgHint[2].Load(L"res/image/EscapeMainPageHint.bmp");
	m_imgHintFail.Load(L"res/image/hintFail.bmp");

	//2. 초기 화면 설정
	m_nCurrentImageIndex = 0;
	m_pCurrentImage = &m_imgHint[m_nCurrentImageIndex];
	Invalidate();

	//3. 타이머 설정
	SetTimer(1, 50000, NULL);

	return TRUE;  
}

void CHintDlg::OnPaint()
{
	CPaintDC dc(this); 
	if (m_pCurrentImage && !m_pCurrentImage->IsNull())
	{
		m_pCurrentImage->Draw(dc, 0, 0);
	}
}

void CHintDlg::OnBnClickedButtonOut()
{
	if (m_nCurrentImageIndex >= 7) {
		AfxMessageBox(_T("교수님에게 들키지 않았다! 계속 힌트를 찾아보자!"), MB_OK | MB_ICONINFORMATION);
		EndDialog(IDOK);
	}
	else {
		KillTimer(1);
		AfxMessageBox(_T("교수님께 들켜버렸다!"), MB_OK | MB_ICONWARNING);
		m_btnOut.ShowWindow(SW_HIDE);
		m_pCurrentImage = &m_imgHintFail;
		Invalidate();
		//실패창 띄우기
	}
		
}

void CHintDlg::OnTimer(UINT_PTR nIDEvent)
{
	m_nCurrentImageIndex++;

	if (m_nCurrentImageIndex >= 7) {
		KillTimer(1);
		return;
	}
	

	m_pCurrentImage = &m_imgHint[m_nCurrentImageIndex];  

	Invalidate();


	CDialogEx::OnTimer(nIDEvent);
}
