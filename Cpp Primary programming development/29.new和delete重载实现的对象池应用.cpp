#include<iostream>
#include<typeinfo>
#include<string>
#include<vector>
using namespace std;

/*
//new 和 delete 重载实现的对象池应用
template<typename T>
class Queue
{
public:
	Queue()
	{
		_front = _rear = new QueueItem();
	}
	~Queue()
	{
		QueueItem* cur = _front;
		while (cur != nullptr)
		{
			_front = _front->_next;
			delete cur;
			cur = _front;
		}
	}
	void push(const T& val)
	{
		QueueItem* item = new QueueItem(val);
		_rear->_next = item;
		_rear = item;
	}
	void pop()
	{
		if (empty())
		{
			return;
		}
		QueueItem* first = _front->_next;
		_front->_next = first->_next;
		if (_front->_next == nullptr)
		{
			_rear = _front;
		}
		delete first;
	}
	T front() const
	{
		  return _front->_next->_data;
	}
	bool empty() const { return _front == _rear; }
private:
	//产生一个 QueueItem 的对象池（10000 个 QueueItem 节点）
	struct QueueItem
	{
		QueueItem(T data = T())//零构造，_data 赋一个默认的、合法的初始值
			:_data(data), _next(nullptr) { }
		//给 QueueItem 提供自定义内存管理
		void* operator new(size_t size)
		{
			if (_itemPool == nullptr)
			{
				_itemPool = (QueueItem*)new char[POOL_ITEM_SIZE * sizeof(QueueItem)];//开辟 100000 个 QueueItem 节点 
				QueueItem* p = _itemPool;
				for (; p < _itemPool + POOL_ITEM_SIZE - 1; ++p)
				{
					p->_next = p + 1;
				}
				p->_next = nullptr;
			}
			QueueItem* p = _itemPool;
			_itemPool = _itemPool->_next;
			return p;
		}
		void operator delete(void* ptr)
		{
			QueueItem* p = (QueueItem*)ptr;
			p->_next = _itemPool;
			_itemPool = p;
		}
		T _data;
		QueueItem* _next;
		static QueueItem* _itemPool;
		static const int POOL_ITEM_SIZE = 100000;
	};
	QueueItem* _front;//指向队头
	QueueItem* _rear;//指向队尾
};
template<typename T>
typename Queue<T>::QueueItem* Queue<T>::QueueItem::_itemPool = nullptr;//此时 Queue 还未实例化，添加 typename 告诉编译器后边嵌套类作用域下的名字是一个类型

int main()
{
//new 和 delete 重载实现的对象池应用
	//实现对象池作用：提高运行效率
	Queue<int> que;
	for (int i = 0; i < 1000000; ++i)
	{
		//频繁 new 和 delete 节点
		que.push(i);
		que.pop();
	}
	cout << que.empty() << endl;

	system("pause");
	return 0;
}
*/