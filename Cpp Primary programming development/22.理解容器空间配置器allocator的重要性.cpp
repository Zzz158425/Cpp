#include<iostream>
#include<typeinfo>
using namespace std;

/*
//容器 vector 无空间配置器 allocator 情况
template<typename T>
class vector
{
public:
	vector(int size = 10)
	{
		_first = new T[size];
		_last = _first;
		_end = _first + size;
	}
	~vector()
	{
		//析构容器有效的元素，然后释放 _first 指针指向的堆内存
		delete[]_first;
		_first = _last = _end = nullptr;
	}
	vector(const vector<T>& rhs)
	{
		int size = rhs._end - rhs._first;
		_first = new T[size];
		int len = rhs._last - rhs._first;
		for (int i = 0; i < len; i++)
		{
			_first[i] = rhs._first[i];
		}
		_last = _first + len;
		_end = _first + size;
	}
	vector<T>& operator=(const vector<T>& rhs)
	{
		if (this == _first)
		{
			return *this;
		}
		delete[]_first;
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
		*_last++ = val;
	}
	//从容器末尾删除元素
	void pop_back()
	{
		if (empty())
		{
			return;
		}
		_last--;
	}
	//返回容器末尾的元素值
	T back() const
	{
		return *(_last - 1);
	}
	bool full() const { return _last == _end; }//判断容器是否满
	bool empty() const { return _last == _first; } //判断容器是否为空
	int size() const { return _last - _first; }//返回容器个数
private:
	T* _first;//指向数组起始的位置
	T* _last;//指向数组中有限元素的后继位置
	T* _end;//指向数组空间的后继位置
	//容器 2 倍扩容
	void expand()
	{
		int size = _end - _first;
		T* ptmp = new T[size * 2];
		for (int i = 0; i < size; i++)
		{
			ptmp[i] = _first[i];
		}
		delete[]_first;
		_first = ptmp;
		_last = _first + size;
		_end = _first + (size * 2);
	}
};
class Test
{
public:
	Test() { cout << "Test()" << endl; }
	~Test() { cout << "~Test()" << endl; }
	Test(const Test&) { cout << "Test(const Test&)" << endl; }
};

//容器 vector 空间配置器 allocator
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
		//_first = new T[size];
		_first = _allocator.allocate(size);//只开辟内存
		_last = _first;
		_end = _first + size;
	}
	~vector1()
	{
		//delete[]_first;
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
		//_first = new T[size];
		_first = _allocator.allocate(size);//只开辟内存
		int len = rhs._last - rhs._first;
		for (int i = 0; i < len; i++)
		{
			//_first[i] = rhs._first[i];
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
		//delete[]_first;
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
private:
	T* _first;//指向数组起始的位置
	T* _last;//指向数组中有限元素的后继位置
	T* _end;//指向数组空间的后继位置
	Alloc _allocator;//定义容器的空间适配器对象
	//容器 2 倍扩容
	void expand()
	{
		int size = _end - _first;
		//T* ptmp = new T[size * 2];
		T* ptmp = _allocator.allocate(size * 2);
		for (int i = 0; i < size; i++)
		{
			//ptmp[i] = _first[i];
			_allocator.construct(ptmp + i, _first[i]);
		}
		//delete[]_first;
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
//容器 vector 无空间配置器 allocator 情况
	//在构造与析构函数中使用了 new 和 delete，new 会分配内存，自动调用构造函数；delete 会释放内存，自动调用析构函数
		//使得定义了一个空容器，但是会创建数个对象
		//在程序结束时，非有效的元素也会被全部析构一遍
	//从容器中删除元素时，没有调用对象的析构函数
	Test t1, t2, t3;
	cout << "----------vector-----------" << endl;
	vector<Test>vec;
	//空容器仍会运行数个构造函数，需要把内存开辟和对象构造分开处理，在空容器时，应该只是开辟空间，而不能去构造对象
	//在析构函数中，delete 会使 _first 指向的数组的每一个元素都被当做了一个有效的 Test 对象，从而全部析构一遍，需要析构容器有效的元素，然后释放 _first 指针指向的堆内存
	vec.push_back(t1);
	vec.push_back(t2);
	vec.push_back(t3);
	cout << "----------vector-----------" << endl;
	vec.pop_back();//若容器对象占用外部资源，而 pop_back 只是 _last--，会使的该对象占用的外部资源无法访问，delete 会使从容器中删除一个元素时，会释放数组的堆内存，只需要析构对象，要把对象的析构和内存释放分离开
	cout << "----------vector-----------" << endl;

//容器 vector 空间配置器 allocator
	//为了解决上述问题，引入空间配置器 allocator，核心就是将内存开辟与对象构造分离，内存释放与对象析构分离
	//空间配置器 allocator 作用：内存开辟，内存释放，对象构造，对象析构
	cout << "----------vector1-----------" << endl;
	vector1<Test>vec1;
	vec1.push_back(t1);
	vec1.push_back(t2);
	vec1.push_back(t3);
	cout << "----------vector1-----------" << endl;
	vec1.pop_back();
	cout << "----------vector1-----------" << endl;

	system("pause");
	return 0;
}
*/