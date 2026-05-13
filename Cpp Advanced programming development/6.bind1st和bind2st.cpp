#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<ctime>
using namespace std;
//2026.4.26

/*
//C++ STL 中的绑定器
template<typename Container>
void showContainer(Container &con)
{
	typename Container::iterator it = con.begin();//需加 typename，告诉编译器 Container::iterator 中的 iterator 为类型
	for (; it != con.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//bindlst 和 bind2nd 的底层实现
template<typename Iterator, typename Compare>
Iterator my_find_if(Iterator first, Iterator last, Compare comp)
{
	for (; first != last; first++)
	{
		if (comp(*first))//comp.operator()(*first)，一元函数对象
		{
			return first;
		}
	}
	return last;
}
template<typename Compare, typename T>
class _mybind1st//绑定器是函数对象的一个应用
{
public:
	_mybind1st(Compare com,	T val)
		: _comp(com)
		, _val(val)
	{ }
	bool operator()(const T& second)
	{
		return _comp(_val, second);//greater
	}
private:
	Compare _comp;
	T _val;
};
template<typename Compare, typename T>
_mybind1st<Compare, T> mybind1st(Compare comp, const T& val)
{
	return _mybind1st<Compare, T>(comp, val);//直接使用函数模板，好处是可以进行类型的推演
}

int main()
{
//C++ STL 中的绑定器
	//bindlst：operator() 的第一个形参变量绑定成一个确定的值，本身是一个函数对象
	//bind2nd：operator() 的第二个形参变量绑定成一个确定的值，本身是一个函数对象
	vector<int> vec;
	srand(time(0));
	for (int i = 0; i < 20; i++)
	{
		vec.push_back(rand() % 100 + 1);
	}
	showContainer(vec);
	sort(vec.begin(), vec.end());//默认小到大排序
	showContainer(vec);
	sort(vec.begin(), vec.end(), greater<int>());//大到小排序
	showContainer(vec);
	//把 70 按顺序插入到 vec 容器当中，找第一个小于 70 的数字
	//需一元函数对象，但是库中均为二元函数对象，绑定器 + 二元函数对象 = 一元函数对象
	//bind1st + greater bool operator()(70, const _Ty& _Right)
	//bind1st + less bool operator()(const _Ty& _left, 70)
	auto it1 = find_if(vec.begin(), vec.end(),
		bind1st(greater<int>(), 70));
	//auto it1 = find_if(vec.begin(), vec.end(),
	//	bind2st(less<int>(), 70));
	if (it1 != vec.end())
	{
		vec.insert(it1, 70);
	}
	showContainer(vec);

//bindlst 和 bind2nd 的底层实现
	auto it3 = my_find_if(vec.begin(), vec.end(),
		mybind1st(greater<int>(), 70));
	showContainer(vec);

	system("pause");
	return 0;
}
*/