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
//线性探测哈希表算法实现 2026.3.9
//哈希桶状态
enum State
{
	STATE_UNUSE,//从未使用过的桶
	STATE_USING,//正在使用的桶
	STATE_DEL,//元素被删除了的桶
};
//桶的类型
struct Bucket
{
	Bucket(int key = 0, State state = STATE_UNUSE)
		: key_(key)
		, state_(state) { }
	int key_;//存储的数据
	State state_;//桶当前的状态
};
//线性探测哈希表类型
class HashTable
{
public:
	HashTable(int size = primes_[0], double loadFactor = 0.75)
		: useBucketNum_(0)
		, loadFactor_(loadFactor)
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
		tableSize_ = primes_[primeIdx_];
		table_ = new Bucket[tableSize_];
	}
	~HashTable()
	{
		delete[]table_;
		table_ = nullptr;
	}
public:
	//插入元素
	bool insert(int key)
	{
		//考虑扩容
		double factor = useBucketNum_ * 1.0 / tableSize_;//useBucketNum_ * 1.0 使结果能得到一个浮点数
		cout << "factor:" << factor << endl;
		if (factor > loadFactor_)
		{
			expand();//哈希表扩容
		}
		//方法一
		//int idx = key % tableSize_;
		//if (table_[idx].state_ != STATE_USING)
		//{
		//	table_[idx].state_ = STATE_USING;
		//	table_[idx] = key;
		//	useBucketNum_++;
		//	return true;
		//}
		//for (int i = (idx + 1) % tableSize_; i != idx; i = (i + 1) % tableSize_)
		//{
		//	if (table_[i].state_ != STATE_USING)
		//	{
		//		table_[i].state_ = STATE_USING;
		//		table_[i] = key;
		//		useBucketNum_++;
		//		return true;
		//	}
		//}
		//优化方法一
		int idx = key % tableSize_;
		int i = idx;
		do
		{
			if (table_[i].state_ != STATE_USING)
			{
				table_[i].state_ = STATE_USING;
				table_[i].key_ = key;
				useBucketNum_++;
				return true;// O(1)
			}
			i = (i + 1) % tableSize_;
		} while (i != idx);// O(n)
		return false;
	}
	//删除所有元素
	bool erase(int key)
	{
		int idx = key % tableSize_;
		int i = idx;
		do
		{
			if ((table_[i].key_ == key) && (table_[i].state_ == STATE_USING))
			{
				table_[i].state_ = STATE_DEL;
				useBucketNum_--;
			}
			i = (i + 1) % tableSize_;
		} while ((table_[i].state_ != STATE_UNUSE) && (i != idx));//遇到 STATE_UNUSE 的桶表明后续没有要删除的值
		return true;
	}
	//查询元素
	bool find(int key)
	{
		int idx = key % tableSize_;
		int i = idx;
		do
		{
			if ((table_[i].key_ == key) && (table_[i].state_ == STATE_USING))
			{
				return true;
			}
			i = (i + 1) % tableSize_;
		} while ((table_[i].state_ != STATE_UNUSE) && (i != idx));
		return false;
	}
private:
	//扩容
	void expand()
	{
		primeIdx_++;
		if (primeIdx_ == PRIME_SIZE)
		{
			throw "HashTable is too large can not expand anymore!";
		}
		Bucket* newTable = new Bucket[primes_[primeIdx_]];
		for (int i = 0; i < tableSize_; ++i)
		{
			if (table_[i].state_ == STATE_USING)//旧表有效数据才拷贝到扩容后的新表
			{
				int idx = table_[i].key_ % primes_[primeIdx_];//将旧表里面的有效数据重新哈希
				int k = idx;
				do
				{
					if (newTable[k].state_ != STATE_USING)
					{
						newTable[k].state_ = STATE_USING;
						newTable[k].key_ = table_[i].key_;
						break;
					}
					k = (k + 1) % primes_[primeIdx_];
				} while (k != idx);
			}	
		}
		delete[]table_;
		table_ = newTable;
		tableSize_ = primes_[primeIdx_];
	}
	Bucket* table_;//指向动态开辟的哈希表
	int tableSize_;//哈希表当前的长度
	int useBucketNum_;//已经使用的桶的个数
	double loadFactor_;//哈希表的装载因子
	static const int PRIME_SIZE = 10;//素数表大小
	static int primes_[PRIME_SIZE];//素数表
	int primeIdx_;//当前使用的素数下标
};
int HashTable::primes_[PRIME_SIZE] = { 3, 7, 23, 47, 97, 251, 443, 911, 1471, 42773 };

int main()
{
//哈希表 2026.2.25
	//哈希表:哈希表（也叫散列表）是一种通过关键字 key 直接映射到存储位置的数据结构，优势：让插入、查找、删除的平均时间复杂度达到 O(1)（理想情况），劣势：占用内存空间比较大
	//哈希/散列函数：设计特点应计算简单（复杂会降低查找的时间）、散列地址分布均匀（减少哈希冲突）
		//直接定址法：取关键字或关键字得某个线性函数值为散列地址，例如：f(key) = a * key + b（a、b为常数）
		//数字分析法：使用 key 的一部分来计算散列码（包括为了减少哈希冲突而进行位移操作、数字叠加操作等）
		//平方取中法：取关键字 key 的平方后的中间部分数字作为散列地址
		//折叠法 & 随机数法
		//除留余数法：f(key) = key mod p，不仅可以对关键字直接取模，也可以折叠、平方取中法等运算之后取模。p的取值很重要，一般取素数，否则冲突的概率会比较大
		//md5、sha加密hash算法等
	//散列冲突处理：
		//线性探测（开放定址法）：f(key) = (key + di) mod m (di = 1, 2, 3, 4, ..., m - 1)
		//二次探测：f(key) = (key + di) mod m(di = 1^2, -1^2, 2^2, -2^2，...，q^2， -q^2) q <= m / 2
			//二次探测是对线性探测法的改进，在散列冲突位置的前后都可以查找空位置，di取平方是为了让数据更加散列的存储，不会聚集
		//链地址法：用链表存储组织产生哈希冲突的 key
	//哈希表的装载因子 loadfactor：已占用的桶的个数 / 桶的总个数，当 loadfactor > 3 / 4 时，产生哈希冲突的概率大幅提升，哈希表此时需扩容
	//哈希表的扩容相当于数组的扩容，原来哈希表中的元素，需要再新的哈希表中重新哈希 O(n)，均摊时间复杂度可以认为 O(1)，因为不是每次操作都会触发扩容

//线性探测哈希表算法思想
	//线性探测是开放寻址法的一种，核心思想是：冲突发生时，从冲突位置开始，按逐个往后的线性顺序查找下一个空位置（找不到就绕回表头）。
	//除留余数法，哈希表（桶）的长度：素数，以减少哈希冲突，扩容采取下一个素数，素数表：{3, 7, 23, 47, 97, 251, 443, 911, 1471, 42773 }
	//线性探测哈希表三大操作：增加、查询与删除
		//增加：通过哈希函数计算数据存放的位置
			//该位置空闲，直接存储元素，完成
			//该位置被占用，从当前位置向后找空闲的位置，存放该元素
		//查询：通过哈希函数计算数据存放的位置，从该位置取值，判断该位置状态
			//该值等于要查询的元素值，找到了
			//该值不等于要查询的元素值（哈希冲突），继续遍历往后找该元素
				//这个位置一直是空，没放过元素，不需要继续往后搜索，查询的数字不存在
				//这个位置是空，以前放过元素，后来删除了，需要继续往后搜索
		//删除：通过哈希函数计算数据存放的位置，从该位置取值，判断该位置状态
			//该值等于要删除的值，直接修改当前位置的状态就可以
			//该值不等于要删除的值（哈希冲突），从当前位置向后遍历，找到该元素，修改状态，如果遇到这个位置一直是空，直接结束
			
//线性探测哈希表算法实现 2026.3.9
	//找素数
	//int data = 3;
	//for (int i = data; i < 10000; i++)
	//{
	//	int j = 2;
	//	for (; j < i; j++)
	//	{
	//		if (i % j == 0)
	//		{
	//			break;
	//		}
	//	}
	//	if (i == j)
	//	{
	//		cout << i << " ";
	//	}
	//}
	HashTable htable;
	htable.insert(21);
	htable.insert(32);
	htable.insert(14);
	htable.insert(15);
	htable.insert(22);
	cout << htable.find(21) << endl;
	htable.erase(21);
	cout << htable.find(21) << endl;

	system("pause");
	return 0;
}
*/