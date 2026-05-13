#include<iostream>
using namespace std;
#include<string>
#include<stack>
#include<queue>
#include<algorithm>

/*
//Stack 常用接口
void test01()
{
	stack<int>s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	while (!s.empty())
	{
		cout << "栈顶元素为： " << s.top() << endl;//输出栈顶元素
		s.pop();//弹出栈顶元素
	}
	cout << "栈的大小为：" << s.size() << endl;
}

//Queue 基本概念
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
void test02()
{
	queue<Person>q;
	Person p1("唐僧", 30);
	Person p2("孙悟空", 1000);
	Person p3("猪八戒", 900);
	Person p4("沙僧", 800);
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);
	cout << "队列大小为：" << q.size() << endl;
	while (!q.empty())
	{
		cout << "队头元素-- 姓名： " << q.front().m_Name
			<< " 年龄： " << q.front().m_Age << endl;//查看队头元素
		cout << "队尾元素-- 姓名： " << q.back().m_Name
			<< " 年龄： " << q.back().m_Age << endl;//查看队尾元素
		cout << endl;
		q.pop();//弹出队头元素
	}
	cout << "队列大小为：" << q.size() << endl;
}

int main()
{
//Stack 基本概念 2025.11.15
	//stack是一种先进后出(First In Last Out, FILO)的数据结构，它只有一个出口
	//栈中只有顶端的元素才可以被外界使用，因此栈不允许有遍历行为
		//栈中进入数据称为---入栈 push
		//栈中弹出数据称为---出栈 pop

//Stack 常用接口
	//构造函数：
		//stack<T > stk;                      //stack 采用模板类实现，stack 对象的默认构造形式
		//stack(const stack& stk);            //拷贝构造函数
	//赋值操作：
		//stack& operator=(const stack & stk);           //重载等号操作符
	//数据存取：
		//push(elem);           //向栈顶添加元素
		//pop();                //从栈顶移除第一个元素
		//top();                //返回栈顶元素
	//大小操作：
		//empty();            //判断堆栈是否为空
		//size();             //返回栈的大小
	test01();

//Queue 基本概念
	//Queue是一种先进先出(First In First Out, FIFO)的数据结构，它有两个出口
	//队列容器允许从一端新增元素，从另一端移除元素，队列中只有队头和队尾才可以被外界使用，因此队列不允许有遍历行为
		//队列中进数据称为---入队 push
		//队列中出数据称为---出队 pop

//Queue 常用接口
	//构造函数：
		//queue<T > que;                       //queue采用模板类实现，queue对象的默认构造形式
		//queue(const queue & que);            //拷贝构造函数
	//赋值操作：
		//queue& operator=(const queue & que);           //重载等号操作符
	//数据存取：
		//push(elem);                             //往队尾添加元素
		//pop();                                  //从队头移除第一个元素
		//back();                                 //返回最后一个元素
		//front();                                //返回第一个元素
	//大小操作：
		//empty();             //判断堆栈是否为空
		//size();              //返回栈的大小
	test02();

	system("pause");
	return 0;
}
*/