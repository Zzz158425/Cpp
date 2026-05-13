#include<iostream>
#include<typeinfo>
using namespace std;

/*
int main()
{
//const 修饰的量常出现的错误是：
	//常量不能再作为左值，不能直接修改常量的值
	//不能把常量的地址泄漏给一个普通的指针或普通的引用变量，不能间接修改常量的值
	const int a = 10;
	//a = 30;直接修改常量的值
	//int *p = &a;间接修改常量的值，不能把 const int* 赋值给 int*

//const 与一级指针的结合
	//C++ 语言规范：const 修饰的是离它最近的类型
		//const int* p;const 修饰 int 类型，修饰 *p 表达式，*p 不能够再被赋值，即指针指向的东西不能够被修改，指向可以修改
		//int const* p;与上面一致
		//int* const p;const 修饰 int* 类型，修饰 p 表达式，p 不能够再被修改，即指针指向的东西能够被修改，指向不可以修改
		//const(1) int* cosnt(2) p;const(1) 修饰 *p 表达式，const(2) 修饰 p 表达式，即指针指向的东西不能够被修改，指向不可以修改

//总结 const 和一级指针的类型转换公式
	//int*（左值）<- const int*（右值），错误
	//const int*（左值）<-int*（右值），正确
	 
//const 如果右边没有指针 * 的话，const 是不参与类型的
	int* q1 = nullptr;
	int* const q2 = nullptr;
	cout << typeid(q1).name() << endl;//q1 类型为 int*
	cout << typeid(q2).name() << endl;//q2 类型为 int*
	int b = 10;
	int* p1 = &b;
	const int* p2 = &b;//const int* <- int*
	int* const p3 = &b;//int* <- int*
	int* p4 = p3;//int* <- int*
	cout << typeid(p2).name() << endl;//p2 类型为 const int*，也可以写成 int const*
	cout << typeid(p3).name() << endl;//p3 类型为 int*
	cout << typeid(p4).name() << endl;//p4 类型为 int*

//const 与二级指针的结合
	//q(0x400) = 0x200 -> p(0x200) = 0x100 -> c(0x100) = 10 
	int c = 10;
	int* p = &c;
	int** q = &p;
	//const int** q;const 修饰 **q，**q 不能被赋值
	//int* const* q;const 修饰 *q，*q 不能被赋值
	//int** const q;const 修饰 q，q 不能被赋值

//总结 const 和二级指针的类型转换公式
	//int**（左值）<- const int**（右值），错误
	//const int**（左值）<-int**（右值），错误
	//int**（左值）<- int* const*（右值），错误
	//int*（左值）const* <- int**（右值），正确
	int d = 10;
	int* p5 = &d;
	//const int** q5 = &p5;const int** <- int** 错误，可能会把常量的地址泄漏给一个普通的指针
		//const int* *q = &p;
		//*q <-等价-> p
		//const int b =20;
		//*q = &b;把常量的地址泄漏给一个普通的指针
	//解决 1：*p6 不能再被赋值，也就不存在把常量的地址泄漏给一个普通的指针
	const int* p6 = &d;
	const int** q6 = &p5;
	//解决 2：*q7 不能再被赋值，也就不存在把常量的地址泄漏给一个普通的指针
	int* p7 = &d;
	const int* const* q7 = &p7;

//练习
 	//1.
		//int a = 10;
		//const int* p = &a;const int* <- int*
		//int* q = p;int* <- const int* 错误
	//2.
		//int a = 10;
		//int* const p = &a;int* <- int*
		//int* q = p;int* <- int* 正确
	//3.
		//int a = 10;
		//int* const p = &a;int* <- int*
		//int* const q = p;int* <- int* 正确
	//4.
		//int a = 10;
		//int* const p = &a;int* <- int*
		//const int* q = p;const int* <- int* 正确
	//5.
		//int a = 10;
		//int* p = &a;
		//const int** q = p;错误
	//6.
		//int a = 10;
		//int* p = &a;
		//int* const* q = &p;int* const* <- int** 正确
	//7.
		//int a = 10;
		//int* p = &a;
		//int** const q = &p;int** <- int** 正确
	//8.
		//int a = 10;
		//int* const p = &a;int* <- int*
		//int** q = &p;int** <- int* const* 错误
	//9.
		//int a = 10;
		//const int* p = &a;const int* <- int*
		//int* const* q = &p;int* const* <- const int** = int* <- const int* 错误

	system("pause");
	return 0;
}
*/