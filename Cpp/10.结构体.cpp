#include<iostream>
#include<string>
#include<ctime>
using namespace std;

/*
//结构体的定义与使用 2025.10.19
struct Student
{
	string name;
	int age;
	int score;
};
struct Student1
{
	string name;
	int age;
	int score;
}s3;//直接创建变量

//结构体嵌套结构体
struct teacher
{
	int id;
	string name;
	int age;
	struct Student stu;
};

//结构体做函数参数
void printstudent1(struct Student s)//值传递
{
	s.age = 28;//形参不会影响实参
	cout << "子函数 1 中打印 姓名：" << s.name << " 年龄：" << s.age << " 分数：" << s.score << endl;
}
void printstudent2(struct Student* p)//地址传递
{
	p -> age = 29;//会改变实参的值
	cout << "子函数 2 中打印 姓名：" << p -> name << " 年龄：" << p-> age << " 分数：" << p-> score << endl;
}

//结构体中 const 使用场景
void printstudent3(const struct Student* s3)//将函数中的形参改为指针，可以减少内存空间，因为指针始终都是 4 / 8 字节，而且不会复制新的副本出来
{
	//s3->age = 20;加入 const 之后，一旦有修改的操作就会报错，防止误操作
	cout << "姓名：" << s3 -> name << " 年龄：" << s3 -> age << " 分数：" << s3 -> score << endl;
}

//结构体案例 1
struct STU
{
	string name;
	int score;
};
struct TEA
{
	string name;
	struct STU stu[5];
};
void allocateSpace(struct TEA teaArray[], int len)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < len; i++)//给老师赋值
	{
		teaArray[i].name = "Teacher_";
		teaArray[i].name += nameSeed[i];//拼接 Teacher_
		for (int j = 0; j < 5; j++)
		{
			teaArray[i].stu[j].name = "Stuent_";
			teaArray[i].stu[j].name += nameSeed[j];//拼接 Stuent_
			int random = rand() % 61 + 40;//随机产生40 ~ 100
			teaArray[i].stu[j].score = random;
		}
	}
}
void printInfo(struct TEA teaArray[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "老师姓名：" << teaArray[i].name << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\t学生姓名：" << teaArray[i].stu[j].name 
				 << " 考试分数" << teaArray[i].stu[j].score << endl;
		}
	}
}

//结构体案例 2
struct hero
{
	string name;
	int age;
	string sex;
};
void bubblesort(struct hero charc[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (charc[j].age > charc[j + 1].age)
			{
				//也可以更简单 struct hero temp = charc[j];
				//charc[j] = charc[j + 1];
				//charc[j + 1] = temp;
				int age_save = charc[j].age;//中间变量暂存
				string name_save = charc[j].name;
				string sex_save = charc[j].sex;
				charc[j].age = charc[j + 1].age;//交换
				charc[j].name = charc[j + 1].name;
				charc[j].sex = charc[j + 1].name;
				charc[j + 1].age = age_save;
				charc[j + 1].name = name_save;
				charc[j + 1].sex = sex_save;
			}
		}
	}
}
void printhero(struct hero charc[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "英雄姓名：" << charc[i].name << " 英雄年龄：" << charc[i].age 
			 << " 英雄性别：" << charc[i].sex << endl;
	}
	cout << "--------" << endl;
}


int main()
{
//结构体的定义与使用 2025.10.19
	//结构体属于用户自定义的数据类型，允许用户存储不同的数据类型
	//语法：struct 结构体名{ 结构体成员列表 }；
	//通过结构体创建变量的方式有三种：
		//1.struct 结构体名 变量名
		//2.struct 结构体名 变量名 = { 成员1值 ， 成员2值... }
		//3.定义结构体时顺便创建变量
	struct Student s1;
	s1.name = "张三";
	s1.age = 18;
	s1.score = 100;
	cout << "姓名：" << s1.name << " 年龄：" << s1.age << " 分数：" << s1.score << endl;
	struct Student s2 = { "李四",19,80 };
	cout << "姓名：" << s2.name << " 年龄：" << s2.age << " 分数：" << s2.score << endl;
	s3.name = "王五";
	s3.age = 20;
	s3.score = 60;
	cout << "姓名：" << s3.name << " 年龄：" << s3.age << " 分数：" << s3.score << endl;

//结构体数组
	//作用：将自定义的结构体放入到数组中方便维护
	//语法：struct  结构体名 数组名[元素个数] = { {} , {} , ... {} }
	struct Student stuArray[3] = {
		{"张三", 18, 100},
		{"李四", 28, 80},
		{"王五", 38, 66}
	};
	stuArray[2].name = "赵六";//给结构体数组中的元素赋值
	stuArray[2].age = 80;
	stuArray[2].score = 60;
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		cout << "姓名：" << stuArray[i].name 
			 << " 年龄：" << stuArray[i].age 
			 << " 分数：" << stuArray[i].score << endl;
	}

//结构体指针
	//作用：通过指针访问结构体中的成员
	//利用操作符 -> 可以通过结构体指针访问结构体属性
	struct Student s = { "秦七",21,99 };
	struct Student* p = &s;
	cout << "姓名：" << p -> name << " 年龄：" << p-> age << " 分数：" << p-> score << endl;

//结构体嵌套结构体
	//作用：结构体中的成员可以是另一个结构体
	//例如：每个老师辅导一个学员，一个老师的结构体中，记录一个学生的结构体
	struct teacher t;
	t.id = 10000;
	t.name = "老王";
	t.age = 50;
	t.stu.name = "小王";
	t.stu.age = 16;
	t.stu.score = 66;
	cout << "老师姓名：" << t.name << " 老师编号：" << t.id << " 老师年龄：" << t.age 
		 << " 辅导学员姓名： " << t.stu.name << " 年龄：" << t.stu.age << " 考试分数： " << t.stu.score << endl;

//结构体做函数参数
	//作用：将结构体作为参数向函数中传递
	//传递方式有两种：
		//1.值传递
		//2.地址传递
	struct Student ss;
	ss.name = "张三";
	ss.age = 20;
	ss.score = 85;
	cout << "main 函数中打印 姓名：" << ss.name << " 年龄：" << ss.age << " 分数：" << ss.score << endl;
	printstudent1(ss);
	cout << "main 函数中打印 姓名：" << ss.name << " 年龄：" << ss.age << " 分数：" << ss.score << endl;
	printstudent2(&ss);
	cout << "main 函数中打印 姓名：" << ss.name << " 年龄：" << ss.age << " 分数：" << ss.score << endl;

//结构体中 const 使用场景
	//作用：用 const 来防止误操作
	struct Student s3 = { "张五", 15, 70 };
	printstudent3(&s3);

//结构体案例 1
	srand((unsigned int)time(NULL));//随机数种子
	struct TEA teaArray[3];
	int len = sizeof(teaArray) / sizeof(teaArray[0]);
	allocateSpace(teaArray, len);
	printInfo(teaArray, len);

//结构体案例 2
	struct hero charc[5] =
	{
		{"刘备",23,"男"},
		{"关羽",22,"男"},
		{"张飞",20,"男"},
		{"赵云",21,"男"},
		{"貂蝉",19,"女"},
	};
	len = sizeof(charc) / sizeof(charc[0]);
	printhero(charc, len);
	bubblesort(charc, len);
	printhero(charc, len);

	system("pause");
	return 0;
}
*/