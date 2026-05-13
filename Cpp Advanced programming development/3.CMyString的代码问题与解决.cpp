#include<iostream>
using namespace std;

/*
class CMyString
{
public:
	CMyString(const char* str = nullptr)
	{
		cout << "CMyString(const char*)" << endl;
		if (str != nullptr)
		{
			mptr = new char[strlen(str) + 1];
			strcpy(mptr, str);
		}
		else
		{
			mptr = new char[1];
			*mptr = '\0';
		}
	}
	~CMyString()
	{
		cout << "~CMyString" << endl;
		delete[]mptr;
		mptr = nullptr;
	}
	//带左值引用参数的拷贝构造
	CMyString(const CMyString& str)
	{
		cout << "CMyString(const CMyString&)" << endl;
		mptr = new char[strlen(str.mptr) + 1];
		strcpy(mptr, str.mptr);
	}
	//注意：此处优化在 VS2022 中并没有用到，因为编译器会自动优化，不存在拷贝构造 tempStr 后，再拷贝构造给 main 函数栈上的临时对象
	//带右值引用参数的拷贝构造
	CMyString(CMyString&& str)//str 引用的就是一个临时对象，即 main 函数栈上的临时对象
	{
		cout << "CMyString(CMyString&& str)" << endl;
		mptr = str.mptr;//直接将 main 函数栈上的临时对象指向该内存所指的空间
		str.mptr = nullptr;//必须将 str.mptr 置空，不然两个指针指向同一块内存，会造成浅拷贝
	}
	//带左值引用参数的赋值重载函数
	CMyString& operator=(const CMyString& str)
	{
		cout << "operator=(const CMyString&)" << endl; 
		if (this == &str)
		{
			return *this;
		}
		delete[]mptr;
		mptr = new char[strlen(str.mptr) + 1]; 
		strcpy(mptr, str.mptr); 
		return *this;
	}
	//带右值引用参数的赋值重载函数
	CMyString& operator=(CMyString&& str)//与上同理
	{
		cout << "operator=(const CMyString&&)" << endl;
		if (this == &str)
		{
			return *this;
		}
		delete[]mptr;
		mptr = str.mptr;
		str.mptr = nullptr;
		return *this;
	}
	const char* c_str() const { return mptr; };
private:
	char* mptr;
};
CMyString GetString(CMyString& str)
{
	const char* pstr = str.c_str();
	//注意：在 VS2022 中编译器会自动优化为 return CMyString(pstr);，即不存在拷贝构造 tempStr 后，再拷贝构造给 main 函数栈上的临时对象
	CMyString tempStr(pstr);
	return tempStr;//tempStr 中有指针 mptr 指向外部的一块内存空间，因为 GetString 函数作用完成后，tempStr 会销毁，需把 mptr 拷贝构造到 main 函数栈上的临时对象，从而把 mptr 指向的内容传递到函数外，但此时完成拷贝构造后 mptr 会立即释放，造成数据的无用拷贝
}

int main()
{
//CMyString 代码问题
	CMyString str1 = ("aaaaaaaaaaaaaaa");
	CMyString str2;
	str2 = GetString(str1);//与上述面临同样的问题，临时对象 operator= 到 str2 中的 mptr 后立即释放，造成数据的无用拷贝
	cout << str2.c_str() << endl;
	
//为了解决该问题引入添加带右值引用参数的拷贝构造和赋值函数
	//左值引用，需要内存、名字
	int a = 10;
	int& b = a;//a 需有内存、名字
	//int& c = 20;不能用左值引用绑定一个右值
	const int& c = 20;//加 const 后编译器会自动进行：int tmp = 20;const int& c = tmp;不可以修改临时量的值
	//右值引用，不需要内存、名字（临时量）
	int&& d = 20;//编译器会自动进行：int tmp = 20;int&& d = tmp;可以修改临时量的值
	//CMyString& e = CMyString("aaa");非常量引用只能绑定到左值
	const CMyString& e = CMyString("aaa");//采用常引用
	CMyString&& ee = CMyString("aaa");//采用右值引用
	//int&& f = d;一个右值引用变量，本身是一个左值

	system("pause");
	return 0;
}
*/