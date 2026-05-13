#include<iostream>
#include<typeinfo>
#include<string>
#include<vector>
using namespace std;

/*
//继承多态笔试题实战分析
//1.分析所示代码
//动物基类
class Animal
{
public:
	Animal(string name) :_name(name) {}
	virtual void bark() = 0;//纯虚函数，此时 Animal 为抽象类
protected:
	string _name;
};
//动物实体类
class Cat : public Animal
{
public:
	Cat(string name) :Animal(name) {}
	void bark() { cout << _name << "bark:miao miao!" << endl; }
};
class Dog : public Animal
{
public:
	Dog(string name) :Animal(name) {}
	void bark() { cout << _name << "bark:wang wang!" << endl; }
};
class Pig : public Animal
{
public:
	Pig(string name) :Animal(name) {}
	void bark() { cout << _name << "bark:heng heng!" << endl; }
};
//bark 的 API 接口
void bark(Animal* p)
{
	p->bark();//Animal::bark 虚函数，动态绑定
}
//2.分析所示代码
class Base
{
public:
	virtual void show(int i = 10) { cout << "call Base::show i:" << i << endl; }
};
class Derive : public Base
{
public:
	void show(int i = 20) { cout << "call Derive::show i:" << i << endl; }
};
//3.分析所示代码
class Base1
{
public:
	virtual void show() { cout << "call Base1::show" << endl; }
};
class Derive1 : public Base1
{
private:
	void show() { cout << "call Derive1::show" << endl; }
};
class Base2
{
private:
	virtual void show() { cout << "call Base2::show" << endl; }
};
class Derive2 : public Base2
{
public:
	void show() { cout << "call Derive2::show" << endl; }
};
//4.分析所示代码
class Base3
{
public:
	Base3() 
	{ 
		cout << "call Base()" << endl; 
		clear();
	}
	void clear() { memset(this, 0, sizeof(*this)); }//从 this 指针上的内存地址开始到 sizeof(*this) 全部置 0
	virtual void show() { cout << "call Base3::show i:" << endl; }
};
class Derive3 : public Base3
{
public:
	Derive3() { cout << "call Derive3()" << endl; }
	void show() { cout << "call Derive3::show i:" << endl; }
};

int main()
{
//继承多态笔试题实战分析
	//1.分析所示代码
	Animal* p1 = new Cat("加菲猫");
	Animal* p2 = new Dog("二哈");
	int* p11 = (int*)p1;
	int* p22 = (int*)p2;
	int temp = p11[0];//p11[0] 访问的就是 Cat 的前 4 个字节
	p11[0] = p22[0];//p22[0] 访问的就是 Dog 的前 4 个字节
	p22[0] = temp;
	p1->bark();//vfptr -> Dog vftable；p1 -> Cat vfptr -> Dog vftable bark
	p2->bark();//vfptr -> Cat vftable；p1 -> Dog vfptr -> Cat vftable bark
	delete p1;
	delete p2;
	//2.分析所示代码
		//在编译阶段，p 仅是一个 Base 类型的指针，只能找到 Base 类型里面的形参默认值
		//push OAh 形参默认值入栈，函数调用，参数压栈是在编译时期就确定好的
		//mov eax, dword ptr[p] 指针指向的前 4 个字节，也就是 vfptr 的值放在寄存器里
		//mov ecx, dword ptr[eax] 再从虚函数表里取 4 个字节，也就是虚函数地址
		//call ecx 
	Base* p = new Derive;
	p->show();//动态绑定，p -> Derive vfptr -> Derive vftable，调用了派生类的 show 方法，但是函数形参默为基类的参数默认值
	delete p;
	//3.分析所示代码
		//成员方法是否能调用，就是说方法的调用权限是不是 public 的，是在编译阶段就需要确定，即调用权限 public、protected、private 只在编译时期起作用
	Base1* q = new Derive1;
	q->show();//虽然 Derive1 类的 show 是 private，但是最终能调用到 Derive1::show，是在运行时期才确定的
	delete q;
	Base2* q1 = new Derive2;
	//q1->show();//同理，虽然 Derive1 类的 show 是 public，但是编译阶段只能去查看 Base::show ，Base::show 为 private，无法调用，编译无法通过，继而无法运行
	//delete q1;
	//4.分析所示代码
		//每一个函数左括号进行到第一行代码之间存在指令生成，以 Base3 为例
		//Base3() 
		//{
			//push ebp 将调用方函数的地址压栈
			//mov ebp, esp 将 ebp 指向当前函数的栈底
			//sub esp,4Ch 为当前函数开辟栈帧
			//rep stos esp <-> ebp 0xCCCCCCCC 初始化
			//vfptr <- &Base::vftable 将 base 的虚函数 vftable 写入了 vfptr
		//cout << "call Base()" << endl;
		//clear();
		//}
	//Base3* pb1 = new Base3();//调用错误，因为构造函数调用了 clear，使得虚函数指针为零地址，无法访问虚函数表
		//mov eax, dword ptr[p] 指针指向的前 4 个字节，也就是 vfptr 的值放在寄存器里
		//mov ecx, dword ptr[eax] 再从虚函数表里取 4 个字节，也就是虚函数地址，eax:0x00000000，非法访问，程序挂掉
		//call ecx 
	//pb1->show();//动态绑定
	//delete pb1;
	Base3* pb2 = new Derive3();//调用正确，因为创建派生类时会先调用基类析构函数，再调用派生类构造函数，基类构造时会把 vfptr 置零，但是调用派生类构造函数后，把 Derive3 的 vftable 写入 vfptr 里，这样当我们用指针去调用 show 时，指针访问派生类对象，此时 vfptr 有效
	pb2->show();//动态绑定
	delete pb2;

	system("pause");
	return 0;
}
*/
