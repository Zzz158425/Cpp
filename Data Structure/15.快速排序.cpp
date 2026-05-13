#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

/*
//快速排序性能分析
//快排分割处理函数
int Partation(int arr[], int l, int r)
{
	int val = arr[l];//记录基准数
	//快速排序 
	while (l < r)
	{
		//右往左找
		while (l < r && arr[r] > val)
		{
			r--;
		}
		if (l < r)
		{
			arr[l] = arr[r];
			l++;
		}
		//左往右找
		while (l < r && arr[l] < val)
		{
			l++;
		}
		if (l < r)
		{
			arr[r] = arr[l];
			r--;
		}
	}
	arr[l] = val;//放置基准数
	return l;//返回基准数位置
}
//快排递归接口
void QuickSort(int arr[], int begin, int end)
{
	//快排递归结束条件
	if (begin >= end)
	{
		return;
	}
	int pos = Partation(arr, begin, end);//快排分割
	//对基准数的左边和右边的序列，再分别进行快排
	QuickSort(arr, begin, pos - 1);
	QuickSort(arr, pos + 1, end);
}
void QuickSort(int arr[], int size)
{
	return QuickSort(arr, 0, size - 1);
}

//快速排序优化
int Partation_optimize(int arr[], int l, int r)
{
	int val = arr[l];//记录基准数
	//快速排序 
	while (l < r)
	{
		//右往左找
		while (l < r && arr[r] > val)
		{
			r--;
		}
		if (l < r)
		{
			arr[l] = arr[r];
			l++;
		}
		//左往右找
		while (l < r && arr[l] < val)
		{
			l++;
		}
		if (l < r)
		{
			arr[r] = arr[l];
			r--;
		}
	}
	arr[l] = val;//放置基准数
	return l;//返回基准数位置
}
//快排递归接口
void QuickSort_optimize(int arr[], int begin, int end)
{
	//快排递归结束条件
	if (begin >= end)
	{
		return;
	}
	//优化一：当 [begin, end] 序列的元素个数小到指定数量，采用插入排序
	//if (end - begin <= 50)
	//{
	//	InserSort(arr, begin, end);
	//	return;
	//}
	int pos = Partation_optimize(arr, begin, end);//快排分割
	//对基准数的左边和右边的序列，再分别进行快排
	QuickSort_optimize(arr, begin, pos - 1);
	QuickSort_optimize(arr, pos + 1, end);
}
void QuickSort_optimize(int arr[], int size)
{
	return QuickSort_optimize(arr, 0, size - 1);
}

int main()
{
//快速排序原理 2026.2.8
	//每次选择基准数，把小于基准数的放到基准数的左边，把大于基准数的放到基准数的右边，然后对基准数左边和右边的序列继续进行这样的操作，直到整个序列变为有序序列

//快速排序性能分析
 	//快速排序走的路径可以看做为一颗二叉树，数的层高 L = logn
	//32 8 7 10 38 (46) 68 76 65 53       （顶层）
	//10 8 7 (32) 38    53 65 (68) 76     （一层）
	//7 8 (10)    (38)    (53) 65    (76) （二层）
	//(7)  8              (65)            （三层）
	//(8)                                 （四层）
	//平均时间复杂度：O(n) * O(logn) = O(nlogn)
		//最好时间复杂度：O(n) * O(logn) = O(nlogn)
		//最坏时间复杂度：O(n) * O(n) = O(n^2)
	//空间复杂度：O(logn) ~ O(n)，递归的深度所占用的栈内存 
	//稳定性：不稳定
	int arr[10];
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 100 + 1;
	}
	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;
	QuickSort(arr, 10);
	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;

//快速排序优化
	//算法效率提升：
		//1、随着快排算法执行，数据越来越趋于有序，对于小段趋于有序的序列采用插入排序
		//2、三数取中法：mid = (L + R) / 2，取 L R mid 数值为中的数，旨在挑选合适的基准数，防止快排退化成冒泡排序
		//3、随机数法

	system("pause");
	return 0;
}
*/