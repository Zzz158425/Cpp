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
//归并排序性能分析
//归并过程函数
void Merge(int arr[], int l, int m, int r)
{
	int* p = new int[r - l + 1];
	int idx = 0;
	int i = l;
	int j = m + 1;
	while (i <= m && j <= r)
	{
		if (arr[i] <= arr[j])
		{
			p[idx++] = arr[i++];
		}
		else
		{
			p[idx++] = arr[j++];
		}
	}
	//左边有剩余
	while (i <= m)
	{
		p[idx++] = arr[i++];
	}
	//右边有剩余
	while (j <= r)
	{
		p[idx++] = arr[j++];
	}
	//再把合并好的大端有序结果，拷贝到原始 arr 数组 [1, r] 区间内
	for (i = l, j = 0; i <= r; i++, j++)
	{
		arr[i] = p[j];
	}
	delete[]p;//释放内存
}
//归并排序递归接口
void MergeSort(int arr[], int begin, int end)
{
	//归并排序递归结束条件
	if (begin >= end)
	{
		return;
	}
	int mid = (begin + end) / 2;
	//先递
	MergeSort(arr, begin, mid);
	MergeSort(arr, mid + 1, end);
	//后归并，把 [begin, mid] 与 [mid + 1, end] 把两个小段有序的序列，合并成大端有序的序列
	Merge(arr, begin, mid, end);

}
void MergeSort(int arr[], int size)
{
	return MergeSort(arr, 0, size - 1);
}

int main()
{
//归并排序原理
	//也采用分治思想，先进行序列划分，再进行元素的有序合并

//归并排序性能分析
	//二路归并
	//平均时间复杂度：O(n*logn)
		//最好时间复杂度：O(n*logn)
		//最坏时间复杂度：O(n*logn)
	//空间复杂度：O(n) + O(logn)（取大值，可忽略）
	//稳定性：稳定
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
	MergeSort(arr, 10);
	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
*/