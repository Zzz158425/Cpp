#include<iostream>
#include<typeinfo>
#include<string>
using namespace std;

/*
//vector 字符串对象的迭代器 iterator 实现
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
		iterator(T* ptr = nullptr)
			:_ptr(ptr) { }
		bool operator!=(const iterator& it) const 
		{
			return _ptr != it._ptr;
		}
		void operator++()
		{
			++_ptr;
		}
		T& operator*() { return *_ptr; }//int data = *it; *it = 20;
		const T& operator*() const { return *_ptr; }//int data = *it;
	private:
		T* _ptr;
	};
	iterator begin() { return iterator(_first); }//begin 返回的是容器底层首元素的迭代器的表示
	iterator end() { return iterator(_last); }//begin 返回的是容器底层末尾元素后继位置的迭代器的表示
private:
	T* _first;//指向数组起始的位置
	T* _last;//指向数组中有限元素的后继位置
	T* _end;//指向数组空间的后继位置
	Alloc _allocator;//定义容器的空间适配器对象
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
//vector 字符串对象的迭代器 iterator 实现
	vector1<int> vec;
	for (int i = 0; i < 20; i++)
	{
		vec.push_back(rand() % 100 + 1);
	}
	int size = vec.size();
	for (int i = 0; i < size; i++)//中括号重载运算符
	{
		cout << vec[i] << " ";
	}
	cout << endl;
	vector1<int>::iterator it = vec.begin();//迭代器
	for (; it != vec.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	auto it1 = vec.begin();//auto
	for (; it1 != vec.end(); ++it1)
	{
		cout << *it1 << " ";
	}
	cout << endl;
	for (int val : vec)//foreach
	{
		cout << *it1 << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
*/