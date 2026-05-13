#include<iostream>
using namespace std;
//2026.2.10

/*
int sum(int a, int b)
{   // "{" 左括号也会生成一条指令 push ebp 将 main 函数的栈帧栈底地址入栈
		//4.main 函数的栈帧：
		//            esp   0x0018ff40
		//                  0x08124458
		//                  10 -> int a（形参）
		//                  20 -> int b（形参）
		// 
		//               
		//                  ret
		//                  b   20
		//0x0018ff40  ebp   a   10
	//给 sum 函数开辟栈帧空间
	//mov ebp, esp 
	//sub esp 4Ch
		//5.sum 函数的栈帧：
		//            esp   0xCCCCCCCC（初始化）
		//                  0xCCCCCCCC（初始化）
		//                  0xCCCCCCCC（初始化）
		//                  0xCCCCCCCC（初始化）
		//            ebp   0xCCCCCCCC（初始化）
		//main 函数的栈帧：
		//                  0x0018ff40
		//                  0x08124458
		//                  10 -> int a（形参）
		//                  20 -> int b（形参）
		// 
		// 
		//                  ret
		//                  b   20
		//0x0018ff40        a   10
	int temp = 0;//mov dword ptrp[ebp - 4], 0
		//6.sum 函数的栈帧：
		//            esp   0xCCCCCCCC（初始化）
		//                  0xCCCCCCCC（初始化）
		//                  0xCCCCCCCC（初始化）
		//                  0xCCCCCCCC（初始化）
		//            ebp   temp   0
		//main 函数的栈帧：
		//                  0x0018ff40
		//                  0x08124458
		//                  10 -> int a（形参）
		//                  20 -> int b（形参）
		// 
		// 
		//                  ret
		//                  b   20
		//0x0018ff40        a   10
	temp = a + b;
	//mov eax, dword ptr[ebp + 0Ch]
	//add eax, dword ptr[ebp + 8] 将 a 与 b 相加
	//mov dword ptr[ebp - 4], eax 将结果放到 temp 中
	return temp;//mov eax , dword ptr[ebp - 4] 将结果放到寄存器中带出
}   // "}" 右括号也会生成指令
    //mov esp, ebp 回退栈空间，这也就是不要返回局部变量的原因
		//7.sum 函数的栈帧：
		//                  0xCCCCCCCC（初始化）
		//                  0xCCCCCCCC（初始化）
		//                  0xCCCCCCCC（初始化）
		//                  0xCCCCCCCC（初始化）
		//                  temp   30
		//main 函数的栈帧：
		//       esp  ebp   0x0018ff40
		//                  0x08124458
		//                  10 -> int a（形参）
		//                  20 -> int b（形参）
		// 
		// 
		//                  ret
		//                  b   20
		//0x0018ff40        a   10
    //pop ebp 出栈并把出栈元素的值赋给 ebp
		//8.sum 函数的栈帧：
		//                  0xCCCCCCCC（初始化）
		//                  0xCCCCCCCC（初始化）
		//                  0xCCCCCCCC（初始化）
		//                  0xCCCCCCCC（初始化）
		//                  temp   30
		//main 函数的栈帧：
		//           esp    0x08124458
		//                  10 -> int a（形参）
		//                  20 -> int b（形参）
		// 
		// 
		//                  ret
		//                  b   20
		//0x0018ff40 ebp    a   10
    //ret 出栈，把出栈的内容放入 CPU 的 PC 寄存器里面，CPU 的 PC 寄存器就是放的下一行要执行的指令的地址，即开始执行 call sum 下一行指令
		//9.sum 函数的栈帧：
		//                  0xCCCCCCCC（初始化）
		//                  0xCCCCCCCC（初始化）
		//                  0xCCCCCCCC（初始化）
		//                  0xCCCCCCCC（初始化）
		//                  temp   30
		//main 函数的栈帧：   
		//           esp    10 -> int a（形参）
		//                  20 -> int b（形参）
		// 
		// 
		//                  ret
		//                  b   20
		//0x0018ff40 ebp    a   10

int main()
{
//问题一：main 函数调用 sum，sum执行完后，怎么知道回到那个函数中？
//问题二：sum 函数执行完，回到 main 以后，怎么知道从哪一行指令继续运行？

	//函数运行时要在栈帧上开辟空间
		//1.main 函数的栈帧：
		//            esp
		// 
		// 
		// 
		//0x0018ff40  ebp
	int a = 10;//mov dword ptrp[ebp - 4], 0Ah，有些编译器会方便阅读会显示 mov dword ptrp[a], 0Ah
	int b = 20;//mov dword ptrp[ebp - 8], 14h
		//2.main 函数的栈帧：
		//            esp
		// 
		// 
		//                  b   20
		//0x0018ff40  ebp   a   10
	//函数运行会从右向左先压参数
	int ret = sum(a, b);
	//mov eax, dword ptr[ebp - 8] 从 b 内存拿值放到寄存器
	//push eax 压栈
	//mov eax, dword ptr[ebp - 4] 从 a 内存拿值放到寄存器
	//push eax 压栈
	//call sum 将下一行的地址压栈，进入 sum 函数
		//3.main 函数的栈帧：
		//            esp   0x08124458
		//                  10 -> int a（形参）
		//                  20 -> int b（形参）
		// 
		// 
		//                  ret
		//                  b   20
		//0x0018ff40  ebp   a   10
	//all esp, 8(0x08124458) 把形参变量的内存交还给系统
		//10.sum 函数的栈帧：
		//                  0xCCCCCCCC（初始化）
		//                  0xCCCCCCCC（初始化）
		//                  0xCCCCCCCC（初始化）
		//                  0xCCCCCCCC（初始化）
		//                  temp   30
		//main 函数的栈帧：   
		//            esp
		// 
		//
		//                  ret 
		//                  b   20
		//0x0018ff40 ebp    a   10 
	//mov dword ptr[ebp - 0Ch], eax 将计算好的值放入 ret 里面
		//11.sum 函数的栈帧：
		//                  0xCCCCCCCC（初始化）
		//                  0xCCCCCCCC（初始化）
		//                  0xCCCCCCCC（初始化）
		//                  0xCCCCCCCC（初始化）
		//                  temp   30
		//main 函数的栈帧：   
		//            esp
		// 
		//
		//                  ret 30
		//                  b   20
		//0x0018ff40 ebp    a   10 
	cout << sum << endl;

	system("pause");
	return 0;
}
*/