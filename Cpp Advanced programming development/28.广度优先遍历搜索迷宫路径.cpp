#include<iostream>
#include<queue>
#include<vector>
using namespace std;

/*
//定义迷宫每一个节点的四个方向
const int RIGHT = 0;
const int DOWN = 1;
const int LEFT = 2;
const int UP = 3;
//迷宫每一个节点方向的数量
const int WAY_NUM = 4;
//定义节点行走状态
const int YES = 4;
const int NO = 5;
//迷宫
class Maze
{
public:
	Maze(int row, int col)
		: _row(row)
		, _col(col)
	{
		_pMaze = new Node * [_row];
		for (int i = 0; i < _row; i++)
		{
			_pMaze[i] = new Node[_col];
		}
		_pPath.resize(_row * _col);//node._x * _row + node._y
	}
public:
	//初始化迷宫路径节点信息
	void initNode(int x, int y, int val)
	{
		_pMaze[x][y]._x = x;
		_pMaze[x][y]._y = y;
		_pMaze[x][y]._val = val;
		//节点四个方向默认初始化
		for (int i = 0; i < WAY_NUM; i++)
		{
			_pMaze[x][y]._state[i] = NO;
		}
	}
	//初始化四个方向的可走状态
	void setNodeState()
	{
		for (int i = 0; i < _row; i++)
		{
			for (int j = 0; j < _col; j++)
			{
				//当前节点无法走到，所以不需要调整其右下左上方向的状态
				if (_pMaze[i][j]._val == 1)
				{
					continue;
				}
				//判断右边能否走
				if (j < _col - 1 && _pMaze[i][j + 1]._val == 0)
				{
					_pMaze[i][j]._state[RIGHT] = YES;
				}
				//判断下边能否走
				if (i < _row - 1 && _pMaze[i + 1][j]._val == 0)
				{
					_pMaze[i][j]._state[DOWN] = YES;
				}
				//判断左边能否走
				if (j > 0 && _pMaze[i][j - 1]._val == 0)
				{
					_pMaze[i][j]._state[LEFT] = YES;
				}
				//判断上边能否走
				if (i > 0 && _pMaze[i - 1][j]._val == 0)
				{
					_pMaze[i][j]._state[UP] = YES;
				}
			}
		}
	}
	//深度搜索迷宫路径
	void searchMazePath()
	{
		if (_pMaze[0][0]._val == 1)
		{
			return;
		}
		_queue.push(_pMaze[0][0]);
		while (!_queue.empty())
		{
			Node front = _queue.front();
			int x = front._x;
			int y = front._y;
			if (x == _row - 1 && y == _col - 1)
			{
				return;
			}
			//往右方向寻找
			if (_pMaze[x][y]._state[RIGHT] == YES)
			{
				_pMaze[x][y]._state[RIGHT] = NO;
				_pMaze[x][y + 1]._state[LEFT] = NO;
				_pPath[x * _row + y + 1] = _pMaze[x][y];//在辅助数组中记录一下节点的行走信息
				_queue.push(_pMaze[x][y + 1]);
				if (check(_pMaze[x][y + 1]))
				{
					return;
				}
			}
			//往下方向寻找
			if (_pMaze[x][y]._state[DOWN] == YES)
			{
				_pMaze[x][y]._state[DOWN] = NO;
				_pMaze[x + 1][y]._state[UP] = NO;
				_pPath[(x + 1) * _row + y] = _pMaze[x][y];//在辅助数组中记录一下节点的行走信息
				_queue.push(_pMaze[x + 1][y]);
				if (check(_pMaze[x  + 1][y]))
				{
					return;
				}
			}
			//往左方向寻找
			if (_pMaze[x][y]._state[LEFT] == YES)
			{
				_pMaze[x][y]._state[LEFT] = NO;
				_pMaze[x][y - 1]._state[RIGHT] = NO;
				_pPath[x * _row + y - 1] = _pMaze[x][y];//在辅助数组中记录一下节点的行走信息
				_queue.push(_pMaze[x][y - 1]);
				if (check(_pMaze[x][y - 1]))
				{
					return;
				}
			}
			//往上方向寻找
			if (_pMaze[x][y]._state[UP] == YES)
			{
				_pMaze[x][y]._state[UP] = NO;
				_pMaze[x - 1][y]._state[DOWN] = NO;
				_pPath[(x - 1) * _row + y] = _pMaze[x][y];//在辅助数组中记录一下节点的行走信息
				_queue.push(_pMaze[x - 1][y]);
				if (check(_pMaze[x - 1][y]))
				{
					return;
				}
			}
			_queue.pop();
		}
	}
	//打印迷宫路径搜索结果
	void showMazePath()
	{
		if (_queue.empty())
		{
			cout << "不存在一条迷宫路径！" << endl;
		}
		else
		{
			int x = _row - 1;
			int y = _col - 1;
			for (;;)
			{
				_pMaze[x][y]._val = '*';
				if (x == 0 && y == 0)
				{
					break;
				}
				Node node = _pPath[x * _row + y];
				x = node._x;
				y = node._y;
			}
			for (int i = 0; i < _row; ++i)
			{
				for (int j = 0; j < _col; ++j)
				{
					if (_pMaze[i][j]._val == '*')
					{
						cout << "* ";
					}
					else
					{
						cout << _pMaze[i][j]._val << " ";
					}
				}
				cout << endl;
			}
		}
	}
private:
	//定义迷宫节点路径信息
	struct Node
	{
		int _x;
		int _y;
		int _val;//节点的值
		int _state[WAY_NUM];//记录节点四个方向状态
	};
	Node** _pMaze;//动态生成迷宫路径
	int _row;
	int _col;
	queue<Node> _queue;//广度优先遍历依赖队列结构
	vector<Node> _pPath;//记录广度优先遍历时，节点的行走信息
	bool check(Node& node)
	{
		return node._x == _row - 1 && node._y == _col - 1;
	}
};

int main()
{
//广度优先遍历搜索迷宫路径
	//请输入迷宫的行列数（例如：10 10）：5 5
	//请输入迷宫的路径信息（0 表示可以走，1 表示不能走）：
		//0 0 0 1 1
		//1 0 0 0 1
		//1 1 0 1 1
		//1 1 0 0 1
		//1 1 1 0 0
	//迷宫路径搜索中...
	//如果没有路径，直接输出：不存在一条迷宫路径！
	//如果有路径，直接输出
		//* * * 1 1
		//1 0 * 0 1
		//1 1 * 1 1
		//1 1 * * 1
		//1 1 1 * *
	//深度优先遍历搜索迷宫路径可能无法找到最优路径
		//请输入迷宫的行列数（例如：10 10）：6 6
		//请输入迷宫的路径信息（0 表示可以走，1 表示不能走）：
		//0 0 1 1 1 1
		//1 0 0 0 0 1
		//1 0 1 1 0 1
		//1 0 0 0 0 1
		//1 0 1 1 1 1
		//1 0 0 0 0 0
		//* * 1 1 1 1
		//1 * * * * 1
		//1 0 1 1 * 1
		//1 * * * * 1
		//1 0 1 1 1 1
		//1 * * * * *
	//深度优先遍历 -> 栈
	//广度优先遍历 -> 层层扩张的方式 -> 队列
	//算法思想： 
		//利用队列的 “先进先出” 特性，从起点开始，像水波纹一样一层一层向外扩散探索
		//第一次到达终点的路径即为最短路径；同时通过前驱数组记录路径，最后反向回溯标记结果
	cout << "请输入迷宫的行列数（例如：10 10）：";
	int row, col, data;
	cin >> row >> col;
	Maze maze(row, col);//创建迷宫对象
	cout << "请输入迷宫的路径信息（0 表示可以走，1 表示不可以走）：" << endl;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cin >> data;
			maze.initNode(i, j, data);//初始化迷宫节点的基本信息
		}
	}
	maze.setNodeState();//设置所有节点的四个方向的状态
	maze.searchMazePath();//开始从左上角搜索迷宫的路径信息
	maze.showMazePath();//打印迷宫路径搜索结果

	system("pause");
	return 0;
}
*/