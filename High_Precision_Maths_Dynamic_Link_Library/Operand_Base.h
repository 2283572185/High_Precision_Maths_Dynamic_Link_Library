#pragma once
/*
	Developed by 2283572185@qq.com
	Developed in C++
	Compiled with Visual Studio 2019 (v142)
	Use C++11 standard
	Use Window SDK 10.0
	Download https://github.com/2283572185/High_Precision_Maths_Library
*/

//写在前面：
//该头文件所提供的类Operand_Base的对象之间支持的计算及其运算符如下
//加法 +
//减法 -
//乘法 *
//除法 /
//乘方 ^
//开方 &
//取余 %
//扩展运算符：
//前置自增运算符 ++
//后置自增运算符 ++(int)
//（以上两个运算符等同于+=1）
//前置自减运算符 --
//后置自减运算符 --(int)
//（以上两个运算符等同于-=1）
//加等于 +=
//减等于 -=
//乘等于 *=
//除等于 /=
//乘方并赋值 ^=
//开方并赋值 &=

#include <iostream>
#include <string>
#include <sstream>
#include "Discontinuity_Dynamic_Memory.h"

template<class T>
using DDM = Discontinuity_Dynamic_Memory::DiscontinuityDynamicMemory<T>;
template<class T>
using Value = Discontinuity_Dynamic_Memory::Value<T>;
using Discontinuity_Dynamic_Memory::Error;
using Discontinuity_Dynamic_Memory::Illegal_Data;
using Discontinuity_Dynamic_Memory::Over_Flow;
using Discontinuity_Dynamic_Memory::Under_Flow;

/*这是一些运算的精度预设
 *请务必保留这些宏的定义
 *下面，用name来代替宏的名称，用precision来代替你想要的精度
 *如果你想修改下面预设的运算符的精度，请使用以下语句
 *	#undef name
 *	#define name precision
*/
//除法精度预设
#define Division_Precision 10
//开方精度预设
#define Extraction_Of_Root_Precision 10

using namespace std;

namespace High_Precision_Maths_Library {
	/// <summary>
	/// 用于储存单位运算后的结果
	/// </summary>
	class Result {
	public:
		char result = '0';
		char change = '0';
	};

	/// <summary>
	/// 高精度数学库的基类，支持非负有理数的加、减、乘、除、乘方、开方、阶乘、取余数，抛出的所以异常都是Error的基类
	/// 不支持以科学计数法的方式输入数据
	/// 注意，当小数点的位置等于该对象的长度时，这个对象是整数
	/// </summary>
	class Operand_Base {
	public:
		/// <summary>
		/// 这个对象的数据
		/// </summary>
		DDM<char> data;
		/// <summary>
		/// 表示小时点的位置，从左往右数，从零开始
		/// </summary>
		unsigned long long point = 0;
		Operand_Base();
		Operand_Base(int value);
		Operand_Base(short value);
		Operand_Base(long value);
		Operand_Base(long long value);
		Operand_Base(unsigned int value);
		Operand_Base(unsigned short value);
		Operand_Base(unsigned long value);
		Operand_Base(unsigned long long value);
		Operand_Base(char value);
		Operand_Base(std::string value);
		Operand_Base(char* value);
		Operand_Base(float value);
		Operand_Base(double value);
		Operand_Base(long double value);
		Operand_Base(const Operand_Base& value);
		Operand_Base(DDM<char>& value);
		/// <summary>
		/// 将对象内所以的字符转化成一个字符串并返回
		/// </summary>
		virtual std::string to_string();
		virtual bool operator==(Operand_Base& right);
		virtual bool operator!=(Operand_Base& right);
		virtual bool operator>(Operand_Base& right);
		virtual bool operator<=(Operand_Base& right);
		virtual bool operator<(Operand_Base& right);
		virtual bool operator>=(Operand_Base& right);
		virtual Operand_Base& operator=(const Operand_Base right);
		/// <summary>
		/// 计算此对象与right的和
		/// </summary>
		virtual Operand_Base operator+(Operand_Base right);
		/// <summary>
		/// 计算此对象与right的和并赋值给此对象
		/// </summary>
		virtual Operand_Base& operator+=(Operand_Base& right);
		/// <summary>
		/// 前置自增运算符
		/// </summary>
		virtual Operand_Base& operator++();
		/// <summary>
		/// 后置自增运算符
		/// </summary>
		virtual Operand_Base operator++(int);
		/// <summary>
		/// 计算此对象与right的积
		/// </summary>
		virtual Operand_Base operator*(Operand_Base right);
		/// <summary>
		/// 计算此对象与right的积并赋值给对象
		/// </summary>
		virtual Operand_Base& operator*=(Operand_Base& right);
		/// <summary>
		/// 乘方
		/// </summary>
		/// <param name="right">次数，请确保次数是整数</param>
		virtual Operand_Base operator^(unsigned long long point);
		/// <summary>
		/// 乘方并赋值给对象
		/// </summary>
		virtual Operand_Base& operator^=(unsigned long long point);
		/// <summary>
		/// 计算此对象与right的差
		/// </summary>
		virtual Operand_Base operator-(Operand_Base right);
		/// <summary>
		/// 计算此对象与right的差并赋值给此对象
		/// </summary>
		virtual Operand_Base& operator-=(Operand_Base& right);
		/// <summary>
		/// 前置自减运算符
		/// </summary>
		virtual Operand_Base& operator--();
		/// <summary>
		/// 后置自减运算符
		/// </summary>
		virtual Operand_Base operator--(int);
	};
}
#include "Operation_Base.h"
#include "Operand_Stream_Base.h"