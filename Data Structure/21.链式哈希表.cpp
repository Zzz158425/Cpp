#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
#include<list>
using namespace std;

/*
//链式哈希表算法实现
class HashTable
{
public:
	HashTable(int size = primes_[0], double loadFactor = 0.75)
		: loadFactor_(loadFactor)
		, useBucketNum_(0)
		, primeIdx_(0)
	{
		//把用户传入的 size 调整到最近的比较大的素数上
		if (size != primes_[0])
		{
			for (; primeIdx_ < PRIME_SIZE; primeIdx_++)
			{
				if (primes_[primeIdx_] >= size)
				{
					break;
				}
			}
			//用户传入的 size 值过大，已经超过最后一个素数，调整到最后一个素数
			if (primeIdx_ == PRIME_SIZE)
			{
				primeIdx_--;
			}
		}
		table_.resize(primes_[primeIdx_]);//reserve 只能预留空间，resize 不仅会开辟空间还会创建元素
	}
public:
	//增加元素，不能重复插入 key
	void insert(int key)
	{
		double factor = useBucketNum_ * 1.0 / table_.size();
		cout << "factor:" << factor << endl;
		//判断是否扩容
		if (factor > loadFactor_)
		{
			expand();//扩容
		}
		int idx = key % table_.size();//O(1)
		if (table_[idx].empty())
		{
			useBucketNum_++;
			table_[idx].emplace_front(key);
		}
		else
		{
			auto it = ::find(table_[idx].begin(), table_[idx].end(), key);//使用全局的 ::find 泛型算法，而不是调用自己的成员方法 O(n)
			if (it == table_[idx].end())
			{
				table_[idx].emplace_front(key);//key 不存在
			}
		}
	}
	//删除元素
	void erase(int key)
	{
		int idx = key % table_.size();//O(1)
		auto it = ::find(table_[idx].begin(), table_[idx].end(), key);//使用全局的 ::find 泛型算法，而不是调用自己的成员方法 O(n)
		if (it != table_[idx].end())
		{
			table_[idx].erase(it);
			//删除一个节点后桶空，应该使 useBucketNum_--
			if (table_[idx].empty())
			{
				useBucketNum_--;
			}
		}
	}
	//搜索元素
	bool find(int key)
	{
		int idx = key % table_.size();//O(1)
		auto it = ::find(table_[idx].begin(), table_[idx].end(), key);//使用全局的 ::find 泛型算法，而不是调用自己的成员方法
		//if (it != table_[idx].end())
		//{
		//	return true;
		//}
		//return false;
		return it != table_[idx].end();//精简
	}
private:
	//扩容操作
	void expand()
	{
		if (primeIdx_ + 1 == PRIME_SIZE)
		{
			throw "HashTable is too large can not expand anymore!";
		}
		primeIdx_++;
		useBucketNum_ = 0;
		vector<list<int>> oldtable;
		table_.swap(oldtable);//swap 只交换了两个容器的成员变量（需两容器使用一致的空间配置器 allocator），效率高，若空间配置器 allocator 不一致，需效率低的逐个数据交换
		table_.resize(primes_[primeIdx_]);
		//重新哈希
		for (auto list : oldtable)//遍历每个桶
		{
			for (auto key : list)//遍历每个桶中的节点
			{
				int idx = key % table_.size();
				if (table_[idx].empty())
				{
					useBucketNum_++;
					//table_[idx].emplace_front(key);
				}
				//else
				//{
				//	table_[idx].emplace_front(key);
				//}
				table_[idx].emplace_front(key);//精简
			}
		}
	}
	vector<list<int>> table_;//哈希表的数据结构
	int useBucketNum_;//已经使用的桶的个数
	double loadFactor_;//哈希表的装载因子
	static const int PRIME_SIZE = 10;//素数表大小
	static int primes_[PRIME_SIZE];//素数表
	int primeIdx_;//当前使用的素数下标
};
int HashTable::primes_[PRIME_SIZE] = { 3, 7, 23, 47, 97, 251, 443, 911, 1471, 42773 };

int main()
{
//链式哈希表算法思想 2026.3.10
	//线性探测哈希表缺陷：
		//发生哈希冲突时，时间复杂度会越来越靠近 O(n)
		//多线程环境中，线性探测所用到的基于数组实现的哈希表，只能给全局的表用互斥锁来保证哈希表的原子操作，保证线程安全
		//在多线程环境中，可以采用分段的锁，即保证了线程安全，右有一定的并发量，提高了效率
	//链式哈希表底层用数组存储链表头指针，通过哈希函数将 key 映射到数组下标，哈希冲突时将元素链入对应下标的链表中，vector<list<int>>
	//链式哈希表的哈希函数同样采用除留余数法
	//以 12 18 21 24 33，哈希函数：val % 7 为例
		// -----   --------
		//0| --|---| 21|  |
		// -----   --------
		// -----
		//1| --|
		// -----
		// -----
		//2| --|
		// -----
		// -----   --------
		//3| --|---| 24|  |
		// -----   --------
		// -----   --------
		//4| --|---| 18|  |
		// -----   --------
		// -----   --------   --------
		//5| --|---| 12|--|---| 33|  |
		// -----   --------   --------
	//链式哈希表增、删、查操作只能无限趋于	O(1)，因为哈希冲突的存在，同时若每个桶的链表比较长，链表搜索的时间复杂度可趋于 O(n)
	//链式哈希表可以通过优化来提升增、删、查操作效率
		//优化一：当链表长度大于8/10，可以把桶里面的这个链表转化成红黑树（增、删、查时间复杂度为 O(logn)）
		//优化二：链式哈希表每个桶都可以创建自己的互斥锁，不同桶中的链表操作可以并发执行

//链式哈希表算法实现
	HashTable htable;
	htable.insert(21);
	htable.insert(32);
	htable.insert(14);
	htable.insert(15);
	htable.insert(22);
	htable.insert(67);
	cout << htable.find(67) << endl;
	htable.erase(67);
	cout << htable.find(67) << endl;

	system("pause");
	return 0;
}
*/