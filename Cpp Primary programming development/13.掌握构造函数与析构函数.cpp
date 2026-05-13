#include<iostream>
#include<typeinfo>
using namespace std;

/*
//OOP 实现顺序栈
class SeqStack
{
public:
	void init(int size = 10)
	{
		_pstack = new int[size];
		_top = -1;
		_size = size;
	}
	void release()
	{
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

//构造函数与析构函数
class SeqStack1
{
public:
	//构造函数
	SeqStack1(int size = 10)
	{
		cout << this << "SeqStack1()" << endl;
		_pstack = new int[size];
		_top = -1;
		_size = size;
	}
	//析构函数
	~SeqStack1()
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
SeqStack1 gs;//定义全局对象会等程序结束才析构

int main()
{
//OOP 实现顺序栈
	//若不使用析构与构造函数，每次必须自己调用初始化与释放申请空间的函数
	SeqStack s;
	s.init(5);
	for (int i = 0; i < 15; i++)
	{
		s.push(rand() % 100);
	}
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
	s.release();

//构造函数与析构函数
	//构造函数可以带参数，可以重载，析构函数不可以带参数，不可以重载，构造完成，对象产生
	//先构造的后析构，先析构的后构造
	//函数名字与类名一样，无返回值，析构函数在函数名字前加 ~
	//没有提供任何构造函数时，会为你生成默认构造和析构函数，为空函数
	SeqStack1 s1;
	for (int i = 0; i < 15; i++)
	{
		s1.push(rand() % 100);
	}
	while (!s1.empty())
	{
		cout << s1.top() << " ";
		s1.pop();
	}
	cout << endl;
	SeqStack1 s2(50);
	//s2.~SeqStack1();可以手动调用析构，不建议，调用以后可以视为对象不存在了，内存仍在
	//s2.push(30);此时若调用 s2，会非法访问堆内存
	SeqStack1* ps = new SeqStack1(60);//new 先会 malloc 内存开辟，然后再调用构造函数，开辟在堆上，不会自动调用析构函数，需手动释放
	ps->push(70);
	ps->push(80);
	ps->pop();
	cout << ps->top() << endl;
	delete ps;//delete 先调用析构函数，然后再 free(ps)

	system("pause");
	return 0;
}
*/