#include<iostream>
using namespace std;

/*
//函数的默认参数 2025.10.25
int func(int a, int b = 10, int c = 10) 
{
	return a + b + c;
}
int func1(int a = 10, int b = 10); //如果函数声明有默认值，函数实现的时候就不能有默认参数,声明和实现只能有一个有默认参数
int func1(int a, int b)
{
	return a + b;
}

//函数占位参数
void func2(int a, int = 20)//占位参数也可以有默认值
{
	cout << "this is func2 " << endl;
}

//函数重载
void func3()
{
	cout << "func3 的调用 " << endl;
}
void func3(int a)
{
	cout << "func3 (int a) 的调用 " << endl;
}
void func3(double a)
{
	cout << "func3 (double a) 的调用 " << endl;
}
void func3(int a, double b)
{
	cout << "func3 (int a, double b) 的调用 " << endl;
}
void func3(double a, int b)
{
	cout << "func3 (double a, int b) 的调用 " << endl;
}

//函数重载注意事项
void func4(int &a)
{
	cout << "func4(int &a) 的调用 " << endl;
}
void func4(const int& a)//与上面类型不同，可重载
{
	cout << "func4(const int& a) 的调用 " << endl;
}
void func5(int a, int b = 10)
{
	cout << "func5(int a, int b = 10) 的调用 " << endl;
}
void func5(int a)
{
	cout << "func5(int a) 的调用 " << endl;
}

int main()
{
//函数的默认参数 2025.10.25
	//在 C++ 中，函数的形参列表中的形参是可以有默认值的
	//语法：返回值类型  函数名 （参数 = 默认值）{}
	//如果某个位置参数有默认值，那么从这个位置往后，从左向右，必须都要有默认值
	cout << "ret = " << func(20, 20) << endl;//优先用传递值
	cout << "ret = " << func(100) << endl;

//函数占位参数
	//C++ 中函数的形参列表里可以有占位参数，用来做占位，调用函数时必须填补该位置
	//语法：返回值类型 函数名(数据类型) {}
	func2(10);

//函数重载
	//作用：函数名可以相同，提高复用性
	//函数重载满足条件：
		//同一个作用域下
		//函数名称相同
		//函数参数类型不同或者个数不同或者顺序不同
	//注意:函数的返回值不可以作为函数重载的条件
	func3();
	func3(10);
	func3(10.0);
	func3(10, 10.0);
	func3(10.0, 10);

//函数重载注意事项
	//引用作为重载条件
	//函数重载碰到函数默认参数
	int a = 10;
	func4(a);//a 为可读可写，会调用第一个
	func4(10);//10 为常量区
	//func5(10);当函数重载碰到默认参数，会出现二义性，避免
	func5(10, 20);

	system("pause");
	return 0;
}
*/
