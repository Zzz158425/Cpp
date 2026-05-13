#include<iostream>
#include<map>
#include<functional>
#include<algorithm>
#include<string>
#include<thread>
using namespace std;
//2026.4.27

/*
//C++11 bind 是函数模板，可以自动推演模板类型参数，绑定器的返回结果还是函数对象
void hello(string str) { cout << str << endl; }
int sum(int a, int b) { return a + b; }
class Test
{
public:
	int sum(int a, int b) { return a + b; }
};

//bind 和 function 实现线程池
//线程类
class Thread
{
public:
	Thread(function<void(int)> func, int no)
		: _func(func) 
		, _no(no) { }
	thread start()
	{
		thread t(_func, _no);//创建一个新线程，运行 _func(_no)
		return t;//移交线程的控制权
	}
private:
	function<void(int)> _func;
	int _no;
};
//线程池类
class ThreadPool
{
public:
	ThreadPool() {}
	~ThreadPool() 
	{
		//释放 Thread 对象占用的堆资源
		for (int i = 0; i < _pool.size(); i++)
		{
			delete _pool[i];
		}
	}
	//开启线程池
	void startPool(int size)
	{
		for (int i = 0; i < size; i++)
		{
			_pool.push_back(
				new Thread(bind(&ThreadPool::runInThread, this, placeholders::_1), i));
		}
		for (int i = 0; i < size; i++)
		{
			_handler.push_back(_pool[i]->start());
		}
		for (thread &t : _handler)
		{
			t.join();
		}
	}
private:
	vector<Thread*> _pool;
	vector<thread> _handler;
	//把 runInThread 这个成员方法充当线程函数 thread pthread_create 都是 C 函数，不能使用成员函数
	void runInThread(int id)
	{
		cout << "call runInThread! id:" << id << endl;
	}
};

int main()
{
//C++11 bind 是函数模板，可以自动推演模板类型参数，绑定器的返回结果还是函数对象
	bind(hello, "hello bind!")();
	cout << bind(sum, 10, 20)() << endl;
	cout << bind(&Test::sum, Test(), 10, 20)() << endl;//&Test::sum 成员方法，Test() 对象，成员方法必须依赖于对象
	
//参数占位符 placeholders 
	//当参数需要等待用户传递等，需要用参数占位符 placeholders，此时需传入参数
	//最多绑定 20 个参数，绑定器出了语句无法继续使用
	bind(hello, placeholders::_1)("hello bind 2!");
	//using namespace placeholders;
	//bind(hello, _1)("hello bind 2!");
	cout << bind(sum, placeholders::_1, placeholders::_2)(10, 20) << endl;
	//函数对象类型可以把绑定器类型留下来，此处把 bind 返回的绑定器 binder 就复用起来了
	function<void(string)> func1 = bind(hello, placeholders::_1);
	func1("hello china!");
	func1("hello si chuan!");
	func1("hello chong qing!");

//bind 和 function 实现线程池
	ThreadPool pool;
	pool.startPool(10);

	system("pause");
	return 0;
}
*/