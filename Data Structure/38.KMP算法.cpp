#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
#include<memory>
using namespace std;

/*
//KMP 算法实现
//KMP 算法求解子串 next 数组
int* getNext(string str)
{
	int* next = new int[str.size()];
	int j = 0;//j 用来遍历子串
	int k = -1;//k 表示公共前后缀的长度
	next[j] = k;
	while (j < str.size() - 1)//O(m)
	{
		if ((-1 == k) || str[k] == str[j])//Pk == Pj
		{
			j++;
			k++;
			if (str[k] == str[j])
			{
				next[j] = next[k];
			}
			else
			{
				next[j] = k;
			}
		}
		else//Pk != Pj
		{
			k = next[k];//做 k 值回溯，继续找最长的公共前后缀
		}
	}
	return next;
}
int KMP(string s, string t)
{
	int i = 0;
	int j = 0;
	int* next = getNext(t);//计算一个子串对应的 next 数组
	unique_ptr<int> ptr(next);
	int size1 = s.size();
	int size2 = t.size();
	//while (i < s.size() && j < t.size()) t.size() 返回无符号数，与有符号数 j 比较会出错
	while (i < size1 && j < size2)//O(n)
	{
		//优化
		if ((-1 == j) || s[i] == t[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	//找到
	if (j == t.size())
	{
		return i - j;
	}
	else
	{
		return -1;
	}

}

int main()
{
//KMP 算法思想
	//字符失配后，主串的 i 不做回退操作，只回退子串的 j
	//由于在任意一个字符匹配时都有可能失配，所以 KMP 算法的关键就是给子串计算出一个 next 数组，里面存储的是当前字符适配时，j 要回退到的位置
	//同理，也就是存储的当前字符前面的子串的公共前后缀的长度
	//关键：求出子串每一个字符前面串的公共前后缀的长度，放在 next 数组中

//KMP 算法的 next 数组求解思想
	//P0 ...... Pk-1 k ...... Pj-k ...... Pj-1 j j + 1
	//next 数组等于子串的长度，j：子串每一个字符的小下标，k：当前位置字符失配时回退的位置等于第 j 个字符前面字符串的最长的公共前后缀的长度
	//当 j = 0 时，k = -1，next[0] = -1
	//当 j = 1 时，k = 0，next[1] = 0
	//......
	//当子串满足 P0 ... Pk-1 = Pj-k ... Pj-1，前后缀对应的字符相等，那么 next[j] = k
	//当 Pk 等于 Pj 时，next[j + 1] = k + 1
	//当 Pk 不等于 Pj 时，k = next[k]

//KMP 算法实现
	//KMP 算法优化：
		//优化前：
			//主串：a b c a b d e f
			//子串：a b c a b c，当子串 c 与主串 d 失配时，应回退两次，回退到 0，因为子串 abcabc 只回退一次显然后续也失配
			//     -1 0 0 0 1 2
		//优化后：
			//主串：a b c a b d e f
			//子串：a b c a b c
			//    -1 0 0 -1 0 0
	//时间复杂度：O(n + m)，n 表示主串的长度，m 表示子串的长度
	//空间复杂度：O(m)
	string S = "ABCDCABDEFG";
	string t = "ABD";
	int pos = KMP(S, t);
	cout << pos << endl;

	system("pause");
	return 0;
}
*/