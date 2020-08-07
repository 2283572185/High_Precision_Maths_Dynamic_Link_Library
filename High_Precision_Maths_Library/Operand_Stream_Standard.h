#pragma once
#include "Operand_Base.h"
namespace High_Precision_Maths_Library {
	/// <summary>
	/// ��׼ת���������Operand_Standardʹ�ã��׳����쳣����Error�����࣬�������ֻ��ͬʱ����һ��Ԫ�ء�
	/// ����ʱ���������Ԫ�غ󲻻���������ڲ�Ԫ�أ�ֻ�ǽ������óɿ�����״̬��
	/// ʹ��clear�����������Ԫ�أ�ʹ��free������ÿ������롣
	/// ���ṩ����ת��������ת��
	/// </summary>
	class DLL_API OperandStream_Standard : public High_Precision_Maths_Library::OperandStream_Base
	{
	protected:
		DDM<High_Precision_Maths_Library::Operand_Standard> data_S;
		bool is_S = false;
	public:
#define fill  true
#define empty false
		OperandStream_Standard();
		OperandStream_Standard(const OperandStream_Standard& value);
		void operator<<(High_Precision_Maths_Library::Operand_Standard& value);
		//����������д������Ԫ�ص�ֵ������������͵�ȡֵ��Χ���ᵼ�²���Ԥ��Ľ��
		//���ֵ����������
		int operator>>(int value);
		short operator>>(short value);
		long operator>>(long value);
		long long operator>>(long long value);
		unsigned int operator>>(unsigned int value);
		unsigned short operator>>(unsigned short value);
		unsigned long operator>>(unsigned long value);
		unsigned long long operator>>(unsigned long long value);
		/// <summary>
		/// �����д������Ԫ��ת���ɵ��ַ������ж���ַ������ܵ������δ֪���
		/// </summary>
		char operator>>(char value);
		std::string operator>>(std::string& value);
		/// <summary>
		/// �ᶯ̬�����ڴ棬�����ڴ�й©
		/// </summary>
		char* operator>>(char* value);
		High_Precision_Maths_Library::Operand_Base operator>>(High_Precision_Maths_Library::Operand_Base& value);
		float operator>>(float value);
		double operator>>(double value);
		long double operator>>(long double value);
		High_Precision_Maths_Library::Operand_Standard operator>>(High_Precision_Maths_Library::Operand_Standard& value);
		/// <summary>
		/// �������Ԫ��
		/// </summary>
		void clear();
		/// <summary>
		/// ������ÿ������룬���ͷ�����Ԫ��
		/// </summary>
		void free();
		/// <summary>
		/// ����ת��������������������������������
		/// </summary>
		/// <param name="value">Ҫ���о���ת���Ķ���</param>
		/// <param name="precision">���ȿ�����Ķ��󣬾�����ת����ʽ��ת���󾫶�</param>
		static void change_precision(High_Precision_Maths_Library::Operand_Standard& value, High_Precision_Maths_Library::Precision_Base& precision);
	};
}