#include<iostream>
#include<typeinfo>
#include<string>
#include<vector>
using namespace std;

/*
//虚析构函数
class Base
{
public:
	Base(int data = 10) :ma(data) { cout << "Base()" << endl; }
	~Base() { cout << "~Base()" << endl; }
	virtual void show() { cout << "call Base::show()" << endl; }
protected:
	int ma;
};
class Derive : public Base
{
public:
	Derive(int data = 20)
		:Base(data), mb(data) 
	{
		cout << "Derive()" << endl;
	}
	~Derive() { cout << "~Derive()" << endl; }
private:
	int mb;
};
class Base1
{
public:
	Base1(int data = 10) :ma(data) { cout << "Base1()" << endl; }
	virtual ~Base1() { cout << "~Base1()" << endl; }//虚析构函数
	virtual void show() { cout << "call Base1::show()" << endl; }
protected:
	int ma;
};
class Derive1 : public Base1
{
public:
	Derive1(int data = 20)
		:Base1(data), mb(data)
	{
		cout << "Derive1()" << endl;
	}
	~Derive1() { cout << "~Derive1()" << endl; }//自动称为虚析构函数
private:
	int mb;
};

int main()
{
//虚析构函数
	//虚函数依赖
		//1.虚函数能产生地址，存储在 vftable 当中
		//2.对象必须存在（vfptr -> vftable -> 虚函数地址）
	//构造函数不能成为虚函数：调用了虚函数，对象才产生，构造函数中调用了虚函数，也不会发生静态绑定
	//static 静态成员方法不能成为虚函数：静态方法调用不依赖对象
	//基类的析构函数时虚函数，派生类的析构函数自动称为虚函数
	//当基类的指针（引用）指向堆上 new 出来的派生类对象的时候基类的析构函数必须实现为虚函数
	//因为当 delete pb（基类的指针），它调用析构函数的时候，必须发生动态绑定，否则会导致派生类的析构函数无法调用
	//派生类覆盖虚析构，只是虚函数表中析构函数的入口地址被替换，但基类析构函数本身并没有消失
	//派生类析构函数执行完毕后，C++ 会自动、隐式地调用基类的析构函数（这是析构的 “链式规则”），和虚函数表无关
	Base* pb = new Derive(10);
	pb->show();//动态绑定
	delete pb;//派生类的析构函数没有被调用到
	//pb->Base Base::~Base 对于析构函数来说是静态绑定
	//call Base::~Base
	Base1* pb1 = new Derive1(10);
	pb1->show();
	delete pb1;
	//pb->Base Base::~Base 对于析构函数来说是动态绑定
	//pb -> Derive Derive vfrable &Derive::Derive

	system("pause");
	return 0;
}
*/