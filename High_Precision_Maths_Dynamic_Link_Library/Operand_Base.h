#pragma once
#ifdef DLL_Project
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

#include "Discontinuity_Dynamic_Memory.h"
template<class T>
using DDM = Discontinuity_Dynamic_Memory::DiscontinuityDynamicMemory<T>;
template<class T>
using Value = Discontinuity_Dynamic_Memory::Value<T>;
using Discontinuity_Dynamic_Memory::Error;
using Discontinuity_Dynamic_Memory::Illegal_Data;
using Discontinuity_Dynamic_Memory::Over_Flow;
using Discontinuity_Dynamic_Memory::Under_Flow;

namespace High_Precision_Maths_Library {
#define Division_Precision 30
#define Extraction_Of_Root 30

	/// <summary>
	/// 高精度数学库的基类，支持正有理数的所以运算
	/// </summary>
	class DLL_API Operand_Base {
	private:
		/// <summary>
		/// 这个对象的数据
		/// </summary>
		DDM<int> data;

	};
}