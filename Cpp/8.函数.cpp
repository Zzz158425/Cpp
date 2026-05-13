#include<iostream>
using namespace std;
//函数的分文件编写
#include "函数-函数分文件编写.h"

/*
//函数的定义
	//定义中的num1,num2并没有真是数据，称为形式参数，简称形参
int add(int num1, int num2)
{
	int sum = num1 + num2;
	return sum;
}

//值传递
void swap(int num1, int num2)
{
	cout << "交换前：" << endl;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;

	int temp = num1;
	num1 = num2;
	num2 = temp;

	cout << "交换后：" << endl;//形参发生改变
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;
}

//函数常见的形式
void fun()//无参无返
{
	cout << "test 01" << endl;
}
void fun1(int a)//有参无返
{
	cout << "test 02 a = " << a << endl;
}
int fun2()//无参有返
{
	cout << "test 03" << endl;
	return 100;
}
int fun3(int a)//有参有返
{
	cout << "test 04 a = " << a << endl;
	return a;
}

//函数的声明
int fun4(int a, int b);

int main()
{
//函数的定义
	//作用：将一段经常使用的代码封装起来，减少重复代码，一个较大的程序，一般分为若干个程序块，每个模块实现特定的功能。
	//函数的定义一般主要有5个步骤：
		//1、返回值类型：一个函数可以返回一个值。在函数定义中
		//2、函数名：给函数起个名称
		//3、参数表列：使用该函数时，传入的数据
		//4、函数体语句：花括号内的代码，函数内需要执行的语句
		//5、return 表达式： 和返回值类型挂钩，函数执行完后，返回相应的数据
	//语法：
		//返回值类型 函数名 （参数列表）
		//{函数体语句
		// return表达式
		//}
//函数的调用
	//功能：使用定义好的函数
	//语法： 函数名（参数）
	int add1 = 120;
	int add2 = 111;
	int add_sum = add(add1, add2);
	cout << "add_sum = " << add_sum << endl;
	
//值传递
	//所谓值传递，就是函数调用时实参将数值传入给形参
	//值传递时，如果形参发生，并不会影响实参
	int num1 = 117;
	int num2 = 321;
	cout << "交换前：" << endl;
	cout << num1 << endl;
	cout << num2 << endl;
	swap(num1, num2);
	cout << "交换后：" << endl;//形参发生，并不会影响实参，实参不会改变
	cout << num1 << endl;
	cout << num2 << endl;

//函数常见的形式 2025.10.18
	//常见的函数样式有4种
		//1. 无参无返
		//2. 有参无返
		//3. 无参有返
		//4. 有参有返
	fun();
	fun1(1);
	int num_fun2 = fun2();
	cout << num_fun2 << endl;
	int num_fun3 = fun3(1000);
	cout << num_fun3 << endl;

//函数的声明
	//作用：告诉编译器函数名称及如何调用函数。函数的实际主体可以单独定义，函数的声明可以多次，但是函数的定义只能有一次
	int num1_fun4 = 10;
	int num2_fun4 = 20;
	int num3_fun4 = fun4(num1_fun4, num2_fun4);
	cout << num3_fun4 << endl;

//函数的分文件编写
	//作用：让代码结构更加清晰
	//函数分文件编写一般有4个步骤
		//1. 创建后缀名为.h的头文件
		//2. 创建后缀名为.cpp的源文件
		//3. 在头文件中写函数的声明
		//4. 在源文件中写函数的定义
	int num1_fun5 = 50;
	int num2_fun5 = 40;
	fun5(num1_fun5, num2_fun5);

	system("pause");
	return 0;
}

//函数的声明
int fun4(int a, int b)
{
	int c = a > b ? a : b;
	return c;
}
*/