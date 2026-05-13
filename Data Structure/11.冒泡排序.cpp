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
//冒泡排序性能分析
void BubbleSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)//比较趟数
	{
		bool flag = false;
		for (int j = 0; j < size - i - 1; j++)//每趟比较次数，如果 j < size - i，会使的 j 与 j + 1 进行比较产生溢出
		{
			if (arr[j] > arr[j + 1])
			{
				//交换
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = true;
			}
		}
		//优化：如果没有做任何的数据交换，那么说明数据已经有序了
		if (!flag)
		{
			return;
		}
	}
}

int main()
{
//冒泡排序原理
	//排序算法主要关注算法的时间复杂度（平均，最优，最差）和空间复杂度和稳定性。
	//基础规则：对待排序的数列重复遍历，两两比较相邻元素，如果两个元素的顺序不符合排序规则（升序 / 降序），就交换它们的位置；
	//每轮效果：每完成一轮完整遍历，当前无序区间内的最大元素会被交换到无序区间的末尾，确定最终位置；
	//终止条件：当某一轮遍历中没有发生任何元素交换，说明数列已经完全有序，排序结束。

//冒泡排序性能分析
	//特点：相邻元素两两比较，把值大的元素往下交换。
	//缺点：数据交换的次数太多了
	//平均时间复杂度：O(n^2)
		//最好时间复杂度：O(n)
		//最坏时间复杂度：O(n^2)
	//空间复杂度：没有申请任何的内存空间 O(1)
	//稳定性（在原始的数据排序中，相同元素经过排序后，他们的前后顺序并没有改变，就叫稳定，反之，对有键值队的数据进行排序时有影响）：稳定
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
	BubbleSort(arr, 10);
	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
*/