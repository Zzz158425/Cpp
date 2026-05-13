#include<iostream>
using namespace std;
#include<string>
#include<list>
#include<algorithm>

/*
//List 构造函数
void printList(const list<int>& L) 
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) 
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test01()
{
	list<int>L1;//默认构造 //list<T> lst
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);
	list<int>L2(L1.begin(), L1.end());//区间构造 //list(beg, end)
	printList(L2);
	list<int>L3(L2);//拷贝构造 //list(const list& lst)
	printList(L3);
	list<int>L4(10, 1000);//n 个 elem //list(n, elem)
	printList(L4);
}

//List 赋值和交换
void test02()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);
	list<int>L2;
	L2 = L1;//operator = //list& operator=(const list & lst)
	printList(L2);
	list<int>L3;
	L3.assign(L2.begin(), L2.end());//assign(beg, end)
	printList(L3);
	list<int>L4;
	L4.assign(10, 100);//assign(n, elem)
	printList(L4);
}
void test03()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);
	list<int>L2;
	L2.assign(10, 100);
	cout << "交换前： " << endl;
	printList(L1);
	printList(L2);
	L1.swap(L2);//swap(lst)
	cout << "交换后： " << endl;
	printList(L1);
	printList(L2);
}

//List 大小操作
void test04()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);
	if (L1.empty())//empty()
	{
		cout << "L1为空" << endl;
	}
	else
	{
		cout << "L1不为空" << endl;
		cout << "L1的大小为： " << L1.size() << endl;
	}
	L1.resize(10);//resize(num)，指定大小长于原容器，默认 0 填充新位置
	printList(L1);
	L1.resize(10,111);//resize(num)，指定大小长于原容器，默认值填充新位置
	L1.resize(2);//resize(num)，指定大小短于原容器，删除超过的部分
	printList(L1);
}

//List 插入和删除
void test05()
{
	list<int>L;
	L.push_back(10);//尾插 //push_back(elem)
	L.push_back(20);
	L.push_back(30);
	L.push_front(100);//头插 //push_front(elem)
	L.push_front(200);
	L.push_front(300);
	printList(L);
	L.pop_back();//尾删 //pop_back()
	printList(L);
	L.pop_front();//头删 //pop_front()
	printList(L);
	L.insert(L.begin(), 1000);//插入 insert(pos, elem)
	printList(L);
	list<int>::iterator it = L.begin();
	L.insert(++it, 999);//需要提供迭代器 it
	printList(L);
	it = L.begin();//删除 //erase(pos)
	L.erase(++it);
	printList(L);
	L.push_back(10000);//移除 //remove(elem)
	L.push_back(10000);
	L.push_back(10000);
	printList(L);
	L.remove(10000);
	printList(L);
	L.clear();//清空 //clear()
	printList(L);
}

//List 数据存取
void test06()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);
	//L1.at(0)，L1[0] 不支持 [] .at() 方式访问 list 容器中的数据，因为 list 本质是链表，不是用连续线性空间存储的数据，迭代器也不支持随机访问
	cout << "第一个元素为： " << L1.front() << endl;
	cout << "最后一个元素为： " << L1.back() << endl;
	list<int>::iterator it = L1.begin();//list 容器的迭代器是双向迭代器，不支持随机访问
	it++;
	it--;
	(it++)++;
	//it = it + 1;错误，不可以跳跃访问，即使是 + 1
}

//List 反转和排序
void test07()
{
	list<int>L1;
	L1.push_back(20);
	L1.push_back(10);
	L1.push_back(50);
	L1.push_back(40);
	L1.push_back(30);
	cout << "反转前：" << endl;
	printList(L1);
	L1.reverse();
	cout << "反转后：" << endl;
	printList(L1);
}
bool myCompare(int val1, int val2)
{
	return val1 > val2;
}
void test08()
{
	list<int>L1;
	L1.push_back(20);
	L1.push_back(10);
	L1.push_back(50);
	L1.push_back(40);
	L1.push_back(30);
	cout << "排序前：" << endl;
	printList(L1);
	//sort(L1.begin(), L1.end());所有不支持随机访问迭代器的容器，不可以用标准算法，不支持随机访问的迭代器的容器，内部会提供对于的一些算法
	L1.sort();//默认的排序规则 从小到大
	cout << "排序后（升序）：" << endl;
	printList(L1);
	L1.sort(myCompare);//降序方式
	cout << "排序后（降序）：" << endl;
	printList(L1);
}

//List 排序案例 2025.11.16
class Person 
{
public:
	Person(string name, int age, int height)
	{
		m_Name = name;
		m_Age = age;
		m_Height = height;
	}
	string m_Name;  //姓名
	int m_Age;      //年龄
	int m_Height;   //身高
};
bool ComparePerson(Person& p1, Person& p2)//制定排序规则
{
	if (p1.m_Age == p2.m_Age) 
	{
		return p1.m_Height > p2.m_Height;
	}
	else
	{
		return  p1.m_Age < p2.m_Age;
	}
}
void test09()
{
	list<Person> L;
	Person p1("刘备", 35, 175);
	Person p2("曹操", 45, 180);
	Person p3("孙权", 40, 170);
	Person p4("赵云", 25, 190);
	Person p5("张飞", 35, 160);
	Person p6("关羽", 35, 200);
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "姓名： " << it->m_Name << " 年龄： " << it->m_Age
			<< " 身高： " << it->m_Height << endl;
	}
	cout << "---------------------------------" << endl;
	L.sort(ComparePerson); //排序
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "姓名： " << it->m_Name << " 年龄： " << it->m_Age
			<< " 身高： " << it->m_Height << endl;
	}
}

int main()
{
//List 基本概念
	//功能：将数据进行链式存储
	//链表（List）是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针链接实现的
	//链表的组成：链表由一系列结点组成
	//结点的组成：一个是存储数据元素的数据域，另一个是存储下一个结点地址的指针域
	//STL 中的链表是一个双向循环链表，由于链表的存储方式并不是连续的内存空间，因此链表 List 中的迭代器只支持前移和后移，属于双向迭代器
	//List 的优点：
		//采用动态存储分配，不会造成内存浪费和溢出
		//链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素
	//List 的缺点：
		//链表灵活，但是空间（指针域）和时间（遍历）额外耗费较大
	//List 有一个重要的性质，插入操作和删除操作都不会造成原有 List 迭代器的失效，这在 Vector 是不成立的。
	//总结：STL 中 List 和 Vector 是两个最常被使用的容器，各有优缺点
	
//List 构造函数
	//函数原型：
		//list<T> lst;                     //list 采用采用模板类实现,对象的默认构造形式：
		//list(beg, end);                   //构造函数将 [beg, end) 区间中的元素拷贝给本身。
		//list(n, elem);                    //构造函数将 n 个 elem 拷贝给本身。
		//list(const list& lst);            //拷贝构造函数。
	test01();

//List 赋值和交换
	//函数原型：
		//assign(beg, end);                  //将 [beg, end) 区间中的数据拷贝赋值给本身。
		//assign(n, elem);                   //将 n 个 elem 拷贝赋值给本身。
		//list& operator=(const list & lst); //重载等号操作符
		//swap(lst);                         //将 lst 与本身的元素互换。
	test02();
	test03();

//List 大小操作
	//函数原型：
		//size();                  //返回容器中元素的个数
		//empty();                 //判断容器是否为空
		//resize(num);             //重新指定容器的长度为 num，若容器变长，则以默认值填充新位置，如果容器变短，则末尾超出容器长度的元素被删除
		//resize(num, elem);       //重新指定容器的长度为 num，若容器变长，则以 elem 值填充新位置，如果容器变短，则末尾超出容器长度的元素被删除
	test04();

//List 插入和删除
	//函数原型：
		//push_back(elem);       //在容器尾部加入一个元素
		//pop_back();            //删除容器中最后一个元素
		//push_front(elem);      //在容器开头插入一个元素
		//pop_front();           //从容器开头移除第一个元素
		//insert(pos, elem);     //在 pos 位置插 elem 元素的拷贝，返回新数据的位置
		//insert(pos, n, elem);  //在 pos 位置插入 n 个 elem 数据，无返回值
		//insert(pos, beg, end); //在 pos 位置插入 [beg,end) 区间的数据，无返回值
		//clear();               //移除容器的所有数据
		//erase(beg, end);       //删除 [beg,end) 区间的数据，返回下一个数据的位置
		//erase(pos);            //删除 pos 位置的数据，返回下一个数据的位置
		//remove(elem);          //删除容器中所有与 elem 值匹配的元素
	test05();

//List 数据存取
	//函数原型：
		//front();        //返回第一个元素
		//back();         //返回最后一个元素
	test06();

//List 反转和排序
	//函数原型：
		//reverse();   //反转链表
		//sort();      //链表排序
	test07();
	test08();

//List 排序案例 2025.11.16
	//案例描述：将 Person 自定义数据类型进行排序，Person 中属性有姓名、年龄、身高
	//排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序
	test09();

	system("pause");
	return 0;
}
*/
