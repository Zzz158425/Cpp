#include<iostream>
#include<typeinfo>
#include<string>
#include<vector>
using namespace std;

/*
//大厂 C++ 开发工程师面试问题
//5.为什么函数调用参数要从右往左压栈？
//可变参函数
void func(int a, ...)
{

}
//6.分析代码，主函数里面通过 string s = fun(s1, s2); 调用，依照代码执行顺序分析调用构造/构造函数顺序
//C++ 会自动优化，如果用临时对象拷贝构造新对象，那么临时对象就不产生了，直接构造新对象就行了
//strng str1 = string("hello world") 等同于 string str1("hello world");此时不会再产生临时对象再拷贝构造给 str1，会直接给 str1 进行拷贝构造
string fun(string s1, string s2)
{
	string tmp = s1 + s2; 
	return tmp;//此处 tmp 不再会产生额外的一个临时对象再拷贝构造给 s，而是 tmp 直接拷贝构造给 s
}
//7.在上一题中，如果 fun 函数内写成 return s1 + s2 有什么区别？
string fun(string s1, string s2)
{
	return s1 + s2;//直接将 s1 与 s2 的结果拷贝构造给 s
}
//8.一个结构体里面定义了一个 char 和 double，它的空间内存布局是怎么样的？
struct Data
{
	char a;//1
	double b;//8
};
struct Data1
{
	char a;//1
};
struct Data2 { };
struct Data3 : public Data2 { };
struct Data4 { virtual void func(); };
struct Data5 : public virtual Data4 {};
//9.对象内存大小和类大小区别？
class Test
{

};

int main()
{
//大厂 C++ 开发工程师面试问题
	//1.程序的内存布局
		//答：掌握进程虚拟地址空间区域划分-进程的虚拟地址空间
	//2.堆内存和栈内存的区别？
		//答：在代码上通过 new、malloc/free、delete 开辟/释放堆内存，调用函数会使用栈内存，调用 } 系统会自动回收
	//3.数据结构中堆和栈的区别？
		//答：堆：二叉树，常用大根堆与小根堆，栈：线性表，满足先进后出，后进先出
	//4.函数调用参数是怎么传递的？
		//答：实参传给对应的形参，参数从右向左压栈，压下一行指令地址，将调用方函数（main 函数）的栈帧栈底地址 ebp 入栈，将 ebp 指向调用函数栈底
	//5.为什么函数调用参数要从右往左压栈？
		//答：C/C++ 要支持可变参函数，所以从右向左压栈，如函数 printf(const char*, ...) 就是可变参函数，指令均在编译阶段生成，不知道要用户要传入多少个参数，无法确定访问函数应该偏移多少才能访问参数
	func(10, 20, 30);
	func(10, 20, 30, 40);
	//6.分析代码，主函数里面通过 string s = fun(s1, s2); 调用，依照代码执行顺序分析调用构造/构造函数顺序
		//答：1.实参 a 到形参 s2 为拷贝构造；2.实参 b 到形参 s1 为拷贝构造；3.s1 + s2 形成新的 string 对象，通过拷贝构造到 tmp；4.此时不会产生临时对象再拷贝给 s，而是 tmp 直接拷贝构造给 s；析构顺序与构造顺序相反，依次是：析构 tmp、s1、s2，main 函数结束析构 s
		//注意：所以调用函数推荐引用传递，可以不用构造与析构 s1、s2，能够提高效率
		//补充：string s;string s = fun(a, b);此时一定会产生临时对象给 s 进行赋值
	string a, b;
	string s = fun(a, b);
	//7.在上一题中，如果 fun 函数内写成 return s1 + s2 有什么区别？
		//答：直接将 s1 与 s2 的结果拷贝构造给 s，省略了 tmp 的拷贝构造与析构函数的调用
		//注意：所以返回对象时，直接返回结果，不用先定义再返回
	//8.一个结构体里面定义了一个 char 和 double，它的空间内存布局是怎么样的？
		//答：Data 存在内存对齐，Data 所占内存大小为 16 字节，Data1 与 Data2 均占内存大小为 1 字节 
		//注意：window vs20 以下 .c 文件不允许定义空 struct 结构体，gcc linux/unix 系统下 .c 文件 sizeof(Data2) = 0，0 字节为系统优化，避免因内存对齐而浪费内存
		//注意：window vs 系列编译器与 gcc/g++ 下 .cpp 文件sizeof(Data2) = 1
		//补充：在 C 中 struct 为变量（只需要内存），C++ 中称 struct 为对象（需要内存、构造），内存最小单位为 1，所以空 struct 所占内存为 1，继承空 struct 所占内存也为 1
		//补充：对有虚函数的 struct 进行虚继承所占内存为 8（x86），因为包含了 vbptr 与 vfptr
	//9.对象内存大小和类大小区别？
		//答：sizeof(Test) = sizeof(t)，sizeof(Test) 表示 Test 将来要是定义一个变量（对象），所占用的内存大小均为 1
	Test t;

	system("pause");
	return 0;
}
*/