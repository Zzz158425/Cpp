#include<iostream>
using namespace std;

/*
//内存四区-全局区：
int g_a = 10;//全局变量
int g_b = 10;
const int c_g_a = 10;//全局常量
const int c_g_b = 10;

//内存四区-栈区：
int* func()//形参数据也会存放在栈区
{
	int a = 10;//局部变量，存放在栈区，栈区的数据在函数执行完后自动释放
	return &a;//返回局部地址变量，禁止
}

//内存四区-堆区：
int* func1()
{
	int* a = new int(10);//指针本质也是局部变量，指针保存的数据放在堆区
	return a;
}

//new 运算
int* func2()
{
	int* a = new int(11);//new 返回该数据对应的类型的指针
	return a;
}
void func2_1()
{
	int* a = func2();//new 返回该数据对应的类型的指针
	cout << *a << endl;
	cout << *a << endl;
	delete a;//释放
}
void func2_2()
{
	int* arr = new int[10];//10 代表数组元素有 10 个元素
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 100;//给 10 个数赋值 100 ~ 109
	}
	for (int j = 0; j < 10; j++)
	{
		cout << arr[j] << endl;
	}
	delete[] arr;//释放数组需加 []
}

int main()
{
//内存四区-代码区 2025.10.24
	//C++程序在执行时，将内存大方向划分为，4个区域
	//不同区域存放的数据，赋予不同的生命周期, 给我们更大的灵活编程
		//代码区：存放函数体的二进制代码，由操作系统进行管理的
		//全局区：存放全局变量和静态变量以及常量
		//栈区：由编译器自动分配释放, 存放函数的参数值, 局部变量等
		//堆区：由程序员分配和释放, 若程序员不释放, 程序结束时由操作系统回收
	//程序运行前，在程序编译后，生成了exe可执行程序，未执行该程序前分为两个区域：代码区和全局区
		//代码区：
			//存放 CPU 执行的机器指令
			//存放 CPU 执行的机器指令
			//代码区是共享的，共享的目的是对于频繁被执行的程序，只需要在内存中有一份代码即可
			//代码区是只读的，使其只读的原因是防止程序意外地修改了它的指令
//内存四区-全局区：
	//全局变量和静态变量存放在此
	//全局区中存放全局变量、静态变量、常量
	//常量区中存放 const 修饰的全局常量  和 字符串常量
	//该区域的数据在程序结束后由操作系统释放
	int a = 10;//局部变量，不在全局区中
	int b = 200;
	cout << "局部变量a地址为： " << (long long)&a << endl;
	cout << "局部变量b地址为： " << (long long)&b << endl;
	cout << "全局变量g_a地址为： " << (long long)&g_a << endl;
	cout << "全局变量g_b地址为： " << (long long)&g_b << endl;
	static int s_a = 10;//静态变量，与全局变量放一起
	static int s_b = 10;
	cout << "静态变量s_a地址为： " << (int)&s_a << endl;
	cout << "静态变量s_b地址为： " << (int)&s_b << endl;
	cout << "字符串常量地址为： " << (int)&"hello world" << endl;//字符串常量，与全局变量放一起
	cout << "字符串常量地址为： " << (int)&"hello world1" << endl;
	cout << "全局常量c_g_a地址为： " << (int)&c_g_a << endl;//全局常量，与全局变量放一起
	cout << "全局常量c_g_b地址为： " << (int)&c_g_b << endl;
	const int c_l_a = 10;
	const int c_l_b = 10;
	cout << "局部常量c_l_a地址为： " << (int)&c_l_a << endl;//局部常量，与局部变量放一起，不在全局区中
	cout << "局部常量c_l_b地址为： " << (int)&c_l_b << endl;

//内存四区-栈区：
	//由编译器自动分配释放, 存放函数的参数值, 局部变量等
	//注意事项：不要返回局部变量的地址，栈区开辟的数据由编译器自动释放
	int* p = func();
	cout << *p << endl;//第一次可以打印正确数字，因为编译器做了保留
	cout << *p << endl;//第二次不再保留

//内存四区-堆区：
	//由程序员分配释放, 若程序员不释放, 程序结束时由操作系统回收
	//在C++中主要利用 new 在堆区开辟内存
	int* p1 = func1();
	cout << *p1 << endl;
	cout << *p1 << endl;

//new运算
	//C++ 中利用 new 操作符在堆区开辟数据
	//堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符 delete
	//语法：new 数据类型
	//利用 new 创建的数据，会返回该数据对应的类型的指针
	func2_1();
	func2_2();

	system("pause");
	return 0;
}
*/