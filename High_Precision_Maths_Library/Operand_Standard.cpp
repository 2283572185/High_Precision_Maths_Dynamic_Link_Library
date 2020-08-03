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
		this->data.data.push_back(s[i]);
	}
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (this->data.point == 0 && this->data.data[this->data.point] == '.') {
			this->data.data.insert(this->data.data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] == '.') {
			this->data.data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] != '.') {
			this->data.data.push_back(_point);
			this->data.data.push_back(_0);
			this->data.point++;
			break;
		}
		//若碰到小数点，返回
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
		this->data.data.push_back(s[i]);
	}
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (this->data.point == 0 && this->data.data[this->data.point] == '.') {
			this->data.data.insert(this->data.data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] == '.') {
			this->data.data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] != '.') {
			this->data.data.push_back(_point);
			this->data.data.push_back(_0);
			this->data.point++;
			break;
		}
		//若碰到小数点，返回
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
		this->data.data.push_back(s[i]);
	}
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (this->data.point == 0 && this->data.data[this->data.point] == '.') {
			this->data.data.insert(this->data.data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] == '.') {
			this->data.data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] != '.') {
			this->data.data.push_back(_point);
			this->data.data.push_back(_0);
			this->data.point++;
			break;
		}
		//若碰到小数点，返回
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
		this->data.data.push_back(s[i]);
	}
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (this->data.point == 0 && this->data.data[this->data.point] == '.') {
			this->data.data.insert(this->data.data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] == '.') {
			this->data.data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] != '.') {
			this->data.data.push_back(_point);
			this->data.data.push_back(_0);
			this->data.point++;
			break;
		}
		//若碰到小数点，返回
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
		//若以小数点开头，在前面补充一个0
		if (this->data.point == 0 && this->data.data[this->data.point] == '.') {
			this->data.data.insert(this->data.data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] == '.') {
			this->data.data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] != '.') {
			this->data.data.push_back(_point);
			this->data.data.push_back(_0);
			this->data.point++;
			break;
		}
		//若碰到小数点，返回
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
		//若以小数点开头，在前面补充一个0
		if (this->data.point == 0 && this->data.data[this->data.point] == '.') {
			this->data.data.insert(this->data.data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] == '.') {
			this->data.data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] != '.') {
			this->data.data.push_back(_point);
			this->data.data.push_back(_0);
			this->data.point++;
			break;
		}
		//若碰到小数点，返回
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
		//若以小数点开头，在前面补充一个0
		if (this->data.point == 0 && this->data.data[this->data.point] == '.') {
			this->data.data.insert(this->data.data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] == '.') {
			this->data.data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] != '.') {
			this->data.data.push_back(_point);
			this->data.data.push_back(_0);
			this->data.point++;
			break;
		}
		//若碰到小数点，返回
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
		Illegal_Data e("value不是一个数字或小数点，不能用于初始化对象");
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
		this->data.data.push_back(value[i]);
	}
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (this->data.point == 0 && this->data.data[this->data.point] == '.') {
			this->data.data.insert(this->data.data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] == '.') {
			this->data.data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] != '.') {
			this->data.data.push_back(_point);
			this->data.data.push_back(_0);
			this->data.point++;
			break;
		}
		//若碰到小数点，返回
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
		this->data.data.push_back(s[i]);
	}
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (this->data.point == 0 && this->data.data[this->data.point] == '.') {
			this->data.data.insert(this->data.data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] == '.') {
			this->data.data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] != '.') {
			this->data.data.push_back(_point);
			this->data.data.push_back(_0);
			this->data.point++;
			break;
		}
		//若碰到小数点，返回
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
		this->data.data.push_back(s[i]);
	}
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (this->data.point == 0 && this->data.data[this->data.point] == '.') {
			this->data.data.insert(this->data.data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] == '.') {
			this->data.data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] != '.') {
			this->data.data.push_back(_point);
			this->data.data.push_back(_0);
			this->data.point++;
			break;
		}
		//若碰到小数点，返回
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
		this->data.data.push_back(s[i]);
	}
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (this->data.point == 0 && this->data.data[this->data.point] == '.') {
			this->data.data.insert(this->data.data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] == '.') {
			this->data.data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] != '.') {
			this->data.data.push_back(_point);
			this->data.data.push_back(_0);
			this->data.point++;
			break;
		}
		//若碰到小数点，返回
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
		this->data.data.push_back(s[i]);
	}
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (this->data.point == 0 && this->data.data[this->data.point] == '.') {
			this->data.data.insert(this->data.data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] == '.') {
			this->data.data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] != '.') {
			this->data.data.push_back(_point);
			this->data.data.push_back(_0);
			this->data.point++;
			break;
		}
		//若碰到小数点，返回
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
		this->data.data.push_back(value[i]);
	}
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (this->data.point == 0 && this->data.data[this->data.point] == '.') {
			this->data.data.insert(this->data.data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] == '.') {
			this->data.data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->data.point == max - 1 && this->data.data[this->data.point] != '.') {
			this->data.data.push_back(_point);
			this->data.data.push_back(_0);
			this->data.point++;
			break;
		}
		//若碰到小数点，返回
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
	//符号不同，返回false
	if (this->minus != right.minus) {
		return false;
	}
	else
	{
		//绝对值相同返回true
		if (this->data == right.data) {
			return true;
		}
		//反之返回false
		else
		{
			return false;
		}
	}
}

bool High_Precision_Maths_Library::Operand_Standard::operator!=(Operand_Standard& right)
{
	//符号不同，返回true
	if (this->minus != right.minus) {
		return true;
	}
	else
	{
		//绝对值相同返回false
		if (this->data == right.data) {
			return false;
		}
		//反之返回true
		else
		{
			return true;
		}
	}
}

bool High_Precision_Maths_Library::Operand_Standard::operator>(Operand_Standard& right)
{
	//左正右负，返回true
	if (!this->minus && right.minus) {
		return true;
	}
	//左负右正，返回false
	else if (this->minus && !right.minus) {
		return false;
	}
	//同正
	else if (!this->minus) {
		//左边绝对值大，返回true
		if (this->data > right.data) {
			return true;
		}
		//反之，返回false
		else
		{
			return false;
		}
	}
	//同负
	else
	{
		//左边绝对值小，返回true
		if (this->data < right.data) {
			return true;
		}
		//反之，返回false
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
	//左正右负，返回false
	if (!this->minus && right.minus) {
		return false;
	}
	//左负右正，返回true
	else if (this->minus && !right.minus) {
		return true;
	}
	//同正
	else if (!this->minus) {
		//左边绝对值大，返回false
		if (this->data > right.data) {
			return false;
		}
		//反之，返回false
		else
		{
			return true;
		}
	}
	//同负
	else
	{
		//左边绝对值小，返回false
		if (this->data < right.data) {
			return false;
		}
		//反之，返回true
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
	//均为负数
	if (this->minus && right.minus) {
		//计算绝对值
		result.data = Addition(this->data, right.data);
		//计算符号
		result.minus = true;
	}
	//若有一者为负数
	else if (this->minus || right.minus) {
		//左边大，左减右
		if (this->data >= right.data) {
			//计算绝对值
			result.data = Subtraction(this->data, right.data);
			//大数为负，结果为负，反正为正
			if (this->minus) {
				result.minus = true;
			}
			else
			{
				result.minus = false;
			}
		}
		//右边大，右减左
		else
		{
			//计算绝对值
			result.data = Subtraction(right.data, this->data);
			//两数相同，结果为正
			if (this->data == right.data) {
				result.minus = true;
			}
			//右边大
			else
			{
				//大数为负，结果为负，反正为正
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
	//均为正数
	else
	{
		//计算绝对值
		result.data = Addition(this->data, right.data);
		//计算符号
		result.minus = false;
	}
	return result;
}

Operand_Standard& High_Precision_Maths_Library::Operand_Standard::operator+=(Operand_Standard& right)
{
	//均为负数
	if (this->minus && right.minus) {
		//计算绝对值
		this->data = Addition(this->data, right.data);
		//计算符号
		this->minus = true;
	}
	//若有一者为负数
	else if (this->minus || right.minus) {
		//左边大，左减右
		if (this->data >= right.data) {
			//计算绝对值
			this->data = Subtraction(this->data, right.data);
			//大数为负，结果为负，反正为正
			if (this->minus) {
				this->minus = true;
			}
			else
			{
				this->minus = false;
			}
		}
		//右边大，右减左
		else
		{
			//计算绝对值
			this->data = Subtraction(right.data, this->data);
			//两数相同，结果为正
			if (this->data == right.data) {
				this->minus = true;
			}
			//右边大
			else
			{
				//大数为负，结果为负，反正为正
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
	//均为正数
	else
	{
		//计算绝对值
		this->data = Addition(this->data, right.data);
		//计算符号
		this->minus = false;
	}
	return *this;
}

Operand_Standard& High_Precision_Maths_Library::Operand_Standard::operator++()
{
	Operand_Standard right('1');
	//若有一者为负数
	if (this->minus || right.minus) {
		//左边大，左减右
		if (this->data > right.data) {
			//计算绝对值
			this->data = Subtraction(this->data, right.data);
			//大数为负，结果为负，反正为正
			if (this->minus) {
				this->minus = true;
			}
			else
			{
				this->minus = false;
			}
		}
		//右边大或等于左边，右减左
		else
		{
			//计算绝对值
			this->data = Subtraction(right.data, this->data);
			//两数相同，结果为正
			if (this->data == right.data) {
				this->minus = true;
			}
			//右边大
			else
			{
				//大数为负，结果为负，反正为正
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
	//均为正数
	else
	{
		//计算绝对值
		this->data = Addition(this->data, right.data);
		//计算符号
		this->minus = false;
	}
	return *this;
}

Operand_Standard High_Precision_Maths_Library::Operand_Standard::operator++(int)
{
	Operand_Standard right('1');
	//若有一者为负数
	if (this->minus || right.minus) {
		//左边大，左减右
		if (this->data > right.data) {
			//计算绝对值
			this->data = Subtraction(this->data, right.data);
			//大数为负，结果为负，反正为正
			if (this->minus) {
				this->minus = true;
			}
			else
			{
				this->minus = false;
			}
		}
		//右边大或等于左边，右减左
		else
		{
			//计算绝对值
			this->data = Subtraction(right.data, this->data);
			//两数相同，结果为正
			if (this->data == right.data) {
				this->minus = true;
			}
			//右边大
			else
			{
				//大数为负，结果为负，反正为正
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
	//均为正数
	else
	{
		//计算绝对值
		this->data = Addition(this->data, right.data);
		//计算符号
		this->minus = false;
	}
	return *this;
}

Operand_Standard High_Precision_Maths_Library::Operand_Standard::operator-(Operand_Standard& right)
{
	Operand_Standard result;
	//均为负数
	if (this->minus && right.minus) {
		//左边的绝对值大，绝对值大减小，结果为负
		if (this->data > right.data) {
			result.data = Subtraction(this->data, right.data);
			result.minus = true;
		}
		//右边边的绝对值大，绝对值大减小，结果为正
		else
		{
			result.data = Subtraction(right.data, this->data);
			result.minus = false;
		}
	}
	//若有一者为负数
	else if (this->minus || right.minus) {
		//左边为负，绝对值相加，结果为负
		if (this->minus) {
			result.data = Addition(right.data, this->data);
			result.minus = true;
		}
		//右边为负,绝对值相加，结果为正
		else
		{
			result.data = Addition(right.data, this->data);
			result.minus = false;
		}
	}
	//均为正数
	else
	{
		//左大于右，左减右，结果为正
		if (this->data >= right.data) {
			result.data = Subtraction(this->data, right.data);
			result.minus = false;
		}
		//反之，右减左，结果为负
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
	//均为负数
	if (this->minus && right.minus) {
		//左边的绝对值大，绝对值大减小，结果为负
		if (this->data > right.data) {
			this->data = Subtraction(this->data, right.data);
			this->minus = true;
		}
		//右边边的绝对值大，绝对值大减小，结果为正
		else
		{
			this->data = Subtraction(right.data, this->data);
			this->minus = false;
		}
	}
	//若有一者为负数
	else if (this->minus || right.minus) {
		//左边为负，绝对值相加，结果为负
		if (this->minus) {
			this->data = Addition(right.data, this->data);
			this->minus = true;
		}
		//右边为负,绝对值相加，结果为正
		else
		{
			this->data = Addition(right.data, this->data);
			this->minus = false;
		}
	}
	//均为正数
	else
	{
		//左大于右，左减右，结果为正
		if (this->data >= right.data) {
			this->data = Subtraction(this->data, right.data);
			this->minus = false;
		}
		//反之，右减左，结果为负
		else
		{
			this->data = Subtraction(right.data, this->data);
			this->minus = true;
		}
	}
	return *this;
}

