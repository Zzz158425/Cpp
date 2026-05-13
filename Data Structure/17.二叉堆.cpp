#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>//引入预定义的比较函数
using namespace std;

/*
//基于堆的优先级队列代码实现
class PriorityQueue
{
public:
	using Comp = function<bool(int, int)>;//把 function<bool(int, int)> 这个冗长的类型名，简化成短名称 Comp，类模板
	PriorityQueue(int cap = 20, Comp comp = greater<int>())
		: size_(0)
		, cap_(cap)
		, comp_(comp)
	{
		que_ = new int[cap_];
	}
	PriorityQueue(Comp comp)
		: size_(0)
		, cap_(20)
		, comp_(comp)
	{
		que_ = new int[cap_];
	}
	~PriorityQueue()
	{
		delete[]que_;
		que_ = nullptr;
	}
public:
	//入堆操作
	void push(int val)
	{
		if (size_ == cap_)//判断是否扩容
		{
			//扩容
			int* p = new int[2 * cap_];
			memcpy(p, que_, cap_ * sizeof(int));
			delete[]que_;
			que_ = p;
			cap_ *= 2;
		}
		if (size_ == 0)//只有一个元素，不用进行堆的上浮调整
		{
			que_[size_] = val;
		}
		else//堆有多个元素，需要进行堆的上浮调整
		{
			siftUp(size_, val);//入堆上浮
		}
		size_++;
	}
	//出推操作
	void pop()
	{
		if (size_ == 0)
		{
			throw "container is empty";
		}
		size_--;//把末尾元素放到堆顶
		if (size_ > 0)
		{
			siftDown(0, que_[size_]);//删除堆顶元素，还有剩余的元素，要进行堆的下沉调整
		}
	}
	//堆是否为空
	bool empty() const
	{
		return size_ == 0;
	}
	//获取堆顶元素
	int top() const
	{
		if (size_ == 0)
		{
			throw "container is empty";
		}
		return que_[0];
	}
	//获取堆个数
	int size() const
	{
		return size_;
	}
private:
	//入堆上浮调整 O(logn)
	void siftUp(int i, int val)
	{
		while (i > 0)//最多计算到根节点
		{
			int father = (i - 1) / 2;//父节点
			if (comp_(val, que_[father]))//若 val > que_[father] 上浮
			{
				que_[i] = que_[father];
				i = father;
			}
			else
			{
				break;
			}
		}
		//把 val 放到 i 的位置
		que_[i] = val;
	}
	//出堆下沉调整 O(logn)
	void siftDown(int i, int val)
	{
		while (i < size_ / 2)//i 下沉不能超过最后一个有孩子的节点，i <= (size_-1 - 1) / 2 -> i <= size_ /2 - 1 -> i < size_ /2
		{
			int child = 2 * i + 1;//第 i 个节点的左孩子
			if (child + 1 < size_ && comp_(que_[child + 1],que_[child]))//有右孩子，且右孩子大于左孩子
			{
				child = child + 1;//如果 i 节点右孩子的值大于左孩子，child 记录右孩子的下标
			}
			if (comp_(que_[child], val))
			{
				que_[i] = que_[child];
				i = child;
			}
			else
			{
				break;//已经满足堆的性质，提前结束
			}
		}
		que_[i] = val;
	}
private:
	int* que_;//指向动态扩容的数组
	int size_;//数组元素的个数
	int cap_;//数组的总空间大小
	Comp comp_;//比较器对象
};

//堆排序算法
//堆下沉调整
void siftDown(int arr[], int i, int size)
{
	int val = arr[i];
	while (i < size / 2)
	{
		int child = 2 * i + 1;
		if (child + 1 < size && arr[child + 1] > arr[child])
		{
			child = child + 1;
		}
		if (val < arr[child])
		{
			arr[i] = arr[child];
			i = child;
		}
		else
		{
			break;
		}
	}
	arr[i] = val;
}
void HeapSort(int arr[], int size)
{
	int n = size - 1;//末尾元素下标
	//从第一个非叶子节点开始，进行下沉操作调整为大根堆
	for (int i = (n - 1) / 2; i >= 0; i--)
	{
		siftDown(arr, i, size);
	}
	//把堆顶元素和末尾元素进行交换，从堆顶开始进行下沉操作
	for (int i = n; i > 0; i--)
	{
		//堆顶元素和末尾元素进行交换
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		siftDown(arr, 0, i);//从堆顶开始进行下沉操作，i 表示参与下沉的元素个数
	}

}

int main()
{
//二叉堆 2026.2.11
	//就是一颗完全二叉树，分为两种典型的堆，分别是大根堆和小根堆，可用来实现优先级队列
	//         12
	//    11        7
	//  8    9    3   2
	//5   6
	//arr[] = { 12 11 7 8 9 3 2 5 6 }
	//逻辑上是一颗完全二叉树，存储方式上还是用数组进行存储，完全：最后一层的叶子节点都是靠左排列
	//当前节点与孩子节点关系：当前节点 i，左孩子 (2 * i) + 1，右孩子 (2 * i) + 2
	//基于二叉堆的基础，规定了当前节点和两个孩子节点值的大小关系，从而分为大根堆和小根堆
		//满足 0 <= i <= (n-1)/2（有孩子节点的范围），n 代表最后一个元素的下标
		//如果 arr[i] <= arr[2 * i + 1] && arr[i] <= arr[2 * i + 2]，就是小根堆
		//如果 arr[i] >= arr[2 * i + 1] && arr[i] >= arr[2 * i + 2]，就是大根堆

//堆的上浮和下沉调整
	//大根堆入堆（上浮）：把新插入到堆末尾的元素，从下往上逐层和父节点比较，若不满足堆规则则交换位置，直到找到合适的位置，让堆恢复有序
	//大根堆出堆（下沉）：删除堆顶后用最后一个元素替换根，从根节点开始，从上往下逐层和子节点比较，若不满足堆规则则与 “更符合堆规则的子节点”交换，直到找到合适位置，恢复堆规则

//基于堆的优先级队列代码实现
	PriorityQueue que;
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		que.push(rand() % 100);
	}
	while (!que.empty())
	{
		cout << que.top() << " ";
		que.pop();
	}
	cout << endl;
	PriorityQueue que1([](int a, int b) {return a < b; });//基于小根堆实现的优先级队列，[](int a, int b) {return a < b; }为 lambda 表达式
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		que1.push(rand() % 100);
	}
	while (!que1.empty())
	{
		cout << que1.top() << " ";
		que1.pop();
	}
	cout << endl;

//堆排序算法
	//1.从第一个非叶子节点 (n - 1) / 2 开始，把二叉堆调整成一个大根堆，即从 (n - 1) / 2 号位元素开始到堆顶元素，进行下沉操作
	//2.把堆顶元素和末尾元素进行交换，从 0 号位继续开始进行堆的下沉调整，此时不再考虑末尾元素（调整前的堆顶元素）
	//3.重复上述步骤
	int arr[10];
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 100 + 1;
	}
	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;
	HeapSort(arr, 10);
	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;

//堆排序算法性能指标
	//平均时间复杂度 O(n*logn)
		//最好时间复杂度 O(n*logn)
		//最坏时间复杂度 O(n*logn)
		//空间复杂度 O(1)
		//稳定性：不稳定

	system("pause");
	return 0;
}
*/