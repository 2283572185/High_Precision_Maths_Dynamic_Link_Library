// CalculatorDlg.cpp: 实现文件

#include "pch.h"
#include "framework.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"
#include "Data_Analysis.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CCalculatorDlg 对话框

CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, Value(_T(""))
	, History(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, Value);
	DDX_Text(pDX, IDC_EDIT3, History);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON7, &CCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CCalculatorDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CCalculatorDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CCalculatorDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CCalculatorDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CCalculatorDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CCalculatorDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CCalculatorDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &CCalculatorDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CCalculatorDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &CCalculatorDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &CCalculatorDlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON21, &CCalculatorDlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON22, &CCalculatorDlg::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON23, &CCalculatorDlg::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON24, &CCalculatorDlg::OnBnClickedButton24)
	ON_BN_CLICKED(IDC_BUTTON25, &CCalculatorDlg::OnBnClickedButton25)
END_MESSAGE_MAP()

// CCalculatorDlg 消息处理程序

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。 当应用程序主窗口不是对话框时，框架将自动 执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码 来绘制该图标。 对于使用文档/视图模型的 MFC 应用程序， 这将由框架自动完成。

void CCalculatorDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/// <summary>
/// 单击+按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton1()
{
	this->Value += '+';
	UpdateData(false);
	return;
}

/// <summary>
/// 单击-按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton2()
{
	this->Value += '-';
	UpdateData(false);
	return;
}

/// <summary>
/// 单击*按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton3()
{
	this->Value += '*';
	UpdateData(false);
	return;
}

/// <summary>
/// 单击/按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton4()
{
	this->Value += '/';
	UpdateData(false);
	return;
}

/// <summary>
/// 单击√按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton5()
{
	this->Value += "√";
	UpdateData(false);
	return;
}

/// <summary>
/// 单击^按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton7()
{
	this->Value += '^';
	UpdateData(false);
	return;
}

/// <summary>
/// 单击(按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton8()
{
	this->Value += '(';
	UpdateData(false);
	return;
}

/// <summary>
/// 单击)按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton9()
{
	this->Value += '(';
	UpdateData(false);
	return;
}

/// <summary>
/// 单击退格键
/// </summary>
void CCalculatorDlg::OnBnClickedButton10()
{
	if (this->remove_at_once) {
		// 清空所有已输入的字符
		this->Value = "";
		UpdateData(false);
		return;
	}
	else
	{
		// 删除最后一个输入的字符
		this->Value.Delete(this->Value.GetLength() - 1);
		UpdateData(false);
		return;
	}
}

/// <summary>
/// 单击清空输入按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton11()
{
	// 清空所有已输入的字符
	this->Value = "";
	UpdateData(false);
	return;
}

/// <summary>
/// 单击7按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton12()
{
	this->Value += '7';
	UpdateData(false);
	return;
}

/// <summary>
/// 单击8按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton13()
{
	this->Value += '8';
	UpdateData(false);
	return;
}

/// <summary>
/// 单击9按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton14()
{
	this->Value += '9';
	UpdateData(false);
	return;
}

/// <summary>
/// 单击4按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton15()
{
	this->Value += '4';
	UpdateData(false);
	return;
}

/// <summary>
/// 单击5按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton16()
{
	this->Value += '5';
	UpdateData(false);
	return;
}

/// <summary>
/// 单击6按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton17()
{
	this->Value += '6';
	UpdateData(false);
	return;
}

/// <summary>
/// 单击1按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton18()
{
	this->Value += '1';
	UpdateData(false);
	return;
}

/// <summary>
/// 单击2按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton19()
{
	this->Value += '2';
	UpdateData(false);
	return;
}

/// <summary>
/// 单击3按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton20()
{
	this->Value += '3';
	UpdateData(false);
	return;
}

/// <summary>
/// 单击-（负号）按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton21()
{
	this->Value += '-';
	UpdateData(false);
	return;
}

/// <summary>
/// 单击0按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton22()
{
	this->Value += '0';
	UpdateData(false);
	return;
}

/// <summary>
/// 单击.（小数点）按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton23()
{
	this->Value += '.';
	UpdateData(false);
	return;
}

/// <summary>
/// 单击=按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton24()
{
	// 先判断Value中的表达式是否合法
	//再计算得到值
	//写入输入栏，作为结果
	//写入历史记录
}

/// <summary>
/// 单击清空历史记录按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton25()
{
	//清空历史记录
	this->History = "";
	UpdateData(false);
	return;
}
