#include "Operand_Stream_Base.h"

High_Precision_Maths_Library::OperandStream_Base::OperandStream_Base()
{
}

High_Precision_Maths_Library::OperandStream_Base::OperandStream_Base(const OperandStream_Base& value)
{
	this->data.copy((DDM< Operand_Base>&)value.data);
	return;
}

void High_Precision_Maths_Library::OperandStream_Base::operator<<(int value)
{
	Operand_Base o(value);
	this->data.push_back(o);
	return;
}

void High_Precision_Maths_Library::OperandStream_Base::operator<<(short value)
{
	Operand_Base o(value);
	this->data.push_back(o);
	return;
}

void High_Precision_Maths_Library::OperandStream_Base::operator<<(long value)
{
	Operand_Base o(value);
	this->data.push_back(o);
	return;
}

void High_Precision_Maths_Library::OperandStream_Base::operator<<(long long value)
{
	Operand_Base o(value);
	this->data.push_back(o);
	return;
}

void High_Precision_Maths_Library::OperandStream_Base::operator<<(unsigned int value)
{
	Operand_Base o(value);
	this->data.push_back(o);
	return;
}

void High_Precision_Maths_Library::OperandStream_Base::operator<<(unsigned short value)
{
	Operand_Base o(value);
	this->data.push_back(o);
	return;
}

void High_Precision_Maths_Library::OperandStream_Base::operator<<(unsigned long value)
{
	Operand_Base o(value);
	this->data.push_back(o);
	return;
}

void High_Precision_Maths_Library::OperandStream_Base::operator<<(unsigned long long value)
{
	Operand_Base o(value);
	this->data.push_back(o);
	return;
}

void High_Precision_Maths_Library::OperandStream_Base::operator<<(char value)
{
	Operand_Base o(value);
	this->data.push_back(o);
	return;
}

void High_Precision_Maths_Library::OperandStream_Base::operator<<(string value)
{
	Operand_Base o(value);
	this->data.push_back(o);
	return;
}

void High_Precision_Maths_Library::OperandStream_Base::operator<<(char* value)
{
	Operand_Base o(value);
	this->data.push_back(o);
	return;
}

void High_Precision_Maths_Library::OperandStream_Base::operator<<(Operand_Base& value)
{
	this->data.push_back(value);
	return;
}

void High_Precision_Maths_Library::OperandStream_Base::operator<<(float value)
{
	Operand_Base o(value);
	this->data.push_back(o);
	return;
}

void High_Precision_Maths_Library::OperandStream_Base::operator<<(double value)
{
	Operand_Base o(value);
	this->data.push_back(o);
	return;
}

void High_Precision_Maths_Library::OperandStream_Base::operator<<(long double value)
{
	Operand_Base o(value);
	this->data.push_back(o);
	return;
}

int High_Precision_Maths_Library::OperandStream_Base::operator>>(int value)
{
	stringstream ss;
	ss << this->data.top().to_string();
	ss >> value;
	return value;
}

short High_Precision_Maths_Library::OperandStream_Base::operator>>(short value)
{
	stringstream ss;
	ss << this->data.top().to_string();
	ss >> value;
	return value;
}

long High_Precision_Maths_Library::OperandStream_Base::operator>>(long value)
{
	stringstream ss;
	ss << this->data.top().to_string();
	ss >> value;
	return value;
}

long long High_Precision_Maths_Library::OperandStream_Base::operator>>(long long value)
{
	stringstream ss;
	ss << this->data.top().to_string();
	ss >> value;
	return value;
}

unsigned int High_Precision_Maths_Library::OperandStream_Base::operator>>(unsigned int value)
{
	stringstream ss;
	ss << this->data.top().to_string();
	ss >> value;
	return value;
}

unsigned short High_Precision_Maths_Library::OperandStream_Base::operator>>(unsigned short value)
{
	stringstream ss;
	ss << this->data.top().to_string();
	ss >> value;
	return value;
}

unsigned long High_Precision_Maths_Library::OperandStream_Base::operator>>(unsigned long value)
{
	stringstream ss;
	ss << this->data.top().to_string();
	ss >> value;
	return value;
}

unsigned long long High_Precision_Maths_Library::OperandStream_Base::operator>>(unsigned long long value)
{
	stringstream ss;
	ss << this->data.top().to_string();
	ss >> value;
	return value;
}

char High_Precision_Maths_Library::OperandStream_Base::operator>>(char value)
{
	stringstream ss;
	ss << this->data.top().to_string();
	ss >> value;
	return value;
}

string High_Precision_Maths_Library::OperandStream_Base::operator>>(string& value)
{
	value = this->data.top().to_string();
	return value;
}

char* High_Precision_Maths_Library::OperandStream_Base::operator>>(char* value)
{
	string s = this->data.top().to_string();
	unsigned long long lenght = s.length();
	value = new char[lenght];
	for (unsigned long long ll = 0; ll < lenght; ll++) {
		value[ll] = s[ll];
	}
	return value;
}

Operand_Base High_Precision_Maths_Library::OperandStream_Base::operator>>(Operand_Base& value)
{
	value = this->data.top();
	return value;
}

float High_Precision_Maths_Library::OperandStream_Base::operator>>(float value)
{
	stringstream ss;
	ss << this->data.top().to_string();
	ss >> value;
	return value;
}

double High_Precision_Maths_Library::OperandStream_Base::operator>>(double value)
{
	stringstream ss;
	ss << this->data.top().to_string();
	ss >> value;
	return value;
}

long double High_Precision_Maths_Library::OperandStream_Base::operator>>(long double value)
{
	stringstream ss;
	ss << this->data.top().to_string();
	ss >> value;
	return value;
}
