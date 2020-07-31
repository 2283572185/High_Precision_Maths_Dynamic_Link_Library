#include "Operand_Base.h"
using namespace High_Precision_Maths_Library;
char _0 = '0';
char _point = '.';

Operand_Base::Operand_Base()
{
	this->point = 0;
	return;
}

Operand_Base::Operand_Base(int value)
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

Operand_Base::Operand_Base(short value)
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

Operand_Base::Operand_Base(long value)
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

Operand_Base::Operand_Base(long long value)
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

Operand_Base::Operand_Base(unsigned int value)
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

Operand_Base::Operand_Base(unsigned short value)
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

Operand_Base::Operand_Base(unsigned long value)
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

Operand_Base::Operand_Base(unsigned long long value)
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

Operand_Base::Operand_Base(char value)
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

Operand_Base::Operand_Base(std::string value)
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

Operand_Base::Operand_Base(char* value)
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

Operand_Base::Operand_Base(const Operand_Base& value)
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

std::string Operand_Base::to_string()
{
	std::string s;
	unsigned long long max = this->data.size();
	for (unsigned long long i = 0; i < max; i++) {
		s += this->data[i];
	}
	return s;
}

bool Operand_Base::operator==(Operand_Base& right)
{
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

bool Operand_Base::operator!=(Operand_Base& right)
{
	return !(*this == right);
}

bool Operand_Base::operator>(Operand_Base& right)
{
	position_point(*this);
	position_point(right);
	decimal_point(*this, right);
	unsigned long long max = this->data.size();
	unsigned long long i = 0;
	if (*this == right) {
		return false;
	}
	else
	{
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

bool Operand_Base::operator<=(Operand_Base& right)
{
	return !(*this > right);
}

bool Operand_Base::operator<(Operand_Base& right)
{
	position_point(*this);
	position_point(right);
	decimal_point(*this, right);
	unsigned long long max = this->data.size();
	unsigned long long i = 0;
	if (*this == right) {
		return false;
	}
	else
	{
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

bool Operand_Base::operator>=(Operand_Base& right)
{
	return !(*this < right);
}

Operand_Base& Operand_Base::operator=(const Operand_Base right) {
	this->point = right.point;
	this->data.copy((DDM<char>&)right.data);
	return *this;
}

Operand_Base Operand_Base::operator+(Operand_Base right)
{
	return Addition(*this, right);
}

Operand_Base& Operand_Base::operator+=(Operand_Base& right)
{
	*this = *this + right;
	return *this;
}

Operand_Base& Operand_Base::operator++()
{
	Operand_Base o('1');
	*this += o;
	return *this;
}

Operand_Base High_Precision_Maths_Library::Operand_Base::operator++(int)
{
	++(*this);
	return *this;
}

Operand_Base High_Precision_Maths_Library::Operand_Base::operator*(Operand_Base right)
{
	return Multiplication(*this, right);
}

Operand_Base& High_Precision_Maths_Library::Operand_Base::operator*=(Operand_Base& right)
{
	*this = *this * right;
	return *this;
}

Operand_Base High_Precision_Maths_Library::Operand_Base::operator^(unsigned long long point)
{
	if (0 == point) {
		return Operand_Base('1');
	}
	Operand_Base result = *this;
	for (unsigned long long i = 1; i < point; i++) {
		result *= *this;
	}
	return result;
}

Operand_Base& High_Precision_Maths_Library::Operand_Base::operator^=(unsigned long long point)
{
	*this = *this ^ point;
	return *this;
}
