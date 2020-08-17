#pragma once
#include "Operand_Base.h"
using namespace High_Precision_Maths_Library;
namespace High_Precision_Maths_Library {
	/// <summary>
	/// 精度转换控制基类
	/// </summary>
	class DLL_API Precision_Base {
	protected:
		friend class OperandStream_Base;
		//精度，即转换后小数位数，0即为整数
		unsigned long long precision;
		//转换方式，在宏中选择
		int type;
	public:
		/// <param name="precision">精度，即转换后小数位数，0即为整数</param>
		/// <param name="type">转换方式，在宏中选择</param>
		Precision_Base(unsigned long long precision, int type);
		//以下是所有可以的转换类型，请在以下宏中做出选择
		//四舍五入
#define round 1
//去尾法
#define round_down 2
//进一法
#define round_up 3
//严格模式，若小数位数不足，会用0不足，取舍策略与选择的转换类型有关，不能单独使用。
//使用该模式的情况下，必须再使用一种且只使用一种转换类型，两个宏之间使用按位或运算符(|)连接
#define strict 0xf000
	};

	/// <summary>
	/// 基础转换流，配合Operand_Base使用，抛出的异常都是Error的子类，流中最多只能同时容纳一个元素。
	/// 运行时，流在输出元素后不会主动清空内部元素，只是将流设置成可输入状态。
	/// 使用clear清空流中所有元素，使用free让流变得可以输入。
	/// 流提供精度转换和类型转换
	/// </summary>
	class DLL_API OperandStream_Base {
	protected:
#define fill true
#define empty false
		/// <summary>
		/// 用于储存流内部的数据
		/// </summary>
		DDM<High_Precision_Maths_Library::Operand_Base> data;
		bool state;
	public:
		OperandStream_Base();
		OperandStream_Base(const OperandStream_Base& value);
		//输入
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
		/// <summary>
		/// 清空所以元素
		/// </summary>
		void clear();
		/// <summary>
		/// 让流变得可以输入，不释放流内元素
		/// </summary>
		void free();
		/// <summary>
		/// 判断流是否是空的
		/// </summary>
		/// <returns>若流是空的，返回true，反正，返回false</returns>
		bool is_empty();
		/// <summary>
		/// 判断流是否是满的
		/// </summary>
		/// <returns>若流是满的，返回true，反正，返回false</returns>
		bool is_fill();
		/// <summary>
		/// 精度转换函数，这个函数不会向流中输入对象
		/// </summary>
		/// <param name="value">要进行精度转换的对象</param>
		/// <param name="precision">精度控制类的对象，决定了转换方式和转换后精度</param>
		static void change_precision(High_Precision_Maths_Library::Operand_Base& value, Precision_Base& precision);
	};
}
