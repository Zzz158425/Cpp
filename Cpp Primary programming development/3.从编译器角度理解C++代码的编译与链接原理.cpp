#include<iostream>
using namespace std;

/*
int main()
{
//在 Linux 系统下，64 位 Ubuntu 系统利用 Xshell 进行远程链接
	//sum.cpp:
		//int gdata = 10;
		//int sum(int a, int b)
		//{
		//      return a + b;
		//}
	//main.cpp:
		//extern int gdata;
		//int sum(int, int);
		//int data = 20;
		//int main()
		//{
		//	int a = gdata;
		//	int b = data;
		//	int ret = sum(a, b);
		//	return 0;
		//}
//编译与链接原理
	//1.编译过程        预编译                                         编译                                    汇编
		//main.cpp     #开头的命令                                    语法分析、语义分析、词法分析、代码优化     生成二进制可重定位的目标文件（*.obj），main.o, sum.o
		//             （#pragma lib 链接库，不在预编译处理）                                                   
		//sum.cpp      （#pragma link 修改入口函数，不在预编译处理）    
	//*.o 文件的格式组成：elf 文件头、.text、.data、.bss、.symbal、.section table ………… 各种各样的段组成
	//编译过程中，符号不分配虚拟地址，这也是 *.obj 无法运行的原因之一
	//2.链接：编译完成的所有 .o 文件和静态库文件参与：sum.o、main.o、*.lib(window)、*.a(linux) 
		//步骤一：所有 .o 文件段的合并，符号表合并后，进行符号解析，符号解析也就是所有对符号的引用，都要找到该符号定义的地方，此时若找不到或找到多个符号的定义就会报错：无/重定义
		//步骤二：符号的重定位（重定向，链接核心）：在符号解析成功以后，给所有的符号分配虚拟地址
	    //完成步骤一、二即可得到 .exe(window) a.out(linux) 文件
	//符号表：
		//main.o: 文件格式 elf64-x86-64
		//SYMBOL TABLE:
		//0000000000000000  1  df  *ABS*  00000000000000000  main.cpp   l：logal 只在当前文件可看
		//0000000000000000  1  d   .text  0000000000000000   .text
		//0000000000000000  1  d   .data  0000000000000000   .data
		//0000000000000000  1  d   .bss   0000000000000000   .bss
		//0000000000000000  1  d   .note.GNU-stack   0000000000000000  .note.GNU-stack
		//0000000000000000  l  d   .eh_frame   0000000000000000   o.eh_frame
		//0000000000000000  1  d   .comment   0000000000000000   .comment
		//0000000000000000  g  O   .data   0000000000000004   data   data：全局变量 data 会放在 .data 段，g：global 在其他文件中也可看
		//0000000000000000	g  F   .text   0000000000000033   main   main：函数 main 的指令会放在 .text 段
		//0000000000000000         *UND*   0000000000000000   gdata   UND：undefined 未定义符号引用
		//0000000000000000         *UND*   0000000000000000   _GLOBAL_OFFSET_TABLE
		//0000000000000000         *UND*   0000000000000000   _z3sumii
		//sum.o: 文件格式 elf64-x86-64
		//SYMBOL TABLE:
		//0000000000000000  1  df  *ABS*  00000000000000000  sum.cpp
		//0000000000000000  1  d   .text  0000000000000000   .text
		//0000000000000000  1  d   .data  0000000000000000   .data
		//0000000000000000  1  d   .bss   0000000000000000   .bss
		//0000000000000000  1  d   .note.GNU-stack   0000000000000000  .note.GNU-stack
		//0000000000000000  l  d   .eh_frame   0000000000000000   o.eh_frame
		//0000000000000000  1  d   .comment   0000000000000000   .comment
		//0000000000000000  g  O   .data   0000000000000004   gdata   
		//0000000000000000	g  F   .text   0000000000000014   _z3sumii   _z3sumii：函数 sum 的指令会放在 .text 段
		//a.out: 文件格式 elf64-x86-64
		//SYMBOL TABLE:
		//00000000004000e8 l  d.text   0000000000000000   .text
		//0000000000400130 l  d.eh_frame   0000000000000000   .eh_frame
		//0000000000601000 l  d.data   0000000000000000   .data
		//0000000000000000 l  d.comment   0000000000000000   .comment
		//0000000000000000 l  d.debug_aranges   0000000000000000   .debug_aranges
		//0000000000000000 l  d.debug_info   0000000000000000   .debug_info
		//0000000000000000 l  d.debug_abbrev   0000000000000000   .debug_abbrev
		//0000000000000000 l  d.debug_line    0000000000000000   .debug_line
		//0000000000000000 l  d.debug_str   0000000000000000   .debug_str
		//0000000000000000 df *ABS*   0000000000000000   main.cpp
		//0000000000000000 df *ABS*   0000000000000000   sum.cpp
		//000000000040011b g  F.text   0000000000000014   _Z3sumii
		//0000000000601008 g  .data   0000000000000000   __bss_start
		//0000000000601000 g  O.data   0000000000000004   data
		//00000000004000e8 g  F.text   0000000000000033   main
		//0000000000601004 g  O.data   0000000000000004   gdata
		//0000000000601008 g  .data   0000000000000000   _edata
		//0000000000601008 g  .data   0000000000000000   _end
	//*.exe 文件的格式组成：*.o 文件的格式相比，多出了 program headers，其中有两个 load ，告诉系统运行这个程序时，把那些内容加载到内存当中

	system("pause");
	return 0;
}
*/