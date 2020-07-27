#pragma once
#include "Operand_Base.h"
using namespace High_Precision_Maths_Library;
namespace High_Precision_Maths_Library {

	class OperandStream_Base;

	/// <summary>
	/// ����ת�����ƻ���
	/// </summary>
	class Precision_Base {
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
	/// ʹ��clear�����������Ԫ�أ�ʹ��pop���������δ�����һ��Ԫ�ء�
	/// ���ṩ����ת��������ת��
	/// </summary>
	class OperandStream_Base {
	protected:
	#define fill  true
	#define empty false
		/// <summary>
		/// ���ڴ������ڲ�������
		/// </summary>
		DDM<Operand_Base> data;
		bool state;
	public:
		OperandStream_Base();
		OperandStream_Base(const OperandStream_Base& value);
		//����
		virtual void operator<<(int value);
		virtual void operator<<(short value);
		virtual void operator<<(long value);
		virtual void operator<<(long long value);
		virtual void operator<<(unsigned int value);
		virtual void operator<<(unsigned short value);
		virtual void operator<<(unsigned long value);
		virtual void operator<<(unsigned long long value);
		virtual void operator<<(char value);
		virtual void operator<<(std::string value);
		virtual void operator<<(char* value);
		virtual void operator<<(Operand_Base& value);
		virtual void operator<<(float value);
		virtual void operator<<(double value);
		virtual void operator<<(long double value);
		//����������д������Ԫ�ص�ֵ������������͵�ȡֵ��Χ���ᵼ�²���Ԥ��Ľ��
		//���ֵ����������
		virtual int operator>>(int value);
		virtual short operator>>(short value);
		virtual long operator>>(long value);
		virtual long long operator>>(long long value);
		virtual unsigned int operator>>(unsigned int value);
		virtual unsigned short operator>>(unsigned short value);
		virtual unsigned long operator>>(unsigned long value);
		virtual unsigned long long operator>>(unsigned long long value);
		/// <summary>
		/// �����д������Ԫ��ת���ɵ��ַ������ж���ַ������ܵ������δ֪���
		/// </summary>
		virtual char operator>>(char value);
		virtual std::string operator>>(std::string& value);
		/// <summary>
		/// �ᶯ̬�����ڴ棬�����ڴ�й©
		/// </summary>
		virtual char* operator>>(char* value);
		virtual Operand_Base operator>>(Operand_Base& value);
		virtual float operator>>(float value);
		virtual double operator>>(double value);
		virtual long double operator>>(long double value);
		/// <summary>
		/// �������Ԫ��
		/// </summary>
		virtual void clear();
		/// <summary>
		/// ���������δ�����Ԫ��
		/// </summary>
		virtual void pop();
		/// <summary>
		/// �ж����Ƿ��ǿյ�
		/// </summary>
		/// <returns>�����ǿյģ�����true������������false</returns>
		virtual bool is_empty();
		/// <summary>
		/// �ж����Ƿ�������
		/// </summary>
		/// <returns>���������ģ�����true������������false</returns>
		virtual bool is_fill();
		/// <summary>
		/// ����ת��������������������������������
		/// </summary>
		/// <param name="value">Ҫ���о���ת���Ķ���</param>
		/// <param name="precision">���ȿ�����Ķ��󣬾�����ת����ʽ��ת���󾫶�</param>
		virtual void change_precision(Operand_Base& value, Precision_Base& precision);
	};
}
