#include<iostream>
#include<typeinfo>
#include<string>
#include<vector>
#include<set>
#include<queue>
using namespace std;

/*
//函数对象
template<typename T, typename Compare>
bool compare(T a, T b, Compare comp)
{
	return comp(a, b);
}
//通过函数指针
template<typename T>
bool mygreater(T a, T b)
{
	return a > b;
}
template<typename T>
bool myless(T a, T b)
{
	return a < b;
}
//通过函数对象
template<typename T>
class mygreater1
{
public:
	bool operator()(T a, T b)
	{
		return a > b;
	}
};
template<typename T>
class myless1
{
public:
	bool operator()(T a, T b)
	{
		return a < b;
	}
};

int main()
{
//函数对象
	//函数对象在 C 语言里面就是函数指针
	//在 C++ 中，把有 operator()小括号运算符重载函数的对象，称作函数对象，或者称作仿函数
	//通过函数指针实现
		//通过函数指针调用函数是无法内联的，效率低，有函数调用开销
	cout << compare(10, 20, mygreater<int>) << endl;//传入 mygreater<int> 函数地址
	cout << compare(10, 20, myless<int>) << endl;
	//通过函数对象实现
		//根据括号重载运算符的参数，如有两个参数为二元函数对象，一个参数为一元函数对象
		//通过函数对象调用 operator()，可以省略函数的调用开销，比通过函数指针调用函数（不能 inline 内联调用）效率高
		//因为函数对象是用类生成的，所以可以添加相关的成员变量，用来记录函数对象使用时更多的信息
	cout << compare(10, 20, mygreater1<int>()) << endl;//传入 mygreater<int>() 函数对象
	cout << compare(10, 20, myless1<int>())<< endl;

//案例1
	priority_queue<int> que1;
	for (int i = 0; i < 10; i++)
	{
		que1.push(rand() % 100);
	}
	while (!que1.empty())
	{
		cout << que1.top() << " ";
		que1.pop();
	}
	cout << endl;
	priority_queue<int,vector<int>,greater<int>> que2;
	for (int i = 0; i < 10; i++)
	{
		que2.push(rand() % 100);
	}
	while (!que2.empty())
	{
		cout << que2.top() << " ";
		que2.pop();
	}
	cout << endl;

//案例2
	set<int,greater<int>> set1;
	for (int i = 0; i < 10; i++)
	{
		set1.insert(rand() % 100);
	}
	for (int v : set1)
	{
		cout << v << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
*/