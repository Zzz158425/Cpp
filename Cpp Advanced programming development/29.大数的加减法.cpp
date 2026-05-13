#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

/*
//大数类
class BigInt
{
public:
	BigInt(string str) : strDigit(str) {}
private:
	string strDigit;
	friend ostream& operator<<(ostream& out, const BigInt& src);
	friend BigInt operator+(const BigInt& lhs, const BigInt& rhs);
	friend BigInt operator-(const BigInt& lhs, const BigInt& rhs);
};
//打印函数
std::ostream& operator<<(std::ostream& out, const BigInt& src)
{
	out << src.strDigit;
	return out;
}
//大数加法
BigInt operator+(const BigInt& lhs, const BigInt& rhs)
{
	string result;//存放结果
	bool flag = false;//是否进位
	int size1 = lhs.strDigit.length() - 1;
	int size2 = rhs.strDigit.length() - 1;
	int i = size1;
	int j = size2;
	for (; (i >= 0) && (j >= 0); i--, j--)
	{
		//将两个字符串形式存储的数字的对应位，从字符转换为整数并求和
		//'5' - '0' = 53 - 48 = 5 字符 '5' 变成了整数 5
		//'9' - '0' = 57 - 48 = 9 字符 '9' 变成了整数 9
		int ret = lhs.strDigit[i] - '0' + rhs.strDigit[j] - '0';
		if (flag)
		{
			ret += 1;
			flag = false;
		}
		if (ret >= 10)
		{
			ret %= 10;
			flag = true;
		}
		result.push_back(ret + '0');
	}
	//i > j
	if (i >= 0)
	{
		while (i >= 0)
		{
			int ret = lhs.strDigit[i] - '0';
			if (flag)
			{
				ret += 1;
				flag = false;
			}
			if (ret >= 10)
			{
				ret %= 10;
				flag = true;
			}
			result.push_back(ret + '0');
			i--;
		}
	}
	//i < j
	else if (j >= 0)
	{
		while (j >= 0)
		{
			int ret = rhs.strDigit[j] - '0';
			if (flag)
			{
				ret += 1;
				flag = false;
			}
			if (ret >= 10)
			{
				ret %= 10;
				flag = true;
			}
			result.push_back(ret + '0');
			j--;
		}
	}
	if (flag)
	{
		result.push_back('1');
	}
	reverse(result.begin(), result.end());
	return result;//return BigInt(result);
}
//大数减法
BigInt operator-(const BigInt& lhs, const BigInt& rhs)
{
	string result;//存放结果
	bool flag = false;//是否借位
	bool minor = false;//是否需要负号
	string maxStr = lhs.strDigit;
	string minStr = rhs.strDigit;
	if (maxStr.length() < minStr.length())//需要负号
	{
		maxStr = rhs.strDigit;
		minStr = lhs.strDigit;
		minor = true;
	}
	else if (maxStr.length() == minStr.length())
	{
		if (maxStr < minStr)//需要负号
		{
			maxStr = rhs.strDigit;
			minStr = lhs.strDigit;
			minor = true;
		}
		else if (maxStr == minStr)
		{
			return string("0");
		}
	}
	int size1 = maxStr.length() - 1;
	int size2 = minStr.length() - 1;
	int i = size1;
	int j = size2;
	for (; (i >= 0) && (j >= 0); i--, j--)
	{
		int ret = maxStr[i] - minStr[j];//两个字符数字直接相减，结果等价于它们对应的整数相减
		if (flag)
		{
			ret -= 1;
			flag = false;
		}
		if (ret < 0)
		{
			ret += 10;
			flag = true;
		}
		result.push_back(ret + '0');
	}
	while (i >= 0)
	{
		int ret = maxStr[i] - '0';
		if (flag)
		{
			ret -= 1;
			flag = false;
		}

		if (ret < 0)
		{
			ret += 10;
			flag = true;
		}
		result.push_back(ret + '0');
		i--;
	}
	//去除前导零，将 003 修正为 3
	while (*(result.rbegin()) == '0')
	{
		result.pop_back();
	}
	if (minor)
	{
		result.push_back('-');
	}
	reverse(result.begin(), result.end());
	return result;
	//string retStr;
	//auto it = result.rbegin();
	//for (; it != result.rend(); ++it)
	//{
	//	if (*it != '0')  
	//	{
	//		break;
	//	}
	//}
	//for (; it != result.rend(); ++it)
	//{
	//	retStr.push_back(*it);
	//}
	//if (minor)
	//{
	//	retStr.insert(retStr.begin(), '-');
	//}
	//return retStr;
}

int main()
{
//大数的加减法
	//大数加法
		//遍历字符串 l,r，从后往前遍历，同位置的数字相加
		//进位 flag 存入一个结果当中 string result
		//同时完成与某个字符串先完成，都要考虑进位
	//大数减法
		//找大的字符串做减数，小的做被减数
		//遍历两个字符串，减法，借位（bool flag），string result 存下来
	BigInt int1("9785645649886874535428765");
	BigInt int2("28937697857832167849697653231243");
	BigInt int3("999545");
	BigInt int4("999544");
	cout << int1 + int2 << endl;
	cout << int1 - int2 << endl;
	cout << int3 - int4 << endl;

	system("pause");
	return 0;
}
*/
