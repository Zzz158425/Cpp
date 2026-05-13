#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
#include<list>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
using namespace std;

/*
//快排分割解决 top-k 问题算法实现
//快排分割函数
//统计重复次数最小的前 3 个数字
int Partation_min(int arr[], int begin, int end)
{
	int val = arr[begin];
	int i = begin;
	int j = end;
	while (i < j)
	{
		//右边一直找小于基准数的数
		while (i < j && arr[j] > val)
		{
			j--;
		}
		//找到与左边交换位置
		if (i < j)
		{
			arr[i] = arr[j];
			i++;
		}
		//左边一直找大于基准数的数
		while (i < j && arr[i] < val)
		{
			i++;
		}
		//找到与右边交换位置
		if (i < j)
		{
			arr[j] = arr[i];
			j--;
		}
	}
	arr[i] = val;
	return i;
}
//统计重复次数最大的前 3 个数字
int Partation_max(int arr[], int begin, int end)
{
	int val = arr[begin];
	int i = begin;
	int j = end;
	while (i < j)
	{
		//右边一直找大于基准数的数
		while (i < j && arr[j] < val)
		{
			j--;
		}
		//找到与左边交换位置
		if (i < j)
		{
			arr[i] = arr[j];
			i++;
		}
		//左边一直找小于基准数的数
		while (i < j && arr[i] > val)
		{
			i++;
		}
		//找到与右边交换位置
		if (i < j)
		{
			arr[j] = arr[i];
			j--;
		}
	}
	arr[i] = val;
	return i;
}
//求 top-k 函数
//统计重复次数最小的前 3 个数字	
void SelectTopK_min(int arr[], int begin, int end, int k)
{
	int pos = Partation_min(arr, begin, end);
	if (pos == k - 1)
	{
		return;
	}
	else if (pos > k - 1)
	{
		SelectTopK_min(arr, begin, pos - 1, k);
	}
	else
	{
		SelectTopK_min(arr, pos + 1, end, k);
	}
	
}
//统计重复次数最大的前 3 个数字
void SelectTopK_max(int arr[], int begin, int end, int k)
{
	int pos = Partation_max(arr, begin, end);
	if (pos == k - 1)
	{
		return;
	}
	else if (pos > k - 1)
	{
		SelectTopK_max(arr, begin, pos - 1, k);
	}
	else
	{
		SelectTopK_max(arr, pos + 1, end, k);
	}

}

int main()
{
//大/小根堆解决 top-k 问题算法思想
	//利用大根堆过滤前 top-k 小的数据；小根堆过滤前 top-k 大的数据
	//需要用一个大根堆（只有 k 个元素）堆顶元素的值是最大的，把大根堆堆顶的大值不断淘汰，放入小值
	//以 64 45 52 80 66 68 0 2 18 75 序列，求最小的前 3 个元素为例，求最大的前 3 个元素同理
		//   64            52          45          18
		//45    52 ---> 45    0 ---> 0    2 ---> 0    2 
	//时间复杂度：O(logk) * O(n) -> O(n)

//大/小根堆解决 top-k 问题算法实现
	vector<int> vec;
	srand(time(NULL));
	for (int i = 0; i < 1000; i++)
	{
		vec.push_back(rand() % 10000);
	}
	//求 vec 中值最小的前 5 个元素
	priority_queue<int> maxheap;
	int k = 5;
	//前 k 个元素构建一个大根堆
	for (int i = 0; i < k; i++)
	{
		maxheap.push(vec[i]);
	}
	//遍历剩余的元素
	for (int j = 5; j < vec.size(); j++)
	{
		if (maxheap.top() > vec[j])
		{
			maxheap.pop();
			maxheap.push(vec[j]);
		}
	}
	while (!maxheap.empty())
	{
		cout << maxheap.top() << " ";
		maxheap.pop();
	}
	cout << endl;
	//求 vec 中值最大的前 5 个元素
	priority_queue<int, vector<int>, greater<int>> minheap;
	int k1 = 5;
	for (int i = 0; i < k1; i++)
	{
		minheap.push(vec[i]);
	}
	for (int j = 5; j < vec.size(); j++)
	{
		if (minheap.top() < vec[j])
		{
			minheap.pop();
			minheap.push(vec[j]);
		}
	}
	while (!minheap.empty())
	{
		cout << minheap.top() << " ";
		minheap.pop();
	}
	cout << endl;
	//查重与 top-k 综合
	vector<int> vec1;
	srand(time(NULL));
	for (int i = 0; i < 10000; i++)
	{
		vec1.push_back(rand() % 1000);
	}
	//统计重复次数最小的前 3 个数字
	unordered_map<int, int> map;
	for (auto key : vec1)
	{
		auto it = map.find(key);
		if (it == map.end())
		{
			map.insert({ key,1 });
		}
		else
		{
			it->second++;
		}
		//map[key]++;精简
	}
	using Type = pair<int, int>;
	using Comp = function<bool(Type&, Type&)>;//明确指定比较函数的类型，返回值是 bool，接受两个类型为 Type& 的参数
	priority_queue<Type, vector<Type>, Comp> maxheap1(//lambda 表达式，使大根堆依赖 value 值来排序
		[](Type& a, Type& b)->bool {
			return a.second < b.second;
		});
	int k2 = 3;
	auto it1 = map.begin();
	for (int i = 0; i < k2; i++,++it1)
	{
		maxheap1.push(*it1);
	}
	for (; it1 != map.end(); ++it1)
	{
		if (maxheap1.top().second > it1->second)
		{
			maxheap1.pop();
			maxheap1.push(*it1);
		}
	}
	while (!maxheap1.empty())
	{
		cout << "key: " << maxheap1.top().first
			<< " cnt: " << maxheap1.top().second << endl;
		maxheap1.pop();
	}
	//统计重复次数最大的前 3 个数字
	priority_queue<Type, vector<Type>, Comp> minheap1(
		[](Type& a, Type& b)->bool {
			return a.second > b.second;
		});
	int k3 = 3;
	auto it2 = map.begin();
	for (int i = 0; i < k3; i++, ++it2)
	{
		minheap1.push(*it2);

	}
	for (; it2 != map.end(); ++it2)
	{
		if (minheap1.top().second < it2->second)
		{
			minheap1.pop();
			minheap1.push(*it2);
		}
	}
	while (!minheap1.empty())
	{
		cout << "key: " << minheap1.top().first
			<< " cnt: " << minheap1.top().second << endl;
		minheap1.pop();
	}

//快排分割解决 top-k 问题算法思想 2026.3.12
	//利用快排分割函数每次返回的基准数的位置，找出前 top-k 大的或者前 top-k 小的数据
	//以 64 45 52 80 66 68 0 2 18 75 找最小的前 2 个元素为例
		//18 45 52 2 0 (64) 68 66 80 75
		//0 2 (18) 52 45
		//若求前 k 小的 k 比 基准数 64 小，则继续对基准数左边进行快排，直到基准数的位置等于 k - 1
		//若求前 k 小的 k 比 基准数 64 大，则对基准数右边进行快排，直到基准数的位置等于 k - 1

//快排分割解决 top-k 问题算法实现	
	//统计重复次数最小的前 3 个数字
	int arr[] = { 64,45,52,80,66,68,0,2,18,75 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int k4 = 3;
	SelectTopK_min(arr, 0, size - 1, k4);
	for (int i = 0; i < k4; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	//统计重复次数最大的前 3 个数字
	int arr1[] = { 64,45,52,80,66,68,0,2,18,75 };
	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	int k5 = 3;
	SelectTopK_max(arr1, 0, size1 - 1, k5);
	for (int i = 0; i < k5; i++)
	{
		cout << arr1[i] << " ";
	}
	cout << endl;
	
	system("pause");
	return 0;
}
*/
