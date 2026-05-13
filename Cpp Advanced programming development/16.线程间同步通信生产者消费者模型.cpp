#include<iostream>
#include<thread>
#include<mutex>
#include<queue>
#include<condition_variable>
using namespace std;

/*
//生产者消费者模型
std::mutex mtx;//定义互斥锁，左线程间的互斥操作
std::condition_variable cv;//定义条件变量，做线程间的同步通信操作
class Queue
{
public:
	//生成物品
	void put(int val)
	{
		//lock_guard<std::mutex> guard(mtx);//互斥锁
		unique_lock<std::mutex> lck(mtx);
		//que 不为空，生产者应该通知消费者去消费，消费完了再继续生产
		//生产者线程应该进入等待状态，并且把 mtx 互斥锁释放掉
		while (!que.empty())
		{
			cv.wait(lck);//wait：1.进入等待状态；2.把互斥锁释放掉
		}
		que.push(val);
		//notify_all 通知其他所以线程，notify_one 通知另外的一个线程
		//其他线程得到该通知，就会从等待状态变为阻塞状态，此时需要获取互斥锁才能继续执行
		cv.notify_all();
		cout << "生产者 生产：" << val << " 号物品" << endl;
	}
	//消费物品
	int get()
	{
		//lock_guard<std::mutex> guard(mtx);//互斥锁
		unique_lock<std::mutex> lck(mtx);
		//que 为空，消费者应该通知生产者去生产，生产完了再继续消费
		//消费者线程应该进入等待状态，并且把 mtx 互斥锁释放掉，直到通知才继续运行
		while (que.empty())
		{
			cv.wait(lck);
		}
		int val = que.front();
		que.pop();
		cv.notify_all();
		cout << "消费者 消费：" << val << " 号物品" << endl;
		return val;
	}
private:
	queue<int> que;
};
//生产者线程函数
void producer(Queue* que)
{
	for (int i = 1; i <= 10; ++i)
	{
		que->put(i);
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}
//消费者线程函数
void consumer(Queue* que)
{
	for (int i = 1; i <= 10; ++i)
	{
		que->get();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

int main()
{
//多线程编程的两个问题：
	//1.线程间互斥：
		//发生竞态条件的代码段称为临界区代码段，利用互斥锁 mutex 或轻量级的的无锁实现 CAS 保证原子操作
	//2.线程间的同步通信
		//线程间存在依赖运行关系等需要进行通信
		//典型的线程间的同步通信问题：生产者消费者线程模型
	//C++ STL 所有的容器都不是线程安全

//生产者消费者模型
	Queue que;//两个线程共享的队列
	//生产者生产一个物品，通知消费者消费一个；消费完了，消费者再通知生产者继续生产物品
	//否则若两线程之间无通信会出现消费的数量大于生成的数量造成程序挂掉
	std::thread t1(producer, &que);//producer(Queue* que)
	std::thread t2(consumer, &que);//consumer(Queue* que)
	t1.join();
	t2.join();

	system("pause");
	return 0;
}
*/