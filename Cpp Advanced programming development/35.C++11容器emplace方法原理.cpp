#include<iostream>
#include<vector>
#include<map>
using namespace std;
//2026.5.6

/*
//push_back 与 emplace_back 异同
class Test
{
public:
	Test(int a) { cout << "Test(int)" << endl; }
	Test(int a, int b) { cout << "Test(int, int)" << endl; }
	Test(const Test&) { cout << "Test(const Test&)" << endl; }
	Test(Test&&) { cout << "Test(Test&&)" << endl; }
	~Test() { cout << "~Test()" << endl; }
};

//实现容器 emplace 方法
template<typename T>
struct MyAllocator
{
	T* allocate(size_t size)
	{
		return (T*)malloc(sizeof(T) * size);
	}
	template<typename... Types>
	void construct(T* ptr, Types&&... args)//引用折叠
	{
		//args 只是一个参数，而且是一个 Test 对象，T 也是 Test 类型
		new (ptr) T(std::forward<Types>(args)...);//在 ptr 指向的已有内存上构造对象 T
	}
};
template<typename T, typename Alloc = MyAllocator<T>>
class Vector
{
public:
	Vector()
		: vec_(nullptr) 
		, size_(0)
		, idx_(0) { }
	void reserve(size_t size)
	{
		vec_ = allocator_.allocate(size);
		size_ = size;
	}
	//void push_back(const T& val)
	//{
	//	allocator_.construct(vec_ + idx_, val);
	//	idx_++;
	//}
	//void push_back(T&& val)
	//{
	//	allocator_.construct(vec_ + idx_, std::move(val));//move() 移动语义
	//	idx_++;
	//}
	template<typename Type>
	void push_back(Type&& val)//引用折叠
	{
		allocator_.construct(vec_ + idx_, std::forward<Type>(val));//move() 移动语义
		idx_++;
	}
	template<typename... Types>
	void emplace_back(Types&&... args)//引用折叠
	{
		allocator_.construct(vec_ + idx_, std::forward<Types>(args)...);//forward() 完美转发
		idx_++;
	}
private:
	T* vec_;
	int size_;
	int idx_;
	Alloc allocator_;
};

int main()
{
//push_back 与 emplace 异同
	Test t1(10);
	vector<Test> v;
	v.reserve(100);
	//直接插入已存在的对象 push_back 与 emplace_back 无区别
	cout << "----------已存在对象----------" << endl;
	v.push_back(t1);
	v.emplace_back(t1);
	//直接插入临时对象 push_back 与 emplace_back 无区别
	cout << "----------临时对象----------" << endl;
	v.push_back(Test(20));
	v.emplace_back(Test(20));
	//给 emplace 传入 Test 对象构造所需要的参数，直接在容器底层构造对象即可
	cout << "----------直接传入所需参数----------" << endl;
	v.emplace_back(20);//直接调用构造 Test(int a)，没有产生任何的额外的其他对象
	v.emplace_back(30, 40);//直接调用构造 Test(int a, int b)，没有产生任何的额外的其他对象
	//map<int, string> m;
	//m.insert(make_pair(10, "zhang san"));//创建一个临时对象 pair，调用了带有右值引用参数的拷贝构造函数
	//m.emplace(10, "zhang san");//在 map 底层直接调用普通构造函数，生成一个 pair 对象即可

//实现容器 emplace 方法
	cout << "----------自定义 Vector----------" << endl;
	Test t2(10);
	Vector<Test> v2;
	v2.reserve(100);
	cout << "----------已存在对象----------" << endl;
	v2.push_back(t2);
	v2.emplace_back(t2);
	cout << "----------临时对象----------" << endl;
	v2.push_back(Test(20));
	v2.emplace_back(Test(20));
	cout << "----------直接传入所需参数----------" << endl;
	v2.emplace_back(20);
	v2.emplace_back(30, 40);

	system("pause");
	return 0;
}
*/