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

	m_strPassword = _T("");
}

CLockerDlg::~CLockerDlg()
{
}

void CLockerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_INPUT, m_strEditInput);
}


BEGIN_MESSAGE_MAP(CLockerDlg, CDialogEx)
	ON_WM_PAINT()
	ON_COMMAND_RANGE(101, 109, &CLockerDlg::OnBnClickedButton)
END_MESSAGE_MAP()



//초기화
BOOL CLockerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//1. 금고 이미지 불러오기
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

	//2. 암호 정답 설정
	m_strPassword = "7456";

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

//암호 버튼 클릭시 
void CLockerDlg::OnBnClickedButton(UINT nID)
{
	// 버튼 컨트롤 가져오기
	CButton* pBtn = (CButton*)GetDlgItem(nID);
	if (!pBtn) return;

	// 버튼 텍스트 읽기
	CString strBtnText;
	pBtn->GetWindowText(strBtnText);

	// Edit Box 값에 누적
	UpdateData(TRUE);         
	m_strEditInput += strBtnText;
	UpdateData(FALSE);

	// 4자리 입력 시 동작
	if (m_strEditInput.GetLength() == 4)
	{
		//1. 비밀번호 일치시->성공화면
		if (m_strEditInput == m_strPassword)
			AfxMessageBox(_T("비밀번호 일치!"));
		//2. 비밀번호 불일치시->실패화면
		else
			AfxMessageBox(_T("비밀번호 틀림!"));

		m_strEditInput.Empty();
		UpdateData(FALSE);
	}
}
