#include<iostream>
using namespace std;

/*
//指针和函数
void swapp(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

//指针配合数组和函数案例
void bubblesort(int* arr_bubblesort, int len)
{
	int i = 0;
	int j = 0;
	int mid = 0;
	for (i = 0; i < len - 1; i++)//比较次数
	{
		for (j = 0; j < len - i - 1; j++)//交换次数
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
}
void printarr1(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << endl;
	}
}

int main()
{
//指针的定义和使用
	//普通变量存放的是数据,指针变量存放的是地址
	//指针的作用：可以通过指针间接访问内存，内存编号是从 0 开始记录的，一般用十六进制数字表示，可以利用指针变量保存地址
	//指针变量定义语法：数据类型* 变量名；
	int a = 10;
	int* p = &a;
	cout << &a << endl; //打印数据 a 的地址
	cout << p << endl;  //打印指针变量 p
	*p = 1000;
	cout << "a = " << a << endl;
	cout << "*p = " << *p << endl;//通过 * 操作指针变量指向的内存，* 表示解引用

//指针所占内存空间
	//所有指针类型在 32 位操作系统下是 4 个字节，64 位操作系统下是 8 个字节
	cout << "sizeof(int*) = " << sizeof(p) << endl;
	cout << "sizeof(int*) = " << sizeof(float*) << endl;
	
//空指针
	//指针变量指向内存中编号为0的空间
	//用途：初始化指针变量
	//注意：空指针指向的内存是不可以访问的
	int* pp = NULL;	//指针变量p指向内存地址编号为0的空间
	//cout << *p << endl;访问空指针报错，内存编号0 ~255为系统占用内存，不允许用户访问

//野指针
	//指针变量指向非法的内存空间，避免
	//空指针和野指针都不是我们申请的空间，因此不要访问
	int* ppp = (int*)0x1100;//指针变量p指向内存地址编号为0x1100的空间
	//cout << *p << endl;访问野指针报错

//const修饰指针
	//const修饰指针有三种情况
		//1. const修饰指针-- - 常量指针
		//2. const修饰常量-- - 指针常量
		//3. const即修饰指针，又修饰常量
	int a1 = 10;
	int b1 = 10;
	const int* p1 = &a1;//const修饰的是指针，指针指向可以改，指针指向的值不可以更改
	p1 = &b1; //正确
	//*p1 = 100;  报错
	int* const p2 = &a1;//const修饰的是常量，指针指向不可以改，指针指向的值可以更改
	//p2 = &b; //错误
	*p2 = 100; //正确
	const int* const p3 = &a1;//const既修饰指针又修饰常量，此时均不可改
	//p3 = &b; //错误
	//*p3 = 100; //错误

//指针和数组
	//利用指针访问数组中元素
	int i = 0;
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p4 = arr;//arr 就是数组首地址
	int m = sizeof(arr) / sizeof(arr[0]);//arr 元素个数
	for ( i = 0; i < m; i++)
	{
		cout << *(p4 + i) << endl;
	}

//指针和函数
	//利用指针作函数参数，可以修改实参的值
	int a2 = 111;
	int b2 = 222;
	cout << a2 << endl;
	cout << b2 << endl;
	swapp(&a2, &b2);
	cout << a2 << endl;
	cout << b2 << endl;

//指针配合数组和函数案例
	i = 0;
	int arr1[10] = { 4,3,6,9,1,2,10,8,7,5 };
	int len = sizeof(arr1) / sizeof(arr1[0]);
	bubblesort(arr1, len);//当数组名传入到函数作为参数时，被退化为指向首元素的指针
	printarr1(arr1, len);

	system("pause");
	return 0;
}
*/