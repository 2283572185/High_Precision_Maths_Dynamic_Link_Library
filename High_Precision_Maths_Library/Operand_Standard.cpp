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
		//标记为负数
		this->minus = true;
		//移除负号
		s.erase(remove(s.begin(), s.end(), '-'), s.end());
	}
	else
	{
		//标记为非负数
		this->minus = false;
	}
	unsigned long long max = s.length();
	for (unsigned long long i = 0; i < max; i++) {
		this->value.data.push_back(s[i]);
	}
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (this->value.point == 0 && this->value.data[this->value.point] == '.') {
			this->value.data.insert(this->value.data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] == '.') {
			this->value.data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] != '.') {
			this->value.data.push_back(_point);
			this->value.data.push_back(_0);
			this->value.point++;
			break;
		}
		//若碰到小数点，返回
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
		//标记为负数
		this->minus = true;
		//移除负号
		s.erase(remove(s.begin(), s.end(), '-'), s.end());
	}
	else
	{
		//标记为非负数
		this->minus = false;
	}
	unsigned long long max = s.length();
	for (unsigned long long i = 0; i < max; i++) {
		this->value.data.push_back(s[i]);
	}
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (this->value.point == 0 && this->value.data[this->value.point] == '.') {
			this->value.data.insert(this->value.data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] == '.') {
			this->value.data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] != '.') {
			this->value.data.push_back(_point);
			this->value.data.push_back(_0);
			this->value.point++;
			break;
		}
		//若碰到小数点，返回
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
		//标记为负数
		this->minus = true;
		//移除负号
		s.erase(remove(s.begin(), s.end(), '-'), s.end());
	}
	else
	{
		//标记为非负数
		this->minus = false;
	}
	unsigned long long max = s.length();
	for (unsigned long long i = 0; i < max; i++) {
		this->value.data.push_back(s[i]);
	}
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (this->value.point == 0 && this->value.data[this->value.point] == '.') {
			this->value.data.insert(this->value.data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] == '.') {
			this->value.data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] != '.') {
			this->value.data.push_back(_point);
			this->value.data.push_back(_0);
			this->value.point++;
			break;
		}
		//若碰到小数点，返回
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
		//标记为负数
		this->minus = true;
		//移除负号
		s.erase(remove(s.begin(), s.end(), '-'), s.end());
	}
	else
	{
		//标记为非负数
		this->minus = false;
	}
	unsigned long long max = s.length();
	for (unsigned long long i = 0; i < max; i++) {
		this->value.data.push_back(s[i]);
	}
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (this->value.point == 0 && this->value.data[this->value.point] == '.') {
			this->value.data.insert(this->value.data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] == '.') {
			this->value.data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] != '.') {
			this->value.data.push_back(_point);
			this->value.data.push_back(_0);
			this->value.point++;
			break;
		}
		//若碰到小数点，返回
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
		//若以小数点开头，在前面补充一个0
		if (this->value.point == 0 && this->value.data[this->value.point] == '.') {
			this->value.data.insert(this->value.data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] == '.') {
			this->value.data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] != '.') {
			this->value.data.push_back(_point);
			this->value.data.push_back(_0);
			this->value.point++;
			break;
		}
		//若碰到小数点，返回
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
		//若以小数点开头，在前面补充一个0
		if (this->value.point == 0 && this->value.data[this->value.point] == '.') {
			this->value.data.insert(this->value.data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] == '.') {
			this->value.data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] != '.') {
			this->value.data.push_back(_point);
			this->value.data.push_back(_0);
			this->value.point++;
			break;
		}
		//若碰到小数点，返回
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
		//若以小数点开头，在前面补充一个0
		if (this->value.point == 0 && this->value.data[this->value.point] == '.') {
			this->value.data.insert(this->value.data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] == '.') {
			this->value.data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] != '.') {
			this->value.data.push_back(_point);
			this->value.data.push_back(_0);
			this->value.point++;
			break;
		}
		//若碰到小数点，返回
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
		Illegal_Data e("value不是一个数字或小数点，不能用于初始化对象");
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
		//标记为负数
		this->minus = true;
		//移除负号
		value.erase(remove(value.begin(), value.end(), '-'), value.end());
	}
	else
	{
		//标记为非负数
		this->minus = false;
	}
	unsigned long long max = value.length();
	for (unsigned long long i = 0; i < max; i++) {
		this->value.data.push_back(value[i]);
	}
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (this->value.point == 0 && this->value.data[this->value.point] == '.') {
			this->value.data.insert(this->value.data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] == '.') {
			this->value.data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] != '.') {
			this->value.data.push_back(_point);
			this->value.data.push_back(_0);
			this->value.point++;
			break;
		}
		//若碰到小数点，返回
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
		//标记为负数
		this->minus = true;
		//移除负号
		s.erase(remove(s.begin(), s.end(), '-'), s.end());
	}
	else
	{
		//标记为非负数
		this->minus = false;
	}
	unsigned long long max = s.length();
	for (unsigned long long i = 0; i < max; i++) {
		this->value.data.push_back(s[i]);
	}
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (this->value.point == 0 && this->value.data[this->value.point] == '.') {
			this->value.data.insert(this->value.data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] == '.') {
			this->value.data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] != '.') {
			this->value.data.push_back(_point);
			this->value.data.push_back(_0);
			this->value.point++;
			break;
		}
		//若碰到小数点，返回
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
		//标记为负数
		this->minus = true;
		//移除负号
		s.erase(remove(s.begin(), s.end(), '-'), s.end());
	}
	else
	{
		//标记为非负数
		this->minus = false;
	}
	unsigned long long max = s.length();
	for (unsigned long long i = 0; i < max; i++) {
		this->value.data.push_back(s[i]);
	}
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (this->value.point == 0 && this->value.data[this->value.point] == '.') {
			this->value.data.insert(this->value.data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] == '.') {
			this->value.data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] != '.') {
			this->value.data.push_back(_point);
			this->value.data.push_back(_0);
			this->value.point++;
			break;
		}
		//若碰到小数点，返回
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
		//标记为负数
		this->minus = true;
		//移除负号
		s.erase(remove(s.begin(), s.end(), '-'), s.end());
	}
	else
	{
		//标记为非负数
		this->minus = false;
	}
	unsigned long long max = s.length();
	for (unsigned long long i = 0; i < max; i++) {
		this->value.data.push_back(s[i]);
	}
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (this->value.point == 0 && this->value.data[this->value.point] == '.') {
			this->value.data.insert(this->value.data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] == '.') {
			this->value.data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] != '.') {
			this->value.data.push_back(_point);
			this->value.data.push_back(_0);
			this->value.point++;
			break;
		}
		//若碰到小数点，返回
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
		//标记为负数
		this->minus = true;
		//移除负号
		s.erase(remove(s.begin(), s.end(), '-'), s.end());
	}
	else
	{
		//标记为非负数
		this->minus = false;
	}
	unsigned long long max = s.length();
	for (unsigned long long i = 0; i < max; i++) {
		this->value.data.push_back(s[i]);
	}
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (this->value.point == 0 && this->value.data[this->value.point] == '.') {
			this->value.data.insert(this->value.data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] == '.') {
			this->value.data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] != '.') {
			this->value.data.push_back(_point);
			this->value.data.push_back(_0);
			this->value.point++;
			break;
		}
		//若碰到小数点，返回
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
		//标记为负数
		this->minus = true;
		//移除负号
		value.remove(value.begin());
	}
	else
	{
		//标记为非负数
		this->minus = false;
	}
	unsigned long long max = value.size();
	for (unsigned long long i = 0; i < max; i++) {
		this->value.data.push_back(value[i]);
	}
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (this->value.point == 0 && this->value.data[this->value.point] == '.') {
			this->value.data.insert(this->value.data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] == '.') {
			this->value.data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->value.point == max - 1 && this->value.data[this->value.point] != '.') {
			this->value.data.push_back(_point);
			this->value.data.push_back(_0);
			this->value.point++;
			break;
		}
		//若碰到小数点，返回
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

