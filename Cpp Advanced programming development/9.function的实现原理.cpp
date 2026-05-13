#include<iostream>
#include<map>
#include<functional>
#include<algorithm>
#include<string>
using namespace std;

/*
//示例一
void hello(string str) { cout << str << endl; }
template<typename Fty>
class myfunction
{

};
template<typename R, typename A1>
class myfunction<R(A1)>
{
public:
	using PFUNC = R(*)(A1);
	myfunction(PFUNC pfunc)
		: _pfunc(pfunc) { }
	R operator()(A1 arg)
	{
		return _pfunc(arg);//就是调用 hello(arg) 函数
	}
private:
	PFUNC _pfunc;
};

//示例二
int sum(int a, int b) { return a + b; }
template<typename R, typename A1, typename A2>
class myfunction<R(A1, A2)>
{
public:
	using PFUNC = R(*)(A1, A2);
	myfunction(PFUNC pfunc)
		: _pfunc(pfunc) {
	}
	R operator()(A1 arg1, A2 arg2)
	{
		return _pfunc(arg1, arg2);//就是调用 sum(arg1, arg2) 函数
	}
private:
	PFUNC _pfunc;
};

//采用可变参数个数的函数参数列表支持任意参数
template<typename Fty>
class myfunction1
{

};
template<typename R, typename... A>
class myfunction1<R(A...)>
{
public:
	using PFUNC = R(*)(A...);
	myfunction1(PFUNC pfunc) : _pfunc(pfunc) {}
	R operator() (A... arg)
	{
		return _pfunc(arg...);
	}
private:
	PFUNC _pfunc;
};

int main()
{
//示例一
	myfunction<void(string)> func1(hello);
	func1("hello world!");//func1.operator()

//示例二
	myfunction<int(int, int)> func2 = sum;
	cout << func2(10, 20) << endl;

//采用可变参数个数的函数参数列表支持任意参数
	myfunction1<void(string)> func3(hello);
	func3("hello world!");
	myfunction1<int(int, int)> func4 = sum;
	cout << func4(10, 20) << endl;

	system("pause");
	return 0;
}
*/