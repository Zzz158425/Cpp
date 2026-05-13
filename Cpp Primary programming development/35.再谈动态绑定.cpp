#include<iostream>
#include<typeinfo>
#include<string>
#include<vector>
using namespace std;

/*
//不是所有的虚函数的调用一定就是动态绑定
class Base
{
public:
	Base(int data = 0) :ma(data) { }
	virtual void show() { cout << "Base::show()" << endl; }//虚函数
protected:
	int ma;
};
class Derive : public Base
{
public:
	Derive(int data = 0)
		:Base(data), mb(data) { }
	void show() { cout << "Derive::show()" << endl; }//虚函数
private:
	int mb;
};

int main()
{
//不是所有的虚函数的调用一定就是动态绑定
	//在类的构造函数中，调用虚函数，也是静态绑定，构造函数中调用其他虚函数，不会发生动态绑定
	//用对象本身调用虚函数，是静态绑定
	//必须由指针/引用调用虚函数才会发生动态绑定
	//不管使用基类指针/引用指向基类对象，还是使用基类对象指向派生类对象，均为动态绑定
	Base b;
	Derive d;
	b.show();//静态绑定
	d.show();//静态绑定
	Base* pb1 = &b;
	pb1->show();//动态绑定
	Base* pb2 = &d;
	pb2->show();//动态绑定
	Base& rb1 = b;
	rb1.show();//动态绑定
	Base& rb2 = d;
	rb2.show();//动态绑定
	Derive* pd3 = &d;
	pd3->show();//动态绑定
	Derive& rd3 = d;
	rd3.show();//动态绑定
	Derive* pd4 = (Derive*)&b;
	pd4->show();//动态绑定 pd4 -> b vfptr -> Base vftale Base::show

	system("pause");
	return 0;
}
*/