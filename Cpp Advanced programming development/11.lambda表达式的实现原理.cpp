#include<iostream>
#include<map>
#include<functional>
#include<algorithm>
#include<string>
#include<thread>
using namespace std;

/*
//lambda 表达式
template<typename T = void>
class TestLambda01
{
public:
	TestLambda01() {}
	void operator()() const
	{
		cout << "hello world!" << endl;
	}
};
template<typename T = int>
class TestLambda02
{
public:
	TestLambda02() {}
	int operator()(int a, int b) const
	{
		return a + b;
	}
};
template<typename T = int>
class TestLambda03
{
public:
	TestLambda03(int a, int b)
	: ma(a)
	, mb(b) {}
	void operator()() const//常方法修改参数需加 mutable
	{
		int temp = ma;
		ma = mb;
		mb = temp;
	}
private:
	mutable int ma;
	mutable int mb;
};
template<typename T = int>
class TestLambda04
{
public:
	TestLambda04(int &a, int &b)
		: ma(a)
		, mb(b) {
	}
	void operator()() const
	{
		int temp = ma;
		ma = mb;
		mb = temp;
	}
private:
	int &ma;
	int &mb;
};

int main()
{
//lambda 表达式
	//函数对象一般使用在泛型算法参数传递，比较性质/自定义操作，智能指针
	//函数对象缺点：灵活性差，用函数对象去实现比较性质/自定义等操作时可能只会使用一次函数对象，但却要创建一个对象
	//lambda 表达式是函数对象的高级实现
	//lambda 表达式语法：
		//[捕获外部变量](形参列表)->返回值{ 操作代码 };
		//[] 为空表示构造函数不接受任何外部传进来的变量，() 表示 () 运算符重载函数的参数列表，返回值表示 () 运算符重载函数的返回值，操作代码就是 () 运算符重载函数的内容
		//如果 lambda 表达式的返回值不需要，那么“->返回值”可以省略
		//[捕获外部变量]
			//[=]：以传值的方式捕获外部的所有变量
			//[&]：以传引用的方式捕获外部的所有变量
			//[this]:捕获外部的 this 指针
			//[=, &a]:以传值的方式捕获外部的所有变量，但是 a 变量以传引用的方式捕获
			//[a, b]:以值传递的方式捕获外部变量 a 和 b
			//[a, &b]：以值传递捕获，b 以传引用的方式捕获
	auto func1 = []()->void { cout << "hello world!" << endl; };
	//auto func1 = [](){ cout << "hello world!" << endl; };
	func1();
	TestLambda01<> t1;//与 func1 一样，t1 等同于 []()->void { cout << "hello world!" << endl; }
	t1();
	auto func2 = [](int a, int b)->int { return a + b; };
	cout << func2(20, 30) << endl;
	TestLambda02<> t2;//t2 等同于 [](int a, int b)->int { return a + b; }
	t2(20,30);
	int a = 10;
	int b = 20;
	//auto func3 = []()访问不了 a 与 b
	//	{
	//		int temp = a;
	//		a = b;
	//		b = temp;
	//	};
	cout << "----------func3 值传递----------" << endl;
	auto func3 = [a, b]() mutable//需加 mutable，operator() 为常方法，值传递无法改变 a 与 b 的值
		{
			int temp = a;
			a = b;
			b = temp;
		};
	func3();
	cout << "a:" << a << " b:" << b << endl;
	TestLambda03<> t3(a, b);//t3 等同于 [a, b]() mutable { int temp = a;a = b;b = temp; }，值传递无法改变 a 与 b 的值
	t3();
	cout << "a:" << a << " b:" << b << endl;
	cout << "----------func3 引用传递----------" << endl;
	auto func4 = [&]()//引用传递才能改变 a 与 b 的值
		{
			int temp = a;
			a = b;
			b = temp;
		};
	func4();
	cout << "a:" << a << " b:" << b << endl;
	TestLambda04<> t4(a, b);//t3 等同于 [&]() { int temp = a;a = b;b = temp; }，引用传递才能改变 a 与 b 的值
	t4();
	cout << "a:" << a << " b:" << b << endl;

//lambda 表达式应用
	//用 lambda 表达式改变 sort 排序顺序
	vector<int> vec;
	for (int i = 0; i < 20; ++i)
	{
		vec.push_back(rand() % 100 + 1);
	}
	sort(vec.begin(), vec.end(), 
		[](int a, int b)->bool 
		{
			return a > b; 
		});
	for (int val : vec)
	{
		cout << val << " ";
	}
	cout << endl;
	//65 按序插入序列，找第一个小于 65 的数字
	auto it = find_if(vec.begin(), vec.end(),
		[](int a)->bool
		{
			return a < 65;
		});
	if (it != vec.end())
	{
		vec.insert(it, 65);
	}
	for (int val : vec)
	{
		cout << val << " ";
	}
	cout << endl;
	//for_each 容器元素输出
	for_each(vec.begin(), vec.end(),
		[](int a)
		{
			if (a % 2 == 0) 
			{ 
				cout << a << " "; 
			}
		});
	cout << endl;

	system("pause");
	return 0;
}
*/