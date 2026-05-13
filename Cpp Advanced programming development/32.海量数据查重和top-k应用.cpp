#include<iostream>
#include<vector>
#include<unordered_map>
#include<functional>
#include<queue>
using namespace std;

/*
int main()
{
//在一组数字中，找出重复次数最多的前 10 个数
	vector<int> vec;
	for (int i = 0; i < 200000; i++)
	{
		vec.push_back(rand());
	}
	//统计所有数字的重复次数，key：数字的值，value：数字重复的次数
	unordered_map<int, int> numMap;
	for (int val : vec)
	{
		numMap[val]++;
	}
	//自定义小根堆的大小比较方式
	using P = pair<int, int>;
	using FUNC = function<bool(P&, P&)>;
	using MinHeap = priority_queue<P, vector<P>, FUNC>;
	MinHeap minheap([](auto& a, auto& b)->bool
		{
			return a.second > b.second;
		});
	//先往堆放 10 个数据
	int k = 0;
	auto it = numMap.begin();
	//先从 map 表中读 10 个数据到小根堆中，建立 top-10 的小根 堆，最小的元素在堆顶
	for (; it != numMap.end() && k < 10; ++it, ++k)
	{
		minheap.push(*it);
	}
	//把 k + 1 到末尾的元素进行遍历，和堆顶元素比较
	for (; it != numMap.end(); ++it)
	{
		//如果 map 表中当前元素重复次数大于堆顶元素的重复次数，则替换
		if(it->second > minheap.top().second)
		{
			minheap.pop();
			minheap.emplace(*it);
		}
	}
	//堆中剩下的就是重复次数最大的前 k 个
	while (!minheap.empty())
	{
		auto& pair = minheap.top();
		cout << pair.first << " : " << pair.second << endl;
		minheap.pop();
	}

//有一个大文件，内存内存限制 200M，求文件中重复次数最多的前 10 个
	//大文件 -> 多个小文件
	//大文件里面的数据 -> 哈希映射 -> 把数据离散的放入小文件当中
	//大文件划分小文件（哈希映射）+ 哈希统计 + 小根堆（需要遍历所有元素）（快排分割）
	//打开存储数据的原始文件 data.dat
	cout << "----------大文件分治处理----------" << endl;
	FILE* pf1 = fopen("data.dat", "wb");
	for (int i = 0; i < 20000; i++)
	{
		int data = rand();
		fwrite(&data, 4, 1, pf1);
	}
	fclose(pf1);
	FILE* pf = fopen("data.dat", "rb");
	if (pf == nullptr)
	{
		return 0;
	}
	//由于原始数据量缩小，所有这里文件划分的个数也变小了
	const int FILE_NO = 11;
	FILE* pfile[FILE_NO] = { nullptr };
	for (int i = 0; i < FILE_NO; i++)
	{
		char filename[20];
		sprintf(filename, "data%d.dat", i + 1);
		pfile[i] = fopen(filename, "wb+");
	}
	//哈希映射，把大文件中的数据，映射到各个小文件中
	int data;
	while (fread(&data, 4, 1, pf) > 0)//从大文件 pf 中读取 1 个大小为 4 字节的数据块，存入 data，> 0 表示成功读取
	{
		int findex = data % FILE_NO;
		fwrite(&data, 4, 1, pfile[findex]);
	}
	unordered_map<int, int> numMap1;
	//自定义小根堆的大小比较方式
	MinHeap minheap1([](auto& a, auto& b)->bool
		{
			return a.second > b.second;
		});
	//分段求解小文件的 top-10 大的数字，并求出最终结果
	for (int i = 0; i < FILE_NO; i++)
	{
		//恢复小文件的文件指针到起始位置
		fseek(pfile[i], 0, SEEK_SET);
		while (fread(&data, 4, 1, pfile[i]) > 0)
		{
			numMap1[data]++;
		}
		int k = 0;
		auto it = numMap1.begin();
		//如果堆空，先往堆放入 10 个数据
		if (minheap1.empty())
		{
			//先从 map 表中读 10 个数据到小根堆中，建立 top-10 的小根 堆，最小的元素在堆顶
			for (; it != numMap1.end() && k < 10; ++it, ++k)
			{
				minheap1.push(*it);
			}
		}
		//把 k + 1 到末尾的元素进行遍历，和堆顶元素比较
		for (; it != numMap1.end(); ++it)
		{
			//如果 map 表中当前元素重复次数大于堆顶元素的重复次数，则替换
			if (it->second > minheap1.top().second)
			{
				minheap1.pop();
				minheap1.emplace(*it);
			}
		}
		//清空哈希表，进行下一个小文件的数据统计
		numMap1.clear();
	}
	//堆中剩下的就是重复次数最大的前 k 个
	while (!minheap1.empty())
	{
		auto& pair = minheap1.top();
		cout << pair.first << " : " << pair.second << endl;
		minheap1.pop();
	}
	fclose(pf);

	system("pause");
	return 0;
}
*/
