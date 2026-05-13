#include<iostream>
using namespace std;
//2026.2.23

/*
int sum(int a = 10, int b = 20)
{
	return a + b;
}
//int sum(int a = 20, int b = 20);声明处也可以给形参默认值，但是不管是定义出给，还是声明处给，形参默认值只能出现一次
//int sum(int a = 10, int b) 不能这样设置形参的默认值，给默认值从右向左给
//{
//	return a + b;
//}

int main()
{
	int a = 10;
	int b = 20;
	int ret = sum(a, b);
	//mov eax, dword ptr[ebp - 8] 从 b 内存拿值放到寄存器
	//push eax
	//mov eax, dword ptr[ebp - 4] 从 a 内存拿值放到寄存器
	//push eax
	//call sum
	cout << "ret:" << ret << endl;
	ret = sum(a);//同样会压栈
	//push 14H 直接取值，不需要从内存中取数，效率更高
	//mov eax, dword ptr[ebp - 4]
	//push eax
	//call sum
	cout << "ret:" << ret << endl;
	ret = sum();
	//push 14H
	//push 0AH
	//call sum
	cout << "ret:" << ret << endl;
	ret = sum(a, 40);
	//push 28H
	//mov eax, dword ptr[ebp - 4]
	//push eax
	//call sum

	system("pause");
	return 0;
}
*/