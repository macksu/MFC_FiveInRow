
// GoBangGameDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "GoBangGame.h"
#include "GoBangGameDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CGoBangGameDlg 对话框



CGoBangGameDlg::CGoBangGameDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GOBANGGAME_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGoBangGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGoBangGameDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CGoBangGameDlg 消息处理程序

BOOL CGoBangGameDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	WHOISPLAYER = BLACK;

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CGoBangGameDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CGoBangGameDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CClientDC dc(this);

		for (int i = 0; i < 16; i++) {
			dc.MoveTo(50, 50 + CellSize * i);
			dc.LineTo(50 + CellSize * Rows, 50 + CellSize * i);
		}
		for (int i = 0; i < 16; i++) {
			dc.MoveTo(50+ CellSize *i,50);
			dc.LineTo(50+ CellSize *i,50+ CellSize *Cols);
		}
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CGoBangGameDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGoBangGameDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CBrush fillbrush1(RGB(0, 0, 0));  //创建填充黑色画刷
	CBrush fillbrush2(RGB(255, 255, 255));  //创建填充白色画刷
	CBrush* poldbrush;
	CBrush* poldbrush1;
	int r = CellSize / 2;
	LastPoint = point;
	if (point.x<50 || point.x>(50 + Cols * CellSize) || point.y<50 || point.y>(50 + Cols * CellSize)) {
				
	}
	else {

		int _X = point.x - (point.x % 40);
		int _Y = point.y - (point.y % 40);
		if (_X % 40 > 20) {
			_X = _X + 20;
		}
		if (_Y % 40 > 20) {
			_Y = _Y + 20;
		}
		if (WHOISPLAYER == BLACK) {
			poldbrush = dc.SelectObject(&fillbrush1);
			dc.Ellipse(_X - r, _Y - r, _X + r, _Y + r);
			WHOISPLAYER = WHITE;
			dc.SelectObject(poldbrush);
		}
		else {
			poldbrush1 = dc.SelectObject(&fillbrush2);
			dc.Ellipse(_X - r, _Y - r, _X + r, _Y + r);
			WHOISPLAYER = BLACK;
			dc.SelectObject(poldbrush1);
		}
	}

	





	CDialogEx::OnLButtonDown(nFlags, point);
}
