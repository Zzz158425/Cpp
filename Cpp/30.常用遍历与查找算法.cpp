#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>
#include<functional>

/*
//常用遍历算法 for_each()
void print01(int val)
{
	cout << val << " ";
}
class print02
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(),v.end(), print01);
	cout << endl;
	for_each(v.begin(), v.end(), print02());
	cout << endl;
}

//常用遍历算法 transform
class Transform
{
public:
	int operator()(int v)
	{
		return v + 100;
	}
};
void test02()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>vTarget;//目标容器
	vTarget.resize(v.size());//需要提前开辟空间
	transform(v.begin(), v.end(), vTarget.begin(), Transform());
	for_each(vTarget.begin(), vTarget.end(), print02());
}

//常用查找算法 find
void test03()//查找内置数据类型
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator it = find(v.begin(), v.end(), 11);
	if (it != v.end())
	{
		cout << "找到了，这个数为：" << * it << endl;
	}
	else
	{
		cout << "没有找到" << endl;
	}
}
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	bool operator==(const Person& p)//该算法底层为 if (*_First == _Val) {break;}，需要重载 == 让 find 知道如何对比 person 数据类型
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
	string m_Name;
	int m_Age;
};
void test04()//查找自定义数据类型
{
	vector<Person>v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	Person pp("bbb", 20);
	vector<Person>::iterator it = find(v.begin(), v.end(), pp);//找与 pp 一样的
	if (it == v.end())
	{
		cout << "没有找到!" << endl;
	}
	else
	{
		cout << "找到姓名:" << it->m_Name << " 年龄: " << it->m_Age << endl;
	}
}

//常用查找算法 find_if
class Greater
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};
void test05()//查找内置数据类型
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator it = find_if(v.begin(), v.end(), Greater());
	if (it == v.end()) 
	{
		cout << "没有找到!" << endl;
	}
	else {
		cout << "找到大于5的数字:" << *it << endl;
	}
}
class Person1
{
public:
	Person1(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
class Greater20
{
public:
	bool operator()(Person1& p)
	{
		return p.m_Age > 20;
	}
};
void test06()//查找自定义数据类型
{
	vector<Person1>v;
	Person1 p1("aaa", 10);
	Person1 p2("bbb", 20);
	Person1 p3("ccc", 30);
	Person1 p4("ddd", 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	vector<Person1>::iterator it = find_if(v.begin(), v.end(), Greater20());
	if (it == v.end())
	{
		cout << "没有找到!" << endl;
	}
	else
	{
		cout << "找到姓名:" << it->m_Name << " 年龄: " << it->m_Age << endl;
	}
}

//常用查找算法 adjacent_find
void test07()
{
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(5);
	v.push_back(2);
	v.push_back(4);
	v.push_back(4);
	v.push_back(3);
	vector<int>::iterator pos = adjacent_find(v.begin(),v.end());
	if (pos == v.end()) 
	{
		cout << "找不到相邻重复元素!" << endl;
	}
	else 
	{
		cout << "找到相邻重复元素为:" << *pos << endl;
	}
}

//常用查找算法 binary_search
void test08()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	bool ret = binary_search(v.begin(), v.end(), 9);
	if (ret)
	{
		cout << "找到了元素" << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}

//常用查找算法 count
void test09()//查找内置数据类型
{
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);
	int num = count(v.begin(), v.end(), 4);
	cout << "4 的个数为： " << num << endl;
}
class Person2
{
public:
	Person2(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	bool operator==(const Person2& p)
	{
		if (p.m_Age == this->m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	string m_Name;
	int m_Age;
};
void test10()//查找自定义数据类型
{
	vector<Person2> v;
	Person2 p1("刘备", 35);
	Person2 p2("关羽", 35);
	Person2 p3("张飞", 35);
	Person2 p4("赵云", 30);
	Person2 p5("曹操", 25);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	Person2 p("诸葛亮", 35);
	int num = count(v.begin(), v.end(), p);
	cout << "num = " << num << endl;
}

//常用查找算法 count_if
class Greater4
{
public:
	bool operator()(int val)
	{
		return val >= 4;
	}
};
void test11()//查找内置数据类型
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);
	int num = count_if(v.begin(), v.end(), Greater4());
	cout << "大于 4 的个数为： " << num << endl;
}
class Person3
{
public:
	Person3(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};
class AgeGreater20
{
public:
	bool operator()(const Person3& p)
	{
		return p.m_Age > 20;
	}
};
void test12()//查找自定义数据类型
{
	vector<Person3> v;
	Person3 p1("刘备", 35);
	Person3 p2("关羽", 35);
	Person3 p3("张飞", 35);
	Person3 p4("赵云", 30);
	Person3 p5("曹操", 25);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	int num = count_if(v.begin(), v.end(), AgeGreater20());
	cout << "大于 20 岁的个数：" << num << endl;
}

int main()
{
//常用遍历算法 for_each() 2025.11.20
	//概述:
		//算法主要是由头文件 <algorithm> <functional> <numeric> 组成
		//<algorithm> 是所有 STL 头文件中最大的一个，范围涉及到比较、交换、查找、遍历操作、复制、修改等
		//<numeric> 体积很小，只包括几个在序列上面进行简单数学运算的模板函数
		//<functional> 定义了一些模板类, 用以声明函数对象
	//算法简介：
		//for_each     //遍历容器
		//transform    //搬运容器到另一个容器中
	//函数原型：
		//for_each(iterator beg, iterator end, _func);
			//beg 开始迭代器，end 结束迭代器，_func 函数或者函数对象
	//总结：for_each 在实际开发中是最常用遍历算法，需要熟练掌握
	test01();

//常用遍历算法 transform
	//功能描述：搬运容器到另一个容器中
	//函数原型：
		//transform(iterator beg1, iterator end1, iterator beg2, _func);
			//beg1 源容器开始迭代器，end1 源容器结束迭代器，beg2 目标容器开始迭代器，_func 函数或者函数对象
	test02();

//常用查找算法 find
	//算法简介：
		//find             //查找元素
		//find_if          //按条件查找元素
		//adjacent_find    //查找相邻重复元素
		//binary_search    //二分查找法
		//count            //统计元素个数
		//count_if         //按条件统计元素个数
	//函数原型：
		//find(iterator beg, iterator end, value);
		//按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置 end()，beg 开始迭代器，end 结束迭代器，value 查找的元素
	test03();
	test04();

//常用查找算法 find_if
	//函数原型：
		//find_if(iterator beg, iterator end, _Pred);
		//按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置，beg 开始迭代器，end 结束迭代器，_Pred 函数或者谓词（返回bool类型的仿函数）
	test05();
	test06();

//常用查找算法 adjacent_find
	//功能描述：查找相邻重复元素
	//函数原型：
		//adjacent_find(iterator beg, iterator end);
		//查找相邻重复元素,返回相邻元素的第一个位置的迭代器，beg 开始迭代器，end 结束迭代器
	test07();

//常用查找算法 binary_search
	//功能描述：查找指定元素是否存在
	//函数原型：
		//bool binary_search(iterator beg, iterator end, value);
		//查找指定的元素，查到返回 true，否则 false，beg 开始迭代器，end 结束迭代器，value 查找的元素
	//注意: 在无序序列中不可用，无需序列结果未知
	test08();

//常用查找算法 count
	//功能描述：统计元素个数
	//函数原型：
		//count(iterator beg, iterator end, value);
		//统计元素出现次数，beg 开始迭代器，end 结束迭代器，value 统计的元素
	test09();
	test10();

//常用查找算法 count_if
	//功能描述：按条件统计元素个数
	//函数原型：
		//count_if(iterator beg, iterator end, _Pred);
		//按条件统计元素出现次数，beg 开始迭代器，end 结束迭代器，_Pred 谓词
	test11();
	test12();

	system("pause");
	return 0;
}
*/
