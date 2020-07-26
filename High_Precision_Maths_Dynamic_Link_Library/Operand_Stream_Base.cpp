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

void High_Precision_Maths_Library::OperandStream_Base::operator<<(std::string value)
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

