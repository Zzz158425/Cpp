#include<iostream>
using namespace std;
#include<string>

/*
int main()
{
//整型
	//short(短整型)       2 字节                                                 (-2^15 ~ 2^15-1)
	//int(整型)           4 字节                                                 (-2 ^ 31 ~2 ^ 31 - 1)
	//long(长整形)        Windows为 4 字节，Linux为 4 字节( 32 位)，8 字节( 64 位) (-2 ^ 31 ~2 ^ 31 - 1)
	//long long(长长整形) 8 字节                                                 (-2 ^ 63 ~2 ^ 63 - 1)
	short a1 = 10;
	int a2 = 10;
	long a3 = 10;
	long long a4 = 10;
	cout << a1 << endl;
	cout << a2 << endl;
	cout << a3 << endl;
	cout << a4 << endl;

//sizeof关键字
	//作用：利用 sizeof 关键字可以统计数据类型所占内存大小
	cout << "short 类型所占内存空间为：" << sizeof(a1) << endl;
	cout << "int 类型所占内存空间为：" << sizeof(a2) << endl;
	cout << "long 类型所占内存空间为：" << sizeof(a3) << endl;
	cout << "long long 类型所占内存空间为：" << sizeof(a4) << endl;

//实型-浮点型
	//float（单精度）  4 字节 7 位有效数字
	//double（双精度） 8 字节 15～16 位有效数字
	//默认情况下，输出一个小数，会显示出 6 位有效数字
	float f = 3.14f;//不带 f 会默认为 double
	double d = 3.14;
	cout << f << endl;
	cout << d << endl;
	cout << "float 类型所占内存空间为：" << sizeof(f) << endl;
	cout << "double 类型所占内存空间为：" << sizeof(d) << endl;
	//科学技术法
	float f1 = 3e2f; //3 * 10 ^ 2 
	cout << "f1 = " << f1 << endl;
	float f2 = 3e-2f;  //3 * 0.1 ^ 2
	cout << "f2 = " << f2 << endl;

//字符型
	//注意 1：在显示字符型变量时，用单引号将字符括起来，不要用双引号
	//注意 2：单引号内只能有一个字符，不可以是字符串
	//C 和 C++ 中字符型变量只占用 1 个字节
	//字符型变量并不是把字符本身放到内存中存储，而是将对应的 ASCII 编码放入到存储单元
	//a - 97 A - 65 大小写英文字母 ASCII 码相差 32
	char ch = 'a';
	cout << ch << endl;
	cout << "char 类型所占内存空间："<< sizeof(char) << endl;
	cout << (int)ch << endl;  //查看字符 a 对应的ASCII码
	char ch1 = 97; //可以直接用 ASCII 给字符型变量赋值
	cout << ch1 << endl;

//转义字符
	//作用：用于表示一些不能显示出来的 ASCII 字符
	cout << "hello world\n";
	cout << "aaa\tbbb" << endl;
	cout << "\\" << endl;

//字符串类型
	char str1[] = "hello world";//C 风格，要用双引号括起来
	cout << str1 << endl;
	string str2 = "hello C++";//C++ 风格字符串，需要加入头文件 #include<string>
	cout << str2 << endl;

//布尔类型
	//作用：布尔数据类型代表真或假的值 
	//bool类型只有两个值：占 1 个字节大小
		//true   真（本质是1），非 0 值
		//false  假（本质是0）
	bool flag = true;
	cout << flag << endl; // 1
	flag = false;
	cout << flag << endl; // 0
	cout << "bool 类型所占内存空间：" << sizeof(flag) << endl; //1

//数据的输入
	//cin >> 变量
	//整型输入
	int aa = 0;
	cout << "请输入整型变量：" << endl;
	cin >> aa;
	cout << "整型变量 aa = " << aa << endl;
	//浮点型输入
	double dd = 0;
	cout << "请输入浮点型变量：" << endl;
	cin >> dd;
	cout << "浮点型变量 bb = " << dd << endl;
	//字符型输入
	char chh = 0;
	cout << "请输入字符型变量：" << endl;
	cin >> chh;
	cout << "字符型变量 chh = " << chh << endl;
	//字符串型输入
	string strr;
	cout << "请输入字符串型变量：" << endl;
	cin >> strr;
	cout << "字符串型变量 strr = " << strr << endl;
	//布尔类型输入
	bool flagg = true;
	cout << "请输入布尔型变量：" << endl;
	cin >> flagg;
	cout << "布尔型变量 flagg = " << flagg << endl;

	system("pause");
	return 0;
}
*/