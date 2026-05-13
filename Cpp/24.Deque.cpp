#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<deque>
#include<algorithm>

/*
//Deque 构造函数 2025.11.14
void printDeque(const deque<int>&d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)//加上 const 可以防止被误修改
	{
		//*it = 100;
		cout << *it << " ";
	}
	cout << endl;
}
void test01()
{
	deque<int>d1;//deque<T > deqT
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);
	deque<int>d2(d1.begin(), d1.end());//deque(beg, end)
	printDeque(d2);
	deque<int>d3(10, 100);//deque(n, elem)
	printDeque(d3);
	deque<int>d4 = d3;//deque(const deque& deq)
	printDeque(d4);
}

//Deque 赋值操作
void test02()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);
	deque<int>d2;
	d2 = d1;//deque& operator=(const deque & deq)
	printDeque(d2);
	deque<int>d3;
	d3.assign(d1.begin(), d1.end());//assign(beg, end)
	printDeque(d3);
	deque<int>d4;
	d4.assign(10, 100);
	printDeque(d4);//assign(n, elem)
}

//Deque 大小操作
void test03()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);
	if (d1.empty()) //deque.empty()
	{
		cout << "d1为空!" << endl;
	}
	else {
		cout << "d1不为空!" << endl;
		cout << "d1的大小为：" << d1.size() << endl;//deque.size()
	}
	
	d1.resize(15, 1);//deque.resize(num)，d1.resize(15) 将会以 0 来填充
	printDeque(d1);
	d1.resize(5);//deque.resize(num, elem)
	printDeque(d1);
}

//Deque 插入和删除
void test04()
{
	deque<int>d1;
	d1.push_back(10);//尾插，push_back(elem)
	d1.push_back(20);
	d1.push_front(100);//头插，push_front(elem)
	d1.push_front(200);
	printDeque(d1);
	d1.pop_back();//尾删，pop_back()
	printDeque(d1);
	d1.pop_front();//头删，pop_front()
	printDeque(d1);
}
void test05()
{
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(100);
	d1.push_front(200);
	printDeque(d1);
	d1.insert(d1.begin(), 1000);//insert(pos, elem)
	printDeque(d1);
	d1.insert(d1.begin(), 2, 1000);//insert(pos, n, elem)
	printDeque(d1);
	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);
	d1.insert(d1.begin(), d2.begin(), d2.end());//insert(pos, beg, end)
	printDeque(d1);
}
void test06()
{
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(100);
	d1.push_front(200);
	printDeque(d1);
	d1.erase(d1.begin());//erase(pos)
	printDeque(d1);
	d1.erase(d1.begin(), d1.end() - 2);//erase(beg, end)
	printDeque(d1);
	d1.clear();//clear()
	printDeque(d1);
}

//Deque 数据存取
void test07()
{
	deque<int>d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);
	for (int i = 0; i < d.size(); i++)
	{
		cout << d[i] << " ";//operator[]
	}
	cout << endl;
	for (int i = 0; i < d.size(); i++)
	{
		cout << d.at(i) << " ";//at(int idx)
	}
	cout << endl;
	cout << "front:" << d.front() << endl;//front()
	cout << "back:" << d.back() << endl;//back()
}

//Deque 排序
void test08()
{
	deque<int>d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);
	cout << "排序前：" << endl;
	printDeque(d);
	sort(d.begin(), d.end());//使用 sort，必须添加 #include<algorithm>，对于支持随机访问的迭代器的容器，都支持 sort 算法
	cout << "排序后：" << endl;
	printDeque(d);
}

//评委打分案例
class Person1//法一-自写，选手类
{	
public:
	Person1(string name, int score[])
	{
		this->m_Name = name;
		for (int i = 0; i < 10; i++)
		{
			this->m_Score[i] = score[i];
		}
	}
	string m_Name;
	int m_Score[10];
};
void test09()
{
	int score_A[10] = { 7,8,9,7,8,9,10,6,8,9};//创建 5 名选手信息
	class Person1 A("A", score_A);
	int score_B[10] = { 4,7,7,6,5,9,8,6,8,9 };
	class Person1 B("B", score_B);
	int score_C[10] = { 9,9,9,9,8,9,10,7,8,9 };
	class Person1 C("C", score_C);
	int score_D[10] = { 10,10,9,8,8,9,10,8,8,9 };
	class Person1 D("D", score_D);
	int score_E[10] = { 7,8,7,7,8,9,9,8,8,9 };
	class Person1 E("E", score_E);
	vector<Person1>v;
	deque<int>d;
	vector<Person1>::iterator it;
	v.push_back(A);//将 5 名选手信息放到容器 v 中
	v.push_back(B);
	v.push_back(C);
	v.push_back(D);
	v.push_back(E);
	float socre_fin = 0;//存放总和分数
	float socre_avg = 0;//存放平均分数
	for (it = v.begin(); it != v.end(); it++)
	{
		socre_fin = 0;
		socre_avg = 0;
		for (int i = 0; i < 10; i++)//将 5 名选手的分数放到 d 容器中
		{
			d.push_back(*((*it).m_Score + i));
		}
		sort(d.begin(), d.end());//对 d 容器中的分数排序
		d.pop_back();//去掉最高分
		d.pop_front();//去掉最低分
		for (int i = 0; i < 8; i++)//将分数累加
		{
			socre_fin = socre_fin + d[i];
		}
		socre_avg = socre_fin / 8;//求分数平均值
		cout << "选手：" << (*it).m_Name << " 分数：" << socre_avg << endl;//输出
		d.clear();//清楚当前选手的信息，为存放下一位选手信息做准备
	}
}
class Person//法二-黑马，选手类
{
public:
	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}

	string m_Name;//姓名
	int m_Score;//平均分
};
void createPerson(vector<Person>& v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameSeed[i];//字符拼接
		int score = 0;
		Person p(name, score);
		v.push_back(p);//将创建的 person 对象 放入到容器中
	}
}
void setScore(vector<Person>& v)//打分
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int>d;//将评委的分数 放入到deque容器中
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;  // 0 + 60 ~ 40 + 60
			d.push_back(score);
		}
		//cout << "选手： " << it->m_Name << " 打分： " << endl;测试
		//for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		//{
		//	cout << *dit << " ";
		//}
		//cout << endl;
		sort(d.begin(), d.end());//排序
		d.pop_back();//去除最高和最低分
		d.pop_front();
		int sum = 0;//取平均分
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit; //累加每个评委的分数
		}
		int avg = sum / d.size();
		it->m_Score = avg;//将平均分赋值给选手身上
	}
}
void showScore(vector<Person>& v)//打印分数
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名： " << it->m_Name << " 平均分： " << it->m_Score << endl;
	}
}

int main()
{
//Deque 构造函数 2025.11.14	
	//功能：双端数组，可以对头端进行插入删除操作
	//Deque 与 Vector 区别：
		//vector 对于头部的插入删除效率低，数据量越大，效率越低
		//deque 相对而言，对头部的插入删除速度回比 vector 快
		//vector 访问元素时的速度会比 deque 快, 这和两者内部实现有关
	//deque 内部工作原理:
		//deque 内部有个中控器，维护每段缓冲区中的内容，缓冲区中存放真实数据
		//中控器维护的是每个缓冲区的地址，使得使用 deque 时像一片连续的内存空间
	//deque 容器的迭代器也是支持随机访问的
	//函数原型：
		//deque<T > deqT;            //默认构造形式
		//deque(beg, end);           //构造函数将 [beg, end) 区间中的元素拷贝给本身
		//deque(n, elem);            //构造函数将 n 个 elem 拷贝给本身
		//deque(const deque& deq);   //拷贝构造函数
	test01();

//Deque 赋值操作
	//函数原型：
		//deque& operator=(const deque & deq);         //重载等号操作符
		//assign(beg, end);                            //将 [beg, end) 区间中的数据拷贝赋值给本身。
		//assign(n, elem);                             //将 n 个 elem 拷贝赋值给本身。
	test02();
	
//Deque 大小操作
	//函数原型：
		//deque.empty();               //判断容器是否为空
		//deque.size();                //返回容器中元素的个数
		//deque.resize(num);           //重新指定容器的长度为 num,若容器变长，则以默认值填充新位置；如果容器变短，则末尾超出容器长度的元素被删除
		//deque.resize(num, elem);     //重新指定容器的长度为 num,若容器变长，则以 elem 值填充新位置，如果容器变短，则末尾超出容器长度的元素被删除。
	test03();

//Deque 插入和删除
	//函数原型：
		//两端插入操作：
			//push_back(elem);          //在容器尾部添加一个数据
			//push_front(elem);         //在容器头部插入一个数据
			//pop_back();               //删除容器最后一个数据
			//pop_front();              //删除容器第一个数据
		//指定位置操作：
			//insert(pos, elem);        //在 pos 位置插入一个 elem 元素的拷贝，返回新数据的位置。
			//insert(pos, n, elem);     //在 pos 位置插入 n 个 elem 数据，无返回值。
			//insert(pos, beg, end);    //在 pos 位置插入 [beg,end) 区间的数据，无返回值。
			//clear();                  //清空容器的所有数据
			//erase(beg, end);          //删除 [beg,end) 区间的数据，返回下一个数据的位置。
			//erase(pos);               //删除 pos 位置的数据，返回下一个数据的位置。
	test04();
	test05();
	test06();

//Deque 数据存取
	//函数原型：
		//at(int idx);     //返回索引 idx 所指的数据
		//operator[];      //返回索引 idx 所指的数据
		//front();         //返回容器中第一个数据元素
		//back();          //返回容器中最后一个数据元素
	test07();

//Deque 排序
	//算法：sort(iterator beg, iterator end)  //对 beg 和 end 区间内元素进行排序
	test08();

//评委打分案例
	//案例描述：有 5 名选手：选手 ABCDE，10 个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分
	//实现步骤:
		//1. 创建五名选手，放到 vector 中
		//2. 遍历 vector 容器，取出来每一个选手，执行 for 循环，可以把 10 个评分打分存到 deque 容器中
		//3. sort 算法对 deque 容器中分数排序，去除最高和最低分
		//4. deque 容器遍历一遍，累加总分
		//5. 获取平均分
	test09();//法一-自写
	vector<Person>v;//法二-黑马
	createPerson(v);
	setScore(v);
	showScore(v);

	system("pause");
	return 0;
}
*/