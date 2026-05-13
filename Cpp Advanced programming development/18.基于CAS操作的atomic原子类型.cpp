#include<iostream>
#include<thread>
#include<mutex>
#include<list>
#include<atomic>
using namespace std;

/*
//主线程访问 isReady 与 taskcount的值与子线程访问 isReady 与 taskcount值可能会不同
//不同的线程栈不同，但堆与数据段是共享的，对共享的变量多线程是会进行缓存的
//即把主线程的 isReady 改为 true 后，其余线程并不是马上就会知道 isReady 为 true 了，因为不同的线程都是读的是属于自己的缓存
//volatile 防止多线程对共享变量进行缓存，均访问原始内存中的变量的值，提供运行的正确率，但是会降低运行速率
volatile std::atomic_bool isReady = false;
volatile std::atomic_int taskcount = 0;
void task()
{
	while (!isReady)
	{
		std::this_thread::yield();//线程出让当前的 CPU 时间片，等待下一次调度
	}
	for (int i = 0; i < 100; i++)
	{
		taskcount++;
	}
}
int main()
{
//使用互斥锁是比较重的，适用于临界区代码做的事情稍微复杂与多的情况
//使用 CAS 来保证例如 count++,count--等操作的原子特性就足够了
//一般称 CAS 为无锁操作，其操作并不在软件层面，而是在硬件上实现的一个加锁操作
	list<std::thread> tlist;
	for (int i = 0; i < 10; i++)
	{
		tlist.push_back(std::thread(task));
	}
	std::this_thread::sleep_for(std::chrono::seconds(3));
	isReady = true;
	for (std::thread& t : tlist)
	{
		t.join();
	}
	std::cout << "taskcount: " << taskcount << std::endl;

	system("pause");
	return 0;
}
*/