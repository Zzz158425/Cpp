#include<iostream>
#include<stack>
using namespace std;
//2026.5.1

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
		_pMaze = new Node* [_row];
		for (int i = 0; i < _row; i++)
		{
			_pMaze[i] = new Node[_col];
		}
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
		_stack.push(_pMaze[0][0]);
		while (!_stack.empty())
		{
			Node top = _stack.top();
			int x = top._x;
			int y = top._y;
			if (x == _row - 1 && y == _col - 1)
			{
				return;
			}
			//往右方向寻找
			if (_pMaze[x][y]._state[RIGHT] == YES)
			{
				_pMaze[x][y]._state[RIGHT] = NO;
				_pMaze[x][y + 1]._state[LEFT] = NO;
				_stack.push(_pMaze[x][y + 1]);
				continue;
			}
			//往下方向寻找
			if (_pMaze[x][y]._state[DOWN] == YES)
			{
				_pMaze[x][y]._state[DOWN] = NO;
				_pMaze[x + 1][y]._state[UP] = NO;
				_stack.push(_pMaze[x + 1][y]);
				continue;
			}
			//往左方向寻找
			if (_pMaze[x][y]._state[LEFT] == YES)
			{
				_pMaze[x][y]._state[LEFT] = NO;
				_pMaze[x][y - 1]._state[RIGHT] = NO;
				_stack.push(_pMaze[x][y - 1]);
				continue;
			}
			//往上方向寻找
			if (_pMaze[x][y]._state[UP] == YES)
			{
				_pMaze[x][y]._state[UP] = NO;
				_pMaze[x - 1][y]._state[DOWN] = NO;
				_stack.push(_pMaze[x - 1][y]);
				continue;
			}
			_stack.pop();
		}
	}
	//打印迷宫路径搜索结果
	void showMazePath()
	{
		if (_stack.empty())
		{
			cout << "不存在一条迷宫路径！" << endl;
		}
		else
		{
			while (!_stack.empty())
			{
				Node top = _stack.top();
				_pMaze[top._x][top._y]._val = '*';
				_stack.pop();
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
	stack<Node> _stack;//栈结构，辅助深度搜索迷宫路径
};

int main()
{
//深度优先遍历搜索迷宫路径
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
	//算法思想：
		//利用栈的 “后进先出” 特性，优先深入探索某一条路径，走不通时弹出栈顶回溯，直到找到终点或遍历完所有可能
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