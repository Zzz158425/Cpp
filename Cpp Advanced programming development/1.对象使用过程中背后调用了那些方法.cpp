#include<iostream>
using namespace std;
//2026.4.22

/*
//示例一
class Test
{
public:
	Test(int a = 10) : ma(a)
	{
		cout << "Test()" << endl;
	}
	~Test()
	{
		cout << "~Test()" << endl;
	}
	Test(const Test& t) : ma(t.ma)
	{
		cout << "Test(const Test&)" << endl;
	}
	Test& operator=(const Test& t)
	{
		cout << "operator=" << endl;
		ma = t.ma;
		return *this;
	}
private:
	int ma;
};

//示例二
class Test1
{
public:
	Test1(int a = 5, int b = 5) : ma(a), mb(b) { cout << "Test1(int, int)" << endl; }//可构造三种形式：Test1()，Test1(10)，Test1(10, 20)
	~Test1() { cout << "~Test1()" << endl; }
	Test1(const Test1& src) : ma(src.ma), mb(src.mb) { cout << "Test1(const Test& t)" << ma << endl; }
	Test1& operator = (const Test1& src)
	{
		cout << "operator=" << endl;
		ma = src.ma;
		mb = src.mb;
		return *this;
	}
private:
	int ma;
	int mb;
};
Test1 t11(10, 10);//全局变量会先构造，1.Test(int, int)

//示例三
class Test2
{
public:
	Test2(int a = 10) : ma(a)
	{
		cout << "Test2(int)" << endl;
	}
	~Test2()
	{
		cout << "~Test2()" << endl;
	}
	Test2(const Test2& t) : ma(t.ma)
	{
		cout << "Test2(const Test2&)" << endl;
	}
	Test2& operator=(const Test2& t)
	{
		cout << "operator=" << endl;
		ma = t.ma;
		return *this;
	}
	int getData() const { return ma; };
private:
	int ma;
};
//不能返回一个指针或引用，一定要保证函数结束后返回的对象依旧存在
Test2 GetObject(Test2 t)//3.Test2(const Test2&)，实参传递到形参会先初始化
{
	int val = t.getData();
	Test2 tmp(val);//不能通过指针或引用返回，4.Test2(int)
	//static Test2 tmp(val);在数据段，程序结束后对象才进行析构，可以通过指针或引用返回
	return tmp;//会构造一个临时对象将 tmp 带出函数 GetObject，5.Test2(const Test2&)
}
//函数 GetObject 结束后析构顺序为 tmp -> t

int main()
{
//示例一
	Test t1;
	Test t2(t1);
	Test t3 = t1;
	Test t4 = Test(20);//生命周期为所在语句，与 Test t4(20) 没有区别，不会产生临时对象，因为 C++ 编译器对于对象构造会自动优化：用临时对象生成新对象的时候，临时对象不产生了，直接构造新对象
	t4 = t2;//t4.operator=(const Test &t)，会产生临时对象
	//显示生成临时对象
	t4 = Test(30);//t4.operator=(const Test &t)，生成的对象无名字
	t4 = (Test)30;//t4.operator=(const Test &t)，int 类型强转 Test，需带整型的构造函数才能隐式生成临时对象
	//隐式生成临时对象
	t4 = 30;//T(30)，int 类型强转 Test，若是 char* 类型强转 Test，需提供 Test(char*) 构造函数
	//指针指向一个已经析构的临时对象
	//Test* p = &Test(40);指针不能取临时对象的地址，因为临时对象的生命周期为所在语句，p 在临时对象生命周期结束后会成为野指针
	const Test& ref = Test(50);//引用相当于给临时对象起了一个名字，会将其生命周期延长至引用变量的生命周期

//示例二
	cout << "----------Test1-----------" << endl;
	Test1 t21(20, 20);//3.Test1(int, int)
	Test1 t31 = t21;//4.Test1(const Test1& t)
	static Test1 t41 = Test1(30, 30);//5.Test1(const Test1& t)，静态局部变量，初始化是运行它时才进行，在数据段程序结束后才析构
	//显示生成临时对象
	t21 = Test1(40, 40);//6.Test1(int, int) -> t21.operator=(const Test1 &t) -> ~Test1()
	t21 = (Test1)(50, 50);//7.逗号表达式为最后一个值，(Test1)(50, 50)等价于(Test1)50；Test1(int, int) -> t21.operator=(const Test1 &t) -> ~Test1()
	//隐式生成临时对象
	t21 = 60;//8.Test1(int, int) -> t21.operator=(const Test1 &t) -> ~Test1()
	Test1* p11 = new Test1(70, 70);//9.Test1(int, int)
	Test1* p21 = new Test1[2];//10.Test1(int, int) -> Test1(int, int)
	//Test1 * p3 = &Test1(80, 80);指针不能取临时对象的地址，11.Test1(int, int) -> ~Test1()
	const Test1 &p41 = Test1(90, 90);//12.Test1(int, int)
	delete p11;//13.~Test1()
	delete[]p21;//13.~Test1() -> ~Test1()

//示例三
	cout << "----------Test2-----------" << endl;
	Test2 t12;//1.Test2(int)
	Test2 t22;//2.Test2(int)
	t22 = GetObject(t12);//6.operator=(const Test &t)
	//完成语句，GetObject 产生的用于将 tmp 带出函数 GetObject 的临时对象将立即析构 ~Test2()

	system("pause");
	return 0;
}
Test1 t51(100, 100);//2.Test1(int, int)
//Test1 程序结束后析构顺序为 p4 -> t31 -> t21 -> t41 -> t51 -> t11
//Test2 程序结束后析构顺序为 t22 -> t12
*/