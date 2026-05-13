#include<iostream>
#include<stdlib.h>
#include<functional>
#include<string>
#include<list>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

/*
//Kruskal 算法实现
//边类型
struct Edge
{
	Edge(int s, int e, int c)
		: start(s)
		, end(e) 
		, cost(c)
	{ }
	int start;//起始节点
	int end;//末尾节点
	int cost;//边的权值
};
const int SIZE = 1000;
int parent[SIZE];
//并查集查询
int find(int x)
{
	if (x == parent[x])
	{
		return x;
	}
	return parent[x] = find(parent[x]);//路径压缩
}

//并查集与最小生成树应用
struct Road
{
	Road(int a, int b, int c)
		: u(a)
		, v(b)
		, w(c)
	{ }
	int u;
	int v;
	int w;
};
const int SIZE1 = 10005;
int parent1[SIZE1];
int find1(int x)
{
	if (x == parent1[x])
	{
		return x;
	}
	return parent1[x] = find1(parent1[x]);
}
void merge1(int x, int y)
{
	x = find1(x);
	y = find1(y);
	if (x != y)
	{
		parent1[x] = y;
	}
}

int main()
{
//Kruskal 算法原理
	//并查集的应用-最小生成树
	//连通图：在无向图中，若任意两个顶点 Vi 和 Vj 都有路径相通，则称该无向图为连通图
	//强连通图：在有向图中，若任意两个顶点 Vi 和 Vj 都有路径相通，则称该有向图为强连通图
	//连通网：在连通图中，若图的边具有一定的意义，每一条边都对应着一个数，称为权值，权值代表着连接各个顶点的代价，称这种连通图叫做连通网
	//生成树：一个连通子图，它包含连通图中全部 n 个顶点，有 n - 1 条边。如果生成树中再添加一条边，则必定成环，生成树不允许存在环
	//最小生成树：在连通网的所有生成树中，所有边的代价之和最小的生成树，称为最小生成树
	//Prim 算法：此算法可以称为“加点法”，每次迭代选择代价最小的边对应的点，加入到最小生成树中。算法从某一顶点 s 开始，逐渐增长覆盖整个连通网的所有顶点
		//1.图的所有顶点集合是V，初始令集合u = { s }，v = V - u。
		//2.在两个集合 u，v 能够组成的边中，选择一条代价最小的边（ui, vi）加入到最小生成树当中，并把 vi 加入到集合u中，更新 v 集合中剩余顶点的权值为最小代价
		//3.重复步骤 2，直到最小生成树有 n - 1 条边或者 n 个顶点为止。
	//Kruskal 算法：此算法可以称为“加边法”，初始最小生成树边数为0，每迭代一次就选择一条满足条件的最小代价边，加入到最小生成树的边集合里
		//1.把图中的所有边按权值从小到大排序，把图中的 n 个顶点看成独立的n颗树组成的森林
		//2.按权值从小到大选择边，所选的边连接的两个顶点 Vi 和 Vj 应属于两颗不同的树，则称为最小生成树中的一条边，并合并成一棵树
		//3.重复步骤 2，直到所有顶点都在一棵树内或者有 n - 1 条边为止。

//Kruskal 算法实现
	//for (int i = 0; i < SIZE; i++)
	//{
	//	parent[i] = i;
	//}
	//vector<Edge> edges;
	//int n;//起始节点与末尾节点的数量
	//cin >> n;
	//char s, e;//起始节点与末尾节点
	//int c;//起始节点与末尾节点之间的权值
	//for (int i = 0; i < n; i++)
	//{
	//	cin >> s >> e >> c;
	//	edges.emplace_back(s, e, c);
	//}
	//sort(edges.begin(), edges.end(), [](auto& a, auto& b)->bool {return a.cost < b.cost; });//给所有的边按权值进行排序
	//for (int i = 0; i < edges.size(); i++)
	//{
	//	//选择边，合并这条边的两个顶点，但这两个顶点不在一颗树上
	//	int a = find(edges[i].start);
	//	int b = find(edges[i].end);
	//	if (a != b)
	//	{
	//		parent[a] = b;//合并
	//		printf("%c -> %c cost:%d \n", edges[i].start, edges[i].end, edges[i].cost);
	//	}
	//}

//并查集与最小生成树应用
	//躲避拥堵的最佳路线
		//小明所在的城镇有 m 条路连接了 n 个区（1 个区的编号在 1 - n 的范围内），每条大道将两个区相连接
		//每条大道有一个拥挤度，小明想要开车从 s 区去 t 区，请你帮他规划一条路线，使得经过道路的拥挤度的最大值最小
	//输入：
		//第一行有四个用空格隔开的 n，m，s，t 其含义见题目描述
		//接下来 m 行，每行三个整数 u, v, w 表示有一条大道连接区 u 和区 v，且拥挤度为 w，两个区之间可能存在多条大道
	for (int i = 0; i < SIZE1; i++)
	{
		parent1[i] = i;
	}
	int n1, m1, s1, t1;
	cin >> n1 >> m1 >> s1 >> t1;
	vector<Road> roads;
	int u1, v1, w1;
	for (int i = 0; i < m1; i++)
	{
		cin >> u1 >> v1 >> w1;
		roads.emplace_back(u1, v1, w1);
	}
	sort(roads.begin(), roads.end(), [](auto& a, auto& b)->bool {return a.w < b.w; });
	for (int i = 0; i < roads.size(); i++)
	{
		merge1(roads[i].u, roads[i].v);
		//s 区与 t 区第一次有通路经过道路的拥挤度的最大值最小
		if (find1(s1) == find1(t1))
		{
			cout << roads[i].w << endl;
			break;
		}
	}

	system("pause");
	return 0;
}
*/