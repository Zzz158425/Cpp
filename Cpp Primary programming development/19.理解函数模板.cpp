#include<iostream>
#include<typeinfo>
using namespace std;
//2026.2.26

/*
//C++ 函数模板
template<typename T>//定义一个模板参数列表
bool compare(T a, T b)// compare 是一个函数模板
{
	cout << "template compare" << endl;
	return a > b;
}

//模板的特例化（专用化）
template<>
bool compare<const char*>(const char* a, const char* b)
{
	cout << "compare<const char*>" << endl;
	return strcmp(a, b);
}

//函数模版、模板的特例化、非模板函数的重载关系
//普通函数
bool compare(const char* a, const char* b)
{
	cout << "normal compare" << endl;
	return strcmp(a, b);
}

int main()
{
//C++ 函数模板
	//函数模板：template 和目标参数列表下方定义的函数，无法编译
	//模板的意义：对类型也可以进行参数化
	//在函数调用点，模板的实例化后，编译器用用户指定的类型，从原模板实例化一份函数代码出来，称为模板函数
	compare<int>(10, 20);//compare（模板名）+ <int>（参数列表）= 函数名
	//模板函数：bool compare<int>(int a, int b)
	//        {
	//        	cout << "template compare" << endl;
	//        	return a > b;
	//        }
	compare<double>(10.5, 20.5);
	//模板函数：bool compare<double>(int a, int b)
	//        {
	//        	cout << "template compare" << endl;
	//        	return a > b;
	//        }
	
//模板的实参推演
		//可以根据用户传入的实参的类型，来推导出模板类型参数的具体类型
		//无法
	compare(20, 30);//不再生成模板函数，直接调用之前已经生成的 bool compare<int>(int a, int b)
	//compare(20, 30.5);形参类型一致，但是实参类型不一致无法推导，可以定义不同的模板类型参数 <typename T, typename E>
	compare<int>(20, 30.5);//指定类型会把 double 类型强转为 int 类型

//模板的特例化（专用化）
		//对于某些类型来说，依赖编译器默认实例化的模板代码，代码处理逻辑错误，此时需将模板特例化，由用户提供
	compare("aaa", "bbb");//不进行特例化，比较两地址大小，不合理，提供 const char* 版本的特例化版本
	//模板函数：bool compare<const char*>(const char* a, const char* b)
	//        {
	//        	cout << "template compare" << endl;
	//        	return a > b;
	//        }

//函数模版、模板的特例化、非模板函数的重载关系
	//编译器优先调用非模板函数，因为简便，不用模板进行推演，如果没有，才去找 compare 模板
	//普通函数 compare 与 compare<const char*> 并不是重载的关系
	compare<const char*>("aaa", "bbb");//此时调用模板的特例化（专用化）
	
//模板特点
	//模板代码是不能在一个文件中定义，在另外一个文件中使用的
	//模板代码调用之前，一定要看到模板定义的地方，这样的话，模板才能够进行正常的实例化，产生能够被编译器编译的代码
	//模板代码一般都是放在头文件中，然后在源文件当中直接进行 #include 包含，#include 是在预编译过程中直接展开源文件在当前文件中
	//当模板定义与使用不在一个文件中时，可以在定义模板的源文件中进行指定类型的模板实例化来解决
		//template bool compare<int>(int, int)
		//template bool compare<double>(double, double)

	system("pause");
	return 0;
}
*/