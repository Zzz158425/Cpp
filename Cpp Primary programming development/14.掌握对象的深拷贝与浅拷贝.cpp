#include<iostream>
#include<typeinfo>
using namespace std;
//2026.2.25

/*
//对象的深拷贝与浅拷贝
class SeqStack
{
public:
	//构造函数
	SeqStack(int size = 10)
	{
		cout << this << "SeqStack1()" << endl;
		_pstack = new int[size];
		_top = -1;
		_size = size;
	}
	//自定义拷贝构造函数，深拷贝
	SeqStack(const SeqStack& src)
	{
		cout << this << "SeqStack1(const SeqStack& src)" << endl;
		_pstack = new int[src._size];
		//此处慎用 memcpy 操作，若拷贝对象为对象占用了外部资源，memcpy 只会对其进行浅拷贝，可能会引发重复释放会产生释放野指针的操作
		for (int i = 0; i < src._top; ++i)
		{
			_pstack[i] = src._pstack[i];
		}
		_top = src._top;
		_size = src._size;
	}
	//赋值重载函数
	void operator=(const SeqStack& src)
	{
		cout << "operator=" << endl;
		//防止自赋值导致自身的 _pstack 被释放从而进行深拷贝出错
		if (this == &src)
		{
			return;
		}
		delete[]_pstack;//需要先释放当前对象占用的外部资源
		_pstack = new int[src._size];
		for (int i = 0; i < src._top; ++i)
		{
			_pstack[i] = src._pstack[i];
		}
		_top = src._top;
		_size = src._size;
	}
	//析构函数
	~SeqStack()
	{
		cout << this << "~SeqStack1()" << endl;
		delete[]_pstack;
		_pstack = nullptr;
	}
	void push(int val)
	{
		if (full())
		{
			resize();
		}
		_pstack[++_top] = val;
	}
	void pop()
	{
		if (empty())
		{
			return;
		}
		--_top;
	}
	int top()
	{
		return _pstack[_top];
	}
	bool empty() { return _top == -1; }
	bool full() { return _top == _size - 1; }
private:
	int* _pstack;//动态开辟数组，存储顺序栈的元素
	int _top;//指向栈顶元素位置
	int _size;//数组扩容的总大小
	void resize()
	{
		int* ptmp = new int[_size * 2];
		for (int i = 0; i < _size; i++)
		{
			ptmp[i] = _pstack[i];
		}
		delete[]_pstack;
		_pstack = ptmp;
		_size *= 2;
	}
};

int main()
{
//对象的深拷贝与浅拷贝
	//浅拷贝：对对象直接进行内存的数据拷贝
	//深拷贝：在堆区重新申请空间，进行拷贝操作
	//对象的成员变量有指针，且指针指向外部的一块堆内存，此时浅拷贝可能会导致重复释放同一块内存，需引入深拷贝
	SeqStack s;
	SeqStack s1(10);
	//SeqStack s2 = s1;自动生成默认拷贝构造函数，此时会把 s1 中的成员变量的值，直接赋给 s2 ，此时 _pstack 会指向同一块内存，重复释放会产生释放野指针的操作，导致程序挂掉
	SeqStack s2(s1);//自定义了拷贝构造函数，添加了深拷贝，重复释放不会产生释放野指针的操作
	//s2 = s1;赋值操作，会自动生成默认的赋值函数做直接的内存拷贝，会产生严重的问题：1.浅拷贝；2.s2 指向的外部资源被 s1 所指向的外部资源替换，此时找不到 s2 所指向的外部资源了
	s2 = s1;//重载了 =，添加了深拷贝，重复释放不会产生释放野指针的操作

	system("pause");
	return 0;
}
*/