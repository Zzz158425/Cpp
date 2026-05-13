#include<iostream>
#include<typeinfo>
#include<string>
using namespace std;
//2026.3.1

/*
//String 字符串对象的迭代器 iterator 实现
class String
{
public:
	String(const char* p = nullptr)
	{
		if (_pstr != nullptr)
		{
			_pstr = new char[strlen(p) + 1];
			strcpy(_pstr, p);
		}
		else
		{
			//防止以后每次都判断 _pstr 是否为空
			_pstr = new char[1];
			*_pstr = '\0';
		}
	}
	String(const String& src)
	{
		_pstr = new char[strlen(src._pstr) + 1];
		strcpy(_pstr, src._pstr);
	}
	String& operator=(const String& str)
	{
		if (this == &str)
		{
			return *this;
		}
		delete[]_pstr;
		_pstr = new char[strlen(str._pstr) + 1];
		strcpy(_pstr, str._pstr);
		return *this;
	}
	bool operator>(const String& str) const
	{
		return strcmp(_pstr, str._pstr) > 0;
	}
	bool operator<(const String& str) const
	{
		return strcmp(_pstr, str._pstr) < 0;
	}
	bool operator==(const String& str) const
	{
		return strcmp(_pstr, str._pstr) == 0;
	}
	int length() const { return strlen(_pstr); }
	char& operator[](int index) { return _pstr[index]; }//char ch = str[6];str[6] = '7';
	const char& operator[](int index) const { return _pstr[index]; }// char ch = str[6];不允许修改
	const char* c_str() const { return _pstr; }
	~String()
	{
		delete[]_pstr;
		_pstr = nullptr;
	}
	//String 迭代器实现
	class iterator
	{
	public:
		iterator(char* p = nullptr)
			:_p(p) { }
		bool operator!=(const iterator& it)
		{
			return _p != it._p;
		}
		void operator++()
		{
			++_p;
		}
		char& operator*()
		{
			return *_p;
		}
	private:
		char* _p;
	};
	iterator begin() { return iterator(_pstr); }//begin 返回的是容器底层首元素的迭代器的表示
	iterator end() { return iterator(_pstr + length()); }//begin 返回的是容器底层末尾元素后继位置的迭代器的表示
private:
	char* _pstr;
	friend ostream& operator<<(ostream& out, const String& str);
	friend String operator+(const String& lhs, const String& rhs);
};
String operator+(const String& lhs, const String& rhs)
{
	String temp;
	temp._pstr = new char[strlen(lhs._pstr) + strlen(lhs._pstr) + 1];
	strcpy(temp._pstr, lhs._pstr);
	strcat(temp._pstr, rhs._pstr);
	return temp;
}
ostream& operator<<(ostream& out, const String& str)
{
	out << str._pstr << endl;
	return out;
}

int main()
{
//String 字符串对象的迭代器 iterator 实现
	//迭代器：提供一种统一的方式，来透明的遍历容器
	string str1 = "hello world";//str1 也可以叫做容器，因为底层放了一组 char 类型的字符数组
	string::iterator it1 = str1.begin();//容器的迭代器 iterator，可以透明的访问容器内部的元素的值
	for (; it1 != str1.end(); ++it1)//前置 ++ 重载不会产生临时对象，推荐使用前置 ++
	{
		cout << *it1 << " ";
	}
	cout << endl;
	String str2 = "hello world";
	String::iterator it2 = str2.begin();
	//auto it2 = str2.begin();C++11 提供 aut，自动根据右边的类型来推导左边的类型
	for (; it2 != str2.end(); ++it2)
	{
		cout << *it2 << " ";
	}
	cout << endl;
	//C++11 foreach 的方式来遍历容器的内部元素的值，foreach 底层还是通过迭代器进行遍历的
	for (char ch : str2)
	{
		cout << ch << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
*/