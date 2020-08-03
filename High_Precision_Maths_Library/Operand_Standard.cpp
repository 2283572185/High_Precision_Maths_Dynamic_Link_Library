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
		this->data.data.push_back(s[i]);
	}
	while (true)
	{
		//����С���㿪ͷ����ǰ�油��һ��0
		if (this->data.point == 0 && this->data.data[this->data.point] == '.') {
			this->data.data.insert(this->data.data.begin(), _0);
			break;
		}
		//����С�����β������󲹳�һ��0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] == '.') {
			this->data.data.push_back(_0);
			break;
		}
		//��û��С���㣬�򲹳�С�����0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] != '.') {
			this->data.data.push_back(_point);
			this->data.data.push_back(_0);
			this->data.point++;
			break;
		}
		//������С���㣬����
		else if (this->data.data[this->data.point] == '.') {
			break;
		}
		else
		{
			this->data.point++;
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
		this->data.data.push_back(s[i]);
	}
	while (true)
	{
		//����С���㿪ͷ����ǰ�油��һ��0
		if (this->data.point == 0 && this->data.data[this->data.point] == '.') {
			this->data.data.insert(this->data.data.begin(), _0);
			break;
		}
		//����С�����β������󲹳�һ��0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] == '.') {
			this->data.data.push_back(_0);
			break;
		}
		//��û��С���㣬�򲹳�С�����0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] != '.') {
			this->data.data.push_back(_point);
			this->data.data.push_back(_0);
			this->data.point++;
			break;
		}
		//������С���㣬����
		else if (this->data.data[this->data.point] == '.') {
			break;
		}
		else
		{
			this->data.point++;
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
		this->data.data.push_back(s[i]);
	}
	while (true)
	{
		//����С���㿪ͷ����ǰ�油��һ��0
		if (this->data.point == 0 && this->data.data[this->data.point] == '.') {
			this->data.data.insert(this->data.data.begin(), _0);
			break;
		}
		//����С�����β������󲹳�һ��0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] == '.') {
			this->data.data.push_back(_0);
			break;
		}
		//��û��С���㣬�򲹳�С�����0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] != '.') {
			this->data.data.push_back(_point);
			this->data.data.push_back(_0);
			this->data.point++;
			break;
		}
		//������С���㣬����
		else if (this->data.data[this->data.point] == '.') {
			break;
		}
		else
		{
			this->data.point++;
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
		this->data.data.push_back(s[i]);
	}
	while (true)
	{
		//����С���㿪ͷ����ǰ�油��һ��0
		if (this->data.point == 0 && this->data.data[this->data.point] == '.') {
			this->data.data.insert(this->data.data.begin(), _0);
			break;
		}
		//����С�����β������󲹳�һ��0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] == '.') {
			this->data.data.push_back(_0);
			break;
		}
		//��û��С���㣬�򲹳�С�����0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] != '.') {
			this->data.data.push_back(_point);
			this->data.data.push_back(_0);
			this->data.point++;
			break;
		}
		//������С���㣬����
		else if (this->data.data[this->data.point] == '.') {
			break;
		}
		else
		{
			this->data.point++;
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
		this->data.data.push_back(s[i]);
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
		this->data.data.push_back(s[i]);
	}
	this->minus = false;
	while (true)
	{
		//����С���㿪ͷ����ǰ�油��һ��0
		if (this->data.point == 0 && this->data.data[this->data.point] == '.') {
			this->data.data.insert(this->data.data.begin(), _0);
			break;
		}
		//����С�����β������󲹳�һ��0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] == '.') {
			this->data.data.push_back(_0);
			break;
		}
		//��û��С���㣬�򲹳�С�����0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] != '.') {
			this->data.data.push_back(_point);
			this->data.data.push_back(_0);
			this->data.point++;
			break;
		}
		//������С���㣬����
		else if (this->data.data[this->data.point] == '.') {
			break;
		}
		else
		{
			this->data.point++;
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
		this->data.data.push_back(s[i]);
	}
	this->minus = false;
	while (true)
	{
		//����С���㿪ͷ����ǰ�油��һ��0
		if (this->data.point == 0 && this->data.data[this->data.point] == '.') {
			this->data.data.insert(this->data.data.begin(), _0);
			break;
		}
		//����С�����β������󲹳�һ��0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] == '.') {
			this->data.data.push_back(_0);
			break;
		}
		//��û��С���㣬�򲹳�С�����0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] != '.') {
			this->data.data.push_back(_point);
			this->data.data.push_back(_0);
			this->data.point++;
			break;
		}
		//������С���㣬����
		else if (this->data.data[this->data.point] == '.') {
			break;
		}
		else
		{
			this->data.point++;
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
		this->data.data.push_back(s[i]);
	}
	this->minus = false;
	while (true)
	{
		//����С���㿪ͷ����ǰ�油��һ��0
		if (this->data.point == 0 && this->data.data[this->data.point] == '.') {
			this->data.data.insert(this->data.data.begin(), _0);
			break;
		}
		//����С�����β������󲹳�һ��0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] == '.') {
			this->data.data.push_back(_0);
			break;
		}
		//��û��С���㣬�򲹳�С�����0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] != '.') {
			this->data.data.push_back(_point);
			this->data.data.push_back(_0);
			this->data.point++;
			break;
		}
		//������С���㣬����
		else if (this->data.data[this->data.point] == '.') {
			break;
		}
		else
		{
			this->data.point++;
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
	this->data.data.push_back(value);
	if (value != '.') {
		this->data.data.push_back(_point);
		this->data.data.push_back(_0);
		this->data.point = 1;
	}
	else
	{
		this->data.data.insert(this->data.data.begin(), _0);
		this->data.data.push_back(_0);
		this->data.point = 1;
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
		this->data.data.push_back(value[i]);
	}
	while (true)
	{
		//����С���㿪ͷ����ǰ�油��һ��0
		if (this->data.point == 0 && this->data.data[this->data.point] == '.') {
			this->data.data.insert(this->data.data.begin(), _0);
			break;
		}
		//����С�����β������󲹳�һ��0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] == '.') {
			this->data.data.push_back(_0);
			break;
		}
		//��û��С���㣬�򲹳�С�����0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] != '.') {
			this->data.data.push_back(_point);
			this->data.data.push_back(_0);
			this->data.point++;
			break;
		}
		//������С���㣬����
		else if (this->data.data[this->data.point] == '.') {
			break;
		}
		else
		{
			this->data.point++;
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
		this->data.data.push_back(s[i]);
	}
	while (true)
	{
		//����С���㿪ͷ����ǰ�油��һ��0
		if (this->data.point == 0 && this->data.data[this->data.point] == '.') {
			this->data.data.insert(this->data.data.begin(), _0);
			break;
		}
		//����С�����β������󲹳�һ��0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] == '.') {
			this->data.data.push_back(_0);
			break;
		}
		//��û��С���㣬�򲹳�С�����0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] != '.') {
			this->data.data.push_back(_point);
			this->data.data.push_back(_0);
			this->data.point++;
			break;
		}
		//������С���㣬����
		else if (this->data.data[this->data.point] == '.') {
			break;
		}
		else
		{
			this->data.point++;
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
		this->data.data.push_back(s[i]);
	}
	while (true)
	{
		//����С���㿪ͷ����ǰ�油��һ��0
		if (this->data.point == 0 && this->data.data[this->data.point] == '.') {
			this->data.data.insert(this->data.data.begin(), _0);
			break;
		}
		//����С�����β������󲹳�һ��0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] == '.') {
			this->data.data.push_back(_0);
			break;
		}
		//��û��С���㣬�򲹳�С�����0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] != '.') {
			this->data.data.push_back(_point);
			this->data.data.push_back(_0);
			this->data.point++;
			break;
		}
		//������С���㣬����
		else if (this->data.data[this->data.point] == '.') {
			break;
		}
		else
		{
			this->data.point++;
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
		this->data.data.push_back(s[i]);
	}
	while (true)
	{
		//����С���㿪ͷ����ǰ�油��һ��0
		if (this->data.point == 0 && this->data.data[this->data.point] == '.') {
			this->data.data.insert(this->data.data.begin(), _0);
			break;
		}
		//����С�����β������󲹳�һ��0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] == '.') {
			this->data.data.push_back(_0);
			break;
		}
		//��û��С���㣬�򲹳�С�����0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] != '.') {
			this->data.data.push_back(_point);
			this->data.data.push_back(_0);
			this->data.point++;
			break;
		}
		//������С���㣬����
		else if (this->data.data[this->data.point] == '.') {
			break;
		}
		else
		{
			this->data.point++;
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
		this->data.data.push_back(s[i]);
	}
	while (true)
	{
		//����С���㿪ͷ����ǰ�油��һ��0
		if (this->data.point == 0 && this->data.data[this->data.point] == '.') {
			this->data.data.insert(this->data.data.begin(), _0);
			break;
		}
		//����С�����β������󲹳�һ��0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] == '.') {
			this->data.data.push_back(_0);
			break;
		}
		//��û��С���㣬�򲹳�С�����0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] != '.') {
			this->data.data.push_back(_point);
			this->data.data.push_back(_0);
			this->data.point++;
			break;
		}
		//������С���㣬����
		else if (this->data.data[this->data.point] == '.') {
			break;
		}
		else
		{
			this->data.point++;
		}
	}
	return;
}

High_Precision_Maths_Library::Operand_Standard::Operand_Standard(const Operand_Standard& value)
{
	this->minus = value.minus;
	this->data.data.copy((DDM<char>&)value.data.data);
	this->data.point = value.data.point;
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
		this->data.data.push_back(value[i]);
	}
	while (true)
	{
		//����С���㿪ͷ����ǰ�油��һ��0
		if (this->data.point == 0 && this->data.data[this->data.point] == '.') {
			this->data.data.insert(this->data.data.begin(), _0);
			break;
		}
		//����С�����β������󲹳�һ��0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] == '.') {
			this->data.data.push_back(_0);
			break;
		}
		//��û��С���㣬�򲹳�С�����0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] != '.') {
			this->data.data.push_back(_point);
			this->data.data.push_back(_0);
			this->data.point++;
			break;
		}
		//������С���㣬����
		else if (this->data.data[this->data.point] == '.') {
			break;
		}
		else
		{
			this->data.point++;
		}
	}
	return;
}

std::string High_Precision_Maths_Library::Operand_Standard::to_string()
{
	if (this->minus) {
		return ('-' + this->data.to_string());
	}
	else
	{
		return this->data.to_string();
	}
}

bool High_Precision_Maths_Library::Operand_Standard::operator==(Operand_Standard& right)
{
	//���Ų�ͬ������false
	if (this->minus != right.minus) {
		return false;
	}
	else
	{
		//����ֵ��ͬ����true
		if (this->data == right.data) {
			return true;
		}
		//��֮����false
		else
		{
			return false;
		}
	}
}

bool High_Precision_Maths_Library::Operand_Standard::operator!=(Operand_Standard& right)
{
	//���Ų�ͬ������true
	if (this->minus != right.minus) {
		return true;
	}
	else
	{
		//����ֵ��ͬ����false
		if (this->data == right.data) {
			return false;
		}
		//��֮����true
		else
		{
			return true;
		}
	}
}

bool High_Precision_Maths_Library::Operand_Standard::operator>(Operand_Standard& right)
{
	//�����Ҹ�������true
	if (!this->minus && right.minus) {
		return true;
	}
	//������������false
	else if (this->minus && !right.minus) {
		return false;
	}
	//ͬ��
	else if (!this->minus) {
		//��߾���ֵ�󣬷���true
		if (this->data > right.data) {
			return true;
		}
		//��֮������false
		else
		{
			return false;
		}
	}
	//ͬ��
	else
	{
		//��߾���ֵС������true
		if (this->data < right.data) {
			return true;
		}
		//��֮������false
		else
		{
			return false;
		}
	}
}

bool High_Precision_Maths_Library::Operand_Standard::operator<=(Operand_Standard& right)
{
	return !(*this > right);
}

bool High_Precision_Maths_Library::Operand_Standard::operator<(Operand_Standard& right)
{
	//�����Ҹ�������false
	if (!this->minus && right.minus) {
		return false;
	}
	//������������true
	else if (this->minus && !right.minus) {
		return true;
	}
	//ͬ��
	else if (!this->minus) {
		//��߾���ֵ�󣬷���false
		if (this->data > right.data) {
			return false;
		}
		//��֮������false
		else
		{
			return true;
		}
	}
	//ͬ��
	else
	{
		//��߾���ֵС������false
		if (this->data < right.data) {
			return false;
		}
		//��֮������true
		else
		{
			return true;
		}
	}
}

bool High_Precision_Maths_Library::Operand_Standard::operator>=(Operand_Standard& right)
{
	return !(*this < right);
}

Operand_Standard High_Precision_Maths_Library::Operand_Standard::operator+(Operand_Standard& right)
{
	Operand_Standard result;
	//��Ϊ����
	if (this->minus && right.minus) {
		//�������ֵ
		result.data = Addition(this->data, right.data);
		//�������
		result.minus = true;
	}
	//����һ��Ϊ����
	else if (this->minus || right.minus) {
		//��ߴ������
		if (this->data >= right.data) {
			//�������ֵ
			result.data = Subtraction(this->data, right.data);
			//����Ϊ�������Ϊ��������Ϊ��
			if (this->minus) {
				result.minus = true;
			}
			else
			{
				result.minus = false;
			}
		}
		//�ұߴ��Ҽ���
		else
		{
			//�������ֵ
			result.data = Subtraction(right.data, this->data);
			//������ͬ�����Ϊ��
			if (this->data == right.data) {
				result.minus = true;
			}
			//�ұߴ�
			else
			{
				//����Ϊ�������Ϊ��������Ϊ��
				if (this->minus) {
					result.minus = false;
				}
				else
				{
					result.minus = true;
				}
			}
		}
	}
	//��Ϊ����
	else
	{
		//�������ֵ
		result.data = Addition(this->data, right.data);
		//�������
		result.minus = false;
	}
	return result;
}

Operand_Standard& High_Precision_Maths_Library::Operand_Standard::operator+=(Operand_Standard& right)
{
	//��Ϊ����
	if (this->minus && right.minus) {
		//�������ֵ
		this->data = Addition(this->data, right.data);
		//�������
		this->minus = true;
	}
	//����һ��Ϊ����
	else if (this->minus || right.minus) {
		//��ߴ������
		if (this->data >= right.data) {
			//�������ֵ
			this->data = Subtraction(this->data, right.data);
			//����Ϊ�������Ϊ��������Ϊ��
			if (this->minus) {
				this->minus = true;
			}
			else
			{
				this->minus = false;
			}
		}
		//�ұߴ��Ҽ���
		else
		{
			//�������ֵ
			this->data = Subtraction(right.data, this->data);
			//������ͬ�����Ϊ��
			if (this->data == right.data) {
				this->minus = true;
			}
			//�ұߴ�
			else
			{
				//����Ϊ�������Ϊ��������Ϊ��
				if (this->minus) {
					this->minus = false;
				}
				else
				{
					this->minus = true;
				}
			}
		}
	}
	//��Ϊ����
	else
	{
		//�������ֵ
		this->data = Addition(this->data, right.data);
		//�������
		this->minus = false;
	}
	return *this;
}

Operand_Standard& High_Precision_Maths_Library::Operand_Standard::operator++()
{
	Operand_Standard right('1');
	//����һ��Ϊ����
	if (this->minus || right.minus) {
		//��ߴ������
		if (this->data > right.data) {
			//�������ֵ
			this->data = Subtraction(this->data, right.data);
			//����Ϊ�������Ϊ��������Ϊ��
			if (this->minus) {
				this->minus = true;
			}
			else
			{
				this->minus = false;
			}
		}
		//�ұߴ�������ߣ��Ҽ���
		else
		{
			//�������ֵ
			this->data = Subtraction(right.data, this->data);
			//������ͬ�����Ϊ��
			if (this->data == right.data) {
				this->minus = true;
			}
			//�ұߴ�
			else
			{
				//����Ϊ�������Ϊ��������Ϊ��
				if (this->minus) {
					this->minus = false;
				}
				else
				{
					this->minus = true;
				}
			}
		}
	}
	//��Ϊ����
	else
	{
		//�������ֵ
		this->data = Addition(this->data, right.data);
		//�������
		this->minus = false;
	}
	return *this;
}

Operand_Standard High_Precision_Maths_Library::Operand_Standard::operator++(int)
{
	Operand_Standard right('1');
	//����һ��Ϊ����
	if (this->minus || right.minus) {
		//��ߴ������
		if (this->data > right.data) {
			//�������ֵ
			this->data = Subtraction(this->data, right.data);
			//����Ϊ�������Ϊ��������Ϊ��
			if (this->minus) {
				this->minus = true;
			}
			else
			{
				this->minus = false;
			}
		}
		//�ұߴ�������ߣ��Ҽ���
		else
		{
			//�������ֵ
			this->data = Subtraction(right.data, this->data);
			//������ͬ�����Ϊ��
			if (this->data == right.data) {
				this->minus = true;
			}
			//�ұߴ�
			else
			{
				//����Ϊ�������Ϊ��������Ϊ��
				if (this->minus) {
					this->minus = false;
				}
				else
				{
					this->minus = true;
				}
			}
		}
	}
	//��Ϊ����
	else
	{
		//�������ֵ
		this->data = Addition(this->data, right.data);
		//�������
		this->minus = false;
	}
	return *this;
}

Operand_Standard High_Precision_Maths_Library::Operand_Standard::operator-(Operand_Standard& right)
{
	Operand_Standard result;
	//��Ϊ����
	if (this->minus && right.minus) {
		//��ߵľ���ֵ�󣬾���ֵ���С�����Ϊ��
		if (this->data > right.data) {
			result.data = Subtraction(this->data, right.data);
			result.minus = true;
		}
		//�ұ߱ߵľ���ֵ�󣬾���ֵ���С�����Ϊ��
		else
		{
			result.data = Subtraction(right.data, this->data);
			result.minus = false;
		}
	}
	//����һ��Ϊ����
	else if (this->minus || right.minus) {
		//���Ϊ��������ֵ��ӣ����Ϊ��
		if (this->minus) {
			result.data = Addition(right.data, this->data);
			result.minus = true;
		}
		//�ұ�Ϊ��,����ֵ��ӣ����Ϊ��
		else
		{
			result.data = Addition(right.data, this->data);
			result.minus = false;
		}
	}
	//��Ϊ����
	else
	{
		//������ң�����ң����Ϊ��
		if (this->data >= right.data) {
			result.data = Subtraction(this->data, right.data);
			result.minus = false;
		}
		//��֮���Ҽ��󣬽��Ϊ��
		else
		{
			result.data = Subtraction(right.data,this->data);
			result.minus = true;
		}
	}
	return result;
}

Operand_Standard& High_Precision_Maths_Library::Operand_Standard::operator-=(Operand_Standard& right)
{
	//��Ϊ����
	if (this->minus && right.minus) {
		//��ߵľ���ֵ�󣬾���ֵ���С�����Ϊ��
		if (this->data > right.data) {
			this->data = Subtraction(this->data, right.data);
			this->minus = true;
		}
		//�ұ߱ߵľ���ֵ�󣬾���ֵ���С�����Ϊ��
		else
		{
			this->data = Subtraction(right.data, this->data);
			this->minus = false;
		}
	}
	//����һ��Ϊ����
	else if (this->minus || right.minus) {
		//���Ϊ��������ֵ��ӣ����Ϊ��
		if (this->minus) {
			this->data = Addition(right.data, this->data);
			this->minus = true;
		}
		//�ұ�Ϊ��,����ֵ��ӣ����Ϊ��
		else
		{
			this->data = Addition(right.data, this->data);
			this->minus = false;
		}
	}
	//��Ϊ����
	else
	{
		//������ң�����ң����Ϊ��
		if (this->data >= right.data) {
			this->data = Subtraction(this->data, right.data);
			this->minus = false;
		}
		//��֮���Ҽ��󣬽��Ϊ��
		else
		{
			this->data = Subtraction(right.data, this->data);
			this->minus = true;
		}
	}
	return *this;
}

