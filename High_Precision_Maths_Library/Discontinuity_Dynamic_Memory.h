#ifndef Discontinuity_Dynamic_Memory_H
#define Discontinuity_Dynamic_Memory_H
#pragma warning(disable:6386)
#pragma warning(disable:6385)
#pragma warning(disable:6001)
#include <string>
namespace Discontinuity_Dynamic_Memory {
	/// <summary>
	/// 异常基类
	/// </summary>
	class Error{
	protected:
		std::string _description;
	public:
		/// <summary>
		/// 获取对当前异常的描述
		/// </summary>
		std::string get_description();
	};

	/// <summary>
	/// 异常：上溢
	/// </summary>
	class Over_Flow : public Error{
	public:
		/// <param name="description">对当前异常的描述</param>
		Over_Flow(std::string description);
	};

	/// <summary>
	/// 异常：下溢
	/// </summary>
	class Under_Flow : public Error{
	public:
		/// <param name="description">对当前异常的描述</param>
		Under_Flow(std::string description);
	};

	/// <summary>
	/// 异常：非法的数据
	/// </summary>
	class Illegal_Data : public Error{
	public:
		/// <param name="description">对当前异常的描述</param>
		Illegal_Data(std::string description);
	};


	/// <summary>
	/// 用于储存数据的类
	/// </summary>
	template <class T> class Value {
	public:
		Value<T>* next = nullptr;
		Value<T>* last = nullptr;
		T* value = nullptr;
		/// <summary>
		/// 初始化对象
		/// </summary>
		/// <param name="_next">上一个元素</param>
		/// <param name="_last">下一个元素</param>
		/// <param name="_vlaue">该元素的值</param>
		Value(Value* _next, Value* _last, T _value);
		/// <summary>
		/// 释放对象
		/// </summary>
		~Value();
	};

	/// <summary>
	/// 非连续性动态内存，抛出的异常均为Error子类的对象
	/// </summary>
	template <class T> class DiscontinuityDynamicMemory
	{
	protected:
		/// <summary>
		/// 当前位于顶端的元素
		/// </summary>
		Value<T>* _top = nullptr;
		/// <summary>
		/// 当前位于底端的元素
		/// </summary>
		Value<T>* _bottom = nullptr;
		/// <summary>
		/// 当前总元素数
		/// </summary>
		unsigned long long _size;
		/// <summary>
		/// 最大总元素数
		/// </summary>
		unsigned long long max_size;
		/// <summary>
		/// 是否具有元素个数上限
		/// </summary>
		bool limited;
	public:
		DiscontinuityDynamicMemory(DiscontinuityDynamicMemory<T>& value);
		/// <summary>
		/// 初始化一个可以容纳无限个元素的对象
		/// </summary>
		DiscontinuityDynamicMemory();
		/// <summary>
		/// 初始化具有元素个数上限的对象
		/// </summary>
		/// <param name="_max_size">最大可容纳的元素个数</param>
		/// <returns>若_max_size的值是0，抛出Illegal_Data异常误</returns>
		DiscontinuityDynamicMemory(unsigned long long _max_size);
		/// <summary>
		/// 判断该对象是否为空
		/// </summary>
		/// <returns>若该对象为空，返回true，反正，返回false</returns>
		bool empty();
		/// <summary>
		/// 获取对象中元素的总数
		/// </summary>
		/// <returns>该对象中元素的总数</returns>
		unsigned long long size();
		/// <summary>
		/// 向对象中添加一个元素
		/// </summary>
		/// <param name="value">要添加的元素的值</param>
		/// <returns>若剩余的可用内存不足或超过最大元素数量，抛出Over_Flow异常</returns>
		void push_back(T& value);
		/// <summary>
		/// 获取对象中最后一个被压入的元素
		/// </summary>
		/// <returns>最后一个被压入的元素。若对象是空的，抛出Over_Flow异常</returns>
		T top();
		/// <summary>
		/// 获取对象中第一个被压入的元素
		/// </summary>
		/// <returns>第一个被压入的元素。若对象是空的，抛出Over_Flow异常</returns>
		T bottom();
		/// <summary>
		/// 从对象中移去最后一个被压入的元素
		/// </summary>
		/// <returns>若对象是空的，抛出Under_Flow异常</returns>
		void pop();
		/// <summary>
		/// 获取对象的第n个元素（n是自然数）
		/// </summary>
		/// <param name="n">该元素在对象中的位置</param>
		/// <returns>对象中的第n个元素。若对象为空或n大于_size-1，抛出Over_Flow异常。</returns>
		T& at(unsigned long long n);
		/// <summary>
		/// 获取该迭代器所指向的元素的值
		/// </summary>
		/// <param name="where">指向该元素的迭代器</param>
		/// <returns>该迭代器所指向的元素的值。若对象是空的，抛出Under_Flow异常；若point为空或指向不能访问的值，引起读取访问权限冲突。</returns>
		T& at(Value<T>* point);
		/// <summary>
		/// 在对象的第n个元素前插入一个元素（n是自然数）
		/// </summary>
		/// <param name="n">要插入元素的位置</param>
		/// <param name="value">要插入元素的值</param>
		/// <returns>若剩余的可用内存不足或超过最大元素数量，抛出Over_Flow异常；若n大于_size-1，抛出Illegal_Data异常。</returns>
		void insert(unsigned long long n, T& value);
		/// <summary>
		/// 在对象的第n个元素前插入length个元素（n是自然数）
		/// </summary>
		/// <param name="n">要插入元素的位置</param>
		/// <param name="value">要插入元素所在的数组</param>
		/// <param name="length">要插入的数组的长度（正整数）</param>
		/// <returns>若剩余的可用内存不足或超过最大元素数量，抛出Over_Flow异常；若n大于_size-1，抛出Illegal_Data异常。</returns>
		void insert(unsigned long long n, T* value, int length);
		/// <summary>
		/// 在迭代器point指向的元素前插入一个元素（n是自然数）
		/// </summary>
		/// <param name="point">指向要插入元素的迭代器</param>
		/// <param name="value">要插入元素的值</param>
		/// <returns>若剩余的可用内存不足或超过最大元素数量，抛出Over_Flow异常；若point为空或指向不能访问的值，引起读取访问权限冲突。</returns>
		void insert(Value<T>* point, T& value);
		/// <summary>
		/// 在对象的第n个元素前插入length个元素（n是自然数）
		/// </summary>
		/// <param name="point">指向要插入元素的迭代器</param>
		/// <param name="value">要插入元素所在的数组</param>
		/// <param name="length">要插入的数组的长度（正整数）</param>
		/// <returns>若剩余的可用内存不足或超过最大元素数量，抛出Over_Flow异常；若point为空或指向不能访问的值，引起读取访问权限冲突。</returns>
		void insert(Value<T>* point, T* value, int length);
		/// <summary>
		/// 获取指向该对象的第一个元素的指针
		/// </summary>
		/// <returns>指向该对象的第一个元素的指针。若对象为空，抛出Over_Flow异常</returns>
		Value<T>* begin();
		/// <summary>
		/// 获取指向该对象的最后一个元素的指针
		/// </summary>
		/// <returns>指向该对象的最后一个元素的指针。若对象为空，抛出Under_Flow异常</returns>
		Value<T>* end();
		/// <summary>
		/// 获取指向该元素的下一个元素的指针
		/// </summary>
		/// <returns>指向该元素的下一个元素的指针。若对象为空或访问顶部指针的下一个元素，抛出Over_Flow异常。</returns>
		Value<T>* next(Value<T>* point);
		/// <summary>
		/// 获取指向该元素的上一个元素的指针
		/// </summary>
		/// <returns>指向该元素的上一个元素的指针。若对象为空或访问底部指针的上一个元素，抛出Under_Flow异常</returns>
		Value<T>* last(Value<T>* point);
		/// <summary>
		/// 获取指向第n个元素的指针（n为自然数）
		/// </summary>
		/// <param name="n">该对象中的第n个元素</param>
		/// <returns>指向该元素的指针，若对象为空或n大于_size-1，抛出Over_Flow异常。</returns>
		Value<T>* address(unsigned long long n);
		/// <summary>
		/// 删除point所指向的元素
		/// </summary>
		/// <param name="point">指向要删除的元素的指针</param>
		/// <returns>若对象为空，抛出Over_Flow异常；若指针不合法，抛出访问权限冲突异常</returns>
		void remove(Value<T>* point);
		/// <summary>
		/// 从对象中删除第n个元素
		/// </summary>
		/// <param name="n">要删除元素的序号</param>
		/// <returns>若对象为空或finish大于size - 1，抛出Over_Flow异常</returns>
		void remove(unsigned long long n);
		/// <summary>
		/// 从对象中删除一段元素
		/// </summary>
		/// <param name="start">开始删除的元素的指针（该元素也会被删除）</param>
		/// <param name="finish">结束删除的元素的指针（该元素也会被删除）</param>
		/// <returns>若对象为空，抛出Over_Flow异常；若指针不合法，抛出访问权限冲突异常</returns>
		void remove(Value<T>* start, Value<T>* finish);
		/// <summary>
		/// 从对象中删除一段元素
		/// </summary>
		/// <param name="start">开始删除的元素的序号（该元素也会被删除）</param>
		/// <param name="finish">结束删除的元素的序号（该元素也会被删除）</param>
		/// <returns>若对象为空或finish大于size - 1，抛出Over_Flow异常；若start大于finish，抛出Illegal_Data异常</returns>
		void remove(unsigned long long start, unsigned long long finish);

		/// <summary>
		/// 清空当前对象并复制value到当前对象
		/// </summary>
		void copy(DiscontinuityDynamicMemory<T>& value);

		T& operator[](unsigned long long n);

		T& operator[](Value<T>* point);

		void operator=(DiscontinuityDynamicMemory<T>& value);

		/// <summary>
		/// 清空当前对象中所有的元素
		/// </summary>
		void clear();
		/// <summary>
		/// 释放对象
		/// </summary>
		~DiscontinuityDynamicMemory();
	};

	template<class T>
	inline Value<T>::Value(Value* _next, Value* _last, T _value)
	{
		next = _next;
		last = _last;
		value = new T(_value);
	}

	template<class T>
	inline Value<T>::~Value()
	{
		next = nullptr;
		last = nullptr;
		delete value;
	}

	template<class T>
	inline DiscontinuityDynamicMemory<T>::DiscontinuityDynamicMemory()
	{
		_size = 0;
		limited = false;
		max_size = 0;
	}

	template<class T>
	inline DiscontinuityDynamicMemory<T>::DiscontinuityDynamicMemory(unsigned long long _max_size)
	{
		if (_max_size == 0) {
			Illegal_Data e("将形参_max_size赋值为0，_max_size应该是一个正整数。");
			throw ((Error)e);
		}
		_size = 0;
		max_size = _max_size;
		limited = true;
	}

	template<class T>
	inline bool DiscontinuityDynamicMemory<T>::empty()
	{
		if (_size == 0) {
			return true;
		}
		else
		{
			return false;
		}
	}

	template<class T>
	inline unsigned long long DiscontinuityDynamicMemory<T>::size() {
		return _size;
	}

	template<class T>
	inline void DiscontinuityDynamicMemory<T>::push_back(T& value)
	{
		if (_size + 1 > max_size && limited) {
			Over_Flow e("该对象所能容纳的元素个数已达到上限，不能再压入元素。");
			throw ((Error)e);
		}
		_size++;
		//开辟新的元素
		try
		{
			_top = new Value<T>(nullptr, _top, value);
		}
		catch (...)
		{
			Over_Flow e("剩余可用内存空间不足，分配内存失败。");
			throw(e);
		}
		if (_size != 1) {
			//当前元素的上一个元素的next指针指向该元素
			_top->last->next = _top;
		}
		else
		{
			//当只有一个元素时，底部指针和顶部指针指向同一个元素
			_bottom = _top;
		}
	}

	template<class T>
	inline T DiscontinuityDynamicMemory<T>::top()
	{
		if (_size == 0) {
			Over_Flow e("该对象是空的，不能读取元素。");
			throw(e);
		}
		return *(_top->value);
	}

	template<class T>
	inline T DiscontinuityDynamicMemory<T>::bottom()
	{
		if (_size == 0) {
			Over_Flow e("该对象是空的，不能读取元素。");
			throw(e);
		}
		return *(_bottom->value);
	}

	template<class T>
	inline void DiscontinuityDynamicMemory<T>::pop()
	{
		if (_size == 0) {
			Under_Flow e("该对象是空的，不能弹出元素。");
			throw(e);
		}
		_size--;
		//指向最后一个元素的上一个元素
		Value<T>* point = _top->last;
		delete _top;
		//将顶部指针向下移动一个元素
		_top = point;
		return;
	}

	template<class T>
	inline T& DiscontinuityDynamicMemory<T>::at(unsigned long long n)
	{
		if (n > _size - 1) {
			Over_Flow e("访问的元素超出了对象所以元素的总和。");
			throw(e);
		}
		Value<T>* work = begin();
		for (unsigned long long i = 0; i < n; i++)
		{
			work = next(work);
		}
		return *(work->value);
	}

	template<class T>
	inline T& DiscontinuityDynamicMemory<T>::at(Value<T>* point)
	{
		if (empty()) {
			Over_Flow e("该对象是空的，不能访问迭代器所指向的元素。");
			throw(e);
		}
		return *(point->value);
	}

	template<class T>
	inline void DiscontinuityDynamicMemory<T>::insert(unsigned long long n, T& value)
	{
		if (n > _size - 1) {
			Illegal_Data e("访问的元素超出了对象所以元素的总和。");
			throw(e);
		}
		if (_size + 1 > max_size && limited) {
			Over_Flow e("该对象所能容纳的元素个数已达到上限，不能再插入元素。");
		}
		Value<T>* work = begin();
		for (unsigned long long i = 0; i < n; i++)
		{
			work = next(work);
		}
		insert(work, value);
	}

	template<class T>
	inline void DiscontinuityDynamicMemory<T>::insert(unsigned long long n, T* value, int length)
	{
		if (n > _size - 1) {
			Illegal_Data e("访问的元素超出了对象所以元素的总和。");
			throw(e);
		}
		if (_size + length > max_size && limited) {
			Over_Flow e("该对象所能容纳的元素个数已达到上限，不能再插入元素。");
		}
		Value<T>* work = begin();
		for (unsigned long long i = 0; i < n; i++)
		{
			work = next(work);
		}
		insert(work, value, length);
	}

	template<class T>
	inline void DiscontinuityDynamicMemory<T>::insert(Value<T>* point, T& value)
	{
		if (_size + 1 > max_size && limited) {
			Over_Flow e("该对象所能容纳的元素个数已达到上限，不能再插入元素。");
		}
		T t;
		//向尾部插入一个元素
		push_back(t);
		Value<T>* pp = this->_top;
		while (true)
		{
			if (pp == point) {
				break;
			}
			else
			{
				//将上一个元素赋值到这一个元素
				*pp->value = *pp->last->value;
				//将指针向前移动
				pp = pp->last;
			}
		}
		*point->value = value;
		return;
	}

	template<class T>
	inline void DiscontinuityDynamicMemory<T>::insert(Value<T>* point, T* value, int length)
	{
		if (_size + length > max_size && limited) {
			Over_Flow e("该对象所能容纳的元素个数已达到上限，不能再插入元素。");
		}
		for (int i = 0; i < length; i++)
		{
			insert(point, value[i]);
			point = next(point);
		}
		return;
	}

	template<class T>
	inline Value<T>* DiscontinuityDynamicMemory<T>::address(unsigned long long n)
	{
		if (n > _size - 1) {
			Over_Flow e("访问的元素超出了对象所以元素的总和。");
			throw(e);
		}
		Value<T>* work = begin();
		for (unsigned long long i = 0; i < n; i++)
		{
			work = next(work);
		}
		return work;
	}

	template<class T>
	inline void DiscontinuityDynamicMemory<T>::remove(Value<T>* point)
	{
		if (empty()) {
			Over_Flow e("该对象是空的，不能删除元素。");
			throw(e);
		}
		Value<T>* pp = point;
		delete point->value;
		while (true)
		{
			if (pp == this->_top) {
				break;
			}
			else
			{
				*pp->value = *pp->next->value;
				pp = pp->next;
			}
		}
		this->pop();
		return;
	}

	template<class T>
	inline void DiscontinuityDynamicMemory<T>::remove(unsigned long long n)
	{
		remove(address(n));
		return;
	}

	template<class T>
	inline void DiscontinuityDynamicMemory<T>::remove(Value<T>* start, Value<T>* finish)
	{
		Value<T>* pp = start;
		unsigned long long need = 0;
		while (true)
		{
			if (pp == finish) {
				break;
			}
			else
			{
				need++;
				pp = next(pp);
			}
		}
		need++;
		pp = start;
		for (unsigned long long i = 0; i < need; i++) {
			remove(pp);
		}
		return;
	}

	template<class T>
	inline void DiscontinuityDynamicMemory<T>::remove(unsigned long long start, unsigned long long finish)
	{
		if (start > finish) {
			Illegal_Data e("开始元素的序号大于结束元素的序号，该序号不合法。");
			throw(e);
		}
		remove(address(start), address(finish));
		return;
	}

	template<class T>
	inline void DiscontinuityDynamicMemory<T>::copy(DiscontinuityDynamicMemory<T>& value)
	{
		this->clear();
		this->limited = value.limited;
		this->max_size = value.max_size;
		this->_size = 0;
		T a;
		for (unsigned long long i = 0; i < value._size; i++) {
			this->push_back(a);
		}
		Value<T>* v = this->_bottom;
		Value<T>* vv = value._bottom;
		while (true)
		{
			if (v == this->_top) {
				*v->value = *vv->value;
				break;
			}
			*v->value = *vv->value;
			v = v->next;
			vv = vv->next;
		}
		return;
	}

	template<class T>
	inline T& DiscontinuityDynamicMemory<T>::operator[](unsigned long long n)
	{
		return *(address(n)->value);
	}

	template<class T>
	inline T& DiscontinuityDynamicMemory<T>::operator[](Value<T>* point)
	{
		return *(point->value);
	}

	template<class T>
	inline void DiscontinuityDynamicMemory<T>::operator=(DiscontinuityDynamicMemory<T>& value)
	{
		this->copy(value);
		return;
	}

	template<class T>
	inline void DiscontinuityDynamicMemory<T>::clear()
	{
		while (true)
		{
			if (_size == 0) {
				break;
			}
			pop();
		}
	}

	template<class T>
	inline DiscontinuityDynamicMemory<T>::~DiscontinuityDynamicMemory()
	{
		while (true)
		{
			if (_size == 0) {
				break;
			}
			pop();
		}
	}

	template<class T>
	inline Value<T>* DiscontinuityDynamicMemory<T>::begin()
	{
		if (_size == 0) {
			Over_Flow e("该对象是空的，不能获取指向第一个元素的指针。");
			throw(e);
		}
		return _bottom;
	}

	template<class T>
	inline Value<T>* DiscontinuityDynamicMemory<T>::end()
	{
		if (_size == 0) {
			Under_Flow e("该对象是空的，不能获取指向最后一个元素的指针。");
			throw(e);
		}
		return _top;
	}

	template<class T>
	inline Value<T>* DiscontinuityDynamicMemory<T>::next(Value<T>* point)
	{
		if (_size == 0) {
			Over_Flow e("该对象是空的，不能获取指向下一个元素的指针。");
			throw(e);
		}
		if (point == _top) {
			Over_Flow e("不能访问顶部指针的下一个元素。");
			throw(e);
		}
		return point->next;
	}

	template<class T>
	inline Value<T>* DiscontinuityDynamicMemory<T>::last(Value<T>* point)
	{
		if (_size == 0) {
			Under_Flow e("该对象是空的，不能获取指向上一个元素的指针。");
			throw(e);
		}
		if (point == _bottom) {
			Under_Flow e("不能访问底部指针的上一个元素。");
			throw(e);
		}
		return point->last;
	}

	inline std::string Error::get_description()
	{
		return _description;
	}

	inline Over_Flow::Over_Flow(std::string description)
	{
		this->_description = description;
	}

	inline Under_Flow::Under_Flow(std::string description)
	{
		this->_description = description;
	}

	inline Illegal_Data::Illegal_Data(std::string description)
	{
		this->_description = description;
	}

	template<class T>
	inline DiscontinuityDynamicMemory<T>::DiscontinuityDynamicMemory(DiscontinuityDynamicMemory<T>& value)
	{
		this->limited = value.limited;
		this->max_size = value.max_size;
		this->_size = 0;
		T a;
		for (unsigned long long i = 0; i < value._size; i++) {
			this->push_back(a);
		}
		Value<T>* v = this->_bottom;
		Value<T>* vv = value._bottom;
		while (true)
		{
			if (v == this->_top) {
				*v->value = *vv->value;
				break;
			}
			*v->value = *vv->value;
			v = v->next;
			vv = vv->next;
		}
		return;
	}
}
#endif // !Discontinuity_Dynamic_Memory_H
