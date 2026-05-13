#include<iostream>
#include<typeinfo>
using namespace std;

/*
int main()
{
//写一句代码，在内存的 0x0018ff44 处写一个 4 字节的 10
	//int&& p = 0x0018ff44 把这个地址数值本身当作 int 值绑定引用，与操作这个地址对应的内存完全不一样
	int*&& p = (int*)0x0018ff44;//(int*)0x0018ff44 的作用是给数值 0x0018ff44 赋予内存地址的语义
	int* const& q = (int*)0x0018ff44;

//练习
	//可以把引用还原成指针来判断
	//1.
		//int a = 10;
		//int* p = &a;int* <- int*
		//int*& q = p;1.int* <- int* 2.&q 必须要求右边为地址，均满足正确
	//2.
		//int a = 10;
		//int* const p = &a;int* <- int*
		//int*& q = p;1.int* <- int* 2.&q 必须要求右边为地址，p为常量，不满足 2，错误
	//3.
		//int a = 10;
		//const int* p = &a;const int* <- int*
		//int*& q = p;-> int** q = &p;int** <- const int** 错误
	//4.
		//int a = 10;
		//int* p = &a;int* <- int*
		//const int*& q = p;-> const int** q = &p;const int** <- int** 错误

	system("pause");
	return 0;
}
*/
