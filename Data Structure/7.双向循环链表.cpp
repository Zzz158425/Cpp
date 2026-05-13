#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
using namespace std;

/*
//双向循环链表
//定义双向链表的节点类型
struct Node
{
	Node(int data = 0) : data_(data), pre_(nullptr), next_(nullptr) {};
	int data_;//数据域
	Node* pre_;//指向前一个节点
	Node* next_;//指向下一个节点
};
class DoubleCircleLink
{
public:
	DoubleCircleLink()
	{
		head_ = new Node();
		head_->next_ = head_;
		head_->pre_ = head_;
	}
	~DoubleCircleLink()
	{
		Node* p = head_->next_;
		while (p != head_)
		{
			head_->next_ = p->next_;//让头节点指向 p 指针的后一节点
			p->next_->pre_ = head_;
			delete p;
			p = head_->next_;//重置 p 
		}
		//删除头节点
		delete head_;
		head_ = nullptr;
	}
public:
	//头插法 O(1)
	void InsertHead(int val)
	{
		Node* node = new Node(val);
		node->next_ = head_->next_;//连接新节点与头节点下一节点
		node->pre_ = head_;//连接新节点与头节点
		if (head_->next_ != nullptr)//判断链表是否为空
		{
			head_->next_->pre_ = node;//连接新节点与头节点下一节点
		}
		head_->next_ = node;//连接新节点与头节点
	}
	//尾插法 O(1)
	void InsertTail(int val)
	{
		Node* node = new Node(val);
		Node* p = head_->pre_;//找到尾节点
		//连接插入节点与尾节点
		p->next_ = node;
		node->pre_ = p;
		//连接插入节点与头节点
		node->next_ = head_;
		head_->pre_ = node;
	}
	//打印链表
	void Show() const
	{
		Node* p = head_->next_;
		while (p != head_)
		{
			cout << p->data_ << " ";
			p = p->next_;
		}
		cout << endl;
	}
	//节点删除
	void Remove(int val)
	{
		Node* p = head_->next_;
		while (p != head_)//循环查找需删除节点
		{
			if (p->data_ == val)//找到
			{
				//删除 p 指向的节点
				p->pre_->next_ = p->next_;
				p->next_->pre_ = p->pre_;
				delete p;
				return;
			}
			else
			{
				p = p->next_;
			}

		}
	}
	//节点搜索
	bool Find(int val)
	{
		Node* p = head_->next_;
		while (p != head_)
		{
			if (p->data_ == val)
			{
				return true;
			}
			else
			{
				p = p->next_;
			}
		}
		return false;
	}
private:
	Node* head_;//指向头节点
};

int main()
{
//双向循环链表
	//特点：
		//每一个节点除了数据域，还有 next 指针域指向下一个节点，pre 指针域指向前一个节点
		//头节点的 pre 指向末尾节点，末尾节点的 next 指向头节点
	DoubleCircleLink dlink;
	dlink.InsertTail(100);
	dlink.InsertTail(20);
	dlink.InsertTail(12);
	dlink.InsertTail(78);
	dlink.InsertTail(32);
	dlink.InsertTail(7);
	dlink.InsertTail(90);
	dlink.Show();
	dlink.InsertHead(200);
	dlink.Show();
	dlink.Remove(200);
	dlink.Show();
	dlink.Remove(90);
	dlink.Show();
	dlink.Remove(78);
	dlink.Show();
 
	system("pause");
	return 0;
}
*/