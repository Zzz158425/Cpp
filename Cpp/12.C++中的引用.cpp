#include<iostream>
using namespace std;

/*
//引用做函数参数
void mySwap01(int a, int b)//值传递
{
	int temp = a;
	a = b;
	b = temp;
}
void mySwap02(int* a, int* b)//地址传递
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void mySwap03(int &a, int &b)//引用传递
{
	int temp = a;
	a = b;
	b = temp;
}

//引用的本质
void func(int& ref)//发现是引用，转换为 int* const ref = &a3;
{
	ref = 100; // ref是引用，转换为 *ref = 100
}

//引用做函数返回值
int& test01()//返回局部变量引用，禁用
{
	int a = 10; //局部变量，存放在栈区中
	return a;
}
int& test02()//返回局部变量引用，禁用
{
	static int a = 10; //静态变量，存放在全局区中，由系统在程序结束后释放
	return a;
}

//引用的本质
void test03(int& ref)//发现是引用，转换为 int* const ref = &a3;
{
	ref = 100; // ref是引用，转换为 *ref = 100
}

//常量引用
void showValue(const int& v)//引用可以使形参修改实参，加上 const 防止被误修改
{
	//v += 10;
	cout << "val = " << v << endl;
}

int main()
{
//引用的基本语法
	//作用：给变量起别名
	//语法：数据类型 &别名 = 原名
	int a = 10;
	int& b = a;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	b = 20;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
//引用注意事项
	//引用必须初始化
	//引用在初始化后，不可以改变，b 引用 a 后，不可改 b 不能改变成引用 c
	int a1 = 10;
	int b1 = 20;
	//int &c; //错误，引用必须初始化
	int& c1 = a1; //一旦初始化后，就不可以更改
	c1 = b1; //这是赋值操作，不是更改引用
	cout << "a1 = " << a1 << endl;
	cout << "b1 = " << b1 << endl;
	cout << "c1 = " << c1 << endl;

//引用做函数参数
	//作用：函数传参时，可以利用引用的技术让形参修饰实参
	//优点：可以简化指针修改实参
	int a2 = 10;
	int b2 = 20;
	mySwap01(a2, b2);
	cout << "a2 = " << a2 << endl;
	cout << "b2 = " << b2 << endl;
	mySwap02(&a2, &b2);
	cout << "a2 = " << a2 << endl;
	cout << "b2 = " << b2 << endl;
	mySwap03(a2, b2);
	cout << "a2 = " << a2 << endl;
	cout << "b2 = " << b2 << endl;

//引用做函数返回值
	//作用：引用是可以作为函数的返回值存在的
	//注意：不要返回局部变量引用
	//用法：函数调用作为左值
	int& ref01 = test01();
	cout << "ref01 = " << ref01 << endl;
	cout << "ref01 = " << ref01 << endl;
	int& ref02 = test02();
	cout << "ref02 = " << ref02 << endl;
	cout << "ref02 = " << ref02 << endl;
	test02() = 1000;
	cout << "ref02 = " << ref02 << endl;
	cout << "ref02 = " << ref02 << endl;

//引用的本质
	//本质：引用的本质在c++内部实现是一个指针常量
	//C++ 推荐用引用技术，因为语法方便，引用本质是指针常量，但是所有的指针操作编译器都帮我们做了
	int a3 = 10;
	int &ref03 = a3;//自动转换为 int* const ref = &a3; 指针常量是指针指向不可改，也说明为什么引用不可更改
	ref03 = 20; //内部发现 ref 是引用，自动帮我们转换为: *ref = 20;
	cout << "a3:" << a3 << endl;
	cout << "ref03:" << ref03 << endl;
	test03(a3);

//常量引用
	//作用：常量引用主要用来修饰形参，防止误操作
	//在函数形参列表中，可以加 const 修饰形参，防止形参改变实参
	int a4 = 10;
	//int& ref = 10;不允许，引用必须引用一块合法的内存空间,10 在常量区
	const int &ref = 10;//编译器优化代码，int temp = 10; const int& ref = temp;
	//ref = 20;加入const 之后变为只读，不可以修改
	int a5 = 100;
	showValue(a5);

	system("pause");
	return 0;
}
*/