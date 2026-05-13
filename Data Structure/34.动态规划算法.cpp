#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

/*
//利用动态规范算法思想递归解决硬币选择问题
//分治算法
//n 表示面值，返回值表示组成面值 n 所需要的最少的硬币数量
int func(int n)
{
	if (n == 1 || n == 3 || n == 5)
	{
		return 1;
	}
	else if (n == 2 || n == 4)
	{
		return 2;
	}
	else
	{
		int n1 = func(n - 1) + 1;//选择了 1 分硬币
		int n2 = func(n - 3) + 1;//选择了 3 分硬币
		int n3 = func(n - 5) + 1;//选择了 5 分硬币
		return min({ n1,n2,n3 });//return min(min(n1, n2), n3)
	}
}
//动态规划
const int n1 = 100;
int dp[n1 + 1] = { 0 };//dp[n] 组成价值 n 需要的硬币最少数量
int cnt1 = 0;
int func1(int n)
{
	if (dp[n] > 0)//dp[n] 这个子问题已经被求解过了
	{
		cnt1++;
		return dp[n];
	}
	if (n == 1 || n == 3 || n == 5)
	{
		dp[n] = 1;//代表了一个子问题最优解的性质（状态）
		return 1;
	}
	else if (n == 2 || n == 4)
	{
		dp[n] = 2;
		return 2;
	}
	else
	{
		int n1 = func1(n - 1) + 1;//选择了 1 分硬币
		int n2 = func1(n - 3) + 1;//选择了 3 分硬币
		int n3 = func1(n - 5) + 1;//选择了 5 分硬币
		dp[n] = min({ n1,n2,n3 });
		return dp[n];
	}
}

//利用动态规范算法思想递归解决斐波那契数列问题
//分治算法
int fibonacci(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}
//动态规划
int fibonacci1(int n4,int dp4[])
{
	if (dp4[n4] > 0)
	{
		return dp4[n4];
	}
	if (n4 == 1 || n4 == 2)
	{
		dp4[n4] = 1;
		return 1;
	}
	else
	{
		dp4[n4] = fibonacci1(n4 - 1, dp4) + fibonacci1(n4 - 2, dp4);
		return dp4[n4];
	}
}

//利用动态规范算法思想递归解决最长非降子序列 LCS 问题 2026.3.25
//分治算法
int cnt7 = 0;
int LCS01(string X, int n, string Y, int m)
{
	if (n < 0 || m < 0)
	{
		return 0;
	}
	cnt7++;
	if (X[n] == Y[m])
	{
		return LCS01(X, n - 1, Y, m - 1) + 1;
	}
	else
	{
		int len1 = LCS01(X, n, Y, m - 1);
		int len2 = LCS01(X, n - 1, Y, m);
		return max(len1, len2);
	}
}
//动态规划算法
static int cnt8 = 0;
string str3 = "helloworld";
string str4 = "hlweord";
int** dp8 = nullptr;
int** path8 = nullptr;//记录最长子序列
int LCS02(string X, int n, string Y, int m)
{
	if (n < 0 || m < 0)
	{
		return 0;
	}
	if (dp8[n][m] >= 0)
	{
		return dp8[n][m];
	}
	cnt8++;
	if (X[n] == Y[m])
	{
		dp8[n][m] = LCS02(X, n - 1, Y, m - 1) + 1;
		path8[n][m] = 1;//n,m -> n - 1,m - 1 对角线
		return dp8[n][m];
		
	}
	else
	{
		int len1 = LCS02(X, n, Y, m - 1);
		int len2 = LCS02(X, n - 1, Y, m);
		if (len1 >= len2)
		{
			dp8[n][m] = len1;
			path8[n][m] = 2;//n,m -> n,m - 1 左边
		}
		else
		{
			dp8[n][m] = len2;
			path8[n][m] = 3;//n,m -> n - 1,m 上方
		}
		return dp8[n][m];
	}
}
void backStrace(string str1, int n, int m)
{
	if (n < 0 || m < 0)
	{
		return;
	}
	if (path8[n][m] == 1)//对应位置的元素是相等的
	{
		backStrace(str1, n - 1, m - 1);
		cout << str1[n];//回溯的时候打印
	}
	else if (path8[n][m] == 2)
	{
		backStrace(str1, n, m - 1);
	}
	else
	{
		backStrace(str1, n - 1, m);
	}
}

//利用动态规范算法思想非递归解决最长降子序列 LCS 问题
int** dp9 = nullptr;
int** path9 = nullptr;
static int cnt9 = 0;
int LCS03(string X, int i, string Y, int j)
{
	for (int n = 1; n <= i + 1; n++)
	{
		for (int m = 1; m <= j + 1; m++)
		{
			if (X[n - 1] == Y[m - 1])
			{
				dp9[n][m] = 1 + dp9[n - 1][m - 1];
				path9[n][m] = 1;
			}
			else
			{
				int len1 = dp9[n - 1][m];
				int len2 = dp9[n][m - 1];
				if (len1 >= len2)
				{
					dp9[n][m] = len1;
					path9[n][m] = 3;
				}
				else
				{
					dp9[n][m] = len2;
					path9[n][m] = 2;
				}
			}
		}
	}
	return dp9[i + 1][j + 1];
}
void backStrace1(string str1, int n, int m)
{
	if (n <= 0 || m <= 0)
	{
		return;
	}
	if (path9[n][m] == 1)//对应位置的元素是相等的
	{
		backStrace1(str1, n - 1, m - 1);
		cout << str1[n - 1];//回溯的时候打印
	}
	else if (path9[n][m] == 2)
	{
		backStrace1(str1, n, m - 1);
	}
	else
	{
		backStrace1(str1, n - 1, m);
	}
}

//利用动态规范算法思想非递归解决 0-1 背包问题 2026.3.26
void backStrace2(int w[], int v[], int n, int c, int** dp)
{
	int bestv = 0;
	for (int i = 0; i < n; i++)
	{
		if (dp[i][c] != dp[i + 1][c])
		{
			//选择了第 i 个物品
			cout << w[i] << " ";
			bestv += v[i];
			c -= w[i];
		}
	}
	//单独处理最后一行
	if (dp[n][c] > 0)
	{
		bestv += v[n];
		cout << w[n] << endl;
	}
	cout << "背包的最大价值：" << bestv << endl;
}

int main()
{
//动态规划算法思想 2026.3.23
	//算法的基本思想与分治算法类似，也是将待求解的问题划分为若干子问题，按划分的顺序求解子阶段问题，前一个子问题的解，为后一子问题的求解提供了有用的信息(最优子结构)
	//在求解任一子问题时，列出各种可能的局部解，通过决策保留那些有可能达到最优的局部解，丢弃其它局部解
	//依次解决各个子问题，最后求出原问题的最优解
	//与分治算法的区别：适合于用动态规划算法求解的问题，经分解后得到的子问题往往不是互相独立的
	//动态规划求解问题的基本步骤：
		//动态规划所处理的问题是一个多阶段决策问题，一般由初始状态开始，通过对中间阶段决策的选择，达到结束状态
		//动态规划算法的代码设计都有一定的模式，一般都要经过以下几个步骤：
			//初始状态 -> 决策 1 -> 决策 2 -> ... -> 决策 n ->结束状态
			//1.找出最优解的性质，并刻划其结构特征。（找问题状态）
			//2.递归地定义最优值。（找状态转移方程）
			//3.自底向上的方式计算出最优值。
			//4.根据计算最优值时得到的信息，构造最优解
	
//利用动态规范算法思想递归解决硬币选择问题
	//有 1 3 5 分面额的硬币，给定一个面值 11，组成给定面值所需要的最少的硬币数量是多少
	//分治算法解决硬币选择问题：会重复求解子问题，在 1 + (10) 与 5 + (6) 中均求解了 (5)，造成算法效率低       
		//                                   11
		//                     /              |              \
		//              1 + (10)            3 + (8)           5 + (6)
		//              /    |    \                           /    |    \ 
		//        1 + (9)  3 + (7)  5 + (5)     ...     1 + (5)  3 + (3)  5 + (1)
	int n = 18;
	int num = func(n);
	cout << "num:" << num << endl;
	//动态规范算法解决硬币选择问题
	int num1 = func1(n1);
	cout << "num1:" << num1 << endl;
	cout << "cnt1:" << cnt1 << endl;

//利用动态规范算法思想非递归解决硬币选择问题
	//问题的状态：dp[i] 组成面值 i 所需要的最少的硬币数量
	//状态转移方程：
		//dp[0] = 0
		//dp[1] = 1 + dp[1 - 1] = 1
		//dp[2] = 1 + dp[2 - 1] = 1 + dp[1] = 1 + 1 = 2
		//dp[3]:
			//dp[3] = 1 + dp[3 - 1] = 1 + dp[2] = 1 + 2 = 3 选择了 3 个 1 分硬币
			//dp[3] = 1 + dp[3 - 3] = 1 + dp[0] = 1（最优） 选择了 1 个 3 分硬币
		//dp[4]:
			//dp[4] = 1 + dp[4 - 1] = 1 + 1 = 2
			//dp[4] = 1 + dp[4 - 3] = 1 + 1 = 2（最优）
		//dp[5]:
			//dp[5] = 1 + dp[5 - 1] = 1 + 2 = 3
			//dp[5] = 1 + dp[5 - 3] = 1 + 2 = 3
			//dp[5] = 1 + dp[5 - 5] = 1 + 0 = 1（最优）
		//经推导，得到状态转移方程：dp[i] = min {1 + dp[i - Vj] i 表示面值，Vj 表示第 j 个硬币的面额，条件 i >= Vj
	int v2[] = { 1,3,5 };
	int length2 = sizeof(v2) / sizeof(v2[0]);
	int c2 = 18;
	int* dp2 = new int[c2 + 1]();
	for (int i = 1; i <= c2; ++i)//dp[0] = 0，从 1 开始
	{
		dp2[i] = i;//表示初始全部由 1 分硬币组成
		for (int j = 0; j < length2; ++j)
		{
			if (i >= v2[j] && (1 + dp2[i - v2[j]]) < dp2[i])
			{
				dp2[i] = 1 + dp2[i - v2[j]];
			}
		}
	}
	cout << dp2[c2] << endl;
	delete[]dp2;

//利用动态规范算法思想递归解决斐波那契数列问题
	//斐波那契数列：1 1 2 3 5 8 13 21 34 ...（从第 3 个数字开始，该数字的值为前两个数字的合）
	//                  func(5) 参数：指定个数的斐波那契数列
	//               /                \
	//        func(4)                 func(3)
	// 	      /     \                 /     \
	//  func(3)  func(2)        func(2)  func(1)  
	//  /     \
	//func(2)  func(1)
	//分治算法
	int n3 = 10;
	int val3 = fibonacci(n3);
	cout << val3 << endl;
	//动态规划算法
	int n4 = 10;
	int* dp4 = new int[n4 + 1];
	int val4 = fibonacci1(n4, dp4);
	cout << val4 << endl;
	delete[]dp4;

//利用动态规范算法思想非递归解决斐波那契数列问题
	//问题的状态：dp[i] 斐波那契数列中第 i 个数字的值
	//状态转移方程：
		//dp[1] = 1
		//dp[2] = 1
		//dp[3] = dp[3 - 1] + dp[3 - 2] = dp[2] + dp[1] = 2
		//dp[4] = dp[4 - 1] + dp[4 - 2] = dp[3] + dp[2] = 2 + 1 = 3
		//dp[5] = dp[5 - 1] + dp[5 - 2] = dp[4] + dp[3] = 3 + 2 = 5
		//经推导，得到状态转移方程：dp[i] = dp[i - 1] + dp[i - 2] i 表示斐波那契数列中第 i 个数字的值，条件 i >= 2
	const int n5 = 10;
	int dp5[n5 + 1] = { 0 };
	dp5[1] = dp5[2] = 1;
	for (int i = 3; i <= n5; ++i)
	{
		dp5[i] = dp5[i - 1] + dp5[i - 2];
	}
	cout << dp5[n5] << endl;

//利用动态规范算法思想非递归解决最大子段和问题
	//给定 n 个整数(可能为负数)组成的序列 a[1], a[2], a[3]....a[n], 求该序列如 a[i] + a[i + 1] + ... + a[j] 的子段和的最大值
	//当所给的整数均为负数时定义子段和为 0，依次定义，所求的最优质为 Max{ 0,a[i] + a[i + 1] + ... + a[j]}，1 <= i <= j <= n
	//例如输入：-2,11,-4,13,-5,-2，输出：11 + -4 + 13 = 20
	//问题的状态：dp[i] 以 i 号位元素结尾的字段和的值
	//状态转移方程：
		//dp[0] = arr[0] < 0 = 0
		//dp[1] = arr[1] + dp[0] = 11
		//dp[2] = arr[2] + dp[1] = -4 + 11 = 7
		//dp[3] = arr[3] + dp[2] = 13 + 7 = 20
		//经推导，得到状态转移方程：dp[i] = arr[i] + dp[i - 1] i 为 0 表示子段和是已知的，条件 i > 0
	int arr6[] = { -2, 11, -4, 13, -5, -2 };
	const int n6 = sizeof(arr6) / sizeof(arr6[0]);
	int dp6[n6 + 1] = { 0 };
	dp6[0] = arr6[0] < 0 ? 0 : arr6[0];
	int maxval = dp6[0];
	for (int i = 1; i < n; ++i)
	{
		dp6[i] = arr6[i] + dp6[i - 1];
		if (dp6[i] < 0)
		{
			dp6[i] = 0;
		}
		if (dp6[i] > maxval)
		{
			maxval = dp6[i];
		}
	}
	cout << maxval << endl;

//利用动态规范算法思想非递归解决最长非降子序列 LIS 问题
	//朴素双循环解法不一定得到最优解
	//LIS 问题：求序列的最长非降（升序子序列的长度）
	//例如序列 5 3 4 1 8 7 9，其中 3 4 7 9 为最长子序列
	//问题的状态：dp[i] 以 i 号位元素结尾的非降子序列的长度
	//状态转移方程：
		//dp[0] = 1
		//dp[1] = max{1, 1 + dp[0]}(arr[0] <= arr[1]) = 1
		//dp[2] = max{1, 1 + dp[1]}(arr[1] <= arr[2]) = 2
		//dp[3] = max{ 1 } = 1
		//经推导，得到状态转移方程：dp[i] = max{1, 1 + dp[j]} j 号位元素和 i 号位元素才能构成非降子序列，条件 arr[j] <= arr[i]
	int arr7[] = { 5,3,4,1,8,6,7,10 };
	const int n7 = sizeof(arr7) / sizeof(arr7[0]);
	int dp7[n7] = { 0 };
	dp7[0] = 1;
	int maxval7 = 0;
	for (int i = 0; i < n7; ++i)
	{
		dp7[i] = 1;
		for (int j = 0; j < i; ++j)
		{
			if (arr7[j] <= arr7[i] && 1 + dp7[j] > dp7[i])
			{
				dp7[i] = 1 + dp7[j];
			}
		}
		if (dp7[i] > maxval7)
		{
			maxval7 = dp7[i];
		}
	}
	cout << maxval7 << endl;

//利用动态规范算法思想递归解决最长降子序列 LCS 问题 2026.3.25
	//LCS：求两个序列的最长公共子序列的长度，子序列不要求连续，子串要求连续
	//helloworld hlweord
	//X:X1,X2,...,Xn
	//Y:Y1,Y2,...,Ym
	//如果Xn == Ym：LCS(X[1 ... n],Y[1 ... m]) = LCS(X[1 ... n - 1],Y[1 ... m - 1]) + 1
	//如果Xn != Ym：LCS(X[1 ... n],Y[1 ... m]) = max{LCS(X[1 ... n],Y[1 ... m - 1]),LCS(X[1 ... n - 1],Y[1 ... m])}
	//分治算法
	string str1 = "helloworld";
	string str2 = "hlweord";
	int size7 = LCS01(str1, str1.size() - 1, str2, str2.size() - 1);//str1.size() - 1 末尾字符下标
	cout << "LCS01:" << size7 << endl;
	cout << "cnt7:" << cnt7 << endl;
	//动态规划
		//问题的状态：dp[n][m] n 表示第一个串的长度，m 表示第二个串的长度，n 行 m 列元素的值，记录的就是这两个串的 LCS 长度
		//状态转移方程：
			//如果 Xn == Ym：dp(X[1 ... n],Y[1 ... m]) = dp(X[1 ... n - 1],Y[1 ... m - 1]) + 1
			//如果 Xn != Ym：dp(X[1 ... n],Y[1 ... m]) = max{dp(X[1 ... n],Y[1 ... m - 1]),dp(X[1 ... n - 1],Y[1 ... m])}
		//输出最长子序列
			//dp 只记录了最长序列的长度，需用 path 记录子序列，以序列 helloworld 与 hlweord 为例
			//dp:                    path: 
				//  h l w e o r d           h l w e o r d
				//h 1 1 1 * * * *         h 1 2 2 0 0 0 0     
				//e 1 1 1 2 * * *         e 3 2 2 1 0 0 0  e(2,1) -> h(1,1)
				//l 1 2 2 2 * * *         l 3 1 2 2 0 0 0  l(3,1) -> e(2,1)
				//l 1 2 2 2 * * *         l 3 1 2 2 0 0 0  l(4,2) -> l(3,1)
				//o 1 2 2 2 * * *         o 3 3 2 2 0 0 0  o(5,2) -> l(4,2)
				//w 1 2 3 3 * * *         w 3 3 1 2 0 0 0  w(6,4) -> w(6,3) -> o(5,2)   ----------------> hlword（最长公共子序列）
				//o 1 2 3 3 4 * *         o 3 3 3 2 1 0 0  o(7,5) -> w(6,4)             1 为 X[n] == Y[m] 
				//r 1 2 3 3 4 5 *         r 3 3 3 2 3 1 0  r(8,6) -> o(7,5)
				//l * 2 3 3 4 5 *         l 0 1 3 2 3 3 0  l(9,6) -> r(8,6)
				//d * * * * * * 6         d 0 0 0 0 0 0 1  d(10,7) -> l(9,6)
	int n8 = str3.size();
	int m8 = str4.size();
	//初始化 dp path
	dp8 = new int*[n8];//n 行
	for (int i = 0; i < n8; i++)
	{
		dp8[i] = new int[m8];//m 列
		for (int j = 0; j < m8; j++)
		{
			dp8[i][j] = -1;
		}
	}
	path8 = new int* [n8];//n 行
	for (int i = 0; i < n8; i++)
	{
		path8[i] = new int[m8];//m 列
		for (int j = 0; j < m8; j++)
		{
			path8[i][j] = -1;
		}
	}
	int size8  = LCS02(str3, n8 - 1, str4, m8 - 1);
	cout << "LCS02:" << size8 << endl;
	cout << "cnt8:" << cnt8 << endl;
	//递归实现输出最长序列
	backStrace(str3, n8 - 1, m8 - 1);
	cout << endl;

//利用动态规范算法思想非递归解决最长降子序列 LCS 问题
	int n9 = str3.size();
	int m9 = str4.size();
	dp9 = new int* [n9 + 1];//n 行
	for (int i = 0; i < n9 + 1; i++)
	{
		dp9[i] = new int[m9 + 1];//m 列
		for (int j = 0; j < m9 + 1; j++)
		{
			dp9[i][j] = 0;
		}
	}
	path9 = new int* [n9 + 1];//n 行
	for (int i = 0; i < n9 + 1; i++)
	{
		path9[i] = new int[m9 + 1];//m 列
		for (int j = 0; j < m9 + 1; j++)
		{
			path9[i][j] = 0;
		}
	}
	int size9 = LCS03(str3, n9 - 1, str4, m9 - 1);
	cout << "LCS03:" << size9 << endl;
	cout << "cnt9:" << cnt9 << endl;
	backStrace1(str3, n9, m9);
	cout << endl;

//利用动态规范算法思想非递归解决 0-1 背包问题 2026.3.26
	//有一组物品，其重量分别是：w1,w2,...,wn，其价值分别是 v1,v2,...,vn，现在有一个背包，其容量是 C，如何使背包的价值最大化
	//问题的状态：重量、价值、背包的容量，dp[i][j] 所选的物品范围在 i,...,n，背包的容量是 j，背包所容纳物品的最大价值
	//状态转移方程：
		//i == n：只考虑一个物品，就是 wn
			//wn > j：说明第 n 个物品无法装入背包，d[n][j] = 0
			//wn <= j：说明第 n 个物品可以装入背包，d[n][j] = vn
		//i,i + 1,...,n 是可选的物品
			//wi > j：说明第 i 个物品无法装入背包中，d[i][j] = d[i + 1][j]
			//wi <= j：说明第 i 个物品可以装入背包中，d[i][j] = d[i + 1][j]，dp[i][j] = max{dp[i + 1][j]（不装入物品 i）,vi + dp[i + 1][j - wi]（装入物品 i）}
	//以 w = { 8,6,4,2,5 }，v = { 6,4,7,8,6 } 为例，dp 矩阵如下
		//物品      容量
		//          1 2 3 4 5 6 7  8  9  10 11 |12| <---矩阵元素表示背包所容纳物品的最大价值
		//1(8,6)    0 8 8 8 8 15 15 15 15 15 21 21  不选择
		//2(6,4)	0 8 8 8 8 15 15 15 15 15 21 21  不选择
		//3(4,7)	0 8 8 8 8 15 15 15 15 15 21 21  选择 7
		//4(2,8)	0 8 8 8 8 14 14 14 14 14 14 14  选择 8
		//5(5,6)	0 0 0 0 6 6  6  6  6  6  6  6   选择 6
		//1.考虑最后一个元素在任何背包容量下所产生的价值，如当背包的容量为 1 - 4 时，均无法放置物品 5，当背包的容量为 5 - 12 时，背包所容纳物品的价值为 6 
		//2.再考虑 n - 1 -> n,n - 2 -> n,....,1 -> n 情况下背包所容纳物品的最大价值，如依次考虑物品 4 5,3 4 5,2 3 4 5,1 2 3 4 5 情况下背包所容纳物品的最大价值
	int w10[] = { 8,6,4,2,5 };
	int v10[] = { 6,4,7,8,6 };
	int c10 = 12;
	int** dp10 = nullptr;
	int n10 = sizeof(w10) / sizeof(w10[0]) - 1;
	dp10 = new int* [n10 + 1];
	for (int i = 0; i < n10 + 1; ++i)//物品个数
	{
		dp10[i] = new int[c10 + 1]();//初始化 dp 数组的元素为 0
	}
	//先填写初始状态的值，填写 dp 二维数组的最后一行，即最后一个物品 n，因为最后一个物品无法以他的下一个物品进行比较
	for (int j = 1; j <= c10; j++)
	{
		//说明第 n 个物品无法装入背包
		if (w10[n10] > j)
		{
			dp10[n10][j] = 0;
		}
		//说明第 n 个物品可以装入背包
		else
		{
			dp10[n10][j] = v10[n10];
		}
	}
	//从 n - 1 -> 0，表示所选择的物品是 i,i + 1,...,n
	for (int i = n10 - 1; i >= 0; --i)
	{
		for (int j = 1; j <= c10; ++j)
		{
			//说明第 i 个物品无法装入背包中
			if (w10[i] > j)
			{
				dp10[i][j] = dp10[i + 1][j];
			}
			//说明第 i 个物品可以装入背包中
			else
			{
				dp10[i][j] = max(dp10[i + 1][j], v10[i] + dp10[i + 1][j - w10[i]]);
			}
		}
	}
	//打印 dp 数组
	for (int i = 0; i <= n10; i++)
	{
		for (int j = 1; j <= c10; j++)
		{
			cout << dp10[i][j] << " ";
		}
		cout << endl;
	}
	//打印选择的物品
	backStrace2(w10, v10, n10, c10, dp10);
	//释放 dp 数组的内存
	for (int i = 0; i < n10 + 1; i++)
	{
		delete[]dp10[i];
	}
	delete[]dp10;

//利用动态规范算法思想非递归解决三角数组求和问题 2026.3.27
	//给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上
	//例如，给定三角形:
		//[2]
		//[3, 4],
		//[6, 5, 7],
		//[4, 1, 8, 3]，自顶向下的最小路径和为11(即，2 + 3 + 5 + 1 = 11)
	//问题的状态：dp[i][j] 以 i 行 j 列元素开始选择数字的和的最大值，思路与 0-1 背包问题相似
	vector<int> v11 = { 2 };
	vector<int> v12 = { 3,4 };
	vector<int> v13 = { 6,5,7 };
	vector<int> v14 = { 4,1,8,3 };
	vector<vector<int>> vv = { v11,v12,v13,v14 };
	int** dp11 = nullptr;
	dp11 = new int* [vv.size()];
	int n11 = vv.size() - 1;
	for (int i = 0; i < vv.size(); i++)
	{
		dp11[i] = new int[v14.size()]();
	}
	//最后一行
	for (int i = 0; i < vv.size(); i++)
	{
		dp11[n11][i] = vv[n11][i];
	}
	//最后一行到最开始的哪一行
	for (int i = n11 - 1; i >= 0; --i)
	{
		for (int j = 0; j < vv[i].size(); ++j)
		{
			dp11[i][j] = min(dp11[i + 1][j], dp11[i + 1][j + 1]) + vv[i][j];
		}
	}
	cout << dp11[0][0] << endl;
	//释放 dp 数组的内存
	for (int i = 0; i < vv.size(); i++)
	{
		delete[]dp11[i];
	}
	delete[]dp11;

	system("pause");
	return 0;
}
*/
