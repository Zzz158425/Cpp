#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>

/*
//Vector 构造函数 2025.11.13
void printVector(vector<int>v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test01()
{
	vector<int>v1;//默认构造，无参构造，vector<T > v
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	vector<int>v2(v1.begin(), v1.end());//通关区间方式构造，vector(v.begin(), v.end())
	printVector(v2);
	vector<int>v3(10, 100);//n 个 elem 方式构造，vector(n, elem)
	printVector(v3);
	vector<int>v4(v3);//拷贝构造，vector(const vector& vec)
	printVector(v4);
}

//Vector 赋值操作
void test02()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	vector<int>v2;
	v2 = v1;//operator=，vector& operator=(const vector& vec)
	printVector(v2);
	vector<int>v3;
	v3.assign(v1.begin(), v1.end());//assign(beg, end)
	printVector(v3);
	vector<int>v4;
	v4.assign(10, 100);//assign(n, elem)
	printVector(v4);
}

//Vector 容量和大小
void test03()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	if (v1.empty())//为真，代表容器为空
	{
		cout << "v1 为空" << endl;
	}
	else
	{
		cout << "v1 不为空 " << endl;
		cout << "v1 的容量 " << v1.capacity() << endl;
		cout << "v1 的大小 " << v1.size() << endl;
	}
	v1.resize(15);//重新指定大小，若比原来长，默认用 0 来填充新的位置，利用重载版本可以指定填充值 v1.resize(15, 100)，resize(int num)
	printVector(v1);
	cout << "v1 的容量 " << v1.capacity() << endl;
	v1.resize(5);
	printVector(v1);//重新指定大小，若比原来短，超出部分会被删除，resize(int num, elem)
	cout << "v1 的容量 " << v1.capacity() << endl;
}

//Vector 插入和删除
void test04()
{
	vector<int>v1;//尾插，push_back(ele)
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	printVector(v1);
	v1.pop_back();//尾删，pop_back()
	printVector(v1);
	v1.insert(v1.begin(), 100);//插入，insert(const_iterator pos, ele)
	printVector(v1);
	v1.insert(v1.begin(), 2, 1000);//插入 n 个数据，insert(const_iterator pos, int count, ele)
	printVector(v1);
	v1.erase(v1.begin());//删除，erase(const_iterator pos)
	printVector(v1);
	v1.erase(v1.begin(), v1.end()-2);//区间删除，erase(const_iterator start, const_iterator end)
	printVector(v1);
	v1.clear();//清空，clear()
	printVector(v1);
}

//Vector 数据存取
void test05()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	for (int i = 0; i < v1.size(); i++)//利用 [] 来访问元素，operator[]
	{
		cout << v1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < v1.size(); i++)//利用 at 来访问元素，at(int idx)
	{
		cout << v1.at(i) << " ";
	}
	cout << endl;
	cout << "v1 第一个元素为：" << v1.front() << endl;
	cout << "v1 最后一个元素为：" << v1.back() << endl;
}

//Vector 互换容器
void test06()
{
	cout << "交换前：" << endl;
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	vector<int>v2;
	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}
	printVector(v2);
	cout << "交换后：" << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);
}
void test07()//实际用途，巧用 swap 可以收纳内存空间
{
	vector<int>v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}
	cout << "v 的容量为:" << v.capacity() << endl;
	cout << "v 的大小为：" << v.size() << endl;
	v.resize(3);//重新指定大小，不会改变原来的容量
	cout << "v 的容量为：" << v.capacity() << endl;
	cout << "v 的大小为：" << v.size() << endl;
	vector<int>(v).swap(v);//收缩内存，vector<int>(v)：匿名对象按照 v 所用的元素个数来做初始化，匿名对象当前行执行完后马上回收；.swap(v)：容器交换
	cout << "v 的容量为：" << v.capacity() << endl;
	cout << "v 的大小为：" << v.size() << endl;
}

//Vector 预留空间
void test08()
{
	vector<int>v;
	int num = 0;//统计开辟次数
	int* p = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];//如果 p 不等于首地址，那么说明进行了动态扩展，因为每次扩展需开辟新内存
			num++;
		}
	}
	cout << "num = " << num << endl;
	vector<int>v1;
	v1.reserve(100000);//提前预留空间，可以防止反复开辟新内存
	num = 0;
	int* p1 = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v1.push_back(i);
		if (p1 != &v1[0])
		{
			p1 = &v1[0];
			num++;
		}
	}
	cout << "num = " << num << endl;
}

int main()
{
//Vector 构造函数 2025.11.13
	//功能：vector 数据结构和数组非常相似，也称为单端数组
	//vector 与普通数组区别：不同之处在于数组是静态空间，而 vector 可以动态扩展
	//动态扩展：并不是在原空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝新空间，释放原空间；vector 容器的迭代器是支持随机访问的迭代器
	//功能描述：创建 vector 容器
	//函数原型：
		//vector<T > v;               		 //采用模板实现类实现，默认构造函数
		//vector(v.begin(), v.end());        //将 v[begin(), end()) 区间中的元素拷贝给本身
		//vector(n, elem);                   //构造函数将 n 个 elem 拷贝给本身
		//vector(const vector& vec);         //拷贝构造函数
	test01();

//Vector 赋值操作
	//函数原型：
		//vector& operator=(const vector& vec); // 重载等号操作符
		//assign(beg, end);       //将[beg, end)区间中的数据拷贝赋值给本身。
		//assign(n, elem);        //将n个elem拷贝赋值给本身。
	test02();

//Vector 容量和大小
	//函数原型：
		//empty();                //判断容器是否为空
		//capacity();             //容器的容量
		//size();                 //返回容器中元素的个数
		//resize(int num);        //重新指定容器的长度为 num，若容器变长，则以默认值填充新位置；如果容器变短，则末尾超出容器长度的元素被删除
		//resize(int num, elem);  //重新指定容器的长度为 num，若容器变长，则以 elem 值填充新位置；如果容器变短，则末尾超出容器长度的元素被删除
	test03();

//Vector 插入和删除
	//函数原型：
		//push_back(ele);                                 //尾部插入元素 ele
		//pop_back();                                     //删除最后一个元素
		//insert(const_iterator pos, ele);                //迭代器指向位置 pos 插入元素 ele
		//insert(const_iterator pos, int count, ele);     //迭代器指向位置 pos 插入 count 个元素 ele
		//erase(const_iterator pos);                      //删除迭代器指向的元素
		//erase(const_iterator start, const_iterator end);//删除迭代器从 start 到 end 之间的元素
		//clear();                                        //删除容器中所有元素
	test04();

//Vector 数据存取
	//函数原型：
		//at(int idx);     //返回索引idx所指的数据
		//operator[];      //返回索引idx所指的数据
		//front();         //返回容器中第一个数据元素
		//back();          //返回容器中最后一个数据元素
	test05();

//Vector 互换容器
	//函数原型：
		//swap(vec); //将vec与本身的元素互换
	test06();
	test07();

//Vector 预留空间
	//功能描述：减少vector在动态扩展容量时的扩展次数
	//函数原型：
		//reserve(int len); //容器预留 len 个元素长度，预留位置不初始化，元素不可访问。
	test08();

	system("pause");
	return 0;
}
*/