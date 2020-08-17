#pragma once
#include "Accumulation.h"
namespace High_Precision_Maths_Library {
	/// <summary>
	/// 统计类，可以计算中位数平均数方差极差标准差
	/// </summary>
	class DLL_API Statistics {
	private:
		Accumulation data;
	public:
		Statistics();
		Statistics(Statistics& value);
		/// <summary>
		/// 向集合中添加一个对象
		/// </summary>
		void put(Operand_Base& value);
		/// <summary>
		/// 向集合中添加一个对象
		/// </summary>
		void put(Operand_Standard& value);
		/// <summary>
		/// 获取集合中元素的个数
		/// </summary>
		unsigned long long size();
		/// <summary>
		/// 获取集合中下标为n的元素
		/// </summary>
		Operand_Standard& at(unsigned long long n);
		/// <summary>
		/// 获取集合中下标为n的元素
		/// </summary>
		Operand_Standard& operator[](unsigned long long n);
		/// <summary>
		/// 用已有集合初始化该集合
		/// </summary>
		void operator()(Statistics& value);
		/// <summary>
		/// 获取该集合中元素的极差
		/// </summary>
		Operand_Standard range();
		/// <summary>
		/// 获取该集合中元素的最大值
		/// </summary>
		Operand_Standard get_max();
		/// <summary>
		/// 获取该集合中元素的最小值
		/// </summary>
		Operand_Standard get_min();
		/// <summary>
		/// 获取该集合中元素的平均数
		/// </summary>
		Operand_Standard average();
		/// <summary>
		/// 获取该集合中元素的方差
		/// </summary>
		Operand_Standard variance();
		/// <summary>
		/// 获取该集合中元素的标准差
		/// </summary>
		Operand_Standard standard_deviation();
		/// <summary>
		/// 获取该集合中元素的中位数
		/// </summary>
		Operand_Standard median();
	};
}
