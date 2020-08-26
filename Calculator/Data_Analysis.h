#pragma once
#include "Operand.h"
#include "CalculatorDlg.h"
#include <vector>
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

using namespace std;
/// <summary>
/// 判断小数点是否合法
/// </summary>
bool check_point(CString value);