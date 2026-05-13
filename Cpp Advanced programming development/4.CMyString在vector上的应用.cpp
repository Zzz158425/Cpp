#include<iostream>
#include<vector>
using namespace std;
//2026.4.24

/*
//示例一
class CMyString
{
public:
	CMyString(const char* str = nullptr)
	{
		cout << "CMyString(const char*)" << endl;
		if (str != nullptr)
		{
			mptr = new char[strlen(str) + 1];
			strcpy(mptr, str);
		}
		else
		{
			mptr = new char[1];
			*mptr = '\0';
		}
	}
	~CMyString()
	{
		cout << "~CMyString" << endl;
		delete[]mptr;
		mptr = nullptr;
	}
	CMyString(const CMyString& str)
	{
		cout << "CMyString(const CMyString&)" << endl;
		mptr = new char[strlen(str.mptr) + 1];
		strcpy(mptr, str.mptr);
	}
	CMyString(CMyString&& str)
	{
		cout << "CMyString(CMyString&& str)" << endl;
		mptr = str.mptr;
		str.mptr = nullptr;
	}
	CMyString& operator=(const CMyString& str)
	{
		cout << "operator=(const CMyString&)" << endl;
		if (this == &str)
		{
			return *this;
		}
		delete[]mptr;
		mptr = new char[strlen(str.mptr) + 1];
		strcpy(mptr, str.mptr);
		return *this;
	}
	CMyString& operator=(CMyString&& str)
	{
		cout << "operator=(const CMyString&&)" << endl;
		if (this == &str)
		{
			return *this;
		}
		delete[]mptr;
		mptr = str.mptr;
		str.mptr = nullptr;
		return *this;
	}
	const char* c_str() const { return mptr; };
private:
	friend CMyString operator+(const CMyString& lhs, const CMyString& rhs);
	friend ostream& operator<<(ostream& out, const CMyString& str);
	char* mptr;
};
CMyString operator+(const CMyString& lhs, const CMyString& rhs)
{
	//注意：此处优化在 VS2022 中并没有用到，因为编译器会自动优化，不存在拷贝构造 tempStr 后，再拷贝构造给 main 函数栈上的临时对象
	//3.继续优化，用带右值引用参数的拷贝构造，即不会造成数据的无效拷贝，也不会造成内存泄漏
	CMyString tmpStr;
	tmpStr.mptr = new char[strlen(lhs.mptr) + strlen(rhs.mptr) + 1];
	//char* ptmp = new char[strlen(lhs.mptr) + strlen(rhs.mptr) + 1];
	strcpy(tmpStr.mptr, lhs.mptr);
	strcat(tmpStr.mptr, rhs.mptr);
	return tmpStr;
	//2.优化为创建一个对象，释放 ptmp，再返回，但会造成数据的无效拷贝，效率会降低
	//CMyString tmpStr(ptmp);
	//delete[]ptmp;
	//return tmpStr;
	//1.直接返回临时对象此处无 delete，造成内存泄漏，每做一个加法就会泄漏一块内存
	//return CMyString(ptmp);
}
ostream& operator<<(ostream& out, const CMyString& str)
{
	out << str.mptr;
	return out;
}

//move 移动语义和 forwar 类型完美转发
template<typename T>
struct Allocator
{
	//负责内存开辟
	T* allocate(size_t size)
	{
		return (T*)malloc(sizeof(T) * size);
	}
	//负责内存释放
	void deallocate(void* p)
	{
		free(p);
	}
	//负责对象构造
	//左值引用
	void construct(T* p, const T& val)
	{
		new (p) T(val);//定位 new
	}
	//右值引用
	void construct(T* p, T&& val)//移动语义不能加 const
	{
		//new (p) T(val);//定位 new，右值引用本身是一个左值，所以此处还是匹配的 construct 左值引用，调用的还是普通的拷贝构造
		new (p) T(std::move(val));//std::move() 强转为右值引用
	}
	//用模板实现对象构造的左右值引用
	template<typename Ty>
	void construct1(T* p, Ty&& val)
	{
		new (p) T(std::forward<Ty>(val));//定位 new
	}
	//负责对象析构
	void destroy(T* p)
	{
		p->~T();//~T() 代表了 T 类型的析构函数
	}
};
template<typename T, typename Alloc = Allocator<T>>
class vector1
{
public:
	vector1(int size = 10, const Alloc = Allocator<T>())
	{
		//_first = new T[size];
		_first = _allocator.allocate(size);//只开辟内存
		_last = _first;
		_end = _first + size;
	}
	~vector1()
	{
		//delete[]_first;
		//析构有效元素
		for (T* p = _first; p != _last; p++)
		{
			_allocator.destroy(p);
		}
		_allocator.deallocate(_first);//释放堆上的数组内存
		_first = _last = _end = nullptr;
	}
	vector1(const vector1<T>& rhs)
	{
		int size = rhs._end - rhs._first;
		//_first = new T[size];
		_first = _allocator.allocate(size);//只开辟内存
		int len = rhs._last - rhs._first;
		for (int i = 0; i < len; i++)
		{
			//_first[i] = rhs._first[i];
			_allocator.construct(_first + i, rhs._first[i]);
		}
		_last = _first + len;
		_end = _first + size;
	}
	vector1<T>& operator=(const vector1<T>& rhs)
	{
		if (this == _first)
		{
			return *this;
		}
		//delete[]_first;
		//析构有效元素
		for (T* p = _first; p != _last; p++)
		{
			_allocator.destroy(p);
		}
		_allocator.deallocate(_first);//释放堆上的数组内存
		int size = rhs._end - rhs._first;
		_first = new T[size];
		int len = rhs._last - rhs._first;
		for (int i = 0; i < len; i++)
		{
			_first[i] = rhs._first[i];
		}
		_last = _first + len;
		_end = _first + size;
		return *this;
	}
	//用函数分别实现从容器末尾添加元素的左右值引用
	//左值引用
	void push_back(const T& val)
	{
		if (full())
		{
			expand();
		}
		//*_last++ = val;
		_allocator.construct(_last, val);
		_last++;
	}
	//右值引用
	void push_back(T&& val)//移动语义不能加 const
	{
		if (full())
		{
			expand();
		}
		//*_last++ = val;
		//_allocator.construct(_last, val);//右值引用本身是一个左值，所以此处还是匹配的 construct 左值引用，调用的还是普通的拷贝构造
		_allocator.construct(_last, std::move(val));//std::move() 强转为右值引用
		_last++;
	}
	//用模板实现从容器末尾添加元素的左右值引用
	template<typename Ty>//函数模板的类型推演 + 引用折叠，引用折叠 & + && = &，&& + && = &&
	void push_back1(Ty&& val)//CMyString& &&val = CMyString& val，CMyString&& &&val = CMyString&& val
	{
		if (full())
		{
			expand();
		}
		_allocator.construct1(_last, std::forward<Ty>(val));//自动识别val 是左值还是右值
		_last++;
	}
	//从容器末尾删除元素
	void pop_back()
	{
		if (empty())
		{
			return;
		}
		//_last--;
		_last--;
		_allocator.destroy(_last);

	}
	//返回容器末尾的元素值
	T back() const
	{
		return *(_last - 1);
	}
	bool full() const { return _last == _end; }//判断容器是否满
	bool empty() const { return _last == _first; } //判断容器是否为空
	int size() const { return _last - _first; }//返回容器个数
private:
	T* _first;//指向数组起始的位置
	T* _last;//指向数组中有限元素的后继位置
	T* _end;//指向数组空间的后继位置
	Alloc _allocator;//定义容器的空间适配器对象
	//容器 2 倍扩容
	void expand()
	{
		int size = _end - _first;
		//T* ptmp = new T[size * 2];
		T* ptmp = _allocator.allocate(size * 2);
		for (int i = 0; i < size; i++)
		{
			//ptmp[i] = _first[i];
			_allocator.construct(ptmp + i, _first[i]);
		}
		//delete[]_first;
		for (T* p = _first; p != _last; p++)
		{
			_allocator.destroy(p);
		}
		_allocator.deallocate(_first);//释放堆上的数组内存
		_first = ptmp;
		_last = _first + size;
		_end = _first + (size * 2);
	}
};

int main()
{
//示例一
	//CMyString 的 operator+ 优化
	CMyString str1 = "hello ";
	CMyString str2 = "world!";
	CMyString str3 = str1 + str2;
	cout << str3 << endl;

//示例二
	//vec.push_back(str4) 与 vec.push_back(CMyString("bbb")) 构造区别
	cout << "----------示例二-----------" << endl;
	CMyString str4 = "aaa";
	vector<CMyString> vec;
	vec.reserve(10);
	vec.push_back(str4);//CMyString(const char*)
	vec.push_back(CMyString("bbb"));//CMyString(CMyString&& str)

//move 移动语义和 forwar 类型完美转发
	//move：移动语义函数，强转为右值引用
	//移动语义：当源对象是一个即将被销毁的对象时，不做深拷贝，而是直接把源对象的资源“偷”过来，转移给目标对象
	//移动语义最常见、最自然的应用场景就是处理临时对象
	//forwar：类型完美转发，自动识别左值还是右值类型
	cout << "----------move 移动语义-----------" << endl;
	CMyString str5 = "aaa";
	vector1<CMyString> vec1;
	vec1.push_back(str5);
	vec1.push_back(CMyString("bbb"));
	cout << "----------forwar 类型完美转发-----------" << endl;
	CMyString str6 = "aaa";
	vector1<CMyString> vec2;
	vec2.push_back1(str6);
	vec2.push_back1(CMyString("bbb"));

	system("pause");
	return 0;
}
*/
