// CPictureDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Escape.h"
#include "afxdialogex.h"
#include "CPictureDlg.h"
#include "CFailDlg.h"

// CPictureDlg 대화 상자

IMPLEMENT_DYNAMIC(CPictureDlg, CDialogEx)

CPictureDlg::CPictureDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PICTURE_DIALOG, pParent)
{

}

CPictureDlg::~CPictureDlg()
{
}

void CPictureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPictureDlg, CDialogEx)
	
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_RADIO_SUCCESS, &CPictureDlg::OnClickedRadioSuccess)
	ON_BN_CLICKED(IDC_RADIO_FAIL1, &CPictureDlg::OnClickedRadioFail1)
	ON_BN_CLICKED(IDC_RADIO_FAIL2, &CPictureDlg::OnClickedRadioFail2)
	ON_BN_CLICKED(IDC_BUTTON_SUBMIT, &CPictureDlg::OnClickedButtonSubmit)
END_MESSAGE_MAP()


// CPictureDlg 메시지 처리기

void CPictureDlg::OnStnClickedPpictureTemp1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

BOOL CPictureDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	m_bmpPicture.LoadBitmap(IDB_BITMAP_PICTURE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

BOOL CPictureDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDC dcMemory;
	dcMemory.CreateCompatibleDC(pDC);

	

	BITMAP bm;
	m_bmpPicture.GetBitmap(&bm);

	CBitmap* pOldBitmap = dcMemory.SelectObject(&m_bmpPicture);
	CRect rect;
	GetClientRect(&rect);

	pDC->StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMemory, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);
	dcMemory.SelectObject(pOldBitmap);

	return TRUE;
}

void CPictureDlg::OnClickedRadioSuccess()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selectedPictureRadio = 1;
}

void CPictureDlg::OnClickedRadioFail1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selectedPictureRadio = 2;
}

void CPictureDlg::OnClickedRadioFail2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_selectedPictureRadio = 3;
}

void CPictureDlg::OnClickedButtonSubmit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFailDlg failDlg;
	switch (m_selectedPictureRadio) {
	case 1:
		m_bmpPicture.DeleteObject();
		m_bmpPicture.LoadBitmap(IDB_BITMAP_PICTURE1);
		break;
	case 2:
		m_bmpPicture.DeleteObject();
		m_bmpPicture.LoadBitmap(IDB_BITMAP_PICTURE2);
		
		failDlg.DoModal();
		break;
	case 3:
		m_bmpPicture.DeleteObject();
		m_bmpPicture.LoadBitmap(IDB_BITMAP_PICTURE3);

		failDlg.DoModal();
		break;
	}

	Invalidate();

	((CButton*)GetDlgItem(IDC_RADIO_SUCCESS))->SetCheck(BST_UNCHECKED);
	((CButton*)GetDlgItem(IDC_RADIO_FAIL1))->SetCheck(BST_UNCHECKED);
	((CButton*)GetDlgItem(IDC_RADIO_FAIL2))->SetCheck(BST_UNCHECKED);

	// 선택값 초기화
	m_selectedPictureRadio = 0;
}
