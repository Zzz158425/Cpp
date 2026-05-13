#include<iostream>
#include<thread>

/*
//C++ 实现多线程编程
//子线程
void threadHandler1(int time)
{
	std::this_thread::sleep_for(std::chrono::seconds(time));//让子线程睡眠 time 秒，this_thread、this_thread 均为命名空间
	std::cout << "hello thread1!" << std::endl;
}
void threadHandler2(int time)
{
	std::this_thread::sleep_for(std::chrono::seconds(time));//让子线程睡眠 time 秒
	std::cout << "hello thread2!" << std::endl;
}

int main()
{
//C++ 多线程编程基本知识
	//thread（线程类）/mutex（线程互斥锁）/condition_variable（线程间的通信）
	//lock_quard/unique_lock（互斥锁相关操作）
	//atomic：原子类型，基于 CAS 操作的原子类型
	//sleep_for
	//C++ 语言层面 thread 可以在编译的时候自动识别当前的操作系统来适配，即最后还是去调用 windows/linux 的 createThread/pthread_create
	//C++ STL 所有的容器都不是线程安全

//线程内容
	//1.怎么创建启动一个线程
		//std::thread 定义一个线程对象，传入线程所需要的线程函数和参数，线程自动开启
	//2.子线程如何结束
		//子线程函数运行完成，线程就结束了
	//3.主线程如何处理子线程
		//t.join()：等待 t 线程结束，当前线程继续往下运行
		//t.detach()：把 t 线程设为分离线程，主线程结束，整个进程结束，所有子线程都自动结束

//C++ 实现线程编程
	//定义线程对象，传入一个线程函数，新线程就开始运行了
	std::thread t1(threadHandler1, 2);//可以传任意多个参数，只要在线程函数添加对应形参
	std::thread t2(threadHandler2, 3);
	//主线程等待子线程结束，主线程继续往下运行，主线程必须等子线程结束才能结束，否则程序会抛出异常
	t1.join();
	t2.join();
	//把子线程设置为分离线程，此时与主线程无关了
	//t1.detach();
	//t2.detach();
	std::cout << "main thread done!" << std::endl;

	system("pause");
	return 0;
}
*/