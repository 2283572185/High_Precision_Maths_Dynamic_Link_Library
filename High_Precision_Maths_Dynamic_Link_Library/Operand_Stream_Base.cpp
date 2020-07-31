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
		Over_Flow e("�������ģ������������ݡ�");
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
		Over_Flow e("�������ģ������������ݡ�");
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
		Over_Flow e("�������ģ������������ݡ�");
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
		Over_Flow e("�������ģ������������ݡ�");
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
		Over_Flow e("�������ģ������������ݡ�");
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
		Over_Flow e("�������ģ������������ݡ�");
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
		Over_Flow e("�������ģ������������ݡ�");
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
		Over_Flow e("�������ģ������������ݡ�");
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
		Over_Flow e("�������ģ������������ݡ�");
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
		Over_Flow e("�������ģ������������ݡ�");
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
		Over_Flow e("�������ģ������������ݡ�");
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
		Over_Flow e("�������ģ������������ݡ�");
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
		Over_Flow e("�������ģ������������ݡ�");
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
		Over_Flow e("�������ģ������������ݡ�");
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
		Over_Flow e("�������ģ������������ݡ�");
		throw(e);
	}
	return;
}

int High_Precision_Maths_Library::OperandStream_Base::operator>>(int value)
{
	if (this->state == fill) {
		this->change_precision((Operand_Base&)this->data.top(), (Precision_Base&)Precision_Base(0, round));
		stringstream ss;
		ss << this->data.top().to_string();
		ss >> value;
		this->state = empty;
	}
	else
	{
		Under_Flow e("���ǿյģ�����������ݡ�");
		throw(e);
	}
	return value;
}

short High_Precision_Maths_Library::OperandStream_Base::operator>>(short value)
{
	if (this->state == fill) {
		this->change_precision((Operand_Base&)this->data.top(), (Precision_Base&)Precision_Base(0, round));
		stringstream ss;
		ss << this->data.top().to_string();
		ss >> value;
		this->state = empty;
	}
	else
	{
		Under_Flow e("���ǿյģ�����������ݡ�");
		throw(e);
	}
	return value;
}

long High_Precision_Maths_Library::OperandStream_Base::operator>>(long value)
{
	if (this->state == fill) {
		this->change_precision((Operand_Base&)this->data.top(), (Precision_Base&)Precision_Base(0, round));
		stringstream ss;
		ss << this->data.top().to_string();
		ss >> value;
		this->state = empty;
	}
	else
	{
		Under_Flow e("���ǿյģ�����������ݡ�");
		throw(e);
	}
	return value;
}

long long High_Precision_Maths_Library::OperandStream_Base::operator>>(long long value)
{
	if (this->state == fill) {
		this->change_precision((Operand_Base&)this->data.top(), (Precision_Base&)Precision_Base(0, round));
		stringstream ss;
		ss << this->data.top().to_string();
		ss >> value;
		this->state = empty;
	}
	else
	{
		Under_Flow e("���ǿյģ�����������ݡ�");
		throw(e);
	}
	return value;
}

unsigned int High_Precision_Maths_Library::OperandStream_Base::operator>>(unsigned int value)
{
	if (this->state == fill) {
		this->change_precision((Operand_Base&)this->data.top(), (Precision_Base&)Precision_Base(0, round));
		stringstream ss;
		ss << this->data.top().to_string();
		ss >> value;
		this->state = empty;
	}
	else
	{
		Under_Flow e("���ǿյģ�����������ݡ�");
		throw(e);
	}
	return value;
}

unsigned short High_Precision_Maths_Library::OperandStream_Base::operator>>(unsigned short value)
{
	if (this->state == fill) {
		this->change_precision((Operand_Base&)this->data.top(), (Precision_Base&)Precision_Base(0, round));
		stringstream ss;
		ss << this->data.top().to_string();
		ss >> value;
		this->state = empty;
	}
	else
	{
		Under_Flow e("���ǿյģ�����������ݡ�");
		throw(e);
	}
	return value;
}

unsigned long High_Precision_Maths_Library::OperandStream_Base::operator>>(unsigned long value)
{
	if (this->state == fill) {
		this->change_precision((Operand_Base&)this->data.top(), (Precision_Base&)Precision_Base(0, round));
		stringstream ss;
		ss << this->data.top().to_string();
		ss >> value;
		this->state = empty;
	}
	else
	{
		Under_Flow e("���ǿյģ�����������ݡ�");
		throw(e);
	}
	return value;
}

unsigned long long High_Precision_Maths_Library::OperandStream_Base::operator>>(unsigned long long value)
{
	if (this->state == fill) {
		this->change_precision((Operand_Base&)this->data.top(), (Precision_Base&)Precision_Base(0, round));
		stringstream ss;
		ss << this->data.top().to_string();
		ss >> value;
		this->state = empty;
	}
	else
	{
		Under_Flow e("���ǿյģ�����������ݡ�");
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
		Under_Flow e("���ǿյģ�����������ݡ�");
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
		Under_Flow e("���ǿյģ�����������ݡ�");
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
		Under_Flow e("���ǿյģ�����������ݡ�");
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
		Under_Flow e("���ǿյģ�����������ݡ�");
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
		Under_Flow e("���ǿյģ�����������ݡ�");
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
		Under_Flow e("���ǿյģ�����������ݡ�");
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
		Under_Flow e("���ǿյģ�����������ݡ�");
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

void High_Precision_Maths_Library::OperandStream_Base::free()
{
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
	//��������
	if (precision.type == round || precision.type == (round | strict)) {
		//��v�Ƶ�Ҫ������λ������һλ��ָ�����λ��
		Value<char>* v = value.data.address(value.point + precision.precision + 1);
		//ɾ��������λ������һλ֮�������
		while (true)
		{
			//��������λ������һλ��Ϊ�����е����һ��Ԫ��ʱ���˳�
			if (value.data.end() == v) {
				break;
			}
			else
			{
				//�������һ��Ԫ��
				value.data.pop();
			}
		}
		//����
		if (*v->value > '4') {
			Result result;
			result.change = '1';
			//ָ������еĵ�һ��Ԫ�ص�ָ�루ָ�����λ��
			Value<char>* top = value.data.begin();
			//��v�Ƶ�Ҫ������λ��
			v = v->last;
			//�����λ��ʼ���λ���ӷ�
			while (true)
			{
				//����λ�͸�λ��ָ���غ�ʱ���ӷ����
				if (v == top) {
					high_precision_add(*v->value, _0, result);
					*v->value = result.result;
					break;
				}
				high_precision_add(*v->value, _0, result);
				*v->value = result.result;
				v = v->last;
			}
			//�н�λ����ǰ�����λ
			if (result.change == '1') {
				value.data.insert(top, _1);
			}
			//����������λ������һλ
			value.data.pop();
			//����������������С����
			if (precision.precision == 0) {
				value.data.pop();
				value.point = value.data.size();
			}
		}
		//����
		else
		{
			value.data.pop();
			//����������������С����
			if (precision.precision == 0) {
				value.data.pop();
				value.point = value.data.size();
			}
		}
	}
	//ȥβ
	else if (precision.type == round_down || precision.type == (round_down | strict)) {
		// ��v�Ƶ�Ҫ������λ��
		Value<char>* v = value.data.address(value.point + precision.precision);
		//ɾ��������λ��֮�������
		while (true)
		{
			//��������λ����Ϊ�����е����һ��Ԫ��ʱ���˳�
			if (value.data.end() == v) {
				break;
			}
			else
			{
				//�������һ��Ԫ��
				value.data.pop();
			}
		}
		//����������������С����
		if (precision.precision == 0) {
			value.data.pop();
			value.point = value.data.size();
		}
	}
	//��һ
	else if (precision.type == round_up || precision.type == (round_up | strict)) {
		// ��v�Ƶ�Ҫ������λ��
		Value<char>* v = value.data.address(value.point + precision.precision);
		//ɾ��������λ��֮�������
		while (true)
		{
			//��������λ����Ϊ�����е����һ��Ԫ��ʱ���˳�
			if (value.data.end() == v) {
				break;
			}
			else
			{
				//�������һ��Ԫ��
				value.data.pop();
			}
		}
		Result result;
		result.change = '1';
		//ָ������еĵ�һ��Ԫ�ص�ָ�루ָ�����λ��
		Value<char>* top = value.data.begin();
		//�����λ��ʼ���λ���ӷ�
		while (true)
		{
			//����λ�͸�λ��ָ���غ�ʱ���ӷ����
			if (v == top) {
				high_precision_add(*v->value, _0, result);
				*v->value = result.result;
				break;
			}
			high_precision_add(*v->value, _0, result);
			*v->value = result.result;
			v = v->last;
		}
		//�н�λ����ǰ�����λ
		if (result.change == '1') {
			value.data.insert(top, _1);
		}
		//����������������С����
		if (precision.precision == 0) {
			value.data.pop();
			value.point = value.data.size();
		}
	}
	//�������򱨴�
	else
	{
		Illegal_Data e("�����ת�����Ͳ��Ϸ��������ں��н���ѡ��");
		throw(e);
	}
	//�����ϸ�ģʽ���ж��Ƿ���Ҫ��0
	if (precision.type == (round | strict) || precision.type == (round_down | strict) || precision.type == (round_up | strict)) {
		//��������ֱ���˳�
		if (precision.precision == 0) {
			return;
		}
		//����С����λ��
		unsigned long long decimal_digits = value.data.size() - 1 - value.point;
		//����Ҫ�����С��λ��
		unsigned long long need = precision.precision - decimal_digits;
		for (unsigned long long i = 0; i < need; i++)
		{
			//��0
			value.data.push_back(_0);
		}
		return;
	}
}
