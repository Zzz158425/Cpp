#include<iostream>
#include<memory>
#include<thread>
#include<functional>
using namespace std;
//2026.4.25

/*
//智能指针基础知识
template<typename T>
class CSmartPtr
{
public:
	CSmartPtr(T *ptr = nullptr)
		: mptr(ptr) { }
	~CSmartPtr() { delete mptr; }
	CSmartPtr(const CSmartPtr<T>& src)//虽然这样操作可以避免浅拷贝，但是 p1 与 p2 管理的并不是一块内存了
	{
		mptr = new T(*src.mptr);
	}
	T& operator*() { return *mptr; }//需返回 &，否则返回立即数无法修改值
	T* operator->() { return mptr; }
private:
	T* mptr;//记录资源地址
};

//带引用计数的智能指针
template<typename T>
class RefCnt
{
public:
	RefCnt(T* ptr = nullptr)
		: mptr(ptr)
	{ 
		if (mptr != nullptr)
		{
			mcount = 1;
		}
	}
	void addRef() { mcount++; }
	int delRef() { return --mcount; }
private:
	T* mptr;
	int mcount;
};
template<typename T>
class CSmartPtr1
{
public:
	CSmartPtr1(T* ptr = nullptr)
		: mptr(ptr) 
	{
		mpRefCnt = new RefCnt<T>(mptr);
	}
	~CSmartPtr1()  
	{ 
		if (0 == mpRefCnt->delRef())
		{
			delete mptr;
			delete mpRefCnt;
			mpRefCnt = nullptr;
			mptr = nullptr;
		}
	}
	CSmartPtr1(const CSmartPtr1<T>& src)
		: mptr(src.mptr)
		, mpRefCnt(src.mpRefCnt)
	{
		if (mptr != nullptr)
		{
			mpRefCnt->addRef();
		}
	}
	CSmartPtr1<T>& operator=(const CSmartPtr1<T>& src)
	{
		if (this == &src)
		{
			return *this;
		}
		//无智能指针使用该资源，则释放该资源
		if (0 == mpRefCnt->delRef())
		{
			delete mptr;
		}
		mptr = src.mptr;
		mpRefCnt = src.mpRefCnt;
		mpRefCnt->addRef();
		return *this;
	}
	T& operator*() { return *mptr; }//需返回 &，否则返回立即数无法修改值
	T* operator->() { return mptr; }
private:
	T* mptr;//指向资源的指针
	RefCnt<T>* mpRefCnt;//指向该资源引用计数对象的指针
};

//shared_ptr 的交叉引用（循环引用）问题
class B;
class A
{
public:
	A() { cout << "A()" << endl; }
	~A() { cout << "~A()" << endl; }
	shared_ptr<B> _ptrb;
};
class B
{
public:
	B() { cout << "B()" << endl; }
	~B() { cout << "~B()" << endl; }
	shared_ptr<A> _ptra;
};
class B1;
class A1
{
public:
	A1() { cout << "A1()" << endl; }
	~A1() { cout << "~A1()" << endl; }
	void testA() { cout << "testA1()" << endl; }
	weak_ptr<B1> _ptrb;
};
class B1
{
public:
	B1() { cout << "B1()" << endl; }
	~B1() { cout << "~B1()" << endl; }
	void func()
	{
		//__ptra->testA();
		shared_ptr<A1> ps = _ptra.lock();//提升方法，将弱智能指针变为强智能指针
		if (ps != nullptr)//提升成功
		{
			ps->testA();
		}
	}
	weak_ptr<A1> _ptra;
};

//多线程访问对象的线程安全问题
//子线程
class A2
{
public:
	A2() { cout << "A2()" << endl; }
	~A2() { cout << "~A2()" << endl; }
	void testA2() { cout << "testA2()" << endl; }
};
void handler01(A2 *q)
{
	std::this_thread::sleep_for(std::chrono::seconds(2));//等待 2s
	q->testA2();//不安全，调用 q->testA()时，q 已经被析构了
}
class A3
{
public:
	A3() { cout << "A3()" << endl; }
	~A3() { cout << "~A3()" << endl; }
	void testA3() { cout << "testA3()" << endl; }
};
void handler02(weak_ptr<A3> pw)
{
	std::this_thread::sleep_for(std::chrono::seconds(2));//等待 2s
	//pw 访问对象 A3 时，需侦测 A3对象是否存活
	shared_ptr<A3> sp = pw.lock();
	if (sp != nullptr)
	{
		sp->testA3();
	}
	else
	{
		cout << "A对象已经析构，不能再访问";
	}
}

//智能指针的自定义删除器
template<typename T>
class MyDeletor
{
public:
	void operator()(T* ptr) const
	{
		cout << "call MyDeletor.operator()" << endl;
		delete[]ptr;
	}
};
template<typename T>
class MyFileDeletor
{
public:
	void operator()(T* ptr) const
	{
		cout << "call MyFileDeletor.operator()" << endl;
		fclose(ptr);
	}
};


int main()
{
//智能指针基础知识
	//对指针进行封装，利用栈上的对象出作用域自动析构的特征，来做到资源的自动释放
	//用栈上的对象（智能指针）去管理堆上的资源（手动开辟的内存）
	int* p = new int(10);//裸指针，容易造成类型泄漏
	*p = 30;
	delete p;
	CSmartPtr<int> ptr1(new int);//智能指针
	//CSmartPtr<int> *p(new int) = new CSmartPtr<int>(new int);不要把智能指针定义到堆上
	//delete p;定义当堆上需手动释放，此智能指针无意义
	*ptr1 = 20;
	class Test
	{
	public:
		void test() { cout << "call Test::test" << endl; }
	};
	CSmartPtr<Test> ptr2(new Test);//(ptr2.operator->())->test();
	ptr2->test();

//不带引用计数的智能指针
	//auto_ptr：C++ 库，不使用，在 C++11 被弃用，C++17 以上被移除
	//scoped_ptr：C++11 新标准，使用较少，只能使用单个对象，禁止拷贝构造和赋值，因为删除了拷贝构造函数与 operator= 重载函数
		//scoped_ptr(const scoped_ptr<T>&) = delete
		//scoped_ptr<T>& operator=(const scoped_ptr<T>&) = delete
	//unique_ptr：C++11 新标准，推荐使用，虽然删除拷贝构造函数与 operator= 重载函数，但提供了右值拷贝构造函数与右值 operator= 重载函数
		//unique_ptr(const unique_ptr<T>&) = delete
		//unique_ptr<T>& operator=(const unique_ptr<T>&) = delete
		//unique_ptr(unique_ptr<T>&&)
		//unique_ptr<T>& operator=(unique_ptr<T>&&)
	CSmartPtr<int> p1(new int);
	CSmartPtr<int> p2(p1);//智能指针会发生浅拷贝	
	//auto_ptr<int> ptr1(new int);
	//auto_ptr<int> ptr2(ptr1);ptr1 会被置空，将 ptr2 指向 ptr1 所指向的内容
	unique_ptr<int> ptr3(new int);
	unique_ptr<int> ptr4(std::move(ptr3));//p1 不再持有资源，移动给 p2 了

//带引用计数的智能指针
	//带引用计数：多个智能指针可以管理同一个资源，给每一个对象资源，匹配一个引用计数
	//智能指针 -> 使用资源的时候 -> 引用计数 + 1
	//智能指针 -> 不再使用资源的时候 -> 引用计数 - 1 -> 引用计数 = 0，资源释放
	//库里面的 shared_ptr、weak_ptr 可以使用在多线程下
	//CSmartPtr1 实现了库中 shared_ptr，但在多线程下使用不安全
	CSmartPtr1<int> ptr5(new int);
	CSmartPtr1<int> ptr6(ptr5);
	CSmartPtr1<int> ptr7;
	ptr7 = ptr6;
	*ptr5 = 20;
	cout << *ptr6 << " " << *ptr7 << endl;

//shared_ptr 的交叉引用（循环引用）问题
	//定义对象的时候，使用强智能指针；引用对象的地方，使用弱智能指针
	//shared_ptr：强智能指针，可以改变资源的引用计数
	//weak_ptr：弱智能指针，不可以改变资源的引用计数，无法使用资源，只能观察
	//weak_ptr 观察 shared_ptr，shared_ptr 观察资源
	//若弱智能指针要使用相关资源，需用提升方法将弱智能指针变为强智能指针
	//shared_ptr 可以通过共享所有权延长对象生命周期；unique_ptr 管理对象生命周期；weak_ptr 不延长生命周期
	shared_ptr<A> pa(new A());
	shared_ptr<B> pb(new B());
	//shared_ptr 的交叉引用，shared_ptr 内部的计数值无法减到 0，造成了 new 出来的资源无法释放
	pa->_ptrb = pb;
	pb->_ptra = pa;
	cout << pa.use_count() << endl;
	cout << pb.use_count() << endl;
	shared_ptr<A1> pa1(new A1());
	shared_ptr<B1> pb1(new B1());
	pa1->_ptrb = pb1;
	pb1->_ptra = pa1;
	cout << pa1.use_count() << endl;
	cout << pb1.use_count() << endl;
	pb1->func();//提升方法，将弱智能指针变为强智能指针

//多线程访问对象的线程安全问题
	//C++ 非常著名的开源网络库 muduo 库，但存在多线程访问共享对象的线程安全问题
	//main 线程
	A2* p3 = new A2();
	thread t1(handler01, p3);
	delete p3;
	t1.join();
	//使用智能指针来解决该问题
	{
		shared_ptr<A3> p4(new A3());
		thread t2(handler02, weak_ptr<A3>(p4));
		t2.detach();
		//std::this_thread::sleep_for(std::chrono::seconds(2));
	}
	std::this_thread::sleep_for(std::chrono::seconds(10));//等待 20s

//智能指针的自定义删除器
	//~unique_ptr{ deletor(ptr); }，自定义删除器只需提供 operator()
	//template<typename T>
	//class Deletor
	//{
	//public:
	//	void operator()(T* ptr) const
	//	{
	//		deleteptr;
	//	}
	//};
	//用模板类自定义删除器
	unique_ptr<int, MyDeletor<int>> ptr8(new int[100]);//默认释放方式与资源的释放不对等，需自己提供 Deletor
	unique_ptr<FILE, MyFileDeletor<FILE>> ptr9(fopen("data.txe", "w"));//默认释放方式与资源的释放不对等，需自己提供 Deletor
	//用 lambda 表达式自定义删除器
	unique_ptr<int, function<void(int*)>>ptr10(new int[100], 
		[](int* p)->void 
		{
			cout << "call lambda release new int[100]" << endl;
			delete[]p; 
		});
	unique_ptr<FILE, function<void(FILE*)>> ptr11(fopen("data.txe", "w"),
		[](FILE* f)->void
		{
			cout << "call lambda release new fopen" << endl;
			fclose(f);
		});

	system("pause");
	return 0;
}
*/
