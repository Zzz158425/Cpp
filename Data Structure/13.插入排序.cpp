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
//插入排序性能分析
void InsertSort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int val = arr[i];//记录当前需要比较的数字
		int j = i - 1;
		//与前面排好序的序列进行逐个比较
		for (; j >= 0; j--)
		{
			if (arr[j] <= val)
			{
				break;
			}
			arr[j + 1] = arr[j];//将数往后挪
		}
		//将需要比较的数字挪到正确位置
		arr[j + 1] = val;
	}
}

int main()
{
//插入排序原理
	//如果数据趋于有序，那么插入排序是所有排序算法中，效率最高的排序算法
	//在基础排序算法中，插入排序 > 冒泡排序 & 选择排序
	//不仅没有交换，而且比较的次数也少

//插入排序性能分析
	//特点：从第二个元素开始，把前面的元素序列当作已经有序的，然后找合适的位置插入。
	//优点：插入排序是普通排序里面效率最高的排序算法，而且在数据越趋于有序的情况下，插入排序的效率是最高的。
	//平均时间复杂度：O(n^2)
		//最好时间复杂度：O(n)
		//最坏时间复杂度：O(n^2)
	//空间复杂度：没有申请任何的内存空间 O(1)
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
	InsertSort(arr, 10);
	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
*/