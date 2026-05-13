#include<iostream>
#include<typeinfo>
using namespace std;

/*
//案例1：string 类型
class String
{
public:
	//普通构造函数
	String(const char* str = nullptr)
	{
		if (str != nullptr)
		{
			m_data = new char[strlen(str) + 1];
			strcpy(this->m_data, str);
		}
		else//防止后续函数总是会判断 m_data 是否为空，所以当传进来的字符串为空，不给底层字符串指针置空方便后续操作
		{
			m_data = new char[1];//存 '\0'
			*m_data = '\0';

		}
	}
	//拷贝构造函数
	String(const String& other = nullptr)
	{
		m_data = new char[strlen(other.m_data) + 1];
		strcpy(m_data, other.m_data);
	}
	//析构函数
	~String(void)
	{
		delete[]m_data;
		m_data = nullptr;
	}
	//赋值函数
	String& operator=(const String& other)//返回 String&，使其能够连续赋值
	{
		//防止自赋值
		if (this == &other)
		{
			return *this;
		}
		delete[]m_data;
		m_data = new char[strlen(other.m_data) + 1];
		strcpy(m_data, other.m_data);
		return *this;
	}
private:
	char* m_data;
};

//案例2：循环队列
class Queue
{
public:
	Queue(int size = 20) : _front(0), _rear(0), _size(size)
	{
		_pQue = new int[size];
	}
	//可以直接删除拷贝构造函数与赋值函数，不允许外部用户使用从而出错
		//Queue(const Queue &queue) = delete;
		//Queue& operator=(const Queue& queue) = delete;
	//拷贝构造，深拷贝
	Queue(const Queue &src)
	{
		_size = src._size;
		_rear = src._rear;
		_front = src._front;
		_pQue = new int[_size];
		for (int i = _front; i != _rear; i = (i + 1) % _size)
		{
			_pQue[i] = src._pQue[i];
		}
		
	}
	//赋值函数，深拷贝
	Queue& operator=(const Queue& src)
	{
		if (this == &src)
		{
			return *this;
		}
		delete[]_pQue;
		_size = src._size;
		_rear = src._rear;
		_front = src._front;
		_pQue = new int[_size];
		for (int i = _front; i != _rear; i = (i + 1) % _size)
		{
			_pQue[i] = src._pQue[i];
		}
		return *this;
	}
	~Queue()
	{
		delete[]_pQue;
		_pQue = nullptr;
	}
	//入队
	void push(int val)
	{
		if (full())
		{
			resize();
		}
		_pQue[_rear] = val;
		_rear = (_rear + 1) % _size;
	}
	//出队
	void pop()
	{
		if (empty())
		{
			return;
		}
		_front = (_front + 1) % _size;
	}
	//获取对头元素
	int top()
	{
		return _pQue[_front];
	}
	//是否队满
	bool full()
	{
		return (_rear + 1) % _size == _front;
	}
	//是否队空
	bool empty()
	{
		return _front == _rear;
	}
private:
	int* _pQue;//申请队列的数组空间
	int _front;//对头位置
	int _rear;//对尾位置
	int _size;//队列扩容的总大小
	void resize()
	{
		int* temp = new int[_size * 2];
		int index = 0;
		for (int i = _front; i != _rear; i = (i + 1) % _size)
		{
			temp[index++] = _pQue[i];
		}
		delete[]_pQue;
		_pQue = temp;
		_front = 0;
		_rear = index;
		_size *= 2;
	}
};

int main()
{
//案例1：string 类型
	//带 const char* 参数的构造函数
	String str1;
	String str2("hello");
	String str3 = "world";
	//拷贝构造函数
	String str4 = str3;
	String str5 = str3;
	str1 = str2;//赋值重载函数
	str3 = str2 = str1;

//案例2：循环队列
	Queue queue;
	for (int i = 0; i < 20; ++i)
	{
		queue.push(rand() % 100);
	}
	while (!queue.empty())
	{
		cout << queue.top() << " ";
		queue.pop();
	}
	cout << endl;
	Queue queue1 = queue;//若没有深拷贝，重复释放会产生释放野指针的操作
	queue1 = queue;//若没有深拷贝，重复释放会产生释放野指针的操作

	system("pause");
	return 0;
}
*/