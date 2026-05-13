#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
using namespace std;

/*
//数组代码输出 2026.1.21
//数组实现
class Array
{
public:
	Array(int size = 10) : mCur(0), mCap(size)
	{
		mpArr = new int[mCap]();
	}
	~Array()
	{
		delete[]mpArr;
		mpArr = nullptr;//C++ 中所有空指针赋值（唯一规范写法），野指针：指针的值不为空，但是指针所存的那个地址内存已经释放
	}
public:
	//末尾增加元素
	void push_back(int val)
	{
		if (mCur == mCap)//判断此时数组容量是否超出
		{
			expand(2 * mCap);
		}
		mpArr[mCur] = val;
		mCur++;
		//或者 mpArr[mCur++] = val;
	}
	//末尾删除元素
	void pop_back()
	{
		if (mCur == 0)
		{
			return;
		}
		mCur--;
	}
	//按位置增加元素
	void insert(int pos, int val)
	{
		if (pos < 0 || pos > mCur)
		{
			cout << "throw pos invalid" << endl;
			return;
		}
		if (mCur == mCap)
		{
			expand(2 * mCap);
		}
		//移动元素
		for (int i = mCur - 1; i >= pos; i--)
		{
			mpArr[i + 1] = mpArr[i];
		}
		mpArr[pos] = val;
		mCur++;
	}
	//按位置删除
	void erase(int pos)
	{
		if (pos < 0 || pos >= mCur)
		{
			cout << "throw pos invalid" << endl;
			return;
		}
		//移动元素
		for (int i = pos + 1; i <= mCur; i++)
		{
			mpArr[i - 1] = mpArr[i];
		}
		mCur--;
	}
	//元素查询
	int find(int val)
	{
		for (int i = 0; i < mCur; i++)
		{
			if ( mpArr[i] == val)
			{
				return i;
			}
		}
		return -1;
	}
	//打印数据
	void show()const
	{
		for (int i = 0; i < mCur; i++)
		{
			cout << mpArr[i] << " ";
		}cout << endl;
	}
private:
	//内部数组扩容接口
	void expand(int size)//数组扩容
	{
		int* p = new int[size];
		memcpy(p, mpArr, sizeof(int) * mCap);//memcpy() 内存拷贝函数，将指定字节数的内存块从“源地址”逐字节复制到“目标地址”（字符、整型、结构体等都能拷贝）
		delete[]mpArr;
		mpArr = p;
		mCap = size;
	}
private:
	int* mpArr;//指向可扩容的数组内存
	int mCap;//数组的容量
	int mCur;//数组有效元素个数
};

//元素逆序问题 2026.1.22
//逆序字符串
void Reverse(char arr[], int size)
{
	//双指针思想
	char* p = arr;
	char* q = arr + size - 1;
	while (p < q)
	{
		char ch = *p;
		*p = *q;
		*q = ch;
		p++;
		q--;
	}
}
//奇偶数调整问题
void AdjustArray(int arr[], int size)
{
	int* p = arr;
	int* q = arr + size - 1;
	while (p < q)
	{
		//p -> 偶数
		if ((*p & 0x1) == 0)//按位来判断是否为偶数：任何数和 0x1 做按位与运算，结果只取决于这个数的二进制最低位，偶数为 0，奇数为 1
		{
			p++;
			continue;//跳过本次循环剩下的所有代码，直接进入下一次循环
		}
		//q -> 奇数
		if ((*q & 0x1) == 1)//按位来判断是否为奇数
		{
			q--;
			continue;
		}
		//p -> 奇数，q -> 偶数
		int temp = *p;
		*p = *q;
		*q = temp;
		p++;
		q--;
	}
}
void AdjustArray1(int arr[], int size)//优化 AdjustArray，q 出现连续多个奇数时，不必再重复让 p 进行判断
{
	int* p = arr;
	int* q = arr + size - 1;
	while (p < q)
	{
		//p -> 偶数
		while (p < q)
		{
			if ((*p & 0x1) == 1)
			{
				break;
			}
			p++;
		}
		//q -> 奇数
		while (p < q)
		{
			if ((*q & 0x1) == 0)
			{
				break;
			}
			q--;
		}
		//p -> 奇数，q -> 偶数
		if (p < q)//防止全为奇/偶数时，还会进行交换
		{
			int temp = *p;
			*p = *q;
			*q = temp;
			p++;
			q--;
		}	
	}
}

//移除元素问题
int removeElement(int* nums, int numsSize, int val)
{
	int* p = nums;
	int* q = nums + numsSize - 1;
	while (p <= q)
	{
		if (*q == val)
		{
			q--;
			continue;
		}
		if (*p == val)
		{
			*p = *q;
			q--;
		}
		p++;
	}
	return p - nums;//同类型、指向同一数组的指针可以相减，结果是两个指针之间的元素个数
}

int main()
{
//数组讲解 2026.1.19
	//特点：内存是连续的
		//优点
			//下标访问（随机访问）时间复杂度是 O(1)
			//末尾位置增加删除元素时间复杂度是 O(1)
			//访问元素前后相邻位置的元素非常方便
		//缺点
			//非末尾位置增加删除元素需要进行大量的数据移动 O(n)
			//搜索的时间复杂度
				//无序数组 - 线性搜索 O(n)
				//有序数组 - 二分搜索 O(logn)
			//数组扩容消耗比较大
	int arr[10] = { 12,23,45,31,56,82,62 };//arr[0] ~ arr[9]，避免数组越界访问 "arr[10]"
	arr[0];//数组下标访问，不是查找搜索
	//查找搜索，线性查找，时间复杂度是 O(n)
	for (int i = 0; i < 10; i++)
	{
		int val = 12;
		if (arr[i] == val)
		{
			cout << "arr[" << i << "]" << " = " << val << endl;
		}
	}
	//线性表：由零个或多个具有相同数据类型的元素组成的有序、有限的序列，元素之间存在明确的前驱后继关系，数组就是最典型的线性表
	
//数组代码输出 2026.1.21
	//C++ 进程在内存上面的布局可以大致分为三段：数据段、堆、栈
		//数据段由系统自动分配释放，生命周期为整个程序的生命周期：全局变量
		//堆：程序员自己通过 new delete 开辟
		//栈：由系统自动分配释放
	//数组实现
	Array arr1;
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		arr1.push_back(rand() % 100);
	}
	arr1.show();
	arr1.pop_back();
	arr1.show();
	arr1.insert(0, 100);
	arr1.show();
	arr1.insert(10, 200);
	arr1.show();
	int pos = arr1.find(100);
	if (pos != -1)
	{
		arr1.erase(pos);
	}
	arr1.show();

//元素逆序问题 2026.1.22
	//逆序字符串
	char arr2[] = "hello world";
	cout << arr2 << endl;
	Reverse(arr2, strlen(arr2));//strlen 字符串长度计算函数，计算以 \0（空字符/字符串结束符）为终止标志的字符串的有效字符个数
	cout << arr2 << endl;
	//奇偶数调整问题
		//整形数组，把偶数调整到数组左边，把奇数调整到数组右边
	int arr3[10] = { 0 };
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		arr3[i] = rand() % 100;
	}
	for (int v : arr3)
	{
		cout << v << " ";
	}
	cout << endl;
	AdjustArray(arr3, 10);
	for (int v : arr3)
	{
		cout << v << " ";
	}
	cout << endl;
	AdjustArray1(arr3, 10);
	for (int v : arr3)
	{
		cout << v << " ";
	}
	cout << endl;

//移除元素问题（Leetcode）
	//给你一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，然后返回 nums 中与 val 不同的元素的数量
	//不要使用额外的数组空间，必须使用 O(1) 额外空间并原地修改输入数组
	//元素的顺序可以改变，不需要考虑数组中超出新长度后面的元素
	int nums[5] = { 1,3,3,4,5 };
	int ret = removeElement(nums, 5, 3);
	for (int v : nums)
	{
		cout << v << " ";
	}
	cout << endl;
	cout << ret << endl;
	
	system("pause");
	return 0;
}
*/