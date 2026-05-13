#include<iostream>
#include<typeinfo>
#include<string>
#include<vector>
using namespace std;

/*
//实现 vector 容器失效
template<typename T>
struct Allocator
{
	//负责内存开辟
	T* allocate(size_t size)
	{
		return (T*)malloc(sizeof(T) * size);
	}
	//负责内存释放
	void deallocate(void* p)
	{
		free(p);
	}
	//负责对象构造
	void construct(T* p, const T& val)
	{
		new (p) T(val);//定位 new
	}
	//负责对象析构
	void destroy(T* p)
	{
		p->~T();//~T() 代表了 T 类型的析构函数
	}
};
template<typename T, typename Alloc = Allocator<T>>
class vector1
{
public:
	vector1(int size = 10, const Alloc = Allocator<T>())
	{
		_first = _allocator.allocate(size);//只开辟内存
		_last = _first;
		_end = _first + size;
	}
	~vector1()
	{
		//析构有效元素
		for (T* p = _first; p != _last; p++)
		{
			_allocator.destroy(p);
		}
		_allocator.deallocate(_first);//释放堆上的数组内存
		_first = _last = _end = nullptr;
	}
	vector1(const vector1<T>& rhs)
	{
		int size = rhs._end - rhs._first;
		_first = _allocator.allocate(size);//只开辟内存
		int len = rhs._last - rhs._first;
		for (int i = 0; i < len; i++)
		{
			_allocator.construct(_first + i, rhs._first[i]);
		}
		_last = _first + len;
		_end = _first + size;
	}
	vector1<T>& operator=(const vector1<T>& rhs)
	{
		if (this == _first)
		{
			return *this;
		}
		//析构有效元素
		for (T* p = _first; p != _last; p++)
		{
			_allocator.destroy(p);
		}
		_allocator.deallocate(_first);//释放堆上的数组内存
		int size = rhs._end - rhs._first;
		_first = new T[size];
		int len = rhs._last - rhs._first;
		for (int i = 0; i < len; i++)
		{
			_first[i] = rhs._first[i];
		}
		_last = _first + len;
		_end = _first + size;
		return *this;
	}
	//从容器末尾添加元素
	void push_back(const T& val)
	{
		if (full())
		{
			expand();
		}
		//*_last++ = val;
		_allocator.construct(_last, val);
		_last++;
	}
	//从容器末尾删除元素
	void pop_back()
	{
		if (empty())
		{
			return;
		}
		verify(_last - 1, _last);
		//_last--;
		_last--;
		_allocator.destroy(_last);

	}
	//返回容器末尾的元素值
	T back() const
	{
		return *(_last - 1);
	}
	bool full() const { return _last == _end; }//判断容器是否满
	bool empty() const { return _last == _first; } //判断容器是否为空
	int size() const { return _last - _first; }//返回容器个数
	T& operator[](int index)//连续存储，可以提供中括号重载
	{
		//判断 index 合法性
		if (index < 0 || index >= size())
		{
			throw "OutOfRangeException";
		}
		return _first[index];
	}
	//vector 迭代器实现
	class iterator
	{
	public:
		friend class vector1<T, Alloc>;
		iterator(vector1<T, Alloc> *pvec = nullptr, T* ptr = nullptr)
			:_ptr(ptr), _pVec(pvec)
		{
			Iterator_Base* itb = new Iterator_Base(this, _pVec->_head._next);//this 表示当前正在创建的迭代器对象的地址
			_pVec->_head._next = itb;
		}
		bool operator!=(const iterator& it) const
		{
			//检查迭代器的有效性
			if (_pVec == nullptr || _pVec != it._pVec)
			{
				throw "iterator incompatable!";
			}
			return _ptr != it._ptr;
		}
		void operator++()
		{
			//检查迭代器的有效性
			if (_pVec == nullptr)
			{
				throw "iterator invalid!";
			}
			++_ptr;
		}
		T& operator*()
		{ 
			//检查迭代器的有效性
			if (_pVec == nullptr)
			{
				throw "iterator invalid!";
			}
			return *_ptr; 
		}
		const T& operator*() const 
		{ 
			//检查迭代器的有效性
			if (_pVec == nullptr)
			{
				throw "iterator invalid!";
			}
			return *_ptr; 
		}
	private:
		T* _ptr;
		vector1<T, Alloc>* _pVec;//当前迭代器迭代的是哪个容器对象
	};
	iterator begin() { return iterator(this, _first); }//begin 返回的是容器底层首元素的迭代器的表示
	iterator end() { return iterator(this, _last); }//begin 返回的是容器底层末尾元素后继位置的迭代器的表示
	//检查迭代器失效
	void verify(T* first, T* last)
	{
		Iterator_Base* pre = &this->_head;
		Iterator_Base* it = this->_head._next;
		while (it != nullptr)
		{
			if (it->_cur->_ptr >= first && it->_cur->_ptr <= last)
			{
				//迭代器失效，把 iterator 持有的容器指针置 nullptr
				it->_cur->_pVec = nullptr;
				//删除当前迭代器节点，继续判断后面的迭代器节点是否失效
				pre->_next = it->_next;
				delete it;
				it = pre->_next;
			}
			else
			{
				pre = it;
				it = it->_next;
			}
		}
	}
	//自定义 vector 容器 insert 方法实现
	//不考虑扩容，不考虑 it.prt 指针的合法性
	iterator insert(iterator it, const T& val)
	{
		verify(it._ptr - 1, _last);
		T* p = _last;
		while (p > it._ptr)
		{
			_allocator.construct(p, *(p - 1));//用上一个对象的值在当前位置构造一个新对象
			_allocator.destroy(p - 1);//析构上一个对象
			p--;
		}
		_allocator.construct(p, val);
		_last++;
		return iterator(this, p);
	}
	//自定义 vector 容器 erase 方法实现
	iterator erase(iterator it)
	{
		verify(it._ptr - 1, _last);
		T* p = it._ptr;

		while (p < _last - 1)
		{
			_allocator.destroy(p);//析构当前位置的对象
			_allocator.construct(p, *(p + 1));//用下一个对象的值在当前位置构造一个新对象
			p++;
		}
		_allocator.construct(p);
		_last--;
		return iterator(this, p);
	}
private:
	T* _first;//指向数组起始的位置
	T* _last;//指向数组中有限元素的后继位置
	T* _end;//指向数组空间的后继位置
	Alloc _allocator;//定义容器的空间适配器对象
	//容器迭代器失效增加
	struct Iterator_Base
	{
		Iterator_Base(iterator* c = nullptr, Iterator_Base* n = nullptr)
			: _cur(c), _next(n) { }
		iterator* _cur;//链表值域
		Iterator_Base* _next;//链表地址域
	};
	Iterator_Base _head;
	//容器 2 倍扩容
	void expand()
	{
		int size = _end - _first;
		T* ptmp = _allocator.allocate(size * 2);
		for (int i = 0; i < size; i++)
		{
			_allocator.construct(ptmp + i, _first[i]);
		}
		for (T* p = _first; p != _last; p++)
		{
			_allocator.destroy(p);
		}
		_allocator.deallocate(_first);//释放堆上的数组内存
		_first = ptmp;
		_last = _first + size;
		_end = _first + (size * 2);
	}
};

int main()
{
//容器的迭代器失效问题
	//删除(erase)迭代器指向的元素时，当前位置到容器末尾位置的所有的迭代器全部失效，删除点迭代器仍有效
	//非扩容增加(insert)迭代器指向的元素时，当前位置到容器末尾位置的所有的迭代器全部失效，插入点迭代器仍有效
	//扩容增加(insert)迭代器指向的元素时，指向元素的原来的迭代器全部失效
	vector<int> vec;
	for (int i = 0; i < 20; i++)
	{
		vec.push_back(rand() % 100 + 1);
	}
	for (int v : vec)
	{
		cout << v << " ";
	}
	cout << endl;
	//把 vec 容器总所有的偶数全部删除
	//auto it = vec.begin();
	//for (; it != vec.end(); ++it)
	//{
	//	if (*it % 2 == 0)
	//	{
	//		
	//		vec.erase(it);迭代器 it 失效了，当第一次调用 rease 以后
	//	};
	//}
	//给 vec 容器中所有的偶数前面添加一个小于偶数值 1 的数字
	//auto it = vec.begin();
	//for (; it != vec.end(); ++it)
	//{
	//	if (*it % 2 == 0)
	//	{
	//		vec.insert(it, *it - 1); 迭代器 it 失效了，当第一次调用 rease 以后
	//	};
	//}

//容器的迭代器失效问题解决
	//对插/删除点的迭代器进行更新操作
	//把 vec 容器总所有的偶数全部删除
	auto it = vec.begin();
	while (it != vec.end())
	{
		if (*it % 2 == 0)
		{
			
			it = vec.erase(it);//erase 返回指向被删元素下一个位置的迭代器，此时应接收新的迭代器 iterator
		}
		else
		{
			++it;//没有进行删除操作才进行加加
		}
	}
	for (int v : vec)
	{
		cout << v << " ";
	}
	cout << endl;
	//给 vec 容器中所有的偶数前面添加一个小于偶数值 1 的数字
	vector<int> vec1;
	for (int i = 0; i < 20; i++)
	{
		vec1.push_back(rand() % 100 + 1);
	}
	for (int v : vec1)
	{
		cout << v << " ";
	}
	cout << endl;
	auto it1 = vec1.begin();
	for (; it1 != vec1.end(); ++it1)
	{
		if (*it1 % 2 == 0)
		{
			it1 = vec1.insert(it1, *it1 - 1);//接收新的迭代器 iterator
			++it1;
		}
	}
	for (int v : vec1)
	{
		cout << v << " ";
	}
	cout << endl;

//实现 vector 容器失效
	//每个容器对象（比如 v1、v2）内部都有一个独立的 _head 成员，对应一条独立的迭代器管理链表 —— 链表不是全局的，而是跟着容器对象走，每个容器只管理自己创建的迭代器。
	vector1<int> vec2;
	for (int i = 0; i < 20; i++)
	{
		vec.push_back(rand() % 100 + 1);
	}
	auto it2 = vec.end();
	//vec.pop_back();verify(_last - 1, _last)
	auto it3 = vec.end();
	cout << (it2 != it3) << endl;

//自定义 vector 容器 insert 方法实现
	vector1<int> vec3(200);
	for (int i = 0; i < 20; i++)
	{
		vec3.push_back(rand() % 100 + 1);
	}
	for (int v : vec3)
	{
		cout << v << " ";
	}
	cout << endl;
	auto it4 = vec3.begin();
	for (; it4 != vec3.end(); ++it4)
	{
		if (*it4 % 2 == 0)
		{
			it4 = vec3.insert(it4, *it4 - 1);
			++it4;
		}
	}
	for (int v : vec3)
	{
		cout << v << " ";
	}
	cout << endl;

//自定义 vector 容器 erase 方法实现
	vector1<int> vec4(200);
	for (int i = 0; i < 20; i++)
	{
		vec4.push_back(rand() % 100 + 1);
	}
	for (int v : vec4)
	{
		cout << v << " ";
	}
	cout << endl;
	auto it5 = vec4.begin();
	for (; it5 != vec4.end(); ++it5)
	{
		if (*it5 % 2 == 0)
		{
			it5 = vec4.insert(it5, *it5 - 1);
			++it5;
		}
	}
	for (int v : vec4)
	{
		cout << v << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
*/