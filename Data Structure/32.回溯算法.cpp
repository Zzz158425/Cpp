#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
#include<cmath>
#include<vector>
using namespace std;

/*
//回溯算法思想 2026.3.20
void func(int arr[], int i, int length, int x[])
{
	if (i == length)//递归结束的条件
	{
		for (int j = 0; j < length; ++j)
		{
			if (x[j] == 1)
			{
				cout << arr[j] << " ";
			}
			
		}
		cout << endl;
	}
	else
	{
		x[i] = 1;//选择 i 节点
		func(arr, i + 1, length, x);//A 遍历 i 的左孩子
		x[i] = 0;//不选择 i 节点
		func(arr, i + 1, length, x);//B 遍历 i 的右孩子
		//for (int k = 1; k >= 0; --k) 也可以这样写，不推荐
		//{
		//	x[i] = k;
		//	func(arr, i + 1, length, x);
		//}
	}
}

//回溯算法求整数选择问题
int arr1[] = { 12,6,7,11,16,3,9 };
const int length1 = sizeof(arr1) / sizeof(arr1[0]);
//int x1[length1] = { 0 };//子集树辅助函数，记录节点的左孩子还是右孩子
//int bestx[length1] = { 0 };//记录最优解
vector<int> x1;//可采用 vector 容器
vector<int> bestx1;
unsigned int min1 = 0xFFFFFFFF;//记录最小的差值
int sum = 0;//记录所选子集数字的总和
int r = 0;//记录未选择数字的和
//生成子集树
void func1(int i)
{
	if (i == length1)//递归结束的条件
	{
		int result = abs(sum - r);
		if (result < min1)
		{
			min1 = result;
			//需要记录一下差值最小的子集
			//for (int j = 0; j < length1; j++)
			//{
			//	bestx[j] = x1[j];
			//}
			bestx1 = x1;
		}
	}
	else
	{
		r -= arr1[i];//记录未选子集数字的总和
		sum += arr1[i];//记录所选子集数字的总和
		//x1[i] = 1;//选择 i 节点
		x1.push_back(arr1[i]);
		func1(i + 1);//遍历 i 的左孩子
		sum -= arr1[i];//回退
		r += arr1[i];//回退
		//x1[i] = 0;//不选择 i 节点
		x1.pop_back();
		func1(i + 1);//遍历 i 的右孩子
	}
}

//回溯算法求 2N 整数选择问题，利用剪枝提升算法效率
int arr2[] = { 12,6,7,11,16,3,8,4 };
const int length2 = sizeof(arr2) / sizeof(arr2[0]);
vector<int> x2;//子集树辅助函数，记录节点的左孩子还是右孩子
vector<int> bestx2;//记录最优解
unsigned int min2 = 0xFFFFFFFF;//记录最小的差值
int sum2 = 0;//记录所选子集数字的总和
int r2 = 0;//记录未选择数字的和
int left2 = length2;//记录未处理的数字的个数
int cnt2 = 0;//记录遍历的子集的个数，用于测试
//生成子集树
void func2(int i)
{
	if (i == length2)//递归结束的条件
	{
		cnt2++;
		if (x2.size() != length2 / 2)
		{
			return;
		}
		int result = abs(sum2 - r2);
		if (result < min2)
		{
			min2 = result;
			bestx2 = x2;
		}
	}
	else
	{
		left2--;//表示处理了一个节点，表示剩余的未处理的元素的个数
		if (x2.size() < length2 / 2)//剪左树枝，提高算法效率，选择数字的前提：还未选择够 N 个数字
		{
			r2 -= arr2[i];//记录未选子集数字的总和
			sum2 += arr2[i];//记录所选子集数字的总和
			x2.push_back(arr2[i]);
			func2(i + 1);//遍历 i 的左孩子，选择 i 号位元素
			sum2 -= arr2[i];//回退
			r2 += arr2[i];//回退
			x2.pop_back();
		}
		if (x2.size() + left2 >= length2 / 2)//剪右树枝，提高算法效率，已选择的数字的个数 + 未来能选择的所有的数字的个数 >= N 个元素
		{
			func2(i + 1);//遍历 i 的右孩子，不选择 i 号位元素
		}
		left2++;//当前 i 节点已处理完成，回溯到其父节点
	}
}

//回溯算法求挑数字问题
//法一
int arr3[] = { 4,8,12,16,7,9,3 };
const int length3 = sizeof(arr3) / sizeof(arr3[0]);
int number3 = 18;
vector<int> x3;//记录所选数字
int sum3 = 0;//记录所选数字和
int cnt3 = 0;//记录遍历的子集的个数，用于测试
int r3 = 0;//记录未处理，与未选择不同
//生成子集树
void func3(int i)
{
	if (i == length3)
	{
		cnt3++;
		if (number3 != sum3)
		{
			return;
		}
		for (int v : x3)
		{
			cout << v << " ";
		}
		cout << endl;
	}
	else
	{
		r3 -= arr3[i];
		if (sum3 + arr3[i] <= number3)//左剪枝，已选择的数字的和 + 即将要选择的数字
		{
			sum3 += arr3[i];
			x3.push_back(arr3[i]);
			func3(i + 1);
			sum3 -= arr3[i];
			x3.pop_back();
		}
		if (sum3 + r3 >= number3)//右剪枝，已选择的数字的和 + 剩余的可以被选择的数字的和
		{
			func3(i + 1);
		}
		r3 += arr3[i];
	}
}
//法二
int arr4[] = { 4,8,12,16,7,9,3 };
const int length4 = sizeof(arr4) / sizeof(arr4[0]);
int number4 = 18;
vector<int> x4;
int cnt4 = 0;
void func4(int i, int number4)
{
	if (number4 == 0)
	{
		cnt4++;
		for (int v : x4)
		{
			cout << v << " ";
		}
		cout << endl;
	}
	else
	{
		//以当前节点开始，把剩余元素的节点的孩子节点生成
		for (int k = i; k < length4; k++)
		{
			if (number4 >= arr4[k])//如果 number < arr4[k]，number4 == 0 不会成立，只有 number >= arr[k]，才可能使 number4 == 0 成立
			{
				x4.push_back(arr4[k]);
				//若 arr4[] 有重复的元素，当千层遍历到下一次的时候，arr[k] != arr[k - 1]
				//不允许重复选择元素
				func4(k + 1, number4 - arr4[k]);//遍历孩子节点，arr[k] 的孩子节点
				//允许重复选择元素
				//func4(k, number4 - arr4[k]);
				x4.pop_back();
			}
		}
	}
}

//回溯算法求背包问题
int w[] = { 12,5,8,9,6 };//物品的重量
const int length5 = sizeof(w) / sizeof(w[0]);
int v[] = { 9,2,4,7,8 };//物品的价值
int c = 20;//背包容量
int cw = 0;//已选择物品的重量
int cv = 0;//已选择物品的价值
vector<int> x5;//选择的物品
vector<int> bestx5;//记录最优选择物品
int cnt5 = 0;//记录遍历的子集的个数，用于测试
int r5 = 0;//已未选择物品的重量
int bestv = 0;//记录装入背包的物品的最大价值
//生成子集树
void func5(int i)
{
	if (i == length5)
	{
		cnt5++;
		if (bestv < cv)
		{
			bestv = cv;
			bestx5 = x5;
		}
		
	}
	else
	{
		r5 -= v[i];
		if (w[i] + cw <= c)//左剪枝，已选择的物品的重量 + 即将要选择的第 i 号物品的重量
		{
			cw += w[i];
			cv += v[i];
			x5.push_back(w[i]);
			func5(i + 1);
			cw -= w[i];
			cv -= v[i];
			x5.pop_back();
		}
		if (w[i] + r5 >= c)
		{
			func5(i + 1);
		}
		r5 += v[i];
	}
}

//解空间-排列树
int cnt6 = 0;//记录遍历的子集的个数，用于测试
void swap(int arr6[], int i, int j)
{
	int temp = arr6[i];
	arr6[i] = arr6[j];
	arr6[j] = temp;
}
void func6(int arr6[], int i, int length6)
{
	if (i == length6)
	{
		cnt6++;
		for (int v = 0; v < length6; ++v)
		{
			cout << arr6[v] << " ";
		}
		cout << endl;
	}
	else
	{
		//生成 i 节点的所以孩子节点
		for (int k = i; k < length6; k++)
		{
			swap(arr6, i, k);
			func6(arr6, i + 1, length6);//生成孩子节点
			swap(arr6, i, k);//归时需交换回来
		}
	}
}

//回溯算法求八皇后问题
int cnt7 = 0;//记录遍历的子集的个数，用于测试
bool judge(int arr7[], int i)//i 表示当前放置皇后旗子的位置
{
	for (int j = 0; j < i; j++)
	{
		if (i == j || arr7[i] == arr7[j] || abs(i - j) == abs(arr7[i] - arr7[j]))//斜线上表示：行减行等于列减列
		{
			return false;
		}
	}
	return true;
}
void func7(int arr7[], int i, int length7)
{
	if (i == length7)
	{
		cnt7++;
		for (int j = 0; j < length7; j++)
		{
			cout << arr7[j] << " ";
		}
		cout << endl;
	}
	else
	{
		//生成 i 节点的所以孩子节点
		for (int k = i; k < length7; k++)
		{
			swap(arr7, i, k);
			if (judge(arr7, i))//判断第 i 个位置的元素，是否满足八皇后的条件
			{
				func7(arr7, i + 1, length7);//生成孩子节点
			}
			swap(arr7, i, k);//归时需交换回来
		}
	}
}

//基于穷举法的全排列实现
int arr8[] = { 1,2,3 };
const int N = 3;
bool state[N];//记录所有元素是否被选择的状态，true：选择了，false：未选择
vector<int> vec;
int cnt8 = 0;
void func8(int i)
{
	if (i == N)
	{
		cnt8++;
		for (int v : vec)
		{
			cout << v << " ";
		}
		cout << endl;
	}
	else
	{
		for (int k = 0; k < N; k++)
		{
			if (!state[k])
			{
				state[k] = true;
				vec.push_back(arr8[k]);
				func8(i + 1);//k 表示的是可选择的元素的起始下标，i 表示层数
				vec.pop_back();
				state[k] = false;
			}
		}
	}
}

int main()
{
//回溯算法思想 2026.3.20
	//算法思想：
		//1.在包含问题的所有解的解空间树中，按照深度优先搜索的策略，从根节点出发深度搜索解空间树
		//2.当搜索到某一节点时，要先判断该节点是否包含问题的解，如果包含就从该节点出发继续深度搜索下去，否则逐层向上回溯
		//3.一般在搜索的过程中都会添加相应的剪枝函数，避免无效解的搜索，提高算法效率
	//解空间：
		//1.解空间就是所有解的可能取值构成的空间，一个解往往包含了得到这个解的每一步，往往就是对应解空间树中一条从根节点到叶子节点的路径
		//2.子集树和排列树都是一种解空间，它们不是真实存在的数据结构，也就是说并不是真的有这样一颗树，只是抽象出的解空间树
	//解空间-子集树：
		//以 func 递归打印为例：                main::func
		//                                 1.main::A::func i = 2
		//                                 12.main::B::func i = 2
		//                    1/                                          \0 
		//              2.A::func i = 2                                13.A::func i = 2        
		//              7.B::func i = 2                                18.B::func i = 2        
		//         1/                    \0                               1/               \0
		//  3.A::func i = 2           8.A::func i = 2             14.A::func i = 2         19.A::func i = 2
		//  5.B::func i = 2           10.B::func i = 2            16.B::func i = 2         21.B::func i = 2
		//    1/         \0              1/         \0                 1/         \0              1/       \0         
		//4.fun i = 3  6.fun i = 3  9.fun i = 3  11.fun i = 3  15.fun i = 3  17.fun i = 3  20.fun i = 3  22.fun i = 3
		//1,2,3        1,2,3        1,2,3        1,2,3         1,2,3         1,2,3         1,2,3         1,2,3
	//子集树解决问题：打印 1 2 3 子集：1 2 3 12 13 23 123
	//规定往左走为 1，往右走为 0
	int arr[] = { 1,2,3 };
	int length = sizeof(arr) / sizeof(arr[0]);
	int x[3] = { 0 };
	func(arr, 0, length, x);

//回溯算法求整数选择问题
	//给定一组整数，从里面挑选出一组整数，让选择的整数的和，和剩下的整数的和的差最小
	for (int v : arr1)
	{
		r += v;
	}
	func1(0);
	//for (int i = 0; i < length1; i++)
	//{
	//	if (bestx[i] == 1)
	//	{
	//		cout << arr1[i] << " ";
	//	}
	//}
	for (int v : bestx1)
	{
		cout << v << " ";
	}
	cout << endl;
	cout << "min1:" << min1 << endl;

//回溯算法求 2N 整数选择问题，利用剪枝提升算法效率
	//给定 2N 个整数，从里面挑选出 N 个整数，让选择的整数的和，和剩下的整数的和的差最小
	for (int v : arr2)
	{
		r2 += v;
	}
	func2(0);
	for (int v : bestx2)
	{
		cout << v << " ";
	}
	cout << endl;
	cout << "min2:" << min2 << endl;
	cout << "cnt2:" << cnt2 << endl;

//回溯算法求挑数字问题
	//有一组整数，请挑选选出一组数字，让他们的和等于指定的值，存在即打印																																																	
	//法一，普通回溯
	for (int v : arr3)
	{
		r3 += v;
	}
	func3(0);
	cout << "cnt3:" << cnt3 << endl;
	//法二，穷举递归
		//                          4 8 12 16 7 9 3
		//                          /              \
		//                         4                ... 
		//                     /  /  /  \  \  \  
 		//                     8  12  16  7  9  3      
		//           /  /  |  \  \   ...
		//         12  16  7   9  3
		//       / / \ \   ...
		//      16 7 9  3
		//    / | \   ...
		//   7  9  3
		//  /\   ...
		//  9 3
		//  |
		//  3
		
	func4(0, number4);
	cout << "cnt4:" << cnt4 << endl;

//回溯算法求背包问题
	//有一组物品，其重量分别是：w1,w2,...,wn，其价值分别是 v1,v2,...,vn，现在有一个背包，其容量是 C，如何使背包的价值最大化
	for (int v : w)
	{
		r5 += v;
	}
	func5(0);
	for (int v : bestx5)
	{
		cout << v << " ";
	}
	cout << endl;
	cout << "bestv:" << bestv << endl;
	cout << "cnt5:" << cnt5 << endl;

//解空间-排列树
	//以 1 2 3 4 为例
	//                            1 2 3 4
	//                    /        /   \         \
	//             1 2 3 4   2 1 3 4   3 2 1 4   4 2 3 1（将 1 与 1 2 3 4 进行交换）
	//           /    |    \   
	//    1 2 3 4  1 3 2 4  1 4 3 2（1 固定，将 2 与 2 3 4 进行交换） ...
	//     /   \     
	//1 2 3 4  1 2 4 3（1 2 固定，将 3 与 3 4 进行交换） ...
	//   |
	//1 2 3 4（1 2 3 固定，将 4 与 4 进行交换） ...
	//一个叶子节点就代表了原序列的一种排列的可能，所有叶子节点总和，就是原序列的全部排序方式
	//时间复杂度：O(n!)
	int arr6[] = { 1,2,3,4 };
	int length6 = sizeof(arr6) / sizeof(arr6[0]);
	func6(arr6, 0, length6);
	cout << "cnt6:" << cnt6 << endl;
		
//回溯算法求八皇后问题
	//在 8×8 棋盘上放 8 个皇后，保证两两不同行、不同列、不同斜线，求所有合法摆法
	int arr7[] = { 1,2,3,4,5,6,7,8 };//把 arr 数组的下标当做行，下标对应的元素的值当做列
	int n = 8;
	func7(arr7, 0, n);
	cout << "cnt7:" << cnt7 << endl;

//基于穷举法的全排列实现
	//       1 2 3
	//    /    |    \
	//    1    2    3
	//   / \  / \  / \
	//  2  3  1  3 1  2
	// /   / /  /  /  /
	// 3  2  3  2  2  1
	func8(0);
	cout << "cnt8:" << cnt8 << endl;

	system("pause");
	return 0;
}
*/