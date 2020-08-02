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
	/// �߾�����ѧ��ı�׼�֧࣬�������������ļӡ������ˡ������˷����������׳ˡ�ȡ�������׳��������쳣����Error�Ļ���
	/// ��֧���Կ�ѧ�������ķ�ʽ��������
	/// </summary>
	class Operand_Standard {
	public:
		//ֵ�����������
		Operand_Base value;
		//�Ǹ���Ϊtrue����֮Ϊfalse
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
		/// �����������Ե��ַ�ת����һ���ַ���������ӷ��ź󷵻�
		/// </summary>
		virtual std::string to_string();
	};
}