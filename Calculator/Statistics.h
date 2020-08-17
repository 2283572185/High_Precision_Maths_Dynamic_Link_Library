#pragma once
#include "Accumulation.h"
namespace High_Precision_Maths_Library {
	/// <summary>
	/// ͳ���࣬���Լ�����λ��ƽ����������׼��
	/// </summary>
	class DLL_API Statistics {
	private:
		Accumulation data;
	public:
		Statistics();
		Statistics(Statistics& value);
		/// <summary>
		/// �򼯺������һ������
		/// </summary>
		void put(Operand_Base& value);
		/// <summary>
		/// �򼯺������һ������
		/// </summary>
		void put(Operand_Standard& value);
		/// <summary>
		/// ��ȡ������Ԫ�صĸ���
		/// </summary>
		unsigned long long size();
		/// <summary>
		/// ��ȡ�������±�Ϊn��Ԫ��
		/// </summary>
		Operand_Standard& at(unsigned long long n);
		/// <summary>
		/// ��ȡ�������±�Ϊn��Ԫ��
		/// </summary>
		Operand_Standard& operator[](unsigned long long n);
		/// <summary>
		/// �����м��ϳ�ʼ���ü���
		/// </summary>
		void operator()(Statistics& value);
		/// <summary>
		/// ��ȡ�ü�����Ԫ�صļ���
		/// </summary>
		Operand_Standard range();
		/// <summary>
		/// ��ȡ�ü�����Ԫ�ص����ֵ
		/// </summary>
		Operand_Standard get_max();
		/// <summary>
		/// ��ȡ�ü�����Ԫ�ص���Сֵ
		/// </summary>
		Operand_Standard get_min();
		/// <summary>
		/// ��ȡ�ü�����Ԫ�ص�ƽ����
		/// </summary>
		Operand_Standard average();
		/// <summary>
		/// ��ȡ�ü�����Ԫ�صķ���
		/// </summary>
		Operand_Standard variance();
		/// <summary>
		/// ��ȡ�ü�����Ԫ�صı�׼��
		/// </summary>
		Operand_Standard standard_deviation();
		/// <summary>
		/// ��ȡ�ü�����Ԫ�ص���λ��
		/// </summary>
		Operand_Standard median();
	};
}
