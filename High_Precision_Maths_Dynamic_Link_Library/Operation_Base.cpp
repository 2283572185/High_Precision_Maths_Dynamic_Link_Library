#include "Operation_Base.h"
constexpr auto _10 = ':';
using namespace High_Precision_Maths_Library;
void High_Precision_Maths_Library::position_point(Operand_Base& value)
{
	char _point = '.';
	char _0 = '0';
	unsigned long long max = value.data.size();
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (value.point == 0 && value.data[value.point] == '.') {
			value.data.insert(value.data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (value.point == max - 1 && value.data[value.point] == '.') {
			value.data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (value.point == max - 1 && value.data[value.point] != '.') {
			value.data.push_back(_point);
			value.data.push_back(_0);
			value.point++;
			break;
		}
		//若碰到小数点，返回
		else if (value.data[value.point] == '.') {
			break;
		}
		else
		{
			value.point++;
		}
	}
	return;
}

void High_Precision_Maths_Library::high_precision_add(char& left, char& right, Result& _result)
{
	//如果是小数点，直接返回
	if (left == '.' || right == '.') {
		_result.result = '.';
		return;
	}
	//如果之前存在进位，在左操作数上加一
	if (_result.change == '1') {
		left++;
	}
	//如果两个操作数相加大于9，进位赋值1，结果为和减10
	if (left + right - '0' > '9') {
		_result.result = left + right - _10;
		_result.change = '1';
	}
	//反正，进位赋值0，结果为和
	else
	{
		_result.result = left + right - '0';
		_result.change = '0';
	}
	return;
}

void High_Precision_Maths_Library::decimal_point(Operand_Base& left, Operand_Base& right)
{
	//补充前导零
	char _0 = '0';
	unsigned long long i, need;
	if (left.point > right.point) {
		need = left.point - right.point;
		for (i = 0; i < need; i++) {
			right.data.insert(right.data.begin(), _0);
		}
		right.point += need;
	}
	else
	{
		need = right.point - left.point;
		for (i = 0; i < need; i++) {
			left.data.insert(left.data.begin(), _0);
		}
		left.point += need;
	}
	//补充后补零
	if (left.data.size() > right.data.size()) {
		need = left.data.size() - right.data.size();
		for (i = 0; i < need; i++) {
			right.data.push_back(_0);
		}
	}
	else
	{
		need = right.data.size() - left.data.size();
		for (i = 0; i < need; i++) {
			left.data.push_back(_0);
		}
	}
}

Operand_Base High_Precision_Maths_Library::Addition(Operand_Base& left, Operand_Base& right)
{
	position_point(left);
	position_point(right);
	decimal_point(left, right);
	unsigned long long max = left.data.size();
	Result _result;
	Operand_Base result;
	result.data.push_back((char&)_10);
	while (true)
	{
		if (max == 0) {
			break;
		}
		high_precision_add(left.data[max - 1], right.data[max - 1], _result);
		result.data.insert(result.data.begin(), _result.result);
		max--;
	}
	result.data.pop();
	if (_result.change == '1') {
		result.data.insert(result.data.begin(), _result.change);
	}
	position_point(result);
	return result;
}
