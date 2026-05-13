#include<iostream>
#include<typeinfo>
#include<string>
#include<vector>
#include<deque>
#include<list>
using namespace std;

/*
int main()
{
//deque 双端队列容器
	//底层数据结构：动态开辟二维数组，一维数组从 2 开始，以 2 倍的方式进行扩容
	//二维数组：
		//                        -----    -----------------------------------------------
		// #define MAP_SIZE 2  -> | --|--> |   |...#define QUE_SIZE 4096/sizeof(T)...|   |
		//               |        -----    -----------------------------------------------
		//               |------> |   |
		//                        -----
		//                        mapper
	//扩容方式：每次扩容后，原来第二维的数组，从新的第一维数组的下标 oldsize / 2 开始存放，上下预留相同的空行，方便支持 deque 的首尾元素添加
	//deque<int> deq;
	//增加：
		//deq.push_back(20);从末尾添加元素 O(1)
		//deq.push_front(20);从首部添加元素 O(1)
		//deq.insert(it, 20);从 it 指定的位置添加元素 O(n)
	//删除：
		//deq.pop_back();从末尾删除元素 O(1)
		//deq.pop_front();从首部删除元素 O(1)
		//deq.erase;从 it 指定的位置删除元素 O(n)
	//查询搜索：
		//iterator（连续的 insert 和 erase 一定要考虑迭代器失效问题）
	
//list 链表容器	
	//底层数据结构：双向循环链表 pre data next
	//list<int> mylist;
	//增加：
		//mylist.push_back(20);从末尾添加元素 O(1)
		//mylist.push_front(20);从首部添加元素 O(1)
		//mylist.insert(it, 20);单单从 it 指定的位置添加元素 O(1)，但在链表中进行 insert 需进行 query 查询
	//删除：
		//mylist.pop_back();从末尾删除元素 O(1)
		//mylist.pop_front();从首部删除元素 O(1)
		//mylist.erase(it);单单从 it 指定的位置删除元素 O(1)，但在链表中进行 insert 需进行 query 查询
	//查询搜索：
		//iterator（连续的 insert 和 erase 一定要考虑迭代器失效问题）
	//deque 与 list，比 vector 容器多出来的增加删除函数接口：push_front、pop_front

//vector、deque 和 list 对比
	//vector 底层数据结构：动态开辟数组，每次以原来空间大小 2 倍扩容
	//deque 底层数据结构：动态开辟二维数组，第二维是固定长度的数组空间，扩容每次从第一维的数组进行 2 倍扩容
		//deque 底层内存不是连续的，第二维每一段都是独立 new 出来的，
	//list 底层数据结构：双向循环链表 pre data next
	//vector 与 deque 区别
		//底层数据结构不同
		//添加插入删除元素时间复杂度略有不同
		//内存使用效率不同：vector 使用效率低，需要的内存空间必须是连续的，deque 可以分块进行数据存储，不需要一块连续的内存空间
		//由于 deque 的第二维内存空间不是连续的，所以在 deque 中间进行元素的 insert/erase，造成元素移动的时候要比 vector 慢
	//vector 与 list 区别
		//底层数据结构完全不同

	system("pause");
	return 0;
}
*/