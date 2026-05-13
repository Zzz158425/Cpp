#include<iostream>
#include<thread>
#include<mutex>
#include<list>
#include<memory>
using namespace std;

/*
class Car
{
public:
	Car(string name) : _name(name) { }
	virtual void show() = 0;
protected:
	string _name;
};
class Bmw : public Car
{
public:
	Bmw(string name) : Car(name) { }
	void show()
	{
		cout << "获取了一辆叫 " << _name << " 的 BMW 汽车！" << endl;
	}
};
class Audi : public Car
{
public:
	Audi(string name) : Car(name) {}
	void show()
	{
		cout << "获取了一辆叫 " << _name << " 的 Audi 汽车！" << endl;
	}
};
//简单工厂
enum CarType
{
	BMW,AUDI
};
class SimpleFactory
{
public:
	Car* createCar(CarType ct)
	{
		switch (ct)
		{
		case BMW:
			return new Bmw("X1");
		case AUDI:
			return new Audi("A6");
		default:
			cerr << "传入工厂的参数不正确" << ct << endl;
			break;
		}
		return nullptr;
	}
};
//工厂方法
class Factory
{
public:
	virtual Car* createCar(string name) = 0;
};
//宝马工厂
class BMWFactory : public Factory
{
public:
	Car* createCar(string name)
	{
		return new Bmw(name);
	}
};
//奥迪工厂
class AudiFactory : public Factory
{
public:
	Car* createCar(string name)
	{
		return new Audi(name);
	}
};

int main()
{
//工厂模式
	//主要封装了对象的创建
	//简单工厂：Simple Factory
	//工厂方法：Factory Method
	//多态
	Car* p1 = new Bmw("X1");
	Car* p2 = new Audi("A6");
	p1->show();
	p2->show();
	delete p1;
	delete p2;
	//简单工厂
		//不满足开闭原则
	SimpleFactory* factory = new SimpleFactory();
	Car* p3 = factory->createCar(BMW);
	Car* p4 = factory->createCar(AUDI);
	p3->show();
	p4->show();
	delete p3;
	delete p4;
	//智能指针 + 简单工厂
	unique_ptr<SimpleFactory> factory1(new SimpleFactory());
	unique_ptr<Car> p5(factory1->createCar(BMW));
	unique_ptr<Car> p6(factory1->createCar(AUDI));
	p5->show();
	p6->show();
	//工厂方法
	unique_ptr<Factory> bmwfactory(new BMWFactory());
	unique_ptr<Factory> audifactory(new AudiFactory());
	unique_ptr<Car> p7(bmwfactory->createCar("X6"));
	unique_ptr<Car> p8(audifactory->createCar("A8"));
	p7->show();
	p8->show();

	system("pause");
	return 0;
}
*/