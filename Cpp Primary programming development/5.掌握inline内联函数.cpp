#include<iostream>
using namespace std;

/*
//inline 内联函数和普通函数的区别
int sum1(int x, int y)
{
	return x + y;
}
inline int sum2(int x, int y)
{
	return x + y;
}

int main()
{
//inline 内联函数和普通函数的区别
	//函数调用开销：函数的调用过程，包含参数压栈，函数栈帧的开辟与回退的过程
	//简单函数的函数开销远大于函数本身指令的执行时间，此时可采用 inline 内联函数
	//inline 函数：在编译过程中，无函数开销，在函数调用点直接把函数的代码展开处理了
	//inline 函数不再生成相应的函数符号，但不是所有的 inline 都会被编译器处理成内联函数，如递归
	//inline 函数只是建议编译器把这个函数处理成内联函数，具体是否内联需编译器决定
	//在 debug 版本上，inline 不起作用，只在 release 版本下才能出现
	//是否内联可在符号表中查看，若内联在符号表中无符号
	int a = 10;
	int b = 20;
	int ret = sum1(a, b);
	int ret = sum2(a, b);//在函数调用点直接把函数的代码展开处理，此时 int ret = a + b;

	system("pause");
	return 0;
}
*/