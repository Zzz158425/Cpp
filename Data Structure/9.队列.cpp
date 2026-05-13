#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

/*
//环形队列
class Queue
{
public:
	Queue(int size = 10) : cap_(size), front_(0), rear_(0), size_(0)
	{
		pQue_ = new int[cap_];
	}
	~Queue()
	{
		delete[]pQue_;
		pQue_ = nullptr;
	}
public:
	//入队 O(1)
	void push(int val)
	{
		if ((rear_ + 1) % cap_ == front_)
		{
			expand(2 * cap_);
		}
		pQue_[rear_] = val;//入队
		rear_ = (rear_ + 1) % cap_;//rear 往后移动
		size_++;
	}
	//出队 O(1)
	void pop()
	{
		if (rear_ == front_)
		{
			throw "Queue is empty";
		}
		front_ = (front_ + 1) % cap_;//出队
		size_--;
	}
	//获取队头元素
	int front() const
	{
		if (rear_ == front_)
		{
			throw "Queue is empty";
		}
		return pQue_[front_];
	}
	//获取队尾元素
	int back() const
	{
		if (rear_ == front_)
		{
			throw "Queue is empty";
		}

		return pQue_[(rear_ - 1 + cap_) % cap_];//rear 前一个位置才有元素，防止 rear 在 0 处进行 -1 等于负数
	}
	//判断队空
	bool empty() const
	{
		return front_ == rear_;
	}
	//统计队内元素个数 O(1)
	int size() const
	{
		return size_;
		//遍历队内元素 O(n)
		//int size = 0;
		//for (int i = front_; i != rear_; i = (i + 1) % cap_)
		//{
		//	size++;
		//}
		//return size;
	}
private:
	//扩容接口
	void expand(int size)
	{
		int* p = new int[size];
		int i = 0;//遍历新队列
		int j = front_;//遍历老队列
		//将老队列内容移动到新队列
		for (; j != rear_; i++, j = (j + 1) % cap_)
		{
			p[i] = pQue_[j];
		}
		delete[]pQue_;
		pQue_ = p;
		cap_ = size;
		front_ = 0;
		rear_ = i;
	}
private:
	int* pQue_;
	int cap_;//空间容量
	int front_;//队头
	int rear_;//队尾
	int size_;//队列元素个数
};

//链式队列
class LinkQueue
{
public:
	LinkQueue()
	{
		head_ = new Node();
		head_->next_ = head_;
		head_->pre_ = head_;
		size_ = 0;
	}
	~LinkQueue()
	{
		Node* p = head_->next_;
		while (p != head_)
		{
			head_->next_ = p->next_;
			p->next_->pre_ = head_;
			delete p;
			p = head_->next_;
		}
		delete head_;
		head_ = nullptr;
	}
public:
	//入队 O(1)
	void push(int val)
	{
		Node* node = new Node(val);
		//尾插入队
		node->next_ = head_;
		node->pre_ = head_->pre_;
		head_->pre_->next_ = node;
		head_->pre_ = node;
		size_++;
	}
	//出队 O(1)
	void pop()
	{
		//删除第一个节点出队
		Node* p = head_->next_;
		head_->next_ = p->next_;
		p->next_->pre_ = head_;
		delete p;
		size_--;
	}
	//获取队头元素
	int front() const
	{
		if (head_->next_ = head_)
		{
			throw "Queue is empty";
		}
		return head_->next_->data_;
	}
	//获取队尾元素
	int back() const
	{
		if (head_->next_ = head_)
		{
			throw "Queue is empty";
		}
		return head_->pre_->data_;
	}
	//判断队空
	bool empty() const
	{
		return head_->next_ = head_;
	}
	//统计队内元素个数 O(1)
	int size() const
	{
		return size_;
	}
private:
	struct Node
	{
		Node(int data = 0) 
			: data_(data)
			, pre_(nullptr)
			, next_(nullptr)
		{}
		int data_;
		Node* pre_;
		Node* next_;
	};
	Node* head_;
	int size_;
};

//两个栈实现一个队列 2026.2.4
class MyQueue
{
public:
	MyQueue(){}
	//入队
	void push(int x)
	{
		s1.push(x);
	}
	//出队
	int pop()
	{
		if (s2.empty())
		{
			while (!s1.empty())
			{
				//将 s1 中元素倒入 s2 中
				s2.push(s1.top());
				s1.pop();
			}
		}
		int val = s2.top();
		s2.pop();
		return val;
	}
	//获取队头元素
	int peek()
	{
		if (s2.empty())
		{
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
		return s2.top();
	}
	//判断队空
	bool empty()
	{
		return s1.empty() && s2.empty();
	}
private:
	stack<int> s1;
	stack<int> s2;
};

//两个队列实现一个栈
class MyStack
{
public:
	MyStack()
	{
		q1 = new queue<int>;
		q2 = new queue<int>;
	}
	~MyStack()
	{
		delete q1;
		delete q2;
		q1 = nullptr;
		q2 = nullptr;
	}
	//入栈
	void push(int x)
	{
		q1->push(x);
		//将 q2 中的元素倒到 q1
		while (!q2->empty())
		{
			q1->push(q2->front());
			q2->pop();
		}
		//交换指针 q1 与 q2 指向 
		queue<int>* q = q1;
		q1 = q2;
		q2 = q;
	}
	//出栈
	int pop()
	{
		int val = q2->front();
		q2->pop();
		return val;
	}
	//获取栈顶元素
	int top()
	{
		return q2->front();
	}
	//判断栈空
	bool empty()
	{
		return q2->empty();
	}
private:
	queue<int>* q1;//始终指向空队列
	queue<int>* q2;//始终指向不为空队列
};

int main()
{
//队列 2026.2.3
	//特点：先进先出、后进后出，队尾进，队头出
	//first：队头
	//rear：队尾

//环形队列
	//依赖数组实现，但必须实现环形：0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 0
	//为了实现环形，rear = (rear + 1) % length，first = (first + 1) % length，length：数组长度
	//为了区分队列满/无元素：first = rear，队列满时会留下最后一个位置不填入数据，防止 first = rear 无法区分满/无元素
	//队列空：first = rear，队列满：(rear + 1) % length == first
	int arr[] = { 12,4,56,7,89,31,53,75 };
	Queue que_Queue;
	for (int v : arr)
	{
		que_Queue.push(v);
	}
	cout << que_Queue.front() << endl;
	cout << que_Queue.back() << endl;
	que_Queue.push(100);
	que_Queue.push(200);
	que_Queue.push(300);
	cout << que_Queue.front() << endl;
	cout << que_Queue.back() << endl;
	while (!que_Queue.empty())
	{
		cout << que_Queue.front() << " " << que_Queue.back() << endl;
		que_Queue.pop();
	}

//链式队列
	//依赖双向循环链表实现
	Queue que_LinkQueue;
	for (int v : arr)
	{
		que_LinkQueue.push(v);
	}
	cout << que_LinkQueue.front() << endl;
	cout << que_LinkQueue.back() << endl;
	que_LinkQueue.push(100);
	que_LinkQueue.push(200);
	que_LinkQueue.push(300);
	cout << que_LinkQueue.front() << endl;
	cout << que_LinkQueue.back() << endl;
	while (!que_LinkQueue.empty())
	{
		cout << que_LinkQueue.front() << " " << que_LinkQueue.back() << " " << que_LinkQueue.size() << endl;
		que_LinkQueue.pop();
	}

//两个栈实现一个队列 2026.2.4
	//描述：使用两个栈实现先入先出队列，队列应当支持一般队列支持的所有操作：push、pop、empty、peek(返回队列开头元素)，实现均摊复杂度为 O(1)：n 次操作可以允许某一次操作的时间复杂度为 O(n)
	//方法：先放入元素，如果没有其他操作，入队的元素都 push 到 s1 中，当做 pop 与 peek 操作，都从 s2 的栈顶直接操作，如果 s2 为空，把 s1 里面的元素全部倒过来。
	MyQueue que_MyQueue;
	for (int v : arr)
	{
		que_MyQueue.push(v);
	}
	cout << que_MyQueue.peek() << endl;
	que_MyQueue.push(100);
	cout << que_MyQueue.peek() << endl;
	while (!que_MyQueue.empty())
	{
		cout << que_MyQueue.peek() << endl;
		que_MyQueue.pop();
	}

//两个队列实现一个栈
	//描述：使用两个队列实现后入先出栈，栈应当支持一般栈支持的所有操作：push、pop、empty、top
	//方法：单队列实现：入队所有 X 个元素，再依次出队 X - 1 个元素再入队；双队列实现：先入队一个元素到 q1，后入队的元素入队到 q2 同时把 q1 元素依次出队并入队到 q2，以此往复，改进：方法与同法二，创建 2 个指针，使第一个指针指向始终为空的队列，剩下一个指针始终指向不为空的队列
	cout << "-----" << endl;
	MyStack s_MyStack;
	for (int v : arr)
	{
		s_MyStack.push(v);
	}
	while (!s_MyStack.empty())
	{
		cout << s_MyStack.top() << " ";
		s_MyStack.pop();
	}
	cout << endl;

	system("pause");
	return 0;
}
*/