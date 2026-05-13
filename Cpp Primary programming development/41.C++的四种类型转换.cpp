#include<iostream>
#include<typeinfo>
#include<string>
#include<vector>
using namespace std;

/*
//dynamic_cast
class Base
{
public:
	virtual void func() = 0;
};
class Derive1 : public Base
{
public:
	void func() { cout << "call Derivel1::func" << endl; }
};
class Derive2 : public Base
{
public:
	void func() { cout << "call Derivel2::func" << endl; }
	//Derive02func 实现新功能的 API 接口函数，此时 showFunc(&d2) 应调用 Derive02func 新方法
	void Derive02func() { cout << "call Derivel2::Derive202func" << endl; }
};
void showFunc(Base* p)
{
	//p->func();//动态绑定
	//Derive2* pd = static_cast<Derive2*>(p);static_cast 也能强制转换成功，但是无法识别 p 指向的是其他对象，还是 Derive2 对象，不安全
		//此时 showFunc(&d1); 也可以成功调用 Derive2::Derive02func 是因为成员函数的地址是编译期就确定好，不需要依赖对象的内存
		//当函数体里会访问成员变量 _data2 （_data2 为 Derive2 的成员变量，Derive1 无 _data2 成员变量）时，编译器按照 Derive2 的内存布局去 Derive1 找 _data2 成员变量；但 Derive1 对象的内存里根本没有 _data2，导致访问非法内存
	Derive2* pd = dynamic_cast<Derive2*>(p);
	//dynamic_cast 会检查 p 指针是否指向的是一个 Derive2 类型的对象
	//p -> vfptr -> vfrable RTTI 信息，如果是，dynamic_cast 类型转换成功
	//返回 Derive2 对象的地址，给 pd，否则返回 nullptr
	if (pd != nullptr)
	{
		pd->Derive02func();
	}
	else
	{
		p->func();
	}
}

int main()
{
//C++ 四种类型转换
	//const_cast：去掉常量属性的一个类型转换
	//static_cast：提供编译器认为安全的类型转换
	//reinterpret_cast：C 风格的强制类型转换
	//dynamic_cast：主要用在继承结果中，可以支持 RTTI 类型识别的上下转换
	
//const_cast
	//() 与 const_cast 在汇编层面一致，是语言类级别的转换
	//const_cast<这里面必须是指针或者引用类型>
	const int a = 10;
	int* p1 = (int*)&a;//C 风格类型转换
	//double *p1 = (double*)&a;解引用后访问 8 个字节内容，不安全，涉及非法访问其他内存
	int* p2 = const_cast<int*>(&a);//C++ 风格类型转换
	//double* p2 = const_cast<double*>(&a);需提供与 &a 去掉常量属性后的类型，此时 a 去掉常量属性后应为 int*

//static_cast
	//C++ 开发中最常用
	//编译时期的类型转换
	//能做提供编译器认为安全的任何类型转换
	//无法提供没有任何联系的类型之间的转换
	//可以通过 static_cast 用于派生类与基类之间的转换
	int a1 = 10;
	char b = static_cast<char>(a1);
	int* p = nullptr;
	//short* b = static_cast<short*>(p);//无法提供没有任何联系的类型之间的转换

//reinterpret_cast
	//C 风格的强制类型转换
	//static_cast 无法转换的类型，可以通过 reinterpret_cast 转换，无安全可言
	short* d = reinterpret_cast<short*>(p);

//dynamic_cast
	//运行时期的类型转换
	//可以支持 RTTI 类型识别的上下转换
	Derive1 d1;
	Derive2 d2;
	showFunc(&d1);
	showFunc(&d2);
	
	system("pause");
	return 0;
}
*/
