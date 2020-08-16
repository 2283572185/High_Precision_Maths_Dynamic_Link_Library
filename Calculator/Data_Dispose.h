#pragma once


// Data_Dispose 对话框

class Data_Dispose : public CDialogEx
{
	DECLARE_DYNAMIC(Data_Dispose)

public:
	Data_Dispose(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Data_Dispose();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
