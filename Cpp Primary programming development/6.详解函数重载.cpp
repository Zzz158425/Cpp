#include<iostream>
#include<typeinfo>
using namespace std;
//2026.2.24

/*
//函数重载
bool compare(int a, int b)
{
	cout << "compare_int_int" << endl;
	return a > b;
}
bool compare(double a, double b)
{
	cout << "compare_double_double" << endl;
	return a > b;
}
bool compare(const char* a, const char* b)
{
	cout << "compare_char*_char*" << endl;
	return strcmp(a, b) > 0;//字符串 a 是否按 ASCII 字典序大于字符串 b，返回值大于 0 就表示 a 大于 b
}
int data = 10;//全局作用域

//const 或者 volatile 时的函数重载
void func(int a){}
//void func(const int a){}无法重载，会产生重定义

//采用 __cplusplus 宏
#ifdef __cplusplus
extern "C" {
#endif
	int sum(int a, int b)
	{
		return a + b;
	}
#ifdef __cplusplus
}
#endif

int main()
{
//C++ 为什么支持函数重载，C 语言不支持函数重载？
	//答：C++ 代码产生函数符号的时候，包含函数名+参数列表类型组成，C 代码产生函数符号的时候，由函数名来决定
//函数重载
	//一组函数，其中函数名相同，但是参数列表的个数或者类型不同，那么这一组函数就称为重载
	//一组函数要称得上重载，一定要处在同一个作用域当中
	//仅返回值不同，不叫重载，因为 C++ 代码产生函数符号的时候，包含的是函数名+参数列表类型组成
	int data = 20;//局部作用域
	int a = data;//优先在最近的作用域找 data，此时 a = 20
	cout << a << endl;
	int b = ::data;//添加全局作用域，此时 a = 10
	cout << b << endl;
	//bool compare(int a, int b);局部函数声明，优先在最近的作用域找 compare，此时下方 compare 均会调用此函数
	compare(10, 20);
	compare(10.0, 20.0);
	compare("a","b");
	
//const 或者 volatile 时的函数重载
	//int a、const int a，均为 int 型，无法重载
	int c = 10;
	const int d = 10;
	cout << typeid(c).name() << endl;//int
	cout << typeid(d).name() << endl;//int

//多态
	//静态（编译时期）多态：函数重载、模版
	//动态（运行使其）多态

//C++ 调用 C
	//无法直接调用，需在 C 函数声明处加 extern "C"
	//C 文件中的方法：编译时按 C 方法生成符号
		//int sum(int a, int b) sum .txt
		//{
		//	return a + b;
		//}
	//C++ 文件中声明调用：编译时按 C++ 方法生成符号
		//int sum(int a, int b);sum_int_int "UND"
		//int ret = sum(10, 20);
	//此时想要调用需加 extern "C"
		//extern "C" {int sum(int a, int b)};sum "UND"

//C 调用 C++
	//无法直接调用，需在 C++ 源码处加 extern "C"
	//C 文件中声明调用：编译时按 C 方法生成符号
		//int sum(int a, int b);sum_int_int "UND"
		//int ret = sum(10, 20);
	//C++ 文件中的方法：编译时按 C++ 方法生成符号
		//int sum(int a, int b) _sum .txt
		//{
		//	return a + b;
		//}
	//此时想要调用需加 extern "C"
		//extern "C" {int sum(int a, int b){return a + b}};_sum "UND"

//采用 __cplusplus 宏
	//在 C++ 编译中按 C 规则生成，在 C 编译中无内置宏 __cplusplus ，直接运行函数，即无论 C 或 C++ 编译都支持 C 直接调用

	system("pause");
	return 0;
}
*/