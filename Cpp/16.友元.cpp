#include<iostream>
using namespace std;
#include<string>

/*
//全局函数做友元 2025.10.29
class Building
{
	
	friend void goodGay(Building* building);//告诉编译器 goodGay 全局函数 是 Building 类的好朋友，可以访问类中的私有内容
public:
	Building()
	{
		this->m_SittingRoom = "客厅";
		this->m_BedRoom = "卧室";
	}
public:
	string m_SittingRoom; //客厅

private:
	string m_BedRoom; //卧室
};
void goodGay(Building* building)
{
	cout << "test01好基友正在访问： " << building->m_SittingRoom << endl;
	cout << "test01好基友正在访问： " << building->m_BedRoom << endl;
}
void test01()
{
	Building b;
	goodGay(&b);
}

//友元类
class Building1;
class goodGay1
{
public:

	goodGay1();
	void visit();

private:
	Building1* building1;
};
class Building1
{
	friend class goodGay1;//告诉编译器 goodGay 类是 Building 类的好朋友，可以访问到 Building 类中私有内容
public:
	Building1();
public:
	string m_SittingRoom; //客厅
private:
	string m_BedRoom;//卧室
};
Building1::Building1()//类外写成员函数
{
	this->m_SittingRoom = "客厅";
	this->m_BedRoom = "卧室";
}
goodGay1::goodGay1()//类外写成员函数
{
	building1 = new Building1;
}
void goodGay1::visit()//类外写成员函数
{
	cout << "test02好基友正在访问" << building1->m_SittingRoom << endl;
	cout << "test02好基友正在访问" << building1->m_BedRoom << endl;
}
void test02()
{
	goodGay1 gg;
	gg.visit();
}

//成员函数做友元
class Building2;
class GoodGay2
{
public:
	GoodGay2();
	void visit1();//visit1 可以访问 Building 中私有成员
	void visit2();//visit2 不可以访问 Building 中私有成员
	Building2* building2;
};
class Building2
{
	friend void GoodGay2::visit1();//告诉编译器  goodGay 类中的 visit1 成员函数是 Building 好朋友，可以访问私有内容
public:
	Building2();
public:
	string m_SittingRoom;
private:
	string m_BedRoom;
};
GoodGay2::GoodGay2()//类外写成员函数
{
	building2 = new Building2;
}
void GoodGay2::visit1()//类外写成员函数
{
	cout << "test03 visit1好基友正在访问" << building2->m_SittingRoom << endl;
	cout << "test03 visit1好基友正在访问" << building2->m_BedRoom << endl;
}
void GoodGay2::visit2()//类外写成员函数
{
	cout << "test03 visit2好基友正在访问" << building2->m_SittingRoom << endl;
	//cout << "好基友正在访问" << building2->m_BedRoom << endl;
}
Building2::Building2()//类外写成员函数
{
	this->m_SittingRoom = "客厅";
	this->m_BedRoom = "卧室";
}
void test03()
{
	GoodGay2 gg;
	gg.visit1();
	gg.visit2();
}

int main()
{
//全局函数做友元 2025.10.29
	//在程序里，有些私有属性 也想让类外特殊的一些函数或者类进行访问，就需要用到友元的技术
	//友元的目的就是让一个函数或者类访问另一个类中私有成员
	//友元的关键字为 friend
	//友元的三种实现
		//全局函数做友元
		//类做友元
		//成员函数做友元
	test01();

//友元类
	test02();

//成员函数做友元
	test03();

	system("pause");
	return 0;
}
*/