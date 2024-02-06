
// GoBangGameDlg.h: 头文件
//
#define CellSize 40
#define Rows 15
#define Cols 15
#pragma once

enum player
{
	EMPTY,
	BLACK,
	WHITE
};
// CGoBangGameDlg 对话框
class CGoBangGameDlg : public CDialogEx
{
// 构造
public:
	CGoBangGameDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GOBANGGAME_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

	int  WHOISPLAYER;

private:
	CPoint LastPoint;
};
