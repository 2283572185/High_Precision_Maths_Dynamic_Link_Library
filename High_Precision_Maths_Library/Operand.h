#pragma once
/*
	Developed by 2283572185@qq.com
	Developed in C++
	Compiled with Visual Studio 2019 (v142)
	Use C++17 standard
	Use Window SDK 10.0
	Use __fastcall in the caller to speed up execution
	Download https://github.com/2283572185/High_Precision_Maths_Library
*/
//�ǳ���Ҫ��һ�㣺�밴������λ�������߿����ĵ�������
//2λ������������7
//4λ������������15
//8λ������������20
//�Դ����ƣ���λ��Խ�࣬��������Խ��
//��������Խ�࣬Ч��Խ��
//��������������ʱ���ʵ����ߵ�������
//��������ֵ��Ҫ������������ֵ�����˷�����
#include "Discontinuity_Dynamic_Memory.h"
#include "Operand_Base.h"
#include "Operand_Standard.h"
#include "Operand_Stream_Base.h"
#include "Operation_Base.h"
using namespace High_Precision_Maths_Library;
using Operand = Operand_Standard;
using OperandStream = OperandStream_Base;
//������ʹ�ó����������Ч��
namespace High_Precision_Maths_Library {
//��
#define pai "3.14"
//��(7λ)
#define pai_7 "3.1415926"
//��(10λ)
#define pai_10 "3.1415926536"
//��(15λ)
#define pai_15 "3.141592653589793"
//��(20λ)
#define pai_20 "3.14159265358979323846"
//��(25λ)
#define pai_25 "3.1415926535897932384626434"
//��(30λ)
#define pai_30 "3.141592653589793238462643383280"
//��(40λ)
#define pai_40 "3.1415926535897932384626433832795028841972"
//��(50λ)
#define pai_50 "3.14159265358979323846264338327950288419716939937511"
//e
#define $e "2.72"
//e(7λ)
#define $e_7 "2.7182818"
//e(10λ)
#define $e_10 "2.7182818285"
//e(15λ)
#define $e_15 "2.718281828459045"
//e(20λ)
#define $e_20 "2.71828182845904523536"
//e(25λ)
#define $e_25 "2.7182818284590452353602875"
//e(30λ)
#define $e_30 "2.718281828459045235360287471353"
//e(40λ)
#define $e_40 "2.7182818284590452353602874713526624977572"
//e(50λ)
#define $e_50 "2.71828182845904523536028747135266249775724709369996"
//��0
#define $0 "0"
//��1
#define $1 "1"
//��2
#define $2 "1.414"
//��2(10λ)
#define $2_10 "1.4142135624"
//��3
#define $3 "1.732"
//��3(10λ)
#define $3_10 "1.7320508076"
//��4
#define $4 "2"
//��5
#define $5 "2.236"
//��5(10λ)
#define $5_10 "2.2360679774"
//��6
#define $6 "2.449"
//��6(10λ)
#define $6_10 "2.4494897428"
//��7
#define $7 "2.646"
//��7(10λ)
#define $7_10 "2.6457513111"
//��8
#define $8 "2.828"
//��8(10λ)
#define $8_10 "2.8284271247"
//��9
#define $9 "3"
//��10
#define $10 "3.162"
//��10(10λ)
#define $10_10 "3.1622776602"
}