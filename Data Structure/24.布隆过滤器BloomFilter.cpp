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
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
using namespace std;

/*
//布隆过滤器 Bloom Filter 算法实现
//哈希函数
template<class T>
size_t BKDRHash(const T* str)
{
	size_t hash = 0;
	while (size_t ch = (size_t)*str++)
	{
		hash = hash * 131 + ch;
	}
	return hash;
}
template<class T>
size_t RSHash(const T* str)
{
	size_t hash = 0;
	size_t magic = 63689;
	while (size_t ch = (size_t)*str++)
	{
		hash = hash * magic + ch;
		magic *= 378551;
	}
	return hash;
}
template<class T>
size_t APHash(const T* str)
{
	size_t hash = 0;
	size_t ch;
	for (long i = 0; ch = (size_t)*str++; i++)
	{
		if ((i & 1) == 0)
		{
			hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
		}
		else
		{
			hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
		}
	}
	return hash;
}
//Bloom Filter 过滤器
class BloomFilter
{
public:
	BloomFilter(int bitSize = 1471)
		: bitSize_(bitSize)
	{
		bitMap_.resize(bitSize_ / 32 + 1);
	}
public:
	//添加元素 O(1)
	void setBit(const char* str)
	{
		//计算 k 组哈希函数的值
		int idx1 = BKDRHash(str) % bitSize_;
		int idx2 = RSHash(str) % bitSize_;
		int idx3 = APHash(str) % bitSize_;
		//把相应的 idx1 idx2 idx3 这几个位置全部置 1
		int index = 0;
		int offset = 0;
		index = idx1 / 32;
		offset = idx1 % 32;
		bitMap_[index] |= (1 << offset);
		index = idx2 / 32;
		offset = idx2 % 32;
		bitMap_[index] |= (1 << offset);
		index = idx3 / 32;
		offset = idx3 % 32;
		bitMap_[index] |= (1 << offset);
	}
	//查询元素 O(1)
	bool getBit(const char* str)
	{
		//计算 k 组哈希函数的值
		int idx1 = BKDRHash(str) % bitSize_;
		int idx2 = RSHash(str) % bitSize_;
		int idx3 = APHash(str) % bitSize_;
		int index = 0;
		int offset = 0;
		index = idx1 / 32;
		offset = idx1 % 32;
		if (0 == (bitMap_[index] & 1 << offset))//判断是否存在
		{
			return false;
		}
		index = idx2 / 32;
		offset = idx2 % 32;
		if (0 == (bitMap_[index] & 1 << offset))
		{
			return false;
		}
		index = idx3 / 32;
		offset = idx3 % 32;
		if (0 == (bitMap_[index] & 1 << offset))
		{
			return false;
		}
		return true;
	}
private:
	int bitSize_;//位图的长度
	vector<int> bitMap_;//位图数组，哈希桶
};
//需过滤内容封装
class BlackList
{
public:
	void add(string url)
	{
		blockList_.setBit(url.c_str());//.c_str 可以把字符串返回为 const char* 类型
	}
	bool query(string url)
	{
		return blockList_.getBit(url.c_str());
	}
private:
	BloomFilter blockList_;
};

int main()
{
//布隆过滤器 Bloom Filter 算法思想
	//在内存有所限制的情况下（如上面的面试问题），快速判断一个元素是否在一个集合（容器）当中，还可以使用布隆过滤器
	//Bloom Filter 是通过一个位数组 + k 个哈希函数构成的
	//Bloom Filter 增加元素的过程：
		//把元素的值通过 k 个哈希函数进行计算，得到 k 个值，然后把 k 当作位数组的下标
		//在位数组中把相应 k 个值修改成 1
	//Bloom Filter 查询元素的过程：
		//把元素的值通过 k 个哈希函数进行计算，得到 k 个值，然后把 k 当作位数组的下标
		//看相应位数组下标标识的值是否全部是 1，如果有一个为 0，表示元素不存在
		//注意：判断不存在绝对正确，如果都为1，表示元素存在，但判断存在有错误率
	//Bloom Filter 的空间和时间利用率都很高，但是它有一定的错误率，虽然错误率很低
	//Bloom Filter 判断某个元素不在一个集合中，那该元素肯定不在集合里面，Bloom Filter 判断某个元素在一个集合中，那该元素有可能在，有可能不在集合当中
	//Bloom Filter 查找错误率，当然和位数组的大小，以及哈希函数的个数有关系，具体的错误率计算有相应的公式（错误率公式的掌握看个人理解，不做要求）
	//Bloom Filter 默认只支持 add 增加和 query 查询操作，不支持 delete 删除操作，因为存储的状态位有可能也是其它数据的状态位，删除后导致其它元素查找判断出错

//布隆过滤器 Bloom Filter 算法应用：
	//大数据处理查重中应用
	//场景一：提示过滤一些非法的网站，如 https://www.xxxxxx.com/
		//Bloom Filter 把所有可能怀疑有问题的网站的 URL 添加到布隆过滤器当中，查找当前访问的 URL 是否在黑名单中
		//如果网站 URL 不存在，那肯定是白名单上的合法的网站，直接访问
		//如果存在（有误判率），会进行提示当前网站有风险，禁止访问
	//场景二：redis 缓存中的应用，在后台服务中，热点数据不存放到 mysql 中，而是存到 redis 中，提高查询效率
		//
		//       ------        -----------        -------------        -------------
		//-----> |    | -----> |         | -----> |           | -----> |           |
		//       | IO |        | service |        |   redis   |        |    DB     |
		//<----- |    | <----- |         | <----- | (key-val) | <----- |  (MySQL)  |
		//       ------        -----------        -------------        -------------
		//                                         在 redis 中          在 redis 中找不到，会在 DB 中
		//                                         找到直接返回          查找，找到将数据存入 redis 一份返回                                                          

//布隆过滤器 Bloom Filter 算法实现
	BlackList list;
	list.add("http:/www.baidu.com");
	list.add("http:/www.360buy.com");
	list.add("http:/www.tmall.com");
	list.add("http:/www.tencent.com");
	string url = "http:/www.361buy.com";
	cout << list.query(url) << endl;

	system("pause");
	return 0;
}
*/