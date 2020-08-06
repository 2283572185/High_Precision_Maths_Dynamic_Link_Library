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
//非常重要的一点：请按照数的位数来调高开方的迭代次数
//2位数，迭代次数7
//4位数，迭代次数15
//8位数，迭代次数20
//以此类推，数位数越多，迭代次数越多
//迭代次数越多，效率越低
//当开方精度增加时，适当调高迭代次数
//开方精度值不要超过除法精度值以免浪费算力
#include "Discontinuity_Dynamic_Memory.h"
#include "Operand_Base.h"
#include "Operand_Standard.h"
#include "Operand_Stream_Base.h"
#include "Operation_Base.h"
using namespace High_Precision_Maths_Library;
using Operand = Operand_Standard;
using OperandStream = OperandStream_Base;
//常数表，使用常数表来提高效率
namespace High_Precision_Maths_Library {
//π
#define pai "3.14"
//π(7位)
#define pai_7 "3.1415926"
//π(10位)
#define pai_10 "3.1415926536"
//π(15位)
#define pai_15 "3.141592653589793"
//π(20位)
#define pai_20 "3.14159265358979323846"
//π(25位)
#define pai_25 "3.1415926535897932384626434"
//π(30位)
#define pai_30 "3.141592653589793238462643383280"
//π(40位)
#define pai_40 "3.1415926535897932384626433832795028841972"
//π(50位)
#define pai_50 "3.14159265358979323846264338327950288419716939937511"
//e
#define $e "2.72"
//e(7位)
#define $e_7 "2.7182818"
//e(10位)
#define $e_10 "2.7182818285"
//e(15位)
#define $e_15 "2.718281828459045"
//e(20位)
#define $e_20 "2.71828182845904523536"
//e(25位)
#define $e_25 "2.7182818284590452353602875"
//e(30位)
#define $e_30 "2.718281828459045235360287471353"
//e(40位)
#define $e_40 "2.7182818284590452353602874713526624977572"
//e(50位)
#define $e_50 "2.71828182845904523536028747135266249775724709369996"
//√0
#define $0 "0"
//√1
#define $1 "1"
//√2
#define $2 "1.414"
//√2(10位)
#define $2_10 "1.4142135624"
//√3
#define $3 "1.732"
//√3(10位)
#define $3_10 "1.7320508076"
//√4
#define $4 "2"
//√5
#define $5 "2.236"
//√5(10位)
#define $5_10 "2.2360679774"
//√6
#define $6 "2.449"
//√6(10位)
#define $6_10 "2.4494897428"
//√7
#define $7 "2.646"
//√7(10位)
#define $7_10 "2.6457513111"
//√8
#define $8 "2.828"
//√8(10位)
#define $8_10 "2.8284271247"
//√9
#define $9 "3"
//√10
#define $10 "3.162"
//√10(10位)
#define $10_10 "3.1622776602"
}