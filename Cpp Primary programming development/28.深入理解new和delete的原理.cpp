#include<iostream>
#include<typeinfo>
#include<string>
#include<vector>
using namespace std;
//2026.3.2

/*
//深入理解 new 和 delete
//operator new 重载
void* operator new (size_t size)//size_t 适配系统的无符号整数类型，表示当前系统支持的最大内存尺寸
{
	void* p = malloc(size);
	if (p == nullptr)
	{
		throw bad_alloc();
	}
	cout << "operator new addr:" << p << endl;
	return p;
}
//operator delete 重载
void operator delete(void* ptr)
{
	cout << "operator delete addr:" << ptr << endl;
	free(ptr);
}
//operator new[] 重载
void* operator new[] (size_t size)
{
	void* p = malloc(size);
	if (p == nullptr)
	{
		throw bad_alloc();
	}
	cout << "operator new[] addr:" << p << endl;
	return p;
}
//operator delete[] 重载
void operator delete[](void* ptr)
{
	cout << "operator delete[] addr:" << ptr << endl;
	free(ptr);
}

//new 和 delete、delete[] 混用
class Test
{
public:
	Test(int data = 10)
		:ptr(new int(data))
	{
		cout << "Test()" << endl;
	}
	~Test()
	{
		delete ptr;
		cout << "~Test()" << endl;
	}
private:
	int* ptr;
};
class Test1
{
public:
	Test1(int data = 10) { cout << "Test()" << endl; }
	~Test1() { cout << "~Test()" << endl; }
private:
	int ma;
};

int main()
{
//深入理解 new 和 delete
	//new：先调用 operator new 开辟内存空间、然后调用对象的构造函数（初始化）
	//delete：调用 p 指向对象的析构函数、再调用 operator delete 释放内存空间
	//本质为 new 与 delete 重载函数调用
	//malloc 与 new 的区别：
		//malloc 是按字节开辟内存的，new 开辟内存时需要指定类型
		//malloc 开辟内存返回的都是 void*，new 会自动返回转成指定类型，不需要做类型强转
		//malloc 只负责开辟空间，new 不仅仅有 malloc 的功能，可以进行数据的初始化
		//malloc 开辟内存失败返回 nullptr 指针，new 抛出的是 bad_alloc 类型的异常
	//free 与 delete 的区别：
		//delete 会先调用析构函数，再释放内存（free），对于 delete (int*)p 与 free 操作并没有区别，因为整型没有析构函数
	//try...catch 判断内存是否分配失败
	//用户需要实现自己的内存管理时，需要自己定义 new 和 delete 的重载函数，一般情况用库提供的 new 和 delete 即可
	try
	{
		int* p = new int;
		delete p;
		int* q = new int[10];
		delete[]q;
	}
	catch(const bad_alloc &err)
	{
		cerr << err.what() << endl;
	}

//new、new[] 和 delete、delete[] 混用
	//对于普通的编译器内置类型，无构造函数和析构函数，new 和 delete、delete[] 只有 malloc 与 free 的功能，可以混用，不建议
	//自定义的类型，有析构函数，为了调用正确的析构函数，那么开辟对象数组的时候会多开辟 4 字节记录对象的个数
	//[] 表示多个对象需要构造/析构，[] 中的数字也会开辟一个所属类型内存进行存储
	try
	{
		int* p1 = new int;
		delete[]p1;
		int* q1 = new int[10];
		delete q1;
	}
	catch (const bad_alloc& err)
	{
		cerr << err.what() << endl;
	}
	Test* p1 = new Test();//开辟两次内存：为 Test 对象本身分配内存，为 int 类型分配内存
	delete p1;//释放两次内存：释放构造函数里分配的 int 内存，释放 Test 对象的内存
	//Test* p1 = new Test();不能混用
	//delete[]p1;
	Test* p2 = new Test[5];
	delete[]p2;
	//Test* p1 = new Test[5];不能混用
	//delete p1;
	Test1* p3 = new Test1[5];//会开辟 4 * 5 + 4 = 25 个字节：包含 5 个 Test 对象的数组和 1 个存储对象的个数，只会返回 0x104 地址给用户
	cout << "p3:" << p3 << endl;
	delete[]p3;//释放会从 0x100 地址开始
	//0x100    存储对象个数
	//0x104    存储的对象
	//0x108    存储的对象
	//...      ...
	//Test1* p2 = new Test1[5];
	//deletep2;混用会导致只会析构 Test1[0]，并直接 free(p2)
	//Test1* p2 = new Test1;
	//deletep[]2;Test1 对象存储在 0x104，混用会导致去 0x100 取个数，free(0x104 -4)，显然错误,

	system("pause");
	return 0;
}
*/