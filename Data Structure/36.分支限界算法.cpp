#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;

/*
//利用分支限界算法解决装载问题
int w[] = { 12,8,15 };//集装箱的重量
const int n = sizeof(w) / sizeof(w[0]);//集装箱的数量
int c = 27;//轮船的容量
int cw = 0;//已选择物品的重量
int bestw = 0;//记录最优的装载量
//描述节点类型
struct Node
{
	Node(int w, int l, Node* p, bool left)
	{
		weight = w;
		level = l;
		parent = p;
		isleft = left;
	}
	int weight;//从根节点到当前节点所选择物品的总重量
	int level;//当前节点的层数
	Node* parent;//记录当前节点的父节点
	bool isleft;//记录当前节点是否被选择
};
queue<Node*> que;//广度优先遍历子集树的 FIFO 队列
int i = 0;//表示起始的层数，从根节点开始
Node* bestnode = nullptr;
int r = 0;//记录未被处理的物品的总重量
void addLiveNode(int w, int level, Node* parent, bool isleft)
{
	Node* node = new Node(w, level, parent, isleft);
	que.push(node);
	//在最后一层，记录最优值节点
	if (level == n && w == bestw)
	{
		bestnode = node;
	}
}
//节点的上界函数，当前不选第 level 个物品时，右子树后续最多还能增加的重量
int maxBound(int level)
{
	int s = 0;
	for (int j = level + 1; j < n; j++)
	{
		s += w[j];
	}
	return s;
}

//利用分支限界算法 FIFO 队列解决背包问题
struct Node1
{
	Node1(int w, int v, int l, Node1* p, bool left)
	{
		weight = w;
		value = v;
		level = l;
		parent = p;
		isleft = left;
	}
	int weight;//从根节点到当前节点所选择物品的总重量
	int level;//当前节点的层数
	int value;
	Node1* parent;//记录当前节点的父节点
	bool isleft;//记录当前节点是否被选择
};
int w1[] = { 16,15,15 };//物品的重量
int v1[] = { 45,25,25 };//物品的价值
int c1 = 20;//背包的容量
const int n1 = sizeof(w1) / sizeof(w1[0]);//物品的个数
int cw1 = 0;//已选择物品的重量
int cv1 = 0;//已选择物品的价值
int bestv1 = 0;//装入背包的物品的最优价值
Node1* bestnode1 = nullptr;//记录最优解的叶子节点
queue<Node1*> que1;//广度遍历所需要的 FIFO 队列
//价值上界
int maxBound1(int level1)
{
	int bound = 0;
	for (int j = level1 + 1; j < n; j++)
	{
		bound += v1[j];
	}
	return bound;
}
void addLiveNode1(int w, int v, int level, Node1* parent, bool isleft)
{
	Node1* node1 = new Node1(w, v, level, parent, isleft);
	que1.push(node1);
	//在最后一层，记录最优值节点
	if (level == n1 && v == bestv1)
	{
		bestnode1 = node1;
	}
}

//利用分支限界算法优先级队列解决背包问题
//价值上界
struct Node2
{
	Node2(int w, int v, int up, int l, Node2* p, bool left)
	{
		weight = w;
		value = v;
		upbound = up;
		level = l;
		parent = p;
		isleft = left;
	}
	int weight;//从根节点到当前节点所选择物品的总重量
	int level;//当前节点的层数
	int value;
	Node2* parent;//记录当前节点的父节点
	bool isleft;//记录当前节点是否被选择
	int upbound;//节点的价值上界，从这个节点往下，最多能选择的物品产生的总价值
};
int w2[] = { 16,15,15 };//物品的重量
int v2[] = { 45,25,25 };//物品的价值
int c2 = 31;//背包的容量
const int n2 = sizeof(w2) / sizeof(w2[0]);//物品的个数
int cw2 = 0;//已选择物品的重量
int cv2 = 0;//已选择物品的价值
int bestv2 = 0;//装入背包的物品的最优价值
priority_queue<Node2*, vector<Node2*>, function<bool(Node2*, Node2*)>> que2([](Node2* n1, Node2* n2)->bool {return n1->upbound < n2->upbound; });//广度遍历所需要的 FIFO 队列
int maxBound2(int level2)
{
	int bound = cv2;
	for (int j = level2; j < n2; j++)
	{
		bound += v2[j];
	}
	return bound;
}
void addLiveNode2(int w, int v, int up, int level, Node2* parent, bool isleft)
{
	Node2* node2 = new Node2(w, v, up, level, parent, isleft);
	que2.push(node2);
	//用优先级队列就不用标记产生最优解的叶子节点了，因为优先级队列到达某一个叶子节点时，最优质就产生了
	//if (level == n1 && v == bestv1)
	//{
	//	bestnode2 = node2;
	//}
}

int main()
{
//分支限界算法思想 2026.4.13
	//分支限界法类似于回溯算法，是在问题的解空间树上搜索问题解的算法，主要体现在两点不同：
		//1.求解目标不同，回溯算法的求解目标是找出解空间树中满足约束条件的所有解，而分支限界法的求解目标是找出满足约束条件的一个解，或者是在满足约束条件的解中找出某种意义下的最优解
		//2.搜索解空间树的方式不同，回溯算法以深度优先的方式搜索解空间树，而分支限界法则以广度优先或者以最小耗费优先的方式搜索解空间树
	//分支限界算法基本思想：
		//分支限界法常以广度优先或以最小耗费（最大效益）优先的方式搜索问题的解空间树
		//在分支限界法中，每一个活结点只有一次机会称为扩展节点，活结点一旦成为扩展节点，就一次性产生其所有儿子节点（分支），在这些儿子节点中，导致不可行解或是导致非最优解的儿子节点会被舍弃掉，其余儿子节点会被加入活结点表中
		//为了有效的选择下一个扩展节点加速搜索，在每一个活结点处计算一个函数值（限界），并根据计算的函数值结果从当前活结点表中取下一个最有利的节点成为当前的扩展节点，使搜索朝着解空间树上最优解的分支推进
		//重复上述节点扩展过程，直到找到所需的最优解或者活结点表为空
	//扩展节点：一个正在产生儿子的节点称作扩展节点
	//活结点：一个自身已经生成，但其儿子还没有全部生成的节点
	//死结点：一个所有儿子已经产生的节点
	//深度优先搜索是对一个扩展节点 R，一旦产生了它的一个儿子 C，就把 C 当作新的扩展节点在完成对子树 C 的深度搜索之后回溯到 R 时，将 R 重新变成扩展节点，继续生成 R 的下一个儿子
	//广度优先搜索是在一个扩展节点 R 变成死节点之前，它一直是扩展节点
	//从活结点表中选择下一个扩展节点时，不同的方式会导致不同的分支限界法，常见有：
		//1.队列式（FIFO）分支限界法
			//a.一开始，根结点是唯一的活结点，根结点加入活结点队列
			//b.从活结点队列中取出队头结点后，作为当前扩展结点
			//c.对当前扩展结点，先从左到右产生它的所有孩子节点，用约束条件检查，把所有满足约束函数的孩子节点加入活结点队列中
			//d.再从活结点表中取出队首结点为当前扩展结点，重复上述过程，直到找到一个解或活结点队列为空为止
		//2.优先级队列式分支限界法
			//a.对每一活结点计算一个优先级（某些信息的函数值）
			//b.根据这些优先级从当前活结点表中优先选择一个优先级最高（最有利）的结点作为扩展结点，使搜索朝着解空间树上有最优解的分支推进，以便尽快地找出一个最优解
			//c.对当前扩展结点，先从左到右产生它的所有孩子节点，用约束条件检查，对所有满足约束函数的孩子节点计算优先级并加入到活结点优先级队列中
			//d.再从活结点表中取出下一个优先级最高的结点为当前扩展结点，重复上述过程，直到找到一个解或活结点队列为空为止

//利用分支限界算法解决装载问题
	//有一批共 n 个集装箱要装上 2 艘载重量分别为 c1，c2的轮船，其中集装箱 i 的重量为 wi，且要求确定是否有一个合理的装载方案可将这 n 个集装箱装上这 2 艘轮船
	Node* node = nullptr;//初始状态
	while (i < n)
	{
		//第 i 层，处理当前节点的左孩子，选择 i 节点
		int wt = cw + w[i];
		if (wt <= c)//选择物品 i 以后，其总重量不能超过轮船的容量
		{
			if (wt > bestw)
			{
				bestw = wt;
			}
			addLiveNode(cw + w[i], i + 1, node, true);//活节点孩子入队列
		}
		//第 i 层，处理当前节点的右孩子，不选择 i 节点
		r = maxBound(i);//求第 i 个节点的重量值上界
		if (cw + r >= bestw)//必须 >=，不然会出现无法选择到叶子节点上的情况
		{
			addLiveNode(cw, i + 1, node, false);
		}
		//处理完 i 节点后，它变为死节点，出队
		node = que.front();
		que.pop();
		//恢复 cw 和 i 的值，表示从 i 节点调到广度遍历的下一个节点了
		cw = node->weight;
		i = node->level;
	}
	cout << bestw << endl;
	int bestx[n] = { 0 };
	for (int j = n - 1; j >= 0; --j)
	{
		bestx[j] = bestnode->isleft ? 1 : 0;
		bestnode = bestnode->parent;
	}
	for (int v : bestx)
	{
		cout << v << " ";
	}
	cout << endl;

//利用分支限界算法 FIFO 队列解决背包问题
	Node1* node1 = nullptr;//初始状态
	int j = 0;//起始层数
	while (j < n1)
	{
		//选择物品 j
		int wt1 = cw1 + w1[j];
		if (wt1 <= c1)
		{
			if (cv1 + v1[j] > bestv1)
			{
				bestv1 = cv1 + v1[j];
			}
			addLiveNode1(cw1 + w1[j], cv1 + v1[j], j + 1, node1, true);
		}
		//不选择物品 j
		int upbound = maxBound2(j);
		if (cv1 + upbound >= bestv1)
		{
			addLiveNode1(cw1, cv1, j + 1, node1, false);
		}
		node1 = que1.front();
		que1.pop();
		j = node1->level;
		cw1 = node1->weight;
		cv1 = node1->value;
	}
	cout << bestv1 << endl;
	int bestx1[n1] = { 0 };
	for (int k = n1 - 1; k >= 0; k--)
	{
		bestx1[k] = bestnode1->isleft ? 1 : 0;
		bestnode1 = bestnode1->parent;
	}
	for (int v : bestx1)
	{
		cout << v << " ";
	}
	cout << endl;

//利用分支限界算法优先级队列解决背包问题
	Node2* node2 = nullptr;//初始状态
	int k = 0;//起始层数
	int upbound2 = maxBound2(0);
	while (k < n2)
	{
		//选择物品 k
		int wt2 = cw2 + w2[k];
		if (wt2 <= c2)
		{
			if (cv2 + v2[k] > bestv2)
			{
				bestv2 = cv2 + v2[k];
			}
			addLiveNode2(cw2 + w2[k], cv2 + v2[k], upbound2, k + 1, node2, true);
		}
		//不选择物品 k
		upbound2 = maxBound2(k + 1);//k + 1 表示第一个未被处理的物品的数组下标
		if (upbound2 >= bestv2)
		{
			addLiveNode2(cw2, cv2, upbound2, k + 1, node2, false);
		}
		node2 = que2.top();
		que2.pop();
		k = node2->level;
		cw2 = node2->weight;
		cv2 = node2->value;
		upbound2 = node2->upbound;
	}
	cout << bestv2 << endl;
	int bestx2[n2] = { 0 };
	for (int l = n2 - 1; l >= 0; l--)
	{
		bestx2[l] = node2->isleft ? 1 : 0;
		node2 = node2->parent;
	}
	for (int v : bestx2)
	{
		cout << v << " ";
	}
	cout << endl;

	system("pause");
    return 0;
}
*/


