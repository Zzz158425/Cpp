#include<iostream>
#include<typeinfo>
using namespace std;

/*
//C++ OOP（面向对象编程）
const int NAME_LEN = 20;
class CGoods
{
public://给外部提供公有的方法，来访问私有属性
	//给商品数据初始化
	void init(const char* name, double price, int amount);//常量字符串不能用普通指针来接收，需加 const，防止解引用修改常量字符串的值
	//打印商品信息
	void show();
	//给成员变量提供一个 getXXX 和 setXXX 方法，类内实现的方法，自动处理成 inline 内联函数
	void setName(char* name) { strcpy(_name, name); }
	void setPrice(double price) { _price = price; }
	void setAmount(int amount) { _amount = amount; }
	const char* getName() { return _name; }//加 const 防止外部接收 _name 指针后修改成员变量
	double getPrice() { return _price; }
	int getAmount() { return _amount; }
private://属性一般都是私有的，外部无法访问
	char _name[NAME_LEN];
	double _price;
	int _amount;
};
//类外实现成员方法
//给商品数据初始化
void CGoods::init(const char* name, double price, int amount)//常量字符串不能用普通指针来接收，需加 const，防止解引用修改常量字符串的值
{
	strcpy(_name, name);
	_price = price;
	_amount = amount;
}
//打印商品信息
void CGoods::show()
{
	cout << "name:" << _name << endl;
	cout << "price:" << _price << endl;
	cout << "_amount:" << _amount << endl;
}

int main()
{
//C++ OOP（面向对象编程）
	//OOP 语言的四大特征是：抽象、封装/隐藏、继承、多态
	//C++ 中的类是给用户来进行自定义类型，即类代表实体的抽象类型
	//实体包含属性与行为，称为实体的ADT(abstract data type)
	//得到实体的 ADT 后可输出为类，类的属性称为成员变量，类的行为称为成员方法
	//封装/隐藏通过访问限定符体现：public（共有）、private（私有）、protected（保护）
	//类型不占空间，用该类型定义的对象占空间
	CGoods good1;
	good1.init("面包", 10.0, 200);//由对象来访问成员方法
	good1.show();
	good1.setPrice(20.0);
	good1.setAmount(100);
	good1.show();
	CGoods good2;
	good2.init("空调", 100000.0, 20);
	good2.show();

//对象的内存大小
	//对象的内存大小只和成员变量有关
	//先看最长的成员分量，其余成员分量以最长的成员分量进行内存字节对齐
	//CGoods 占 40 字节大小：_name(0~23)_price(24-31)_amount(32-39)
	//可以打开 VS 命令行（工具-VS 命令提示）进行查看
		//切到当前文件所在文件夹：1.d:（回车） 2. cd D:\Visual Studio2022SharedProject\C ++\C ++ Primary programming development（回车）
		//dir（回车），cl 12.类和对象、this指针.cpp /dlreportSingleClassLayoutCGoods（回车）

//this 指针
	//this 指针会指向调用该方法的对象
	//类的成员方法一经编译，所有的方法参数，都会加一个 this 指针，接收调用该方法的对象的地址
		//void setName(CGoods *this, char* name) { strcpy(_name, name); }
		//void setPrice(CGoods *this, double price) { _price = price; }
		//void setAmount(CGoods *this, int amount) { _amount = amount; }
		//const char* getName(CGoods *this, ) { return _name; }
		//double getPrice(CGoods *this, ) { return _price; }
		//int getAmount(CGoods *this, ) { return _amount; }

	system("pause");
	return 0;
}
*/