#include<iostream>
#include<thread>
#include<mutex>
#include<list>
#include<memory>
using namespace std;

/*
//抽象基类
class Car 
{
public:
	virtual void show() = 0;
};
//三个实体汽车类
class Bmw : public Car
{
public:
	void show() { cout << "‘这是一辆宝马汽车，配置有："; }
};
class Audi : public Car
{
public:
	void show() { cout << "‘这是一辆奥迪汽车，配置有："; }
};
class Benz : public Car
{
public:
	void show() { cout << "‘这是一辆奔驰汽车，配置有："; }
};
//装饰器类
//装饰器 1 定速巡航
class ConcreteDecorator01 : public Car
{
public:
	ConcreteDecorator01(Car* p) : pCar(p) {}
	void show()
	{
		pCar->show();
		cout << "带定速巡航 ";
	}
private:
	Car* pCar;
};
class ConcreteDecorator02 : public Car
{
public:
	ConcreteDecorator02(Car* p) : pCar(p) {}
	void show()
	{
		pCar->show();
		cout << "带车道保持 ";
	}
private:
	Car* pCar;
};
class ConcreteDecorator03 : public Car
{
public:
	ConcreteDecorator03(Car* p) : pCar(p) {}
	void show()
	{
		pCar->show();
		cout << "带主动刹车 ";
	}
private:
	Car* pCar;
};

int main()
{
//装饰器模式（Decorator Pattern）
	//主要是增加现有类的功能，
	//添加子类也能实现现有类的功能增加，但通过子类实现功能增强问题：
		//为了增强现有类的功能，通过实现子类的方式，重写接口完成功能扩展
		//但代码中有太多的子类被添加进来了
	Car* p1 = new ConcreteDecorator01(new Bmw());
	p1->show();
	cout << endl;
	Car* p2 = new ConcreteDecorator01(new Audi());
	p2->show();
	cout << endl;
	//p3 链式调用
	Car* p3 = new ConcreteDecorator01(new Benz());
	//p3 -> ConcreteDecorator01 对象
	//ConcreteDecorator01 对象内部 pCar -> Benz 对象
	p3 = new ConcreteDecorator02(p3);
	//p3 -> ConcreteDecorator02 对象
	//ConcreteDecorator02 对象内部 pCar -> ConcreteDecorator01 对象
	p3 = new ConcreteDecorator03(p3);
	//p3 -> ConcreteDecorator03 对象
	//ConcreteDecorator03 对象内部 pCar -> ConcreteDecorator02 对象
	p3->show();
	cout << endl;

	system("pause");
	return 0;
}
*/