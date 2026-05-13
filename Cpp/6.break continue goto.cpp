#include<iostream>
using namespace std;

/*
int main()
{
//break 2025.10.14
	//作用:用于跳出选择结构或者循环结构
	//break使用的时机：
		//出现在switch条件语句中，作用是终止case并跳出switch
		//出现在循环语句中，作用是跳出当前的循环语句
		//出现在嵌套循环中，跳出最近的内层循环语句
	//在 switch 语句中使用 break
	cout << "请选择您挑战副本的难度：" << endl;
	cout << "1、普通" << endl;
	cout << "2、中等" << endl;
	cout << "3、困难" << endl;
	int num = 0;
	cin >> num;
	switch (num)
	{
	case 1:
		cout << "您选择的是普通难度" << endl;
		break;
	case 2:
		cout << "您选择的是中等难度" << endl;
		break;
	case 3:
		cout << "您选择的是困难难度" << endl;
		break;
	default:
		break;
	}
	//在 for 循环语句中用 break
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		if (i == 5)
		{
			break; //跳出循环语句
		}
		cout << i << endl;
	}
	//在嵌套循环语句中使用 break，退出内层循环
	int j = 0;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (j == 5)
			{
				break;//退出内层循环
			}
			cout << "*" << " ";
		}
		cout << endl;
	}

//continue
	//作用：在循环语句中，跳过本次循环中余下尚未执行的语句，继续执行下一次循环
	//注意：continue并没有使整个循环终止，而break会跳出循环
	for (i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
		{
			continue;
		}
		cout << i << endl;
	}

//goto
	//作用：可以无条件跳转语句
	//语法：goto 标记;
	//解释：如果标记的名称存在，执行到goto语句时，会跳转到标记的位置
	//注意：在程序中不建议使用goto语句，以免造成程序流程混乱
	cout << "1" << endl;
	goto FLAG;
	cout << "2" << endl;
	cout << "3" << endl;
	cout << "4" << endl;
	FLAG:
	cout << "5" << endl;

	system("pause");
	return 0;
}
*/