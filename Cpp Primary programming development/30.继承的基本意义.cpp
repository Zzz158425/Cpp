#include<iostream>
#include<typeinfo>
#include<string>
#include<vector>
using namespace std;

/*
//继承的基本意义
class A
{
public:
	int ma = 0;
protected:
	int mb;
private:
	int mc;//自己或者友元能访问私有的成员
};
//继承 A 基类/父类，B 派生类/子类
class B : public A
{
public:
	void func()
	{
		cout << mb << endl;
	}
	int md;
protected:
	int me;
private:
	int mf;
};
class C : protected A
{
public:
	void func()
	{
		cout << mb << endl;
	}
	int md;
protected:
	int me;
private:
	int mf;
};
class D : private A
{
public:
	void func()
	{
		cout << mb << endl;
	}
	int md;
protected:
	int me;
private:
	int mf;
};
class D : private A
{
public:
	void func()
	{
		cout << mb << endl;
	}
	int md;
protected:
	int me;
private:
	int mf;
};
class E : public D
{
	void func()
	{
		//cout << ma << endl; 不可见
	}
};
int main()
{
//继承的基本意义
	//类和类之间的关系：组合与继承
		//组合：一部分的关系
		//继承：一种关系
	//继承好处
		//代码复用
		//在基类中给所有派生类提供统一的虚函数接口，让派生类进行重写，然后就可以使用多态了
	//基类的成员的访问限定，在派生类里面是不可能超过继承方式的
	//继承方式      基类访问限定      派生类的访问      外部的访问限定
	//public
	//             public           public           Y
	//             protected        protected        N
	//             private          不可见            N
	//protected
	//             public           protected        N
	//             protected        protected        N
	//             private          不可见            N
	//private
	//             public           private          N
	//             protected        private          N
	//             private          不可见            N
	//多重继承看直接基类的权限
	//外部只能访问对象 public 的成员，protected 和 private 的成员无法直接访问
	//在继承结果中，派生类从基类可以继承过来 private 的成员，但是派生类却无法直接访问
	//protected 和 private 区别：在基类中定义的成员，想被派生类访问，但是不想被外部访问，那么在基类中，把相关成员定义为 protected
	//如果派生类和外部都不打算访问，那么在基类中，就把相关成员定义为 private 
	//默认继承方式：class 定义派生类，默认继承为 private，struct 定义派生类，默认继承为 public
	B b;
	cout << b.ma << endl;
	//cout << b.mb << endl;外部无法访问 protected
	//cout << b.mc << endl;不可见，无法访问
	C c;
	//cout << c.ma << endl;外部无法访问 protected
	//cout << c.mb << endl;外部无法访问 protected
	//cout << c.mc << endl;不可见，无法访问
	D d;
	//cout << d.ma << endl;外部无法访问 private
	//cout << d.mb << endl;外部无法访问 private
	//cout << d.mc << endl;不可见，无法访问

	system("pause");
	return 0;
}
*/