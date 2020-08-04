#pragma once
#include "Operand_Base.h"
namespace High_Precision_Maths_Library {
	/// <summary>
	/// 确定小数点的位置，若原操作数没有小数点，将在最后补上
	/// </summary>
	/// <param name="value">操作数</param>
	void position_point(Operand_Base& value);

	/// <summary>
	/// 单位高精度加法算法
	/// </summary>
	/// <param name="left">加数</param>
	/// <param name="right">加数</param>
	/// <param name="_result">用于储存结果的类对象的引用</param>
	void high_precision_addition(char& left, char& right, Result& _result);

	/// <summary>
	/// 对齐小数点，在这之前，请调用High_Precision_Maths_Library::position_point
	/// </summary>
	/// <param name="left">左操作数</param>
	/// <param name="right">右操作数</param>
	void decimal_point(Operand_Base& left, Operand_Base& right);

	/// <summary>
	/// 加法
	/// </summary>
	/// <param name="left">加数</param>
	/// <param name="right">加数</param>
	Operand_Base Addition(Operand_Base& left, Operand_Base& right);

	/// <summary>
	/// 单位高精度乘法算法
	/// </summary>
	/// <param name="left">乘数</param>
	/// <param name="right">乘数</param>
	/// <param name="_result">用于储存结果的类对象的引用</param>
	void high_precision_multiplication(char& left, char& right, Result& _result);

	/// <summary>
	/// 乘法
	/// </summary>
	/// <param name="left">乘数</param>
	/// <param name="right">乘数</param>
	Operand_Base Multiplication(Operand_Base& left, Operand_Base& right);

	/// <summary>
	/// 去除对象中无效的0，保留有效数字
	/// </summary>
	void remain_significant_number(Operand_Base& value);

	/// <summary>
	/// 单位高精度减法算法
	/// </summary>
	/// <param name="left">被减数</param>
	/// <param name="right">减数</param>
	/// <param name="_result">用于储存结果的类对象的引用</param>
	void high_precision_subtraction(char& left, char& right, Result& _result);

	/// <summary>
	/// 减法
	/// </summary>
	/// <param name="left">被减数</param>
	/// <param name="right">减数</param>
	Operand_Base Subtraction(Operand_Base& left, Operand_Base& right);

	/// <summary>
	/// 除法
	/// </summary>
	/// <param name="left">被除数</param>
	/// <param name="right">除数</param>
	Operand_Base Division(Operand_Base left, Operand_Base right);

	/// <summary>
	/// 开方
	/// </summary>
	Operand_Base Extraction(Operand_Base left, unsigned long long n);

	/// <summary>
	/// 取余数
	/// </summary>
	Operand_Base Remainder(Operand_Base left, Operand_Base right);

	/// <summary>
	/// 改变预设精度
	/// </summary>
	/// <param name="type">要改变的运算符的类型，在下列宏中选择</param>
	/// <param name="precision">新的精度</param>
	void change_precision(int type, unsigned long long precision);
	//可选用的运算符类型
	//除法
	#define division 1
	//开方，开方的精度因小于等于除法精度，否则开方精度为除法精度
	#define extraction_of_root 2
	//开方迭代次数，此时precision表示新的迭代次数，迭代次数越大，精度越高
	#define extraction_of_root_time 3
}
void High_Precision_Maths_Library::Multiplication_thread(Operand_Base* a, Value<char>* value, unsigned long long n, Operand_Base** result, unsigned long long m);
