#include "Operand_Base.h"

char _0 = '0';

inline High_Precision_Maths_Library::Operand_Base::Operand_Base()
{
	this->point = 0;
	return;
}

inline High_Precision_Maths_Library::Operand_Base::Operand_Base(int value)
{
	std::stringstream ss;
	std::string s;
	ss << value;
	ss >> s;
	unsigned long long i, max;
	max = s.length();
	for (i = 0; i < max; i++) {
		this->data.push(s[i]);
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
			this->data.push(_0);
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

inline High_Precision_Maths_Library::Operand_Base::Operand_Base(short value)
{
	std::stringstream ss;
	std::string s;
	ss << value;
	ss >> s;
	unsigned long long i, max;
	max = s.length();
	for (i = 0; i < max; i++) {
		this->data.push(s[i]);
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
			this->data.push(_0);
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

inline High_Precision_Maths_Library::Operand_Base::Operand_Base(long value)
{
	std::stringstream ss;
	std::string s;
	ss << value;
	ss >> s;
	unsigned long long i, max;
	max = s.length();
	for (i = 0; i < max; i++) {
		this->data.push(s[i]);
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
			this->data.push(_0);
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

inline High_Precision_Maths_Library::Operand_Base::Operand_Base(long long value)
{
	std::stringstream ss;
	std::string s;
	ss << value;
	ss >> s;
	unsigned long long i, max;
	max = s.length();
	for (i = 0; i < max; i++) {
		this->data.push(s[i]);
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
			this->data.push(_0);
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

inline High_Precision_Maths_Library::Operand_Base::Operand_Base(unsigned int value)
{
	std::stringstream ss;
	std::string s;
	ss << value;
	ss >> s;
	unsigned long long i, max;
	max = s.length();
	for (i = 0; i < max; i++) {
		this->data.push(s[i]);
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
			this->data.push(_0);
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

inline High_Precision_Maths_Library::Operand_Base::Operand_Base(unsigned short value)
{
	std::stringstream ss;
	std::string s;
	ss << value;
	ss >> s;
	unsigned long long i, max;
	max = s.length();
	for (i = 0; i < max; i++) {
		this->data.push(s[i]);
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
			this->data.push(_0);
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

inline High_Precision_Maths_Library::Operand_Base::Operand_Base(unsigned long value)
{
	std::stringstream ss;
	std::string s;
	ss << value;
	ss >> s;
	unsigned long long i, max;
	max = s.length();
	for (i = 0; i < max; i++) {
		this->data.push(s[i]);
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
			this->data.push(_0);
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

inline High_Precision_Maths_Library::Operand_Base::Operand_Base(unsigned long long value)
{
	std::stringstream ss;
	std::string s;
	ss << value;
	ss >> s;
	unsigned long long i, max;
	max = s.length();
	for (i = 0; i < max; i++) {
		this->data.push(s[i]);
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
			this->data.push(_0);
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

inline High_Precision_Maths_Library::Operand_Base::Operand_Base(char value)
{
	std::stringstream ss;
	std::string s;
	ss << value;
	ss >> s;
	unsigned long long i, max;
	max = s.length();
	for (i = 0; i < max; i++) {
		this->data.push(s[i]);
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
			this->data.push(_0);
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

inline High_Precision_Maths_Library::Operand_Base::Operand_Base(std::string value)
{
	unsigned long long i, max;
	max = value.length();
	for (i = 0; i < max; i++) {
		this->data.push(value[i]);
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
			this->data.push(_0);
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

inline High_Precision_Maths_Library::Operand_Base::Operand_Base(char* value)
{
	std::stringstream ss;
	std::string s;
	ss << value;
	ss >> s;
	unsigned long long i, max;
	max = s.length();
	for (i = 0; i < max; i++) {
		this->data.push(s[i]);
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
			this->data.push(_0);
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

bool High_Precision_Maths_Library::Operand_Base::operator==(Operand_Base& base)
{
	return false;
}
