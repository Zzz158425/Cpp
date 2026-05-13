#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>

/*
//String 构造函数
void test01()
{
	string s1;//string()
	const char* str = "hello world";//string(const char* s)
	string s2(str);
	cout << "s2 = " << s2 << endl;
	string s3(s2);//string(const string& str)
	cout << "s3 = " << s3 << endl;
	string s4(10, 'a');//string(int n, char c)
	cout << "s4 = " << s4 << endl;
}

//String 赋值操作
void test02()
{
	string str1;
	str1 = "hello world";//string& operator=(const char* s)
	cout << "str1 = " << str1 << endl;
	string str2;
	str2 = str1;//string& operator=(const string & s)
	cout << "str2 = " << str2 << endl;
	string str3;
	str3 = 'a';//string& operator=(char c)
	cout << "str3 = " << str3 << endl;
	string str4;
	str4.assign("hello Cpp");//string& assign(const char* s)
	cout << "str4 = " << str4 << endl;
	string str5;
	str5.assign("hello Cpp", 7);//string& assign(const char* s, int n)
	cout << "str5 = " << str5 << endl;
	string str6;
	str6.assign(str5);//string& assign(const string & s)
	cout << "str6 = " << str6 << endl;
	string str7;
	str7.assign(10, 'w');//string& assign(int n, char c)
	cout << "str7 = " << str7 << endl;
}

//String 字符串拼接
void test03()
{
	string str1 = "我";
	str1 += "爱玩游戏";//string& operator+=(const char* str)
	cout << "str1 = " << str1 << endl;
	str1 += ':';//string& operator+=(const char c)
	cout << "str1 = " << str1 << endl;
	string str2 = "LOL DNF";
	str1 += str2;//string& operator+=(const string & str)
	cout << "str1 = " << str1 << endl;
	string str3 = "I ";
	str3.append("Love ");//string& append(const char* s)
	cout << "str3 = " << str3 << endl;
	str3.append("Gamegggg", 4);//string& append(const char* s, int n)
	cout << "str3 = " << str3 << endl;
	str3.append(str2);//string& assign(const string & s)
	cout << "str3 = " << str3 << endl;
	str3.append(str2, 0, 5);//string& append(const string & s, int pos, int n)，pos 为起始位置
	cout << "str3 = " << str3 << endl;
}

//String 查找和替换 2025.11.12
void test04()
{
	string str1 = "abcdefg";
	int pos = str1.find("de");//int find(const string & str, int pos = 0) const
	if (pos == -1)
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "已找到，pos = " << pos << endl;
	}
	string str2 = "abcdefgde";
	pos = str2.rfind("de");//rfind 是从右往左查找，find 是从左往右查找，int rfind(const string & str, int pos = npos) const
	cout << "pos = " << pos << endl;
}
void test05()
{
	string str1 = "abcdefg";
	str1.replace(1, 3, "1111");//从 1 号位置起，3 个字符替换为 1111
	cout << "str1 = " << str1 << endl;
}

//String 字符串比较
void test06()
{
	string str1 = "hello";
	string str2 = "xello";
	if (str1.compare(str2) == 0)//取决第一个不同字母的 ASCII 码值
	{
		cout << "str1 等于 str2" << endl;
	}
	else if (str1.compare(str2) > 0)
	{
		cout << "str1 大于 str2" << endl;
	}
	else
	{
		cout << "str1 小于 str2" << endl;
	}
}

//String 字符存取
void test07()
{
	string str = "hello";
	cout << "str = " << str << endl;
	for (int i = 0; i < str.size(); i++)//str.size() 可以返回字符串长度
	{
		cout << str[i] << " ";//char& operator[](int n)
	}
	cout << endl;
	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << " ";//char& at(int n)
	}
	cout << endl;
	str[0] = 'x';//修改字符
	cout << "str[] = " << str << endl;
	str.at(1) = 'x';
	cout << "str.at = " << str << endl;
}

//String 插入和删除
void test08()
{
	string str = "hello";
	str.insert(1, "111");
	cout << "str.insert = " << str << endl;
	str.erase(1, 3);
	cout << "str.erase = " << str << endl;
}

//String 子串获取
void test09()
{
	string str = "abcdef";
	string subStr = str.substr(1, 3);
	cout << "subStr = " << subStr << endl;
}
void test10()//实用操作
{
	string email = "hello@sina.com";
	int pos = email.find("@");
	string userName = email.substr(0, pos);
	cout << "userName = " << userName << endl;
}

int main()
{
//String 构造函数
	//本质：string 是 C++ 风格的字符串，而 string 本质上是一个类
	//string 和 char 区别：
		//char* 是一个指针
		//string 是一个类，类内部封装了char\* ，管理这个字符串，是一个 char* 型的容器。
	//特点：
		//string 类内部封装了很多成员方法
		//例如：查找 find，拷贝 copy，删除 delete 替换 replace，插入 insert。string 管理 char* 所分配的内存，不用担心复制越界和取值越界等，由类内部进行负责
	//构造函数原型：
		//string();       				//创建一个空的字符串 例如: string str;
		//string(const char* s);        //使用字符串 s 初始化
		//string(const string& str);    //使用一个 string 对象初始化另一个 string 对象
		//string(int n, char c);        //使用 n 个字符 c 初始化
	//总结：string的多种构造方式没有可比性，灵活使用即可
	test01();

//String 赋值操作
	//功能描述：给 string 字符串进行赋值
	//赋值的函数原型：
		//string& operator=(const char* s);        //char* 类型字符串 赋值给当前的字符串
		//string& operator=(const string & s);     //把字符串 s 赋给当前的字符串
		//string& operator=(char c);               //字符赋值给当前的字符串
		//string& assign(const char* s);           //把字符串 s 赋给当前的字符串
		//string& assign(const char* s, int n);    //把字符串 s 的前 n 个字符赋给当前的字符串
		//string& assign(const string & s);        //把字符串 s 赋给当前字符串
		//string& assign(int n, char c);           //用 n 个字符 c 赋给当前字符串
	test02();

//字符串拼接 
	//功能描述：实现在字符串末尾拼接字符串
	//函数原型：
		//string& operator+=(const char* str);                 //重载 += 操作符
		//string& operator+=(const char c);                    //重载 += 操作符
		//string& operator+=(const string & str);              //重载 += 操作符
		//string& append(const char* s);                       //把字符串 s 连接到当前字符串结尾
		//string& append(const char* s, int n);                //把字符串 s 的前 n 个字符连接到当前字符串结尾
		//string& append(const string & s);                    //同 operator+=(const string& str)
		//string& append(const string & s, int pos, int n);    //字符串 s 中从 pos 开始的 n 个字符连接到字符串结尾
	test03();

//String 查找和替换 2025.11.12
	//功能描述：
		//查找：查找指定字符串是否存在
		//替换：在指定的位置替换字符串
	//函数原型：
		//int find(const string & str, int pos = 0) const;           //查找str第一次出现位置,从pos开始查找
		//int find(const char* s, int pos = 0) const;                //查找s第一次出现位置,从pos开始查找
		//int find(const char* s, int pos, int n) const;             //从pos位置查找s的前n个字符第一次位置
		//int find(const char c, int pos = 0) const;                 //查找字符c第一次出现位置
		//int rfind(const string & str, int pos = npos) const;       //查找str最后一次位置,从pos开始查找
		//int rfind(const char* s, int pos = npos) const;            //查找s最后一次出现位置,从pos开始查找
		//int rfind(const char* s, int pos, int n) const;            //从pos查找s的前n个字符最后一次位置
		//int rfind(const char c, int pos = 0) const;                //查找字符c最后一次出现位置
		//string& replace(int pos, int n, const string & str);       //替换从pos开始n个字符为字符串str
		//string& replace(int pos, int n, const char* s);            //替换从pos开始的n个字符为字符串s
	//rfind 是从右往左查找，find是从左往右查找
	//find找到字符串后返回查找的第一个字符位置，找不到返回 -1
	//replace 在替换时，要指定从哪个位置起，多少个字符，替换成什么样的字符串
	test04();
	test05();

//String 字符串比较
	//字符串之间的比较
	//比较方式：字符串比较是按字符的ASCII码进行对比，= 返回 0，> 返回 1，< 返回 -1
	//函数原型：
		//int compare(const string & s) const;  //与字符串 s 比较
		//int compare(const char* s) const;     //与字符串 s 比较
	//字符串对比主要是用于比较两个字符串是否相等，判断谁大谁小的意义并不是很大
	test06();

//String 字符存取
	//string 中单个字符存取方式有两种
		//char& operator[](int n);     //通过 [] 方式取字符
		//char& at(int n);             //通过 at 方法获取字符
	test07();

//String 插入和删除
	//函数原型：
		//string& insert(int pos, const char* s);             //插入字符串
		//string& insert(int pos, const string & str);        //插入字符串
		//string& insert(int pos, int n, char c);             //在指定位置插入 n 个字符 c
		//string& erase(int pos, int n = npos);               //删除从 Pos 开始的 n 个字符 
	test08();

//String 子串获取
	//功能描述：
		//从字符串中获取想要的子串
	//函数原型：
		//string substr(int pos = 0, int n = npos) const;   //返回由 pos 开始的 n 个字符组成的字符串
	test09();
	test10();

	system("pause");
	return 0;
}
*/