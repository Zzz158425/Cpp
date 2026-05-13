#include<iostream>
#include<map>
#include<functional>
#include<algorithm>
#include<string>
using namespace std;

/*
//模板的完全特例化与部分特例化
template<typename T>
bool compare(T a, T b)
{
    cout << "template compare" << endl;
    return a > b;
}
//对 const char* 类型提供的完全特例化版本
template<>
bool compare<const char*>(const char* a, const  char* b)
{
    cout << "compare<const char*>" << endl;
    return strcmp(a, b) > 0;
}
template<typename T>
class Vector
{
public:
    Vector()
    {
        cout << "call Vector template init" << endl;
    }
};
//对 char* 类型提供的完全特例化版本
template<>
class Vector<char*>
{
public:
    Vector()
    {
        cout << "call Vector<char*> template init" << endl;
    }
};
//对指针类型提供的部分特例化版本
template<typename Ty>
class Vector<Ty*>
{
public:
    Vector()
    {
        cout << "call Vector<Ty*> template init" << endl;
    }
};
//对函数指针（有返回值，有两个形参办理）类型提供的部分特例化版本
template<typename R, typename A1, typename A2>
class Vector<R(*) (A1, A2)>
{
public:
    Vector()
    {
        cout << "call Vector<R(*)(A1, A2)> init" << endl;
    }
};
// 针对函数类型（有一个返回值，两个形参变量）部分特例化
template<typename R, typename A1, typename A2>
class Vector<R(A1, A2)>
{
public:
    Vector()
    {
        cout << "call Vector<R(A1, A2) init" << endl;
    }
};

//区分函数指针类型和函数类型
int sum(int a, int b) { return a + b; }

//模板的实参推演
//T 包含了所有的大类型
template<typename T>
void func(T a)
{
    cout << typeid(T).name() << endl;
}
template<typename T>
void func1(T *a)
{
    cout << typeid(T).name() << endl;
}
//将 T 返回值与所有形参的类型都取出来
template<typename R, typename A1, typename A2>
void func2(R(*a)(A1, A2))
{
    cout << typeid(R).name() << endl;
    cout << typeid(A1).name() << endl;
    cout << typeid(A2).name() << endl;
}
class Test
{
public:
    int sum(int a, int b) { return a + b; }
};
//将成员方法返回值、类类型与所有形参的类型都取出来
template<typename R, typename T, typename A1, typename A2>
void func3(R (T::*a)(A1, A2))
{
    cout << typeid(R).name() << endl;
    cout << typeid(T).name() << endl;
    cout << typeid(A1).name() << endl;
    cout << typeid(A2).name() << endl;
}

int main()
{
//模板的完全特例化与部分特例化
    //优先匹配完全特例化版本 -> 部分特例化 -> 从源模板自己实例化
    compare(10, 20);
    compare("aaa", "bbb");//此时比较的是 aaa 和 bbb 的地址大小，不符合要求需特例化
    Vector<int> vec;
    Vector<char*> vec1;
    Vector<int*> vec2;
    Vector<int(*)(int, int)> vec3;
    Vector<int(int, int)> vec4;//函数类型与函数指针类型不是同一个类型

//区分函数指针类型和函数类型
    //函数指针类型：可以定义变量，可以存在类的成员变量里
    //方式一
    typedef int(*PFUNC1)(int, int);
    PFUNC1 pfunc1 = sum;
    cout << pfunc1(10, 20) << endl;
    //方式二
    using pfunc11 = int(*)(int, int);
    pfunc11 p11 = sum;
    cout << p11(1, 2) << endl;
    //函数类型：不能定义变量，不能存在类里
    //方式一
    typedef int PFUNC2(int, int);
    PFUNC2* pfunc2 = sum;
    cout << (*pfunc2)(10, 20) << endl;
    //方式二
    using pfunc22 = int(int, int);
    pfunc22* p22 = sum;
    cout << (*p22)(1, 2) << endl;

//模板的实参推演
    func(10);
    func("aaa");
    func(sum);//int (__cdecl*)(int,int) 函数指针类型，调用约定
    func1(sum);//int __cdecl(int,int) 函数类型，调用约定
    func2(sum);//int int int
    func(&Test::sum);//int (__cdecl Test::*)(int,int) __ptr64 指向成员方法的指针类型
    func3(&Test::sum);//int  class Test  int int

	system("pause");
	return 0;
}
*/