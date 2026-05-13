#include<iostream>
#include<typeinfo>
using namespace std;

/*
//模板的非类型参数
template<typename T, int SIZE>
void sort(T* arr)
{
	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = 0; j < SIZE - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//类模板
template<typename T>
class SeqStack//模板名称 + 类型参数列表 = 类名称
{
public:
	SeqStack<T>(int size = 10)//析构和构造函数 <T> 可以省略，其他不能省略
		: _pstack(new T[size])
		, _top(0)
		, _size(size)
	{}
	SeqStack<T>(const SeqStack<T>& stack)
		:  _top(stack._top)
		, _size(stack._size)
	{
		_pstack = new T[_size];
		for (int i = 0; i < _top; i++)//只拷贝有效元素，应小于 _top
		{
			_pstack[i] = stack._pstack[i];
		}
	}
	~SeqStack<T>()
	{
		delete[]_pstack;
		_pstack = nullptr;
	}
	SeqStack<T>& operator=(const SeqStack<T>& stack)
	{
		if (this == &stack)
		{
			return *this;
		}
		delete[]_pstack;
		_top = stack._top;
		_size = stack._size;
		_pstack = new T[_size];
		for (int i = 0; i < _top; i++)
		{
			_pstack[i] = stack._pstack[i];
		}
		return *this;
	}
	void push(const T& val);
	void pop()
	{
		if (empty())
		{
			return;
		}
		--_top;
	}
	T top()const
	{
		if (empty())
		{
			throw "stack is empty!";//抛异常也代表函数逻辑结束，不需要和函数返回值保持一致
		}
		return _pstack[_top - 1];
	}
	bool full() const { return _top == _size; }
	bool empty() const { return _top == 0; }
private:
	T* _pstack;
	int _top;
	int _size;
	void expand()
	{
		T* ptmp = new T[_size * 2];
		for (int i = 0; i < _top; i++)
		{
			ptmp[i] = _pstack[i];
		}
		delete[]_pstack;
		_pstack = ptmp;
		_size *= 2;
	}
};
template<typename T>//类外实现需重新加 template<typename T>
void SeqStack<T>::push(const T& val)
{
	if (full())
	{
		expand();
	}
	_pstack[_top++] = val;
}

int main()
{
//模板的非类型参数
	//模板的非类型参数都是常量，必须是整数类型（整数或地址/引用都可以），只能使用，不能修改
	int arr[] = { 12,5,7,89,32,21,35 };
	const int size = sizeof(arr) / sizeof(arr[0]);//需加 const，因为模板的非类型参数都是常量
	sort<int, size>(arr);
	for (int val : arr)
	{
		cout << val << " ";
	}
	cout << endl;

//类模板
	//类模板选择性实例化：类模板实例化时只会实例化调用的部分
	//类模板也可以设置默认类型参数 template<typename T = int>，此时可以简写 SeqStack<> s1
	SeqStack<int> s1;//实例化析构与构造函数
	s1.push(20);//实例化 push 成员方法
	s1.push(10);
	s1.pop();// 实例化 pop 成员方法
	cout << s1.top() << endl;

	system("pause");
	return 0;
}
*/