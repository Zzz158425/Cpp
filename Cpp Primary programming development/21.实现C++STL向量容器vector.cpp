#include<iostream>
#include<typeinfo>
using namespace std;
//2026.2.27

/*
//实现 C++ STL 向量容器 vector
template<typename T>
class vector
{
public:
	vector(int size = 10)
	{
		_first = new T[size];
		_last = _first;
		_end = _first + size;
	}
	~vector()
	{
		delete[]_first;
		_first = _last = _end = nullptr;
	}
	vector(const vector<T>& rhs)
	{
		int size = rhs._end - rhs._first;
		_first = new T[size];
		int len = rhs._last - rhs._first;
		for (int i = 0; i < len; i++)
		{
			_first[i] = rhs._first[i];
		}
		_last = _first + len;
		_end = _first + size;
	}
	vector<T>& operator=(const vector<T>& rhs)
	{
		if (this == _first)
		{
			return *this;
		}
		delete[]_first;
		int size = rhs._end - rhs._first;
		_first = new T[size];
		int len = rhs._last - rhs._first;
		for (int i = 0; i < len; i++)
		{
			_first[i] = rhs._first[i];
		}
		_last = _first + len;
		_end = _first + size;
		return *this;
	}
	//从容器末尾添加元素
	void push_back(const T& val)
	{
		if (full())
		{
			expand();
		}
		*_last++ = val;
	}
	//从容器末尾删除元素
	void pop_back()
	{
		if (empty())
		{
			return;
		}
		_last--;
	}
	//返回容器末尾的元素值
	T back() const
	{
		return *(_last - 1);
	}
	bool full() const { return _last == _end; }//判断容器是否满
	bool empty() const { return _last == _first; } //判断容器是否为空
	int size() const { return _last - _first; }//返回容器个数
private:
	T* _first;//指向数组起始的位置
	T* _last;//指向数组中有限元素的后继位置
	T* _end;//指向数组空间的后继位置
	//容器 2 倍扩容
	void expand()
	{
		int size = _end - _first;
		T* ptmp = new T[size * 2];
		for (int i = 0; i < size; i++)
		{
			ptmp[i] = _first[i];
		}
		delete[]_first;
		_first = ptmp;
		_last = _first + size;
		_end = _first + (size * 2);
	}
};

int main()
{
//实现 C++ STL 向量容器 vector
	//与 C++ 库中的 vector 相比，上面实现的 vector 不包含空间配置器 allocator
	vector<int> vec;
	for (int i = 0; i < 20; i++)
	{
		vec.push_back(rand() % 100);
	}
	vec.pop_back();
	while (!vec.empty())
	{
		cout << vec.back() << " ";
		vec.pop_back();
	}
	cout << endl;
	
	system("pause");
	return 0;
}
*/

