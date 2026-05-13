#include<iostream>
using namespace std;
#include<ctime>

/*
int main()
{
//while
	//作用： 满足循环条件，执行循环语句
	//语法：while (循环条件) { 循环语句 }
	//解释：只要循环条件的结果为真，就执行循环语句
	//注意：在执行循环语句时候，程序必须提供跳出循环的出口，否则出现死循环
	int num = 1;
	while (num <= 10)
	{
		cout << "num = " << num << endl;
		num++;
	}

//猜数字练习
	//rand() % 100 随机生成 0 ~ 99 伪随机数
	//添加随机数种子 作用利用当前系统时间生成随机数，防止每次随机数都一样
	srand((unsigned int)time(NULL));//需包含头文件 #include<ctime>
	int number_generation = rand() % 100 + 1;//随机生成 1 ~ 100
	int number_guess = 0;
	while (1)
	{
		cout << "请输入猜测的数字：" << endl;
		cin >> number_guess;
		if (number_guess == number_generation)
		{
			cout << "您猜对了，数字就是：" << number_guess << endl;
			break;
		}
		else if (number_guess > number_generation)
		{
			cout << "数字猜大了" << endl;
		}
		else
		{
			cout << "数字猜小了" << endl;
		}
	}

//dowhile
	//作用：满足循环条件，执行循环语句
	//语法：do{ 循环语句} while (循环条件);
	//注意：与while的区别在于 do...while 会先执行一次循环语句，再判断循环条件
	int number = 0;
	do
	{
		cout << "number：" << number << endl;
		number++;
	} while (number <= 9);

//水仙花数练习
	int i = 100;
	int i_save = 0;
	int save_units = 0;
	int save_tens = 0;
	int save_hundreds = 0;
	do
	{
		i_save = i;
		save_units = i % 10;
		i /= 10;
		save_tens = i % 10;
		i /= 10;
		save_hundreds = i % 10;
		i = i_save;
		if (i == (save_units * save_units * save_units) + (save_tens * save_tens * save_tens) + (save_hundreds * save_hundreds * save_hundreds))
		{
			cout << i << endl;
		}
		i++;
	} while (i < 1000);

//for
	//作用：满足循环条件，执行循环语句
	//语法：for (起始表达式; 条件表达式; 末尾循环体) { 循环语句; }
	int j = 0;
	for ( j = 0; j < 10; j++)
	{
		cout << j << endl;
	}

//敲桌子练习
	save_units = 0;
	save_tens = 0;
	for (j = 1; j <= 100; j++)
	{
		save_units = j % 10;
		save_tens = j / 10;
		if ((j % 7 == 0) || (save_units == 7) || (save_tens == 7))
		{
			cout << "敲桌子" << endl;
		}
		else
		{
			cout << j << endl;
		}
	}

//嵌套循环
	for ( i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}

//乘法口诀表练习
	for ( i = 1; i < 10; i++)
	{
		for ( j = 1; j <= i; j++)
		{
			cout << j << " * " << i << " = " << i * j << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}
*/
