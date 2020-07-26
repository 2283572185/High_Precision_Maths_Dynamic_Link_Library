#pragma once
#include "Operand_Base.h"
namespace High_Precision_Maths_Library {
	/// <summary>
	/// ȷ��С�����λ�ã���ԭ������û��С���㣬���������
	/// </summary>
	/// <param name="value">������</param>
	void position_point(Operand_Base& value);

	/// <summary>
	/// ��λ�߾��ȼӷ��㷨
	/// </summary>
	/// <param name="left">����</param>
	/// <param name="right">����</param>
	/// <param name="_result">���ڴ�����������������</param>
	void high_precision_add(char& left, char& right, Result& _result);

	/// <summary>
	/// ����С���㣬����֮ǰ�������High_Precision_Maths_Library::position_point
	/// </summary>
	/// <param name="left">�������</param>
	/// <param name="right">�Ҳ�����</param>
	void decimal_point(Operand_Base& left, Operand_Base& right);

	/// <summary>
	/// �ӷ�
	/// </summary>
	/// <param name="left">����</param>
	/// <param name="right">����</param>
	Operand_Base Addition(Operand_Base& left, Operand_Base& right);
}