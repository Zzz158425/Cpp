#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;

/*
//BF 算法实现
int BF(string s, string t)
{
	int i = 0;
	int j = 0;
	while (i < s.size() && j < t.size())//O(n)
	{
		if (s[i] == t[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;//复位 i，指向之前开始匹配字符的下一个字符 O(m)
			j = 0;
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
//BF 算法思想 2026.4.14
	//A B C D C A B D E F G 主串
	//A B D 子串/模式串
	//子串在主串里面的搜索过程/操作也称为模式匹配
	//i                              i                        i                                                 i
	//A B C D C A B D E F G ---> A B C D C A B D E F G ---> A B C D C A B D E F G ---> ... ---> A B C D C A B D E F G  
	//A B D                      A B D                        A B D                                       A B D
	//j                              j                        j                                                 j
	//BF 算法中对于子串的形状没有做任何的分析，导致匹配过程中做了很多无效的匹配操作（明知结果不可能匹配成功的操作）
	//导致算法效率降低，让匹配过程中，主串的 i 不用回退，提高算法的效率
	
//BF 算法实现
	//BF 算法时间复杂度：O(n * m)，n 表示主串的长度，m 表示子串的长度
	//BF 算法空间复杂度：O(1)
	string S = "ABCDCABDEFG";
	string t = "ABX";
	int pos = BF(S, t);
	cout << pos << endl;

	system("pause");
	return 0;
}
*/