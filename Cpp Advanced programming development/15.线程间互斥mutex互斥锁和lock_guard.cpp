#include<iostream>
#include<thread>
#include<mutex>
#include<list>
using namespace std;
//2026.4.28

/*
//C++ thread 不加互斥锁模拟车站三个窗口卖票的程序
int ticket_count = 100;//车站有 100 张车票，由三个窗口一起卖票
//模拟卖票的线程函数
void sellTicket(int index)
{
	while (ticket_count > 0)
	{
		std::cout << "窗口：" << index << "卖出第：" << ticket_count << "张票！" << endl;
		ticket_count--;//线程不安全
		//程序的运行顺序由 CPU 的调度来决定
		//每一个线程在运行完每一个指令的时候，都有可能其 CPU 的时间片到达，进入阻塞
		//ticket_count--                              ticket_count--    
		//mov eax, ticket_count（eax = 100）           mov eax, ticket_count（eax = 100） 
		//sub eax, 1（eax = 99，时间片到达进入阻塞）     sub eax, 1（eax = 99）
		//mov ticket_count, eax（ticket_count = 99）   mov ticket_count, eax（ticket_count = 99）
		//以上两个线程都把 99 写入了 ticket_count，两个线程理应从 100 到 98，此时确为 99，这就是线程不安全
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

//C++ thread 加互斥锁模拟车站三个窗口卖票的程序
std::mutex mtx;//全局互斥锁
int ticket_count1 = 100;
void sellTicket1(int index)
{
	while (ticket_count1 > 0)
	{
		//mtx.lock();
		{
			//lock_guard 等效于 scoped_ptr，无拷贝构造与 operator= 重载
			//unique_lock 等效于 unique_ptr，有拷贝构造与 operator= 重载
			lock_guard<std::mutex> lock(mtx);//使用 lock_guard，只要出该作用域就会析构释放该锁，防止死锁
			//unique_lock 使用方法与 mtx 一致，防止死锁
			//unique_lock<std::mutex> lck(mtx);
			//lck.lock();
			if (ticket_count1 > 0)//双重判断，防止同时有多个线程进入 while 而导致 ticket_count1 减至 -1
			{
				//-----临界区代码段，保证原子操作，进行线程间互斥操作-----
				std::cout << "窗口：" << index << "卖出第：" << ticket_count1 << "张票！" << endl;
				ticket_count1--;
				//----------------------------------------------------
			}
			//lck.unlock();
		}
		//mtx.unlock();//若在 mtx.unlock() 之前线程 return 掉，其他程序就会一直获取不到这把锁，那么会进入死锁的状态，所以引入 lock_guard 与 unique_lock
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

int main()
{
//多线程程序
	//线程安全：多线程执行的结果是一致的，如果不会随着 CPU 不同的调度顺序（操作系统调度器决定的线程在 CPU 上的执行顺序），而产生不同的运行结果，反之产生竞态条件
//C++ thread 不加互斥锁模拟车站三个窗口卖票的程序
	list<std::thread> tlist;
	//定义相应的线程
	for (int i = 1; i <= 3; i++)
	{
		tlist.push_back(std::thread(sellTicket, i));
	}
	//等待所以子线程结束
	for (std::thread& t : tlist)
	{
		t.join();
	}

//C++ thread 加互斥锁模拟车站三个窗口卖票的程序
	list<std::thread> tlist1;
	for (int i = 1; i <= 3; i++)
	{
		tlist1.push_back(std::thread(sellTicket1, i));
	}
	for (std::thread& t1 : tlist1)
	{
		t1.join();
	}

	system("pause");
	return 0;
}
*/