#pragma once
#include "Operand_Base.h"
using namespace High_Precision_Maths_Library;
namespace High_Precision_Maths_Library {
	/// <summary>
	/// 基础转换流，配合Operand_Base使用
	/// </summary>
	class OperandStream_Base {
	protected:
		/// <summary>
		/// 用于储存流内部的数据
		/// </summary>
		DDM<Operand_Base> data;
	public:
		OperandStream_Base();
		OperandStream_Base(const OperandStream_Base& value);
		//输入
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
		//输出
		virtual int operator>>(int);
		virtual short operator>>(short);
		virtual long operator>>(long);
		virtual long long operator>>(long long);
		virtual unsigned int operator>>(unsigned int);
		virtual unsigned short operator>>(unsigned short);
		virtual unsigned long operator>>(unsigned long);
		virtual unsigned long long operator>>(unsigned long long);
		virtual char operator>>(char);
		virtual std::string operator>>(std::string);
		virtual char* operator>>(char*);
		virtual Operand_Base& operator>>(Operand_Base&);
		virtual float operator>>(float);
		virtual double operator>>(double);
		virtual long double operator>>(long double);
	};
}
