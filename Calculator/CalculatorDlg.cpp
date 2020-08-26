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
	ON_BN_CLICKED(IDC_BUTTON27, &CCalculatorDlg::OnBnClickedButton27)
	ON_BN_CLICKED(IDC_BUTTON26, &CCalculatorDlg::OnBnClickedButton26)
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
	if (!this->remove_at_once) {
		if (this->number == 2) {
			MessageBox(L"抱歉，暂不支持如此多的数据一起运算，请拆分数据");
			return;
		}
		if (!this->operation) {
			this->Value += '+';
			this->operation = true;
			this->number++;
		}
		else
		{
			// 删除最后一个输入的字符
			this->Value.Delete(this->Value.GetLength() - 1);
			this->Value += '+';
			this->number++;
		}
		UpdateData(false);
	}
	return;
}

/// <summary>
/// 单击-按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton2()
{
	if (!this->remove_at_once) {
		if (this->number == 2) {
			MessageBox(L"抱歉，暂不支持如此多的数据一起运算，请拆分数据");
			return;
		}
		if (!this->operation) {
			this->Value += '-';
			this->operation = true;
			this->number++;
		}
		else
		{
			// 删除最后一个输入的字符
			this->Value.Delete(this->Value.GetLength() - 1);
			this->Value += '-';
			this->number++;
		}
		UpdateData(false);
	}
	return;
}

/// <summary>
/// 单击*按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton3()
{
	if (!this->remove_at_once) {
		if (this->number == 2) {
			MessageBox(L"抱歉，暂不支持如此多的数据一起运算，请拆分数据");
			return;
		}
		if (!this->operation) {
			this->Value += L'×';
			this->operation = true;
			this->number++;
		}
		else
		{
			// 删除最后一个输入的字符
			this->Value.Delete(this->Value.GetLength() - 1);
			this->Value += L'×';
			this->number++;
		}
		UpdateData(false);
	}
	return;
}

/// <summary>
/// 单击/按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton4()
{
	if (!this->remove_at_once) {
		if (this->number == 2) {
			MessageBox(L"抱歉，暂不支持如此多的数据一起运算，请拆分数据");
			return;
		}
		if (!this->operation) {
			this->Value += L'÷';
			this->operation = true;
			this->number++;
		}
		else
		{
			// 删除最后一个输入的字符
			this->Value.Delete(this->Value.GetLength() - 1);
			this->Value += L'÷';
			this->number++;
		}
		UpdateData(false);
	}
	return;
}

/// <summary>
/// 单击√按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton5()
{
	if (!this->remove_at_once) {
		if (this->number == 2) {
			MessageBox(L"抱歉，暂不支持如此多的数据一起运算，请拆分数据");
			return;
		}
		if (!this->operation) {
			this->Value += L'√';
			this->operation = true;
			this->number++;
		}
		else
		{
			// 删除最后一个输入的字符
			this->Value.Delete(this->Value.GetLength() - 1);
			this->Value += L'√';
			this->number++;
		}
		UpdateData(false);
	}
	return;
}

/// <summary>
/// 单击^按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton7()
{
	if (!this->remove_at_once) {
		if (this->number == 1) {
			MessageBox(L"抱歉，暂不支持如此多的数据一起运算，请拆分数据");
			return;
		}
		if (!this->operation) {
			this->Value += '^';
			this->operation = true;
			this->number++;
		}
		else
		{
			// 删除最后一个输入的字符
			this->Value.Delete(this->Value.GetLength() - 1);
			this->Value += '^';
			this->number++;
		}
		UpdateData(false);
	}
	return;
}

/// <summary>
/// 单击退格键
/// </summary>
void CCalculatorDlg::OnBnClickedButton10()
{
	if (this->remove_at_once) {
		this->Value = "0";
		this->remove_at_once = false;
		this->operation = false;
		this->number = 0;
	}
	// 如果最后一个字符是运算符，重置状态
	if (this->Value[this->Value.GetLength() - 1] < '0' || this->Value[this->Value.GetLength() - 1]>'9') {
		this->operation = false;
		this->number--;
	}
	// 删除最后一个输入的字符
	this->Value.Delete(this->Value.GetLength() - 1);
	// 如果数据是空的，在最后插入0
	if (this->Value.GetLength() == 0) {
		this->Value = "0";
	}
	UpdateData(false);
	return;
}

/// <summary>
/// 单击清空输入按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton11()
{
	// 清空所有已输入的字符
	this->Value = "0";
	this->operation = false;
	this->remove_at_once = false;
	this->number = 0;
	UpdateData(false);
	return;
}

/// <summary>
/// 单击7按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton12()
{
	if (!this->remove_at_once) {
		// 如果数据中只有一个0，用此字符替代0
		if (this->Value.GetLength() == 1 && this->Value[0] == '0') {
			this->Value = L"7";
		}
		else
		{
			this->Value += '7';
		}
		UpdateData(false);
	}
	return;
}

/// <summary>
/// 单击8按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton13()
{
	if (!this->remove_at_once) {
		// 如果数据中只有一个0，用此字符替代0
		if (this->Value.GetLength() == 1 && this->Value[0] == '0') {
			this->Value = L"8";
		}
		else
		{
			this->Value += '8';
		}
	}
	return;
}

/// <summary>
/// 单击9按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton14()
{
	if (!this->remove_at_once) {
		// 如果数据中只有一个0，用此字符替代0
		if (this->Value.GetLength() == 1 && this->Value[0] == '0') {
			this->Value = L"9";
		}
		else
		{
			this->Value += '9';
		}
	}
	return;
}

/// <summary>
/// 单击4按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton15()
{
	if (!this->remove_at_once) {
		// 如果数据中只有一个0，用此字符替代0
		if (this->Value.GetLength() == 1 && this->Value[0] == '0') {
			this->Value = L"4";
		}
		else
		{
			this->Value += '4';
		}
	}
	return;
}

/// <summary>
/// 单击5按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton16()
{
	if (!this->remove_at_once) {
		// 如果数据中只有一个0，用此字符替代0
		if (this->Value.GetLength() == 1 && this->Value[0] == '0') {
			this->Value = L"5";
		}
		else
		{
			this->Value += '5';
		}
	}
	return;
}

/// <summary>
/// 单击6按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton17()
{
	if (!this->remove_at_once) {
		// 如果数据中只有一个0，用此字符替代0
		if (this->Value.GetLength() == 1 && this->Value[0] == '0') {
			this->Value = L"6";
		}
		else
		{
			this->Value += '6';
		}
	}
	return;
}

/// <summary>
/// 单击1按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton18()
{
	if (!this->remove_at_once) {
		// 如果数据中只有一个0，用此字符替代0
		if (this->Value.GetLength() == 1 && this->Value[0] == '0') {
			this->Value = L"1";
		}
		else
		{
			this->Value += '1';
		}
	}
	return;
}

/// <summary>
/// 单击2按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton19()
{
	if (!this->remove_at_once) {
		// 如果数据中只有一个0，用此字符替代0
		if (this->Value.GetLength() == 1 && this->Value[0] == '0') {
			this->Value = L"2";
		}
		else
		{
			this->Value += '2';
		}
	}
	return;
}

/// <summary>
/// 单击3按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton20()
{
	if (!this->remove_at_once) {
		// 如果数据中只有一个0，用此字符替代0
		if (this->Value.GetLength() == 1 && this->Value[0] == '0') {
			this->Value = L"3";
		}
		else
		{
			this->Value += '3';
		}
	}
	return;
}

/// <summary>
/// 单击-（负号）按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton21()
{
	if (!this->remove_at_once) {
		if (this->number == 2) {
			MessageBox(L"抱歉，暂不支持如此多的数据一起运算，请拆分数据");
			return;
		}
		if (!this->operation) {
			this->Value += '+';
			this->operation = true;
			this->number++;
		}
		else
		{
			// 删除最后一个输入的字符
			this->Value.Delete(this->Value.GetLength() - 1);
			this->Value += '+';
			this->number++;
		}
		UpdateData(false);
	}
	return;
}

/// <summary>
/// 单击0按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton22()
{
	if (!this->remove_at_once) {
		// 如果数据中只有一个0，用此字符替代0
		if (this->Value.GetLength() == 1 && this->Value[0] == '0') {
			this->Value = L"0";
		}
		else
		{
			this->Value += '0';
		}
	}
	return;
}

/// <summary>
/// 单击.（小数点）按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton23()
{
	if (!this->remove_at_once) {
		this->Value += '.';
		UpdateData(false);
	}
	return;
}

/// <summary>
/// 单击=按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton24()
{
	// 先判断合法性
	if (this->left_bracket != this->right_bracket) {
		this->Value = L"输入的表达式不合法，请重新输入";
		this->remove_at_once = true;
	}

}

/// <summary>
/// 单击清空历史记录按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton25()
{
	//清空历史记录
	this->History = "";
	UpdateData(false);
	remove("History.log");
	ofstream os;
	os.open("History.log");
	os.close();
	return;
}

BOOL CCalculatorDlg::PreTranslateMessage(MSG* pMsg) {
	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
			// 小键盘输入0~9
		case VK_NUMPAD0:
			if (GetKeyState(VK_NUMPAD0) < 0)
				this->OnBnClickedButton22();
			break;
		case VK_NUMPAD1:
			if (GetKeyState(VK_NUMPAD1) < 0)
				this->OnBnClickedButton18();
			break;
		case VK_NUMPAD2:
			if (GetKeyState(VK_NUMPAD2) < 0)
				this->OnBnClickedButton19();
			break;
		case VK_NUMPAD3:
			if (GetKeyState(VK_NUMPAD3) < 0)
				this->OnBnClickedButton20();
			break;
		case VK_NUMPAD4:
			if (GetKeyState(VK_NUMPAD4) < 0)
				this->OnBnClickedButton15();
			break;
		case VK_NUMPAD5:
			if (GetKeyState(VK_NUMPAD5) < 0)
				this->OnBnClickedButton16();
			break;
		case VK_NUMPAD6:
			if (GetKeyState(VK_NUMPAD6) < 0)
				this->OnBnClickedButton17();
			break;
		case VK_NUMPAD7:
			if (GetKeyState(VK_NUMPAD7) < 0)
				this->OnBnClickedButton12();
			break;

		case VK_NUMPAD8:
			if (GetKeyState(VK_NUMPAD8) < 0)
				this->OnBnClickedButton13();
			break;

		case VK_NUMPAD9:
			if (GetKeyState(VK_NUMPAD9) < 0)
				this->OnBnClickedButton14();
			break;
			// 小数点键
		case VK_DECIMAL:
			if (GetKeyState(VK_DECIMAL) < 0)
				this->OnBnClickedButton23();
			break;
			// 等于键
		case VK_OEM_PLUS:
			// 未按shift输入=
			if (GetKeyState(VK_SHIFT) >= 0)
				this->OnBnClickedButton24();
			// 按shift输入+
			else
				this->OnBnClickedButton1();
			break;
			// 数字键输入0~9
		case 0x30:
			// 未按shift输入0
			if (GetKeyState(VK_SHIFT) >= 0)
				this->OnBnClickedButton22();
			// 按住输入)
			else
				this->OnBnClickedButton26();
			break;
		case 0x31:
			if (GetKeyState(0x31) < 0)
				this->OnBnClickedButton18();
			break;
		case 0x32:
			if (GetKeyState(0x32) < 0)
				this->OnBnClickedButton19();
			break;
		case 0x33:
			if (GetKeyState(0x33) < 0)
				this->OnBnClickedButton20();
			break;
		case 0x34:
			if (GetKeyState(0x34) < 0)
				this->OnBnClickedButton15();
			break;
		case 0x35:
			if (GetKeyState(0x35) < 0)
				this->OnBnClickedButton16();
			break;
		case 0x36:
			// 未按shift输入6
			if (GetKeyState(VK_SHIFT) >= 0)
				this->OnBnClickedButton17();
			// 按shift输入^
			else
				this->OnBnClickedButton7();
			break;
		case 0x37:
			// 未按shift输入7
			if (GetKeyState(VK_SHIFT) >= 0)
				this->OnBnClickedButton12();
			// 按shift输入&
			else
				this->OnBnClickedButton5();
			break;
		case 0x38:
			// 未按shift输入8
			if (GetKeyState(VK_SHIFT) >= 0)
				this->OnBnClickedButton13();
			// 按shift输入*
			else
				this->OnBnClickedButton3();
			break;
		case 0x39:
			// 未按shift输入9
			if (GetKeyState(VK_SHIFT) >= 0)
				this->OnBnClickedButton14();
			// 按住输入(
			else
				this->OnBnClickedButton27();
			break;
			// 回车键
		case VK_RETURN:
			if (GetKeyState(VK_RETURN) < 0)
				this->OnBnClickedButton24();
			break;
			// 加
		case VK_ADD:
			if (GetKeyState(VK_ADD) < 0)
				this->OnBnClickedButton1();
			break;
			// 减
		case VK_SUBTRACT:
			if (GetKeyState(VK_SUBTRACT) < 0)
				this->OnBnClickedButton2();
			break;
			// 乘
		case VK_MULTIPLY:
			if (GetKeyState(VK_MULTIPLY) < 0)
				this->OnBnClickedButton3();
			break;
			// 除
		case VK_DIVIDE:
			if (GetKeyState(VK_DIVIDE) < 0)
				this->OnBnClickedButton4();
			break;
			// 退格键
		case VK_BACK:
			if (GetKeyState(VK_BACK) < 0)
				this->OnBnClickedButton10();
			break;
			// 清空输入
		case VK_DELETE:
			if (GetKeyState(VK_DELETE) < 0)
				this->OnBnClickedButton11();
			break;
			// 主键盘上的-
		case VK_OEM_MINUS:
			if (GetKeyState(VK_SHIFT) < 0)
				this->OnBnClickedButton2();
			break;
			// 主键盘上的/
		case VK_OEM_2:
			if (GetKeyState(VK_SHIFT) >= 0)
				this->OnBnClickedButton4();
			break;
			// 按VK_ESCAPE退出程序
		case VK_ESCAPE:
			exit(0);
			break;
		case 'H':
			MessageBox(L"特殊的热键：\n按esc以退出程序\n按Shift+&以输入√\n历史记录：\n所有的历史储存在History.log中",L"帮助", MB_ICONINFORMATION);
			break;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}

/// <summary>
/// 单击(按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton27()
{
	if (!this->left_bracket) {
		this->Value += '(';
		this->left_bracket = true;
		this->operation = false;
	}
	else {
		MessageBox(L"抱歉，只能出现一对括号");
	}
	UpdateData(false);
}

/// <summary>
/// 单击)按钮
/// </summary>
void CCalculatorDlg::OnBnClickedButton26()
{
	if (!this->right_bracket) {
		this->Value += ')';
		this->right_bracket = true;
		this->operation = false;
	}
	else {
		MessageBox(L"抱歉，只能出现一对括号");
	}
	UpdateData(false);
}
