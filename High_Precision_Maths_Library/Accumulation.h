#pragma once
#include "Operand_Standard.h"
namespace High_Precision_Maths_Library {
	/// <summary>
	/// �ۼ��࣬������Operand_Standard��Operand_Base������Ӳ�������ṩ���Һ�������Operand_Standard�ļ��ϣ����Խ��д�С��������
	/// �׳��������쳣����Error������
	/// </summary>
	class DLL_API Accumulation {
	private:
		//�ۼ����ڲ���Ԫ��
		DDM<Operand_Standard> data;
	public:
		/// <summary>
		/// ����һ���յĶ���
		/// </summary>
		Accumulation();
		/// <summary>
		/// �����ж��󴴽�����
		/// </summary>
		/// <param name="value">���еĶ���</param>
		Accumulation(Accumulation& value);
		/// <summary>
		/// �򼯺������һ��Ԫ��
		/// </summary>
		/// <param name="value">Ҫ��ӵ�Operand_Standard����Ԫ��</param>
		void push_back(Operand_Standard& value);
		/// <summary>
		/// �򼯺������һ��Ԫ��
		/// </summary>
		/// <param name="value">Ҫ��ӵ�Operand_Base����Ԫ��</param>
		void push_back(Operand_Base& value);
		/// <summary>
		/// �򼯺������һ��Ԫ��
		/// </summary>
		/// <param name="value">Ҫ��ӵ�Operand_Standard����Ԫ��</param>
		void operator<<(Operand_Standard& value);
		/// <summary>
		/// �򼯺������һ��Ԫ��
		/// </summary>
		/// <param name="value">Ҫ��ӵ�Operand_Base����Ԫ��</param>
		void operator<<(Operand_Base& value);
		/// <summary>
		/// �Ƴ��������±�Ϊn��Ԫ��
		/// </summary>
		/// <param name="n">Ҫ�Ƴ���Ԫ�ص��±�</param>
		void remove(unsigned long long n);
		/// <summary>
		/// ��ȡ�������±�Ϊn��Ԫ��
		/// </summary>
		/// <param name="n">Ҫ��ȡ��Ԫ�ص��±�</param>
		Operand_Standard& at(unsigned long long n);
		/// <summary>
		/// ��ȡ�������±�Ϊn��Ԫ��
		/// </summary>
		/// <param name="n">Ҫ��ȡ��Ԫ�ص��±�</param>
		Operand_Standard& operator[](unsigned long long n);
		/// <summary>
		/// ��ȡ����������Ԫ�صĺ�
		/// </summary>
		/// <returns>����������Ԫ�صĺ�</returns>
		Operand_Standard get_result();
		/// <summary>
		/// ��ռ���������Ԫ��
		/// </summary>
		void clear();
		/// <summary>
		/// ��ȡ������Ԫ�ص�����
		/// </summary>
		unsigned long long size();
		/// <summary>
		/// ��С��������
		/// </summary>
		void sort();
		/// <summary>
		/// �򼯺������һ��Ԫ�أ�Ȼ������
		/// </summary>
		void put(Operand_Standard& value);
		/// <summary>
		/// �򼯺������һ��Ԫ�أ�Ȼ������
		/// </summary>
		void put(Operand_Base& value);
	};
}
