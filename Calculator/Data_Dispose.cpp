// Data_Dispose.cpp: 实现文件
//

#include "pch.h"
#include "Calculator.h"
#include "Data_Dispose.h"
#include "afxdialogex.h"


// Data_Dispose 对话框

IMPLEMENT_DYNAMIC(Data_Dispose, CDialogEx)

Data_Dispose::Data_Dispose(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
{

}

Data_Dispose::~Data_Dispose()
{
}

void Data_Dispose::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Data_Dispose, CDialogEx)
END_MESSAGE_MAP()


// Data_Dispose 消息处理程序
