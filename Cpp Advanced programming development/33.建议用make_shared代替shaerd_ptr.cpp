#include<iostream>
using namespace std;
//2026.5.4

/*
class Test
{ 
public:
	Test(int a) { cout << "Test(int)" << endl; }
	Test(int a, int b) { cout << "Test(int, int)" << endl; }
};

int main()
{
//C++11 make_shared
	//不带引用计数的智能指针：unique_ptr
	//带引用计数的智能指针：shared_ptr/weak_ptr
	shared_ptr<int> sp1(new int(10));
	shared_ptr<Test> sp2(new Test(10));
	//使用 shared_ptr 底层会开辟两个内存：
		//---shared_ptr---
		//| int* ptr--- |---> new int(10)   ----------------
		//| RefCnt* ref-|-----------------> | uses | weaks |
		//----------------                  ----------------
		//shared_ptr<int> sp2(sp1);uses++
		//weak_ptr<int> wp1(sp1);weaks++
	//存在缺陷：当 shared_ptr 对象生成失败，此时存在 new int(10)，但无 uses 与 weaks，此时无法进行析构，从而造成内存泄漏
	shared_ptr<int> sp3 = make_shared<int>(10);//make_shared 返回 shared_ptr
	//auto sp3 = make_shared<int>(10);
	auto sp4 = make_shared<Test>(10);
	auto sp5 = make_shared<Test>(10, 20);
	//auto sp5(make_shared<Test>(10, 20));
	*sp3 = 20;
	cout << *sp3 << endl;
	//使用 make_shared 底层会开辟一个内存：
		//---make_shared---   ------------------------------
		//| int* ptr--- |---> | new int(10) | uses | weaks |  
		//| RefCnt* ref |     -------------------------------
		//----------------               
		//make_shared 把我们需要托管的内存资源和存储引用计数的内存资源起开辟了，在一块内存上
		//此时不会出现 new int(10) 内存开辟成功，而 uses 与 weaks 内存开辟失败的情况，要么全部开辟成功，要么全部开辟失败
	//make_shared 优点：
		//1.内存分配效率高
		//2.防止资源泄漏的风险
	//make_shared 缺点：
		//1.make_shared 无法自定义删除器
		//2.即使没有强智能指针指向资源，资源也无法释放
		//3.导致托管的资源延迟释放，需强弱智能指针计数均为 0，内存才释放，unique_ptr 只要强智能指针计数为 0 就释放开辟的内存

	system("pause");
	return 0;
}
*/