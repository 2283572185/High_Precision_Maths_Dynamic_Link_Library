#pragma once
#include "Operand_Base.h"

/*
	Developed by 2283572185@qq.com
	Developed in C++
	Compiled with Visual Studio 2019 (v142)
	Use C++17 standard
	Use Window SDK 10.0
	Download https://github.com/2283572185/High_Precision_Maths_Library
*/

//写在前面：
//该头文件所提供的类Operand_Base的对象之间支持的计算及其运算符如下：
//数学运算符：
//加法 +
//减法 -
//乘法 *
//除法 /
//乘方 ^
//右移 >>
//左移 <<
//开方 &
//取余 %
//-------------------------------------------------------------------
//扩展数学运算符：
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
//右移并赋值 >>=
//左移并赋值 <<=
//开方并赋值 &=
//取余并赋值 %=
//-------------------------------------------------------------------
//逻辑运算符：
//相等 ==
//不相等 !=
//大于 >
//小于 <
//大于等于 >=
//小于等于 <=

namespace High_Precision_Maths_Library {
	/// <summary>
	/// 高精度数学库的标准类，支持所有有理数的加、减、乘、除、乘方、开方、阶乘、取余数，抛出的所以异常都是Error的基类
	/// 不支持以科学计数法的方式输入数据
	/// </summary>
	class DLL_API Operand_Standard {
	private:
		//值，不储存符号
		Operand_Base data;
		//是负数为true，反之为false
		bool minus;
	public:
		friend class OperandStream_Standard;
		friend class Accumulation;
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
		std::string to_string();
		/// <summary>
		/// 相等
		/// </summary>
		bool operator==(Operand_Standard& right);
		/// <summary>
		/// 不相等
		/// </summary>
		bool operator!=(Operand_Standard& right);
		/// <summary>
		/// 大于
		/// </summary>
		bool operator>(Operand_Standard& right);
		/// <summary>
		/// 小于等于
		/// </summary>
		bool operator<=(Operand_Standard& right);
		/// <summary>
		/// 小于
		/// </summary>
		bool operator<(Operand_Standard& right);
		/// <summary>
		/// 大于等于
		/// </summary>
		bool operator>=(Operand_Standard& right);
		/// <summary>
		/// 加
		/// </summary>
		Operand_Standard operator+(Operand_Standard& right);
		/// <summary>
		/// 加等于
		/// </summary>
		Operand_Standard& operator+=(Operand_Standard& right);
		/// <summary>
		/// 前置自增运算符
		/// </summary>
		Operand_Standard& operator++();
		/// <summary>
		/// 后置自增运算符
		/// </summary>
		Operand_Standard operator++(int);
		/// <summary>
		/// 减
		/// </summary>
		Operand_Standard operator-(Operand_Standard& right);
		/// <summary>
		/// 减等于
		/// </summary>
		Operand_Standard& operator-=(Operand_Standard& right);
		/// <summary>
		/// 前置自减运算符
		/// </summary>
		Operand_Standard& operator--();
		/// <summary>
		/// 后置自减运算符
		/// </summary>
		Operand_Standard operator--(int);
		/// <summary>
		/// 左移
		/// </summary>
		Operand_Standard operator<<(unsigned long long n);
		/// <summary>
		/// 左移并赋值
		/// </summary>
		Operand_Standard& operator<<=(unsigned long long n);
		/// <summary>
		/// 右移
		/// </summary>
		Operand_Standard operator>>(unsigned long long n);
		/// <summary>
		/// 右移并赋值
		/// </summary>
		Operand_Standard& operator>>=(unsigned long long n);
		/// <summary>
		/// 乘
		/// </summary>
		Operand_Standard operator*(Operand_Standard& right);
		/// <summary>
		/// 乘等于
		/// </summary>
		Operand_Standard& operator*=(Operand_Standard& right);
		/// <summary>
		/// 除
		/// </summary>
		Operand_Standard operator/(Operand_Standard& right);
		/// <summary>
		/// 除等于
		/// </summary>
		Operand_Standard& operator/=(Operand_Standard& right);
		/// <summary>
		/// 开方
		/// </summary>
		Operand_Standard operator&(unsigned long long n);
		/// <summary>
		/// 开方并赋值
		/// </summary>
		Operand_Standard& operator&=(unsigned long long n);
		/// <summary>
		/// 乘方
		/// </summary>
		Operand_Standard operator^(unsigned long long n);
		/// <summary>
		/// 乘方并赋值
		/// </summary>
		Operand_Standard& operator^=(unsigned long long n);
		/// <summary>
		/// 取余
		/// </summary>
		Operand_Standard operator^(Operand_Standard& right);
		/// <summary>
		/// 取余并赋值
		/// </summary>
		Operand_Standard& operator^=(Operand_Standard& right);
		/// <summary>
		/// 清空当前对象的值并用value的值初始化当前对象
		/// </summary>
		void copy(Operand_Standard& value);
		/// <summary>
		/// 清空当前对象的值并用value的值初始化当前对象
		/// </summary>
		void operator()(Operand_Standard& value);
	};
}
#include "Accumulation.h"