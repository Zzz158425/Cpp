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
//希尔排序性能分析
void ShellSort(int arr[], int size)
{
	for (int gap = size / 2; gap > 0; gap /= 2)//分组
	{
		for (int i = gap; i < size; i++)//对每组内元素进行排序
		{
			//对每组内元素进行插入排序
			int val = arr[i];
			int j = i - gap;
			for (; j >= 0; j -= gap)
			{
				if (arr[j] <= val)
				{
					break;
				}
				arr[j + gap] = arr[j];
			}
			arr[j + gap] = val;
		}
	}
}

//冒泡 选择 插入 希尔算法性能统计
//冒泡排序
void BubbleSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		bool flag = false;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = true;
			}
		}
		if (!flag)
		{
			return;
		}
	}
}
//选择排序
void ChoiceSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int min = arr[i];
		int k = i;
		for (int j = i + 1; j < size; j++)
		{
			if (min > arr[j])
			{
				min = arr[j];
				k = j;
			}
		}
		if (k != i)
		{
			int temp = arr[i];
			arr[i] = arr[k];
			arr[k] = temp;
		}
	}
}
//插入排序
void InsertSort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int val = arr[i];
		int j = i - 1;
		for (; j >= 0; j--)
		{
			if (arr[j] <= val)
			{
				break;
			}
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = val;
	}
}

int main()
{
//希尔排序原理 2026.2.7
	//增量（gap）定义：初始 gap 通常取数组长度的一半（gap = n / 2），之后每次缩小为gap = gap / 2，直到 gap = 1；
	//排序逻辑：每组内执行插入排序，逐步缩小 gap 后重复；
	//终止条件：gap = 1 时，完成最后一轮插入排序，数组完全有序。

//希尔排序性能分析
	//插入排序的效率最好，尤其是在数据已经趋于有序的情况下，采用插入排序效率最高。一般中等数据量的排序都用希尔排序，选择合适的增量序列，效率就已经不错了，如果数据量比较大，可以选择高级的排序算法，如快速排序
	//特点：可以看作是多路的插入排序，分组的数据越趋于有序，整体上的数据也越趋于有序，插入排序效率完美体现。
	//平均时间复杂度：依赖不同的增量序列设置 O(n^1.3)
		//最好时间复杂度：O(n)
		//最坏时间复杂度：O(n^2)
	//空间复杂度：O(1)
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
	ShellSort(arr, 10);
	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;

//冒泡 选择 插入 希尔算法性能统计
	const int COUNT = 100000;
	int* arr1 = new int[COUNT];
	int* arr2 = new int[COUNT];
	int* arr3 = new int[COUNT];
	int* arr4 = new int[COUNT];
	srand(time(NULL));
	for (int i = 0; i < COUNT; i++)
	{
		int val = rand() % COUNT + 1;
		arr1[i] = val;
		arr2[i] = val;
		arr3[i] = val;
		arr4[i] = val;
	}
	clock_t begin, end;
	begin = clock();
	BubbleSort(arr1, COUNT);
	end = clock();
	cout << "BubbleSort Spend:" << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;//将 clock() 返回的滴答数转换为直观的秒数，其中滴答数：时钟滴答数 / 时钟脉冲数
	begin = clock();
	ChoiceSort(arr2, COUNT);
	end = clock();
	cout << "ChoiceSort Spend:" << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;
	begin = clock();
	InsertSort(arr3, COUNT);
	end = clock();
	cout << "InsertSort Spend:" << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;
	begin = clock();
	ShellSort(arr4, COUNT);
	end = clock();
	cout << "ShellSort Spend:" << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;

	system("pause");
	return 0;
}
*/