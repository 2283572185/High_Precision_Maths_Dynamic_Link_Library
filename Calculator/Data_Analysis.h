#pragma once
#include "Operand.h"
#include "CalculatorDlg.h"
// Win64
#ifdef _WIN64
// Debug
#ifdef DEBUG
#pragma comment(lib, "../x64/Debug/High_Precision_Maths_Library.lib")
// Release
#else
#pragma comment(lib, "../x64/Release/High_Precision_Maths_Library.lib")
#endif
// Win32
#else
// Debug
#ifdef DEBUG
#pragma comment(lib, "../Debug/High_Precision_Maths_Library.lib")
// Release
#else
#pragma comment(lib, "../Release/High_Precision_Maths_Library.lib")
#endif
#endif

/// <summary>
/// 判断表达式中括号的匹配是否合法
/// </summary>
/// <param name ="value">要判断的字符串的引用</param>
/// <returns>合法返回true，反之返回false</returns>
bool check_bracket(CString& value);

/// <summary>
/// 判断表达式中运算符的使用是否合法
/// </summary>
/// <param name ="value">要判断的字符串的引用</param>
/// <returns>合法返回true，反之返回false</returns>
bool check_operator(CString& value);