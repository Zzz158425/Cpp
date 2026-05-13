#include<iostream>
using namespace std;
#include<string>

/*
int main()
{
//一维数组定义方式
	//所谓数组，就是一个集合，里面存放了相同类型的数据元素
		//特点1：数组中的每个数据元素都是相同的数据类型
		//特点2：数组是由连续的内存位置组成的
	//一维数组定义的三种方式：
		//1.数组名[数组长度];
		//2.数组名[数组长度] = { 值1，值2 ... };
		//3.数组名[] = { 值1，值2 ... };
	//数据类型 数组名[元素个数];
	int score[10];//数组名的命名规范与变量名命名规范一致，不要和变量重名
	score[0] = 100;//利用下标赋值。从 0 开始索引
	score[1] = 99;
	score[2] = 85;
	cout << score[0] << endl;//利用下标输出
	cout << score[1] << endl;
	cout << score[2] << endl;
	//数据类型 数组名[元素个数] =  {值1，值2 ，值3 ...};
	int score2[10] = { 100, 90,80,70,60,50,40,30,20,10 };//如果{}内不足10个数据，剩余数据用0补全
	cout << score2[0] << endl;//逐个输出
	cout << score2[1] << endl;
	int i = 0;
	int j = 0;
	for ( i = 0; i < 10; i++)//一个一个输出太麻烦，因此可以利用循环进行输出
	{
		cout << score2[i] << endl;
	}
	//数据类型 数组名[] =  {值1，值2 ，值3 ...};
	int score3[] = { 100,90,80,70,60,50,40,30,20,10 };
	for (int i = 0; i < 10; i++)
	{
		cout << score3[i] << endl;
	}

//数组名
	//一维数组名称的用途
		//1. 可以统计整个数组在内存中的长度
		//2. 可以获取数组在内存中的首地址
	//可以获取整个数组占用内存空间大小
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };//数组名是常量，因此不可以赋值
	cout << "整个数组所占内存空间为： " << sizeof(arr) << endl;
	cout << "每个元素所占内存空间为： " << sizeof(arr[0]) << endl;
	cout << "数组的元素个数为： " << sizeof(arr) / sizeof(arr[0]) << endl;
	//可以通过数组名获取到数组首地址
	cout << "数组首地址为： " << (long long)arr << endl;
	cout << "数组中第一个元素地址为： " << (long long)&arr[0] << endl;
	cout << "数组中第二个元素地址为： " << (long long)&arr[1] << endl;

//五知小猪称体重练习
	//法一
	int weight[5] = { 100,350,200,400,450 };
	int weight_comparison1 = 0;//让 weight_comparison1 始终比 weight_comparison2 大
	int weight_comparison2 = 0;
	i = 0;//控制 weight_comparison1 指向位置
	j = 1;//控制 weight_comparison2 指向位置
	weight_comparison1 = weight[i];
	weight_comparison2 = weight[i + j];
	while (1)
	{
		if ( weight_comparison1 < weight_comparison2 )
		{
			weight_comparison1 = weight_comparison2;//让 weight_comparison1 始终比 weight_comparison2 大
			j++;//控制 weight_comparison2 指向下一个位置
			if (j == 5)// j == 5 比较完毕，输出结果
			{
				cout << "最重的小猪为：" << weight_comparison1 << endl;
				break;
			}
			weight_comparison2 = weight[i + j];// j != 5 未比较完，控制 weight_comparison2 指向下一个位置
		}
		else
		{
			j++;//控制 weight_comparison2 指向下一个位置
			if (j == 5)
			{
				cout << "最重的小猪为：" << weight_comparison1 << endl;
				break;
			}
			weight_comparison2 = weight[i + j];
		}
	}
	//法二
	int max = 0;
	for ( i = 0; i < 5; i++)
	{
		if (weight[i] > max)
		{
			max = weight[i];
		}
	}
	cout << "最重的小猪为：" << max << endl;

//数组元素逆置练习
	//法一
	int arr_pra[5] = { 1,3,2,5,4 };
	int start = 0;
	int end  = sizeof(arr_pra) / sizeof(arr[0]) - 1;//末尾素组下标
	int arr_pra_save[5] = { 0 };
	for ( i = end; i >= 0; i--)
	{
		arr_pra_save[start] = arr_pra[end];
		cout << arr_pra_save[start] << " ";
		start++;
		end--;
	}
	//法二
	start = 0;
	end = sizeof(arr_pra) / sizeof(arr[0]) - 1;//末尾素组下标
	while (start < end)
	{
		int temp = arr_pra[start];
		arr_pra[start] = arr_pra[end];
		arr_pra[end] = temp;
		start++;
		end--;
	}
	end = sizeof(arr_pra) / sizeof(arr[0]);
	for ( i = 0; i < end; i++)
	{
		cout << endl;
		cout << arr_pra[i] << " ";
	}

//冒泡排序练习 2025.10.17
	//作用：最常用的排序算法，对数组内元素进行排序
		//1. 比较相邻的元素。如果第一个比第二个大，就交换他们两个，排序总论述 = 元素个数 - 1，每轮对比次数 = 元素个数 - 排序轮数 - 1
		//2. 对每一对相邻元素做同样的工作，执行完毕后，找到第一个最大值。
		//3. 重复以上的步骤，每次比较次数 - 1，直到不需要比较
	i = 0;
	j = 0;
	int mid = 0;
	int arr_bubblesort[] = {4,2,8,0,5,7,1,3,9};
	int num_arr_bubblesort = sizeof(arr_bubblesort) / sizeof(arr_bubblesort[0]) - 1;//比较次数
	for ( i = 0; i < num_arr_bubblesort; i++)//比较次数
	{
		for ( j = 0; j < num_arr_bubblesort - i; j++)//交换次数
		{
			if (arr_bubblesort[j] > arr_bubblesort[j + 1])//满足条件交换
			{
				mid = 0;
				mid = arr_bubblesort[j];
				arr_bubblesort[j] = arr_bubblesort[j + 1];
				arr_bubblesort[j + 1] = mid;
			}
		}
	}
	i = 0;
	for ( i = 0; i <= num_arr_bubblesort; i++)
	{
		cout << arr_bubblesort[i] << " ";
	}

//二维数组定义方式
	//二维数组定义的四种方式：
		//1.数据类型  数组名[行数][列数];
		//2.数据类型  数组名[行数][列数] = { {数据1，数据2 } ，{数据3，数据4 } };
		//3.数据类型  数组名[行数][列数] = { 数据1，数据2，数据3，数据4 };
		//4.数据类型  数组名[][列数] = { 数据1，数据2，数据3，数据4 };
	i = 0;
	j = 0;
	int arr_dimension[2][3];
	arr_dimension[0][0] = 1;
	arr_dimension[0][1] = 2;
	arr_dimension[0][2] = 3;
	arr_dimension[1][0] = 4;
	arr_dimension[1][1] = 5;
	arr_dimension[1][2] = 6;
	cout << arr_dimension[0][0] << endl;
	cout << arr_dimension[0][1] << endl;
	for ( i = 0; i < 2; i++)
	{
		for ( j = 0; j < 3; j++)
		{
			cout << arr_dimension[i][j] << " ";
		}
		cout << endl;
	}
	int arr_dimension1[2][3] = {
		{7,8,9},
		{4,5,6}
	};
	i = 0;
	j = 0;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			cout << arr_dimension1[i][j] << " ";
		}
		cout << endl;
	}
	int arr_dimension2[2][3] = { 1,2,3,4,5,6 };
	int arr_dimension3[][3] = { 1,2,3,4,5,6 };

//二维数组数组名
	//查看二维数组所占内存空间
	//获取二维数组首地址
	int arr_dimension4[2][3] = {
	{7,7,7},
	{8,8,8}
	};
	cout << "二维数组大小： " << sizeof(arr_dimension4) << endl;
	cout << "二维数组一行大小： " << sizeof(arr_dimension4[0]) << endl;
	cout << "二维数组元素大小： " << sizeof(arr_dimension4[0][0]) << endl;
	cout << "二维数组行数： " << sizeof(arr_dimension4) / sizeof(arr_dimension4[0]) << endl;
	cout << "二维数组列数： " << sizeof(arr_dimension4[0]) / sizeof(arr_dimension4[0][0]) << endl;
	cout << "二维数组首地址：" << arr_dimension4 << endl;
	cout << "二维数组第一行地址：" << arr_dimension4[0] << endl;
	cout << "二维数组第二行地址：" << arr_dimension4[1] << endl;
	cout << "二维数组第一个元素地址：" << &arr_dimension4[0][0] << endl;
	cout << "二维数组第二个元素地址：" << &arr_dimension4[0][1] << endl;

//考试成绩练习
	int grade[3][3] = {
		{100,100,100},
		{90,50,100},
		{60,70,80}
	};
	cout << "张三的成绩为：" << (grade[0][0] + grade[0][1] + grade[0][2]) << endl;
	cout << "李四的成绩为：" << (grade[1][0] + grade[1][1] + grade[1][2]) << endl;
	cout << "王五的成绩为：" << (grade[2][0] + grade[2][1] + grade[2][2]) << endl;
	i = 0;
	j = 0;
	string grade_name[3] = {"张三","李四","王五"};
	int grade_sum = 0;
	for ( i = 0; i < 3; i++)
	{
		grade_sum = 0;
		for (j = 0; j < 3; j++)
		{
			grade_sum = grade[i][j] + grade_sum;
		}
		cout << "第 " << i + 1 <<" 人成绩为：" << grade_sum << endl;
		cout << grade_name[i] <<" 成绩为：" << grade_sum << endl;
	}

	system("pause");
	return 0;
}
*/