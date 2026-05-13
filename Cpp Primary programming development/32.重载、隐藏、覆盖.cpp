#include<iostream>
#include<typeinfo>
#include<string>
#include<vector>
using namespace std;

/*
//重载、隐藏、覆盖
class Base
{
public:
	Base(int data = 10) :ma(data) { }
	void show() { cout << "Base::show()" << endl; }
	void show(int) { cout << "Base::show(int)" << endl; }
	~Base() { }
protected:
	int ma;
};
class Derive : public Base
{
public:
	Derive(int data = 20)
		:Base(data), mb(data) { }
	void show() { cout << "Derive::show()" << endl; }
	~Derive() { }
protected:
	int mb;
};

int main()
{
//重载、隐藏、覆盖
	//重载：一组函数要重载，必须处于同一作用域当中；而且名字相同，但参数类别不同
	//隐藏：在继承结果当中，派生类的同名成员，把基类的同名成员给隐藏调用了
	//覆盖：基类和派生类的方法，返回值、函数名以及参数列表都相同，而且基类的方法是虚函数，那么派生类的方法就自动处理成虚函数，他们之间成为覆盖关系
	Derive a;
	a.show();//只能调用自己作用域的函数
	//d.show(10);派生类的同名成员把基类的同名成员给隐藏，隐藏的是作用域，派生类无法调用基类 show(int)
	a.Base::show(10);//必须加基类作用域

//基类对象与派生类对象的转换
 	//在继承结果中进行上下的类型转换，默认只支持从下到上的类型的转换
	//基类对象 b <- 派生类对象 d，类型从下到上的转换
	Base b(10);
	Derive d;
	b = d;
	//基类对象 b -> 派生类对象 d，类型从上到下的转换，无法转换
	//d = b;无法转换

//基类指针与派生类指针的转换
	//基类指针（引用）<- 派生类对象，类型从下到上的转换
	Base* pb = &d;
	//默认情况下，只能访问派生类从基类继承来的成员
	pb->show();
	pb->show(10);
	((Derive*)pb)->show();//也可以强转为派生类，从而访问派生类成员
	//基类指针（引用）-> 派生类对象，类型从上到下的转换，无法转换
	//Derive* pd = &b;无法转换
	//Derive* pd = (Derive*)&b;不安全，涉及了内存的非法访问，因为派生类所占内存可能大于基类所占内存，解引用后可能会内存非法访问

	system("pause");
	return 0;
}
*/