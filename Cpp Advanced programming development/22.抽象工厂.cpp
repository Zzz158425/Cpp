#include<iostream>
#include<thread>
#include<mutex>
#include<list>
#include<memory>
using namespace std;
//2026.4.29

/*
//系列产品 1
class Car
{
public:
	Car(std::string name) : _name(name) {}
	virtual void show() = 0;
protected:
	std::string _name;
};
class BMW : public Car
{
public:
	BMW(std::string name) : Car(name) {}
	void show()
	{
		std::cout << "获取了一辆宝马汽车" << _name << std::endl;
	}
};
class Audi : public Car
{
public:
	Audi(std::string name) : Car(name) {}
	void show()
	{
		std::cout << "获取了一辆奥迪汽车" << _name << std::endl;
	}
};
//系列产品 2
class Light
{
public:
	virtual void show() = 0;
};

class BmwLight : public Light
{
public:
	void show() { std::cout << "BMW light!" << std::endl; }
};

class AudiLight : public Light
{
public:
	void show() { std::cout << "Audi light!" << std::endl; }
};

//工厂方法
class Factory
{
public:
	virtual Car* createCar(string name) = 0;
};
class LightFactory
{
public:
	virtual Light* createLight() = 0;
};
//宝马工厂
class BMWFactory : public Factory
{
public:
	Car* createCar(string name)
	{
		return new BMW(name);
	}
};
class BMWFLightactory : public LightFactory
{
public:
	Light* createLight()
	{
		return new BmwLight();
	}
};
//奥迪工厂
class AudiLightFactory : public LightFactory
{
public:
	Car* createCar(string name)
	{
		return new Audi(name);
	}
};
class AudiLightFactory : public LightFactory
{
public:
	Light* createLight()
	{
		return new AudiLight();
	}
};
//抽象工厂
// 对有一组关联关系的产品簇提供产品对象的统一创建
class AbstractFactory
{
public:
	virtual Car* createCar(std::string name) = 0;//工厂方法 创建汽车
	virtual Light* createCarLight() = 0;//工厂方法 创建汽车关联产品
};

class AbstractBMWFactory : public AbstractFactory
{
public:
	Light* createCarLight()
	{
		return new BmwLight();
	}
	Car* createCar(std::string name)
	{
		return new BMW(name);
	}
};
class AbstractAudiFactory : public AbstractFactory
{
public:
	Light* createCarLight()
	{
		return new BmwLight();
	}
	Car* createCar(std::string name)
	{
		return new Audi(name);
	}
};

int main()
{
//抽象工厂
	//一个产品对应一个工厂，使用工厂方法当产品多了之后会使工厂急剧增多
	//工厂方法 -> 抽象工厂（对有一组关联关系的产品簇提供产品对象的统一创建）
	//缺点：在基类里面增加抽象接口，子类必须重写接口，否则变为抽象类
	std::unique_ptr<AbstractFactory> bmwfty(new AbstractBMWFactory());
	std::unique_ptr<AbstractFactory> audifty(new AbstractAudiFactory());
	std::unique_ptr<Car> p1(bmwfty->createCar("X6"));
	std::unique_ptr<Car> p2(audifty->createCar("A6"));
	std::unique_ptr<Light> l1(bmwfty->createCarLight());
	std::unique_ptr<Light> l2(audifty->createCarLight());
	p1->show();
	l1->show();
	p2->show();
	l2->show();

//简单工厂、工厂方法、抽象工厂总结
	//简单工厂 SimpleFactory
		//把对象的创建封装在一个接口函数里面，通过传入不同的标识，返回创建的对象
		//客户不用自己负责new对象，不用了解对象创建的详细过程
		//缺点：提供创建对象实例的接口函数不闭合，不能对修改关闭
	//工厂方法 FactoryMethod
		//Factory基类，提供了一个纯虚函数（创建产品），定义派生类（具体产品的工厂）负责创建对应的产品
		//可以做到不同的产品，在不同的工厂里面创建，能够对现有工厂，以及产品的修改关闭
		//缺点：实际上，很多产品是有关联关系的，属于一个产品簇，不应该放在不同的工厂里面去创建，这样是不符合实际的产品对象创建逻辑，二是工厂类太多了，不好维护
	//抽象工厂 AbstractFactory
		//把有关联关系的，属于一个产品簇的所有产品创建的接口函数，放在一个抽象工厂里面 AbstractFactory
		//派生类（具体产品的工厂）应该负责创建该产品簇里面所有的产品
		//缺点：在基类里面增加抽象接口，子类必须重写接口，否则变为抽象类

	system("pause");
	return 0;
}
*/