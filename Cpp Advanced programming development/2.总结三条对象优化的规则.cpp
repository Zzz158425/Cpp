#include<iostream>
using namespace std;
//2026.4.23

/*
//1.函数参数传递过程中，对象优先按引用传递，不要值传递
class Test
{
public:
	Test(int a = 10) : ma(a)
	{
		cout << "Test(int)" << endl;
	}
	~Test()
	{
		cout << "~Test()" << endl;
	}
	Test(const Test& t) : ma(t.ma)
	{
		cout << "Test(const Test&)" << endl;
	}
	Test& operator=(const Test& t)
	{
		cout << "operator=" << endl;
		ma = t.ma;
		return *this;
	}
	int getData()const
	{
		return ma;
	}
private:
	int ma;
};
Test GetObject(Test& t)//优化一，对象按引用传递后，无 t1 的拷贝构造，即出作用域也不需要析构
{
	int val = t.getData();
	//Test tmp(val);
	//return tmp;
	return Test(val);//优化二，返回一个临时对象，此时C++ 编译器会自动优化，不返回临时对象，直接构造 main 函数栈帧上的临时对象
}

int main()
{
//1.函数参数传递过程中，对象优先按引用传递，不要值传递
//2.函数返回对象的时候，应该优先返回一个临时对象，而不要返回一个定义过的对象
//3.接收返回值是对象的函数调用的时候，优先按初始化的方式接收，不要按赋值的方式接收
	Test t1;
	//Test t2;
	//t2 = GetObject(t1);
	Test t2 = GetObject(t1);//优化三，以初始化的方式接收，此时用 main 函数栈帧上的临时对象直接拷贝构造同类型的新对象 t3，编译器自动优化不再产生临时对象再 operator=，直接对 t3 进行拷贝构造

	system("pause");
	return 0;
}
*/