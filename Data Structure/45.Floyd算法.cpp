#include<iostream>
#include<stdlib.h>
#include<functional>
#include<string>
#include<list>
#include<vector>
#include<queue>
//using namespace std;
//using uint = unsigned int;
//const uint INF = INT_MAX;

/*
int main()
{
//Floyd 算法原理
	//Floyd 算法又称为插点法，是一种利用动态规划的思想寻找给定的加权图中多源点之间最短路径的算法
	//主要思想:
		//1.从第 1 个点到第 n 个点依次加入图中，每个点加入后进行试探是否有路径长度被更改
			//具体方法为遍历图中每一个点（i,j 双重循环），判断每一个点对距离是否因为加入的点而发生最小距离变化，如果发生改变，更新两点 (i,j) 的距离
		//2.重复上述直到最后插点试探完成
	//更新距离的状态转移方程为 : dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j])
	//dp[x][y] 的意思可以理解为 x 到 y 的最短路径，dp[i[k] 为 i 倒 k 的最短路径，dp[k][j] 为 k 到 j 的最短路径
	//以下图为例：
		//  --- B --5-- D --3-- F  
		// /6   |   /   |  /
		//A    2|  /3  2| /5
		// \3   | /     |/
		//  --- C --4-- E
		//		A   B   C   D   E   F
		//		A   0   6   3  INF INF INF
		//      B   6   0   2   5  INF INF
		//adj = C   3   2   0   3   4  INF
		//		D  INF  5   3   0   2   3
		//		E  INF INF  4   2   0   5
		//		F  INF INF  INF 3   5   0
		//1.把 A 加入中转节点，判断 X->Y 的距离 min(X -> Y，与 X -> A（中转节点） -> Y)，更新 adj 矩阵中对应的值
		//2.重复上述步骤，遍历 B - F 
	 
//Floyd算法实现
	vector<vector<uint>> graph =
	{
		{0, 6, 3, INF, INF, INF},
		{6, 0, 2, 5, INF, INF},
		{3, 2, 0, 3, 4, INF},
		{INF, 5, 3, 0, 2, 3},
		{INF, INF, 4, 2, 0, 5},
		{INF, INF, INF, 3, 5, 0},
	};
	//依次把每一个顶点加入
	for (int k = 0; k < graph.size(); k++)
	{
		//遍历领接矩阵
		for (int i = 0; i < graph.size(); i++)
		{
			for (int j = 0; j < graph.size(); j++)
			{
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
	for (auto line : graph)
	{
		for (auto dis : line)
		{
			cout << dis << " ";
		}
		cout << endl;
	}
	cout << endl;
	//cout << graph[start][end] << endl;

	system("pause");
	return 0;
}
*/