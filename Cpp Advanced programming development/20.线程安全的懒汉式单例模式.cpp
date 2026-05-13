#include<iostream>
#include<thread>
#include<mutex>
#include<list>
using namespace std;

/*
std::mutex mtx;
class Singleton1
{
public:
	static Singleton1* getInstance()
	{

		if (instance == nullptr)
		{
			lock_guard<std::mutex> guard(mtx);
			if (instance == nullptr)//双重判断
			{
				//new Singleton1()：
					//开辟对象
					//给 instance 赋值
					//构造对象
				instance = new Singleton1();//线程不安全
			}
		}
		return instance;
	}
private:
	static Singleton1* volatile instance;//添加 volatile，防止多线程对共享变量进行缓存
	Singleton1()
	{
		std::cout << "Singleton1()" << std::endl;
	}
	Singleton1(const Singleton1&) = delete;
	Singleton1& operator=(const Singleton1&) = delete;
};
Singleton1* volatile Singleton1::instance = nullptr;//添加 volatile，防止多线程对共享变量进行缓存
class Singleton2
{
public:
	static Singleton2* getInstance()
	{
		// 函数静态局部变量的初始化，在汇编指令上已经自动添加线程互斥指令了
		static Singleton2 instance;//第一次运行到该对象时，进行初始化
		return &instance;
	}
private:
	Singleton2()
	{
		std::cout << "Singleton2()" << std::endl;
	}
	Singleton2(const Singleton2&) = delete;
	Singleton2& operator=(const Singleton2&) = delete;
};

int main()
{
//可重入函数：在该程序还未运行结束，再次被调用
	Singleton1* sl1 = Singleton1::getInstance();
	Singleton2* sl2 = Singleton2::getInstance();

	system("pause");
	return 0;
}
*/
