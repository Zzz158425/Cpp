#include<iostream>
using namespace std;
#include<string>

/*
//构造函数和析构函数
class Person
{
public:

	Person()//构造函数
	{
		cout << "Person 构造函数的调用" << endl;
	}
	~Person()//析构函数
	{
		cout << "Person 析构函数的调用" << endl;
	}
};
void test01()
{
	Person p;//在栈上的数据，test01 执行完毕后会释放这个对象
}

//函数的分类及其调用 2025.10.27
class Person1
{
public:
	Person1()//无参（默认）构造函数
	{
		cout << "无参 构造函数!" << endl;
	}
	Person1(int a)//有参构造函数 
	{
		age = a;
		cout << "有参 构造函数!" << endl;
	}
	Person1(const Person1 &p)//拷贝构造函数
	{
		age = p.age;
		cout << "拷贝 构造函数!" << endl;
	}
	~Person1()//析构函数 
	{
		cout << "析构 函数!" << endl;
	}
public:
	int age;
};
void test02()
{
	Person1 p1;//括号法，默认构造函数调用
	//Person p2();调用无参构造函数不能加括号，如果加了编译器认为这是一个函数声明
	Person1 p2(10);//有参构造函数调用
	Person1 p3(p2);//拷贝构造函数调用
	cout << "P2 的年龄为：" << p2.age << endl;
	cout << "P3 的年龄为：" << p3.age << endl;
	Person1 p11;//显示法
	Person1 p22 = Person1(10);//显式法
	Person1 p33 = Person1(p22);
	Person1(10);//匿名对象，特点：当前行执行结束后，系统会立即回收掉匿名对象
	Person1 p4 = 10;//隐式转换法 Person1 p4 = Person1(10);
	//Person1(p33);不要利用拷贝构造函数，初始化匿名对象，编译器会认为 Person1(p33) === Person1 p33;
	Person1 p5 = p4; // Person1 p5 = Person1(p4); 
}

//拷贝构造函数调用时机
class Person2
{
public:
	Person2()//无参（默认）构造函数
	{
		cout << "Person2 默认构造函数调用!" << endl;
	}
	Person2(int age)//有参构造函数 
	{
		m_Age = age;
		cout << "Person2 有参构造函数调用!" << endl;
	}
	Person2(const Person2& p)//拷贝构造函数
	{
		m_Age = p.m_Age;
		cout << "Person2 拷贝构造函数调用!" << endl;
	}
	~Person2()//析构函数 
	{
		cout << "Person2 析构函数调用!" << endl;
	}
public:
	int m_Age;
};
void test03()//使用一个已经创建完毕的对象来初始化一个新对象
{
	Person2 p1(20);
	Person2 p2(p1);
	cout << "P2 的年龄为：" << p2.m_Age << endl;
}
void doWork(Person2 p)//值传递的方式给函数参数传值
{

}
void test04()
{
	Person2 p;
	doWork(p);
}
Person2 doWork1()//以值方式返回局部对象
{
	Person2 p1;
	cout << (int*)&p1 << endl;
	return Person2(p1);
}
void test05()
{
	Person2 p = doWork1();
	cout << (int*)&p << endl;
}

//构造函数的调用规则
class Person3
{
public:
	Person3()//无参（默认）构造函数
	{
		cout << "Person3 默认构造函数调用!" << endl;
	}
	Person3(int age)//有参构造函数 
	{
		m_Age = age;
		cout << "Person3 有参构造函数调用!" << endl;
	}
	Person3(const Person3& p)//拷贝构造函数
	{
		m_Age = p.m_Age;
		cout << "Person3 拷贝构造函数调用!" << endl;
	}
	~Person3()//析构函数 
	{
		cout << "Person3 析构函数调用!" << endl;
	}
public:
	int m_Age;
};
void test06()
{
	Person3 p;
	p.m_Age = 18;
	Person3 p2(p);
	cout << "P2 的年龄为：" << p2.m_Age << endl;
}

//深拷贝与浅拷贝
class Person4
{
public:
	Person4()//无参（默认）构造函数
	{
		cout << "Person4 默认构造函数调用!" << endl;
	}
	Person4(int age, int height)//有参构造函数 
	{
		m_Age = age;
		m_Height = new int(height);
		cout << "Person4 有参构造函数调用!" << endl;
	}
	Person4(const Person4& p)//拷贝构造函数
	{
		cout << "Person4 拷贝构造函数调用!" << endl;
		m_Age = p.m_Age;
		//m_Height = p.m_Height;编译器会默认实现这行代码
		m_Height = new int(*p.m_Height);//深拷贝操作，再申请一块空间，防止两次执行析构函数时会重复释放同一空间造成中断
	}
	~Person4()//析构函数 
	{
		//将堆区开辟的数据释放
		if (m_Height != NULL)
		{
			delete m_Height;
			m_Height = NULL;
		}
		cout << "Person4 析构函数调用!" << endl;
	}
public:
	int m_Age;
	int* m_Height;
};
void test07()
{
	Person4 p1(18, 160);
	cout << "P1 的年龄为：" << p1.m_Age << "身高为：" << *p1.m_Height << endl;
	Person4 p2(p1);
	cout << "P2 的年龄为：" << p2.m_Age << "身高为：" << *p2.m_Height << endl;
}

//初始化列表
class Person5
{
public:
	Person5(int a, int b, int c)//传统初始化操作
	{
		m_A = a;
		m_B = b;
		m_C = c;
	}
public:
	int m_A;
	int m_B;
	int m_C;
};
void test08()
{
	Person5 p(10, 20, 30);
	cout << "m_A:" << p.m_A << endl;
	cout << "m_B:" << p.m_B << endl;
	cout << "m_C:" << p.m_C << endl;
}
class Person6//初始化列表初始化属性
{
public:
	Person6(int a, int b, int c) :m_A(a), m_B(b), m_C(c)
	{

	}
public:
	int m_A;
	int m_B;
	int m_C;
};
void test09()
{
	Person6 p(10, 20, 30);
	cout << "m_A:" << p.m_A << endl;
	cout << "m_B:" << p.m_B << endl;
	cout << "m_C:" << p.m_C << endl;
}

//类对象作为类成员 2025.10.28
class Phone
{
public:
	Phone(string name)
	{
		m_PhoneName = name;
		cout << "Phone构造" << endl;
	}

	~Phone()
	{
		cout << "Phone析构" << endl;
	}

	string m_PhoneName;

};
class Person7
{
public:
	//初始化列表可以告诉编译器调用哪一个构造函数
	Person7(string name, string pName) :m_Name(name), m_Phone(pName)
	{
		cout << "Person7构造" << endl;
	}
	~Person7()
	{
		cout << "Person析构" << endl;
	}
	void playGame()
	{
		cout << m_Name << " 使用" << m_Phone.m_PhoneName << " 牌手机! " << endl;
	}
	string m_Name;
	Phone m_Phone;
};
void test10()
{
	Person7 p("张三", "苹果MAX");
	p.playGame();

}

//静态成员
class Person8//静态成员变量
{

public:

	static int m_A; //静态成员变量，类内声明

private:
	static int m_B; //静态成员变量也是有访问权限的
};
int Person8::m_A = 10;//类外初始化
int Person8::m_B = 10;
void test11()
{
	Person8 p;
	cout << p.m_A << endl;
	Person8 p2;
	p2.m_A = 200;
	cout << p.m_A << endl;
	//静态成员变量两种访问方式
	Person8 p1;//通过对象访问
	p1.m_A = 100;
	cout << "p1.m_A = " << p1.m_A << endl;
	Person8 p3;
	p3.m_A = 200;
	cout << "p1.m_A = " << p1.m_A << endl; //共享同一份数据
	cout << "p3.m_A = " << p3.m_A << endl;
	cout << "m_A = " << Person8::m_A << endl;//通过类名访问
	//cout << "m_B = " << Person8::m_B << endl; //私有权限访问不到
}
class Person9//静态成员函数
{

public:

	static void func()
	{
		cout << "static void func调用" << endl;
		m_A = 100;//静态成员函数可以访问静态成员变量
		//m_B = 100;//错误，不可以访问非静态成员变量，无法区分到底是那个对象的m_B，因为他是非静态成员变量，分开各自存储
	}
	static int m_A;//静态成员变量
	int m_B;//非静态成员变量
private:
	static void func2()//静态成员函数也是有访问权限的
	{
		cout << "func2调用" << endl;
	}
};
int Person9::m_A = 0;
void test12()
{
	Person9 p;//通过对象访问
	p.func();
	Person9::func();//通过类名访问
	//Person::func2(); //私有权限访问不到
}

//成员变量和成员函数分开存储
class Person10//空对象
{

};
void test13()
{
	Person10 p;//C++ 编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置，每个空对象也应该有一个独一无二的内存地址
	cout << "size of p = " << sizeof(p) << endl;//空对象占用内存空间位 1 
}
class Person11//非空对象
{
	int m_A;//非静态成员变量，属于类的对象上
	static int m_B;//静态成员变量，不属于类的对象上
	void func() {}//非静态成员函数，不属于类的对象上
	static void func2() {}//静态成员函数，不属于类的对象上
};
void test14()
{
	Person11 p;
	cout << "size of p = " << sizeof(p) << endl;
}

//this 指针的用途
class Person12//解决名称冲突
{
public:
	Person12(int age)
	{
		this -> age = age;//this 指针指向被调用的成员函数所属的对象
	}
	Person12& PersonAddAge(Person12 &p)
	{
		this->age += p.age;
		return *this;//this 指向 p2 的指针，而 *this 指向的就是 p2 这个对象本体
	}
	int age;
};
void test15()
{
	Person12 p1(18);
	cout << "p1的年龄为：" << p1.age << endl;
}
void test16()
{
	Person12 p1(10);
	Person12 p2(10);
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);//链式编程思想
	cout << "p2的年龄为：" << p2.age << endl;

}

//空指针访问成员函数
class Person13//解决名称冲突
{
public:
	void ShowClassName() {
		cout << "我是Person类!" << endl;
	}

	void ShowPerson() {
		if (this == NULL) {
			return;
		}
		cout << "m_Age = " << m_Age << endl;//cout << "m_Age = " << this->m_Age << endl;this 指向p，若 p 为空则会出错
	}

public:
	int m_Age;
};
void test17()
{
	Person13* p = NULL;//空指针
	p->ShowClassName();//空指针，可以调用成员函数
	p->ShowPerson();//但是如果成员函数中用到了 this 指针，就不可以了
}

//const修饰成员函数
class Person14//常函数
{
public:
	Person14() {
		m_A = 0;
		m_B = 0;
	}
	//this 指针的本质是一个指针常量，指针的指向不可修改
	//如果想让指针指向的值也不可以修改，需要声明常函数
	void ShowPerson() const//修饰 this，让指针指向的值也不可以修改
	{
		//const Type* const pointer;
		//this = NULL; //不能修改指针的指向 Person* const this;
		//this->mA = 100; //但是 this 指针指向的对象的数据是可以修改的
		this->m_B = 100;
	}

	void MyFunc() 
	{
		m_A = 10000;
	}

public:
	int m_A;
	mutable int m_B; //可修改 可变的
};
void test18()
{
	Person14 p;
	p.ShowPerson();
}
void test19()//常对象
{
	const Person14 p;
	p.ShowPerson();
	//p.MyFunc();常对象只能调用常函数，因为普通成员函数可以修改属性，与之矛盾
	//p.m_A = 100;无法修改
	p.m_B = 100;//加 mutable 后，在常对象下也可以修改
}

int main()
{
//构造函数和析构函数 2025.10.26
	//对象的初始化和清理也是两个非常重要的安全问题
	//一个对象或者变量没有初始状态，对其使用后果是未知
	//同样的，使用完一个对象或变量，没有及时清理，也会造成一定的安全问题
	//c++ 利用了构造函数和析构函数解决上述问题，这两个函数将会被编译器自动调用，完成对象初始化和清理工作。
	//对象的初始化和清理工作是编译器强制要我们做的事情，因此如果我们不提供构造和析构，编译器会提供编译器提供的构造函数和析构函数是空实现
	//构造函数：主要作用在于创建对象时为对象的成员属性赋值，构造函数由编译器自动调用，无须手动调用。
	//析构函数：主要作用在于对象销毁前系统自动调用，执行一些清理工作。
	//构造函数语法：类名() {}
		//1. 构造函数，没有返回值也不写 void
		//2. 函数名称与类名相同
		//3. 构造函数可以有参数，因此可以发生重载
		//4. 程序在调用对象时候会自动调用构造，无须手动调用, 而且只会调用一次
	//析构函数语法：~类名() {}
		//1. 析构函数，没有返回值也不写void
		//2. 函数名称与类名相同, 在名称前加上符号  ~
		//3. 析构函数不可以有参数，因此不可以发生重载
		//4. 程序在对象销毁前会自动调用析构，无须手动调用, 而且只会调用一次
	test01();
	Person p;//对象在system("pause")后释放，即调用析构函数

//函数的分类及其调用 2025.10.27
	//两种分类方式：
		//​按参数分为： 有参构造和无参构造
		//​按类型分为： 普通构造和拷贝构造
	//三种调用方法
		//括号法
		//显示法
		//隐式转换法
	test02();

//拷贝构造函数调用时机
	//C++ 中拷贝构造函数调用时机通常有三种情况
		//使用一个已经创建完毕的对象来初始化一个新对象
		//值传递的方式给函数参数传值
		//以值方式返回局部对象
	test03();
	test04();
	test05();

//构造函数的调用规则
	//默认情况下，c++ 编译器至少给一个类添加 3 个函数
		//1．默认构造函数(无参，函数体为空)
		//2．默认析构函数(无参，函数体为空)
		//3．默认拷贝构造函数，对属性进行值拷贝
	//构造函数调用规则如下：
		//如果用户定义有参构造函数，c++ 不在提供默认无参构造，但是会提供默认拷贝构造
		//如果用户定义拷贝构造函数，c++ 不会再提供其他构造函数
	test06();

//深拷贝与浅拷贝
	//深浅拷贝是面试经典问题，也是常见的一个坑
		//浅拷贝：简单的赋值拷贝操作
		//深拷贝：在堆区重新申请空间，进行拷贝操作
	test07();

//初始化列表
	//作用：C++ 提供了初始化列表语法，用来初始化属性
	//语法：构造函数()：属性1(值1), 属性2（值2）... {}
	test08();
	test09();

//类对象作为类成员 2025.10.28
	//C++ 类中的成员可以是另一个类的对象，我们称该成员为对象成员
	//构造的顺序是 ：先调用对象成员的构造，再调用本类构造
	//析构顺序与构造相反
	test10();
	test11();
//静态成员
	//静态成员就是在成员变量和成员函数前加上关键字 static，称为静态成员
	//静态成员分为：
		//静态成员变量
			//所有对象共享同一份数据
			//在编译阶段分配内存
			//类内声明，类外初始化
		//静态成员函数
			//所有对象共享同一个函数
			//静态成员函数只能访问静态成员变量
	test11();
	test12();

//成员变量和成员函数分开存储
	//在 C++ 中，类内的成员变量和成员函数分开存储，只有非静态成员变量才属于类的对象上
	test13();
	test14();

//this 指针的用途
	//我们知道在 C++ 中成员变量和成员函数是分开存储的
	//每一个非静态成员函数只会诞生一份函数实例，也就是说多个同类型的对象会共用一块代码
	//那么问题是：这一块代码是如何区分那个对象调用自己的呢？
	//c++ 通过提供特殊的对象指针，this 指针，解决上述问题，this 指针指向被调用的成员函数所属的对象
	//this 指针是隐含每一个非静态成员函数内的一种指针
	//this 指针不需要定义，直接使用即可
	//this 指针的用途：
		//当形参和成员变量同名时，可用 this 指针来区分
		//在类的非静态成员函数中返回对象本身，可使用 return *this
	test15();
	test16();

//空指针访问成员函数
	//C++ 中空指针也是可以调用成员函数的，但是也要注意有没有用到 this 指针
	//如果用到 this 指针，需要加以判断保证代码的健壮性
	test17();

//const修饰成员函数
	//常函数：
		//成员函数后加 const 后我们称为这个函数为常函数
		//常函数内不可以修改成员属性
		//成员属性声明时加关键字 mutable 后，在常函数中依然可以修改
	//常对象：
		//声明对象前加 const 称该对象为常对象
		//常对象只能调用常函数
	test18();

	system("pause");
	return 0;
}
*/