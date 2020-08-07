#pragma once
#include "Operand_Base.h"
namespace High_Precision_Maths_Library {
	/// <summary>
	/// 标准转换流，配合Operand_Standard使用，抛出的异常都是Error的子类，流中最多只能同时容纳一个元素。
	/// 运行时，流在输出元素后不会主动清空内部元素，只是将流设置成可输入状态。
	/// 使用clear清空流中所有元素，使用free让流变得可以输入。
	/// 流提供精度转换和类型转换
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
		//输出，若流中待输出的元素的值超出了输出类型的取值范围，会导致不可预测的结果
		//输出值会四舍五入
		int operator>>(int value);
		short operator>>(short value);
		long operator>>(long value);
		long long operator>>(long long value);
		unsigned int operator>>(unsigned int value);
		unsigned short operator>>(unsigned short value);
		unsigned long operator>>(unsigned long value);
		unsigned long long operator>>(unsigned long long value);
		/// <summary>
		/// 若流中待输出的元素转化成的字符串中有多个字符，可能导致输出未知结果
		/// </summary>
		char operator>>(char value);
		std::string operator>>(std::string& value);
		/// <summary>
		/// 会动态分配内存，当心内存泄漏
		/// </summary>
		char* operator>>(char* value);
		High_Precision_Maths_Library::Operand_Base operator>>(High_Precision_Maths_Library::Operand_Base& value);
		float operator>>(float value);
		double operator>>(double value);
		long double operator>>(long double value);
		High_Precision_Maths_Library::Operand_Standard operator>>(High_Precision_Maths_Library::Operand_Standard& value);
		/// <summary>
		/// 清空所以元素
		/// </summary>
		void clear();
		/// <summary>
		/// 让流变得可以输入，不释放流内元素
		/// </summary>
		void free();
		/// <summary>
		/// 精度转换函数，这个函数不会向流中输入对象
		/// </summary>
		/// <param name="value">要进行精度转换的对象</param>
		/// <param name="precision">精度控制类的对象，决定了转换方式和转换后精度</param>
		static void change_precision(High_Precision_Maths_Library::Operand_Standard& value, High_Precision_Maths_Library::Precision_Base& precision);
	};
}