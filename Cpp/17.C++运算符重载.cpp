#include<iostream>
using namespace std;
#include<string>

/*
//加号运算符重载
class Person
{
public:
	//Person operator+(Person& A)//成员函数重载 + 号
	//{
	//	Person temp;
	//	temp.m_B = this->m_B + A.m_B;
	//	temp.m_A = this->m_A + A.m_A;
	//	return temp;
	//}
public:
	int m_A;
	int m_B;
};
Person operator+(Person& P1, Person& P2)//全局函数重载 + 号，Person + Person
{
	Person temp;
	temp.m_B = P1.m_B + P2.m_B;
	temp.m_A = P1.m_A + P2.m_A;
	return temp;
}
Person operator+(Person& P1, int num)//Person + int，运算符重载也可以发生函数重载
{
	Person temp;
	temp.m_B = P1.m_B + num;
	temp.m_A = P1.m_A + num;
	return temp;
}
void test01()
{
	Person p1;
	Person p2;
	p1.m_A = 10;
	p1.m_B = 20;
	p2.m_A = 10;
	p2.m_B = 20;
	Person p3 = p1 + p2;
	cout << "p3.m_A = " << p3.m_A << endl;
	cout << "p3.m_B = " << p3.m_B << endl;
	//Person p3 = p1.operator+(p2);成员函数重载本质调用
	//Person p3 = operator+(p1, p2);全局函数重载本质调用
	Person p4 = p1 + 100;
	cout << "p4.m_A = " << p4.m_A << endl;
	cout << "p4.m_B = " << p3.m_B << endl;
}

//左移运算符重载
class Person1
{
public:
	Person1(int a, int b):m_A(a), m_B(b)//构造函数赋值
	{

	}
	friend ostream& operator<<(ostream& cout, Person1& p);//友元
public:
	void operator<<(Person1& p)//成员函数重载 <<
	{
		//成员函数 实现不了  p << cout 不是我们想要的效果，无法实现 cout 在左侧
		//void operator<<(Person& p){}
	}
private:
	int m_A;
	int m_B;
};
ostream& operator<<(ostream& cout, Person1& p)//成员函数重载 <<，cout 为输出流对象，全局只能有一个
{
	cout << "m_A = " << p.m_A << " m_B = " << p.m_B << endl;
	return cout;//返回 cout 可实现链式
}
void test02()
{
	Person1 p(20, 20);
	cout << p << endl;
}

//递增运算符重载 2025.10.30
class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger myint);
public:
	MyInteger()
	{
		m_Num = 0;
	}
	MyInteger& operator++()//成员函数重载前置 ++，返回引用是希望对一个数据进行操作
	{
		m_Num++;
		return *this;
	}
	MyInteger operator++(int)//成员函数重载后置 ++，参数为int，代表占位参数，编译器就会认为这是后置 ++ 的重载
	{
		MyInteger temp = *this;
		m_Num++;
		return temp;//只能用值返回，不能返回引用，temp 为局部变量
	}
	MyInteger& operator--()//成员函数重载前置 --
	{
		m_Num--;
		return *this;
	}
	MyInteger operator--(int)//成员函数重载后置 --
	{
		MyInteger temp = *this;
		m_Num--;
		return temp;
	}
private:
	int m_Num;
};
ostream& operator<<(ostream& cout, MyInteger myint)
{
	cout << myint.m_Num;
	return cout;
}
void test03()
{
	MyInteger myint;
	cout << myint << endl;
	cout << ++myint << endl;
	cout << ++(++myint) << endl;
}
void test04()
{
	MyInteger myint;
	cout << myint << endl;
	cout << myint++ << endl;
	cout << (myint++)++ << endl;
}

//递减运算符重载
//MyInteger& operator--(MyInteger& p)//全局函数重载前置 --
//{
//	p.m_Num--;
//	return p;
//}
//MyInteger operator--(MyInteger& p, int)//全局函数重载后置 -- 错误！！！
//{
//	MyInteger temp;
//	temp = p;
//	p.m_Num--;          
//	return temp;
//}
void test05()
{
	MyInteger myint;
	cout << myint << endl;
	cout << --myint << endl;
	cout << --(--myint) << endl;
}
void test06()
{
	MyInteger myint;
	cout << myint << endl;
	cout << myint-- << endl;
	cout << (myint--)-- << endl;
}

//赋值运算符重载
class Person2
{
public:
	Person2(int age)
	{
		m_Age = new int(age);
	}
	~Person2()//系统自带 = 是浅拷贝，会出现重复释放，需要重载 = ，使其实现深拷贝
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}
	Person2& operator=(Person2& p)//成员函数重载 =
	{
		//编译器提供的代码是浅拷贝，m_Age = p.m_Age;
		if (m_Age != NULL)//先判断是否有属性在堆区，如果有先释放干净，再进行深拷贝，因为原有数据不一定装的下新数据，为了代码规范性
		{
			delete m_Age;
			m_Age = NULL;
		}
		m_Age = new int(*p.m_Age);//深拷贝，重新申请一块空间，防止重复释放
		return *this;
	}
	int* m_Age;
};
void test07()
{
	Person2 p1(18);
	Person2 p2(20);
	Person2 p3(30);
	cout << "p1 的年龄为：" << *p1.m_Age << endl;
	cout << "p2 的年龄为：" << *p2.m_Age << endl;
	p2 = p1;
	cout << "p1 的年龄为：" << *p1.m_Age << endl;
	cout << "p2 的年龄为：" << *p2.m_Age << endl;
	p3 = p2 = p1;
	cout << "p1 的年龄为：" << *p1.m_Age << endl;
	cout << "p2 的年龄为：" << *p2.m_Age << endl;
	cout << "p3 的年龄为：" << *p3.m_Age << endl;
}

//关系运算符重载
class Person3
{
public:
	Person3(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	};
	bool operator==(Person3 &p)//成员函数重载 ==
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator!=(Person3& p)//成员函数重载 !=
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	string m_Name;
	int m_Age;
};
void test08()
{
	Person3 p1("TOM", 18);
	Person3 p2("TOM", 18);
	Person3 p3("Jerry", 18);
	if (p1 == p2)
	{
		cout << "p1 和 p2 是相等的" << endl;
	}
	else
	{
		cout << "p1 和 p2 不相等的" << endl;
	}
	if (p1 != p3)
	{
		cout << "p1 和 p3 不相等的" << endl;
	}
	else
	{
		cout << "p1 和 p3 是相等的" << endl;
	}
}

//函数调用运算符重载
class MyPrint
{
public:
	void operator()(string test)
	{
		cout << test << endl;
	}
};
void test09()
{
	MyPrint myPrint;
	myPrint("hello world");//使用起来非常类似于函数调用，因此称仿函数

}
class Myadd
{
public:
	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}
};
void test10()
{
	Myadd myadd;
	int ret = myadd(100, 100);//使用起来非常类似于函数调用，因此称仿函数
	cout << ret << endl;
	cout << Myadd()(100, 100) << endl;//匿名函数对象
}
int main()
{
//加号运算符重载
	//运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
	//总结1：对于内置的数据类型的表达式的的运算符是不可能改变的
	//总结2：不要滥用运算符重载
	test01();

//左移运算符重载 
	//作用：可以输出自定义数据类型
	test02();

//递增运算符重载 2025.10.30
	//作用：通过重载递增运算符，实现自己的整型数据
	//总结：前置递增返回引用，后置递增返回值
	test03();
	test04();

//递减运算符重载
	test05();
	test06();

//赋值运算符重载
	//c++ 编译器至少给一个类添加4个函数
		//1. 默认构造函数(无参，函数体为空)
		//2. 默认析构函数(无参，函数体为空)
		//3. 默认拷贝构造函数，对属性进行值拷贝
		//4. 赋值运算符 operator=, 对属性进行值拷贝
	//如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题
	test07();

//关系运算符重载
	//作用：重载关系运算符，可以让两个自定义类型对象进行对比操作
	test08();

//函数调用运算符重载
	//函数调用运算符()也可以重载
	//由于重载后使用的方式非常像函数的调用，因此称为仿函数
	//仿函数没有固定写法，非常灵活
	test09();
	test10();

	system("pause");
	return 0;
}
*/
