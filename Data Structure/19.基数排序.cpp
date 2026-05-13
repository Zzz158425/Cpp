#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;

/*
//基数排序性能分析
void RadixSort(int arr[], int size)
{
	//找到最大的数
	int maxData = arr[0];
	for (int i = 1; i < size; i++)
	{
		if(abs(arr[i]) > maxData)
		{
			maxData = abs(arr[i]);//abs() 取数绝对值
		}
	}
	int len = to_string(maxData).size();//转为字符串获取最大数的长度
	vector<vector<int>> vecs;//创建桶
	int mod = 10;
	int dev = 1;
	for (int i = 0; i < len; mod *= 10, dev *= 10, i++)//O(d)：d 为数据长度
	{
		vecs.resize(20);//采用下标操作必须先设置 vecs 的大小，采用 20 个桶是为了处理负数：-9 ~ 9
		for (int j = 0; j < size; j++)//O(n)
		{
			//得到当前元素第 i 个位置的元素
			int index = arr[j] % mod / dev + 10;//0 ~ 9 号桶放负数，10 ~ 19 号桶放正数
			vecs[index].push_back(arr[j]);
		}
		//依次变量所有的桶，把元素拷贝会原始的数组当中
		int idx = 0;
		for (auto vec : vecs)//O(20)
		{
			for (int v : vec)//O(n)
			{
				arr[idx++] = v;
			}
		}
		vecs.clear();//清空桶供下一轮使用
	}
}

int main()
{
	//基数排序算法思想 2026.2.23
		//基数排序也称桶排序
		//找出最长的数字，确定要处理的桶排序的躺数（位数）
		//依次由个位开始处理，把相应位数上的数字，放入相应序号的桶里面，完成后，在按照桶的序号，依次取出桶里面的数据，放回原始的数组当中
		//当处理完所有的位数，最终得到有序的序列
		
	//基数排序性能分析
		//无法处理浮点数，需修改源码
		//平均时间复杂度：O(nd)
			//最好时间复杂度：O(nd)
			//最坏时间复杂度：O(nd)
		//空间复杂度：O(n)
		//稳定性：稳定
	int arr[10];
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 100 + 1;
	}
	arr[9] = -123;
	arr[6] = -38;
	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;
	RadixSort(arr, 10);
	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
*/

