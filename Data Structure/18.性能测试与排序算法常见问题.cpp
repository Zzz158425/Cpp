#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;

/*
//快排 归并 希尔 堆排性能测试 2026.2.22
//快排
//快排分割处理函数
int Partation(int arr[], int l, int r)
{
	int val = arr[l];//记录基准数
	//快速排序 
	while (l < r)
	{
		//右往左找
		while (l < r && arr[r] > val)
		{
			r--;
		}
		if (l < r)
		{
			arr[l] = arr[r];
			l++;
		}
		//左往右找
		while (l < r && arr[l] < val)
		{
			l++;
		}
		if (l < r)
		{
			arr[r] = arr[l];
			r--;
		}
	}
	arr[l] = val;//放置基准数
	return l;//返回基准数位置
}
//快排递归接口
void QuickSort(int arr[], int begin, int end)
{
	//快排递归结束条件
	if (begin >= end)
	{
		return;
	}
	int pos = Partation(arr, begin, end);//快排分割
	//对基准数的左边和右边的序列，再分别进行快排
	QuickSort(arr, begin, pos - 1);
	QuickSort(arr, pos + 1, end);
}
void QuickSort(int arr[], int size)
{
	return QuickSort(arr, 0, size - 1);
}

//快速排序优化
int Partation_optimize(int arr[], int l, int r)
{
	int val = arr[l];//记录基准数
	//快速排序 
	while (l < r)
	{
		//右往左找
		while (l < r && arr[r] > val)
		{
			r--;
		}
		if (l < r)
		{
			arr[l] = arr[r];
			l++;
		}
		//左往右找
		while (l < r && arr[l] < val)
		{
			l++;
		}
		if (l < r)
		{
			arr[r] = arr[l];
			r--;
		}
	}
	arr[l] = val;//放置基准数
	return l;//返回基准数位置
}
//快排递归接口
void QuickSort_optimize(int arr[], int begin, int end)
{
	//快排递归结束条件
	if (begin >= end)
	{
		return;
	}
	//优化一：当 [begin, end] 序列的元素个数小到指定数量，采用插入排序
	//if (end - begin <= 50)
	//{
	//	InserSort(arr, begin, end);
	//	return;
	//}
	int pos = Partation_optimize(arr, begin, end);//快排分割
	//对基准数的左边和右边的序列，再分别进行快排
	QuickSort_optimize(arr, begin, pos - 1);
	QuickSort_optimize(arr, pos + 1, end);
}
void QuickSort_optimize(int arr[], int size)
{
	return QuickSort_optimize(arr, 0, size - 1);
}

//归并
//归并过程函数
void Merge(int arr[], int l, int m, int r, int *p)
{
	//int* p = new int[r - l + 1];（优化）
	int idx = 0;
	int i = l;
	int j = m + 1;
	while (i <= m && j <= r)
	{
		if (arr[i] <= arr[j])
		{
			p[idx++] = arr[i++];
		}
		else
		{
			p[idx++] = arr[j++];
		}
	}
	//左边有剩余
	while (i <= m)
	{
		p[idx++] = arr[i++];
	}
	//右边有剩余
	while (j <= r)
	{
		p[idx++] = arr[j++];
	}
	//再把合并好的大端有序结果，拷贝到原始 arr 数组 [1, r] 区间内
	for (i = l, j = 0; i <= r; i++, j++)
	{
		arr[i] = p[j];
	}
	//delete[]p;//释放内存（优化）
}
//归并排序递归接口
void MergeSort(int arr[], int begin, int end,int *p)
{
	//归并排序递归结束条件
	if (begin >= end)
	{
		return;
	}
	int mid = (begin + end) / 2;
	//先递
	MergeSort(arr, begin, mid, p);
	MergeSort(arr, mid + 1, end, p);
	//后归并，把 [begin, mid] 与 [mid + 1, end] 把两个小段有序的序列，合并成大端有序的序列
	Merge(arr, begin, mid, end, p);

}
void MergeSort(int arr[], int size)
{
	//优化 一开始直接申请 size 长度的数组指针，不再需要在 Merge 的过程中频繁开辟释放
	int* p = new int[size];
	MergeSort(arr, 0, size - 1, p);
	delete[] p;
}

//希尔
void ShellSort(int arr[], int size)
{
	for (int gap = size / 2; gap > 0; gap /= 2)//分组
	{
		for (int i = gap; i < size; i++)//对每组内元素进行排序
		{
			//对每组内元素进行插入排序
			int val = arr[i];
			int j = i - gap;
			for (; j >= 0; j -= gap)
			{
				if (arr[j] <= val)
				{
					break;
				}
				arr[j + gap] = arr[j];
			}
			arr[j + gap] = val;
		}
	}
}

//堆排
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
			if (child + 1 < size_ && comp_(que_[child + 1], que_[child]))//有右孩子，且右孩子大于左孩子
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
//快排 归并 希尔 堆排性能测试 2026.2.22
	//不管是快排，或者是归并排序，遍历元素的时候都是按照顺序遍历的，对 CPU 缓存友好（CPU 缓存命中率高）
	//堆排序访问元素时，是按照父子节点的关系进行访问的，并不是按照顺序访问的，所以排序过程中，不管是进行元素上浮/下沉调整，对 CPU 缓存不友好
	//堆排序的过程中，进行元素下沉调整所做的无效比较较多，即末尾元素本身比较小，与堆顶元素交换后下沉次数多，中间做了很多比较
	const int COUNT = 100000000;
	//数据达 100000000 时堆内存申请过多会出错，换一种测试方式
	int* arr1 = new int[COUNT];//存放拷贝数据
	int* arr2 = new int[COUNT];//存放排序数据
	//int* arr3 = new int[COUNT];
	//int* arr4 = new int[COUNT];
	srand(time(NULL));
	for (int i = 0; i < COUNT; i++)
	{
		int val = rand() % COUNT + 1;
		arr1[i] = val;
		//arr2[i] = val;
		//arr3[i] = val;
		//arr4[i] = val;
	}
	clock_t begin, end;
	memcpy(arr2, arr1, COUNT * sizeof(int));
	begin = clock();
	QuickSort(arr2, COUNT);
	end = clock();
	cout << "QuickSort Spend:" << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;//将 clock() 返回的滴答数转换为直观的秒数，其中滴答数：时钟滴答数 / 时钟脉冲数
	memcpy(arr2, arr1, COUNT * sizeof(int));
	begin = clock();
	MergeSort(arr2, COUNT);
	end = clock();
	cout << "MergeSort Spend:" << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;
	memcpy(arr2, arr1, COUNT * sizeof(int));
	begin = clock();
	ShellSort(arr2, COUNT);
	end = clock();
	cout << "ShellSort Spend:" << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;
	memcpy(arr2, arr1, COUNT * sizeof(int));
	begin = clock();
	HeapSort(arr2, COUNT);
	end = clock();
	cout << "HeapSort Spend:" << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;

//排序算法常见问题
	//STL 里 sort 算法用的是什么排序算法？
		//答：快排，个数过小会采用插排(N < 32)，当快排递归深度过大，该改为堆排，防止撑破栈
	//快速排序的时间复杂度不是稳定的 nlogn，最坏情况会变成 n^2，怎么解决复杂度恶化问题？
		//答：三数取中，选择合理的基准数
	//快速排序递归实现时，怎么解决递归层次过深的问题？
		//答：当递归到某一深度时，进行堆排序
	//递归过深会引发什么问题？
		//答：函数调用次数过多，函数开销大（从指令角度掌握函数调用堆栈详细过程），会导致栈内存溢出，程序挂掉
	//怎么控制递归深度？如果达到递归深度了还没排完序怎么办？
		//答：设置递归深度值，每执行一次递归缩减递归深度值，当其小于 0 时，进行堆排序
	//个数约为 50K 的数列需要进行从小到大排序，数列特征是基本逆序(多数数字从大到小，个别乱序)，以下哪种排序算法在事先不了解数列特征的情况下性能最优
	//A.冒泡排序 B.改进冒泡排序 C.选择排序 D.快速排序 E.堆排序 F.插入排序
		//答：快速排序期望序列越乱越好，插入期望序列趋于有序，排序堆排序无论何种序列性能趋近，选择 E
	//现有 1GB 数据进行排序，计算资源只有 1GB 内存可用，下列排序方法中最可能出现性能问题的是
	//A.堆排序 B.插入排序 C.归并排序 D.快速排序 E.选择排序 F.冒泡排序
		//答：只能原地排序，归并排序空间复杂度：O(n) + O(logn)（取大值，可忽略），选择 C
	//假设你只有 100Mb 的内存，需要对 1Gb 的数据进行排序，最合适的算法是
	//A.归并排序 B.插入排序 C.快速排序 D.冒泡排序
		//答：内排序：数据都在内存上，外排序：内存小，数据量大，无法将所有数据加载到内存上，只有归并排序能实现外排序，选择 A

	system("pause");
	return 0;
}
*/