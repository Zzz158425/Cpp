#include<iostream>
#include<typeinfo>
#include<string>
#include<vector>
using namespace std;
//2026.3.3

/*
//虚函数、静态绑定和动态绑定
class Base
{
public:
	Base(int data = 10)
		:ma(data) { }
	//非虚函数
	void show() { cout << "Base::show()" << endl; }
	void show(int) { cout << "Base::show(int)" << endl; }
protected:
	int ma;
};
class Derive : public Base
{
public:
	Derive(int data = 20)
		:Base(data), mb(data) { }
	void show() { cout << "Derive::show()" << endl; }
protected:
	int mb;
};
class Base1
{
public:
	Base1(int data = 10)
		:ma(data) {
	}
	//虚函数
	virtual void show() { cout << "Base::show()" << endl; }
	virtual void show(int) { cout << "Base::show(int)" << endl; }
protected:
	int ma;
};
class Derive1 : public Base1
{
public:
	Derive1(int data = 20)
		:Base1(data), mb(data) {
	}
	void show() { cout << "Derive::show()" << endl; }//自动处理成虚函数，与基类的 void show() 为覆盖关系
protected:
	int mb;
};

int main()
{
//虚函数、静态绑定和动态绑定
	//如果类里面定义了虚函数，那么编译阶段，编译器给这个类型产生一个唯一的 vftable 虚函数表
	//虚函数表中主要存储的内容就是 RTTI 指针和虚函数的地址
	//当程序运行时，每一张虚函数表都会加载到内存的 .rodata 区，只读不写
	//虚函数表：以 Base1vftable（基类） 为例
		//&RTTI             RTTI：run-time type information 运行时的类型信息
		//                  指向类型字符串，指向 Base1
		//0                 vfptr 在对象内存的偏移量
		//
		//&Base1::show()    虚函数表起始地址，虚函数地址，先定义的就在虚函数表前面，后定义的就在虚函数表后面
		//
		//&Base1::show(int) 虚函数地址
		//
	//虚函数表：以 Derive1vftable（子类） 为例
		//&RTTI             RTTI：run-time type information 运行时的类型信息
		//                  指向类型字符串，指向 Derive1
		//0                 vfptr 在对象内存的偏移量
		//
		//&Base1::show(int) 虚函数表起始地址，虚函数地址，先定义的就在虚函数表前面，后定义的就在虚函数表后面，将基类 void show() 覆盖了
		//
		//&Derive1::show()  虚函数表起始地址
		//
	//一个类里面定义了虚函数，那么这个类定义的对象，其运行时，内存中开始部分，多存储一个 vftable 虚函数指针，指向相应类型的虚函数表
	//一个类型定义的 n 个对象定义，他们的 vftable  指向的都是同一张虚函数表
	//一个类里面虚函数的个数，不影响对象内存大小(vftable)，影响虚函数表的大小
	//如果派生类中的方法，和基类继承来的某个方法，返回值、函数名、参数列表都相同，而且基类的方法是 virtual 虚函数，那么派生类的这个方法，自动处理成虚函数
	//编译时，若基类的函数为普通函数，则会进行静态绑定，若基类的函数为需函数，则会进行动态（运行时期）绑定（函数调用）
	Derive d(50);
	Base* pb = &d;
	pb->show();//调用派生类继承来的基类的函数，静态（汇编时期）绑定（函数调用）
	pb->show(10);//静态绑定
	cout << sizeof(Base) << endl;//4
	cout << sizeof(Derive) << endl;//8
	cout << typeid(pb).name() << endl;//class Base*
	cout << typeid(*pb).name() << endl;//class Base
	Base b1;//占 8 字节，包含 vfptr 指针与 ma
	Base b2;//占 8 字节，vfptr 指针指向与 b1 同一个虚函数表
	Derive1 d1;//占 12 字节，包含 vfptr 指针、ma 与 mb
	Derive1 d2;//占 12 字节，vfptr 指针指向与 d1 同一个虚函数表
	Base1* pb1 = &d1;
	pb1->show();//动态绑定
	//mov eax, dword ptr[pb1] 将虚函数表的地址放入寄存器
	//mov ecx, dword ptr[eax] 取派生类方法的地址放入寄存器
	//call ecx 编译阶段不明确到底调用谁的地址，所以称为动态绑定
	pb1->show(10);//动态绑定
	//mov eax, dword ptr[pb1]
	//mov ecx, dword ptr[eax]
	//call ecx
	cout << sizeof(Base1) << endl;//8
	cout << sizeof(Derive1) << endl;//12
	cout << typeid(pb1).name() << endl;//静态类型语言，定义什么类型，打印就是什么类型 class Base1* 
	//如果 Base 没有虚函数，*pb 识别就是编译时期的类型，Base 类型
	//如果 Base 有虚函数，*pb 识别就是运行时期的类型，RTTI 类型
	cout << typeid(*pb1).name() << endl;//RTTI 类型 class Derive1

//查看虚函数表
	//可以打开 VS 命令行（工具-VS 命令提示）进行查看
		//切到当前文件所在文件夹：1.d:（回车） 2. cd D:\Visual Studio2022SharedProject\C ++\C ++ Primary programming development（回车）
		//dir（回车），cl 12.类和对象、this指针.cpp /dlreportSingleClassLayoutDRrive1（回车）
	
	system("pause");
	return 0;
}
*/