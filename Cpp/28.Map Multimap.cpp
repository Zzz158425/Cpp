#include<iostream>
using namespace std;
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<ctime>

/*
//Map 构造和赋值 2025.11.17
void printMap(map<int, int>m)
{
	for (map<int, int>::iterator it = m.begin() ; it != m.end(); it++)
	{
		cout << "key = " << (*it).first << " value = " << it->second << endl;
	}
	cout << endl;
}
void test01()
{
	map<int, int>m;//map<T1, T2 > mp
	m.insert(pair<int, int>(1, 10));//插数
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	printMap(m);
	map<int, int>m2(m); //拷贝构造 //map(const map& mp)
	printMap(m2);
	map<int, int>m3;
	m3 = m2; //赋值 //map& operator=(const map & mp)
	printMap(m3);
}

//Map 大小和交换
void test02()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	if (m.empty())//empty()
	{
		cout << "m为空" << endl;
	}
	else
	{
		cout << "m不为空" << endl;
		cout << "m的大小为： " << m.size() << endl;//size()
	}
}
void test03()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	map<int, int>m2;
	m2.insert(pair<int, int>(4, 100));
	m2.insert(pair<int, int>(5, 200));
	m2.insert(pair<int, int>(6, 300));
	cout << "交换前" << endl;
	printMap(m);
	printMap(m2);
	cout << "交换后" << endl;
	m.swap(m2);//swap(st)
	printMap(m);
	printMap(m2);
}

//Map 插入和删除
void test04()
{
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));//第一种插入方式
	m.insert(make_pair(2, 20));//第二种插入方式
	m.insert(map<int, int>::value_type(3, 30));//第三种插入方式
	m[4] = 40;	//第四种插入方式，不建议，因为，若不存在会创建一个数，可以利用 key 访问 value
	printMap(m);
	m.erase(m.begin());	//删除 //erase(pos)
	printMap(m);
	m.erase(3);//erase(key)
	printMap(m);
	m.erase(m.begin(), m.end());//erase(beg, end)
	m.insert(pair<int, int>(1, 10));
	printMap(m);
	m.clear();//clear()
	printMap(m);
}

//Map 查找和统计
void test05()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	map<int, int>::iterator pos = m.find(3);//查找 //find(key)
	if (pos != m.end())
	{
		cout << "找到了元素 key = " << (*pos).first << " value = " << (*pos).second << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}
	int num = m.count(3);//统计 count(key)，map 不允许插入重复的值，只能返回 0 或 1
	cout << "num = " << num << endl;
}

//Map 内置类型指定排序规则
class myCompare
{
public:
	bool operator()(int v1, int v2)
	const {return v1 > v2;}//C++ 11 新特性，需要在参数列表后加 const
};
void test06()
{
	map<int, int, myCompare>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(5, 50));
	for (map<int, int, myCompare>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << (*it).first << " value = " << it->second << endl;
	}
}

//Map 自定义数据类型指定排序规则
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
	bool operator()(int v1, int v2)
		const {
		return v1 > v2;
	}
};
void test07()
{
	map<int, Person, comparePerson>m;//自定义的数据类型，都应该指定排序规则
	Person p1("刘备", 23);
	Person p2("关羽", 27);
	Person p3("张飞", 25);
	Person p4("赵云", 21);
	m.insert(make_pair(1, p1));
	m.insert(make_pair(2, p2));
	m.insert(make_pair(3, p3));
	m.insert(make_pair(4, p4));
	for (map<int, Person, comparePerson>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "ID：" << (*it).first << " 姓名：" << (*it).second.m_Name << " 年龄：" << (*it).second.m_Age << endl;
	}
	cout << endl;
}

//员工分组案例
#define CHEHUA 0
#define MEISHU 1
#define YANFA 2
class Worker
{
public:
	string m_Name;
	int m_Salary;
};
void createWorker(vector<Worker>& v)//创建员工
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_Name = "员工";
		worker.m_Name += nameSeed[i];
		worker.m_Salary = rand() % 10000 + 10000;//10000 ~ 19999
		v.push_back(worker);
	}
}
void setGroup(vector<Worker>& v, multimap<int, Worker>& m)//分组员工
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		int deptId = rand() % 3;//产生随机部门编号 0 ~ 3
		m.insert(make_pair(deptId, *it));//key 部门编号，value 具体员工
	}
}
void showWorkerByGroup(multimap<int, Worker>& m)//显示员工
{
	cout << "策划部门" << endl;
	multimap<int,Worker>::iterator pos = m.find(CHEHUA);//找到策划部门的位置
	int count = m.count(CHEHUA);//统计策划部门人数
	int index = 0;
	for (; pos != m.end() && index < count; pos++,index++)
	{
		cout << "姓名：" << pos->second.m_Name << " 工资：" << pos->second.m_Salary << endl;
	}
	cout << "美术部门" << endl;
	pos = m.find(MEISHU);//找到美术部门的位置
	count = m.count(MEISHU);//统计美术部门人数
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << " 工资：" << pos->second.m_Salary << endl;
	}
	cout << "研发部门" << endl;
	pos = m.find(YANFA);//找到研发部门的位置
	count = m.count(YANFA);//统计研发部门人数
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << " 工资：" << pos->second.m_Salary << endl;
	}
}

int main()
{
//Map 构造和赋值 2025.11.17
	//简介：
		//map 中所有元素都是 pair
		//pair 中第一个元素为 key（键值），起到索引作用，第二个元素为 value（实值）
		//所有元素都会根据元素的键值自动排序
	//本质：map / multimap属于关联式容器，底层结构是用二叉树实现
	//优点：可以根据 key 值快速找到 value 值
	//map 和 multimap 区别：
		//map 不允许容器中有重复 key 值元素
		//multimap 允许容器中有重复 key 值元素
	//函数原型：
		//构造：
			//map<T1, T2 > mp;                   //map默认构造函数: 
			//map(const map& mp);                //拷贝构造函数
		//赋值：
			//map& operator=(const map & mp);    //重载等号操作符	
	test01();

//Map 大小和交换
	//函数原型：
		//size();        //返回容器中元素的数目
		//empty();       //判断容器是否为空
		//swap(st);      //交换两个集合容器
	test02();
	test03();

//Map 插入和删除
	//函数原型：
		//insert(elem);          //在容器中插入元素。
		//clear();               //清除所有元素
		//erase(pos);            //删除 pos 迭代器所指的元素，返回下一个元素的迭代器。
		//erase(beg, end);       //删除区间 [beg,end) 的所有元素 ，返回下一个元素的迭代器。
		//erase(key);            //删除容器中值为 key 的元素。
	test04();

//Map 查找和统计
	//函数原型：
		//find(key);                  //查找 key 是否存在,若存在，返回该键的元素的迭代器；若不存在，返回 set.end();
		//count(key);                //统计 key 的元素个数，返回整型
	test05();

//Map 内置类型指定排序规则
	test06();

//Map 自定义数据类型指定排序规则
	test07();

//员工分组案例
	//案例描述
		//公司今天招聘了 10 个员工（ABCDEFGHIJ），10 名员工进入公司之后，需要指派员工在那个部门工作
		//员工信息有: 姓名  工资组成；部门分为：策划、美术、研发
		//随机给 10 名员工分配部门和工资
		//通过 multimap 进行信息的插入 key(部门编号) value(员工)
		//分部门显示员工信息
	//实现步骤
		//1. 创建 10 名员工，放到 vector 中
		//2. 遍历 vector 容器，取出每个员工，进行随机分组
		//3. 分组后，将员工部门编号作为 key，具体员工作为 value，放入到 multimap 容器中
		//4. 分部门显示员工信息
	srand((unsigned int)time(NULL));
	vector<Worker>vWorker;
	createWorker(vWorker);
	multimap<int, Worker>mWorker;
	setGroup(vWorker, mWorker);
	showWorkerByGroup(mWorker);

	system("pause");
	return 0;
}
*/