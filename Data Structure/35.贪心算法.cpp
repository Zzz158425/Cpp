#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

/*
//利用贪心算法思想非递归解决部分背包选择问题
struct Product
{
	double getPrice() const
	{
		return v * 1.0 / w;
	}
	bool operator >(const Product& p) const
	{
		return getPrice() > p.getPrice();
	}
	int id;//物品 ID
	int w;//物品的重量
	int v;//物品的价值
};

//利用贪心算法思想非递归解决柜台提供服务问题 2026.3.28
struct Counter
{
	bool operator <(const Counter& counter) const
	{
		return time < counter.time;
	}
	int id;//柜台 id
	int time;//柜台提供服务所花费时间
};

int main()
{
//贪心算法思想 2026.3.27
	//当一个问题具有最优子结构性质时，可以使用动态规划法求解，但有时候使用贪心算法更简单，更直接而且解决问题的效率很高
	//贪心算法总是做出在当前看来最好的选择，也就是说贪心算法并不从整体最优考虑，它所做出的选择只是在某种意义上的局部最优选择，当然最终希望贪心算法得到的最终结果也是最优的
	//虽然贪心算法不能对所有问题都得到整体最优解，但是对于很多问题它能够产生整体最优解，或者是趋近于最优解

//利用贪心算法思想非递归解决硬币选择问题
	//有 1 3 5 分面额的硬币，给定一个面值 11，组成给定面值所需要的最少的硬币数量是多少
	int arr[] = { 1,3,5 };
	int length = sizeof(arr) / sizeof(arr[0]);
	int c = 11;
	sort(arr, arr + length, [](int a, int b)->bool{return a > b; });
	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;
	int idx = 0;//5 3 1
	int cnt = 0;//记录硬币个数
	while (c > 0)
	{
		if (c > arr[idx])
		{
			cnt++;
			c -= arr[idx];
		}
		else
		{
			idx++;
		}
	}

//利用贪心算法思想非递归解决部分背包选择问题
	//部分背包问题，有 n 个物体，第 i 个物体的重量为 wi，价值为 vi，在总重量不超过 c 的情况下让总价值尽量高
	//每一个物体都可以只取走一部分，价值和重量按比例计算，求最大总价值int w10[] = { 8,6,4,2,5 };
	int w1[] = { 8,6,4,2,5 };
	int v1[] = { 6,4,7,8,6 };
	int c1 = 12;
	const int n1 = sizeof(w1) / sizeof(w1[0]);
	Product pros[n1];
	int x1[n1] = { 0 };
	for (int i = 0; i < n1; i++)
	{
		pros[i].id = i;
		pros[i].w = w1[i];
		pros[i].v = v1[i];
	}
	//按物品的性价比降序排列
	sort(pros, pros + n1, [](const Product& p1, const Product& p2)->bool {return p1 > p2; });//提供了 > 运算符重载函数，不需要 p1.getPrice() > p2.getPrice()
	//按性价比高的放入背包里面（只考虑局部的最优解）
	double bestv = 0;//记录背包最大价值
	for (int i = 0; i < n1; i++)
	{
		//第 i 个物品可以装入背包
		if (pros[i].w <= c1)
		{
			bestv += pros[i].v;
			c1 -= pros[i].w;
		}
		//第 i 个物品不可以全部装入背包，按剩余容量的比例装入物品的一部分
		else
		{
			bestv = bestv + pros[i].v * (c1 * 1.0 / pros[i].w);
			x1[pros[i].id] = 1;
			break;
		}
		x1[pros[i].id] = 1;
	}
	cout << "bestv:" << bestv << endl;
	for (int v : x1)
	{
		cout << v << " ";
	}
	cout << endl;

//利用贪心算法思想非递归解决柜台提供服务问题 2026.3.28
	//m 个柜台提供服务，每个柜台给一个用户提供服务的时间是 t（用数组表示每一个柜台提供服务的时间），怎么排列，使得柜台给所有用户提供服务的时间最少
	int arr2[] = { 3,2,4 };//每一个柜台提供服务的时间
	const int m2 = sizeof(arr2) / sizeof(arr2[0]);//柜台的数量
	int n2 = 15;//办理业务的人数
	//定义柜台信息数组，初始化柜台 id 与 time
	Counter cons[m2];
	for (int i = 0; i < m2; i++)
	{
		cons[i].id = i;
		cons[i].time = arr2[i];
	}
	sort(cons, cons + m2);//按照柜台提供服务的时间升序排列
	int mintime = 0;//记录给所有用户提供服务的最少时间
	int x[m2] = { 0 };//记录每一个柜台安排的用户数量
	for (int i = 0; i < n2; i++)
	{
		int time = cons[0].time * (x[0] + 1);//先计算把 i 用户放在 0 号柜台的时间
		//再遍历其他的柜台，看是否可以得到更少的花费时间
		int j = 1;
		for (; j < m2; j++)
		{
			int t = cons[j].time * (x[j] + 1);
			if (t <= time)
			{
				x[j]++;//放在其他柜台处理时间总体更快，直接放入 j 柜台
				//新添加了一个人，整体花费的时间有可能变得更长了
				if (t > mintime)
				{
					mintime = t;
				}
				break;
			}
		}
		//最终还是放在 0 号柜台花费时间最少
		if (j == m2)
		{
			x[0]++;
			mintime = cons[0].time * x[0];//新添加了一个人，整体花费的时间有可能变得更长了
		}
	}
	cout << "mintime:" << mintime << endl;
	for (int i = 0; i < m2; i++)
	{
		cout << arr2[cons[i].id] << ":" << x[i] << endl;
	}

	system("pause");
	return 0;
}
*/