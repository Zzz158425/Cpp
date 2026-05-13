#include<iostream>
using namespace std;
#include<string>
#include"21.1.模板-类模板分文件编写.cpp"//直接包含.cpp源文件
#include"模板-类模板分文件编写.hpp"//将声明和实现写到同一个文件中，并更改后缀名为.hpp
#include"模板-数组类封装.hpp"

/*
//函数模板基本语法
void swapInt(int& a, int& b)//交换两个整型函数
{
	int temp = a;
	a = b;
	b = temp;
}
void swapDouble(double& a, double& b)//交换两个浮点型函数
{
	double temp = a;
	a = b;            
	b = temp;
}
template<typename T>//声明一个模版，告诉编译器后面代码中紧跟的 T 不要报错，T 是一个通用数据类型
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
void test01()
{
	int a = 10;
	int b = 20;
	swapInt(a, b);
	cout << "a = " <<   a << endl;
	cout << "b = " << b << endl;
	double c = 1.1;
	double d = 2.2;
	swapDouble(c, d);
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
	int e = 10;
	int f = 20;
	//mySwap(e, f);自动推导类型
	mySwap<int>(e, f);//显示指定类型
	cout << "e = " << e << endl;
	cout << "f = " << f << endl;
}

//函数模板注意事项
template<class R>
void func()
{
	cout << "func 调用" << endl;
}
void test02()
{
	//func();模板必须要确定出 T 的数据类型，才可以使用
	func<int>();
}

//数组排序
template<class T>//冒泡排序
void mySort_bubble(T arr[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1] )
			{
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (int k = 0; k < len; k++)
	{
		cout << arr[k] << " ";;
	}
	cout << endl;
}
void test03()
{
	char charArr[] = "bdcfeagh";//测试char数组
	mySort_bubble(charArr, sizeof(charArr) / sizeof(char) - 1);
	int intArr[] = { 7, 5, 8, 1, 3, 9, 2, 4, 6 };//测试int数组
	mySort_bubble(intArr, sizeof(intArr) / sizeof(int));
}
template<typename T>//选择排序
void mySwap2(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
template<class T>
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i; //最大数的下标
		for (int j = i + 1; j < len; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (max != i) //如果最大数的下标不是i，交换两者
		{
			mySwap2(arr[max], arr[i]);
		}
	}
}
template<typename T>
void printArray(T arr[], int len) 
{

	for (int i = 0; i < len; i++) 
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void test04()
{
	
	char charArr[] = "bdcfeagh";//测试char数组
	int num1 = sizeof(charArr) / sizeof(char);
	mySort(charArr, num1);
	printArray(charArr, num1);
	int intArr[] = { 7, 5, 8, 1, 3, 9, 2, 4, 6 };//测试int数组
	int num2 = sizeof(intArr) / sizeof(int);
	mySort(intArr, num2);
	printArray(intArr, num2);
}

//普通函数与函数模板区别：
int myAdd01(int a, int b)//普通函数
{
	return a + b;
}
template<class T>//函数模板
T myAdd02(T a, T b)
{
	return a + b;
}
void test05()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	cout << myAdd01(a, c) << endl; //正确，将char类型的'c'隐式转换为int类型  'c' 对应 ASCII码 99
	//myAdd02(a, c); // 报错，使用自动类型推导时，不会发生隐式类型转换
	myAdd02<int>(a, c); //正确，如果用显示指定类型，可以发生隐式类型转换
}

//普通函数与函数模板的调用规则
void myPrint(int a, int b)
{
	cout << "调用的普通函数" << endl;
}

template<typename T>
void myPrint(T a, T b)
{
	cout << "调用的模板" << endl;
}
template<typename T>
void myPrint(T a, T b, T c)
{
	cout << "调用重载的模板" << endl;
}
void test06()
{
	int a = 10;
	int b = 20;
	myPrint(a, b);//如果函数模板和普通函数都可以实现，优先调用普通函数，如果告诉编译器普通函数是有的，但只是声明没有实现，或者不在当前文件内实现，就会报错找不到
	myPrint<>(a, b);//可以通过空模板参数列表来强制调用函数模板
	myPrint<>(a, b, 100);//函数模板也可以发生重载
	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2); //如果函数模板可以产生更好的匹配,优先调用函数模板

}

//模板的局限性
template<class T>//普通模版
bool myCompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void test07()
{
	int a = 10;
	int b = 20;
	bool ret = myCompare(a, b);
	if (ret)
	{
		cout << "a == b " << endl;
	}
	else
	{
		cout << "a != b " << endl;
	}
}
class Person
{
public:
	Person(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}
	string m_Name;
	int m_Age;
};
template<> bool myCompare(Person& p1, Person& p2)//显示具体化的原型和定意思以 template<> 开头，并通过名称来指出类型
{
	if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void test08()
{
	Person p1("Tom", 10);
	Person p2("Tom", 10);
	bool ret = myCompare(p1, p2);
	if (ret)
	{
		cout << "p1 == p2 " << endl;
	}
	else
	{
		cout << "p1 != p2 " << endl;
	}
}

//类模板基本语法 2025.11.8
template<class NameType, class AgeType>
class Person1
{
public:
	Person1(NameType name, AgeType age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	void showPerson()
	{
		cout << "name: " << this->m_Name << " age: " << this->m_Age << endl;
	}
	NameType m_Name;
	AgeType m_Age;
};
void test09()
{
	Person1<string, int> p1("孙悟空", 999);
	p1.showPerson();
}

//类模版与函数模版区别
template<class NameType, class AgeType>
class Person2
{
public:
	Person2(NameType name, AgeType age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	void showPerson()
	{
		cout << "name: " << this->m_Name << " age: " << this->m_Age << endl;
	}
	NameType m_Name;
	AgeType m_Age;
};
void test10()
{
	Person2 p2("孙悟空", 999);//C++ 17 以上支持自动类型推导
	p2.showPerson();
}
template<class NameType, class AgeType = int>//类模板在模板参数列表中可以有默认参数
class Person3
{
public:
	Person3(NameType name, AgeType age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	void showPerson()
	{
		cout << "name: " << this->m_Name << " age: " << this->m_Age << endl;
	}
	NameType m_Name;
	AgeType m_Age;
};
void test11()
{
	Person3<string>p3("猪八戒", 998);
	p3.showPerson();
}

//类模板中成员函数创建时机
class Person4
{
public:
	void showPerson4()
	{
		cout << "Person4 show" << endl;
	}
};
class Person5
{
public:
	void showPerson5()
	{
		cout << "Person5 show" << endl;
	}
};
template<class T>
class MyClass
{
public:
	T obj;
	void fun1() { obj.showPerson4(); }
	void fun2() { obj.showPerson5(); }
};
void test12()
{
	MyClass<Person4> m;
	m.fun1();
	//m.fun2();类模板中的成员函数，并不是一开始就创建的，而是在模板调用时再生成
}

//类模板对象做函数参数
template<class T1, class T2>
class Person6
{
public:
	Person6(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	void showPerson()
	{
		cout << "name: " << this->m_Name << " age: " << this->m_Age << endl;
	}
	T1 m_Name;
	T2 m_Age;
};
void printPeron1(Person6<string, int> &p6)//指定传入的类型
{
	p6.showPerson();
}
template<class T1, class T2>//参数模板化
void printPeron2(Person6<T1, T2>& p66)
{
	p66.showPerson();
	cout << "T1 的类型为： " << typeid(T1).name() << endl;//查看 T1 的类型
	cout << "T2 的类型为： " << typeid(T2).name() << endl;//查看 T2 的类型
}
template<class T>
void printPeron3(T &p666)//整个类模板化
{
	p666.showPerson();
	cout << "T 的类型为： " << typeid(T).name() << endl;//查看 T 的类型
}
void test13()
{
	Person6<string, int>p6("孙悟空", 100);//指定传入的类型
	printPeron1(p6);
	Person6<string, int>p66("猪八戒", 99);//参数模板化
	printPeron2(p66);
	Person6<string, int>p666("唐僧", 98);//整个类模板化
	printPeron3(p666);
}

//类模板与继承
template<class T>
class Base
{
	T m;
};
//class Son : public Base错误，必须要知道父类中 T 的类型，才能继承给子类
class Son : public Base<int>{};
template<class T1, class T2>//如果想灵活指定出父类中 T 的类型，子类也需变为类模板
class Son2 : public Base<T2> 
{
public:
	Son2()
	{
		cout << "T1 的类型为： " << typeid(T1).name() << endl;
		cout << "T2 的类型为： " << typeid(T2).name() << endl;
	}
	T1 obj;
};
void test14()
{
	Son s;
	Son2<int, char>s2;
}

//类模板成员函数类外实现
template<class T1, class T2>
class Person7
{
public:
	Person7(T1 name, T2 age);
		//{
		//	this->m_Name = name;
		//	this->m_Age = age;
		//}
	void showPerson();
	//{
	//	cout << "name: " << this->m_Name << " age: " << this->m_Age << endl;
	//}
	T1 m_Name;
	T2 m_Age;
};
template<class T1, class T2>//构造函数类外实现
Person7<T1, T2>::Person7(T1 name, T2 age)
{
	this->m_Name = name;
	this->m_Age = age;
}
template<class T1, class T2>//成员函数类外实现
void Person7<T1, T2>::showPerson()
{
	cout << "name: " << this->m_Name << " age: " << this->m_Age << endl;
}
void test15()
{
	Person7 p7("Tom", 20);
	p7.showPerson();
}

//类模板分文件编写
void test16()
{
	Person8<string, int> p8("Jerry", 18);
	p8.showPerson();
}
void test17()
{
	Person9<string, int> p9("Bob", 19);
	p9.showPerson();
}

//类模板与友元 2025.11.10
template<class T1, class T2> class Person10;//全局函数配合友元  类外实现 - 先做函数模板声明，下方在做函数模板定义，在做友元，如果声明了函数模板，可以将实现写到后面，否则需要将实现体写到类的前面让编译器提前看到
template<class T1, class T2>
void printPerson1(Person10<T1, T2> p)
{
	cout << "类外实现---姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
}
template<class T1, class T2>
class Person10
{
	friend void printPerson(Person10<T1, T2> p)//全局函数 类内实现
	{
		cout << "类内实现---姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
	}
	friend void printPerson1<>(Person10<T1, T2> p);//全局函数 类外实现，需在 printPerson1 后加 <>，,函数模版载调用是才会创建，由于在声明的时候是以普通函数声明，编译器找不到定义会认为定义在别的文件不会报错，链接时在别的文件也找不到定义从而报错
public:
	Person10(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
private:
	T1 m_Name;
	T2 m_Age;
};
void test18()
{
	Person10<string, int>p10("Tom", 20);
	printPerson(p10);
	Person10<string, int>p100("Jerry", 30);
	printPerson1(p100);
}

//类模版案例-数组类封装
class Person11
{
public:
	Person11() {};
	Person11(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
void printIntArray(MyArray<int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << endl;
	}
}
void printPersonArray(MyArray<Person11>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "姓名：" << arr[i].m_Name << " 年龄： " << arr[i].m_Age << endl;
	}
}
void test19()
{
	MyArray<int>arr1(5);
	MyArray<int>arr2(arr1);
	MyArray<int>arr3(100);
	arr3 = arr1;
	for (int i = 0; i < 5; i++)//利用尾插法向数组中插入数据
	{
		arr1.Push_Back(i);
	}
	cout << "arr1的打印输出" << endl;
	printIntArray(arr1);
	cout << "arr1的容量为：" << arr1.getCapacity() << endl;
	cout << "arr1的大小为：" << arr1.getSize() << endl;
	MyArray<int>arr4(arr1);
	cout << "arr4的打印输出" << endl;
	printIntArray(arr4);
	arr4.Pop_Back();
	cout << "arr4的容量为：" << arr4.getCapacity() << endl;
	cout << "arr4的大小为：" << arr4.getSize() << endl;
	MyArray<Person11> arr(10);
	Person11 p1("孙悟空", 999);
	Person11 p2("韩信", 20);
	Person11 p3("妲己", 18);
	Person11 p4("王昭君", 15);
	Person11 p5("赵云", 24);
	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);
	printPersonArray(arr);
	cout << "arr的容量为：" << arr.getCapacity() << endl;
	cout << "arr的大小为：" << arr.getSize() << endl;
}

int main()
{
//模板的概念
	//模板就是建立通用的模具，大大提高复用性
	//模板的特点：
		//模板不可以直接使用，它只是一个框架
		//模板的通用并不是万能的

//函数模板基本语法 2025.11.7
	//C++ 另一种编程思想称为泛型编程，主要利用的技术就是模板
	//C++ 提供两种模板机制:函数模板和类模板
	//函数模板作用：
		//建立一个通用函数，其函数返回值类型和形参类型可以不具体制定，用一个虚拟的类型来代表。
	//语法：template<typename T> 函数声明或定义
	//解释：
		//template --- 声明创建模板
		//typename --- 表面其后面的符号是一种数据类型，可以用 class 代替
		//T --- 通用的数据类型，名称可以替换，通常为大写字母
	//总结：
		//函数模板利用关键字 template
		//使用函数模板有两种方式：自动类型推导、显示指定类型
		//模板的目的是为了提高复用性，将类型参数化
	test01();

//函数模板注意事项
	//注意事项：
		//自动类型推导，必须推导出一致的数据类型 T, 才可以使用
		//模板必须要确定出 T 的数据类型，才可以使用
	test02();

//数组排序
	//案例描述：
		//利用函数模板封装一个排序的函数，可以对不同数据类型数组进行排序
		//排序规则从大到小，排序算法为选择排序
		//分别利用 char 数组和 int 数组进行测试
	test03();
	test04();

//普通函数与函数模板区别：
		//普通函数调用时可以发生自动类型转换（隐式类型转换）
		//函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
		//如果利用显示指定类型的方式，可以发生隐式类型转换
	test05();

//普通函数与函数模板的调用规则
	//调用规则如下：
		//1. 如果函数模板和普通函数都可以实现，优先调用普通函数
		//2. 可以通过空模板参数列表来强制调用函数模板
		//3. 函数模板也可以发生重载
		//4. 如果函数模板可以产生更好的匹配, 优先调用函数模板
	//总结：既然提供了函数模板，最好就不要提供普通函数，否则容易出现二义性
	test06();

//模板的局限性
	//模板的通用性并不是万能的
	//template<class T>
	//void f(T a, T b){ a = b; }
	//在上述代码中提供的赋值操作，如果传入的a和b是一个数组，就无法实现了
	//template<class T>
	//void f(T a, T b){ if (a > b) { ... } }
	//在上述代码中，如果 T 的数据类型传入的是像 Person 这样的自定义数据类型，也无法正常运行
	//因此 C++ 为了解决这种问题，提供模板的重载，可以为这些特定的类型提供具体化的模板
	//总结：
		//利用具体化的模板，可以解决自定义类型的通用化
		//学习模板并不是为了写模板，而是在 STL 能够运用系统提供的模板
	test07();
	test08();

//类模板基本语法 2025.11.9
	//类模板作用：
		//建立一个通用类，类中的成员数据类型可以不具体制定，用一个虚拟的类型来代表。
	//语法：
		//template<typename T> 类
	//解释：
		//template  --- 声明创建模板
		//typename  --- 表面其后面的符号是一种数据类型，可以用 class 代替
		//T--- 通用的数据类型，名称可以替换，通常为大写字母
	test09();

//类模版与函数模版区别
	//类模板与函数模板区别主要有两点：
		//1. 类模板没有自动类型推导的使用方式，C++ 17 以上支持自动类型推导
		//2. 类模板在模板参数列表中可以有默认参数
	test10();
	test11();

//类模板中成员函数创建时机
	//类模板中成员函数和普通类中成员函数创建时机是有区别的：
		//普通类中的成员函数一开始就可以创建
		//类模板中的成员函数在调用时才创建
	//总结：类模板中的成员函数并不是一开始就创建的，在调用时才去创建
	test12();

//类模板对象做函数参数
	//类模板实例化出的对象，向函数传参的方式，一共有三种传入方式：
		//1. 指定传入的类型 --- 直接显示对象的数据类型
		//2. 参数模板化 --- 将对象中的参数变为模板进行传递
		//3. 整个类模板化 --- 将这个对象类型模板化进行传递
	//使用比较广泛是第一种：指定传入的类型
	test13();

//类模板与继承
	//当类模板碰到继承时，需要注意一下几点：
		//当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中 T 的类型
		//如果不指定，编译器无法给子类分配内存
		//如果想灵活指定出父类中 T 的类型，子类也需变为类模板
	test14();

//类模板成员函数类外实现
	//总结：类模板中成员函数类外实现时，需要加上模板参数列表
	test15();

//类模板分文件编写
	//问题：类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到
	//解决：
		//解决方式1：直接包含.cpp源文件，因为类模板中的成员函数在调用时才创建，所以看不见 cpp 当中的代码
		//解决方式2：将声明和实现写到同一个文件中，并更改后缀名为 .hpp，hpp 是约定的名称，并不是强制
	test16();
	test17();

//类模板与友元 2025.11.10
	//全局函数类内实现 - 直接在类内声明友元即可
	//全局函数类外实现 - 需要提前让编译器知道全局函数的存在
	test18();

//类模版案例-数组类封装的需求分析
	//案例描述:实现一个通用的数组类，要求如下：
		//可以对内置数据类型以及自定义数据类型的数据进行存储
		//将数组中的数据存储到堆区
		//构造函数中可以传入数组的容量
		//提供对应的拷贝构造函数以及 operator= 防止浅拷贝问题
		//提供尾插法和尾删法对数组中的数据进行增加和删除
		//可以通过下标的方式访问数组中的元素
		//可以获取数组中当前元素个数和数组的容量

//类模版案例-数组类封装
	test19();

	system("pause");
	return 0;
}
*/