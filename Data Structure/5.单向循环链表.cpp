#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
using namespace std;

/*
//单向循环链表 2026.1.29	
class CircleLink
{
public:
	CircleLink()
	{
		head_ = new Node();
		tail_ = head_;
		head_->next_ = head_;
	}
	~CircleLink()
	{
		Node* p = head_->next_;
		while (p != head_)                     
		{
			head_->next_ = p->next_;//头节点指向下下个节点
			delete p;
			p = head_->next_;//重置 p 指针
		}
		delete head_;
	}
public:
	//尾插法 O(1)
	void InsertTail(int val)
	{
		Node* node = new Node(val);
		tail_->next_ = node;
		node->next_ = head_;//也可以 node->next_ = tail_>next_;
		tail_ = node;//更新 tail 指针指向新的尾节点
	}
	//头插法 O(1)
	void InsertHead(int val)
	{
		Node* node = new Node(val);
		node->next_ = head_->next_;
		head_->next_ = node;
		if (node->next_ == head_)//判断是否是空链表插入第一个节点，此时新插入的节点会变成尾节点
		{
			tail_ = node;//更新 tail 指针指向新的尾节点
		}
	}
	//删除节点
	void Remove(int val)
	{
		Node* p = head_->next_;//指向第 1 个节点
		Node* q = head_; //指向头节点
		while (p != head_)//遍历链表查找
		{
			if (p->data_ == val)//找到
			{
				q->next_ = p->next_;
				delete p;
				if (q->next_ == head_)
				{
					tail_ = q;
				}
				return;
			}
			else//未找到，继续遍历
			{
				p = p->next_;
				q = q->next_;
			}
		}
	}
	//查询
	bool Find(int val) const//为了安全，只读不写的方法均加上 const
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
private:
	//创建节点
	struct Node
	{
		Node(int data = 0) :data_(data), next_(nullptr) {}
		int data_;
		Node* next_;
	};
	Node* head_;//指向头节点
	Node* tail_;//指向尾节点
};

//约瑟夫环问题 2026.1.30	
//无头节点单向循环链表
struct Node
{
	Node(int data = 0) :data_(data), next_(nullptr) {}
	int data_;
	Node* next_;
};
void Joseph(Node* head, int k, int m)
{
	Node* p = head;
	Node* q = head;
	//q 指针指向最后一个节点
	while (q->next_ != head)
	{
		q = q->next_;
	}
	//从第 k 个人开始报数
	for (int i = 1; i < k; i++)
	{
		q = p;
		p = p->next_;
	}
	for (;;)//死循环
	{
		//找到第 m 节点与前节点
		for (int i = 1; i < m; i++)
		{
			q = p;
			p = p->next_;
		}
		cout << p->data_ << " ";
		//出列第 m 个人，删除 p 指向的节点
		if (p == q)//判断是否只剩最后一个节点了，最后一个节点 p 与 q 会指向同一节点
		{
			delete p;
			break;
		}
		q->next_ = p->next_;
		delete p;
		p = q->next_;
	}
	




}



int main()
{
//单向循环链表 2026.1.29	
	//特点：
		//每一个节点除了数据域，还有一个 next 指针域指向下一个节点(存储了下一个节点的地址)
		//末尾节点的指针域指向了头节点
	CircleLink clink;
	srand(time(NULL));
	clink.InsertHead(100);
	for (int i = 0; i < 10; i++)
	{
		clink.InsertTail(rand() % 100);
	}
	clink.InsertTail(200);
	clink.Show();
	clink.Remove(200);
	clink.Show();
	clink.InsertTail(300);
	clink.Show();

//约瑟夫环问题（无头节点）
	//描述：约瑟夫环是一个数学的应用问题：已知 n 个人（以编号1，2，3...n分别表示）围坐在一张圆桌周围，从编号为 k 的人开始报数，数到 m 的那个人出列，它的下一个人又从 1 开始报数，数到 m 的那个人又出列，依此规律重复下去，直到圆桌周围的人全部出列，输出人的出列顺序
	//双指针，先让双指针走到 k 个人的位置，再一前一后走到需要出列的人的位置，删除需出列的节点，以此往复，直到双指针指向同一节点，意味着只剩 1 个未出列，直接出列即可
	Node* head = new Node(1);
	Node* n2 = new Node(2);
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);
	Node* n5 = new Node(5);
	Node* n6 = new Node(6);
	Node* n7 = new Node(7);
	Node* n8 = new Node(8);
	head->next_ = n2;
	n2->next_ = n3;
	n3->next_ = n4;
	n4->next_ = n5;
	n5->next_ = n6;
	n6->next_ = n7;
	n7->next_ = n8;
	n8->next_ = head;
	Joseph(head, 1, 5);
	cout << endl;

	system("pause");
	return 0;
}
*/