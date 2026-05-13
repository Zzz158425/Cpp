#include<iostream>
using namespace std;
//2026.2.9

/*
//全局变量
//全局变量均视为数据，存放在 .data 或 .bss																
int gdata1 = 10;//存放在 .data
int gdata1 = 0;//存放在 .bss
int gdata1;//存放在 .bss
//全局静态变量
static int gdata4 = 11;//存放在 .data
static int gdata4 = 0;//存放在 .bss
static int gdata4;//存放在 .bss

int main()
{
	//任何的编程语言都会生成指令与数据
	//在编译链接完成以后会生成 .exe 文件（以 window为例）放在磁盘上，运行该文件会把程序从磁盘上加载到内存当中（不可能加载到物理内存当中）
	//在 x86，32 位 linux 环境下会给当前进程分配一个 2^32(4G) 大小的空间，这个空间叫做进程的虚拟地址空间，此空间不是物理内存上的一块空间
	//进程的虚拟地址空间：每一个用户空间是私有的，但是内核空间是共享的
	//用户空间(3G):
	//user space   --------不可访问-------- 0x00000000
	//             .text .rodata段（不可写） 0x08048000 指令放在 .text 段，常量字符串存在 .rodata 段
	//             .data                               存放初始化不为 0 的数
	//             .bss                                存放未初始化或初始化为 0 的数
	//             .heap                               堆，调用了 new malloc 才会使用此部分空间，从低地址到高地址
	//             共享/动态链接库 *.dll/*so            程序在运行中会加载共享/动态链接库
	//             stack                               栈，从高地址到低地址
	//             命令行参数、环境变量
	//内核空间(1G): 
	//kernal space ZONE_DMA                0xC0000000  16M
	//             ZONE_NORMAL                         800M，内核空间 PCB 块，进程控制块，内核空间的线程，内核函数运行时所依赖的栈空间
	//             ZONE_HIGHMEM                        高端内存，地址映射

	//局部变量
	//局部变量生成指令，int a = 12 生成 mov dword ptr[a],0Ch，指令放在 .text 段，指令运行时会在栈上划分出来自己的一块空间来存放
	int a = 12;//存放在 .text
	int b = 0;//存放在 .text
	int c;//存放在 .text
	//局部静态变量
	//局部静态变量放在数据段，第一次运行时才初始化
	static int e = 13;//存放在 .data
	static int f = 0;//存放在 .bss
	static int g;//存放在 .bss
	cout << c << endl;//不为 0 ，无效值
	cout << g << endl;//为 0，内核起来之后会把 .bss 段置零

	system("pause");
	return 0;
}
*/