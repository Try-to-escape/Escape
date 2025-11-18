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

	m_strPassword = _T("");
}

CLockerDlg::~CLockerDlg()
{
}

void CLockerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT_INPUT, m_strEditInput);
	DDX_Control(pDX, 101, m_btn1);
	DDX_Control(pDX, 102, m_btn2);
	DDX_Control(pDX, 103, m_btn3);
	DDX_Control(pDX, 104, m_btn4);
	DDX_Control(pDX, 105, m_btn5);
	DDX_Control(pDX, 106, m_btn6);
	DDX_Control(pDX, 107, m_btn7);
	DDX_Control(pDX, 108, m_btn8);
	DDX_Control(pDX, 109, m_btn9);
	DDX_Control(pDX, IDC_EDIT_INPUT, m_editInput);
	DDX_Control(pDX, IDC_BUTTON_OK, n_btnOk);
}


BEGIN_MESSAGE_MAP(CLockerDlg, CDialogEx)
	ON_WM_PAINT()
	ON_COMMAND_RANGE(101, 109, &CLockerDlg::OnBnClickedButton)
//	ON_WM_TIMER()
ON_BN_CLICKED(IDC_BUTTON1, &CLockerDlg::OnBnClickedButton1)
END_MESSAGE_MAP()



//초기화
BOOL CLockerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//1. 이미지들 불러오기
	m_imgLocker.Load(L"res/image/locker.bmp");	//기본 금고 닫힘
	m_imgLockerOpen.Load(L"res/image/lockerOpen.bmp"); //금고 열림
	m_imgTestPaper.Load(L"res/image/EscapeEnding1.bmp"); //시험지

	//2. 초기 화면 설정(닫힌 금고)
	m_pCurrentImage = &m_imgLocker;
	Invalidate();

	//3. 암호 정답 설정
	m_strPassword = "1234";

	return TRUE;
	
}

//화면 출력
void CLockerDlg::OnPaint()
{
	CPaintDC dc(this);

	//금고 이미지 출력
	if (m_pCurrentImage && !m_pCurrentImage->IsNull())
	{
		m_pCurrentImage->Draw(dc, 0, 0);
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

	// Edit Box 값에 버튼 클릭값 추가
	CString strInput;
	m_editInput.GetWindowText(strInput);
	strInput += strBtnText;
	m_editInput.SetWindowText(strInput);

	// 4자리 입력 시 동작
	if (strInput.GetLength() == 4)
	{
		//1. 비밀번호 일치시->성공화면
		if (strInput == m_strPassword) {

			// 1) 컨트롤들 제거
			m_editInput.ShowWindow(SW_HIDE);
			m_btn1.ShowWindow(SW_HIDE);
			m_btn2.ShowWindow(SW_HIDE);
			m_btn3.ShowWindow(SW_HIDE);
			m_btn4.ShowWindow(SW_HIDE);
			m_btn5.ShowWindow(SW_HIDE);
			m_btn6.ShowWindow(SW_HIDE);
			m_btn7.ShowWindow(SW_HIDE);
			m_btn8.ShowWindow(SW_HIDE);
			m_btn9.ShowWindow(SW_HIDE);
			// 2) 열린 금고 화면
			m_pCurrentImage = &m_imgLockerOpen;
			Invalidate();
			n_btnOk.ShowWindow(SW_SHOW);
			// 3) 시험지 확대 화면, 확인 버튼(클릭시 대화상자 닫힘)
		}
		//2. 비밀번호 불일치시->실패화면(금고 경보-> 다시하기 대화상자)
		else {
			m_pCurrentImage = &m_imgLockerAlert;
			Invalidate();
		}

		m_editInput.SetWindowText(_T(""));
		strInput.Empty();
		UpdateData(FALSE);

	}
}

void CLockerDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
