#include<iostream>
#include<typeinfo>
using namespace std;

/*
//引用
void swap(int &a, int &b)//引用
{
	int temp = a;
	a = b;
	b = temp;
}
void swap1(int* x, int* y)//指针
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
//引用
	//引用是一种更安全的指针，在汇编层面，引用与指针的处理一致
	//引用必须初始化，指针可以不初始化
	//引用只有一级引用，没有多级引用，指针可以有一级指针，也可以有多级指针
	//定义一个引用变量，和定义一个指针变量，其汇编指令是一模一样的
	//通关引用变量修改所引用内存的值，和通过指针解引用修改指针指向的内存的值，其底层指令也是一模一样的
	int a = 10;
	int* p = &a;
	int& b = a;//引用 a，将 a 的地址放入 b 中
	*p = 20;
	cout << a << " " << *p << " " << b << endl;
	b = 30;
	cout << a << " " << *p << " " << b << endl;
	//int &c = 20;20 立即数无法取地址，不能这样引用
	int c = 10;
	int d = 20;
	//引用与指针在汇编层面处理一致，优先用引用，更简便安全
	cout << "c:" << c << "d:" << d << endl;
	swap(c, d);
	cout << "c:" << c << "d:" << d << endl;
	swap1(&c, &d);
	cout << "c:" << c << "d:" << d << endl;

//定义一个引用变量，来引用 array 数组
	//可以先定义一个指针，把 * 用 & 替代即可
	int array[5] = {};
	int* p1 = array;
	int(&q1)[5] = array;//引用 array 数组
	cout << sizeof(array) << endl;
	cout << sizeof(p1) << endl;
	cout << sizeof(q1) << endl;

//左值引用
	//左值：有内存，有名字，值可以修改
	int e = 10;
	int& f = e;
	//int &g = 20;20 是右值：没内存，没名字，无法引用

//右值引用
	//右值：没内存，没名字
	//C++ 11 提供了右值引用：自动产生临时量，将临时量的地址放入 g 中，即直接引用临时量
	int&& g = 20;
	g = 30;//可以修改
	const int& h = 20;//const 左值引用可以绑定右值，其与右值引用一致，int temp = 20; &temp -> h
	//h = 20;const 修饰 h，无法修改 h
	int& i = g;//一个右值引用变量，本身是一个左值
	//int&& j = g;只能引用右值量，不能引用左值

	system("pause");
	return 0;
}
*/