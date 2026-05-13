#include<iostream>
#include<thread>
#include<mutex>
#include<list>
#include<atomic>
using namespace std;

/*
//单例模式
//饿汉式单例模式
class Singleton
{
public:
	//3.获取类的唯一实例对象的接口方法
	static Singleton* getInstance()
	{
		return &instance;
	}
private:
	static Singleton instance;//2.定义一个唯一的类的实例对象，数据段
	//1.构造函数私有化，去掉默认构造与 operator=
	Singleton()
	{

	}
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
};
Singleton Singleton::instance;
//懒汉式单例模式
class Singleton1
{
public:
	static Singleton1* getInstance()
	{
		//只有第一次想访问实例对象时，才创建对象
		if (instance == nullptr)
		{
			instance = new Singleton1();
		}
		return instance;
	}
private:
	static Singleton1* instance;//初始无对象，只有一个指针
	Singleton1()
	{

	}
	Singleton1(const Singleton1&) = delete;
	Singleton1& operator=(const Singleton1&) = delete;
};
Singleton1* Singleton1::instance = nullptr;

int main()
{
//单例模式
	//一个类不管创建多少次对象，永远只能得到该类型一个对象的实例
	//应用：日志模块、数据库模块
	//饿汉式单例模式：还没有获取实例对象，实例对象就已经产生了
		//一定线程安全，但有可能在业务运行中并未用到该对象，但也去创建了该对象，导致浪费时间，启动该业务/软件时间过长
	//懒汉式单例模式：唯一的实例对象，直到第一次获取它的时候才产生
	Singleton* p1 = Singleton::getInstance();
	Singleton* p2 = Singleton::getInstance();
	cout << p1 << endl;
	cout << p2 << endl;
	Singleton1* p3 = Singleton1::getInstance();
	Singleton1* p4 = Singleton1::getInstance();
	cout << p3 << endl;
	cout << p4 << endl;

	system("pause");
	return 0;
}
*/