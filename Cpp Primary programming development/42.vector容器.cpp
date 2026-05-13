#include<iostream>
#include<typeinfo>
#include<string>
#include<vector>
using namespace std;
//2026.3.5

/*
int main()
{
//C++ STL
	//STL standard template library 标准模板库
	//标准容器，C++11 还提供了 array、forward_list
		//1.顺序容器：vector、deque、list
		//2.容器适配器：stack、queue、priority_queue
		//3.关联容器
			//无序关联容器（链式哈希表，无序，增删查 O(1)）：set：集合 key，map：映射表 [key, value]，常用
				//unordered_set（单重集合）
				//unordered_multiset（多重集合）
				//unordered_map（单重映射表）
				//unordered_multimap（多重映射表）
			//有序关联容器（红黑树，有序，增删查 O(log2n)）：set、multiset、map、multimap
	//近容器：数组、string、bitset
	//迭代器：
		//iterator 和 const_iterator
		//reverse_iterator 和 const_reverse_iterator
	//函数对象（类似 C 函数指针）：greater、less
	//泛型算法：sort、find、find_if、binary_search、for_each、...

//vector 容器
	//底层数据结构：动态开辟数组，每次以原来空间大小 2 倍扩容
	//vector<int> vec;
	//增加：
		//vec.push_back(20);末尾添加元素 O(1)，可能会导致容器扩容
		//vec.insert(it, 20);it 迭代器指向的位置添加一个元素 20 O(n)，可能会导致容器扩容
	//删除：
		//vec.pop_back();末尾删除元素 O(1)
		//vec.erase(it);删除 it 迭代器指向的元素 O(n)
	//查询：
		//operator[] 下标的随机访问 vec[5] O(1)
		//iterator 迭代器进行遍历
		//find、for_each
		//foreach，通过 iterator 来实现
	//对容器进行连续插入或者删除操作（insert/erase），一定要更新迭代器，否则第一次 insert/erase 完成后，迭代器就失效了
	//常用方法：
		//size()、empty()、reserve(20)：预留空间，但不会参加新的元素、resize(20)：扩容，预留空间，会参加新的元素、swap
	vector<int> vec;
	for (int i = 0; i < 20; i++)
	{
		vec.push_back(rand() % 100 + 1);
	}
	int size = vec.size();
	for (int i = 0; i < size; i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
	auto it1 = vec.begin();
	for (; it1 != vec.end(); ++it1)
	{
		cout << *it1 << " ";
	}
	cout << endl;
	//把 vec 容器中所有的偶数全部删除
	auto it2 = vec.begin();
	while (it2 != vec.end())
	{
		if (*it2 % 2 == 0)
		{
			it2 = vec.erase(it2);
		}
		else
		{
			++it2;
		}
	}
	it2 = vec.begin();
	for (; it2 != vec.end(); ++it2)
	{
		cout << *it2 << " ";
	}
	cout << endl;
	//把 vec 容器中所有的奇数前面都添加一个小于奇数 1 的偶数
	auto it3 = vec.begin();
	while (it3 != vec.end())
	{
		if (*it3 % 2 != 0)
		{
			it3 = vec.insert(it3, *it3 - 1);
			it3 = it3 + 2;
		}
		else
		{
			++it3;
		}
	}
	it3 = vec.begin();
	for (; it3 != vec.end(); ++it3)
	{
		cout << *it3 << " ";
	}
	cout << endl;
	vector<int>vec1;
	vec1.reserve(20);//reserve
	cout << vec1.empty() << endl;
	cout << vec1.size() << endl;
	for (int i = 0; i < 20; i++)
	{
		vec1.push_back(rand() % 100 + 1);
	}
	cout << vec1.empty() << endl;
	cout << vec1.size() << endl;
	auto it4 = vec1.begin();
	for (; it4 != vec1.end(); ++it4)
	{
		cout << *it4 << " ";
	}
	cout << endl;
	vector<int>vec2;
	vec2.resize(20);//resize
	cout << vec2.empty() << endl;
	cout << vec2.size() << endl;
	for (int i = 0; i < 20; i++)
	{
		vec2.push_back(rand() % 100 + 1);
	}
	cout << vec2.empty() << endl;
	cout << vec2.size() << endl;
	auto it5 = vec2.begin();
	for (; it5 != vec2.end(); ++it5)
	{
		cout << *it5 << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
*/