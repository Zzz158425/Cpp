#include<iostream>
#include<typeinfo>
using namespace std;

/*
//类的各种方法
class CDate
{
public:
	CDate(int y, int m, int d)
	{
		_year = y;
		_month = m;
		_day = d;
	}
	void show() const//必须也是常成员方法
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
		_count++;//记录所有产生的新对象的数量
	}
	//打印商品信息
	void show()
	{
		cout << "name:" << _name << endl;
		cout << "amount:" << _amount << endl;
		cout << "price:" << _price << endl;
		_date.show();
	}
	//常成员方法，show() 的重载
	void show() const //编译器生成 this 指针时，会生成 const CGoods *this
	{
		cout << "name:" << _name << endl;
		cout << "amount:" << _amount << endl;
		cout << "price:" << _price << endl;
		_date.show();//必须也是常成员方法
	}
	void setName(char* name) { strcpy(_name, name); }
	void setPrice(double price) { _price = price; }
	void setAmount(int amount) { _amount = amount; }
	const char* getName() { return _name; }//加 const 防止外部接收 _name 指针后修改成员变量
	double getPrice() { return _price; }
	int getAmount() { return _amount; }
	void showCGoodsCount(){ cout << "所有商品的种类数量是：" << _count << endl; }//普通成员方法
	static void showAllCGoodsCount() { cout << "所有商品的种类数量是：" << _count << endl; }//静态成员方法
private:
	char _name[20];
	double _price;
	int _amount;
	CDate _date;//成员对象
	static int _count;//静态成员变量，用来记录商品对象的总数量，需在外部进行定义，此处仅有声明的作用，所有成员共享，本质不属于对象，属于类级别
};
int CGoods::_count = 0;//静态成员变量一定要在类外进行定义并初始化

int main()
{
//类的各种方法
	//普通的成员方法
		//属于类的作用域
		//调用该方面时，需要依赖一个对象，因为编译器会添加一个 this 形参变量，即存在 this 指针
		//可以任意访问对象的私有成员变量
	CGoods good1("商品", 100, 35.0, 2019, 5, 12);
	good1.show();
	CGoods good2("商品", 100, 35.0, 2019, 5, 12);
	good2.show();
	CGoods good3("商品", 100, 35.0, 2019, 5, 12);
	good3.show();
	CGoods good4("商品", 100, 35.0, 2019, 5, 12);
	good4.show();
	good4.showCGoodsCount();//统计所有商品的总数量，但是只能由对象进行调用，不符合一般逻辑

	//静态成员方法
		//属于类的作用域
		//用类名作用域来调用方法
		//不需要依赖一个对象，不会生成 this 形参变量，即没有 this 指针
		//若一个方法访问的是所有对象共享信息，应该把他设置为静态成员方法
		//静态成员方法中无法访问普通的成员变量，没有 this 指针，无法找到访问的对象，看见访问任意对象的私有不依赖对象的成员（只能调用其他的 static 静态成员）
	CGoods::showAllCGoodsCount();

	//常成员方法
		//属于类的作用域
		//调用该方面时，需要依赖一个对象，普通对象或者常对象都可以，因为编译器会添加一个 const this 形参变量
		//可以任意访问对象的私有成员变量，只能读，不能写
		//对成员变量只读操作应一律应使用常成员方法
	const CGoods good5("非卖商品", 100, 35.0, 2019, 5, 12);
	//good5.show();无法调用，此时是 CGoods::show(&good5)，good5 为 const CGoods* 类型，普通方法为 CGoods *this 类型，const CGoods* 无法传给 CGoods *this
	good5.show();//使用常成员方法后，可调用

	system("pause");
	return 0;
}
*/