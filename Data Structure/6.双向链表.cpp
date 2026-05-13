#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
using namespace std;

/*
//双向链表 2026.1.31
//定义双向链表的节点类型
struct Node
{
	Node(int data = 0) : data_(data), pre_(nullptr), next_(nullptr) {};
	int data_;//数据域
	Node* pre_;//指向前一个节点
	Node* next_;//指向下一个节点
};
class DoubleLink
{
public:
	DoubleLink()
	{
		head_ = new Node();
	}
	~DoubleLink()
	{
		Node* p = head_;
		while (p != nullptr)
		{
			head_ = head_->next_;
			delete p;
			p = head_;
		}
	}
public:
	//头插法
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
	//尾插法
	void InsertTail(int val)
	{
		Node* node = new Node(val);
		//查找尾节点
		Node* p = head_;
		while (p->next_ != nullptr)
		{
			p = p->next_;
		}
		//连接插入节点与尾节点
		p->next_ = node;
		node->pre_ = p;
	}
	//打印链表
	void Show() const
	{
		Node* p = head_->next_;
		while (p != nullptr)
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
		while (p != nullptr)//循环查找需删除节点
		{
			if (p->data_ == val)//找到
			{
				//删除 p 指向的节点
				p->pre_->next_ = p->next_;
				if (p->next_ != nullptr)//判断后一节点是否为空
				{
					p->next_->pre_ = p->pre_;
				}
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
		while (p != nullptr)
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
//双向链表 2026.1.31
	//特点：
		//每一个节点除了数据域，还有next指针域指向下一个节点，pre指针域指向前一个节点
		//头节点的pre是NULL，末尾节点的next是NULL
	DoubleLink dlink;
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