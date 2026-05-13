#include<iostream>
#include<typeinfo>
#include<string>
#include<vector>
using namespace std;

/*
//菱形继承问题
class A
{
public:
	A(int data) :ma(data) { cout << "A()" << endl; }
	~A() { cout << "~A()" << endl; }
protected:
	int ma;
};
class B : public A
{
public:
	B(int data) :A(data), mb(data) { cout << "B()" << endl; }
	~B() { cout << "~B()" << endl; }
protected:
	int mb;
};
class C : public A
{
public:
	C(int data) :A(data), mc(data) { cout << "C()" << endl; }
	~C() { cout << "~C()" << endl; }
protected:
	int mc;
};
class D : public B, public C
{
public:
	D(int data) :B(data), C(data), md(data) { cout << "D()" << endl; }
	~D() { cout << "~D()" << endl; }
protected:
	int md;
};

//虚继承
class A1//虚基类
{
public:
	A1(int data) :ma(data) { cout << "A1()" << endl; }
	~A1() { cout << "~A1()" << endl; }
protected:
	int ma;
};
class B1 : virtual public A1//虚继承
{
public:
	B1(int data) :A1(data), mb(data) { cout << "B1()" << endl; }
	~B1() { cout << "~B1()" << endl; }
protected:
	int mb;
};
class C1 : virtual public A1//虚继承
{
public:
	C1(int data) :A1(data), mc(data) { cout << "C1()" << endl; }
	~C1() { cout << "~C1()" << endl; }
protected:
	int mc;
};
class D1 : public B1, public C1
{
public:
	D1(int data) :A1(data), B1(data), C1(data), md(data) { cout << "D1()" << endl; }
	~D1() { cout << "~D1()" << endl; }
protected:
	int md;
};

int main()
{
//菱形继承问题
	//多重继承会导致菱形继承问题
	//菱形继承：
		//      A(ma)
		//     /     \
		//    /       \
		//B(ma、mb)    C(ma,mc)
		//    \       /
		//     \     /
		//      D(ma,mb,ma,mc,md)
		//D
		//B::
			//A::ma
			//mb
		//C::
			//A::ma
			//mc
		//md
	//菱形继承问题：普通菱形继承下，最终派生类从多条路径重复继承顶层基类的同一成员，导致冗余、歧义、数据不一致
	D d(10);//重复构造了 A

//虚继承
	//虚继承后，A::ma 属于 D，需要 D 来初始化 
	//      A(ma)（虚基类）
	//virtu/al   \virtual
	//    /       \
	//B(ma、mb)    C(ma,mc)
	//    \       /
	//     \     /
	//      D(ma,mb,ma,mc,md)
	//D
	//B::
		//vbptr 偏移为 14h
		//mb
	//C::
		//vbptr 偏移为 0Ch
		//mc
	//md
	//A::ma 重复的 A::ma 只保留一份，为此解决了菱形继承问题
	D1 d1(10);

	system("pause");
	return 0;
}
*/