#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>

/*
//容器算法迭代器初识
void myPrint(int val)
{
	cout << val << endl;
}
void test01()
{
	vector<int> v1;//创建了一个 vector 的容器，数组
	v1.push_back(10);//向容器中放数据
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	vector<int>::iterator itBegin = v1.begin();//起始迭代器，指向容器中第一个元素
	vector<int>::iterator itEnd = v1.end();//结束迭代器，指向容器中最后一个元素的下一个位置
	while (itBegin != itEnd)//第一种遍历方式
	{
		cout << *itBegin << endl;
		itBegin++;
	}
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)//第二种遍历方式
	{
		cout << *it << endl;
	}
	for_each(v1.begin(), v1.end(), myPrint);//第三种遍历方式，利用 STL 提供的遍历算法
}

//Vector存放自定义数据类型
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
public:
	string m_Name;
	int m_Age;
};
void test02()
{
	vector<Person>v2;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);
	v2.push_back(p1);
	v2.push_back(p2);
	v2.push_back(p3);
	v2.push_back(p4);
	v2.push_back(p5);
	for (vector<Person>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << "Name:" << (*it).m_Name << " Age:" << (*it).m_Age << endl;//it 可当做指针，可以通关 -> 访问：it->m_Name，(*it)解引用后为 Person 数据类型
	}
}
void test03()
{
	vector<Person*>v3;
	Person p1("aaa", 11);
	Person p2("bbb", 22);
	Person p3("ccc", 33);
	Person p4("ddd", 44);
	Person p5("eee", 55);
	v3.push_back(&p1);
	v3.push_back(&p2);
	v3.push_back(&p3);
	v3.push_back(&p4);
	v3.push_back(&p5);
	for (vector<Person*>::iterator it = v3.begin(); it != v3.end(); it++)
	{
		cout << "Name:" << (*(*it)).m_Name << " Age:" << (*(*it)).m_Age << endl;//*it 为Person* 的指针，可以通关 -> 访问：(*it)->m_Name
	}
}

//Vector容器嵌套容器
void test04()
{
	vector<vector<int>>v4;
	vector<int>vv1;//创建小容器
	vector<int>vv2;
	vector<int>vv3;
	vector<int>vv4;
	for (int i = 0; i < 4; i++)//向小容器中添加数据
	{
		vv1.push_back(i + 1);
		vv2.push_back(i + 2);
		vv3.push_back(i + 3);
		vv4.push_back(i + 4);
	}
	v4.push_back(vv1);//把小容器插入到大容器中
	v4.push_back(vv2);
	v4.push_back(vv3);
	v4.push_back(vv4);
	for (vector<vector<int>>::iterator it = v4.begin(); it != v4.end(); it++)//通过大容器，把所有数据遍历一遍
	{
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)//(*it) --- 容器 vector<int>
		{
			cout << *vit << " ";
		}
		cout << endl;
	}
}

int main()
{
//STL初识 2025.11.11
	//STL的诞生
		//长久以来，软件界一直希望建立一种可重复利用的东西
		//C++ 的面向对象和泛型编程思想，目的就是复用性的提升
		//大多情况下，数据结构和算法都未能有一套标准,导致被迫从事大量重复工作
		//为了建立数据结构和算法的一套标准, 诞生了STL
	//STL基本概念
		//STL(Standard Template Library，标准模板库)
		//STL 从广义上分为：容器(container)，算法(algorithm)，迭代器(iterator)
		//容器和算法之间通过迭代器进行无缝连接。
		//STL 几乎所有的代码都采用了模板类或者模板函数
	//STL六大组件：STL大体分为六大组件，分别是:容器、算法、迭代器、仿函数、适配器（配接器）、空间配置器
		//1. 容器：各种数据结构，如 vector、list、deque、set、map 等,用来存放数据。
		//2. 算法：各种常用的算法，如 sort、find、copy、for_each 等
		//3. 迭代器：扮演了容器与算法之间的胶合剂。
		//4. 仿函数：行为类似函数，可作为算法的某种策略。
		//5. 适配器：一种用来修饰容器或者仿函数或迭代器接口的东西。
		//6. 空间配置器：负责空间的配置与管理。
	//STL中容器、算法、迭代器
		//容器：置物之所也，STL 容器就是将运用最广泛的一些数据结构实现出来
			//常用的数据结构：数组, 链表, 树, 栈, 队列, 集合, 映射表 等
			//这些容器分为序列式容器和关联式容器两种:
				//序列式容器:强调值的排序，序列式容器中的每个元素均有固定的位置。
				//关联式容器: 二叉树结构，各元素之间没有严格的物理上的顺序关系
		//算法：问题之解法也
			//有限的步骤，解决逻辑或数学上的问题，这一门学科我们叫做算法(Algorithms)
			//算法分为:质变算法和非质变算法。
				//质变算法：是指运算过程中会更改区间内的元素的内容。例如拷贝，替换，删除等等
				//非质变算法：是指运算过程中不会更改区间内的元素内容，例如查找、计数、遍历、寻找极值等等
		//迭代器：容器和算法之间粘合剂
			//提供一种方法，使之能够依序寻访某个容器所含的各个元素，而又无需暴露该容器的内部表示方式。
			//每个容器都有自己专属的迭代器，迭代器使用非常类似于指针，初学阶段我们可以先理解迭代器为指针
			//常用的容器中迭代器种类为双向迭代器，和随机访问迭代器
				//双向迭代器：读写操作，并能向前和向后操作，读写，支持++、--，
				//随机访问迭代器：读写操作，可以以跳跃的方式访问任意数据，功能最强的迭代器，读写，支持++、--、[n]、 - n、<、 <= 、>、 >=
//容器算法迭代器初识
	//STL中最常用的容器为 Vector，可以理解为数组
	test01();

//Vector存放自定义数据类型
	test02();
	test03();

//Vector容器嵌套容器
	test04();

	system("pause");
	return 0;
}
*/