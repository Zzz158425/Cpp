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
int main()
{
//位图算法思想 2026.3.11
	//位图法，就是用一个位（0或者1）来存储数据的状态，比较适合状态简单，数据量比较大，要求内存使用率低的问题场景
	//位图法首先需要知道待处理数据中的最大值，然后按照 size = (maxNumber / 32) + 1 的大小来开辟一个 char 类型的数组，当需要在位图中查找某个元素是否存在的时候，首先需要计算该数字对应的数组中的比特位，然后读取值，0 表示不存在，1 表示已存在
	//位图法有一个很大的缺点，就是数据没有多少，但是最大值却很大，比如有 10 个整数，最大值是 10 亿，那么就得按 10 亿这个数字计算开辟位图数组的大小，太浪费内存空间
	//以 7 8 12 15 16 19 开辟 char 类型数组为例，8 表示一个号位所占 bit
		//bitmap 00000000   00000000   00000000
		//号位   0          1          2
		//index = 7 / 8 = 0 offset = 7 % 8 = 7，7 这个数字对应的为在 0 号位的第 7 位上
		//index = 8 / 8 = 1 offset = 8 % 8 = 0，8 这个数字对应的为在 1 号位的第 0 位上
		//index = 15 / 8 = 1 offset = 15 % 8 = 7，15 这个数字对应的为在 1 号位的第 7 位上 
		//index = 16 / 8 = 0 offset = 16 % 8 = 0，16 这个数字对应的为在 0 号位的第 0 位上
		//index = 19 / 8 = 2 offset = 19 % 8 = 1，19 这个数字对应的为在 2 号位的第 1 位上
		//bitmap 10000010   10000010   01000000
		//号位   0          1          2
		
//位图算法实现
	//大数据处理查重中应用
	vector<int> vec{ 12,78,90,78,123,8,9 };
	int max = vec[0];
	for (int i = 1; i < vec.size(); i++)
	{
		if (vec[i] > max)
		{
			max = vec[i];
		}
	}
	cout << "max:" << max << endl;
	int* bitmap = new int[max / 32 + 1]();//不能这样定义 int bitmap[max / 32 + 1]，静态数组（栈上数组）的大小必须是编译期就能确定的常量表达式
	unique_ptr<int> ptr(bitmap);//智能指针
	//找第一个重复出现的数字
	for (auto key : vec)
	{
		int index = key / 32;
		int offset = key % 32;
		//取 key 对应的位的值
		if (0 == (bitmap[index] & (1 << offset)))//1 << offset 是将 000...001 向左移动 offset 位为 000...010...000
		{
			bitmap[index] |= (1 << offset);//表示 key 没有出现
		}
		else
		{
			cout << key << " 是第一个重复出现的数字" << endl;
			break;
		}
	}

	system("pause");
	return 0;
}
*/