
// imageload34Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "imageload34.h"
#include "imageload34Dlg.h"
#include "afxdialogex.h"
#include<vector>
#include<string>
using namespace std;
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cimageload34Dlg 대화 상자



Cimageload34Dlg::Cimageload34Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_IMAGELOAD34_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cimageload34Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cimageload34Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPEN, &Cimageload34Dlg::OnBnClickedOpen)
	ON_BN_CLICKED(IDC_CHANGE, &Cimageload34Dlg::OnBnClickedChange)
END_MESSAGE_MAP()


// Cimageload34Dlg 메시지 처리기

BOOL Cimageload34Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void Cimageload34Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
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

void Cimageload34Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR Cimageload34Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cimageload34Dlg::OnBnClickedOpen()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Mat img = imread("Lenna.png"); //자신이 저장시킨 이미지 이름이 입력되어야 함, 확장자까지

	imshow("img", img);
	waitKey(0);
}


UINT Image(LPVOID pParam)
{
	Mat img;
	Mat gray;
	Mat p_img;
	Mat p_gray;
	String path(".\\ImgLog\\*.jpg");
	String path2(".\\test"); // 변경후 경로
	vector<String>str;

	int index = 0;
	char buf[256];
	glob(path, str, true);
	for (int cnt = 0; cnt < str.size(); cnt++)
	{
		p_img = imread(str[cnt]);
		cvtColor(p_img, p_gray, COLOR_BGR2GRAY);

		// Grayscale 처리된 이미지 저장
		sprintf(buf, ".\\test\\%d.jpg", index);
		int debug = 1;
		imwrite(buf, p_gray); // imwrite(저장할 경로 및 파일 이름, Mat 형식)
		index++; // 파일 이름의 인덱스 증가


		
	}
	//MessageBox(_T("완료"));
	return 0;
}

void Cimageload34Dlg::OnBnClickedChange()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	/*Mat color_img = imread("Lenna.png");
	Mat grayscale_img;

	cvtColor(color_img, grayscale_img, COLOR_BGR2GRAY);

	imshow("grayscale_img",grayscale_img);*/

	//String path(".\\test\\*.jpg"); 변경전 경로
	/*/String path(".\\ImgLog\\*.jpg");
	String path2(".\\test"); // 변경후 경로
	vector<String>str;

	int index = 0;
	char buf[256];
	glob(path, str, true);
	for (int cnt = 0; cnt < str.size(); cnt++)
	{
		p_img = imread(str[cnt]);
		cvtColor(p_img, p_gray, COLOR_BGR2GRAY);

		// Grayscale 처리된 이미지 저장
		sprintf(buf, ".\\test\\%d.jpg", index);
		int debug = 1;
		imwrite(buf, p_gray); // imwrite(저장할 경로 및 파일 이름, Mat 형식)
		index++; // 파일 이름의 인덱스 증가

		
		
	}*/
	int val = 1;
	AfxBeginThread(Image,(LPVOID)val);
	MessageBox(_T("완료"));
}
