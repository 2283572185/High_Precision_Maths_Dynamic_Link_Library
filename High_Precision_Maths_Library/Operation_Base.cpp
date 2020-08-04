#include "Operation_Base.h"
/// <summary>
/// 开方多线程函数1，计算a ^ (n - 1)
/// </summary>
void Extraction_theard_1(Operand_Base* a, unsigned long long n, Operand_Base* result);

/// <summary>
/// 开方多线程函数2，计算a * (n - 1)
/// </summary>
void Extraction_theard_2(Operand_Base* a, unsigned long long n, Operand_Base* result);

/// <summary>
/// 多线程乘法
/// </summary>
/// <param name="a">完整的乘数</param>
/// <param name="value">乘数的一部分</param>
/// <param name="n">单位高精度乘法调用的次数</param>
/// <param name="result">储存每一次乘法</param>
/// <param name="m">第一次乘法补充0的个数</param>
void High_Precision_Maths_Library::Multiplication_thread(Operand_Base* a, Value<char>* value, unsigned long long n, Operand_Base** result, unsigned long long m);

//除法精度预设
unsigned long long Division_Precision = 15;
//开方精度预设
unsigned long long Extraction_Of_Root_Precision = 15;
//开方迭代次数
unsigned long long Extraction_Of_Root_Time = 7;
constexpr auto _10 = ':';
using namespace High_Precision_Maths_Library;

inline void High_Precision_Maths_Library::position_point(Operand_Base& value)
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

inline void High_Precision_Maths_Library::high_precision_addition(char& left, char& right, Result& _result)
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

inline void High_Precision_Maths_Library::decimal_point(Operand_Base& left, Operand_Base& right)
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
		high_precision_addition(left.data[max - 1], right.data[max - 1], _result);
		result.data.insert(result.data.begin(), _result.result);
		max--;
	}
	result.data.pop();
	if (_result.change == '1') {
		result.data.insert(result.data.begin(), _result.change);
	}
	position_point(result);
	remain_significant_number(result);
	return result;
}

inline void High_Precision_Maths_Library::high_precision_multiplication(char& left, char& right, Result& _result)
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
	//分段乘法次数
	unsigned long long max;
	if (left.data.size() > right.data.size()) {
		max = left.data.size() - 1;
	}
	else
	{
		max = right.data.size() - 1;
	}
	//动态数组
	Operand_Base** ppresult = new Operand_Base*[max];
	//开辟储存空间
	for (unsigned long long i = 0; i < max; i++) {
		ppresult[i] = new Operand_Base;
	}
	//用于储存中间数据
	Operand_Base middle;
	Value<char>* left_max = left.data.begin();
	Value<char>* right_max = right.data.begin();
	Value<char>* left_do = left.data.end();
	Value<char>* right_do = right.data.end();
	Value<char>* begin = nullptr;
	char _0 = '0';
	//插入小数点
	begin = result.data.end();
	for (unsigned long long i = 0; i < rl_point - 1; i++) {
		begin = begin->last;
	}
	result.data.insert(begin, _point);
	position_point(result);
	remain_significant_number(result);
	return result;
}

inline void High_Precision_Maths_Library::remain_significant_number(Operand_Base& value)
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

inline void High_Precision_Maths_Library::high_precision_subtraction(char& left, char& right, Result& _result)
{
	//遇到小数点返回
	if (left == '.' || right == '.') {
		_result.result = '.';
		return;
	}
	left += 0x30;
	if (_result.change == '-') {
		left--;
	}
	if (left - right < '0') {
		_result.change = '-';
		_result.result = left + 10 - right;
	}
	else
	{
		_result.change = '0';
		_result.result = left - right;
	}
	return;
}

Operand_Base High_Precision_Maths_Library::Subtraction(Operand_Base& left, Operand_Base& right)
{
	position_point(left);
	position_point(right);
	decimal_point(left, right);
	Result _result;
	Operand_Base result;
	unsigned long long max = left.data.size();
	result.data.push_back((char&)_10);
	while (true)
	{
		if (max == 0) {
			break;
		}
		high_precision_subtraction(left.data[max - 1], right.data[max - 1], _result);
		result.data.insert(result.data.begin(), _result.result);
		max--;
	}
	result.data.pop();
	position_point(result);
	remain_significant_number(result);
	return result;
}

Operand_Base High_Precision_Maths_Library::Division(Operand_Base left, Operand_Base right)
{
	position_point(left);
	position_point(right);
	Operand_Base result;
	result.point = 0;
	char _point = '.';
	char _0 = '0';
	char i;
	//记录原除数的小数点位置
	unsigned long long point = right.point;
	unsigned long long n = 0;
	//将除数的整数位数扩大到和被除数的整数位数一样大
	while (true)
	{
		if (right.point >= left.point) {
			n = right.point - point;
			break;
		}
		else
		{
			right >>= 1;
		}
	}
	//算整数
	while (true)
	{
		if (n == 0) {
			//商
			i = '0';
			//不够减了，退出
			while (true) {
				if (left < right) {
					break;
				}
				else
				{
					left -= right;
					i++;
				}
			}
			//储存商
			result.data.push_back(i);
			break;
		}
		//商
		i = '0';
		//不够减了，退出
		while (true) {
			if (left < right) {
				break;
			}
			else
			{
				left -= right;
				i++;
			}
		}
		//储存商
		result.data.push_back(i);
		//除数缩小10倍
		right <<= 1;
		n--;
	}
	//补充小数点
	result.data.push_back(_point);
	Value<char>* v = result.data.begin();
	//去除无用的0
	while (true)
	{
		if (*v->value != '0') {
			break;
		}
		else
		{
			result.data.remove(v);
		}
	}
	result.point = result.data.size() - 1;
	//算小数
	while (true)
	{
		if (result.data.size() - 1 - result.point == Division_Precision + 1) {
			break;
		}
		//商
		i = '0';
		//余数扩大10倍
		left >>= 1;
		//不够减了，退出
		while (true) {
			if (left < right) {
				break;
			}
			else
			{
				left -= right;
				i++;
			}
		}
		result.data.push_back(i);
	}
	OperandStream_Base::change_precision(result, (Precision_Base&)Precision_Base(Division_Precision, round));
	return result;
}

Operand_Base High_Precision_Maths_Library::Extraction(Operand_Base left, unsigned long long n)
{
	if (n == 0) {
		Illegal_Data e("不存在0次方根。");
		throw(e);
	}
	else if (n == 1) {
		return left;
	}
	Operand_Base a('1');
	Operand_Base thread_1;
	Operand_Base thread_2;
	for (unsigned long long i = 0; i < Extraction_Of_Root_Time; i++) {
		thread first(Extraction_theard_1, &a, n, &thread_1);
		thread second(Extraction_theard_2, &a, n, &thread_2);
		first.join();
		second.join();
		a = (((left / thread_1) + thread_2)) / n;
	}
	remain_significant_number(a);
	OperandStream_Base os;
	os.change_precision(a, (Precision_Base&)Precision_Base(Extraction_Of_Root_Precision, round));
	return a;
}

Operand_Base High_Precision_Maths_Library::Remainder(Operand_Base left, Operand_Base right)
{
	position_point(left);
	position_point(right);
	//记录原除数的小数点位置
	unsigned long long point = right.point;
	//将除数的整数位数扩大到和被除数的整数位数一样大
	while (true)
	{
		if (right.point == left.point) {
			break;
		}
		else
		{
			right >>= 1;
		}
	}
	//取余数
	while (true)
	{
		if (right.point == point) {
			//不够减了，退出
			while (true) {
				if (left < right) {
					break;
				}
				else
				{
					left -= right;
				}
			}
			break;
		}
		//不够减了，退出
		while (true) {
			if (left < right) {
				break;
			}
			else
			{
				left -= right;
			}
		}
		//除数缩小10倍
		right <<= 1;
	}
	remain_significant_number(left);
	position_point(left);
	return left;
}

void High_Precision_Maths_Library::change_precision(int type, unsigned long long precision)
{
	if (type == division) {
		Division_Precision = precision;
	}
	else if (type == extraction_of_root) {
		Extraction_Of_Root_Precision = precision;
	}
	else if (type == extraction_of_root_time) {
		Extraction_Of_Root_Time = precision;
	}
	else
	{
		Illegal_Data e("所选用的类型超出了支持的范围。");
		throw(e);
	}
}

inline void Extraction_theard_1(Operand_Base* a, unsigned long long n, Operand_Base* result) {
	*result = (*a) ^ (n - 1);
	return;
}

inline void Extraction_theard_2(Operand_Base* a, unsigned long long n, Operand_Base* result) {
	*result = (*a) * (n - 1);
	return;
}

namespace High_Precision_Maths_Library {
	inline void Multiplication_thread(Operand_Base* a, Value<char>* value, unsigned long long n, Operand_Base** result, unsigned long long m) {
		Result _result;
		Value<char>* left_do = a->data.end();
		Value<char>* left_max = a->data.begin();
		Value<char>* begin;
		char _0 = '0';
		//循环乘法
		for (unsigned long long i = 0; i < n; i++) {
			//遇到小数点，算下一位
			if (*value->value == '.') {
				value = value->last;
				i++;
				continue;
			}
			//归零
			_result.change = '0';
			_result.result = '0';
			//最后加入一个0使迭代器可用
			result[m]->data.push_back(_0);
			while (true)
			{
				begin = result[m]->data.begin();
				//到达顶部，执行最后一次乘法
				if (left_do == left_max) {
					high_precision_multiplication(*left_do->value, *value->value, _result);
					result[m]->data.insert(begin, _result.result);
					break;
				}
				//遇到小数点，跳过
				if (*left_do->value == '.') {
					left_do = left_do->last;
					continue;
				}
				high_precision_multiplication(*left_do->value, *value->value, _result);
				result[m]->data.insert(begin, _result.result);
				left_do = left_do->last;
			}
			if (_result.change != '0') {
				result[m]->data.insert(begin, _result.change);
			}
			//弹出补上的0
			result[m]->data.pop();
			//插入0
			for (unsigned long long k = 0; k < m; k++) {
				result[m]->data.push_back(_0);
			}
			m++;
			left_do = a->data.end();
			//未到顶就上移
			if (value->last != nullptr) {
				value = value->last;
			}
		}
		return;
	}
}
