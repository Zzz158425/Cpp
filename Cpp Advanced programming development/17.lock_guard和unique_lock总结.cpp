#include<iostream>
#include<thread>
#include<mutex>
#include<queue>
#include<condition_variable>
using namespace std;

/*
std::mutex mtx;
std::condition_variable cv;
int main()
{
//主动获取/释放互斥锁
	//当程序未运行到 mtx.unlock() 处变 return，会造成死锁等问题
	mtx.lock();
	mtx.unlock();

//lock_guard
	//不能使用在函数参数传递或返回过程中，因为在函数参数传递或返回过程中会用到拷贝构造与 operator= 重载函数
	//lock_guard 无拷贝构造与 operator= 重载函数
	//只能用在简单的临界区代码段的互斥操作中
	lock_guard<std::mutex> guard(mtx);

//unique_lock
	//不仅可以使用在简单的临界区代码段的互斥操作中，还能用在函数调用过程中
	//lock_guard 有右值引用参数拷贝构造与 operator= 重载函数
	unique_lock<std::mutex> lck(mtx);
	cv.wait(lck);//1.使线程进入等待状态；2.把互斥锁释放掉

//condition_variable
	//通知在 cv 上等待的线程
	//其他线程在 cv 上等待的线程，收到通知，从等待状态变为阻塞状态，若此时获取互斥锁了，线程继续往下执行
	cv.notify_all();//通知其他所以线程
	cv.notify_one();//通知单个线程，由操作系统调度器决定，无法指定

	system("pause");
	return 0;
}
*/