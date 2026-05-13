#include<iostream>
using namespace std;

/*
int main()
{
//顺序结构：程序按顺序执行，不发生跳转
//选择结构：依据条件是否满足，有选择的执行相应功能
//循环结构：依据条件是否满足，循环多次执行某段代码
//单行 if 
	int score = 0;
	cout << "请输入一个分数：" << endl;
	cin >> score;
	cout << "您输入的分数为： " << score << endl;
	if (score > 600)//注意事项，在if判断语句后面，不要加分号
	{
		cout << "我考上了XX大学！！！" << endl;
	}

//多行 if 
	int score1 = 0;
	cout << "请输入考试分数：" << endl;
	cin >> score1;
	if (score1 > 600)
	{
		cout << "我考上了XX大学" << endl;
	}
	else
	{
		cout << "我未考上XX大学" << endl;
	}

//多条件 if
	int score2 = 0;
	cout << "请输入考试分数：" << endl;
	cin >> score2;
	if (score2 > 600)
	{
		cout << "我考上了A大学" << endl;
	}
	else if (score2 > 500)
	{
		cout << "我考上了B大学" << endl;
	}
	else if (score2 > 400)
	{
		cout << "我考上了C大学" << endl;
	}
	else
	{
		cout << "我未考上大学" << endl;
	}

//嵌套 if
	int score3 = 0;
	cout << "请输入考试分数：" << endl;
	cin >> score3;
	if (score3 > 600)
	{
		if (score3 > 700)
		{
			cout << "我考上了A.A大学" << endl;
		}
		else if (score3 > 650)
		{
			cout << "我考上了A.B大学" << endl;
		}
		else
		{
			cout << "我考上了A.C大学" << endl;
		}
	}
	else if (score3 > 500)
	{
		cout << "我考上了B大学" << endl;
	}
	else if (score3 > 400)
	{
		cout << "我考上了C大学" << endl;
	}
	else
	{
		cout << "我未考上大学" << endl;
	}
//案例 if
	double pigA = 0;
	double pigB = 0;
	double pigC = 0;
	cout << "pigA 重量为：" << endl;
	cin >> pigA;
	cout << "pigB 重量为：" << endl;
	cin >> pigB;
	cout << "pigC 重量为：" << endl;
	cin >> pigC;
	if (pigA > pigB)
	{
		if (pigB > pigC)
		{
			cout << "pigA 最重" << endl;
		}
		else//pigB < pigC
		{
			if (pigA > pigC)
			{
				cout << "pigA 最重" << endl;
			}
			else
			{
				cout << "pigC 最重" << endl;
			}
		}
	}
	else//pigA < pigB
	{
		if (pigA > pigC)
		{
			cout << "pigB 最重" << endl;
		}
		else//pigA < pigC
		{
			if (pigB > pigC)
			{
				cout << "pigB 最重" << endl;
			}
			else
			{
				cout << "pigC 最重" << endl;
			}
		}
	}

//三目运算符
	//语法：表达式1 ? 表达式2 ：表达式3
		//如果表达式1的值为真，执行表达式2，并返回表达式2的结果
		//如果表达式1的值为假，执行表达式3，并返回表达式3的结果
	int x = 10;
	int y = 11;
	int z = 0;
	z = x > y ? x : y;
	cout << "z = " << z << endl;
	//C++中三目运算符返回的是变量,可以继续赋值
	(x > y ? x : y) = 100;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "z = " << z << endl;

//switch
	//作用：执行多条件分支语句
	//语法：switch(表达式){case 结果1：执行语句; break;case 结果2：执行语句; break;...default:执行语句; break;}
	//注意1：switch语句中表达式类型只能是整型或者字符型
	//注意2：case里如果没有break，那么程序会一直向下执行
	//总结：与if语句比，对于多条件判断时，switch的结构清晰，执行效率高，缺点是switch不可以判断区间
	int eva = 0;
	cout << "您的评分为：" << endl;
	cin >> eva;
	switch (eva)
	{
	case 10:
		cout << "经典" << endl;
		break;
	case 9:
		cout << "经典" << endl;
		break;
	case 8:
		cout << "非常好" << endl;
		break;
	case 7:
		cout << "非常好" << endl;
		break;
	case 6:
		cout << "一般" << endl;
		break;
	case 5:
		cout << "一般" << endl;
		break;
	default:
		cout << "烂片" << endl;
		break;
	}

	system("pause");
	return 0;
}
*/