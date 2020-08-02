#include "Operation_Base.h"

class High_Precision_Maths_Library::Operand_Base;
class High_Precision_Maths_Library::Result;
class High_Precision_Maths_Library::OperandStream_Base;

//��������Ԥ��
unsigned long long Division_Precision = 15;
//��������Ԥ��
unsigned long long Extraction_Of_Root_Precision = 15;
//������������
unsigned long long Extraction_Of_Root_Time = 7;
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
		//����С���㿪ͷ����ǰ�油��һ��0
		if (value.point == 0 && value.data[value.point] == '.') {
			value.data.insert(value.data.begin(), _0);
			break;
		}
		//����С�����β������󲹳�һ��0
		else if (value.point == max - 1 && value.data[value.point] == '.') {
			value.data.push_back(_0);
			break;
		}
		//��û��С���㣬�򲹳�С�����0
		else if (value.point == max - 1 && value.data[value.point] != '.') {
			value.data.push_back(_point);
			value.data.push_back(_0);
			value.point++;
			break;
		}
		//������С���㣬����
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

void High_Precision_Maths_Library::high_precision_addition(char& left, char& right, Result& _result)
{
	//�����С���㣬ֱ�ӷ���
	if (left == '.' || right == '.') {
		_result.result = '.';
		return;
	}
	//���֮ǰ���ڽ�λ������������ϼ�һ
	if (_result.change == '1') {
		left++;
	}
	//���������������Ӵ���9����λ��ֵ1�����Ϊ�ͼ�10
	if (left + right - '0' > '9') {
		_result.result = left + right - _10;
		_result.change = '1';
	}
	//��������λ��ֵ0�����Ϊ��
	else
	{
		_result.result = left + right - '0';
		_result.change = '0';
	}
	return;
}

void High_Precision_Maths_Library::decimal_point(Operand_Base& left, Operand_Base& right)
{
	//����ǰ����
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
	//�������
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

void High_Precision_Maths_Library::high_precision_multiplication(char& left, char& right, Result& _result)
{
	//�����С���㣬���ã�ֱ�ӷ���
	if (left == '.' || right == '.') {
		_result.result = '0';
		_result.change = '0';
		return;
	}
	//ԭ����ʮλ������ڵĸ�λ
	_result.result = _result.change;
	_result.change = '0';
	//�žų˷��ھ���
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
	//������λ�����ڡ�10����ʮλ+1����λ-10
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
	//С����λ�ã�����������
	unsigned long long rl_point = (left.data.size() - 1 - left.point) + (right.data.size() - 1 - right.point);
	Result _result;
	Operand_Base result;
	//���ڴ����м�����
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
				//����С����ͺ���
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
					//����С����ͺ���
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
			//����С����ͺ���
			result.data.pop();
			result.data.pop();
		}
		need++;
		right_do = right_do->last;
		left_do = left.data.end();
	}
	//����С����
	begin = result.data.end();
	for (unsigned long long i = 0; i < rl_point - 1; i++) {
		begin = begin->last;
	}
	result.data.insert(begin, _point);
	position_point(result);
	remain_significant_number(result);
	return result;
}

void High_Precision_Maths_Library::remain_significant_number(Operand_Base& value)
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

void High_Precision_Maths_Library::high_precision_subtraction(char& left, char& right, Result& _result)
{
	//����С���㷵��
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
	//��¼ԭ������С����λ��
	unsigned long long point = right.point;
	//������������λ�����󵽺ͱ�����������λ��һ����
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
	//������
	while (true)
	{
		if (right.point == point) {
			//��
			i = '0';
			//�������ˣ��˳�
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
			//������
			result.data.push_back(i);
			break;
		}
		//��
		i = '0';
		//�������ˣ��˳�
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
		//������
		result.data.push_back(i);
		//������С10��
		right <<= 1;
	}
	//����С����
	result.data.push_back(_point);
	Value<char>* v = result.data.begin();
	//ȥ�����õ�0
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
	//��С��
	while (true)
	{
		if (result.data.size() - 1 - result.point == Division_Precision + 1) {
			break;
		}
		//��
		i = '0';
		//��������10��
		left >>= 1;
		//�������ˣ��˳�
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
	remain_significant_number(result);
	OperandStream_Base os;
	os.change_precision(result, (Precision_Base&)Precision_Base(Division_Precision, round));
	return result;
}

Operand_Base High_Precision_Maths_Library::Extraction(Operand_Base left, unsigned long long n)
{
	if (n == 0) {
		Illegal_Data e("������0�η�����");
		throw(e);
	}
	else if (n == 1) {
		return left;
	}
	Operand_Base a('1');
	for (unsigned long long i = 0; i < Extraction_Of_Root_Time; i++) {
		a = Division(Addition((Operand_Base&)Division(left, (a ^ (n - 1))), (Operand_Base&)(Multiplication(a, (Operand_Base&)Operand_Base(n - 1)))), n);
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
	//��¼ԭ������С����λ��
	unsigned long long point = right.point;
	//������������λ�����󵽺ͱ�����������λ��һ����
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
	//ȡ����
	while (true)
	{
		if (right.point == point) {
			//�������ˣ��˳�
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
		//�������ˣ��˳�
		while (true) {
			if (left < right) {
				break;
			}
			else
			{
				left -= right;
			}
		}
		//������С10��
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
		Illegal_Data e("��ѡ�õ����ͳ�����֧�ֵķ�Χ��");
		throw(e);
	}
}