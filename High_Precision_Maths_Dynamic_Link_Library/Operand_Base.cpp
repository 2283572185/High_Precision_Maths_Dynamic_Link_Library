#include "Operand_Base.h"
using namespace High_Precision_Maths_Library;
char _0 = '0';
char _point = '.';

class High_Precision_Maths_Library::Operand_Base;
class High_Precision_Maths_Library::Result;
class High_Precision_Maths_Library::OperandStream_Base;

High_Precision_Maths_Library::Operand_Base::Operand_Base()
{
	this->point = 0;
	return;
}

High_Precision_Maths_Library::Operand_Base::Operand_Base(int value)
{
	std::stringstream ss;
	std::string s;
	ss << value;
	ss >> s;
	unsigned long long i, max;
	max = s.length();
	for (i = 0; i < max; i++) {
		this->data.push_back(s[i]);
	}
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (this->point == 0 && this->data[point] == '.') {
			this->data.insert(this->data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->point == max - 1 && this->data[point] == '.') {
			this->data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->point == max - 1 && this->data[point] != '.') {
			this->data.push_back(_point);
			this->data.push_back(_0);
			this->point++;
			break;
		}
		//若碰到小数点，返回
		else if (this->data[point] == '.') {
			break;
		}
		else
		{
			this->point++;
		}
	}
	return;
}

High_Precision_Maths_Library::Operand_Base::Operand_Base(short value)
{
	std::stringstream ss;
	std::string s;
	ss << value;
	ss >> s;
	unsigned long long i, max;
	max = s.length();
	for (i = 0; i < max; i++) {
		this->data.push_back(s[i]);
	}
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (this->point == 0 && this->data[point] == '.') {
			this->data.insert(this->data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->point == max - 1 && this->data[point] == '.') {
			this->data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->point == max - 1 && this->data[point] != '.') {
			this->data.push_back(_point);
			this->data.push_back(_0);
			this->point++;
			break;
		}
		//若碰到小数点，返回
		else if (this->data[point] == '.') {
			break;
		}
		else
		{
			this->point++;
		}
	}
	return;
}

High_Precision_Maths_Library::Operand_Base::Operand_Base(long value)
{
	std::stringstream ss;
	std::string s;
	ss << value;
	ss >> s;
	unsigned long long i, max;
	max = s.length();
	for (i = 0; i < max; i++) {
		this->data.push_back(s[i]);
	}
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (this->point == 0 && this->data[point] == '.') {
			this->data.insert(this->data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->point == max - 1 && this->data[point] == '.') {
			this->data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->point == max - 1 && this->data[point] != '.') {
			this->data.push_back(_point);
			this->data.push_back(_0);
			this->point++;
			break;
		}
		//若碰到小数点，返回
		else if (this->data[point] == '.') {
			break;
		}
		else
		{
			this->point++;
		}
	}
	return;
}

High_Precision_Maths_Library::Operand_Base::Operand_Base(long long value)
{
	std::stringstream ss;
	std::string s;
	ss << value;
	ss >> s;
	unsigned long long i, max;
	max = s.length();
	for (i = 0; i < max; i++) {
		this->data.push_back(s[i]);
	}
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (this->point == 0 && this->data[point] == '.') {
			this->data.insert(this->data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->point == max - 1 && this->data[point] == '.') {
			this->data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->point == max - 1 && this->data[point] != '.') {
			this->data.push_back(_point);
			this->data.push_back(_0);
			this->point++;
			break;
		}
		//若碰到小数点，返回
		else if (this->data[point] == '.') {
			break;
		}
		else
		{
			this->point++;
		}
	}
	return;
}

High_Precision_Maths_Library::Operand_Base::Operand_Base(unsigned int value)
{
	std::stringstream ss;
	std::string s;
	ss << value;
	ss >> s;
	unsigned long long i, max;
	max = s.length();
	for (i = 0; i < max; i++) {
		this->data.push_back(s[i]);
	}
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (this->point == 0 && this->data[point] == '.') {
			this->data.insert(this->data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->point == max - 1 && this->data[point] == '.') {
			this->data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->point == max - 1 && this->data[point] != '.') {
			this->data.push_back(_point);
			this->data.push_back(_0);
			this->point++;
			break;
		}
		//若碰到小数点，返回
		else if (this->data[point] == '.') {
			break;
		}
		else
		{
			this->point++;
		}
	}
	return;
}

High_Precision_Maths_Library::Operand_Base::Operand_Base(unsigned short value)
{
	std::stringstream ss;
	std::string s;
	ss << value;
	ss >> s;
	unsigned long long i, max;
	max = s.length();
	for (i = 0; i < max; i++) {
		this->data.push_back(s[i]);
	}
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (this->point == 0 && this->data[point] == '.') {
			this->data.insert(this->data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->point == max - 1 && this->data[point] == '.') {
			this->data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->point == max - 1 && this->data[point] != '.') {
			this->data.push_back(_point);
			this->data.push_back(_0);
			this->point++;
			break;
		}
		//若碰到小数点，返回
		else if (this->data[point] == '.') {
			break;
		}
		else
		{
			this->point++;
		}
	}
	return;
}

High_Precision_Maths_Library::Operand_Base::Operand_Base(unsigned long value)
{
	std::stringstream ss;
	std::string s;
	ss << value;
	ss >> s;
	unsigned long long i, max;
	max = s.length();
	for (i = 0; i < max; i++) {
		this->data.push_back(s[i]);
	}
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (this->point == 0 && this->data[point] == '.') {
			this->data.insert(this->data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->point == max - 1 && this->data[point] == '.') {
			this->data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->point == max - 1 && this->data[point] != '.') {
			this->data.push_back(_point);
			this->data.push_back(_0);
			this->point++;
			break;
		}
		//若碰到小数点，返回
		else if (this->data[point] == '.') {
			break;
		}
		else
		{
			this->point++;
		}
	}
	return;
}

High_Precision_Maths_Library::Operand_Base::Operand_Base(unsigned long long value)
{
	std::stringstream ss;
	std::string s;
	ss << value;
	ss >> s;
	unsigned long long i, max;
	max = s.length();
	for (i = 0; i < max; i++) {
		this->data.push_back(s[i]);
	}
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (this->point == 0 && this->data[point] == '.') {
			this->data.insert(this->data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->point == max - 1 && this->data[point] == '.') {
			this->data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->point == max - 1 && this->data[point] != '.') {
			this->data.push_back(_point);
			this->data.push_back(_0);
			this->point++;
			break;
		}
		//若碰到小数点，返回
		else if (this->data[point] == '.') {
			break;
		}
		else
		{
			this->point++;
		}
	}
	return;
}

High_Precision_Maths_Library::Operand_Base::Operand_Base(char value)
{
	if ((value < '0' || value > '9') && value != '.') {
		Illegal_Data e("value不是一个数字或小数点，不能用于初始化对象");
		throw(e);
	}
	this->data.push_back(value);
	if (value != '.') {
		this->data.push_back(_point);
		this->data.push_back(_0);
		this->point = 1;
	}
	else
	{
		this->data.insert(this->data.begin(), _0);
		this->data.push_back(_0);
		this->point = 1;
	}
	return;
}

High_Precision_Maths_Library::Operand_Base::Operand_Base(std::string value)
{
	unsigned long long i, max;
	max = value.length();
	for (i = 0; i < max; i++) {
		this->data.push_back(value[i]);
	}
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (this->point == 0 && this->data[point] == '.') {
			this->data.insert(this->data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->point == max - 1 && this->data[point] == '.') {
			this->data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->point == max - 1 && this->data[point] != '.') {
			this->data.push_back(_point);
			this->data.push_back(_0);
			this->point++;
			break;
		}
		//若碰到小数点，返回
		else if (this->data[point] == '.') {
			break;
		}
		else
		{
			this->point++;
		}
	}
	return;
}

High_Precision_Maths_Library::Operand_Base::Operand_Base(char* value)
{
	std::stringstream ss;
	std::string s;
	ss << value;
	ss >> s;
	unsigned long long i, max;
	max = s.length();
	for (i = 0; i < max; i++) {
		this->data.push_back(s[i]);
	}
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (this->point == 0 && this->data[point] == '.') {
			this->data.insert(this->data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->point == max - 1 && this->data[point] == '.') {
			this->data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->point == max - 1 && this->data[point] != '.') {
			this->data.push_back(_point);
			this->data.push_back(_0);
			this->point++;
			break;
		}
		//若碰到小数点，返回
		else if (this->data[point] == '.') {
			break;
		}
		else
		{
			this->point++;
		}
	}
	return;
}

High_Precision_Maths_Library::Operand_Base::Operand_Base(float value)
{
	std::stringstream ss;
	std::string s;
	ss << value;
	ss >> s;
	unsigned long long i, max;
	max = s.length();
	for (i = 0; i < max; i++) {
		this->data.push_back(s[i]);
	}
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (this->point == 0 && this->data[point] == '.') {
			this->data.insert(this->data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->point == max - 1 && this->data[point] == '.') {
			this->data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->point == max - 1 && this->data[point] != '.') {
			this->data.push_back(_point);
			this->data.push_back(_0);
			this->point++;
			break;
		}
		//若碰到小数点，返回
		else if (this->data[point] == '.') {
			break;
		}
		else
		{
			this->point++;
		}
	}
	return;
}

High_Precision_Maths_Library::Operand_Base::Operand_Base(double value)
{
	std::stringstream ss;
	std::string s;
	ss << value;
	ss >> s;
	unsigned long long i, max;
	max = s.length();
	for (i = 0; i < max; i++) {
		this->data.push_back(s[i]);
	}
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (this->point == 0 && this->data[point] == '.') {
			this->data.insert(this->data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->point == max - 1 && this->data[point] == '.') {
			this->data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->point == max - 1 && this->data[point] != '.') {
			this->data.push_back(_point);
			this->data.push_back(_0);
			this->point++;
			break;
		}
		//若碰到小数点，返回
		else if (this->data[point] == '.') {
			break;
		}
		else
		{
			this->point++;
		}
	}
	return;
}

High_Precision_Maths_Library::Operand_Base::Operand_Base(long double value)
{
	std::stringstream ss;
	std::string s;
	ss << value;
	ss >> s;
	unsigned long long i, max;
	max = s.length();
	for (i = 0; i < max; i++) {
		this->data.push_back(s[i]);
	}
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (this->point == 0 && this->data[point] == '.') {
			this->data.insert(this->data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->point == max - 1 && this->data[point] == '.') {
			this->data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->point == max - 1 && this->data[point] != '.') {
			this->data.push_back(_point);
			this->data.push_back(_0);
			this->point++;
			break;
		}
		//若碰到小数点，返回
		else if (this->data[point] == '.') {
			break;
		}
		else
		{
			this->point++;
		}
	}
	return;
}

High_Precision_Maths_Library::Operand_Base::Operand_Base(const Operand_Base& value)
{
    this->point = value.point;
	this->data.copy((DDM<char>&)value.data);
}

High_Precision_Maths_Library::Operand_Base::Operand_Base(DDM<char>& value)
{
	this->data = value;
	unsigned long long i, max;
	max = value.size();
	for (i = 0; i < max; i++) {
		this->data.push_back(value[i]);
	}
	while (true)
	{
		//若以小数点开头，在前面补充一个0
		if (this->point == 0 && this->data[point] == '.') {
			this->data.insert(this->data.begin(), _0);
			break;
		}
		//若以小数点结尾，在最后补充一个0
		else if (this->point == max - 1 && this->data[point] == '.') {
			this->data.push_back(_0);
			break;
		}
		//若没有小数点，则补充小数点和0
		else if (this->point == max - 1 && this->data[point] != '.') {
			this->data.push_back(_point);
			this->data.push_back(_0);
			this->point++;
			break;
		}
		//若碰到小数点，返回
		else if (this->data[point] == '.') {
			break;
		}
		else
		{
			this->point++;
		}
	}
	return;
}

inline std::string High_Precision_Maths_Library::Operand_Base::to_string()
{
	std::string s;
	unsigned long long max = this->data.size();
	for (unsigned long long i = 0; i < max; i++) {
		s += this->data[i];
	}
	return s;
}

inline bool High_Precision_Maths_Library::Operand_Base::operator==(Operand_Base& right)
{
	remain_significant_number(*this);
	remain_significant_number(right);
	if (this->data.size() != right.data.size()) {
		return false;
	}
	else
	{
		unsigned long long max = right.data.size();
		for (unsigned long long i = 0; i < max; i++) {
			if (this->data[i] != right.data[i]) {
				return false;
			}
		}
		return true;
	}
}

inline bool High_Precision_Maths_Library::Operand_Base::operator!=(Operand_Base& right)
{
	return !(*this == right);
}

inline bool High_Precision_Maths_Library::Operand_Base::operator>(Operand_Base& right)
{
	if (*this == right) {
		return false;
	}
	else
	{
		position_point(*this);
		position_point(right);
		decimal_point(*this, right);
		unsigned long long max = this->data.size();
		unsigned long long i = 0;
		while (true)
		{
			if (this->data[i] == right.data[i]) {
				i++;
			}
			else if (this->data[i] > right.data[i]) {
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

inline bool High_Precision_Maths_Library::Operand_Base::operator<=(Operand_Base& right)
{
	return !(*this > right);
}

inline bool High_Precision_Maths_Library::Operand_Base::operator<(Operand_Base& right)
{
	if (*this == right) {
		return false;
	}
	else
	{
		position_point(*this);
		position_point(right);
		decimal_point(*this, right);
		unsigned long long max = this->data.size();
		unsigned long long i = 0;
		while (true)
		{
			if (this->data[i] == right.data[i]) {
				i++;
			}
			else if (this->data[i] < right.data[i]) {
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}

inline bool High_Precision_Maths_Library::Operand_Base::operator>=(Operand_Base& right)
{
	return !(*this < right);
}

inline High_Precision_Maths_Library::Operand_Base& High_Precision_Maths_Library::Operand_Base::operator=(const Operand_Base right) {
	this->point = right.point;
	this->data.copy((DDM<char>&)right.data);
	return *this;
}

inline High_Precision_Maths_Library::Operand_Base High_Precision_Maths_Library::Operand_Base::operator+(Operand_Base right)
{
	return Addition(*this, right);
}

inline High_Precision_Maths_Library::Operand_Base& High_Precision_Maths_Library::Operand_Base::operator+=(Operand_Base& right)
{
	*this = Addition(*this, right);
	return *this;
}

inline High_Precision_Maths_Library::Operand_Base& High_Precision_Maths_Library::Operand_Base::operator++()
{
	Operand_Base o('1');
	*this = Addition(*this, o);
	return *this;
}

inline High_Precision_Maths_Library::Operand_Base High_Precision_Maths_Library::Operand_Base::operator++(int)
{
	Operand_Base o('1');
	*this = Addition(*this, o);
	return *this;
}

inline High_Precision_Maths_Library::Operand_Base High_Precision_Maths_Library::Operand_Base::operator*(Operand_Base right)
{
	return Multiplication(*this, right);
}

inline High_Precision_Maths_Library::Operand_Base& High_Precision_Maths_Library::Operand_Base::operator*=(Operand_Base& right)
{
	*this = Multiplication(*this, right);
	return *this;
}

inline High_Precision_Maths_Library::Operand_Base High_Precision_Maths_Library::Operand_Base::operator^(unsigned long long point)
{
	if (0 == point) {
		if (*this == (Operand_Base&)Operand_Base('0')) {
			Illegal_Data e("0的0次方没有意义。");
			throw e;
		}
		return Operand_Base('1');
	}
	Operand_Base result = *this;
	for (unsigned long long i = 1; i < point; i++) {
		result = Multiplication(result, *this);
	}
	return result;
}

inline High_Precision_Maths_Library::Operand_Base& High_Precision_Maths_Library::Operand_Base::operator^=(unsigned long long point)
{
	*this = *this ^ point;
	return *this;
}

inline High_Precision_Maths_Library::Operand_Base High_Precision_Maths_Library::Operand_Base::operator-(Operand_Base right)
{
	return Subtraction(*this, right);
}

inline High_Precision_Maths_Library::Operand_Base& High_Precision_Maths_Library::Operand_Base::operator-=(Operand_Base& right)
{
	*this = Subtraction(*this, right);
	return *this;
}

inline High_Precision_Maths_Library::Operand_Base& High_Precision_Maths_Library::Operand_Base::operator--()
{
	Operand_Base o('1');
	*this = Subtraction(*this, o);
	return *this;
}

inline High_Precision_Maths_Library::Operand_Base High_Precision_Maths_Library::Operand_Base::operator--(int)
{
	Operand_Base o('1');
	*this = Subtraction(*this, o);
	return *this;
}

inline High_Precision_Maths_Library::Operand_Base High_Precision_Maths_Library::Operand_Base::operator/(Operand_Base right)
{
	return Division(*this, right);
}

inline High_Precision_Maths_Library::Operand_Base& High_Precision_Maths_Library::Operand_Base::operator/=(Operand_Base& right)
{
	*this = Division(*this, right);
	return *this;
}

inline High_Precision_Maths_Library::Operand_Base High_Precision_Maths_Library::Operand_Base::operator>>(unsigned long long n)
{
	Operand_Base result(*this);
	result.data.push_back((char&)(const char&)'0');
	for (unsigned long long i = 0; i < n; i++) {
		//将小数点变成小数点的下一位
		result.data[result.point] = result.data[result.point + 1];
		//将小数点的下一位变成小数点
		result.data[result.point + 1] = '.';
		//小数点的位置++
		result.point++;
	}
	remain_significant_number(result);
	return result;
}

inline High_Precision_Maths_Library::Operand_Base& High_Precision_Maths_Library::Operand_Base::operator>>=(unsigned long long n)
{
	this->data.push_back((char&)(const char&)'0');
	for (unsigned long long i = 0; i < n; i++) {
		//将小数点变成小数点的下一位
		this->data[this->point] = this->data[this->point + 1];
		//将小数点的下一位变成小数点
		this->data[this->point + 1] = '.';
		//小数点的位置++
		this->point++;
	}
	remain_significant_number(*this);
	return *this;
}

inline High_Precision_Maths_Library::Operand_Base High_Precision_Maths_Library::Operand_Base::operator<<(unsigned long long n)
{
	Operand_Base result(*this);
	result.data.insert(result.data.begin(), (char&)(const char&)'0');
	for (unsigned long long i = 0; i < n; i++) {
		//将小数点变成小数点的上一位
		result.data[result.point] = result.data[result.point - 1];
		//将小数点的上一位变成小数点
		result.data[result.point - 1] = '.';
		//小数点的位置--
		result.point--;
	}
	remain_significant_number(result);
	return result;
}

inline High_Precision_Maths_Library::Operand_Base& High_Precision_Maths_Library::Operand_Base::operator<<=(unsigned long long n)
{
	this->data.insert(this->data.begin(), (char&)(const char&)'0');
	this->point++;
	for (unsigned long long i = 0; i < n; i++) {
		//将小数点变成小数点的上一位
		this->data[this->point] = this->data[this->point - 1];
		//将小数点的上一位变成小数点
		this->data[this->point - 1] = '.';
		//小数点的位置--
		this->point--;
	}
	remain_significant_number(*this);
	return *this;
}

inline High_Precision_Maths_Library::Operand_Base High_Precision_Maths_Library::Operand_Base::operator&(unsigned long long n)
{
	Operand_Base result;
	result = Extraction(*this, n);
	return result;
}

inline High_Precision_Maths_Library::Operand_Base& High_Precision_Maths_Library::Operand_Base::operator&=(unsigned long long n)
{
	*this = Extraction(*this, n);
	return *this;
}

inline High_Precision_Maths_Library::Operand_Base High_Precision_Maths_Library::Operand_Base::operator%(Operand_Base right)
{
	return Remainder(*this,right);
}

inline High_Precision_Maths_Library::Operand_Base& High_Precision_Maths_Library::Operand_Base::operator%=(Operand_Base& right)
{
	*this = Remainder(*this, right);
	return *this;
}
