#include<iostream>
#include<typeinfo>
#include<string>
#include<vector>
#include<deque>
#include<stack>
#include<queue>
using namespace std;
//2026.3.6

/*
//容器适配器
template<typename T, typename Container = deque<T>>
class Stack
{
public:
	void push(const T& val) { con.push_back(val); }
	void pop() { con.pop_back(); }
	T top() const { return con.back(); }
private:
	Container con;
};

int main()
{
//容器适配器
	//适配器底层没有自己的数据结构，它是另外一个容器的封装，它的方法全部由底层依赖的容器进行实现
	//没有实现自己的迭代器
	//采用容器适配器去实现 stack、queue 是为了避免重复造轮子，代码冗余，防止失去灵活性，无法适配不同场景，保持容器体系的一致性
	//stack：push 入栈、pop 出栈、top 查看栈顶元素、empty 判断栈空、size 返回元素个数
	stack<int> s1;
	for (int i = 0; i < 20; i++)
	{
		s1.push(rand() % 100 + 1);
	}
	cout << s1.size() << endl;
	while (!s1.empty())
	{
		cout << s1.top() << " ";
		s1.pop();
	}
	cout << endl;
	//queue：push 入队、pop 出队、front 查看对头元素、back 查看队尾元素、empty 判断队空、size 返回元素个数
	queue<int> que;
	for (int i = 0; i < 20; i++)
	{
		que.push(rand() % 100 + 1);
	}
	cout << que.size() << endl;
	while (!que.empty())
	{
		cout << que.front() << " ";
		que.pop();
	}
	cout << endl;
	//priority_queue：push 入队、pop 出队、top 查看队顶元素、empty 判断队空、size 返回元素个数
		//priority_queue 依赖 vector
		//优先级高的先出队，数字越大优先级越高
	priority_queue<int> pque;
	for (int i = 0; i < 20; i++)
	{
		pque.push(rand() % 100 + 1);
	}
	cout << pque.size() << endl;
	while (!pque.empty())
	{
		cout << pque.top() << " ";
		pque.pop();
	}
	cout << endl;

//stack 与 queue 依赖 deque 原因
	//1.因为 deque 初始内存使用效率高，若依赖 vector 会导致频繁扩容
	//2.queue 需要支持尾部插入，头部删除，依赖 vector 其出队效率低
	//3.vector 需要大片连续内存，而 deque 只需要分段内存，当存储大量数据时，deque 内存利用率更好
	
//priority_queue 依赖 vector 原因	
	//底层默认把数据组成一个大根堆结构，其需要在一个内存连续的数组上构建一个大根堆或小根堆，因为查找左右孩子依赖下标来实现
	
	system("pause");
	return 0;
}
*/