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
//二分搜索算法非递归
int BinarySearch(int arr[], int size, int val)
{
	int first = 0;
	int last = size - 1;
	while (first <= last)
	{
		int mid = (first + last) / 2;
		if (arr[mid] == val)
		{
			return mid;//找到，返回元素所在下标
		}
		else if (arr[mid] > val)
		{
			last = mid - 1;
		}
		else
		{
			first = mid + 1;
		}
	}
	return -1;//没找到
}

//递归 2026.2.5
//阶层递归求解
int func1(int n)
{
	//递归结束条件
	if (n == 0 || n == 1)
	{
		return 1;
	}
	//递归
	else
	{
		return n * func1(n - 1);
	}
}

//二分搜索算法递归
int BinarySearch_recursion(int arr[], int i, int j, int val)
{
	//递归结束的条件
	if (i > j)
	{
		return -1;
	}
	int mid = (i + j) / 2;
	//递归
	if (arr[mid] == val)
	{
		return mid;
	}
	else if (arr[mid] > val)
	{
		return BinarySearch_recursion(arr, i, mid - 1, val);
	}
	else
	{
		return BinarySearch_recursion(arr, mid + 1, j, val);
	}

}
int BinarySearch_recursion(int arr[], int size, int val)
{
	return BinarySearch_recursion(arr, 0, size - 1, val);
}

int main()
{
//二分搜索算法非递归
	//有序序列才能使用二分搜索算法：定义指针 first 与 last 分别指向序列首/尾元素，每次与 middle = (first + last) / 2 进行比较，若 middle 不为搜索值，则调整 first 与 last位置，重新计算新的 middle 进行比较
	//12 25 34 39 45 57 63 78 82 96 100
	//线性搜索：O(n)
		//for (int i = 0; i < size; i++)
		//{
		//	if (arr[i] == val)
		//	{
		//		return i;
		//	}
		//}
		//return -1;
	int arr[] = { 12,25,34,39,45,57,63,78,82,96,100 };
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << BinarySearch(arr, size, 39) << endl;
	cout << BinarySearch(arr, size, 45) << endl;
	cout << BinarySearch(arr, size, 12) << endl;
	cout << BinarySearch(arr, size, 64) << endl;

//二分搜索算法时间复杂度
	//对数时间复杂度：O(logn)
	//12 25 34 39 45 57 63 78 82 96 100
	//               57
	//         34               82
	//    12        39     63         96
	//       25        45    78          100
	//二分搜索路径 = 二叉搜索树，即对上面这一颗 BST 树从 root 根节点开始搜索的过程，每一次搜索只会沿着这一条路径搜索下去
	//二分搜索算法的时间复杂度：上面这课 BST 树的 L 层数/高度，数据规模：2^0 + 2^1 + 2^2 + 2^3 + …… +2^( L - 1 ) = n = 2^L - 1 -> L = logn(忽略 1 )

//递归 2026.2.5
	//递：n -> n-1 -> …… -> 2 -> 1，归：1 -> 2 -> …… -> n-1 -> n
 	//递归：1.不管是什么数据规模，求解问题的方式是一样的；2.不同规模的数据，其计算结果是有关系可寻的；3.数据规模从 n -> n-1 -> …… -> 2-> 1，小到问题的答案是已知的或是可算出的
	//递归在形式上就是函数自己调用自己，递归问题的思考是水平方向上的，递归代码的具体执行是垂直方向上的
	//递归函数：1.一定要搞清楚递归函数的意义是什么？返回值、参数列表以及它能完成什么功能；2.一定有递归结束的条件；3.每个数据规模要写好他们之间的计算关系
	//以递归求阶层 4 为例：4 * func1(3) -> 4 * 3 * func1(2) -> 4 * 3 * 2 * func1(1) -> 4 * 3 * 2 * 1 * func1(0) ->  4 * 3 * 2 * 1 * 1
	cout << func1(4) << endl;

//二分搜索算法递归
	//数组的数据规模缩减依赖起始下标与末尾下标所在位置
	//BinarySearch_recursion(int arr[], int i, int j, int val) 在 arr 数组的 [i,j] 范围内，二分搜索值 val，找到的话返回下标，找不到返回 -1
	cout << BinarySearch_recursion(arr, size, 39) << endl;
	cout << BinarySearch_recursion(arr, size, 45) << endl;
	cout << BinarySearch_recursion(arr, size, 12) << endl;
	cout << BinarySearch_recursion(arr, size, 64) << endl;

	system("pause");
	return 0;
}
*/