#include<iostream>
#include<typeinfo>
using namespace std;

/*
int main()
{
//在 C++ 中，const 修饰的变量叫常量，与普通变量的区别：编译方式不同，不能作为左值
	int a = 10;
	a = 20;
	const int b = 20;
	//b = 30;不能修改 b

//const 在 C 中
	//const 修饰的量，可以不用初始化，他不叫常量，叫做常变量：不能够作为左值，其余与变量一致
	//在 C 中，不用当做常量使用：const int a = 20;int array[a] = {};不能用作数组下标
	//可以使用内存，插入汇编指令进行修改：const int a = 20;int *p = (int*)&a;*p = 30;

//const 在 C++ 中
	//必须初始化，叫常量，可以用作数组下标

//C 和 C++ 中 const 的区别：const 的编译方式不同
	//C 中 const 就是当做一个变量来编译生成指令
	//C++ 中，所有出现 const 常量名字的地方，都被常量的初始化替代了：const int a = 20;int array[20(a)] = {};
	//在编译阶段就替换完成，所以必须初始化
	const int c = 20;
	int array[c] = {};
	int* p = (int*)&a;
	*p = 30;//此时已经把 a 的内存的值改为了 30，因为在编译阶段就替换完成，仍然输出 20
	cout << c << " " << *p << " " << *(&c) << endl;//编译阶段替换：cout << 20 << " " << *p << " " << 20 << endl;

//初始值不是立即数，会退化为常变量
	int d = 20;
	const int e = d;//常变量，与 C 中一致，不能够再用于数组下标

	system("pause");
	return 0;
}
*/