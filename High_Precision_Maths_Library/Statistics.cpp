#include "Statistics.h"
#include "Operand_Stream_Standard.h"

__forceinline High_Precision_Maths_Library::Statistics::Statistics()
{
	return;
}

__forceinline High_Precision_Maths_Library::Statistics::Statistics(Statistics& value)
{
	this->data.data.copy(value.data.data);
	return;
}

__forceinline void High_Precision_Maths_Library::Statistics::put(Operand_Base& value)
{
	this->data.put(value);
	return;
}

__forceinline void High_Precision_Maths_Library::Statistics::put(Operand_Standard& value)
{
	this->data.put(value);
	return;
}

__forceinline unsigned long long High_Precision_Maths_Library::Statistics::size()
{
	return this->data.size();
}

Operand_Standard& High_Precision_Maths_Library::Statistics::at(unsigned long long n)
{
	return this->data.at(n);
}

Operand_Standard& High_Precision_Maths_Library::Statistics::operator[](unsigned long long n)
{
	return this->data.at(n);
}

void High_Precision_Maths_Library::Statistics::operator()(Statistics& value)
{
	this->data.data.copy(value.data.data);
	return;
}

Operand_Standard High_Precision_Maths_Library::Statistics::range()
{
	return (this->data.at(this->size() - 1) - this->data.at(0));
}

Operand_Standard High_Precision_Maths_Library::Statistics::get_max()
{
	return this->data.at(this->size() - 1);
}

Operand_Standard High_Precision_Maths_Library::Statistics::get_min()
{
	return this->data.at(0);
}

Operand_Standard High_Precision_Maths_Library::Statistics::average()
{
	Operand_Standard value;
	unsigned long long max = this->size() - 1;
	for (unsigned long long i = 0; i < max; i++) {
		if (i == 0) {
			value(this->at(i));
		}
		else
		{
			value += this->at(i);
		}
	}
	return (value / (Operand_Standard&)Operand_Standard(this->size()));
}

Operand_Standard High_Precision_Maths_Library::Statistics::variance()
{
	Operand_Standard average = this->average();
	Operand_Standard value;
	unsigned long long max = this->size() - 1;
	for (unsigned long long i = 0; i < max; i++) {
		if (i == 0) {
			value = ((this->at(i) - average) ^ 2);
		}
		else
		{
			value += (Operand_Standard&)((this->at(i) - average) ^ 2);
		}
	}
	return (value / (Operand_Standard&)Operand_Standard(this->size()));
}

Operand_Standard High_Precision_Maths_Library::Statistics::standard_deviation()
{
	Operand_Standard average = this->average();
	Operand_Standard value;
	Operand_Standard middle;
	unsigned long long max = this->size() - 1;
	for (unsigned long long i = 0; i < max; i++) {
		if (i == 0) {
			middle((Operand_Standard&)(this->at(i) - average));
			OperandStream_Standard::absolute_value(middle);
			value(middle);
		}
		else
		{
			middle((Operand_Standard&)(this->at(i) - average));
			OperandStream_Standard::absolute_value(middle);
			value += middle;
		}
	}
	return (value / (Operand_Standard&)Operand_Standard(this->size()));
}

Operand_Standard High_Precision_Maths_Library::Statistics::median()
{
	if (this->size() % 2 == 1) {
		return this->at((this->size() + 1) / 2 - 1);
	}
	else {
		return ((this->at(this->size() / 2 - 1) + this->at(this->size() / 2)) / (Operand_Standard&)Operand_Standard(2));
	}
}
