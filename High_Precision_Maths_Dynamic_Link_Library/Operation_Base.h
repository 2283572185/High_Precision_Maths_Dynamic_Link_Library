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
	void high_precision_add(char& left, char& right, Result& _result);

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
}