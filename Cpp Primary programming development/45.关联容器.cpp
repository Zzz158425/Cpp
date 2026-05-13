#include<iostream>
#include<typeinfo>
#include<string>
#include<vector>
//使用有序关联容器包含头文件
#include<set>
#include<map>
//使用无序关联容器包含的头文件
#include<unordered_set>
#include<unordered_map>
using namespace std;

/*
//有序关联容器
class Student
{
public:
	Student(int id, string name)
		:_id(id), _name(name) { }
	bool operator<(const Student& stu) const
	{
		return stu._id > _id;
	}
private:
	int _id;
	string _name;
	friend ostream& operator<<(ostream& out, const Student& stu);
};
ostream& operator<<(ostream& out, const Student& stu)
{
	cout << "id:" << stu._id << "name:" << stu._name << endl;
	return out;
}
class Student1
{
public:
	Student1(int id = 0, string name = " ")
		:_id(id), _name(name) {
	}
private:
	int _id;
	string _name;
	friend ostream& operator<<(ostream& out, const Student1& stu);
};
ostream& operator<<(ostream& out, const Student1& stu)
{
	cout << "id:" << stu._id << "name:" << stu._name << endl;
	return out;
}


int main()
{
//关联容器	
	//使用有序关联容器包含头文件：
		//#include<set>:set、multiset
		//#include<map>:map、multimap
	//使用无序关联容器包含的头文件
		//#include<unordered_set>:
		//#include<unordered_map>:
	//常用增删查方法
		//增加：insert
		//遍历：iterator，find
		//删除：erase(key)、erase(it)
		
//无序关联容器		
	//set 与 multiset
	unordered_set<int> set1;//不会存储 key 值重复的元素
	for (int i = 0; i < 50; i++)
	{
		set1.insert(rand() % 20 + 1);
	}
	cout << set1.size() << endl;
	cout << set1.count(15) << endl;
	unordered_multiset<int> set2;//可以存储 key 值重复的元素
	for (int i = 0; i < 50; i++)
	{
		set2.insert(rand() % 20 + 1);
	}
	cout << set2.size() << endl;
	cout << set2.count(15) << endl;
	auto it1 = set1.begin();
	for (; it1 != set1.end(); ++it1)
	{
		cout << *it1 << " ";
	}
	cout << endl;
	set1.erase(20);//按 key 值删除元素
	for (it1 = set1.begin(); it1 != set1.end();)
	{
		if (*it1 == 30)
		{
			it1 = set1.erase(it1);//调用 erase，it1 迭代器就失效了，需更新迭代器
		}
		else
		{
			++it1;
		}
	}
	it1 = set1.find(20);//存在返回迭代器，不存在返回末尾迭代器
	if (it1 != set1.end())
	{
		set1.erase(it1);
	}
	for (int v : set1)
	{
		cout << v << " ";
	}
	cout << endl;
	//map 与 multimap
	unordered_map<int, string> map1;//不会存储 key 值重复的元素
	map1.insert(make_pair(1000, "张三"));
	map1.insert({ 1010, "李四" });
	map1.insert({ 1020, "王五" });
	cout << map1.size() << endl;
	cout << map1[1000] << endl;//查询
	map1.erase(1020);//删除
	cout << map1.size() << endl;
	map1[2000];//map 的 operator[] 如果 key 不存在，会插入一堆数据 [key, string()]
	cout << map1.size() << endl;
	map1[2001] = "刘硕";//利用 operator[] 进行插入
	map1[1000] = "张四";//利用 operator[] 进行修改
	cout << map1[1000] << endl;
	auto it2 = map1.find(2001);
	if (it2 != map1.end())
	{
		cout << "key:" << it2->first << "v:" << it2->second << endl;
	}
	unordered_multimap<int, string> map2;//可以存储 key 值重复的元素
	map2.insert(make_pair(1000, "张三"));//增加
	map2.insert({ 1010, "李四" });
	map2.insert({ 1020, "王五" });
	map2.insert({ 1000, "王凯" });
	cout << map2.size() << endl;
	//案例 1
		//处理海量数据查重复，并统计那些数组重复，重复次数
	const int ARR_LEN = 100;
	int arr[ARR_LEN] = { 0 };
	for (int i = 0; i < ARR_LEN; ++i)
	{
		arr[i] = rand() % 20 + 1;
	}
	unordered_map<int, int>map3;//第一个 int 存数字，第二个 int 存重复次数
	for (int k : arr)
	{
		auto it = map3.find(k);
		if (it == map3.end())
		{
			map3.insert({ k, 1 });
		}
		else
		{
			it->second++;
		}
		//map3[k]++;当 k 未存在会自动进行插入 [k, int() = 0] -> 通过自 ++ [k, 1]；k 存在直接自 ++
	}
	for ( const pair<int, int> &p : map3)//&p 直接指向 map3 里的原对象，没有拷贝，零成本访问，此外必须使用常引用，因为 unordered_map<int, int> 中存储的元素类型是 std::pair<const int, int>
	{
		if (p.second > 1)
		{
			cout << "key:" << p.first << "count:" << p.second << endl;
		}
	}
	auto it3 = map3.begin();
	for (; it3 != map3.end(); ++it3)
	{
		if (it3->second > 1)
		{
			cout << "key:" << it3->first << "count:" << it3->second << endl;
		}
	}
	cout << endl;
	//案例 2
		//处理海量数据查重复，把数字进行去重打印
	unordered_set<int>set3;
	for (int k : arr)
	{
		set3.insert(k);
	}
	for (int v : set3)
	{
		cout << v << " ";
	}
	cout << endl;

//有序关联容器
	//默认从小到大
	//与无序关联容器 set、multiset、map、multimap 基本一致
	set<int> set4;
	for (int i = 0; i < 20; i++)
	{
		set4.insert(rand() % 20 + 1);
	}
	for (int v : set4)
	{
		cout << v << " ";
	}
	cout << endl;
	set<Student> set5;//自定义容器需要提供 < 运算符重载
	set5.insert(Student(1020, "张雯"));
	set5.insert(Student(1010, "李广"));
	for (auto it1 = set5.begin(); it1 != set5.end(); ++it1)
	{
		cout << *it1 ;
	}
	cout << endl;
	map<int, Student1> stuMap;
	stuMap.insert({ 1000, Student1(1000, "张雯")});
	stuMap.insert({ 1020, Student1(1020, "李广") });
	stuMap.insert({ 1030, Student1(1030, "高洋") });
	cout << stuMap[1020] << endl;//需提供默认构造函数，当 stuMap[2000]，会自动插入 [2000, V()]，此时排序是利用 key 来排序，可以不重载 <
	auto it4 = stuMap.begin();
	for (; it4 != stuMap.end(); ++it4)
	{
		cout << "key:" << it4->first << "value:" << it4->second;
	}
	cout << endl;

	system("pause");
	return 0;
}
*/
