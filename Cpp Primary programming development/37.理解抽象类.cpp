#include<iostream>
#include<typeinfo>
#include<string>
#include<vector>
using namespace std;

/*
//理解抽象类
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
//汽车基类
class Car
{
public:
	Car(string name, double oil) :_name(name), _oil(oil) {}
	//获取汽车剩余流量还能跑的公里数
	double getLeftMiles() { return _oil * this->getMilePerGallon(); }//this->getMilePerGallon() 动态绑定
	string getName() const { return _name; }
protected:
	string _name;
	double _oil;
	virtual double getMilePerGallon() = 0;//纯虚函数，此时 Car 为抽象类
};
class Bnze : public Car
{
public:
	Bnze(string name, double oil) :Car(name, oil) {}
	double getMilePerGallon() { return 20.0; }
};
class Audi : public Car
{
public:
	Audi(string name, double oil) :Car(name, oil) {}
	double getMilePerGallon() { return 18.0; }
};
class BMW : public Car
{
public:
	BMW(string name, double oil) :Car(name, oil) {}
	double getMilePerGallon() { return 19.0; }
};
//外部统一获取汽车剩余路程数 API 接口
void showCarLeftMiles(Car* car)
{
	cout << car->getName() << " left miles:" << car->getLeftMiles() << endl;//car->getLeftMiles() 为静态绑定
}

int main()
{
//理解抽象类
	//以动物基类-动物实体类为例，定义 Animal 的初衷，并不是让 Animal 抽象某个实体的类型
		//1.string_name，让所有的动物实体类通过继承 Animal 直接复用该属性
		//2.给所有的派生类保留统一的覆盖/重写接口
	//拥有纯虚函数的类，叫抽象类，抽象类不能再实例化对象，但是可以定义指针和引用变量
	//抽象类与普通类区别：
		//1.抽象类不是用来抽象某一个实体类型
		//2.不能实例化对象，可以定义指针和引用变量
	Bnze b1("奔驰", 20.0);
	Audi a("奥迪", 20.0);
	BMW b2("宝马", 20.0);
	showCarLeftMiles(&b1);
	showCarLeftMiles(&a);
	showCarLeftMiles(&b2);

	system("pause");
	return 0;
}
*/
