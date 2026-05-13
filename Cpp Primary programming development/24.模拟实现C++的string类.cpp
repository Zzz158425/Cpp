#include<iostream>
#include<typeinfo>
#include<string>
using namespace std;

/*
//模拟实现 C++ 的 string 类
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
private:
	char* _pstr;
	friend ostream& operator<<(ostream& out, const String& str);
	friend String operator+(const String& lhs, const String& rhs);
};
String operator+(const String& lhs, const String& rhs)
{
	//不能直接 strcat(lhs._pstr, lhs._pstr)，lhs._pstr 空间不足
	//效率低，会产生两次 new 与 delete，需优化
	//char* ptmp = new char[strlen(lhs._pstr) + strlen(lhs._pstr) + 1];
	//strcpy(ptmp, lhs._pstr);
	//strcat(ptmp, rhs._pstr);//strcat 将一个 C 风格字符串追加到另一个字符串末尾
	//String tmp(ptmp);
	//delete[]ptmp;
	//return tmp;
	//效率提高，只产生一次 new 与 delete
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
//string 
	string str1;//默认构造
	string str2 = "aaa";//string(const char*)
	string str3 = "bbb";
	string str4 = str2 + str3;//运算符重载
	string str5 = str2 + "ccc";
	string str6 = "ddd" + str2;
	cout << "str6:" << str6 << endl;//输出运算符重载
	if (str5 > str6)
	{
		cout << str5 << " > " << str6 << endl;
	}
	else
	{
		cout << str6 << " > " << str5 << endl;

	}
	int len = str6.length();
	for (int i = 0; i < len; i++)
	{
		cout << str6[i] << " ";//下标运算符重载 str6.operator[](i)
	}
	cout << endl;
	char buf[1024] = { 0 };
	strcpy(buf, str6.c_str());//.c_str 可以把字符串返回为 const char* 类型
	cout << "buf:" << buf << endl;

//模拟实现 C++ 的 string 类
	string str7;//默认构造
	string str8 = "aaa";//string(const char*)
	string str9 = "bbb";
	string str10 = str8 + str9;//运算符重载
	string str11 = str8 + "ccc";
	string str12 = "ddd" + str8;
	cout << "str12:" << str12 << endl;//输出运算符重载
	if (str11 > str12)
	{
		cout << str11 << " > " << str12 << endl;
	}
	else
	{
		cout << str12 << " > " << str11 << endl;

	}
	int len1 = str12.length();
	for (int i = 0; i < len; i++)
	{
		cout << str12[i] << " ";//下标运算符重载 str6.operator[](i)
	}
	cout << endl;
	char buf1[1024] = { 0 };
	strcpy(buf1, str12.c_str());//.c_str 可以把字符串返回为 const char* 类型
	cout << "buf1:" << buf1 << endl;

	system("pause");
	return 0;
}
*/