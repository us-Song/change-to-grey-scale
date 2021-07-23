
// imageload34Dlg.h: 헤더 파일
//

#pragma once
#include "opencv2/opencv.hpp"

using namespace cv;

// Cimageload34Dlg 대화 상자
class Cimageload34Dlg : public CDialogEx
{
// 생성입니다.
public:
	Cimageload34Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	Mat InpImg, OutImg, TempImg;
	unsigned char** GrayImg;
	unsigned char** U, ** V;
	Mat img;
	Mat gray;
	Mat p_img;
	Mat p_gray;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IMAGELOAD34_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOpen();
	afx_msg void OnBnClickedChange();
};
