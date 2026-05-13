#include<iostream>
#include<typeinfo>
#include<string>
#include<vector>
using namespace std;
//2026.3.7

/*
int main()
{
//迭代器
	//iterator：普通的正向迭代器，可读可写
	//const_iterator：常量的正向迭代器，只能读
	//reverse_iterator：反向迭代器，可读可写
		//rbegin()：返回的是最后一个元素的反向迭代器表示
		//rend：返回的是首元素前序位置的迭代器的表示
	//const_reverse_iterator：常量的反向迭代器，只能读
	
//iterator
	vector<int> vec;
	for (int i = 0; i < 20; i++)
	{
		vec.push_back(rand() % 100);
	}
	vector<int>::iterator it = vec.begin();
	auto it1 = vec.begin();
	for (; it1 != vec.end(); ++it1)
	{
		cout << *it1 << " ";//通过迭代器访问元素
		//通过迭代器修改元素
		if (*it1 % 2 == 0)
		{
			*it1 = 0;
		}

	}
	cout << endl;
	for (int v : vec)
	{
		cout << v << " ";
	}
	cout << endl;

//const_iterator
	vector<int> vec1;
	for (int i = 0; i < 20; i++)
	{
		vec1.push_back(rand() % 100);
	}
	vector<int>::const_iterator it2 = vec1.begin();//iterator 从 const_iterator 继承而来，基类定义的对象可以接收派生类对象
	//class const_iterator { const T& operator*(){ return *_ptr; }}
	//class iterator : public const_iterator { T& operator*(){ return *_ptr; }}
	for (; it2 != vec1.end(); ++it2)
	{
		cout << *it2 << " ";//通过迭代器访问元素
		//无法修改元素
		//if (*it2 % 2 == 0)
		//{
		//	*it2 = 0;
		//}
	}
	cout << endl;
	for (int v : vec1)
	{
		cout << v << " ";
	}
	cout << endl;

//reverse_iterator
	vector<int>::reverse_iterator it3 = vec1.rbegin();
	auto rit = vec1.rbegin();
	for (; rit != vec1.rend(); ++rit)
	{
		cout << *rit << " ";
	}
	cout << endl;
	for (int v : vec1)
	{
		cout << v << " ";
	}
	cout << endl;
	vector<int>::const_reverse_iterator it4 = vec1.rbegin();
	//*it4 = 1;无法修改元素

	system("pause");
	return 0;
}
*/