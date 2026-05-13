#include<iostream>
#include<typeinfo>
using namespace std;
//2026.2.25

/*
int main()
{
//C 开辟内存：malloc 和 free 称作 C 的库函数
	//malloc 只能用于开辟内存
	//malloc 开辟内存失败，是通关返回值和 nullptr 来做比较
	//开辟单个元素
 	int* p = (int*)malloc(sizeof(int));
	//判断内存开辟是否成功
	if (p == nullptr)
	{
		return -1;
	}
	*p = 20;
	free(p);
	//开辟数组
	int* p1 = (int*)malloc(sizeof(int) * 20);
	//判断内存开辟是否成功
	if (p1 == nullptr)
	{
		return -1;
	}
	free(p1);

//C++ 开辟内存：new 和 delete 称作运算符
	//new 不仅可以做内存开辟，还可以做内存初始化操作
	//new 开辟失败是通关抛出 bad_alloc 类型的异常来判断
	//开辟单个元素
	int* q = new int(20);
	delete q;
	//判断内存开辟是否成功，try-catch 用来捕获异常，防止程序会触发未处理异常，从而崩溃，try { ... } 块：标记需要监控异常的代码，catch ( ...  &T)：捕获异常
	try
	{
		int* q = new int(20);
	}
	catch (const bad_alloc &e)
	{

	}
	//开辟数组
	int* q1 = new int[20];//堆上只开辟数组，元素不初始化
	int* q2 = new int[20]();//开辟开辟数组，元素初始化为 0
	delete[]q1;

//new 的种类
	int* p2 = new int;//常用写法
	int* p3 = new (nothrow) int;//不抛出异常写法，开辟内存失败判读与 malloc 一致
	const int* p4 = new const int(40);//在堆上开辟一个常量
	int data = 0;
	int* p5 = new (&data) int(50);//在指定的地址上开辟内存
	cout << "data:" << data << endl;

	system("pause");
	return 0;
}
*/

