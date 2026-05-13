#include<iostream>
using namespace std;
#include<string>
#include<fstream>

/*
//文本文件-写文件
void test01()
{
	ofstream ofs;
	ofs.open("test.txt", ios::out);//不指定目录会直接创建文件在项目目录下
	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：18" << endl;
	ofs.close();
}

//文本文件-读文件
void test02()
{
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	if ( !ifs.is_open() )
	{
		cout << " 文件打开失败" << endl;
		return;
	}
	char buf[1024] = { 0 };//第一种
	while (ifs >> buf)
	{
		cout << buf << endl;
	}
	//char buf[1024] = { 0 };第二种
	//while (ifs.getline(buf, sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}
	//string buf; 第三种
	//while (getline(ifs, buf))
	//{
	//	cout << buf << endl;
	//}
	//char c;第四种，不推荐
	//while ((c = ifs.get()) != EOF)//EOF end of file
	//{
	//	cout << c;
	//}
	ifs.close();
}

//二进制文件-写文件
class Person
{
public:
	char m_Name[64];
	int m_Age;
};
void test03()
{
	ofstream ofs1;//也可以 ofstream ofs1("Person.text", ios::out | ios::binary);
	ofs1.open("Person.text", ios::out | ios::binary);
	Person p = { "张三", 18 };//初始化列表，聚合初始化，适用于没有自定义构造函数的类或结构体
	ofs1.write((const char*)&p, sizeof(Person));
	ofs1.close();
}

//二进制文件-读文件
class Person1
{
public:
	char m_Name[64];
	int m_Age;
};
void test04()
{
	ifstream ifs1;
	ifs1.open("Person.text", ios::in | ios::binary);
	if (!ifs1.is_open())
	{
		cout << " 文件打开失败" << endl;
		return;
	}
	Person1 p1;
	ifs1.read((char*)&p1,sizeof(Person1));
	cout << "姓名：" << p1.m_Name << " 年龄：" << p1.m_Age << endl;
	ifs1.close();
}

int main()
{
//文本文件-写文件
	//程序运行时产生的数据都属于临时数据，程序一旦运行结束都会被释放，通过文件可以将数据持久化
	//C++ 中对文件操作需要包含头文件 fstream
	//文件类型分为两种：
		//1.文本文件 - 文件以文本的 ASCII 码形式存储在计算机中
		//2.二进制文件 - 文件以文本的二进制形式存储在计算机中，用户一般不能直接读懂它们
	//操作文件的三大类:
		//1. ofstream：写操作
		//2. ifstream：读操作
		//3. fstream ：读写操作
	//写文件步骤如下：
		//1. 包含头文件 #include <fstream>
		//2. 创建流对象 ofstream ofs;
		//3. 打开文件 ofs.open("文件路径", 打开方式);
		//4. 写数据 ofs << "写入的数据";
		//5. 关闭文件ofs.close();
	//文件打开方式：
		//打开方式              解释
		//ios::in              为读文件而打开文件
		//ios::out             为写文件而打开文件
		//ios::ate             初始位置：文件尾
		//ios::app             追加方式写文件
		//ios::trunc           如果文件存在先删除，再创建
		//ios::binary          二进制方式
	//注意：文件打开方式可以配合使用，利用 | 操作符，例如：用二进制方式写文件 ios::binary | ios::out
	test01();

//文本文件-写文件
	//读文件与写文件步骤相似，但是读取方式相对于比较多
	//读文件步骤如下：
		//1.包含头文件 #include <fstream>
		//2. 创建流对象 ifstream ifs;
		//3. 打开文件并判断文件是否打开成功 ifs.open("文件路径", 打开方式);
		//4. 读数据，四种方式读取
		//5. 关闭文件 ifs.close();
	test02();

//二进制文件-写文件
	//以二进制的方式对文件进行读写操作，打开方式要指定为 ios::binary
	//二进制方式写文件主要利用流对象调用成员函数 write
	//函数原型 ：ostream& write(const char* buffer, int len);
	//参数解释：字符指针 buffer 指向内存中一段存储空间。len 是读写的字节数
	//文件输出流对象 可以通过 write 函数，以二进制方式写数据
	test03();

//二进制文件-读文件
	//二进制方式读文件主要利用流对象调用成员函数 read
	//函数原型：istream& read(char* buffer, int len);
	//参数解释：字符指针 buffer 指向内存中一段存储空间。len 是读写的字节数
	test04();

system("pause");
return 0;
}
*/