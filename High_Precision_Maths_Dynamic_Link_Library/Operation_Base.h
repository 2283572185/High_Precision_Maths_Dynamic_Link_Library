#pragma once
#include "Operand_Base.h"
using namespace High_Precision_Maths_Library;

/// <summary>
	/// ȷ��С�����λ�ã���ԭ������û��С���㣬���������
	/// </summary>
	/// <param name="value">������</param>
void DLL_API position_point(Operand_Base& value);

/// <summary>
	/// ��λ�߾��ȼӷ��㷨
	/// </summary>
	/// <param name="left">����</param>
	/// <param name="right">����</param>
	/// <param name="_result">���ڴ�����������������</param>
void DLL_API high_precision_add(char& left, char& right, Result& _result);
