#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include<ctime>
#include<numeric>

/*
//常用排序算法 sort 2025.11.21
void myprint(int val)
{
	cout << val << " ";
}
void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);
	sort(v.begin(), v.end());//默认从小到大排序
	for_each(v.begin(), v.end(), myprint);
	cout << endl;
	sort(v.begin(), v.end(), greater<int>());//利用内建匿名函数 greater<int>() 改变排序规则
	for_each(v.begin(), v.end(), myprint);
	cout << endl;
}

//常用排序算法 random_shuffle
class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
void test02()
{
	srand((unsigned int)time(NULL));
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
	//shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}

//常用排序算法 merge
void test03()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}
	vector<int> vtarget;
	vtarget.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vtarget.begin());
	for_each(vtarget.begin(), vtarget.end(), myPrint());
	cout << endl;
}

//常用排序算法 reverse
void test04()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);
	cout << "反转前： " << endl;
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
	cout << "反转后： " << endl;
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}

//常用拷贝和替换算法 copy
void test05()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());
	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;
}

//常用拷贝和替换算法 replace
void test06()
{
	vector<int> v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);
	cout << "替换前：" << endl;
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
	cout << "替换后：" << endl;
	replace(v.begin(), v.end(), 20, 2000);
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}

//常用拷贝和替换算法 replace_if
class ReplaceGreater30
{
public:
	bool operator()(int val)
	{
		return val >= 30;
	}
};
void test07()
{
	vector<int> v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);
	cout << "替换前：" << endl;
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
	cout << "替换后：" << endl;
	replace_if(v.begin(), v.end(), ReplaceGreater30(), 3000);
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}

//常用拷贝和替换算法 swap
void test08()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++) 
	{
		v1.push_back(i);
		v2.push_back(i + 100);
	}
	cout << "交换前： " << endl;
	for_each(v1.begin(), v1.end(), myPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;
	cout << "交换后： " << endl;
	swap(v1, v2);
	for_each(v1.begin(), v1.end(), myPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;
}

//常用算术生成算法 accumulate
void test09()
{
	vector<int> v;
	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}
	int total = accumulate(v.begin(), v.end(), 0);
	cout << "total：" << total << endl;
}

//常用算术生成算法 fill
void test10()
{
	vector<int> v;
	v.resize(10);//重新制定大小后，超出部分会按 0 填充
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
	fill(v.begin(), v.end(), 100);
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}

//常用集合算法 set_intersection 2025.11.21
void test11()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector<int> vTarget;
	vTarget.resize(min(v1.size(), v2.size()));//取两个里面较小的值给目标容器开辟空间，函数 min()
	vector<int>::iterator itEnd =
		set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint());//开辟的 vTarget 迭代器可能会更大，会显示不需要的部分，所以用 itEnd
	cout << endl;
}

//常用集合算法 set_union
void test12()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector<int> vTarget;
	vTarget.resize(v1.size()+ v2.size());//考虑特殊情况，v1，v2没有交集
	vector<int>::iterator itEnd =
		set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint());//开辟的 vTarget 迭代器可能会更大，会显示不需要的部分，所以用 itEnd
	cout << endl;
}

//常用集合算法 set_difference
void test13()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector<int> vTarget;
	vTarget.resize(max(v1.size(), v2.size()));//取两个里面较大的值给目标容器开辟空间，函数 max()
	cout << "v1与v2的差集为： " << endl;
	vector<int>::iterator itEnd =
		set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint());//开辟的 vTarget 迭代器可能会更大，会显示不需要的部分，所以用 itEnd
	cout << endl;
	cout << "v2与v1的差集为： " << endl;
	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint());//开辟的 vTarget 迭代器可能会更大，会显示不需要的部分，所以用 itEnd
	cout << endl;
}

int main()
{
//常用排序算法 sort 2025.11.21
	//算法简介：
		//sort             //对容器内元素进行排序
		//random_shuffle   //洗牌：指定范围内的元素随机调整次序
		//merge            //容器元素合并，并存储到另一容器中
		//reverse          //反转指定范围的元素
	//功能描述：对容器内元素进行排序
	//函数原型：
		//sort(iterator beg, iterator end, _Pred);
		//按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置，beg 开始迭代器，end 结束迭代器，_Pred 谓词
	test01();

//常用排序算法 random_shuffle
	//功能描述：洗牌   指定范围内的元素随机调整次序
	//函数原型：
		//random_shuffle(iterator beg, iterator end);
		//指定范围内的元素随机调整次序，beg 开始迭代器，end 结束迭代器
	//！！！注意！！！，random_shuffle 已在 C++ 17 以上版本中被移除
	test02();

//常用排序算法 merge
	//功能描述：两个容器元素合并，并存储到另一容器中
	//函数原型：
		//merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
		//容器元素合并，并存储到另一容器中，beg1 容器 1 开始迭代器，end1 容器 1 结束迭代器，beg2 容器 2 开始迭代器，end2 容器 2 结束迭代器，dest 目标容器开始迭代器
	//注意: 两个容器必须是有序的
	test03();

//常用排序算法 reverse
	//功能描述：将容器内元素进行反转
	//函数原型：
		//reverse(iterator beg, iterator end);
		//反转指定范围的元素，beg 开始迭代器，end 结束迭代器
	test04();

//常用拷贝和替换算法 copy
	//算法简介：
		//copy                //容器内指定范围的元素拷贝到另一容器中
		//replace             //将容器内指定范围的旧元素修改为新元素
		//replace_if          //容器内指定范围满足条件的元素替换为新元素
		//swap                //互换两个容器的元素
	//功能描述：容器内指定范围的元素拷贝到另一容器中
	//函数原型：
		//copy(iterator beg, iterator end, iterator dest);
		//按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置，beg 开始迭代器，end 结束迭代器，dest 目标起始迭代器
	test05();

//常用拷贝和替换算法 replace
	//功能描述：将容器内指定范围的旧元素修改为新元素，有重复元素均替换
	//函数原型：
		//replace(iterator beg, iterator end, oldvalue, newvalue);
		//将区间内旧元素替换成新元素，beg 开始迭代器，end 结束迭代器，oldvalue 旧元素，newvalue 新元素
	test06();

//常用拷贝和替换算法 replace_if
	//功能描述:将区间内满足条件的元素，替换成指定元素
	//函数原型：
		//replace_if(iterator beg, iterator end, _pred, newvalue);
		//按条件替换元素，满足条件的替换成指定元素，beg 开始迭代器，end 结束迭代器，_pred 谓词，newvalue 替换的新元素
	test07();

//常用拷贝和替换算法 swap
	//功能描述：互换两个容器的元素
		//函数原型：
		//swap(container c1, container c2);
		//互换两个容器的元素，c1 容器 1，c2 容器 2
	//总结：swap 交换容器时，注意交换的容器要同种类型
	test08();

//常用算术生成算法 accumulate
	//注意：算术生成算法属于小型算法，使用时包含的头文件为 #include <numeric>
	//算法简介：
		//accumulate         //计算容器元素累计总和
		//fill               //向容器中添加元素
	//功能描述：计算区间内容器元素累计总和
	//函数原型：
		//accumulate(iterator beg, iterator end, value);
		//计算容器元素累计总和，beg 开始迭代器，end 结束迭代器，value 起始累加值，返回 int
	test09();

//常用算术生成算法 fill
	//功能描述：向容器中填充指定的元素
	//函数原型：
		//fill(iterator beg, iterator end, value);
		//向容器中填充元素，beg 开始迭代器，end 结束迭代器，value 填充的值
	test10();

//常用集合算法 set_intersection 2025.11.21
	//算法简介：
		//set_intersection            //求两个容器的交集
		//set_union                   //求两个容器的并集
		//set_difference              //求两个容器的差集
	//功能描述：求两个容器的交集
	//函数原型：
		//set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
		//求两个集合的交集，beg1 容器 1 开始迭代器，end1 容器 1 结束迭代器，beg2 容器 2 开始迭代器，end2 容器 2 结束迭代器，dest 目标容器开始迭代器
	//注意：两个集合必须是有序序列
	//总结：
		//求交集的两个集合必须的有序序列
		//目标容器开辟空间需要从两个容器中取小值
		//set_intersection 返回值既是交集中最后一个元素的位置
	test11();

//常用集合算法 set_union
	//功能描述：求两个集合的并集
	//函数原型：
		//set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest); 
		//求两个集合的并集，beg1 容器 1 开始迭代器，end1 容器 1 结束迭代器，beg2 容器 2 开始迭代器，end2 容器 2 结束迭代器，dest 目标容器开始迭代器
	//注意:两个集合必须是有序序列
	//总结：
		//求并集的两个集合必须的有序序列
		//目标容器开辟空间需要两个容器相加
		//set_union 返回值既是并集中最后一个元素的位置
	test12();

//常用集合算法 set_difference
	//功能描述：求两个集合的差集：不是交集的部分
	//函数原型：
		//set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
		//求两个集合的差集，beg1 容器 1 开始迭代器，end1 容器 1 结束迭代器，beg2 容器 2 开始迭代器，end2 容器 2 结束迭代器，dest 目标容器开始迭代器
	//注意:两个集合必须是有序序列
	//总结：
		//求差集的两个集合必须的有序序列
		//目标容器开辟空间需要从两个容器取较大值
		//set_difference 返回值既是差集中最后一个元素的位置
	test13();

	system("pause");
	return 0;
}
*/