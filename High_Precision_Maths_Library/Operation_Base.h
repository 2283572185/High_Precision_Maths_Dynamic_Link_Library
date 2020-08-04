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
	void high_precision_addition(char& left, char& right, Result& _result);

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

	/// <summary>
	/// ��λ�߾��ȳ˷��㷨
	/// </summary>
	/// <param name="left">����</param>
	/// <param name="right">����</param>
	/// <param name="_result">���ڴ�����������������</param>
	void high_precision_multiplication(char& left, char& right, Result& _result);

	/// <summary>
	/// �˷�
	/// </summary>
	/// <param name="left">����</param>
	/// <param name="right">����</param>
	Operand_Base Multiplication(Operand_Base& left, Operand_Base& right);

	/// <summary>
	/// ȥ����������Ч��0��������Ч����
	/// </summary>
	void remain_significant_number(Operand_Base& value);

	/// <summary>
	/// ��λ�߾��ȼ����㷨
	/// </summary>
	/// <param name="left">������</param>
	/// <param name="right">����</param>
	/// <param name="_result">���ڴ�����������������</param>
	void high_precision_subtraction(char& left, char& right, Result& _result);

	/// <summary>
	/// ����
	/// </summary>
	/// <param name="left">������</param>
	/// <param name="right">����</param>
	Operand_Base Subtraction(Operand_Base& left, Operand_Base& right);

	/// <summary>
	/// ����
	/// </summary>
	/// <param name="left">������</param>
	/// <param name="right">����</param>
	Operand_Base Division(Operand_Base left, Operand_Base right);

	/// <summary>
	/// ����
	/// </summary>
	Operand_Base Extraction(Operand_Base left, unsigned long long n);

	/// <summary>
	/// ȡ����
	/// </summary>
	Operand_Base Remainder(Operand_Base left, Operand_Base right);

	/// <summary>
	/// �ı�Ԥ�辫��
	/// </summary>
	/// <param name="type">Ҫ�ı������������ͣ������к���ѡ��</param>
	/// <param name="precision">�µľ���</param>
	void change_precision(int type, unsigned long long precision);
	//��ѡ�õ����������
	//����
	#define division 1
	//�����������ľ�����С�ڵ��ڳ������ȣ����򿪷�����Ϊ��������
	#define extraction_of_root 2
	//����������������ʱprecision��ʾ�µĵ�����������������Խ�󣬾���Խ��
	#define extraction_of_root_time 3
}
void High_Precision_Maths_Library::Multiplication_thread(Operand_Base* a, Value<char>* value, unsigned long long n, Operand_Base** result, unsigned long long m);
