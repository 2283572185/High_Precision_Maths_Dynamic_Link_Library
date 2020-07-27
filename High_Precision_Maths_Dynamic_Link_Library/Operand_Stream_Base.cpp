#include "Operand_Stream_Base.h"

High_Precision_Maths_Library::Precision_Base::Precision_Base(unsigned long long precision, int type)
{
	this->precision = precision;
	this->type = type;
	return;
}

High_Precision_Maths_Library::OperandStream_Base::OperandStream_Base()
{
	this->state = empty;
}

High_Precision_Maths_Library::OperandStream_Base::OperandStream_Base(const OperandStream_Base& value)
{
	this->data.copy((DDM< Operand_Base>&)value.data);
	this->state = value.state;
	return;
}

void High_Precision_Maths_Library::OperandStream_Base::operator<<(int value)
{
	if (this->state == empty) {
		Operand_Base o(value);
		this->data.push_back(o);
		this->state = fill;
	}
	else
	{
		Over_Flow e("流是满的，不能输入数据。");
		throw(e);
	}
	return;
}

void High_Precision_Maths_Library::OperandStream_Base::operator<<(short value)
{
	if (this->state == empty) {
		Operand_Base o(value);
		this->data.push_back(o);
		this->state = fill;
	}
	else
	{
		Over_Flow e("流是满的，不能输入数据。");
		throw(e);
	}
	return;
}

void High_Precision_Maths_Library::OperandStream_Base::operator<<(long value)
{
	if (this->state == empty) {
		Operand_Base o(value);
		this->data.push_back(o);
		this->state = fill;
	}
	else
	{
		Over_Flow e("流是满的，不能输入数据。");
		throw(e);
	}
	return;
}

void High_Precision_Maths_Library::OperandStream_Base::operator<<(long long value)
{
	if (this->state == empty) {
		Operand_Base o(value);
		this->data.push_back(o);
		this->state = fill;
	}
	else
	{
		Over_Flow e("流是满的，不能输入数据。");
		throw(e);
	}
	return;
}

void High_Precision_Maths_Library::OperandStream_Base::operator<<(unsigned int value)
{
	if (this->state == empty) {
		Operand_Base o(value);
		this->data.push_back(o);
		this->state = fill;
	}
	else
	{
		Over_Flow e("流是满的，不能输入数据。");
		throw(e);
	}
	return;
}

void High_Precision_Maths_Library::OperandStream_Base::operator<<(unsigned short value)
{
	if (this->state == empty) {
		Operand_Base o(value);
		this->data.push_back(o);
		this->state = fill;
	}
	else
	{
		Over_Flow e("流是满的，不能输入数据。");
		throw(e);
	}
	return;
}

void High_Precision_Maths_Library::OperandStream_Base::operator<<(unsigned long value)
{
	if (this->state == empty) {
		Operand_Base o(value);
		this->data.push_back(o);
		this->state = fill;
	}
	else
	{
		Over_Flow e("流是满的，不能输入数据。");
		throw(e);
	}
	return;
}

void High_Precision_Maths_Library::OperandStream_Base::operator<<(unsigned long long value)
{
	if (this->state == empty) {
		Operand_Base o(value);
		this->data.push_back(o);
		this->state = fill;
	}
	else
	{
		Over_Flow e("流是满的，不能输入数据。");
		throw(e);
	}
	return;
}

void High_Precision_Maths_Library::OperandStream_Base::operator<<(char value)
{
	if (this->state == empty) {
		Operand_Base o(value);
		this->data.push_back(o);
		this->state = fill;
	}
	else
	{
		Over_Flow e("流是满的，不能输入数据。");
		throw(e);
	}
	return;
}

void High_Precision_Maths_Library::OperandStream_Base::operator<<(string value)
{
	if (this->state == empty) {
		Operand_Base o(value);
		this->data.push_back(o);
		this->state = fill;
	}
	else
	{
		Over_Flow e("流是满的，不能输入数据。");
		throw(e);
	}
	return;
}

void High_Precision_Maths_Library::OperandStream_Base::operator<<(char* value)
{
	if (this->state == empty) {
		Operand_Base o(value);
		this->data.push_back(o);
		this->state = fill;
	}
	else
	{
		Over_Flow e("流是满的，不能输入数据。");
		throw(e);
	}
	return;
}

void High_Precision_Maths_Library::OperandStream_Base::operator<<(Operand_Base& value)
{
	if (this->state == empty) {
		this->data.push_back(value);
		this->state = fill;
	}
	else
	{
		Over_Flow e("流是满的，不能输入数据。");
		throw(e);
	}
	return;
}

void High_Precision_Maths_Library::OperandStream_Base::operator<<(float value)
{
	if (this->state == empty) {
		Operand_Base o(value);
		this->data.push_back(o);
		this->state = fill;
	}
	else
	{
		Over_Flow e("流是满的，不能输入数据。");
		throw(e);
	}
	return;
}

void High_Precision_Maths_Library::OperandStream_Base::operator<<(double value)
{
	if (this->state == empty) {
		Operand_Base o(value);
		this->data.push_back(o);
		this->state = fill;
	}
	else
	{
		Over_Flow e("流是满的，不能输入数据。");
		throw(e);
	}
	return;
}

void High_Precision_Maths_Library::OperandStream_Base::operator<<(long double value)
{
	if (this->state == empty) {
		Operand_Base o(value);
		this->data.push_back(o);
		this->state = fill;
	}
	else
	{
		Over_Flow e("流是满的，不能输入数据。");
		throw(e);
	}
	return;
}

int High_Precision_Maths_Library::OperandStream_Base::operator>>(int value)
{
	if (this->state == fill) {
		stringstream ss;
		ss << this->data.top().to_string();
		ss >> value;
		this->state = empty;
	}
	else
	{
		Under_Flow e("流是空的，不能输出数据。");
		throw(e);
	}
	return value;
}

short High_Precision_Maths_Library::OperandStream_Base::operator>>(short value)
{
	if (this->state == fill) {
		stringstream ss;
		ss << this->data.top().to_string();
		ss >> value;
		this->state = empty;
	}
	else
	{
		Under_Flow e("流是空的，不能输出数据。");
		throw(e);
	}
	return value;
}

long High_Precision_Maths_Library::OperandStream_Base::operator>>(long value)
{
	if (this->state == fill) {
		stringstream ss;
		ss << this->data.top().to_string();
		ss >> value;
		this->state = empty;
	}
	else
	{
		Under_Flow e("流是空的，不能输出数据。");
		throw(e);
	}
	return value;
}

long long High_Precision_Maths_Library::OperandStream_Base::operator>>(long long value)
{
	if (this->state == fill) {
		stringstream ss;
		ss << this->data.top().to_string();
		ss >> value;
		this->state = empty;
	}
	else
	{
		Under_Flow e("流是空的，不能输出数据。");
		throw(e);
	}
	return value;
}

unsigned int High_Precision_Maths_Library::OperandStream_Base::operator>>(unsigned int value)
{
	if (this->state == fill) {
		stringstream ss;
		ss << this->data.top().to_string();
		ss >> value;
		this->state = empty;
	}
	else
	{
		Under_Flow e("流是空的，不能输出数据。");
		throw(e);
	}
	return value;
}

unsigned short High_Precision_Maths_Library::OperandStream_Base::operator>>(unsigned short value)
{
	if (this->state == fill) {
		stringstream ss;
		ss << this->data.top().to_string();
		ss >> value;
		this->state = empty;
	}
	else
	{
		Under_Flow e("流是空的，不能输出数据。");
		throw(e);
	}
	return value;
}

unsigned long High_Precision_Maths_Library::OperandStream_Base::operator>>(unsigned long value)
{
	if (this->state == fill) {
		stringstream ss;
		ss << this->data.top().to_string();
		ss >> value;
		this->state = empty;
	}
	else
	{
		Under_Flow e("流是空的，不能输出数据。");
		throw(e);
	}
	return value;
}

unsigned long long High_Precision_Maths_Library::OperandStream_Base::operator>>(unsigned long long value)
{
	if (this->state == fill) {
		stringstream ss;
		ss << this->data.top().to_string();
		ss >> value;
		this->state = empty;
	}
	else
	{
		Under_Flow e("流是空的，不能输出数据。");
		throw(e);
	}
	return value;
}

char High_Precision_Maths_Library::OperandStream_Base::operator>>(char value)
{
	if (this->state == fill) {
		stringstream ss;
		ss << this->data.top().to_string();
		ss >> value;
		this->state = empty;
	}
	else
	{
		Under_Flow e("流是空的，不能输出数据。");
		throw(e);
	}
	return value;
}

string High_Precision_Maths_Library::OperandStream_Base::operator>>(string& value)
{
	if (this->state == fill) {
		value = this->data.top().to_string();
		this->state = empty;
	}
	else
	{
		Under_Flow e("流是空的，不能输出数据。");
		throw(e);
	}
	return value;
}

char* High_Precision_Maths_Library::OperandStream_Base::operator>>(char* value)
{
	if (this->state == fill) {
		string s = this->data.top().to_string();
		unsigned long long lenght = s.length();
		value = new char[lenght];
		for (unsigned long long ll = 0; ll < lenght; ll++) {
			value[ll] = s[ll];
		}
		this->state = empty;
	}
	else
	{
		Under_Flow e("流是空的，不能输出数据。");
		throw(e);
	}
	return value;
}

Operand_Base High_Precision_Maths_Library::OperandStream_Base::operator>>(Operand_Base& value)
{
	if (this->state == fill) {
		value = this->data.top();
		this->state = empty;
	}
	else
	{
		Under_Flow e("流是空的，不能输出数据。");
		throw(e);
	}
	return value;
}

float High_Precision_Maths_Library::OperandStream_Base::operator>>(float value)
{
	if (this->state == fill) {
		stringstream ss;
		ss << this->data.top().to_string();
		ss >> value;
		this->state = empty;
	}
	else
	{
		Under_Flow e("流是空的，不能输出数据。");
		throw(e);
	}
	return value;
}

double High_Precision_Maths_Library::OperandStream_Base::operator>>(double value)
{
	if (this->state == fill) {
		stringstream ss;
		ss << this->data.top().to_string();
		ss >> value;
		this->state = empty;
	}
	else
	{
		Under_Flow e("流是空的，不能输出数据。");
		throw(e);
	}
	return value;
}

long double High_Precision_Maths_Library::OperandStream_Base::operator>>(long double value)
{
	if (this->state == fill) {
		stringstream ss;
		ss << this->data.top().to_string();
		ss >> value;
		this->state = empty;
	}
	else
	{
		Under_Flow e("流是空的，不能输出数据。");
		throw(e);
	}
	return value;
}

void High_Precision_Maths_Library::OperandStream_Base::clear()
{
	this->data.clear();
	this->state = empty;
	return;
}

void High_Precision_Maths_Library::OperandStream_Base::pop()
{
	this->data.pop();
	this->state = empty;
	return;
}

bool High_Precision_Maths_Library::OperandStream_Base::is_empty()
{
	if (this->state == empty) {
		return true;
	}
	else
	{
		return false;
	}
}

bool High_Precision_Maths_Library::OperandStream_Base::is_fill()
{
	if (this->state == fill) {
		return true;
	}
	else
	{
		return false;
	}
}

void High_Precision_Maths_Library::OperandStream_Base::change_precision(Operand_Base& value, Precision_Base& precision)
{
	char _0 = '0';
	char _1 = '1';
	//四舍五入
	if (precision.type == round) {
		//将v移到要保留的位数的下一位（指向最低位）
		Value<char>* v = value.data.address(value.point + precision.precision + 1);
		//删除保留的位数的下一位之后的数据
		while (true)
		{
			//当保留的位数的下一位成为对象中的最后一个元素时，退出
			if (value.data.end() == v) {
				break;
			}
			else
			{
				//弹出最后一个元素
				value.data.pop();
			}
		}
		//五入
		if (*v->value > '4') {
			Result result;
			result.change = '1';
			//指向对象中的第一个元素的指针（指向最高位）
			Value<char>* top = value.data.begin();
			//从最低位开始向高位做加法
			while (true)
			{
				//当低位和高位的指针重合时，加法完成
				if (v == top) {
					high_precision_add(*v->value, _0, result);
					*v->value = result.result;
					break;
				}
				high_precision_add(*v->value, _0, result);
				*v->value = result.result;
				v = v->next;
			}
			//有进位，向前插入进位
			if (result.change == '1') {
				value.data.insert(top, _1);
			}
			//弹出保留的位数的下一位
			value.data.pop();
			//若保留整数，弹出小数点
			if (precision.precision == 0) {
				value.data.pop();
			}
			return;
		}
		//四舍
		else
		{
			value.data.pop();
			//若保留整数，弹出小数点
			if (precision.precision == 0) {
				value.data.pop();
			}
			return;
		}
	}
	//去尾
	else if (precision.type == round_down) {
		// 将v移到要保留的位数
		Value<char>* v = value.data.address(value.point + precision.precision);
		//删除保留的位数之后的数据
		while (true)
		{
			//当保留的位数成为对象中的最后一个元素时，退出
			if (value.data.end() == v) {
				break;
			}
			else
			{
				//弹出最后一个元素
				value.data.pop();
			}
		}
		//若保留整数，弹出小数点
		if (precision.precision == 0) {
			value.data.pop();
		}
		return;
	}
	//进一
	else if (precision.type == round_up) {
		// 将v移到要保留的位数
		Value<char>* v = value.data.address(value.point + precision.precision);
		//删除保留的位数之后的数据
		while (true)
		{
			//当保留的位数成为对象中的最后一个元素时，退出
			if (value.data.end() == v) {
				break;
			}
			else
			{
				//弹出最后一个元素
				value.data.pop();
			}
		}
		Result result;
		result.change = '1';
		//指向对象中的第一个元素的指针（指向最高位）
		Value<char>* top = value.data.begin();
		//从最低位开始向高位做加法
		while (true)
		{
			//当低位和高位的指针重合时，加法完成
			if (v == top) {
				high_precision_add(*v->value, _0, result);
				*v->value = result.result;
				break;
			}
			high_precision_add(*v->value, _0, result);
			*v->value = result.result;
			v = v->next;
		}
		//有进位，向前插入进位
		if (result.change == '1') {
			value.data.insert(top, _1);
		}
		//若保留整数，弹出小数点
		if (precision.precision == 0) {
			value.data.pop();
		}
		return;
	}
	//都不是则报错
	else
	{
		Illegal_Data e("输入的转换类型不合法。，请在宏中进行选择。");
		throw(e);
	}
}
