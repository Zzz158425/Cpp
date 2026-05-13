#include<iostream>
#include<typeinfo>
using namespace std;

/*
//指向类成员（成员变量和成员方法）的指针
class Test
{
public:
	void func() { cout << "call Test::func" << endl; }
	static void static_func() { cout << "Test::static_func" << endl; }
	int ma;
	static int mb;
};
int Test::mb;

int main()
{
//指向类成员（成员变量和成员方法）的指针
	//指向成员变量指针
	//int* p = &Test::ma;无法使普通指针指向成员变量，无法从 int Test::* 转换为 int*
	//*p = 20;无法解引用，普通成员变量依赖对象
	Test t1;
	Test* t2 = new Test();
	int Test::*p = &Test::ma;//需加作用域
	t1.*p = 20;//普通成员变量依赖对象
	cout << t1.*p << endl;
	t2->*p = 30;
	cout << t2->*p << endl;
	int* p1 = &Test::mb;//普通指针指向即可
	*p1 = 40;//静态成员成员不依赖对象
	cout << *p1 << endl;
	delete t2;

	//指向成员方法指针
	//void(*pfunc)() = &Test::func;无法使普通函数指针指向成员方法，无法从 void(__thiscall Test::*)(void) 转换为 void(__cdecl*)(void)
	//(*pfunc)();//普通成员方法依赖对象
	void(Test:: *pfunc)() = &Test::func;
	(t1.*pfunc)();
	(t2->*pfunc)();
	void(*pfunc1)() = &Test::static_func;//普通函数指针指向即可
	(*pfunc1)();//静态成员方法不依赖对象

	system("pause");
	return 0;
}
*/