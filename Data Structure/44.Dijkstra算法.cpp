#include<iostream>
#include<stdlib.h>
#include<functional>
#include<string>
#include<list>
#include<vector>
#include<algorithm>
#include<queue>
//using namespace std;
//using uint = unsigned int;
//const uint INF = INT_MAX;//2147483647

/*
//Dijkstra 算法实现
int Dijkstra(vector<vector<uint>>& graph, int start, int end)
{
	const int N = graph.size();
	vector<uint> dis(N, 0);//存储各个顶点的最短路径（最小权值）
	vector<bool> use(N, false);//false集合， 表示在 U true 表示在 S 集合
	use[start] = true;//把 start 放入 S 集合
	//初始化 start 到其他 U 集合顶点权值
	for (int i = 0; i < N; i++)
	{
		dis[i] = graph[start][i];
	}
	//把 U 集合中的顶点处理完	
	for (int i = 1; i < N; i++)//O(n)
	{
		//先从 U 集合中找到权值最小的顶点
		int k = -1;
		int min = INF;
		for (int j = 0; j < N; j++)//O(n)
		{
			if (!use[j] && min > dis[j])
			{
				min = dis[j];
				k = j;
			}
		}
		if (k == -1)
		{
			break;
		}
		use[k] = true;//把选出的顶点加入到 S 集合中
		//更新 U 集合中剩余顶点的权值信息
		for (int j = 0; j < N; j++)
		{
			if (!use[j] && min + graph[k][j] < dis[j])
			{
				dis[j] = min + graph[k][j];
			}
		}
	}
	for (int d : dis)
	{
		cout << d << " ";
	}
	cout << endl;
	return dis[end];
}

//Dijkstra 算法优化
int Dijkstra_optimize(vector<vector<uint>>& graph, int start, int end)
{
	const int N = graph.size();
	vector<uint> dis(N, 0);
	vector<bool> use(N, false);
	priority_queue<pair<uint, int>, vector<pair<uint, int>>, greater<pair<uint, int>>> que;//定义小根堆
	use[start] = true;//把 start 放入 S 集合
	//初始化 start 到其他 U 集合顶点权值
	for (int i = 0; i < N; i++)
	{
		dis[i] = graph[start][i];
		//把除 start 顶点的其他顶点全部放入 U 集合小根堆中
		if (i != start)
		{
			que.emplace(dis[i], i);
		}
	}
	//把 U 集合中的顶点处理完
	while (!que.empty())//O(n)
	{
		//先从 U 集合中找到权值最小的顶点
		auto pair = que.top();
		que.pop();
		if (pair.first == INF)
		{
			break;
		}
		int k = pair.second;
		int min = pair.first;
		if (use[k])
		{
			continue;
		}
		use[k] = true;//把选出的顶点加入到 S 集合中
		//更新 U 集合中剩余顶点的权值信息
		for (int j = 0; j < N; j++)
		{
			if (!use[j] && min + graph[k][j] < dis[j])
			{
				dis[j] = min + graph[k][j];
				que.emplace(dis[j], j);
			}
		}
	}
	for (int d : dis)
	{
		cout << d << " ";
	}
	cout << endl;
	return dis[end];
}

int main()
{
//Dijkstra 算法原理 2026.4.20
	//Dijkstra（迪杰斯特拉）算法是典型的单源最短路径算法，用于计算一个节点到其他所有节点的最短路径
	//主要特点是以起始点为中心向外层层扩展，直到扩展到终点为止，Dijkstra算去是很有代表性的最短路径算法
	//贪心算法的典型应用场景，但是会导致无法处理负权边，有可能得不到最短的路径
	//算法思想:
		//设G = (V, E)是一个带权有向图，把图中顶点集合V分成两组
		//第一组为已求出最短路径的顶点集合（用 S 表示，初始时 S 中只有一个源点，以后每求得一条最短路径，就将加入到集合 S 中，直到全部顶点都加入到S中，算法就结束了）
		//第二组为其余未确定最短路径的顶点集合（用 U 表示），按最短路控长度的递增次序依次把第二组的顶点加入 S 中
		//在加入的过程中，总保持从源点 V 到 S 中各顶点的最短路径长度不大于从源点 V 到 U 中任何顶点的最短路径长度
		//此外，每个顶点对应一个距离，S 中的质点的距离就是从 v 到此顶点的最短路径长度，U 中的顶点的距离，是从 V 到此质点只包括S中的顶点为中间顶点的当前最短路径长度
	//以下图为例：
		//  --- B --5-- D --3-- F
		// /6   |   /   |  /
		//A    2|  /3  2| /5
		// \3   | /     |/
		//  --- C --4-- E
		//1.S 集合        U 集合
		//  A             B   C   D   E   F （指定顶点 A 到其他所有顶点的最短路径全部求出来）
		//  0             6   3  INF INF INF
		//2.A C           B   D   E   F （每一次从 U 集合中选出权值最小的顶点，放入 S 集合）
		//  0 3           6  INF INF INF 
		//3.A C B         D   E   F （加入 S 集合后，需要更新 U 集合中剩余顶点的权值信息）
		//  0 3 5         6   7  INF
		//4.A C B D       E   F （重复上述步骤）
		//  0 3 5 6       7  INF
		//5.A C B D E     F
		//  0 3 5 6 7     9
		//5.A C B D E F   -
		//  0 3 5 6 7 9   -
		
//Dijkstra 算法实现
	vector<vector<uint>> graph =
	{
		{0, 6, 3, INF, INF, INF},
		{6, 0, 2, 5, INF, INF},
		{3, 2, 0, 3, 4, INF},
		{INF, 5, 3, 0, 2, 3},
		{INF, INF, 4, 2, 0, 5},
		{INF, INF, INF, 3, 5, 0},
	};
	int distance = Dijkstra(graph, 0, 3);
	if (distance == INF)
	{
		cout << "不存在有效路径！" << endl;
	}
	else
	{
		cout << "有效路径为：" << distance << endl;
	}

//Dijkstra 算法优化
	//使用小根堆找权值最小的顶点 O(logn)
	int distance_optimize = Dijkstra_optimize(graph, 0, 3);
	if (distance_optimize == INF)
	{
		cout << "（优化）不存在有效路径！" << endl;
	}
	else
	{
		cout << "（优化）有效路径为：" << distance_optimize << endl;
	}

	system("pause");
	return 0;
}
*/