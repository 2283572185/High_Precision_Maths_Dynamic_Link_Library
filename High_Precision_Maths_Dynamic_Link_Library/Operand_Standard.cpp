#include "Operand_Standard.h"

static char _0 = '0';
static char _point = '.';

High_Precision_Maths_Library::Operand_Standard::Operand_Standard()
{
	this->minus = false;
}

High_Precision_Maths_Library::Operand_Standard::Operand_Standard(int value)
{
	stringstream ss;
	string s;
	ss << value;
	ss >> s;
	if (s[0] == '-') {
		//���Ϊ����
		this->minus = true;
		//�Ƴ�����
		s.erase(remove(s.begin(), s.end(), '-'), s.end());
	}
	else
	{
		//���Ϊ�Ǹ���
		this->minus = false;
	}
	unsigned long long max = s.length();
	for (unsigned long long i = 0; i < max; i++) {
		this->value.data.push_back(s[i]);
	}
	while (true)
	{
		//����С���㿪ͷ����ǰ�油��һ��0
		if (this->value.point == 0 && this->value.data[this->value.point] == '.') {
			this->value.data.insert(this->value.data.begin(), _0);
			break;
		}
		//����С�����β������󲹳�һ��0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] == '.') {
			this->value.data.push_back(_0);
			break;
		}
		//��û��С���㣬�򲹳�С�����0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] != '.') {
			this->value.data.push_back(_point);
			this->value.data.push_back(_0);
			this->value.point++;
			break;
		}
		//������С���㣬����
		else if (this->value.data[this->value.point] == '.') {
			break;
		}
		else
		{
			this->value.point++;
		}
	}
	return;
}

High_Precision_Maths_Library::Operand_Standard::Operand_Standard(short value)
{
	stringstream ss;
	string s;
	ss << value;
	ss >> s;
	if (s[0] == '-') {
		//���Ϊ����
		this->minus = true;
		//�Ƴ�����
		s.erase(remove(s.begin(), s.end(), '-'), s.end());
	}
	else
	{
		//���Ϊ�Ǹ���
		this->minus = false;
	}
	unsigned long long max = s.length();
	for (unsigned long long i = 0; i < max; i++) {
		this->value.data.push_back(s[i]);
	}
	while (true)
	{
		//����С���㿪ͷ����ǰ�油��һ��0
		if (this->value.point == 0 && this->value.data[this->value.point] == '.') {
			this->value.data.insert(this->value.data.begin(), _0);
			break;
		}
		//����С�����β������󲹳�һ��0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] == '.') {
			this->value.data.push_back(_0);
			break;
		}
		//��û��С���㣬�򲹳�С�����0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] != '.') {
			this->value.data.push_back(_point);
			this->value.data.push_back(_0);
			this->value.point++;
			break;
		}
		//������С���㣬����
		else if (this->value.data[this->value.point] == '.') {
			break;
		}
		else
		{
			this->value.point++;
		}
	}
	return;
}

High_Precision_Maths_Library::Operand_Standard::Operand_Standard(long value)
{
	stringstream ss;
	string s;
	ss << value;
	ss >> s;
	if (s[0] == '-') {
		//���Ϊ����
		this->minus = true;
		//�Ƴ�����
		s.erase(remove(s.begin(), s.end(), '-'), s.end());
	}
	else
	{
		//���Ϊ�Ǹ���
		this->minus = false;
	}
	unsigned long long max = s.length();
	for (unsigned long long i = 0; i < max; i++) {
		this->value.data.push_back(s[i]);
	}
	while (true)
	{
		//����С���㿪ͷ����ǰ�油��һ��0
		if (this->value.point == 0 && this->value.data[this->value.point] == '.') {
			this->value.data.insert(this->value.data.begin(), _0);
			break;
		}
		//����С�����β������󲹳�һ��0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] == '.') {
			this->value.data.push_back(_0);
			break;
		}
		//��û��С���㣬�򲹳�С�����0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] != '.') {
			this->value.data.push_back(_point);
			this->value.data.push_back(_0);
			this->value.point++;
			break;
		}
		//������С���㣬����
		else if (this->value.data[this->value.point] == '.') {
			break;
		}
		else
		{
			this->value.point++;
		}
	}
	return;
}

High_Precision_Maths_Library::Operand_Standard::Operand_Standard(long long value)
{
	stringstream ss;
	string s;
	ss << value;
	ss >> s;
	if (s[0] == '-') {
		//���Ϊ����
		this->minus = true;
		//�Ƴ�����
		s.erase(remove(s.begin(), s.end(), '-'), s.end());
	}
	else
	{
		//���Ϊ�Ǹ���
		this->minus = false;
	}
	unsigned long long max = s.length();
	for (unsigned long long i = 0; i < max; i++) {
		this->value.data.push_back(s[i]);
	}
	while (true)
	{
		//����С���㿪ͷ����ǰ�油��һ��0
		if (this->value.point == 0 && this->value.data[this->value.point] == '.') {
			this->value.data.insert(this->value.data.begin(), _0);
			break;
		}
		//����С�����β������󲹳�һ��0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] == '.') {
			this->value.data.push_back(_0);
			break;
		}
		//��û��С���㣬�򲹳�С�����0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] != '.') {
			this->value.data.push_back(_point);
			this->value.data.push_back(_0);
			this->value.point++;
			break;
		}
		//������С���㣬����
		else if (this->value.data[this->value.point] == '.') {
			break;
		}
		else
		{
			this->value.point++;
		}
	}
	return;
}

High_Precision_Maths_Library::Operand_Standard::Operand_Standard(unsigned int value)
{
	stringstream ss;
	string s;
	ss << value;
	ss >> s;
	unsigned long long max = s.length();
	for (unsigned long long i = 0; i < max; i++) {
		this->value.data.push_back(s[i]);
	}
	this->minus = false;
	return;
}

High_Precision_Maths_Library::Operand_Standard::Operand_Standard(unsigned short value)
{
	stringstream ss;
	string s;
	ss << value;
	ss >> s;
	unsigned long long max = s.length();
	for (unsigned long long i = 0; i < max; i++) {
		this->value.data.push_back(s[i]);
	}
	this->minus = false;
	while (true)
	{
		//����С���㿪ͷ����ǰ�油��һ��0
		if (this->value.point == 0 && this->value.data[this->value.point] == '.') {
			this->value.data.insert(this->value.data.begin(), _0);
			break;
		}
		//����С�����β������󲹳�һ��0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] == '.') {
			this->value.data.push_back(_0);
			break;
		}
		//��û��С���㣬�򲹳�С�����0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] != '.') {
			this->value.data.push_back(_point);
			this->value.data.push_back(_0);
			this->value.point++;
			break;
		}
		//������С���㣬����
		else if (this->value.data[this->value.point] == '.') {
			break;
		}
		else
		{
			this->value.point++;
		}
	}
	return;
}

High_Precision_Maths_Library::Operand_Standard::Operand_Standard(unsigned long value)
{
	stringstream ss;
	string s;
	ss << value;
	ss >> s;
	unsigned long long max = s.length();
	for (unsigned long long i = 0; i < max; i++) {
		this->value.data.push_back(s[i]);
	}
	this->minus = false;
	while (true)
	{
		//����С���㿪ͷ����ǰ�油��һ��0
		if (this->value.point == 0 && this->value.data[this->value.point] == '.') {
			this->value.data.insert(this->value.data.begin(), _0);
			break;
		}
		//����С�����β������󲹳�һ��0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] == '.') {
			this->value.data.push_back(_0);
			break;
		}
		//��û��С���㣬�򲹳�С�����0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] != '.') {
			this->value.data.push_back(_point);
			this->value.data.push_back(_0);
			this->value.point++;
			break;
		}
		//������С���㣬����
		else if (this->value.data[this->value.point] == '.') {
			break;
		}
		else
		{
			this->value.point++;
		}
	}
	return;
}

High_Precision_Maths_Library::Operand_Standard::Operand_Standard(unsigned long long value)
{
	stringstream ss;
	string s;
	ss << value;
	ss >> s;
	unsigned long long max = s.length();
	for (unsigned long long i = 0; i < max; i++) {
		this->value.data.push_back(s[i]);
	}
	this->minus = false;
	while (true)
	{
		//����С���㿪ͷ����ǰ�油��һ��0
		if (this->value.point == 0 && this->value.data[this->value.point] == '.') {
			this->value.data.insert(this->value.data.begin(), _0);
			break;
		}
		//����С�����β������󲹳�һ��0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] == '.') {
			this->value.data.push_back(_0);
			break;
		}
		//��û��С���㣬�򲹳�С�����0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] != '.') {
			this->value.data.push_back(_point);
			this->value.data.push_back(_0);
			this->value.point++;
			break;
		}
		//������С���㣬����
		else if (this->value.data[this->value.point] == '.') {
			break;
		}
		else
		{
			this->value.point++;
		}
	}
	return;
}

High_Precision_Maths_Library::Operand_Standard::Operand_Standard(char value)
{
	if ((value < '0' || value > '9') && value != '.') {
		Illegal_Data e("value����һ�����ֻ�С���㣬�������ڳ�ʼ������");
		throw(e);
	}
	this->minus = false;
	this->value.data.push_back(value);
	if (value != '.') {
		this->value.data.push_back(_point);
		this->value.data.push_back(_0);
		this->value.point = 1;
	}
	else
	{
		this->value.data.insert(this->value.data.begin(), _0);
		this->value.data.push_back(_0);
		this->value.point = 1;
	}
	return;
}

High_Precision_Maths_Library::Operand_Standard::Operand_Standard(std::string value)
{
	if (value[0] == '-') {
		//���Ϊ����
		this->minus = true;
		//�Ƴ�����
		value.erase(remove(value.begin(), value.end(), '-'), value.end());
	}
	else
	{
		//���Ϊ�Ǹ���
		this->minus = false;
	}
	unsigned long long max = value.length();
	for (unsigned long long i = 0; i < max; i++) {
		this->value.data.push_back(value[i]);
	}
	while (true)
	{
		//����С���㿪ͷ����ǰ�油��һ��0
		if (this->value.point == 0 && this->value.data[this->value.point] == '.') {
			this->value.data.insert(this->value.data.begin(), _0);
			break;
		}
		//����С�����β������󲹳�һ��0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] == '.') {
			this->value.data.push_back(_0);
			break;
		}
		//��û��С���㣬�򲹳�С�����0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] != '.') {
			this->value.data.push_back(_point);
			this->value.data.push_back(_0);
			this->value.point++;
			break;
		}
		//������С���㣬����
		else if (this->value.data[this->value.point] == '.') {
			break;
		}
		else
		{
			this->value.point++;
		}
	}
	return;
}

High_Precision_Maths_Library::Operand_Standard::Operand_Standard(char* value)
{
	stringstream ss;
	string s;
	ss << value;
	ss >> s;
	if (s[0] == '-') {
		//���Ϊ����
		this->minus = true;
		//�Ƴ�����
		s.erase(remove(s.begin(), s.end(), '-'), s.end());
	}
	else
	{
		//���Ϊ�Ǹ���
		this->minus = false;
	}
	unsigned long long max = s.length();
	for (unsigned long long i = 0; i < max; i++) {
		this->value.data.push_back(s[i]);
	}
	while (true)
	{
		//����С���㿪ͷ����ǰ�油��һ��0
		if (this->value.point == 0 && this->value.data[this->value.point] == '.') {
			this->value.data.insert(this->value.data.begin(), _0);
			break;
		}
		//����С�����β������󲹳�һ��0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] == '.') {
			this->value.data.push_back(_0);
			break;
		}
		//��û��С���㣬�򲹳�С�����0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] != '.') {
			this->value.data.push_back(_point);
			this->value.data.push_back(_0);
			this->value.point++;
			break;
		}
		//������С���㣬����
		else if (this->value.data[this->value.point] == '.') {
			break;
		}
		else
		{
			this->value.point++;
		}
	}
	return;
}

High_Precision_Maths_Library::Operand_Standard::Operand_Standard(float value)
{
	stringstream ss;
	string s;
	ss << value;
	ss >> s;
	if (s[0] == '-') {
		//���Ϊ����
		this->minus = true;
		//�Ƴ�����
		s.erase(remove(s.begin(), s.end(), '-'), s.end());
	}
	else
	{
		//���Ϊ�Ǹ���
		this->minus = false;
	}
	unsigned long long max = s.length();
	for (unsigned long long i = 0; i < max; i++) {
		this->value.data.push_back(s[i]);
	}
	while (true)
	{
		//����С���㿪ͷ����ǰ�油��һ��0
		if (this->value.point == 0 && this->value.data[this->value.point] == '.') {
			this->value.data.insert(this->value.data.begin(), _0);
			break;
		}
		//����С�����β������󲹳�һ��0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] == '.') {
			this->value.data.push_back(_0);
			break;
		}
		//��û��С���㣬�򲹳�С�����0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] != '.') {
			this->value.data.push_back(_point);
			this->value.data.push_back(_0);
			this->value.point++;
			break;
		}
		//������С���㣬����
		else if (this->value.data[this->value.point] == '.') {
			break;
		}
		else
		{
			this->value.point++;
		}
	}
	return;
}

High_Precision_Maths_Library::Operand_Standard::Operand_Standard(double value)
{
	stringstream ss;
	string s;
	ss << value;
	ss >> s;
	if (s[0] == '-') {
		//���Ϊ����
		this->minus = true;
		//�Ƴ�����
		s.erase(remove(s.begin(), s.end(), '-'), s.end());
	}
	else
	{
		//���Ϊ�Ǹ���
		this->minus = false;
	}
	unsigned long long max = s.length();
	for (unsigned long long i = 0; i < max; i++) {
		this->value.data.push_back(s[i]);
	}
	while (true)
	{
		//����С���㿪ͷ����ǰ�油��һ��0
		if (this->value.point == 0 && this->value.data[this->value.point] == '.') {
			this->value.data.insert(this->value.data.begin(), _0);
			break;
		}
		//����С�����β������󲹳�һ��0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] == '.') {
			this->value.data.push_back(_0);
			break;
		}
		//��û��С���㣬�򲹳�С�����0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] != '.') {
			this->value.data.push_back(_point);
			this->value.data.push_back(_0);
			this->value.point++;
			break;
		}
		//������С���㣬����
		else if (this->value.data[this->value.point] == '.') {
			break;
		}
		else
		{
			this->value.point++;
		}
	}
	return;
}

High_Precision_Maths_Library::Operand_Standard::Operand_Standard(long double value)
{
	stringstream ss;
	string s;
	ss << value;
	ss >> s;
	if (s[0] == '-') {
		//���Ϊ����
		this->minus = true;
		//�Ƴ�����
		s.erase(remove(s.begin(), s.end(), '-'), s.end());
	}
	else
	{
		//���Ϊ�Ǹ���
		this->minus = false;
	}
	unsigned long long max = s.length();
	for (unsigned long long i = 0; i < max; i++) {
		this->value.data.push_back(s[i]);
	}
	while (true)
	{
		//����С���㿪ͷ����ǰ�油��һ��0
		if (this->value.point == 0 && this->value.data[this->value.point] == '.') {
			this->value.data.insert(this->value.data.begin(), _0);
			break;
		}
		//����С�����β������󲹳�һ��0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] == '.') {
			this->value.data.push_back(_0);
			break;
		}
		//��û��С���㣬�򲹳�С�����0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] != '.') {
			this->value.data.push_back(_point);
			this->value.data.push_back(_0);
			this->value.point++;
			break;
		}
		//������С���㣬����
		else if (this->value.data[this->value.point] == '.') {
			break;
		}
		else
		{
			this->value.point++;
		}
	}
	return;
}

High_Precision_Maths_Library::Operand_Standard::Operand_Standard(const Operand_Standard& value)
{
	this->minus = value.minus;
	this->value.data.copy((DDM<char>&)value.value.data);
	this->value.point = value.value.point;
}

High_Precision_Maths_Library::Operand_Standard::Operand_Standard(DDM<char>& value)
{
	if (value[value.begin()] == '-') {
		//���Ϊ����
		this->minus = true;
		//�Ƴ�����
		value.remove(value.begin());
	}
	else
	{
		//���Ϊ�Ǹ���
		this->minus = false;
	}
	unsigned long long max = value.size();
	for (unsigned long long i = 0; i < max; i++) {
		this->value.data.push_back(value[i]);
	}
	while (true)
	{
		//����С���㿪ͷ����ǰ�油��һ��0
		if (this->value.point == 0 && this->value.data[this->value.point] == '.') {
			this->value.data.insert(this->value.data.begin(), _0);
			break;
		}
		//����С�����β������󲹳�һ��0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] == '.') {
			this->value.data.push_back(_0);
			break;
		}
		//��û��С���㣬�򲹳�С�����0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] != '.') {
			this->value.data.push_back(_point);
			this->value.data.push_back(_0);
			this->value.point++;
			break;
		}
		//������С���㣬����
		else if (this->value.data[this->value.point] == '.') {
			break;
		}
		else
		{
			this->value.point++;
		}
	}
	return;
}

std::string High_Precision_Maths_Library::Operand_Standard::to_string()
{
	if (this->minus) {
		return ('-' + this->value.to_string());
	}
	else
	{
		return this->value.to_string();
	}
}

