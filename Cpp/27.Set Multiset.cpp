#include<iostream>
using namespace std;
#include<string>
#include<set>
#include<algorithm>

/*
//构造函数和赋值
void printSet(set<int>s1)
{
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test01()
{
	set<int>s1;//set<T > st
	s1.insert(10);//插入数据只有 insert 方法
	s1.insert(30);
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);
	printSet(s1);
	set<int>s2(s1);//拷贝构造 set(const set& st)
	printSet(s2);
	set<int>s3;
	s3 = s2;//赋值 set& operator=(const set & st)
	printSet(s3);
}

//Set 大小和交换
void test02()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(70);
	s1.insert(50);
	s1.insert(40);
	s1.insert(90);
	printSet(s1);
	if (s1.empty())//empty()
	{
		cout << "s1为空" << endl;
	}
	else
	{
		cout << "s1不为空" << endl;
		cout << "s1的大小为： " << s1.size() << endl;//size()
	}
}
void test03()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	set<int>s2;
	s2.insert(100);
	s2.insert(300);
	s2.insert(200);
	s2.insert(400);
	cout << "交换前" << endl;
	printSet(s1);
	printSet(s2);
	cout << "交换后" << endl;
	s1.swap(s2);//swap(st)
	printSet(s1);
	printSet(s2);
}

//Set 插入和删除
void test04()
{
	set<int>s1;
	s1.insert(30);
	s1.insert(10);
	s1.insert(20);
	s1.insert(40);
	printSet(s1);
	s1.erase(s1.begin());//erase(pos)，删除排序后的第一个数
	printSet(s1);
	s1.erase(30);//erase(elem)
	printSet(s1);
	s1.erase(s1.begin(), s1.end());//erase(beg, end)
	printSet(s1);
	s1.insert(30);
	s1.insert(10);
	s1.insert(20);
	s1.insert(40);
	printSet(s1);
	s1.clear();//clear()
	printSet(s1);
}

//Set 查找和统计
void test05()
{
	set<int>s1;
	s1.insert(30);
	s1.insert(10);
	s1.insert(20);
	s1.insert(40);
	printSet(s1);
	set<int>::iterator pos = s1.find(30);//find(key)
	if (pos != s1.end())
	{
		cout << "找到了元素 ： " << *pos << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}
}
void test06()
{
	set<int>s1;
	s1.insert(30);
	s1.insert(10);
	s1.insert(20);
	s1.insert(40);
	s1.insert(30);
	printSet(s1);
	int num1 = s1.count(30);//count(key)，对于 Set 容器而言，统计结果只能是 1 或 0
	cout << "num1：" << num1 << endl;
	int num2 = s1.count(70);
	cout << "num2：" << num2 << endl;
}

//Set 和 Multiset 区别
void test07()
{
	set<int>s1;
	pair<set<int>::iterator, bool>  ret = s1.insert(10);//会返回 2 个数据，会返回插入位置和是否插入成功
	if (ret.second) 
	{
		cout << "第一次插入成功!" << endl;
	}
	else {
		cout << "第一次插入失败!" << endl;
	}
	ret = s1.insert(10);//不允许插入重复的值，因此插入失败
	if (ret.second)
	{
		cout << "第二次插入成功!" << endl;
	}
	else
	{
		cout << "第二次插入失败!" << endl;
	}
	multiset<int>ms;//允许插入重复的值
	ms.insert(10);
	ms.insert(10);//直接返回插入位置，不会返回是否插入成功，因为支持重复插入
	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//Pair 对组创建
void test08()
{
	pair<string, int>p("Tom", 20);//pair<type, type > p(value1, value2)
	cout << "姓名：" << p.first << " 年龄：" << p.second << endl;
	pair<string, int>p2 = make_pair("Jerry", 30);//pair<type, type > p = make_pair(value1, value2)
	cout << "姓名：" << p2.first << " 年龄：" << p2.second << endl;
}

//Set 内置类型指定排序规则
class MyCompare//重载()
{
public:
	bool operator()(int v1, int v2)
	const {return v1 > v2;}//C++ 11 新特性，需要在参数列表后加 const
};
void test09()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(50);
	s1.insert(30);
	printSet(s1);
	set<int, MyCompare>s2;
	s2.insert(10);
	s2.insert(40);
	s2.insert(20);
	s2.insert(50);
	s2.insert(30);
	for (set<int, MyCompare>:: iterator it = s2.begin() ; it != s2.end(); it++)
	{
		cout << *it << "";
	}
	cout << endl;
}

//Set 自定义数据类型指定排序规则
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
class comparePerson//重载()
{
public:
	bool operator()(const Person& p1, const Person& p2)
	const{return p1.m_Age > p2.m_Age;}
};
void test10()
{
	set<Person, comparePerson>s;//自定义的数据类型，都应该指定排序规则
	Person p1("刘备", 23);
	Person p2("关羽", 27);
	Person p3("张飞", 25);
	Person p4("赵云", 21);
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	for (set<Person, comparePerson>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "姓名：" << (*it).m_Name << " 年龄：" << (*it).m_Age << endl;
	}
	cout << endl;
}


int main()
{
//构造函数和赋值	
	//简介：所有元素都会在插入时自动被排序
	//本质：set / multiset属于关联式容器，底层结构是用二叉树实现
	//set和multiset区别：
		//set 不允许容器中有重复的元素
		//multiset 允许容器中有重复的元素
	//构造：
		//set<T > st;                        //默认构造函数
		//set(const set& st);                //拷贝构造函数
	//赋值：
		//set& operator=(const set & st);    //重载等号操作符
	test01();

//Set 大小和交换
	//函数原型：
		//size();        //返回容器中元素的数目
		//empty();       //判断容器是否为空
		//swap(st);      //交换两个集合容器
	test02();
	test03();

//Set 插入和删除
	//函数原型：
		//insert(elem);           //在容器中插入元素。
		//clear();                //清除所有元素
		//erase(pos);             //删除 pos 迭代器所指的元素，返回下一个元素的迭代器。
		//erase(beg, end);        //删除区间 [beg,end) 的所有元素 ，返回下一个元素的迭代器。
		//erase(elem);            //删除容器中值为 elem 的元素。
	test04();

//Set 查找和统计
	//函数原型：
		//find(key);               //查找 key 是否存在,若存在，返回该键的元素的迭代器；若不存在，返回 set.end();
		//count(key);              //统计 key 的元素个数
	test05();
	test06();

//Set 和 Multiset 区别
	//区别：
		//set 不可以插入重复数据，而 multiset 可以
		//set 插入数据的同时会返回插入结果，表示插入是否成功
		//multiset 不会检测数据，因此可以插入重复数据
	test07();

//Pair 对组创建
	//两种创建方式：
		//pair<type, type > p(value1, value2);
		//pair<type, type > p = make_pair(value1, value2);
	test08();

//Set 内置类型指定排序规则
	//利用仿函数，可以改变排序规则
	test09();

//Set 自定义数据类型指定排序规则
	test10();

	system("pause");
	return 0;
}
*/