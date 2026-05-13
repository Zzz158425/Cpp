#include<iostream>
#include<typeinfo>
#include<string>
#include<vector>
using namespace std;
//2026.3.4

/*
//理解多态本质
//动物基类
class Animal
{
public:
	Animal(string name) :_name(name) { }
	virtual void bark() { }
protected:
	string _name;
};
//动物实体类
class Cat : public Animal
{
public:
	Cat(string name) :Animal(name) { }
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
void bark(Animal* p)//bark 的 API 接口
{
	p->bark();//Animal::bark 虚函数，动态绑定
}

int main()
{
//理解多态本质
	//多态分为静态（编译时期）多态和动态（运行时期）多态
		//静态多态：函数重载、模板（函数模版和类模板）
		//动态多态：在继承结构中，基类指针（引用）指向派生类对象，通关该指针（引用）调用同名覆盖方法（虚函数），基类指针指向那个派生类对象，就会调用那个派生类对象的覆盖方法，称为多态
	//多态底层是通过调用动态绑定来实现的，基类指针指向谁 -> 访问谁的 vfptr -> 继续访问谁的 vftable -> 调用对应的派生类对象方法
	Cat cat("猫咪");
	Dog dog("二哈");
	Pig pig("佩奇");
	bark(&cat);//p -> cat Cat vftable &Cat::bark
	bark(&dog);//p -> Dog Dog vftable &Dog::bark
	bark(&pig);//p -> Pig Pig vftable &Pig::bark

	system("pause");
	return 0;
}
*/