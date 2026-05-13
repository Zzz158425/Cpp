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
//选择排序性能分析
void ChoiceSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		//设定初始 min，k
		int min = arr[i];
		int k = i;
		//遍历序列查找最小值
		for (int j = i + 1; j < size; j++)
		{
			if (min > arr[j])
			{
				min = arr[j];
				k = j;
			}
		}
		//找到后面剩余序列中的最小值，和开始位置的值进行交换
		if (k != i)
		{
			int temp = arr[i];
			arr[i] = arr[k];
			arr[k] = temp;
		}
	}
}

int main()
{
//选择排序原理 2026.2.6
	//将数组逻辑划分为有序区和无序区
	//初始状态：有序区为空，整个数组都是无序区
	//迭代流程：每一轮从无序区中找到最值元素（升序找最小值，降序找最大值），将它与无序区的第一个元素交换位置
	//区域更新：交换后，该最值元素被纳入有序区末尾，无序区范围缩小一位
	//终止条件：当无序区为空（所有元素都归入有序区），排序完成

//选择排序性能分析
	//特点：每次在剩下的元素中选择值最小的元素，和当前元素进行交换
	//缺点：相比于冒泡排序，交换的次数少了，但是比较的次数依然很多
	//平均时间复杂度：O(n^2)
		//最好时间复杂度：O(n^2)
		//最坏时间复杂度：O(n^2)
	//空间复杂度：没有申请任何的内存空间 O(1)
	//稳定性：不稳定，5(1) 5(2) 3 -> 3 5(2) 5(1)
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
	ChoiceSort(arr, 10);
	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
*/