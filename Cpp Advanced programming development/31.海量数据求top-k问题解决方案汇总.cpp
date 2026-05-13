#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
//考察基本的数据求 top-k 问题思想应用
//快排分割函数
int partation(vector<int>& arr, int i, int j)
{
	int k = arr[i];
	while (i < j)
	{
		while (i < j && arr[j] >= k)
		{
			j--;
		}
		if (i < j)
		{
			arr[i++] = arr[j];
		}
		while (i < j && arr[i] < k)
		{
			i++;
		}
		if (i < j)
		{
			arr[j--] = arr[i];
		}
	}
	arr[i] = k;
	return i;
}
int selectNok(vector<int>& arr, int start, int end, int k)
{
	int pos = partation(arr, start, end);
	if (pos == k - 1)
	{
		return pos;
	}
	else if (pos < k - 1)
	{
		return selectNok(arr, pos + 1, end, k);
	}
	else
	{
		return selectNok(arr, start, pos - 1, k);
	}

}

int main()
{
//海量数据求 top-k 问题
	//1.求最大的/最小的前 k 个元素
	//2.求最大的/最小的第 k 个元素

//海量数据求 top-k 问题解法
	//1.大根堆（前 k 小）/小根堆（前 k 大）
		//先用前 k 个整数创建一个大（小）根堆（最大（小）值就在堆顶）
		//然后遍历剩下的整数，如果整数比堆顶元素小（大），那么删除堆顶元素（出堆）
		//再把整数入堆，遍历完所有整数，大（小）根堆里面放的就是值最小（大）的前 k 个元素了
		//如果找的是第 k 小（大），只需要访问堆顶一个元素就可以了
	//2.快排分割函数
		//经过快排分割函数，能够在 o(lgn) 时间内
		//把小于基准数的整数调整到左边，把大于基准数的整数调整到右边
		//基准数 (index) 就可以认为是第 (index + 1) 小的整数了
		//[0，(index)]就是前 index + 1 小的整数了

//考察基本的数据求 top-k 问题思想应用
	//利用小根堆求 vector 容器中元素值的前 10 大的数字
	vector<int> vec;
	for (int i = 0; i < 100000; i++)
	{
		vec.push_back(rand() + i);
	}
	priority_queue<int, std::vector<int>, std::greater<int>> minHeap;//定义小根堆
	//先往小根堆放入 10 个元素
	int k = 0;
	for (; k < 10; ++k)
	{
		minHeap.push(vec[k]);
	}
	//遍历剩下的元素依次和堆顶元素进行比较
	//如果比堆顶元素大，那么删除堆顶元素，把当前元素添加到小根堆中
	//元素遍历完成，堆中剩下的 10 个元素，就是值最大的 10 个元素
	for (; k < vec.size(); k++)
	{
		if (vec[k] > minHeap.top())
		{
			minHeap.pop();
			minHeap.push(vec[k]);
		}
	}
	//打印结果
	while (!minHeap.empty())
	{
		std::cout << minHeap.top() << " ";
		minHeap.pop();
	}
	cout << endl;
	//利用快排分割求 vector 容器中元素值的第 10 小的数字
	vector<int> vec1;
	for (int i = 0; i < 100000; i++)
	{
		vec.push_back(rand() + i);
	}
	int pos = selectNok(vec, 0, vec.size() - 1, 10);
	cout << vec1[pos] << endl;//第 10 小
	for (int i = 0; i <= pos; ++i)
	{
		cout << vec1[i] << endl;
	}
	//有一个大文件，里面放的是整数，内存限制 200M，求最大的前 10 个
		//采用分治的思想，计算一下整数文件的大小 / 200M = 要分的小文件的数量
		//哈希映射：整数 % 小文件的个数 = file index
		//现在每一个小文件就可以加载到内存当中了，对每一个小文件的整数求 top-k 元素了
		//合并所有小文件的结果即可

	system("pause");
	return 0;
}
*/