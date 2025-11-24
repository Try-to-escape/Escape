
// EscapeDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Escape.h"
#include "EscapeDlg.h"
#include "afxdialogex.h"
/*
#include "CBookListDlg.h"
#include "CLightDlg.h"
#include "CLockerDlg.h"
#include "CPictureDlg.h"
*/

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange *pDX);    // DDX/DDV 지원입니다.

	// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange *pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CEscapeDlg 대화 상자



CEscapeDlg::CEscapeDlg(CWnd *pParent /*=nullptr*/)
	: CDialogEx(IDD_ESCAPE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEscapeDlg::DoDataExchange(CDataExchange *pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_BOOKLIST, m_boollist);
}

BEGIN_MESSAGE_MAP(CEscapeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_BN_CLICKED(IDC_BUTTON_BOOKLIST, &CEscapeDlg::OnBnClickedButtonBooklist)
	//ON_BN_CLICKED(IDC_BUTTON_PICTURE, &CEscapeDlg::OnBnClickedButtonPicture)
	//ON_BN_CLICKED(IDC_BUTTON_LOCKER, &CEscapeDlg::OnBnClickedButtonLocker)
	//ON_BN_CLICKED(IDC_BUTTON_STAND, &CEscapeDlg::OnBnClickedButtonStand)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_HIDE, &CEscapeDlg::OnBnClickedHide)
	ON_BN_CLICKED(IDC_OUT, &CEscapeDlg::OnBnClickedOut)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CEscapeDlg 메시지 처리기

BOOL CEscapeDlg::OnInitDialog()
{
	CPictureDlg dlg;
	dlg.DoModal();

	CDialogEx::OnInitDialog();

	m_fontTimer.CreatePointFont(200, L"굴림");

	GetDlgItem(IDC_STATIC_TIMER)->SetFont(&m_fontTimer);
	SetTimer(1, 1000, NULL);

	CMenu *pSysMenu = GetSystemMenu(FALSE);
	if ( pSysMenu != nullptr )
	if (!m_bmpBackground.LoadBitmap(IDB_BACKGROUND))
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if ( !strAboutMenu.IsEmpty() )
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
		TRACE(_T("ERROR: Background bitmap (IDB_BACKGROUND) load failed!\n"));
	}
	if (IsIconic())
	{
		CPaintDC dc(this);

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);

		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
		return true;
	}

	// 여기부터 배경 비트맵 그리기
	CPaintDC dc(this);

	BITMAP bitmap;
	m_bmpBackground.GetBitmap(&bitmap);

	CDC memDC;
	memDC.CreateCompatibleDC(&dc);
	CBitmap* pOldBitmap = memDC.SelectObject(&m_bmpBackground);

	CRect rect;
	GetClientRect(&rect);

	dc.StretchBlt(0, 0, rect.Width(), rect.Height(),
		&memDC, 0, 0, bitmap.bmWidth, bitmap.bmHeight,
		SRCCOPY);

	memDC.SelectObject(pOldBitmap);
}

void CEscapeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ( (nID & 0xFFF0) == IDM_ABOUTBOX )
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CEscapeDlg::OnPaint()
{
	if ( IsIconic() )
	{
		CPaintDC dc(this);

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);

		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
		return;
	}

	// 배경 그리기
	CPaintDC dc(this);

	if (m_bmpBackground.GetSafeHandle() == NULL)
		return;

	BITMAP bitmap;
	m_bmpBackground.GetBitmap(&bitmap);

	CDC memDC;
	memDC.CreateCompatibleDC(&dc);
	CBitmap* pOldBitmap = memDC.SelectObject(&m_bmpBackground);

	CRect rect;
	GetClientRect(&rect);

	dc.StretchBlt(
		0, 0, rect.Width(), rect.Height(),
		&memDC, 0, 0,
		bitmap.bmWidth, bitmap.bmHeight,
		SRCCOPY
	);

	memDC.SelectObject(pOldBitmap);
}
// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CEscapeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/*
void CEscapeDlg::OnBnClickedButtonBooklist()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CBookListDlg dlg;
	dlg.DoModal();
}

void CEscapeDlg::OnBnClickedButtonPicture()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CPictureDlg dlg;
	dlg.DoModal();
}

void CEscapeDlg::OnBnClickedButtonLocker()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CLockerDlg dlg;
	dlg.DoModal();
}

void CEscapeDlg::OnBnClickedButtonStand()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CLightDlg dlg;
	dlg.DoModal();
}
*/

void CEscapeDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	/*
	CString msg;
	msg.Format(_T("X: %d, Y: %d"), point.x, point.y);

	SetDlgItemText(IDC_STATIC1, msg);
	CDialogEx::OnMouseMove(nFlags, point);*/
}

void CEscapeDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CRect bookList(0, 0, 755, 405);
	CRect laptop(114, 493, 605, 776);      // 노트북
	CRect light(783, 417, 971, 793);       // 전등
	CRect safe(654, 1058, 910, 1205);      // 금고
	CRect frame(1445, 39, 1762, 406);      // 액자



	if (bookList.PtInRect(point))
	{

		MessageBox(L"책장");

		// 여기부터 다이얼로그 띄우는 코드 (주석 처리)
		/*
		CBookListDlg dlg;
		dlg.DoModal();
		*/
	}
	else if (laptop.PtInRect(point))
	{
		MessageBox(L"노트북");
	}
	else if (light.PtInRect(point))
	{
		MessageBox(L"전등");
	}
	else if (safe.PtInRect(point))
	{
		MessageBox(L"금고");
	}
	else if (frame.PtInRect(point))
	{
		MessageBox(L"액자");
	}


	CDialogEx::OnLButtonDown(nFlags, point);
}

void CEscapeDlg::OnBnClickedHide()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_bmpBackground.DeleteObject();

	if (!m_bmpBackground.LoadBitmap(IDB_HIDE))
	{
		MessageBox(L"IDB_HIDE 비트맵 로드 실패!");
		return;
	}

	Invalidate(FALSE);

}

void CEscapeDlg::OnBnClickedOut()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_bmpBackground.DeleteObject();

	if (!m_bmpBackground.LoadBitmap(IDB_BACKGROUND))
	{
		MessageBox(L"IDB_HIDE 비트맵 로드 실패!");
		return;
	}

	Invalidate(FALSE);
}

void CEscapeDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	if (nIDEvent == 1)
	{
		m_seconds++;

		int minutes = m_seconds / 60;
		int seconds = m_seconds % 60;

		CString text;
		text.Format(L"%02d:%02d", minutes, seconds);

		SetDlgItemText(IDC_STATIC_TIMER, text);
	}

	CDialogEx::OnTimer(nIDEvent);
}
