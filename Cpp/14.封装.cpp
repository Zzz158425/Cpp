#include<iostream>
using namespace std;
#include<string>

/*
//属性和行为作为整体
const double PI = 3.14;
class Circle//class 表示一个类，类后面紧跟类名称
{
public://访问权限-公共权限
	//类中的属性和行为统一称为成员
	int m_r;//属性/成员属性/成员变量
	double calculateZC()//行为/成员函数/成员方法
	{
		return 2 * PI * m_r;
	}
};

//设计学生类练习
class Student
{
public:
	string m_name;
	int m_id;
	void setName(string name)
	{
		m_name = name;
	}
	void setID(int id)
	{
		m_id = id;
	}
	void showStudent()
	{
		cout << "name:" << m_name << " ID:" << m_id << endl;
	}
};

//访问权限
class Person
{
public://访问权限-公共权限
	string m_Name;

protected://访问权限-保护权限
	string m_Car;

private://访问权限-私有权限
	int m_Password;

public:
	void func()
	{
		m_Name = "张三";
		m_Car = "拖拉机";
		m_Password = 123456;
	}
};

//class 与 struct 区别
class C1
{
	int  m_A; //默认是私有权限
};
struct C2
{
	int m_A;  //默认是公共权限
};

//成员属性设置为私有
class Person1
{
public:
	void setName(string name)
	{
		m_Name = name;
	}
	string getName()
	{
		return m_Name;
	}
	int getAge()
	{
		return m_Age;
	}
	void setAge(int age)
	{
		if (age < 0 || age >150)
		{
			cout << "年龄 " << age << " 输入有误，赋值失败" << endl;
			return;
		}
		m_Age = age;
	}
	void setIdol(string Idol)
	{
		m_Idol = Idol;
	}
private:
	string m_Name; //可读可写  姓名
	int m_Age = 18; //只读  年龄
	string m_Idol; //只写  偶像
};

//立方体类练习
class Cube
{
public:
	void setL(int l)//设置长
	{
		m_L = l;
	}
	int getL()//获取长
	{
		return m_L;
	}
	void setW(int w)//设置宽
	{
		m_W = w;
	}
	int getW()//获取宽
	{
		return m_W;
	}
	void setH(int h)//设置高
	{
		m_H = h;
	}
	int getH()//获取高
	{
		return m_H;
	}
	int calculatesS()//获取面积
	{
		return 2 * m_L * m_W + 2 * m_H * m_W + 2 * m_L * m_H;
	}
	int calculatesV()//获取体积
	{
		return m_L * m_W * m_H;
	}
	bool isSameByClass(Cube &cu2)//成员函数判断两立方体是否相等
	{
		if (m_L == cu2.getL() && m_W == cu2.getW() && m_H == cu2.getH())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	int m_H;
	int m_L;
	int m_W;
};
bool isSame(Cube &cu1, Cube &cu2)//全局函数判断两立方体是否相等
{
	if (cu1.getL() == cu2.getL() && cu1.getW() == cu2.getW() && cu1.getH() == cu2.getH())
	{
		return true;
	}
	else
	{
		return false;
	}
}

//点和圆位置关系练习
#include "封装-点.h"//可以将类拆分到不同文件中
#include "封装-圆.h"
//class Point//创建点
//{
//public:
//	void setX(int x)//写 X
//	{
//		m_X = x;
//	}
//	int getX()//读 X
//	{
//		return m_X;
//	}
//	void setY(int y)//写 Y
//	{
//		m_Y = y;
//	}
//	int getY()//读 Y
//	{
//		return m_Y;
//	}
//private:
//	int m_Y;
//	int m_X;
//};
//class Circle1//创建圆
//{
//public:
//	void setR(int r)//写 R
//	{
//		m_R = r;
//	}
//	int getR()//读 R
//	{
//		return m_R;
//	}
//	void setCenter(Point Center)//写圆心
//	{
//		m_Center = Center;
//	}
//	Point getCenter()//读圆心
//	{
//		return m_Center;
//	}
//private:
//	int m_R;
//	Point m_Center;//在类中可以让另一个类，作为本来中的成员
//};
void isInCircle(Circle1 &c, Point &p)
{
	int distance =
		(c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
		(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
	int rDistance = c.getR() * c.getR();
	if (distance == rDistance)
	{
		cout << "点在圆上" << endl;
	}
	else if (distance > rDistance)
	{
		cout << "点在圆外" << endl;
	}
	else
	{
		cout << "点在圆内" << endl;
	}

}

int main()
{
//属性和行为作为整体
	//C++ 面向对象的三大特性为：封装、继承、多态
	//C++ 认为万事万物都皆为对象，对象上有其属性和行为
	//具有相同性质的对象，我们可以抽象称为类，人属于人类，车属于车类
	//封装是 C++ 面向对象三大特性之一
	//封装的意义：
		//将属性和行为作为一个整体，表现生活中的事物
		//将属性和行为加以权限控制
		//在设计类的时候，属性和行为写在一起，表现事物
	//语法：class 类名{ 访问权限： 属性 / 行为 };
	//实例化：通过一个类创建一个对象的过程
	Circle c;//创建圆类 创建具体的圆（对象）
	c.m_r = 10;//给圆对象的属性进行赋值
	cout << "圆的周长为：" << c.calculateZC() << endl;

//设计学生类练习
	Student stu;
	stu.setName("德玛西亚");
	stu.setID(250);
	stu.showStudent();

//访问权限
	//类在设计时，可以把属性和行为放在不同的权限下，加以控制
		//访问权限有三种：
			//public     公共权限，类内可以访问，类外可以访问
			//protected  保护权限，类内可以访问，类外不可以访问，子类可以访问父类中保护的内容
			//private    私有权限，类内可以访问，类外不可以访问，子类不可以访问父类中保护的内容
	Person p1;
	p1.m_Name = "李四";
	//p1.m_Car = "奔驰";保护权限，类外不能访问
	//p.m_Password = 123; //私有权限，类外访问不到

//class 与 struct 区别
	//在 C++ 中 struct 和 class 唯一的区别就在于默认的访问权限不同，struct 默认权限为公共，class 默认权限为私有
	C1 c1;
	//c1.m_A = 100;私有权限，类外访问不到
	C2 c2;
	c2.m_A = 100; //公共权限，类外可以访问

//成员属性设置为私有
	//优点1：将所有成员属性设置为私有，可以自己控制读写权限
	//优点2：对于写权限，我们可以检测数据的有效性
	Person1 p2;
	p2.setName("张三");//写姓名
	cout << "姓名： " << p2.getName() << endl;//读姓名
	//p2.setAge(50);写年龄无效
	//p2.m_Age;私有化无效
	cout << "年龄： " << p2.getAge() << endl;//读年龄
	p2.setIdol("苍井");//写偶像
	//cout << "偶像： " << p.m_Lover << endl;只写属性，不可以读取
	p2.setAge(160);

//立方体类练习
	Cube cu1;
	cu1.setL(10);
	cu1.setW(10);
	cu1.setH(10);
	cout << "立方体面积为：" << cu1.calculatesS()<< endl;
	cout << "立方体体积为：" << cu1.calculatesV() << endl;
	Cube cu2;
	cu1.setL(10);
	cu1.setW(10);
	cu1.setH(10);
	bool ret = isSame(cu1, cu2);
	if (ret)
	{
		cout << "cu1和cu2相等的" << endl;
	}
	else
	{
		cout << "cu1和cu2不相等的" << endl;
	}
	ret = cu1.isSameByClass(cu2);
	if (ret)
	{
		cout << "cu1和cu2是相等的" << endl;
	}
	else
	{
		cout << "cu1和cu2不相等的" << endl;
	}

//点和圆位置关系练习
	Circle1 cc;//创建圆
	cc.setR(10);
	Point center;
	center.setX(10);//圆心为（10,0）
	center.setY(0);
	cc.setCenter(center);
	Point p;//创建点
	p.setX(10);
	p.setY(10);
	isInCircle(cc, p);


	system("pause");
	return 0;
}
*/