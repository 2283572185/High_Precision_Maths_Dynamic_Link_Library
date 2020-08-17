#include "pch.h"
#include "Data_Analysis.h"

bool check_bracket(CString& value)
{
	int left = 0;
	int max = value.GetLength();
	//记录(的个数
	for (int i = 0; i < max; i++) {
		if (value[i] == '(') {
			left++;
		}
	}
	int right = 0;
	//记录)的个数
	for (int i = 0; i < max; i++) {
		if (value[i] == ')') {
			right++;
		}
	}
	if (left == right) {
		return true;
	}
	else
	{
		return false;
	}
}

bool check_operator(CString& value)
{
	/*判断是否合法的标准：
		+-/*^不能相互接触
		/*^运算符不能再开头
		除)外不能在结尾出现
		.前后必须有数字
		√前的数字不能是小数
	*/
	// 以不合法的运算符开头，返回false
	if (value[0] == '*' || value[0] == '/' || value[0] == '^' || value[0] == '.') {
		return false;
	}
	int max = value.GetLength();
	// 结尾字符不是)或数字，返回false
	if (value[max - 1] != ')' && value[max - 1] != '1' && value[max - 1] != '2' && value[max - 1] != '3'
		&& value[max - 1] != '4' && value[max - 1] != '5' && value[max - 1] != '6' && value[max - 1] != '7'
		&& value[max - 1] != '8' && value[max - 1] != '9' && value[max - 1] != '0') {
		return false;
	}
	// 判断运算符是否有不合法的接触
	for (int i = 0; i < max - 1; i++) {
		// 若出现敏感运算符，继续下面的判断
		if (value[i] == '+' || value[i] == '-' || value[i] == '*' || value[i] == '/' || value[i] == '^') {
			// 两个敏感运算符接触，返回false
			if (value[i + 1] == '+' || value[i + 1] == '-' || value[i + 1] == '*' || value[i + 1] == '/' || value[i + 1] == '^') {
				return false;
			}
		}
	}
	// 寻找.并判断.左右是否有数字
	for (int i = 1; i < max - 1; i++) {

	}
}
