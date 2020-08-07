#pragma once
#include "Operand_Standard.h"
namespace High_Precision_Maths_Library {
	/// <summary>
	/// 累加类，将输入Operand_Standard或Operand_Base对象相加并输出，提供查找函数，是Operand_Standard的集合，可以进行从小到大排序
	/// 抛出的所有异常都是Error的子类
	/// </summary>
	class DLL_API Accumulation {
	private:
		//累加类内部的元素
		DDM<Operand_Standard> data;
	public:
		/// <summary>
		/// 构造一个空的对象
		/// </summary>
		Accumulation();
		/// <summary>
		/// 用已有对象创建对象
		/// </summary>
		/// <param name="value">已有的对象</param>
		Accumulation(Accumulation& value);
		/// <summary>
		/// 向集合中添加一个元素
		/// </summary>
		/// <param name="value">要添加的Operand_Standard类型元素</param>
		void push_back(Operand_Standard& value);
		/// <summary>
		/// 向集合中添加一个元素
		/// </summary>
		/// <param name="value">要添加的Operand_Base类型元素</param>
		void push_back(Operand_Base& value);
		/// <summary>
		/// 向集合中添加一个元素
		/// </summary>
		/// <param name="value">要添加的Operand_Standard类型元素</param>
		void operator<<(Operand_Standard& value);
		/// <summary>
		/// 向集合中添加一个元素
		/// </summary>
		/// <param name="value">要添加的Operand_Base类型元素</param>
		void operator<<(Operand_Base& value);
		/// <summary>
		/// 移除集合中下标为n的元素
		/// </summary>
		/// <param name="n">要移除的元素的下标</param>
		void remove(unsigned long long n);
		/// <summary>
		/// 获取集合中下标为n的元素
		/// </summary>
		/// <param name="n">要获取的元素的下标</param>
		Operand_Standard& at(unsigned long long n);
		/// <summary>
		/// 获取集合中下标为n的元素
		/// </summary>
		/// <param name="n">要获取的元素的下标</param>
		Operand_Standard& operator[](unsigned long long n);
		/// <summary>
		/// 获取集合中所有元素的和
		/// </summary>
		/// <returns>集合中所有元素的和</returns>
		Operand_Standard get_result();
		/// <summary>
		/// 清空集合中所有元素
		/// </summary>
		void clear();
		/// <summary>
		/// 获取对象中元素的总数
		/// </summary>
		unsigned long long size();
		/// <summary>
		/// 从小到大排序
		/// </summary>
		void sort();
		/// <summary>
		/// 向集合中添加一个元素，然后排序
		/// </summary>
		void put(Operand_Standard& value);
		/// <summary>
		/// 向集合中添加一个元素，然后排序
		/// </summary>
		void put(Operand_Base& value);
	};
}
