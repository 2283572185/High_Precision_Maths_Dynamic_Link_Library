#include "Operation_Base.h"
constexpr auto _10 = ':';
using namespace High_Precision_Maths_Library;
void High_Precision_Maths_Library::position_point(Operand_Base& value)
{
	char _point = '.';
	char _0 = '0';
	unsigned long long max = value.data.size();
	value.point = 0;
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
	retain_significant_number(result);
	return result;
}

void High_Precision_Maths_Library::high_precision_multiplication(char& left, char& right, Result& _result)
{
	//如果是小数点，重置，直接返回
	if (left == '.' || right == '.') {
		_result.result = '0';
		_result.change = '0';
		return;
	}
	//原来的十位变成现在的个位
	_result.result = _result.change;
	_result.change = '0';
	//九九乘法口诀表
	switch (left)
	{
	case '0':
		_result.result += 0;
		break;
	case'1':
		_result.result += (right - '0');
		break;
	case'2':
		switch (right)
		{
		case'0':
			_result.result += 0;
			_result.change = '0';
			break;
		case'1':
			_result.result += 2;
			_result.change = '0';
			break;
		case'2':
			_result.result += 4;
			_result.change = '0';
			break;
		case'3':
			_result.result += 6;
			_result.change = '0';
			break;
		case'4':
			_result.result += 8;
			_result.change = '0';
			break;
		case'5':
			_result.result += 0;
			_result.change = '1';
			break;
		case'6':
			_result.result += 2;
			_result.change = '1';
			break;
		case'7':
			_result.result += 4;
			_result.change = '1';
			break;
		case'8':
			_result.result += 6;
			_result.change = '1';
			break;
		case'9':
			_result.result += 8;
			_result.change = '1';
			break;
		}
		break;
	case'3':
		switch (right)
		{
		case'0':
			_result.result += 0;
			_result.change = '0';
			break;
		case'1':
			_result.result += 3;
			_result.change = '0';
			break;
		case'2':
			_result.result += 6;
			_result.change = '0';
			break;
		case'3':
			_result.result += 9;
			_result.change = '0';
			break;
		case'4':
			_result.result += 2;
			_result.change = '1';
			break;
		case'5':
			_result.result += 5;
			_result.change = '1';
			break;
		case'6':
			_result.result += 8;
			_result.change = '1';
			break;
		case'7':
			_result.result += 1;
			_result.change = '2';
			break;
		case'8':
			_result.result += 4;
			_result.change = '2';
			break;
		case'9':
			_result.result += 7;
			_result.change = '2';
			break;
		}
		break;
	case'4':
		switch (right)
		{
		case'0':
			_result.result += 0;
			_result.change = '0';
			break;
		case'1':
			_result.result += 4;
			_result.change = '0';
			break;
		case'2':
			_result.result += 8;
			_result.change = '0';
			break;
		case'3':
			_result.result += 2;
			_result.change = '1';
			break;
		case'4':
			_result.result += 6;
			_result.change = '1';
			break;
		case'5':
			_result.result += 0;
			_result.change = '2';
			break;
		case'6':
			_result.result += 4;
			_result.change = '2';
			break;
		case'7':
			_result.result += 8;
			_result.change = '2';
			break;
		case'8':
			_result.result += 2;
			_result.change = '3';
			break;
		case'9':
			_result.result += 6;
			_result.change = '3';
			break;
		}
		break;
	case'5':
		switch (right)
		{
		case'0':
			_result.result += 0;
			_result.change = '0';
			break;
		case'1':
			_result.result += 5;
			_result.change = '0';
			break;
		case'2':
			_result.result += 0;
			_result.change = '1';
			break;
		case'3':
			_result.result += 5;
			_result.change = '1';
			break;
		case'4':
			_result.result += 0;
			_result.change = '2';
			break;
		case'5':
			_result.result += 5;
			_result.change = '2';
			break;
		case'6':
			_result.result += 0;
			_result.change = '3';
			break;
		case'7':
			_result.result += 5;
			_result.change = '3';
			break;
		case'8':
			_result.result += 0;
			_result.change = '4';
			break;
		case'9':
			_result.result += 5;
			_result.change = '4';
			break;
		}
		break;
	case'6':
		switch (right)
		{
		case'0':
			_result.result += 0;
			_result.change = '0';
			break;
		case'1':
			_result.result += 6;
			_result.change = '0';
			break;
		case'2':
			_result.result += 2;
			_result.change = '1';
			break;
		case'3':
			_result.result += 8;
			_result.change = '1'; 
			break;
		case'4':
			_result.result += 4;
			_result.change = '2'; 
			break;
		case'5':
			_result.result += 0;
			_result.change = '3';
			break;
		case'6':
			_result.result += 6;
			_result.change = '3';
			break;
		case'7':
			_result.result += 2;
			_result.change = '4';
			break;
		case'8':
			_result.result += 8;
			_result.change = '4';
			break;
		case'9':
			_result.result += 4;
			_result.change = '5';
			break;
		}
		break;
	case'7':
		switch (right)
		{
		case'0':
			_result.result += 0;
			_result.change = '0';
			break;
		case'1':
			_result.result += 7;
			_result.change = '0';
			break;
		case'2':
			_result.result += 4;
			_result.change = '1';
			break;
		case'3':
			_result.result += 1;
			_result.change = '2';
			break;
		case'4':
			_result.result += 8;
			_result.change = '2';
			break;
		case'5':
			_result.result += 5;
			_result.change = '3';
			break;
		case'6':
			_result.result += 2;
			_result.change = '4';
			break;
		case'7':
			_result.result += 9;
			_result.change = '4';
			break;
		case'8':
			_result.result += 6;
			_result.change = '5';
			break;
		case'9':
			_result.result += 3;
			_result.change = '6';
			break;
		}
		break;
	case'8':
		switch (right)
		{
		case'0':
			_result.result += 0;
			_result.change = '0';
			break;
		case'1':
			_result.result += 8;
			_result.change = '0';
			break;
		case'2':
			_result.result += 6;
			_result.change = '1';
			break;
		case'3':
			_result.result += 4;
			_result.change = '2';
			break;
		case'4':
			_result.result += 2;
			_result.change = '3';
			break;
		case'5':
			_result.result += 0;
			_result.change = '4';
			break;
		case'6':
			_result.result += 8;
			_result.change = '4';
			break;
		case'7':
			_result.result += 6;
			_result.change = '5';
			break;
		case'8':
			_result.result += 4;
			_result.change = '6';
			break;
		case'9':
			_result.result += 2;
			_result.change = '7';
			break;
		}
		break;
	case'9':
		switch (right)
		{
		case'0':
			_result.result += 0;
			_result.change = '0';
			break;
		case'1':
			_result.result += 9;
			_result.change = '0';
			break;
		case'2':
			_result.result += 8;
			_result.change = '1';
			break;
		case'3':
			_result.result += 7;
			_result.change = '2';
			break;
		case'4':
			_result.result += 6;
			_result.change = '3';
			break;
		case'5':
			_result.result += 5;
			_result.change = '4';
			break;
		case'6':
			_result.result += 4;
			_result.change = '5';
			break;
		case'7':
			_result.result += 3;
			_result.change = '6';
			break;
		case'8':
			_result.result += 2;
			_result.change = '7';
			break;
		case'9':
			_result.result += 1;
			_result.change = '8';
			break;
		}
		break;
	}
	//若“个位”大于“10”，十位+1，个位-10
	if (_result.result > '9') {
		_result.result -= 10;
		_result.change += 1;
	}
	return;
}

Operand_Base High_Precision_Maths_Library::Multiplication(Operand_Base& left, Operand_Base& right)
{
	char _point = '.';
	position_point(left);
	position_point(right);
	decimal_point(left, right);
	unsigned long long need = 0;
	//小数点位置，从右往左数
	unsigned long long rl_point = (left.data.size() - 1 - left.point) + (right.data.size() - 1 - right.point);
	Result _result;
	Operand_Base result;
	//用于储存中间数据
	Operand_Base middle;
	Value<char>* left_max = left.data.begin();
	Value<char>* right_max = right.data.begin();
	Value<char>* left_do = left.data.end();
	Value<char>* right_do = right.data.end();
	Value<char>* begin = nullptr;
	char _0 = '0';
	while (true)
	{
		if (right_do == right_max) {
			middle.data.clear();
			middle.data.push_back((char&)_10);
			begin = middle.data.begin();
			_result.change = '0';
			_result.result = '0';
			while (true)
			{
				if (left_do == left_max) {
					high_precision_multiplication(*left_do->value, *right_do->value, _result);
					middle.data.insert(begin, _result.result);
					break;
				}
				if (*left_do->value == '.') {
					left_do = left_do->last;
				}
				high_precision_multiplication(*left_do->value, *right_do->value, _result);
				middle.data.insert(begin, _result.result);
				left_do = left_do->last;
			}
			if (_result.change != '0') {
				middle.data.insert(begin, _result.change);
			}
			middle.data.pop();
			for (unsigned long long i = 0; i < need; i++) {
				middle.data.push_back(_0);
			}
			if (need == 0) {
				result = middle;
			}
			else
			{
				result += middle;
				//弹出小数点和后补零
				result.data.pop();
				result.data.pop();
			}
			break;
		}
		if (*right_do->value == '.') {
			right_do = right_do->last;
			if (right_do == right_max) {
				middle.data.clear();
				middle.data.push_back((char&)_10);
				begin = middle.data.begin();
				_result.change = '0';
				_result.result = '0';
				while (true)
				{
					if (left_do == left_max) {
						high_precision_multiplication(*left_do->value, *right_do->value, _result);
						middle.data.insert(begin, _result.result);
						break;
					}
					if (*left_do->value == '.') {
						left_do = left_do->last;
						if (left_do == left_max) {
							high_precision_multiplication(*left_do->value, *right_do->value, _result);
							middle.data.insert(begin, _result.result);
							break;
						}
					}
					high_precision_multiplication(*left_do->value, *right_do->value, _result);
					middle.data.insert(begin, _result.result);
					left_do = left_do->last;
				}
				if (_result.change != '0') {
					middle.data.insert(begin, _result.change);
				}
				middle.data.pop();
				for (unsigned long long i = 0; i < need; i++) {
					middle.data.push_back(_0);
				}
				if (need == 0) {
					result = middle;
				}
				else
				{
					result += middle;
					//弹出小数点和后补零
					result.data.pop();
					result.data.pop();
				}
				break;
			}
		}
		middle.data.clear();
		middle.data.push_back((char&)_10);
		begin = middle.data.begin();
		_result.change = '0';
		_result.result = '0';
		while (true)
		{
			if (left_do == left_max) {
				high_precision_multiplication(*left_do->value, *right_do->value, _result);
				middle.data.insert(begin, _result.result);
				break;
			}
			if (*left_do->value == '.') {
				left_do = left_do->last;
				if (left_do == left_max) {
					high_precision_multiplication(*left_do->value, *right_do->value, _result);
					middle.data.insert(begin, _result.result);
					break;
				}
			}
			high_precision_multiplication(*left_do->value, *right_do->value, _result);
			middle.data.insert(begin, _result.result);
			left_do = left_do->last;
		}
		if (_result.change != '0') {
			middle.data.insert(begin, _result.change);
		}
		middle.data.pop();
		for (unsigned long long i = 0; i < need; i++) {
			middle.data.push_back(_0);
		}
		if (need == 0) {
			result = middle;
		}
		else
		{
			result += middle;
			//弹出小数点和后补零
			result.data.pop();
			result.data.pop();
		}
		need++;
		right_do = right_do->last;
		left_do = left.data.end();
	}
	//插入小数点
	begin = result.data.end();
	for (unsigned long long i = 0; i < rl_point - 1; i++) {
		begin = begin->last;
	}
	result.data.insert(begin, _point);
	position_point(result);
	retain_significant_number(result);
	return result;
}

void High_Precision_Maths_Library::retain_significant_number(Operand_Base& value)
{
	char _0 = '0';
	while (true)
	{
		if (*value.data.begin()->value == '0') {
			value.data.remove(value.data.begin());
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		if (value.data.top() == '0') {
			value.data.pop();
		}
		else
		{
			break;
		}
	}
	if (value.data.top() == '.') {
		value.data.push_back(_0);
		value.point = value.data.size() - 2;
	}
	if (value.data.bottom() == '.') {
		value.data.insert(value.data.begin(), _0);
		value.point = 1;
	}
	return;
}
