#include<iostream>
#include<typeinfo>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
//2026.3.8

/*
//泛型算法和绑定器
template<typename T>
class mygreater
{
public:
	bool operator()(T a, T b)
	{
		return a > b;
	}
};

int main()
{
//泛型算法
	//泛型算法 = template + 迭代器 + 函数对象
	//头文件 #include<algorithm> 包含了 C++ STL 里面的泛型算法
	//泛型算法的参数接收的都是迭代器
	//泛型算法的参数还可以接收函数对象（区别 C 函数指针）
	//常用泛型算法：sort、find、find_if、binary_search、for_each
	int arr[] = { 12,4,78,9,21,43,56,52,42,31 };
	vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));//arr 起始位置地址，arr + sizeof(arr) / sizeof(arr[0]) 末尾后继位置地址
	for (int v : vec)
	{
		cout << v << " ";
	}
	cout << endl;
	//传入函数对象 greater，改变容器元素排序时的比较方式
	sort(vec.begin(), vec.end(), mygreater<int>());
	sort(vec.begin(), vec.end(), greater<int>());//也可以使用 C++ 自带的函数对象
	for (int v : vec)
	{
		cout << v << " ";
	}
	cout << endl;
	sort(vec.begin(), vec.end());
	for (int v : vec)
	{
		cout << v << " ";
	}
	cout << endl;
	if (binary_search(vec.begin(), vec.end(), 21))//有序查找元素，二分搜索 binary_search 最佳，但必须是升序，否则会查找失败，O(log2n)
	{
		cout << "21 存在" <<endl;
	}
	else
	{
		cout << "21 不存在" << endl;
	}
	auto it1 = find(vec.begin(), vec.end(), 21);//find O(n)
	if (it1 != vec.end())
	{
		cout << "find 21 存在" << endl;
	}
	sort(vec.begin(), vec.end(), greater<int>());//greater<int> 为二元函数对象
	for (int v : vec)
	{
		cout << v << " ";
	}
	cout << endl;

//绑定器
	//头文件 #include<functional> 包含了函数对象和绑定器
	//bind1st：把二元函数对象的 operator() 的第一个形参绑定起来
	//bind2nd：把二元函数对象的 operator() 的第二个形参绑定起来
	//绑定器 + 二元函数对象 -> 一元函数对象
	//将 48 按序插入 vector 容器中，找第一个小于 48 的数字
		//78 56 52 43 42 31 21 12 9 4
		//find_if 每次取 1 个数字进行比较，需要的是一个函数对象
	auto it2 = find_if(vec.begin(), vec.end(), bind1st(greater<int>(), 48));//greater a > b -> 48 > b
	//auto it2 = find_if(vec.begin(), vec.end(), bind2nd(less<int>(), 48));//less a < b -> a < 48
	//auto it2 = find_if(vec.begin(), vec.end(), [](int val)->bool { return val < 48; });//lambda 表达式：[]（是否捕获外部变量，[] 表示不捕获）(int val)（形参变量）->bool（返回布尔值）{ return val < 48; }（拿捕获的变量进行比较）
	vec.insert(it2, 48);
	for (int v : vec)
	{
		cout << v << " ";
	}
	cout << endl;
	for_each(vec.begin(), vec.end(), //for_each 可以遍历容器的所有元素，可以自行添加合适的函数对象容器的元素进行过滤
		[](int val)->void 
		{
			if (val % 2 == 0) 
			{ 
				cout << val << " "; 
			}
		});
	cout << endl;

	system("pause");
	return 0;
}
*/