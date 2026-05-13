#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
using namespace std;

/*
//单向链表
//节点类型
struct Node
{
	Node(int data = 0) : data_(data), next_(nullptr) {};
	int data_;
	Node* next_;
};
class Clink
{
public:
	Clink()
	{
		head_ = new Node();//给 head_ 初始化指向头节点
	}
	~Clink()
	{
		//节点释放
		Node* p = head_;
		while (p != nullptr)
		{
			head_= head_->next_;
			delete p;
			p = head_;

		}
		head_ = nullptr;
	}
public:
	//链表尾插法 O(n)
	void InsertTail(int val)
	{
		//先找到当前链表的末尾节点
		Node* p = head_;
		while (p->next_ != nullptr)
		{
			p = p->next_;
		}
		Node* node = new Node(val);//生成新节点
		p->next_ = node;//把新节点挂在尾节点的后面
	}
	//链表头插法 O(1)
	void InsertHead(int val)
	{
		Node* node = new Node(val);//生成新节点
		node->next_ = head_->next_;//将头节点的地址域（指向插入前第一个节点）赋给新节点的地址域
		head_->next_ = node;//将新节点的地址赋给头节点的地址域
	}
	//链表节点的删除
	void Remove(int val)
	{
		Node* q = head_;//头节点
		Node* p = head_->next_;//第一个节点
		while (p != nullptr)
		{
			if (p->data_ == val)
			{
				q->next_ = p->next_;
				delete p;//释放删除节点所占内存
				return;
			}
			else
			{
				q = q->next_;
				p = p->next_;
			}
		}

	}
	//单向链表删除多个节点
	void RemoveAll(int val)
	{
		Node* q = head_;//头节点
		Node* p = head_->next_;//第一个节点
		while (p != nullptr)
		{
			if (p->data_ == val)
			{
				q->next_ = p->next_;
				delete p;//释放删除节点所占内存
				//对指针 p 进行重置
				p = q->next_;
			}
			else
			{
				q = q->next_;
				p = p->next_;
			}
		}
	}
	//单向链表搜索 O(n)
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
	//链表打印
	void Show()
	{
		Node* p = head_->next_;//第一个节点
		while (p != nullptr)//找尾节点才使用 p->next_ != nullptr，不然会漏判
		{
			cout << p->data_ << " ";
			p = p->next_;
		}
		cout << endl;
	}
private:
	Node* head_;//指向链表的头节点
	friend void ReverseLink(Clink& link);//定义友元以访问私有元素
	friend bool GetLastKNode(Clink& link, int k, int& val);
	friend void MergeLink(Clink& link1, Clink& link2);
};

//单向链表逆序问题 2026.1.26
void ReverseLink(Clink &link)
{
	Node* head = link.head_;//方便后续调用
	Node* p = head->next_;//第一个节点
	if (p == nullptr)//判断是否为空链表
	{
		return;
	}
	head->next_ = nullptr;//将头指针置空分离链表
	while (p != nullptr)
	{
		Node* q = p->next_;//q 记录 p 的下一个节点
		//p 指针指向的节点进行头插
		p->next_ = head->next_;
		head->next_ = p;
		p = q;//重置 p
	}
	
}

//单链表求倒数第 K 个节点
bool GetLastKNode(Clink& link, int k, int& val)
{
	Node* head = link.head_;
	Node* p = head;
	Node* pre = head;
	//防止 K 为 0 使程序出错
	if (k < 1)
	{
		return false;
	}
	//先让 p 移动到第 K 个节点
	for (int i = 0; i < k; i++)
	{
		p = p->next_;
		if (p == nullptr)
		{
			return false;
		}
	}
	//pre 在头节点，p 在整数第 K 个节点
	while (p != nullptr)
	{
		p = p->next_;
		pre = pre->next_;
	}
	val = pre->data_;
	return true;
}

//合并两个有序单链表 2026.1.27
void MergeLink(Clink& link1, Clink& link2)
{
	Node* p = link1.head_->next_;//指向链表 1 第 1 个节点
	Node* q = link2.head_->next_;//指向链表 2 第 1 个节点
	Node* last = link1.head_;//指向链表 1 第 1 个节点（根据要求）
	link2.head_->next_ = nullptr;//断开链表 2 头节点
	while (p != nullptr && q != nullptr)//判断短的一条链表是否比较完成
	{
		if (p->data_ > q->data_)//判断链表 1 的值是否大于链表 2 的值
		{
			last->next_ = q;//将 last 指针指向数据小的链表 
			last = last->next_;//last 指针跟随从小到大节点移动
			q = q->next_;//移动 q 指向 链表 2 下一个节点
		}
		else//反之
		{
			last->next_ = p;
			last = last->next_;
			p = p->next_;
		}
	}
	if (q == nullptr)//链表 2 判断完成
	{
		last->next_ = p;//将剩余链表 1 接在后面
	}
	else//反之
	{
		last->next_ = q;
	}
}

//判断单链表是否存在环以及入口节点
bool IsLinkHasCircle(Node* head, int& val)
{
	Node* fast = head;//快指针
	Node* slow = head;//慢指针
	while (fast != nullptr && fast->next_ != nullptr)
	{
		slow = slow->next_;//慢指针走 1 步
		fast = fast->next_->next_;//快指针走 2 步
		if (slow == fast)//快慢指针相遇
		{
			fast= head;//重置 fast 指针
			while (fast != slow)//快慢指针同步走，等待再次相遇即为入口节点
			{
				slow = slow->next_;
				fast = fast->next_;
			}
			val = slow->data_;
			return true;
		}
	}
	return false;
}

//判断两个链表是否相交 2026.1.28
bool IsLinkHasMerge(Node* head1, Node* head2, int& val)
{
	int cnt1 = 0, cnt2 = 0;//计数各链表长度
	Node* p = head1->next_;
	Node* q = head2->next_;
	//计数链表 1 长度
	while (p != nullptr)
	{
		cnt1++;
		p = p->next_;
	}
	//计数链表 2 长度
	while (q != nullptr)
	{
		cnt2++;
		q = q->next_;
	}
	p = head1;//计算长度后 p 指针为空，需重新设置
	q = head2;//计算长度后 q 指针为空，需重新设置
	if (cnt1 > cnt2)//链表 1 长度大于链表 2
	{
		int offset = cnt1 - cnt2;//链表长度差值
		//长链表先走 offset 步
		for (int i = 0; i < offset; i++)
		{
			p = p->next_;
		}
	}
	else//同理
	{
		int offset = cnt2 - cnt1;
		for (int i = 0; i < offset; i++)
		{
			q = q->next_;
		}
	}
	while (p != nullptr && q != nullptr)
	{
		if (p == q)//判断是否存在相同节点
		{
			val = p->data_;
			return true;
		}
		p = p->next_;
		q = q->next_;
	}
	return false;//两相交链表不想交
}

//删除链表的倒数第 N 个节点 2026.1.29
struct Node* removeNthFromEnd(struct Node* head, int n)
{
	//该链表无头节点，人为加上头节点方便操作
	Node head_;
	head_.next_ = head;
	Node* p = &head_;//指向人为添加的头节点
	Node* q = &head_;//指向人为添加的头节点
	//先让 p 走到整数第 N 个节点
	for (int i = 0; i < n; i++)
	{
		if (p == nullptr)//判断 n 是否大于了链表长度
		{
			return head;
		}
		p = p->next_;
	}
	//指针 q 与 p 同步走
	while (p->next_ != nullptr)
	{
		q = q->next_;
		p = p->next_;
	}
	p = q->next_;//记录删除节点
	q->next_ = q->next_->next_;//让需删除的上一节点指向需删除的下一节点
	p = nullptr;
	return head_.next_;
}

//旋转链表
Node* rotateRight(Node* head, int k)
{
	Node* p = head;
	Node* q = head;
	int number = 0;
	//异常情况检测
	if (head == nullptr || k == 0)
	{
		return head;
	}
	//统计链表长度
	for (Node *k = head; k != nullptr; k = k->next_)
	{
		number++;
	}
	k = k % number;//对 k 取模，算出应该右移的步数
	//p 指针先移动 k 步
	for (int i = 0; i < k; i++)
	{
		p = p->next_;
	}
	//p 与 q 指针同时移动 k 步
	while (p->next_ != nullptr)
	{
		p = p->next_;
		q = q->next_;
	}
	p->next_ = head;//将末尾节点与头节点相接
	head = q->next_;//将头节点接入第一个节点
	q->next_ = nullptr;//将移动后的最后一个节点置空作末尾节点
	return head;
}




int main()
{
//链表讲解 2026.1.24
	//内存碎片化会使开辟大内存数组时容易失败
	//特点：每一个节点都是在堆内存上独立 new 出来的，节点内存不连续，从当前节点能够找到下一个节点，最后一个节点的地址域是 nullptr
	//优点：
		//内存利用率高，不需要大块连续内存
		//插入和删除节点不需要移动其它节点，时间复杂度 O(1)
		//不需要专门进行扩容操作
	//缺点：
		//内存占用量大，每一个节点多出存放地址的空间
		//节点内存不连续，无法进行内存随机访问
		//链表搜索效率不高，只能从头节点开始逐节点遍历
//单向链表尾插法
	//单向链表特点：
		//每一个节点除了数据域，还有一个 next 指针域指向下一个节点(存储了下一个节点的地址)，但是无法回退到前一个节点
		//末尾节点的指针域是 NULL
	
//单向链表头插法 2026.1.25
	Clink linkTail;
	Clink linkHead;
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		int val = rand() % 100;
		linkTail.InsertTail(val);
		cout << val << " ";
	}
	cout << endl;
	linkTail.Show();
	for (int i = 0; i < 10; i++)
	{
		int val = rand() % 100;
		linkHead.InsertHead(val);
		cout << val << " ";
	}
	cout << endl;
	linkHead.Show();

//单向链表删除节点
	//删除操作本身时间复杂度 O(1)，但是搜索应该删除节点时间复杂度 O(n)
	linkHead.InsertTail(200);
	linkHead.Show();
	linkHead.Remove(200);
	linkHead.Show();

//单向链表删除多个节点
	linkHead.InsertTail(200);
	linkHead.InsertTail(200);
	linkHead.InsertTail(200);
	linkHead.Show();
	linkHead.RemoveAll(200);
	linkHead.Show();

//单向链表搜索与总结
	//数组：适用于下标访问/随机访问多、搜索多
	//链表：适用于增加、删除多
	linkHead.InsertTail(200);
	cout << linkHead.Find(200) << endl;
	linkHead.RemoveAll(200);

//单向链表逆序问题 2026.1.26
	//头节点与剩余节点分离，对头节点进行头插
	Clink linkReverse;
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		int val = rand() % 100;
		linkReverse.InsertHead(val);
		cout << val << " ";
	}
	cout << endl;
	linkReverse.Show();
	ReverseLink(linkReverse);
	linkReverse.Show();

//单链表求倒数第 K 个节点
	//双指针，两指针从头节点出发，其中一指针先走 K 个后，两指针同时走
	int kval;
	int k = 3;
	if (GetLastKNode(linkReverse, k, kval))
	{
		cout << "倒数第 " << k << " 个节点的值：" << kval << endl;
	}

//合并两个有序单链表 2026.1.27
	//双指针，比较 q 指针与 p 指针所指链表所存数据大小，用 last 指针跟随移动
	int arr_MergeLink1[] = { 25, 37, 52, 78, 88, 92, 108 };
	int arr_MergeLink2[] = { 13, 23, 40, 56, 62, 77, 109 };
	Clink linkMergeLink1;
	Clink linkMergeLink2;
	for (int v: arr_MergeLink1)
	{
		linkMergeLink1.InsertTail(v);
	}
	for (int v : arr_MergeLink2)
	{
		linkMergeLink2.InsertTail(v);
	}
	MergeLink(linkMergeLink1, linkMergeLink2);
	linkMergeLink1.Show();

//判断单链表是否存在环以及入口节点
	//方法 1：额外开辟一个数组记录依次遍历的节点的地址值，在遍历一个节点后与之前存储的地址值进行遍历比较，若存在相同的地址，则说明有环，并且此节点为入口节点                                                   
	//方法 2：快慢指针，指针 fast/slow 每次移动 2/1 个节点，当两指针重合即说明有环，且 fast 遍历的节点数量 = 2 * slow 遍历的节点数量，可推出：起始节点到入口节点的距离 = 相遇节点到尾节点的距离，所以安排两个指针在头节点与相遇节点一起往后走再次相遇的节点即为头节点                                                                                                                                                                                                            
	Node linkIsLinkHasCircleHead;
	Node n1(25), n2(67), n3(32), n4(18);
	linkIsLinkHasCircleHead.next_ = &n1;
	n1.next_ = &n2;
	n2.next_ = &n3;
	n3.next_ = &n4;
	n4.next_ = &n2;
	int val_IsLinkHasCircle;
	if (IsLinkHasCircle(&linkIsLinkHasCircleHead, val_IsLinkHasCircle))
	{
		cout << "链表存在环，环的入口节点为：" << val_IsLinkHasCircle << endl;
	}
	else
	{
		cout << "链表不存在环 " << endl;
	}

//判断两个链表是否相交 2026.1.28
	//方法 1：遍历并记录链表 1 所有节点的地址，再依次遍历链表 2 节点地址并与之前记录的链表 1 的地址相比较，若出现相同则两个链表相交，且第一次重复的地址即为相交节点
	//方法 2：双指针，遍历链表 1 和 2，计算各链表长度并做差，让长链表先走差值步，再同步往后走，若走到某一节点时，地址值相同则两个链表相交，此节点为相交节点，反之，则不相交
	Node linkIsLinkHasMergeHead1;
	Node n5(25), n6(67), n7(32), n8(18);
	linkIsLinkHasMergeHead1.next_ = &n5;
	n5.next_ = &n6;
	n6.next_ = &n7;
	n7.next_ = &n8;
	Node linkIsLinkHasMergeHead2;
	Node n9(31), n10(10);
	linkIsLinkHasMergeHead2.next_ = &n9;
	n9.next_ = &n10;
	n10.next_ = &n6;
	int val_IsLinkHasMerge;
	if (IsLinkHasMerge(&linkIsLinkHasMergeHead1, &linkIsLinkHasMergeHead2, val_IsLinkHasMerge))
	{
		cout << "链表相交，相交节点为：" << val_IsLinkHasMerge << endl;
	}
	else
	{
		cout << "链表不相交 " << endl;
	}

//删除链表的倒数第 N 个节点（无不含数据的头节点） 2026.1.29
	//双指针，其中一指针先走 N 步，再同步走直到最后一个节点停止，查找倒数第 N + 1 个节点，再删除第 N 个节点
	Node linkremoveNthFromEnd(1), n12(2), n13(3), n14(4);
	linkremoveNthFromEnd.next_ = &n12;
	n12.next_ = &n13;
	n13.next_ = &n14;
	cout << n12.next_->data_ << endl;
	removeNthFromEnd(&linkremoveNthFromEnd,2);
	cout << n12.next_->data_ << endl;

//旋转链表（无不含数据的头节点）
	//描述：给你一个链表的头节点 head，旋转链表，将链表每个节点向右移动 k 个位置，输入：head = [1,2,3,4,5]，k = 2，输出：[4,5,1,2,3]
	//右移动 k 个位置即找到链表的倒数第 K 个节点，对其进行整体头插，原链表尾部接头节点，倒数第 K 个节点为头节点，倒数第 K+1 个节点作为尾部置空
	Node linkrotateRight(1), n15(2), n16(3), n17(4), n18(5);
	linkrotateRight.next_ = &n15;
	n15.next_ = &n16;
	n16.next_ = &n17;
	n17.next_ = &n18;
	cout << linkrotateRight.data_ 
		<< " " << linkrotateRight.next_->data_
		<< " " << linkrotateRight.next_->next_->data_ 
		<< " " << linkrotateRight.next_->next_->next_->data_
		<< " " << linkrotateRight.next_->next_->next_->next_->data_ << endl;
	rotateRight(&linkrotateRight, 2);
	cout << n17.data_
		<< " " << n17.next_->data_
		<< " " << n17.next_->next_->data_
		<< " " << n17.next_->next_->next_->data_
		<< " " << n17.next_->next_->next_->next_->data_ << endl;

	system("pause");
	return 0;
}
*/