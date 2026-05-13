#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

/*
//跳跃表算法实现
class SkipList
{
public:
	SkipList()
	{
		head_ = new HeadNode(1);
	}
	~SkipList()
	{
		int level = head_->level_;
		for (int i = 0; i < head_->level_; i++)
		{
			Node* cur = head_->next_;
			while (cur != nullptr)
			{
				Node* temp = cur->next_;
				delete cur;
				cur = temp;
			}
			cur = head_;
			head_ = static_cast<HeadNode*>(head_->down_);
			delete cur;
		}
	}
public:
	//搜索数据
	bool find(int data)
	{
		Node* pre = head_;
		Node* cur = pre->next_;
		for (;;)
		{
			if (cur != nullptr)
			{
				if (cur->data_ < data)
				{
					pre = cur;
					cur = cur->next_;
					continue;
				}
				else if (cur->data_ == data)
				{
					return true;
				}
			}
			if (pre->down_ == nullptr)
			{
				//pre 和 cur 已经变量到第一层的末尾了
				break;
			}
			pre = pre->down_;
			cur = pre->next_;
		}
		return false;
	}
	//添加数据
	void add(int data)
	{
		//先查找数据是否存在
		if (find(data))
		{
			return;
		}
		//抛硬币，data 数据添加几层
		int level = getLevel();
		//level 过大，跳跃表只增长一层
		if (level > head_->level_)
		{
			level = head_->level_ + 1;
			HeadNode* hnode = new HeadNode(level);
			hnode->down_ = head_;
			head_ = hnode;
		}
		//先创建 level 层的 data 节点，修改 down 指针域
		Node** nodeList = new Node * [level];
		for (int i = level - 1; i >= 0; i--)
		{
			nodeList[i] = new Node(data);
			if (i < level - 1)
			{
				//上面节点的 down 指针域，存储下面节点的地址
				nodeList[i]->down_ = nodeList[i + 1];
			}
		}
		Node* head = head_;
		for (int i = head_->level_; i > level; i--)
		{
			head = head->down_;
		}
		//head 就指向了要插入节点的链表了
		Node* pre = head;
		Node* cur = head->next_;
		for (int i = 0; i < level; i++)
		{
			while (cur != nullptr && cur->data_ < data)
			{
				pre = cur;
				cur = cur->next_;
			}
			//将新节点插入到 pre 和 cur 的中间
			nodeList[i]->next_ = cur;
			pre->next_ = nodeList[i];
			//继续对下一层进行插入
			pre = pre->down_;
			if (pre != nullptr)
			{
				cur = pre->next_;
			}
		}
		delete[]nodeList;
		nodeList = nullptr;
	}
	//打印数据
	void show() const
	{
		Node* head = head_;
		while (head != nullptr)
		{
			Node* cur = head->next_;
			while (cur != nullptr)
			{
				cout << cur->data_ << " ";
				cur = cur->next_;
			}
			cout << endl;
			head = head->down_;
		}
		cout << endl;
	}
	//删除数据
	void remove(int data)
	{
		Node* pre = head_;
		Node* cur = pre->next_;
		for (;;)
		{
			if (cur != nullptr)
			{
				if (cur->data_ < data)
				{
					pre = cur;
					cur = cur->next_;
					continue;
				}
				else if (cur->data_ == data)
				{
					//删除 cur 指向的节点
					pre->next_ = cur->next_;
					delete cur;
				}
			}
			if (pre->down_ == nullptr)
			{
				break;
			}
			//cur == nullptr 当前层没有 data 节点
			pre = pre->down_;
			//若删除节点后为空层，应删除该层
			if (head_->next_ == nullptr)
			{
				delete head_;
				head_ = static_cast<HeadNode*>(pre);
			}
			cur = pre->next_;
		}
	}
private:
	//普通节点类型
	struct Node
	{
		Node(int data = int())
			: data_(data)
			, next_(nullptr)
			, down_(nullptr)
		{}
		int data_;//数据域
		Node* next_;//指向同一层的后一个节点指针域
		Node* down_;//指向下一层的节点指针域
	};
	//跳跃表的头节点类型
	struct HeadNode : public Node
	{
		HeadNode(int level)
			: level_(level)
		{ }
		int level_;//跳跃表的层数
	};
	HeadNode* head_;//指向跳跃表最上面一层链表的头节点
	//抛硬币
	int getLevel() const
	{
		int level = 1;
		while (rand() % 2 == 1)
		{
			level++;
		}
		return level;
	}
};

int main()
{
//跳跃表算法思想 2026.4.15
	//跳跃表具有如下性质：
		//1.由很多层链表组成
		//2.每一层都是一个有序的链表
		//3.最底层 level 1 的链表包含所有元素
		//4.如果一个元素出现在 level i 层的链表中，则它在 level i 之下的链表也都会出现
		//5.每个节点都包含两个指针，一个指向同一链表中的下一个元素，一个指向下面一层的元素
	//跳跃表的增加、删除、查询操作时间复杂度和红黑树一样，也是 O(logn)，相比于红黑树，它的优势是：
		//1.实现起来更加简单
		//2.跳跃表的增加、删除操作只会改动局部，不像红黑树的增加、删除操作，因为需要节点重新着色和旋转，可能整棵树都要进行调整，因此在并发环境下，跳跃表加锁的粒度会更小一些，并发能力更强
		//3.因为跳跃表的每一层都是一个有序的链表，因此范围查找非常方便，优于红黑树的范围搜索的
	//跳跃表相比于红黑树，是用空间换时间（level 2 层开始每一层都有会存储重复的数据），因此占用的内存空间比红黑树大
	
//跳跃表算法实现
	SkipList list;
	srand(time(0));
	for (int i = 0; i < 20; i++)
	{
		list.add(rand() % 100);
	}
	list.add(50);
	list.show();
	list.remove(50);
	list.show();

	system("pause");
	return 0;
}
*/