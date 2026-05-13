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
//并查集算法实现 2026.4.20
const int SIZE = 9;
int parent[SIZE];
//并查集查询方法，返回参数 x 节点所在树的根节点的编号
int find(int x)
{
	while (x != parent[x])
	{
		//x 更新成其父节点的编号
		x = parent[x];
	}
	return x;
}
//递归实现并查集查询方法
int rfind(int x)
{
	if (x == parent[x])
	{
		return x;
	}
	return rfind(parent[x]);
}
//并查集合并方法
void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	//x 与 y 不在同一个集合中才进行合并
	if (x != y)
	{
		parent[x] = y;//parent[y] = x;也可以，存在问题：永远是一个方向上父子关系
	}
}

//并查集路径压缩算法
//find 优化
int rfind_optimize(int x)
{
	if (x == parent[x])
	{
		return x;
	}
	//把执行查询操作的时候将访问过的每个点的父节点修改成树根
	return parent[x] = rfind_optimize(parent[x]);
}
//加权标记
int rank[SIZE];//记录节点的层高
void merge_optimize(int x, int y)
{
	x = rfind_optimize(x);
	y = rfind_optimize(y);
	//x 与 y 不在同一个集合中才进行合并
	if (x != y)
	{
		if (::rank[x] > ::rank[y])
		{
			parent[y] = x;//将 y 挂在 x 的树下
		}
		else
		{
			if (::rank[x] == ::rank[y])
			{
				::rank[y]++;
			}
			parent[x] = y;//将 x 挂在 y 的树下
		}
	}
}

int main()
{
//并查集算法原理
	//并查集是一种树形的数据结构，主要用于解决一些元素分组的问题，用于处理一些不相交集合的合并以及查询问题
	//并查集的思想是用一个数组表示了整片森林，树的根节点唯一标识了一个集合，我们只要找到了某个元素的树根，就能确定它在哪个集合里
	//以 1 2 3 4 5 6 7 8 这 8 个点为例，两两在一个集合中的节点有：1（父）3（子）,1 2,5 4,2 4,6 8,8 7，一组节点中，前一个节点为后一个节点的父节点
		//1 3       1 3,1 2      1 3,1 2,5 4     1 3,1 2,5 4,2 4      
		//   1 --->   1     --->    1     5 --->     1             
		// /        /   \         /   \   |      /   |   \  w
		//3        3     2       3     2  4     3    2    5
		//                                                 \ 
		//                                                  4
		//
		//     1 3,1 2,5 4,2 4,6 8      1 3,1 2,5 4,2 4,6 8,8 7
		//--->      1         6    --->     1          6
		//      /   |   \     |         /   |   \     / \
		//     3    2    5    8        3    2    5   8   7
		//                \                       \ 
		//                 4                       4
	//问题场景
		//合并：将若干元素合并到一个或者多个集合（构成一棵树或多棵树），将多个集合合并（多颗树合并为一棵树）
		//查询：查询两个元素是否在同一个集合中
		//其它：计算共有几个集合（几棵树）
	//主要思想：每一个节点对应的数组元素位置，存储它父节点的编号即可，当 x == arr[x]，x 就是当前树的根了
	//以 1 2 3 4 5 6 7 8 这 8 个点为例
		//-------------------------------------
		//|   | 1 | 1 | 1 | 5 | 1 | 6 | 6 | 6 | parent
		//-------------------------------------
		//  0   1   2   3   4   5   6   7   8   child
		
//并查集算法实现 2026.4.20
	//数组初始化，存储当前节点自己的编号
	for (int i = 0; i < SIZE; i++)
	{
		parent[i] = i;
	}
	int x, y;
	for (int i = 0; i < 6; i++)
	{
		cin >> x >> y;
		merge(x, y);
	}
	cout << (find(2) == find(8) ? "OK" : "NO") << endl;

//并查集路径压缩算法
	//大多数情况下，在查询过程中只关心根节点是什么，并不关系这棵树的形态，因此在查询操作的时候将访问过的每个点的父节点修改成树根，这样的方法叫做路径压缩
	//压缩算法：find 优化与加权标记
	//find 优化：在第一次 find 的时候优化
		//树低一些或矮一些，并查集查询效率就高
		//find 优化：第一次执行 find 优化的效率不高，后续查询效率非常好
	//加权标记：在合并的时候进行优化
		//期望在并查集构建的过程中，进行集合合并的时候，尽量的使用合并后的集合树的高度低一些，矮一些最好
	//find 优化与加权标记一起用会导致 rank 层高失效，因为 rfind_optimize 会使树变化，但是并没有更新 rank
	for (int i = 0; i < SIZE; i++)
	{
		::rank[i] = 1;
	}
	for (int i = 0; i < 6; i++)
	{
		cin >> x >> y;
		merge_optimize(x, y);
	}
	cout << (rfind_optimize(2) == rfind_optimize(5) ? "OK" : "NO") << endl;

	system("pause");
	return 0;
}
*/