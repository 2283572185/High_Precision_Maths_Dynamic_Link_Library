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
		virtual int operator>>(int value);
		virtual short operator>>(short value);
		virtual long operator>>(long value);
		virtual long long operator>>(long long value);
		virtual unsigned int operator>>(unsigned int value);
		virtual unsigned short operator>>(unsigned short value);
		virtual unsigned long operator>>(unsigned long value);
		virtual unsigned long long operator>>(unsigned long long value);
		virtual char operator>>(char value);
		virtual std::string operator>>(std::string& value);
		/// <summary>
		/// 会动态分配内存，当心内存泄漏
		/// </summary>
		virtual char* operator>>(char* value);
		virtual Operand_Base operator>>(Operand_Base& value);
		virtual float operator>>(float value);
		virtual double operator>>(double value);
		virtual long double operator>>(long double value);
	};
}
