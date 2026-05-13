#pragma once
#include<iostream>
using namespace std;
#include<string>

/*
template<class T>
class MyArray
{
public:
	MyArray(int capacity)//有参构造函数
	{
		cout << "MyArray 有参构造函数调用" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity + 8];
	}
	MyArray(const MyArray& arr)//拷贝构造函数
	{
		cout << "MyArray 拷贝构造函数调用" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//this->pAddress = arr.pAddress;浅拷贝
		this->pAddress = new T[arr.m_Capacity];//深拷贝
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	MyArray& operator=(const MyArray& arr)//operator= 防止浅拷贝问题
	{
		cout << "operator= 函数调用" << endl;
		if (this->pAddress != NULL)//先判断原理堆区是否有数据，如果有先释放
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}
	void Push_Back(const T& val)//尾插法
	{
		if (this->m_Capacity == this->m_Size)
		{
			cout << "容量已满，插入失败" << endl;
			return;
		}
		this->pAddress[this->m_Size] = val;//在数组末尾插入数据
		this->m_Size++;//更新数组大小
	}
	void Pop_Back()//尾删法
	{
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}
	T& operator[](int index)//通过下标方式访问数组中的元素
	{
		return this->pAddress[index];
	}
	int getCapacity()//返回数组容量
	{
		return this->m_Capacity;
	}
	int getSize()//返回数组大小
	{
		return this->m_Size;
	}
	~MyArray()//析构函数
	{
		cout << "MyArray析构函数调用" << endl;
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}
private:
	T* pAddress;//指针指向堆区开辟的真实数组
	int m_Capacity;
	int m_Size;
};
*/
