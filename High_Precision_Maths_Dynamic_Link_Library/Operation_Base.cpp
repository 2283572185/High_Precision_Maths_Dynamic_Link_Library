#include "Operation_Base.h"
#define _10 ':'

void position_point(Operand_Base& value)
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
			value.data.push(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (value.point == max - 1 && value.data[value.point] != '.') {
			value.data.push(_point);
			value.data.push(_0);
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

void high_precision_add(char& left, char& right, Result& _result)
{
	//如果之前存在进位，在左操作数上加一
	if (_result.change == '1') {
		left++;
	}
	//如果两个操作数相加大于9，进位赋值1，结果为和减10
	if (left + right > '9') {
		_result.result = left + right - _10;
		_result.change = '1';
	}
	//反正，进位赋值0，结果为和
	else
	{
		_result.result = left + right;
		_result.change = '0';
	}
	return;
}

void decimal_point(Operand_Base& left, Operand_Base& right)
{
	//补充前导零
	char _0 = '0';
	unsigned long long i, need;
	if (left.point > right.point) {
		need = left.point - right.point;
		Value<char>* begin = right.data.begin();
		for (i = 0; i < need; i++) {
			right.data.insert(begin, _0);
		}
	}
	else
	{
		need = right.point - left.point;
		Value<char>* begin = left.data.begin();
		for (i = 0; i < need; i++) {
			left.data.insert(begin, _0);
		}
	}
	//补充后补零
	if (left.data.size() > right.data.size()) {
		need = left.data.size() - right.data.size();
		for (i = 0; i < need; i++) {
			right.data.push(_0);
		}
	}
	else
	{
		need = right.data.size() - left.data.size();
		for (i = 0; i < need; i++) {
			left.data.push(_0);
		}
	}
}
