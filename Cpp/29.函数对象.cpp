#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>
#include<functional>//内建函数对象头文件

/*
//函数对象基本使用
class MyAdd//函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};
class MyPrint//函数对象可以有自己的状态
{
public:
	MyPrint()
	{
		this->count = 0;
	}
	void operator()(string test)
	{
		cout << test << endl;
		this->count++;
	}
	int count;//内部自己状态
};
void doPrint(MyPrint& mp, string test)//函数对象可以作为参数传递
{
	mp(test);
}
void test01()
{
	MyAdd myAdd;
	MyPrint myprint;
	cout << myAdd(10, 10) << endl;
	myprint("张三");
	myprint("李四");
	myprint("王五");
	cout << "myprint 调用次数：" << myprint.count << endl;
	MyPrint myPrint;
	doPrint(myPrint, "hello c++");
}

//谓词
class GreaterFive
{
public:
	bool operator()(int val)//一元谓词
	{
		return val > 5;
	}
};
void test02()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());//find_if 按条件方式去寻找，GreaterFive() 匿名对象，返回迭加器，找到返回当前位置，未找到返回 end()
	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到了大于 5 的数字 " << *it << endl;
	}
}

//二元谓词
class MyCompare
{
public:
	bool operator()(int num1, int num2)//二元谓词
	{
		return num1 > num2;
	}
};
void test03()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	sort(v.begin(), v.end(), MyCompare());//使用函数对象改变算法策略，排序从大到小
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//内建函数对象
void test04()
{
	negate<int>n;//template<class T > T negate<T>
	cout << n(50) << endl;
	plus<int>p;
	cout << p(10, 20) << endl;//template<class T > T plus<T>

}

//关系仿函数
void test05()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	sort(v.begin(), v.end(), MyCompare());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	sort(v.begin(), v.end(), less<int>());//template<class T > bool less<T>，less<int>() 内建函数对象实现从大到小
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//逻辑仿函数
void test06()
{
	vector<bool>v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);
	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	vector<bool>v2;
	v2.resize(v.size());//必须提前开辟 v2 空间
	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());//transform 搬运算法
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
//函数对象基本使用 2025.11.18
	//概念：
		//重载函数调用操作符的类，其对象常称为函数对象
		//函数对象使用重载的 () 时，行为类似函数调用，也叫仿函数
	//本质：函数对象(仿函数)是一个类 ，不是一个函数
	//特点：
		//函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
		//函数对象超出普通函数的概念，函数对象可以有自己的状态
		//函数对象可以作为参数传递
	test01();

//谓词
	//概念：
		//返回 bool 类型的仿函数称为谓词
		//如果 operator() 接受一个参数，那么叫做一元谓词
		//如果 operator() 接受两个参数，那么叫做二元谓词
	test02();

//二元谓词
	test03();

//内建函数对象
	//概念：STL内建了一些函数对象
	//分类:
		//算术仿函数
		//关系仿函数
		//逻辑仿函数
	//用法：
		//这些仿函数所产生的对象，用法和一般函数完全相同
		//使用内建函数对象，需要引入头文件 #include<functional>
	//算术仿函数
		//功能描述：
			//实现四则运算
			//其中 negate 是一元运算，其他都是二元运算
		//仿函数原型：
			//template<class T > T plus<T>          //加法仿函数
			//template<class T > T minus<T>         //减法仿函数
			//template<class T > T multiplies<T>    //乘法仿函数
			//template<class T > T divides<T>       //除法仿函数
			//template<class T > T modulus<T>       //取模仿函数
			//template<class T > T negate<T>        //取反仿函数
	test04();

//关系仿函数
	//仿函数原型：
		//template<class T > bool equal_to<T>               //等于
		//template<class T > bool not_equal_to<T>           //不等于
		//template<class T > bool greater<T>                //大于
		//template<class T > bool greater_equal<T>          //大于等于
		//template<class T > bool less<T>                   //小于
		//template<class T > bool less_equal<T>             //小于等于
	test05();

//逻辑仿函数
	//函数原型：
		//template<class T > bool logical_and<T>              //逻辑与
		//template<class T > bool logical_or<T>               //逻辑或
		//template<class T > bool logical_not<T>              //逻辑非
	test06();

	system("pause");
	return 0;
}
*/