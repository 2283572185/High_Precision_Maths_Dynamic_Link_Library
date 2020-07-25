#pragma once
#ifdef DLL_Project
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

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

namespace High_Precision_Maths_Library {
//除法精度预设
#define Division_Precision 30
//开方精度预设
#define Extraction_Of_Root_Precision 30
//取余数精度
#define Remainder_Precision 30

	/// <summary>
	/// 高精度数学库的基类，支持非负有理数的加、减、乘、除、乘方、开方、阶乘、取余数，抛出的所以异常都是Error的基类
	/// </summary>
	class DLL_API Operand_Base {
	protected:
		/// <summary>
		/// 这个对象的数据
		/// </summary>
		DDM<char> data;
		/// <summary>
		/// 表示小时点的位置，从左往右数，从零开始
		/// </summary>
		unsigned long long point = 0;
	public:
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
		/// 获取对象中第n个字符（n是自然数）
		/// </summary>
		/// <param name="n">要获取字符的序号</param>
		char& at(unsigned long long n);
	};
}