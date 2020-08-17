#pragma once
#include "Operand_Base.h"

/*
	Developed by 2283572185@qq.com
	Developed in C++
	Compiled with Visual Studio 2019 (v142)
	Use C++17 standard
	Use Window SDK 10.0
	Download https://github.com/2283572185/High_Precision_Maths_Library
*/

//д��ǰ�棺
//��ͷ�ļ����ṩ����Operand_Base�Ķ���֮��֧�ֵļ��㼰����������£�
//��ѧ�������
//�ӷ� +
//���� -
//�˷� *
//���� /
//�˷� ^
//���� >>
//���� <<
//���� &
//ȡ�� %
//-------------------------------------------------------------------
//��չ��ѧ�������
//ǰ����������� ++
//������������� ++(int)
//�����������������ͬ��+=1��
//ǰ���Լ������ --
//�����Լ������ --(int)
//�����������������ͬ��-=1��
//�ӵ��� +=
//������ -=
//�˵��� *=
//������ /=
//�˷�����ֵ ^=
//���Ʋ���ֵ >>=
//���Ʋ���ֵ <<=
//��������ֵ &=
//ȡ�ಢ��ֵ %=
//-------------------------------------------------------------------
//�߼��������
//��� ==
//����� !=
//���� >
//С�� <
//���ڵ��� >=
//С�ڵ��� <=

namespace High_Precision_Maths_Library {
	/// <summary>
	/// �߾�����ѧ��ı�׼�֧࣬�������������ļӡ������ˡ������˷����������׳ˡ�ȡ�������׳��������쳣����Error�Ļ���
	/// ��֧���Կ�ѧ�������ķ�ʽ��������
	/// </summary>
	class DLL_API Operand_Standard {
	private:
		//ֵ�����������
		Operand_Base data;
		//�Ǹ���Ϊtrue����֮Ϊfalse
		bool minus;
	public:
		friend class OperandStream_Standard;
		friend class Accumulation;
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
		std::string to_string();
		/// <summary>
		/// ���
		/// </summary>
		bool operator==(Operand_Standard& right);
		/// <summary>
		/// �����
		/// </summary>
		bool operator!=(Operand_Standard& right);
		/// <summary>
		/// ����
		/// </summary>
		bool operator>(Operand_Standard& right);
		/// <summary>
		/// С�ڵ���
		/// </summary>
		bool operator<=(Operand_Standard& right);
		/// <summary>
		/// С��
		/// </summary>
		bool operator<(Operand_Standard& right);
		/// <summary>
		/// ���ڵ���
		/// </summary>
		bool operator>=(Operand_Standard& right);
		/// <summary>
		/// ��
		/// </summary>
		Operand_Standard operator+(Operand_Standard& right);
		/// <summary>
		/// �ӵ���
		/// </summary>
		Operand_Standard& operator+=(Operand_Standard& right);
		/// <summary>
		/// ǰ�����������
		/// </summary>
		Operand_Standard& operator++();
		/// <summary>
		/// �������������
		/// </summary>
		Operand_Standard operator++(int);
		/// <summary>
		/// ��
		/// </summary>
		Operand_Standard operator-(Operand_Standard& right);
		/// <summary>
		/// ������
		/// </summary>
		Operand_Standard& operator-=(Operand_Standard& right);
		/// <summary>
		/// ǰ���Լ������
		/// </summary>
		Operand_Standard& operator--();
		/// <summary>
		/// �����Լ������
		/// </summary>
		Operand_Standard operator--(int);
		/// <summary>
		/// ����
		/// </summary>
		Operand_Standard operator<<(unsigned long long n);
		/// <summary>
		/// ���Ʋ���ֵ
		/// </summary>
		Operand_Standard& operator<<=(unsigned long long n);
		/// <summary>
		/// ����
		/// </summary>
		Operand_Standard operator>>(unsigned long long n);
		/// <summary>
		/// ���Ʋ���ֵ
		/// </summary>
		Operand_Standard& operator>>=(unsigned long long n);
		/// <summary>
		/// ��
		/// </summary>
		Operand_Standard operator*(Operand_Standard& right);
		/// <summary>
		/// �˵���
		/// </summary>
		Operand_Standard& operator*=(Operand_Standard& right);
		/// <summary>
		/// ��
		/// </summary>
		Operand_Standard operator/(Operand_Standard& right);
		/// <summary>
		/// ������
		/// </summary>
		Operand_Standard& operator/=(Operand_Standard& right);
		/// <summary>
		/// ����
		/// </summary>
		Operand_Standard operator&(unsigned long long n);
		/// <summary>
		/// ��������ֵ
		/// </summary>
		Operand_Standard& operator&=(unsigned long long n);
		/// <summary>
		/// �˷�
		/// </summary>
		Operand_Standard operator^(unsigned long long n);
		/// <summary>
		/// �˷�����ֵ
		/// </summary>
		Operand_Standard& operator^=(unsigned long long n);
		/// <summary>
		/// ȡ��
		/// </summary>
		Operand_Standard operator^(Operand_Standard& right);
		/// <summary>
		/// ȡ�ಢ��ֵ
		/// </summary>
		Operand_Standard& operator^=(Operand_Standard& right);
		/// <summary>
		/// ��յ�ǰ�����ֵ����value��ֵ��ʼ����ǰ����
		/// </summary>
		void copy(Operand_Standard& value);
		/// <summary>
		/// ��յ�ǰ�����ֵ����value��ֵ��ʼ����ǰ����
		/// </summary>
		void operator()(Operand_Standard& value);
	};
}
#include "Accumulation.h"