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
//有向图的领接表实现
class Digraph
{
public:
	//从配置文件读入顶点和边的信息，生成领接表，配置文件 data.txt 在资源文件中
	void readFile(string filePath)
	{
		FILE* pf = fopen(filePath.c_str(), "r");
		if (pf == nullptr)
		{
			throw filePath + "not exists!";
		}
		vertics.emplace_back("");//占用第 0 号位置
		//读取文件
		while (!feof(pf))
		{
			char line[1024] = { 0 };
			fgets(line, 1024, pf);//从文件 pf 中读取一行内容到 line 数组
			//增加一个节点信息
			string linestr(line);
			vertics.emplace_back(linestr.substr(0, linestr.size() - 1));
			fgets(line, 1024, pf);//再次调用 fgets 读取下一行到 line
			char* vertic_no = strtok(line, ",");//用 strtok 逐次按逗号 "," 分割 line 字符串
			while (vertic_no != nullptr)
			{
				int vex = atoi(vertic_no);
				if (vex > 0)
				{
					vertics.back().adjList_.emplace_back(atoi(vertic_no));
				}
				vertic_no = strtok(nullptr, ",");
			}
		}
		fclose(pf);
	}
	//输出领接表信息
	void Show() const
	{
		for (int i = 1; i < vertics.size(); i++)
		{
			cout << vertics[i].data_ << ":";
			for (auto no : vertics[i].adjList_)
			{
				cout << no << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	//图的深度优先遍历接口
	void dfs()
	{
		vector<bool> visited(vertics.size(), false);
		dfs(1, visited);
		cout << endl;
	}
	//图的广度优先遍历
	void bfs()
	{
		vector<bool> visited(vertics.size(), false);
		queue<int> que;
		que.push(1);
		visited[1] = true;
		while (!que.empty())
		{
			int cur_no = que.front();
			que.pop();
			cout << vertics[cur_no].data_ << " ";
			for (auto no : vertics[cur_no].adjList_)
			{
				if (!visited[no])
				{
					que.push(no);
					visited[no] = true;
				}
			}
		}
		cout << endl;
	}
	//求不带权值的最短路径问题（图的广度优先遍历）
	void shortPath(int start, int end)
	{
		vector<bool> visited(vertics.size(), false);
		queue<int> que;
		vector<int> path(vertics.size(), 0);//记录顶点在遍历过程中的前后遍历关系
		que.push(start);
		visited[start] = true;
		while (!que.empty())
		{
			int cur_no = que.front();
			//找到 end 末尾节点了
			if (cur_no == end)
			{
				break;
			}
			que.pop();
			for (auto no : vertics[cur_no].adjList_)
			{
				if (!visited[no])
				{
					que.push(no);
					visited[no] = true;
					path[no] = cur_no;//当前节点处，记录是从哪一个节点过来的
				}
			}
		}
		if (!que.empty())
		{
			//while (end != 0)
			//{
			//	cout << vertics[end].data_ << " <- ";
			//	end = path[end];
			//}
			showPath(end, path);
		}
		else
		{
			cout << "不存在有效的最短路径！" << endl;
		}
		cout << endl;
	}
private:
	//顶点类型
	struct Vertic
	{
		Vertic(string data)
			:data_(data)
		{ }
		string data_;//存储顶点的信息
		list<int> adjList_;//领接链表结构
	};
	vector<Vertic> vertics;//领接表结构
	//图的深度优先遍历实现
	void dfs(int start, vector<bool>& visited)
	{
		//该 start 顶点已经遍历过了
		if (visited[start])
		{
			return;
		}
		cout << vertics[start].data_ << " ";
		visited[start] = true;
		//递归遍历下一层节点
		for (auto no : vertics[start].adjList_)
		{
			dfs(no, visited);
		}
	}
	//输出最短路径信息
	void showPath(int end, vector<int>& path)
	{
		if (end == 0)
		{
			return;
		}
		showPath(path[end], path);
		cout << vertics[end].data_ << " ";
	}
};

int main()
{
//有向图与无向图
	//有向图：
		//是由一个有限的称为顶点(vertices)的元素集合以及一个有限的连接每对顶点的有向边的集合组成的，简写为 digraph
		//和树的区别是，有向图不需要指定一个根节点，并且一个节点到另一个节点之间可能存在好几条（或者没有）的路径
		//出向边：从该顶点出发的边
		//入向边：到达该顶点的边
		//节点的入度：终点是当前节点的边的个数
		//节点的出度：起点是当前节点的边的个数
	//无向图：
		//在建模通信网络，设备节点，城市节点的时候，可以用图来表示从一个节点通过不同的路径流向另一个节点的过程
		//在另外一些应用场景当中，节点之间的连接是没有方向的，可以使用图来进行建模
		//没有入向边与出向边的区分，顶点没有到达自己顶点位置的边
		//顶点的度：与该顶点所关联的边的个数

//图的存储结构 2026.4.18
	//领接矩阵
		//将有向图中所有的顶点编号为 1,2,...,n，邻接矩阵是一个 n x n 的矩阵
		//如果节点 j 邻接于节点i(也就是有一条有向边从节点 i 指向节点)，则矩阵中第 i 行第 j 列的元素为 1，否则这个元素的值为 0
		//有向图：
			//对于带权有向图，在领接矩阵表示的时候，顶点 i 到顶点 j 的 1 就被权值所替换
			//有向图的邻接矩阵来说，如果邻接矩阵是一个稀疏矩阵（顶点多，边少）的话，存储的效率太低（空间利用率太低）
			//          1 -> 2 <- 6 
			//         / \   |\     \
			//5 <- 5 <-   -> 4 -> 3 <-
			//      0 1 0 1 1 0   1 -> 2,4,5   行 1 的个数为该顶点出度，列 1 的个数为顶点入度
			//      0 0 1 1 0 0   2 -> 3,4   
			//adj = 0 0 0 0 0 0 
			//      0 1 1 0 0 0   4 -> 2,3
			//		0 0 0 0 1 0   5 -> 5
			//      0 1 1 0 0 0   6 -> 2,3
		//无向图：
			//1.对角线上全部是 0
			//2.以对角线为中心，左下和右上的存储完全是对称的		
			//3.无向图的邻接矩阵同样存在存储的效率太低的情况
	//领接表
		//将有向图表示为一个数组或向量 v[1],v[2],...,v[n]，每个元素对应有向图的一个节点，每个 v[] 存储顶点i中的数据，以及一个包含所有邻接于顶点的顶点编号的链表
		//领接表只描述顶点的出度，遍历整个领接表，才能知道顶点的入度；逆领接表是描述顶点入度，遍历整个领接表，才能知道顶点的出度
		//可采用十字链表来优化存储
		//有向图：
			//          1 -> 2 <- 6 
			//         / \   |\     \
			//5 <- 5 <-   -> 4 -> 3 <-
			// ---     -----     -----     -----
			//| 1 |---| 2 | |---| 4 | |---| 5 | |
			// ---     -----     -----     -----
			//| 2 |---| 3 | |---| 4 | |
			// ---     -----     -----
			//| 3 |
			// ---     -----     -----
			//| 4 |---| 2 | |---| 3 | |
			// ---     -----     -----
			//| 5 |---| 5 | |
			// ---     -----     -----
			//| 5 |---| 2 | |---| 3 | |
			// ---     -----     -----
		//无向图：
			//1.数据存储存在一定冗余
			//2.可采用领接多重表来减少冗余

//有向图与无向图的链式存储结构
	//十字链表：有向图的另一种链式存储结构
		//顶点结构：
			//-----------------------------
			//| data | firstin | firstout |
			//-----------------------------
			//data：顶点信息
			//firstin：指向该顶点入边表中的第一个节点
			//firstout：指向该顶点处边表中的第一个节点
		//边表节点结构：
			//-------------------------------------
			//| tailvex | headvex | hlink | tlink |
			//-------------------------------------
			//tailvex：弧起点在顶点的下标
			//headvex：弧终点在顶点的下标
			//hlink：入边表指针域，指向终点相同的下一条边
			//tlink：出边表指针域，指向起点相同的下一条边
	//领接多重表：无向图的另一种链式存储结构
		//顶点结构：
			//--------------------
			//| data | firstedge |
			//--------------------
			//data：顶点信息
			//firstedge：存储指针域
		//边表节点结构：
			//-------------------------------------
			//| mark | ivec | ilink | jvec | jlink|
			//-------------------------------------
			//mark：存储标记信息
			//ivex、jvex：一条边依附的两个顶点的下标
			//ilink：指向依附顶点 ivex 的下条边
			//jlink：指向依附顶点 jvex 的下条边

//图的深度与广度优先遍历
	//与树的前序与层序遍历类似

//有向图的领接表实现
	Digraph grapg;
	grapg.readFile("data.txt");
	grapg.Show();
	grapg.dfs();
	grapg.bfs();
	grapg.shortPath(1, 9);

	system("pause");
	return 0;
}
*/