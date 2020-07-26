#pragma once
#ifdef DLL_Project
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

#include <iostream>
#include <string>
#include <sstream>
#include "Discontinuity_Dynamic_Memory.h"
//#include "Operation_Base.h"
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
#define Division_Precision 30
//开方精度预设
#define Extraction_Of_Root_Precision 30
//取余数精度
#define Remainder_Precision 30

namespace High_Precision_Maths_Library {
class Result;
class Operand_Base;
#include "Operation_Base.h"

	/// <summary>
	/// 用于储存单位运算后的结果
	/// </summary>
	class DLL_API Result {
	public:
		char result;
		char change;
	};

	/// <summary>
	/// 高精度数学库的基类，支持非负有理数的加、减、乘、除、乘方、开方、阶乘、取余数，抛出的所以异常都是Error的基类
	/// </summary>
	class DLL_API Operand_Base {
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
		/// <summary>
		/// 将对象内所以的字符转化成一个字符串并返回
		/// </summary>
		virtual std::string to_string();
		virtual bool operator==(Operand_Base& right);
		virtual bool operator!=(Operand_Base& right);
		virtual bool operator>(Operand_Base& right);
	};
}