#pragma once
#include "Operand_Base.h"

/*
	Developed by 2283572185@qq.com
	Developed in C++
	Compiled with Visual Studio 2019 (v142)
	Use C++17 standard
	Use Window SDK 10.0
	Use __fastcall in the caller to speed up execution
	Download https://github.com/2283572185/High_Precision_Maths_Library
*/

namespace High_Precision_Maths_Library {
	/// <summary>
	/// 高精度数学库的标准类，支持所有有理数的加、减、乘、除、乘方、开方、阶乘、取余数，抛出的所以异常都是Error的基类
	/// 不支持以科学计数法的方式输入数据
	/// </summary>
	class Operand_Standard {
	public:
		//值，不储存符号
		Operand_Base value;
		//是负数为true，反之为false
		bool minus;
		Operand_Standard();
		Operand_Standard(int value);
		Operand_Standard(short value);
		Operand_Standard(long value);
		Operand_Standard(long long value);
		Operand_Standard(unsigned int value);
		Operand_Standard(unsigned short value);
		Operand_Standard(unsigned long value);
		Operand_Standard(unsigned long long value);
		Operand_Standard(char value);
		Operand_Standard(std::string value);
		Operand_Standard(char* value);
		Operand_Standard(float value);
		Operand_Standard(double value);
		Operand_Standard(long double value);
		Operand_Standard(const Operand_Standard& value);
		Operand_Standard(DDM<char>& value);
		/// <summary>
		/// 将对象内所以的字符转化成一个字符串并在添加符号后返回
		/// </summary>
		virtual std::string to_string();
	};
}