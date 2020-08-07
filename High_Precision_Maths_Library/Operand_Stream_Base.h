#pragma once
#include "Operand_Base.h"
using namespace High_Precision_Maths_Library;
namespace High_Precision_Maths_Library {
	/// <summary>
	/// ����ת�����ƻ���
	/// </summary>
	class DLL_API Precision_Base {
	protected:
		friend class OperandStream_Base;
		//���ȣ���ת����С��λ����0��Ϊ����
		unsigned long long precision;
		//ת����ʽ���ں���ѡ��
		int type;
	public:
		/// <param name="precision">���ȣ���ת����С��λ����0��Ϊ����</param>
		/// <param name="type">ת����ʽ���ں���ѡ��</param>
		Precision_Base(unsigned long long precision, int type);
		//���������п��Ե�ת�����ͣ��������º�������ѡ��
		//��������
#define round 1
//ȥβ��
#define round_down 2
//��һ��
#define round_up 3
//�ϸ�ģʽ����С��λ�����㣬����0���㣬ȡ�������ѡ���ת�������йأ����ܵ���ʹ�á�
//ʹ�ø�ģʽ������£�������ʹ��һ����ֻʹ��һ��ת�����ͣ�������֮��ʹ�ð�λ�������(|)����
#define strict 0xf000
	};

	/// <summary>
	/// ����ת���������Operand_Baseʹ�ã��׳����쳣����Error�����࣬�������ֻ��ͬʱ����һ��Ԫ�ء�
	/// ����ʱ���������Ԫ�غ󲻻���������ڲ�Ԫ�أ�ֻ�ǽ������óɿ�����״̬��
	/// ʹ��clear�����������Ԫ�أ�ʹ��free������ÿ������롣
	/// ���ṩ����ת��������ת��
	/// </summary>
	class DLL_API OperandStream_Base {
	protected:
#define fill true
#define empty false
		/// <summary>
		/// ���ڴ������ڲ�������
		/// </summary>
		DDM<High_Precision_Maths_Library::Operand_Base> data;
		bool state;
	public:
		OperandStream_Base();
		OperandStream_Base(const OperandStream_Base& value);
		//����
		void operator<<(int value);
		void operator<<(short value);
		void operator<<(long value);
		void operator<<(long long value);
		void operator<<(unsigned int value);
		void operator<<(unsigned short value);
		void operator<<(unsigned long value);
		void operator<<(unsigned long long value);
		void operator<<(char value);
		void operator<<(std::string value);
		void operator<<(char* value);
		void operator<<(High_Precision_Maths_Library::Operand_Base& value);
		void operator<<(float value);
		void operator<<(double value);
		void operator<<(long double value);
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
		/// <summary>
		/// �������Ԫ��
		/// </summary>
		void clear();
		/// <summary>
		/// ������ÿ������룬���ͷ�����Ԫ��
		/// </summary>
		void free();
		/// <summary>
		/// �ж����Ƿ��ǿյ�
		/// </summary>
		/// <returns>�����ǿյģ�����true������������false</returns>
		bool is_empty();
		/// <summary>
		/// �ж����Ƿ�������
		/// </summary>
		/// <returns>���������ģ�����true������������false</returns>
		bool is_fill();
		/// <summary>
		/// ����ת��������������������������������
		/// </summary>
		/// <param name="value">Ҫ���о���ת���Ķ���</param>
		/// <param name="precision">���ȿ�����Ķ��󣬾�����ת����ʽ��ת���󾫶�</param>
		static void change_precision(High_Precision_Maths_Library::Operand_Base& value, Precision_Base& precision);
	};
}
