#include "Accumulation.h"

__forceinline void quickSort(unsigned long long left, unsigned long long right, Accumulation& arr)
{
	if (left >= right)
		return;
	unsigned long long i, j;
	i = left, j = right;
	Operand_Standard base(arr[left]); //取最左边的数为基准数
	Operand_Standard temp;
	while (i < j)
	{
		while (arr[j] >= base && i < j)
			j--;
		while (arr[i] <= base && i < j)
			i++;
		if (i < j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	//基准数归位
	arr[left] = arr[i];
	arr[i] = base;
	quickSort(left, i - 1, arr);//递归左边
	quickSort(i + 1, right, arr);//递归右边
}

__forceinline High_Precision_Maths_Library::Accumulation::Accumulation()
{
	return;
}

__forceinline High_Precision_Maths_Library::Accumulation::Accumulation(Accumulation& value)
{
	this->data.copy(value.data);
	return;
}

__forceinline void High_Precision_Maths_Library::Accumulation::push_back(Operand_Standard& value)
{
	this->data.push_back(value);
	return;
}

__forceinline void High_Precision_Maths_Library::Accumulation::push_back(Operand_Base& value)
{
	Operand_Standard o;
	o.data = value;
	this->data.push_back(o);
	return;
}

__forceinline void High_Precision_Maths_Library::Accumulation::operator<<(Operand_Standard& value)
{
	this->data.push_back(value);
	return;
}

__forceinline void High_Precision_Maths_Library::Accumulation::operator<<(Operand_Base& value)
{
	Operand_Standard o;
	o.data = value;
	this->data.push_back(o);
	return;
}

__forceinline void High_Precision_Maths_Library::Accumulation::remove(unsigned long long n)
{
	this->data.remove(n);
	return;
}

__forceinline Operand_Standard& High_Precision_Maths_Library::Accumulation::at(unsigned long long n)
{
	return this->data.at(n);
}

__forceinline Operand_Standard& High_Precision_Maths_Library::Accumulation::operator[](unsigned long long n)
{
	return this->data.at(n);
}

__forceinline Operand_Standard High_Precision_Maths_Library::Accumulation::get_result()
{
	Operand_Standard result;
	Value<Operand_Standard>* sign = this->data.begin();
	unsigned long long max = this->data.size() - 1;
	for (unsigned long long i = 0; i < max; i++) {
		if (i == 0) {
			result = *sign->value;
		}
		else
		{
			result += *sign->value;
		}
		sign = sign->next;
	}
	return result;
}

__forceinline void High_Precision_Maths_Library::Accumulation::clear()
{
	this->data.clear();
	return;
}

__forceinline unsigned long long High_Precision_Maths_Library::Accumulation::size()
{
	return this->data.size();
}

__forceinline void High_Precision_Maths_Library::Accumulation::sort()
{
	quickSort(0, this->data.size() - 1, *this);
	return;
}

__forceinline void High_Precision_Maths_Library::Accumulation::put(Operand_Standard& value)
{
	*this << value;
	this->sort();
	return;
}

__forceinline void High_Precision_Maths_Library::Accumulation::put(Operand_Base& value)
{
	*this << value;
	this->sort();
	return;
}