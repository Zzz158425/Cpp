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
//哈希表应用
	//哈希表查重或者统计重复的次数，查询的效率高但是占用内存空间较大
	//大数据处理查重中应用
	vector<int> vec;
	srand(time(NULL));
	for (int i = 0; i < 10000; i++)
	{
		vec.push_back(rand() % 10000);
	}
	//找第一个出现重复的数字
	unordered_set<int> s1;
	for (int i = 0; i < 10000; i++)
	{
		if (s1.find(vec[i]) == s1.end())
		{
			s1.insert(vec[i]);
		}
		else
		{
			cout << "第一个重复的数字为：" << vec[i] << endl;
			break;
		}
	}
	//找所有重复出现的数字
	unordered_set<int> s2;
	for (auto key : vec)
	{
		auto it = s2.find(key);
		if (it == s2.end())
		{
			s2.insert(key);
		}
		else
		{
			cout << "key:" << key << endl;
		}
	}
	//统计重复数字以及出现的次数
	unordered_map<int, int> m1;
	for (auto key : vec)
	{
		auto it = m1.find(key);
		if (it == m1.end())
		{
			m1.insert({ key, 1 });
		}
		else
		{
			it->second += 1;
		}
		//m1[key]++;精简
	}
	for (auto pair : m1)
	{
		if (pair.second > 1)
		{
			cout << "重复出现的数字：" << pair.first << " " << "重复次数：" << pair.second << endl;
		}
	}
	//过滤重复数据
	unordered_set<int> s3;
	for (auto key : vec)
	{
		s3.emplace(key);
	}
	for (auto it : s3)
	{
		cout << it << " ";
	}
	cout << endl;
	//找出第一个没有重复出现过的字符
	string src = "jjhfgiyurtytrs";
	unordered_map<char, int> m2;;
	for (char ch : src)
	{
		m2[ch]++;
	}
	for (auto ch : src)
	{
		if (m2[ch] == 1)
		{
			cout << "第一个没有重复出现过的字符：" << ch << endl;
			break;
			//return 0;
		}
	}
	cout << "所有字符都有重复出现" << endl;
	//return 0;
	//两文件 a 与 b，里面放了很多 ip地址（url、email），找出两个文件重复的 ip 并输出
		//不限制内存，采用哈希表
	//两文件 a 与 b，各自存放约 1 亿条 ip 地址（url、email），限制内存使用 100M，找出两个文件重复的 ip 并输出
		//分治思想：文件 a 与 b 中 ip 依次读取 % 11 = 各自划分到小文件中（桶的下标），之后 a1 ... a11 各自对应与 b1 ... b11 查重
			//文件 a  文件 b
			//a1      b1    10M * 4 = 40M * 2 = 80M < 100M                                 
			//a2      b2      
			//a3      b3
			//a4      b4
			//a5      b5
			//a6      b6
			//a7      b7
			//a8      b8
			//a9      b9
			//a10     b10
			//a11     b11

	system("pause");
	return 0;
}
*/