#include<iostream>
#include<typeinfo>
#include<string>
#include<vector>
using namespace std;

/*
//派生类的构造过程
class Base
{
public:
	Base(int data) :ma(data) { cout << "Base()" << endl; }
	~Base() { cout << "~Base()" << endl; }
protected:
	int ma;
};
class Derive : public Base
{
public:
	Derive(int data) 
		:Base(data), mb(data) { cout << "Derive()" << endl; }//不允许派生类这样：ma(data)，直接初始化继承来的成员变量，会去基类寻找合适的构造函数初始化
	~Derive() { cout << "~Derive()" << endl; }
protected:
	int mb;
};

int main()
{
//派生类的构造过程
	//派生类从基类可以继承所有的成员（变量与方法），除了析构函数与构造函数
	//不允许派生类直接初始化继承来的成员变量，会去基类寻找合适的构造函数初始化
	//可以通过调用基类相应的构造函数来初始化
	//派生类的构造函数与析构函数，负责初始化和清理派生类部分
	//派生类从基类继承过来的成员，是由基类的构造和析构函数负责
	//派生类对象构造与析构的过程是：
		//1.派生类调用基类的构造函数，初始化从基类继承来的成员
		//2.调用派生类自己的构造函数，初始化派生类自己特有的成员
		//...
		//3.调用派生类的析构函数，释放派生类成员肯占用的外部资源（堆内存，文件）
		//4.调用基类的析构函数，释放派生类内存中，从基类继承过来的成员可能占用的外部资源（堆内存，文件）

	Derive d(20);

	system("pause");
	return 0;
}
*/