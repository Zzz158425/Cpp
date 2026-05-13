#include<iostream>
#include<typeinfo>
using namespace std;

/*
//构造函数的初始化列表
//日期类
class CDate
{
public:
	CDate(int y, int m, int d)
	{
		_year = y;
		_month = m;
		_day = d;
	}
	void show()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
class CGoods
{
public:
	CGoods(const char* n, int a, double p, int y, int m, int d)//常量字符串不能用普通指针来接收，需加 const，防止解引用修改常量字符串的值
		:_amount(a)
		, _price(p)//double _price = p;
		, _date(y, m, d)//构造函数初始化列表
	{
		//当前类类型构造函数体
		strcpy(_name, n);
		//_price = p;double _price;_price = a;
		//_date = CDate(y, m, d);会调用默认构造，但是无默认构造，错误写法
	}
	//打印商品信息
	void show()
	{
		cout << "name:" << _name << endl;
		cout << "amount:" << _amount << endl;
		cout << "price:" << _price << endl;
		_date.show();
	}
	void setName(char* name) { strcpy(_name, name); }
	void setPrice(double price) { _price = price; }
	void setAmount(int amount) { _amount = amount; }
	const char* getName() { return _name; }//加 const 防止外部接收 _name 指针后修改成员变量
	double getPrice() { return _price; }
	int getAmount() { return _amount; }
private:
	char _name[20];
	double _price;
	int _amount;
	CDate _date;//成员对象
};

//案例
class Test
{
public:
	Test(int data = 10) : mb(data), ma(mb){}
	void show() { cout << "ma:" << ma << "mb:" << mb << endl; }
private:
	int ma;
	int mb;
};

int main()
{
//构造函数的初始化列表
	//指定当前对象成员变量的初始化方式   
	//在执行构造函数时，先执行构造函数初始化列表，再执行当前类类型构造函数体
	//在进行构造函数成员变量初始化时，尽量将成员变量的初始化写在构造函数的初始化列表中
	CGoods good("商品", 100, 35.0, 2019, 5, 12);
	good.show();

//案例
	//成员变量的初始化和他们定义的顺序有关：先定义的成员变量先初始化，和构造函数初始化列表中出现的先后顺序无关
	Test t;
	t.show();//输出：ma:-858993460mb:10，ma 先初始化，此时 ma 无值，对象在栈上此时显示默认值，在初始化 mb

	system("pause");
	return 0;
}
*/