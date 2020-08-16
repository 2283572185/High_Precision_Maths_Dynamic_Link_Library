#include "Operand_Stream_Standard.h"

High_Precision_Maths_Library::OperandStream_Standard::OperandStream_Standard()
{
	this->state = empty;
	return;
}

High_Precision_Maths_Library::OperandStream_Standard::OperandStream_Standard(const OperandStream_Standard& value)
{
	this->data.copy((DDM<Operand_Base>&)value.data);
	this->state = value.state;
	return;
}

__forceinline void High_Precision_Maths_Library::OperandStream_Standard::operator<<(int value)
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

__forceinline void High_Precision_Maths_Library::OperandStream_Standard::operator<<(short value)
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

__forceinline void High_Precision_Maths_Library::OperandStream_Standard::operator<<(long value)
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

__forceinline void High_Precision_Maths_Library::OperandStream_Standard::operator<<(long long value)
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

__forceinline void High_Precision_Maths_Library::OperandStream_Standard::operator<<(unsigned int value)
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

__forceinline void High_Precision_Maths_Library::OperandStream_Standard::operator<<(unsigned short value)
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

__forceinline void High_Precision_Maths_Library::OperandStream_Standard::operator<<(unsigned long value)
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

__forceinline void High_Precision_Maths_Library::OperandStream_Standard::operator<<(unsigned long long value)
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

__forceinline void High_Precision_Maths_Library::OperandStream_Standard::operator<<(char value)
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

__forceinline void High_Precision_Maths_Library::OperandStream_Standard::operator<<(string value)
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

__forceinline void High_Precision_Maths_Library::OperandStream_Standard::operator<<(char* value)
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

__forceinline void High_Precision_Maths_Library::OperandStream_Standard::operator<<(Operand_Base& value)
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

__forceinline void High_Precision_Maths_Library::OperandStream_Standard::operator<<(float value)
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

__forceinline void High_Precision_Maths_Library::OperandStream_Standard::operator<<(double value)
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

__forceinline void High_Precision_Maths_Library::OperandStream_Standard::operator<<(long double value)
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

__forceinline void High_Precision_Maths_Library::OperandStream_Standard::operator<<(High_Precision_Maths_Library::Operand_Standard& value)
{
	if (this->state == empty) {
		this->data_S.push_back(value);
		this->state = fill;
		this->is_S = true;
	}
	else
	{
		Over_Flow e("流是满的，不能输入数据。");
		throw(e);
	}
	return;
}

__forceinline int High_Precision_Maths_Library::OperandStream_Standard::operator>>(int value)
{
	if (this->state == fill) {
		OperandStream_Base::change_precision((Operand_Base&)this->data.top(), (Precision_Base&)Precision_Base(0, round));
		stringstream ss;
		if (this->is_S) {
			ss << this->data_S.top().to_string();
			this->is_S = false;
		}
		else
		{
			ss << this->data.top().to_string();
		}
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

__forceinline short High_Precision_Maths_Library::OperandStream_Standard::operator>>(short value)
{
	if (this->state == fill) {
		OperandStream_Base::change_precision((Operand_Base&)this->data.top(), (Precision_Base&)Precision_Base(0, round));
		stringstream ss;
		if (this->is_S) {
			ss << this->data_S.top().to_string();
			this->is_S = false;
		}
		else
		{
			ss << this->data.top().to_string();
		}
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

__forceinline long High_Precision_Maths_Library::OperandStream_Standard::operator>>(long value)
{
	if (this->state == fill) {
		OperandStream_Base::change_precision((Operand_Base&)this->data.top(), (Precision_Base&)Precision_Base(0, round));
		stringstream ss;
		if (this->is_S) {
			ss << this->data_S.top().to_string();
			this->is_S = false;
		}
		else
		{
			ss << this->data.top().to_string();
		}
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

__forceinline long long High_Precision_Maths_Library::OperandStream_Standard::operator>>(long long value)
{
	if (this->state == fill) {
		OperandStream_Base::change_precision((Operand_Base&)this->data.top(), (Precision_Base&)Precision_Base(0, round));
		stringstream ss;
		if (this->is_S) {
			ss << this->data_S.top().to_string();
			this->is_S = false;
		}
		else
		{
			ss << this->data.top().to_string();
		}
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

__forceinline unsigned int High_Precision_Maths_Library::OperandStream_Standard::operator>>(unsigned int value)
{
	if (this->state == fill) {
		OperandStream_Base::change_precision((Operand_Base&)this->data.top(), (Precision_Base&)Precision_Base(0, round));
		stringstream ss;
		if (this->is_S) {
			ss << this->data_S.top().to_string();
			this->is_S = false;
		}
		else
		{
			ss << this->data.top().to_string();
		}
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

__forceinline unsigned short High_Precision_Maths_Library::OperandStream_Standard::operator>>(unsigned short value)
{
	if (this->state == fill) {
		OperandStream_Base::change_precision((Operand_Base&)this->data.top(), (Precision_Base&)Precision_Base(0, round));
		stringstream ss;
		if (this->is_S) {
			ss << this->data_S.top().to_string();
			this->is_S = false;
		}
		else
		{
			ss << this->data.top().to_string();
		}
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

__forceinline unsigned long High_Precision_Maths_Library::OperandStream_Standard::operator>>(unsigned long value)
{
	if (this->state == fill) {
		OperandStream_Base::change_precision((Operand_Base&)this->data.top(), (Precision_Base&)Precision_Base(0, round));
		stringstream ss;
		if (this->is_S) {
			ss << this->data_S.top().to_string();
			this->is_S = false;
		}
		else
		{
			ss << this->data.top().to_string();
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

__forceinline unsigned long long High_Precision_Maths_Library::OperandStream_Standard::operator>>(unsigned long long value)
{
	if (this->state == fill) {
		OperandStream_Base::change_precision((Operand_Base&)this->data.top(), (Precision_Base&)Precision_Base(0, round));
		stringstream ss;
		if (this->is_S) {
			ss << this->data_S.top().to_string();
			this->is_S = false;
		}
		else
		{
			ss << this->data.top().to_string();
		}
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

__forceinline char High_Precision_Maths_Library::OperandStream_Standard::operator>>(char value)
{
	if (this->state == fill) {
		stringstream ss;
		if (this->is_S) {
			ss << this->data_S.top().to_string();
			this->is_S = false;
		}
		else
		{
			ss << this->data.top().to_string();
		}
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

__forceinline string High_Precision_Maths_Library::OperandStream_Standard::operator>>(string& value)
{
	if (this->state == fill) {
		if (this->is_S) {
			value = this->data_S.top().to_string();
			this->is_S = false;
		}
		else
		{
			value = this->data.top().to_string();
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

__forceinline char* High_Precision_Maths_Library::OperandStream_Standard::operator>>(char* value)
{
	if (this->state == fill) {
		string s;
		if (this->is_S) {
			s = this->data_S.top().to_string();
			this->is_S = false;
		}
		else
		{
			s = this->data.top().to_string();
		}
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

__forceinline Operand_Base High_Precision_Maths_Library::OperandStream_Standard::operator>>(Operand_Base& value)
{
	if (this->state == fill) {
		if (this->is_S) {
			value = this->data_S.top().data;
			this->is_S = false;
		}
		else
		{
			value = this->data.top();
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

__forceinline float High_Precision_Maths_Library::OperandStream_Standard::operator>>(float value)
{
	if (this->state == fill) {
		stringstream ss;
		if (this->is_S) {
			ss << this->data_S.top().to_string();
			this->is_S = false;
		}
		else
		{
			ss << this->data.top().to_string();
		}
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

__forceinline double High_Precision_Maths_Library::OperandStream_Standard::operator>>(double value)
{
	if (this->state == fill) {
		stringstream ss;
		if (this->is_S) {
			ss << this->data_S.top().to_string();
			this->is_S = false;
		}
		else
		{
			ss << this->data.top().to_string();
		}
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

__forceinline long double High_Precision_Maths_Library::OperandStream_Standard::operator>>(long double value)
{
	if (this->state == fill) {
		stringstream ss;
		if (this->is_S) {
			ss << this->data_S.top().to_string();
			this->is_S = false;
		}
		else
		{
			ss << this->data.top().to_string();
		}
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

__forceinline High_Precision_Maths_Library::Operand_Standard High_Precision_Maths_Library::OperandStream_Standard::operator>>(High_Precision_Maths_Library::Operand_Standard& value)
{
	if (this->state == fill) {
		if (this->is_S) {
			value = this->data_S.top();
			this->is_S = false;
		}
		else
		{
			value.data = this->data.top();
			value.minus = false;
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

__forceinline void High_Precision_Maths_Library::OperandStream_Standard::clear()
{
	this->data.clear();
	this->data_S.clear();
	this->is_S = false;
	this->state = empty;
	return;
}

__forceinline void High_Precision_Maths_Library::OperandStream_Standard::free()
{
	if (this->is_S) {
		this->is_S = false;
		this->data_S.pop();
	}
	else
	{
		this->data.pop();
	}
	this->state = empty;
	return;
}

__forceinline void High_Precision_Maths_Library::OperandStream_Standard::change_precision(High_Precision_Maths_Library::Operand_Standard& value, Precision_Base& precision)
{
	OperandStream_Base::change_precision(value.data, precision);
	return;
}

__forceinline void High_Precision_Maths_Library::OperandStream_Standard::absolute_value(High_Precision_Maths_Library::Operand_Standard& value)
{
	value.minus = false;
	return;
}