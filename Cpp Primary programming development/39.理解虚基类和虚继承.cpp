#include<iostream>
#include<typeinfo>
#include<string>
#include<vector>
using namespace std;

/*
//理解虚基类和虚继承
class A//虚基类
{
public:
private:
	int ma;
};
class B : virtual public A
{
public:
private:
	int mb;
};
//查看虚基类表
class A1
{
	virtual void fun() {}
};
class B1 : virtual public A1
{

};
//虚基类与多态
class A3
{
public:
	virtual void func() { cout << "call A::func" << endl; }
	void operator delete(void* ptr)
	{
		cout << "operator delete p:" << ptr << endl;
		free(ptr);
	}
private:
	int ma;
};
class B3 : virtual public A3
{
public:
	void func() { cout << "call B::func" << endl; }
	void* operator new(size_t size)
	{
		void* p = malloc(size);
		cout << "operator new p:" << p << endl;
		return p;
	}
private:
	int mb;
};

int main()
{
//理解虚基类和虚继承
	//多重继承：一个派生类有多个基类
	//虚基类与抽象类不同
		//有纯虚函数的类称为抽象类
		//被虚继承的类称为虚基类
	A a;//4 字节
	B b;//12 字节，多了 vbptr

//查看虚基类表
	//vbptr：virtual base ptr 虚基类指针，vbtable：virtual base table 虚基类表
	//可以打开 VS 命令行（工具-VS 命令提示）进行查看
	//切到当前文件所在文件夹：1.d:（回车） 2. cd D:\Visual Studio2022SharedProject\C ++\C ++ Primary programming development（回车）
	//dir（回车），cl 12.类和对象、this指针.cpp /dlreportSingleClassLayoutA（回车）
	//class B size(12)
	//    -----
	//0   vbptr -> vbtable
	//4   mb
	//    ----- virtual base A
	//8   ma
	//    -----
	//B::vbtable
	//0   0 向上偏移量，相比派生类起始地址的偏移量 
	//1   8 向下偏移量，从 vbptr 偏移 8 字节就能找到 ma，即虚基类指针域虚基类数据的偏移
	cout << sizeof(B1) << endl;//包含 vfptr 和 vbptr	

//虚基类与多态
	//虚基类能够发生多态，但是释放内存会出错
	//基类指针指向派生类对象，永远指向的是派生类基类部分数据的地址
	//派生类内存布局，以 A3 B3 为例：
		//    -----
		//0   vbptr
		//4   mb
		//    -----    virutal base A3
		//8   vfptr    从基类继承而来，算基类部分
		//12  ma
		//    -----
		//B3::vbptr
		//0   0
		//1   8        从 vbptr 偏移 8 字节就能找到虚基类数据
		//B3::vfptr
		//    -8       vfptr 离派生类起始地址的偏移量
		//0   B::func
	A3* p = new B3();//p 指向 vfptr 所以能够发生多态
	p->func();
	//delete p;//释放内存出错，应该从 vbptr 处开始释放内存,但是 p 一开始指向 vfptr，从 vfptr 开始释放内存
	B3 b3;
	A3* p1 = &b3;
	cout << "main p1:" << p1 << endl;
	p1->func();

	system("pause");
	return 0;
}
*/