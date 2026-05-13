#include<iostream>
using namespace std;
#include<string>

/*
//基本语法 2025.10.31
class Java//普通实现
{
public:
	void header()
	{
		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
	}
	void footer()
	{
		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
	}
	void left()
	{
		cout << "Java,Python,C++...(公共分类列表)" << endl;
	}
	void content()
	{
		cout << "JAVA学科视频" << endl;
	}
};
class Python
{
public:
	void header()
	{
		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
	}
	void footer()
	{
		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
	}
	void left()
	{
		cout << "Java,Python,C++...(公共分类列表)" << endl;
	}
	void content()
	{
		cout << "Python学科视频" << endl;
	}
};
class CPP
{
public:
	void header()
	{
		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
	}
	void footer()
	{
		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
	}
	void left()
	{
		cout << "Java,Python,C++...(公共分类列表)" << endl;
	}
	void content()
	{
		cout << "C++ 学科视频" << endl;
	}
};
void test01()
{
	cout << "Java 下载视频页面如下： " << endl;//Java页面
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();
	cout << "--------------------" << endl;
	cout << "Python 下载视频页面如下： " << endl;//Python页面
	Python py;
	py.header();
	py.footer();
	py.left();
	py.content();
	cout << "--------------------" << endl;
	cout << "C++ 下载视频页面如下： " << endl;//C++页面
	CPP cp;
	cp.header();
	cp.footer();
	cp.left();
	cp.content();
}
class BasePage//继承实现
{
public:
	void header()
	{
		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
	}
	void footer()
	{
		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
	}
	void left()
	{
		cout << "Java,Python,C++...(公共分类列表)" << endl;
	}
};
class Java1 :public BasePage
{
public:
	void content()
	{
		cout << "Jave 学科视频" << endl;
	}
};
class Python1 :public BasePage
{
public:
	void content()
	{
		cout << "Python 学科视频" << endl;
	}
};
class CPP1 :public BasePage
{
public:
	void content()
	{
		cout << "C++ 学科视频" << endl;
	}
};
void test02()
{
	//Java页面
	cout << "Java下载视频页面如下： " << endl;
	Java1 ja1;
	ja1.header();
	ja1.footer();
	ja1.left();
	ja1.content();
	cout << "--------------------" << endl;

	//Python页面
	cout << "Python下载视频页面如下： " << endl;
	Python1 py1;
	py1.header();
	py1.footer();
	py1.left();
	py1.content();
	cout << "--------------------" << endl;

	//C++页面
	cout << "C++下载视频页面如下： " << endl;
	CPP1 cp1;
	cp1.header();
	cp1.footer();
	cp1.left();
	cp1.content();
}

//继承方式
class Base1
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
class Son1 :public Base1//公共继承
{
public:
	void func()
	{
		m_A = 10;//可访问 public 权限
		m_B = 10;//可访问 protected 权限
		//m_C = 10;不可访问
	}
};
void test03()
{
	Son1 s1;
	s1.m_A = 100;//类外只能访问到公共权限
	cout << "m_A = " << s1.m_A << endl;
}
class Son2 :protected Base1//保护继承
{
public:
	void func()
	{
		m_A = 10; //可访问 protected 权限
		m_B = 10; //可访问 protected 权限
		//m_C = 10; //不可访问
	}
};
void test04()
{
	Son2 s;
	//s.m_A = 100; //类外只能访问到公共权限
}
class Son3 :private Base1
{
public:
	void func()
	{
		m_A = 10; //可访问 private权限
		m_B = 10; //可访问 private权限
		//m_C = 10; //不可访问
	}
};
void test05()
{
	Son3 s;
	//s.m_A = 100; //类外只能访问到公共权限
}
class GrandSon3 :public Son3
{
public:
	void func()
	{
		//m_A = 10;Son3 私有继承 Base1，m_A变为私有，无法访问
	}
};

//继承中的对象模型
class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C; //私有成员只是被隐藏了，但是还是会继承下去
};
class Son :public Base//公共继承
{
public:
	int m_D;
};
void test06()
{
	cout << "sizeof Son = " << sizeof(Son) << endl;
}

//构造和析构顺序
class Base2
{
public:
	Base2()
	{
		cout << "Base2 构造函数!" << endl;
	}
	~Base2()
	{
		cout << "Base2 析构函数!" << endl;
	}
};
class Son4 :public Base2
{
public:
	Son4()
	{
		cout << "Son4 构造函数!" << endl;
	}
	~Son4()
	{
		cout << "Son4 析构函数!" << endl;
	}

};
void test07()
{
	Son4 s;//继承中 先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反
}

//同名成员处理
class Base3
{
public:
	Base3()
	{
		m_A = 100;
	}

	void func()
	{
		cout << "Base3 - func()调用" << endl;
	}

	void func(int a)
	{
		cout << "Base3 - func(int a)调用" << endl;
	}

public:
	int m_A;
};
class Son5 : public Base3
{
public:
	Son5()
	{
		m_A = 200;
	}
	void func()
	{
		cout << "Son5 - func()调用" << endl;
	}
public:
	int m_A;
};
void test08()
{
	Son5 s;
	cout << "Son5 下的m_A = " << s.m_A << endl;
	cout << "Base3 下的m_A = " << s.Base3::m_A << endl;
	s.func();
	s.Base3::func();
	s.Base3::func(10);
}

//同名静态成员处理
class Base4
{
public:
	static int m_A;
	static void func()
	{
		cout << "Base4 - static void func()" << endl;
	}
	static void func(int a)
	{
		cout << "Base4 - static void func(int a)" << endl;
	}
};
int Base4::m_A = 100;
class Son6 :public Base4
{
public:
	static int m_A;
	static void func()
	{
		cout << "Son6 - static void func()" << endl;
	}
};
int Son6::m_A = 200;
void test09()
{
	Son6 s;//通过对象访问
	cout << "通关对象访问 Son6 m_A = " << s.m_A << endl;
	cout << "通关对象访问 Base4 m_A = " << s.Base4::m_A << endl;
	cout << "通关类名访问 Son6 m_A = " << Son6::m_A << endl;//通过类名访问
	cout << "通关类名访问 Base4 m_A = " << Son6::Base4::m_A << endl;//通过类名的方式访问父类下的 m_A
	cout << "通关类名访问 Base4 m_A = " << Base4::m_A << endl;//通过类名的方式访问 Base4 下的 m_A
	s.func();//通过对象访问
	s.Base4::func();
	s.Base4::func(10);
	Son6::func();//通过类名访问
	Son6::Base4::func();
}

//多继承语法
class Base5
{
public:
	Base5()
	{
		m_A = 111;
	}
	int m_A;
};
class Base6
{
public:
	Base6()
	{
		m_A = 555;
		m_B = 222;
	}
	int m_B;
	int m_A;
};
class Son7 :public Base5, public Base6
{
public:
	Son7()
	{
		m_C = 333;
		m_D = 444;
	}
	int m_C;
	int m_D;
};
void test10()
{
	Son7 s;
	cout << "sizeof Son7 = " << sizeof(Son7) << endl;
	cout << "m_B = " << s.m_B << endl;//当父类中出现同名成员，需加作用域区分
	cout << "Base5 m_A = " << s.Base5::m_A << endl;//当父类中出现同名成员，需加作用域区分
	cout << "Base6 m_A = " << s.Base6::m_A << endl;//当父类中出现同名成员，需加作用域区分
}

//菱形继承问题及其解决方法
class Animal//菱形继承问题
{
public:
	int m_Age;
};
class Sheep :public Animal {};
class Camel :public Animal {};
class Alpaca :public Sheep, public Camel{};
void test11()
{
	Alpaca al;
	al.Sheep::m_Age = 18;//Alpaca 分别从 Sheep 和 Camel 各子继承了一个 m_Age，需加作用域，此外，该数据有一份即可，继承导致数据有两份，资源浪费
	al.Camel::m_Age = 28;
	cout << "al.Sheep m_Aage = " << al.Sheep::m_Age << endl;
	cout << "al.Camel m_Aage = " << al.Camel::m_Age << endl;
}
class Animal1//利用虚继承解决菱形继承问题
{
public:
	int m_Age;
};
class Sheep1 :virtual public Animal1 {};
class Camel1 :virtual public Animal1 {};
class Alpaca1 :public Sheep1, public Camel1 {};
void test12()
{
	Alpaca1 al;
	al.Sheep1::m_Age = 18;
	al.Camel1::m_Age = 28;
	cout << "al.Sheep1 m_Aage = " << al.Sheep1::m_Age << endl;
	cout << "al.Camel1 m_Aage = " << al.Camel1::m_Age << endl;
	cout << al.m_Age << endl;
}

int main()
{
//基本语法 2025.10.31
	//继承是面向对象三大特性之一
	//有些类与类之间存在特殊的关系，我们发现，定义这些类时，下级别的成员除了拥有上一级的共性，还有自己的特性。这个时候我们就可以考虑利用继承的技术，减少重复代码
	//总结：继承的好处：可以减少重复的代码
	//语法：class A : public B;A 类称为子类或派生类，B 类称为父类或基类
	//派生类中的成员，包含两大部分：
		//一类是从基类继承过来的，一类是自己增加的成员。
		//从基类继承过过来的表现其共性，而新增的成员体现了其个性。
	test01();
	test02();

//继承方式
		//继承的语法：class 子类 : 继承方式  父类
	//继承方式一共有三种：
		//公共继承
		//保护继承
		//私有继承
	test03();
	test04();
	test05();

//继承中的对象模型
	//父类中所有非静态成员属性都会被子类继承下去
	//父类中私有成员属性是被编译器隐藏了，因此访问不到，但是确实被继承下去了
	//利用开发人员命令提示工具查看对象模型 -> 跳转盘符 F: -> 跳转文件路径 cd 具体路径下 -> cl / d1 reportSingleClassLayout 类名
	test06();

//构造和析构顺序
	//子类继承父类后，当创建子类对象，也会调用父类的构造函数
	//先构造父亲，再构造子类，析构顺序与构造顺序想反
	test07();

//同名成员处理
	//当子类与父类出现同名的成员，访问子类同名成员，直接访问即可；访问父类同名成员，需要加作用域
	//当子类与父类拥有同名的成员函数，子类会隐藏父类中所有版本的同名成员函数
	//如果想访问父类中被隐藏的同名成员函数，需要加父类的作用域
	//当子类与父类拥有同名的成员函数，子类会隐藏父类中同名成员函数，加作用域可以访问到父类中同名函数
	test08();

//同名静态成员处理
	//继承中同名的静态成员在子类对象上，静态成员和非静态成员出现同名，处理方式一致，访问子类同名成员，直接访问即可；访问父类同名成员，需要加作用域
	test09();

//多继承语法
	//C++ 允许一个类继承多个类
	//语法：class 子类 ：继承方式 父类1 ，继承方式 父类2...
	//多继承可能会引发父类中有同名成员出现，需要加作用域区分，C++ 实际开发中不建议用多继承
	test10();

//菱形继承问题及其解决方法
	//菱形继承概念：
		//两个派生类继承同一个基类
		//又有某个类同时继承者两个派生类
		//这种继承被称为菱形继承，或者钻石继承
	//利用虚继承，可以解决菱形继承问题，继承之前，加上关键字 virtual 变为虚继承
	test11();
	test12();

	system("pause");
	return 0;
}
*/
