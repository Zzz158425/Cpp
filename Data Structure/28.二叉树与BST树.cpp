#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
#include<list>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include "md5.h"
#include<cmath>
using namespace std;

/*
void test_isChildTree();//判断二叉树子树问题
//BST 树算法实现 2026.3.14
template<typename T,typename Comp = less<T>>
class BSTree
{
public:
	//初始化根节点和函数对象 + lambda 表达式
	BSTree(Comp comp = Comp()) 
		: root_(nullptr)
		, comp_(comp) {}
	//层序遍历思想释放 BST 树所有节点资源
	~BSTree()
	{
		if (root_ != nullptr)
		{
			queue<Node*> s;
			s.push(root_);
			while (!s.empty())
			{
				Node* front = s.front();
				s.pop();
				if (front->left_ != nullptr)
				{
					s.push(front->left_);
				}
				if (front->right_ != nullptr)
				{
					s.push(front->right_);
				}
				delete front;
			}
		}
	}
public:
	//非递归插入操作
	void n_insert(const T& val)
	{
		//树为空生成根节点
		if (root_ == nullptr)
		{
			root_ = new Node(val);
			return;
		}
		//搜索合适的插入位置
		Node* parent = nullptr;//记录插入节点的父节点
		Node* cur = root_;//从根节点开始找
		while (cur != nullptr)
		{
			if (cur->data_ == val)
			{
				return;//不插入元素相同的值
			}
			else if (comp_(cur->data_, val))//cur->data_ < val
			{
				parent = cur;
				cur = cur->right_;
			}
			else//cur->data_ > val
			{
				parent = cur;
				cur = cur->left_;
			}
		}
		//把新节点插入到 parent 节点的孩子上
		if (comp_(val, parent->data_))//cur->data_ > val
		{
			parent->left_ = new Node(val);
		}
		else
		{
			parent->right_ = new Node(val);
		}
	}
	//非递归删除操作
	void n_remove(const T& val)
	{
		//树空直接结束
		if (root_ == nullptr)
		{
			return;
		}
		//搜索待删除节点
		Node* parent = nullptr;
		Node* cur = root_;
		while (cur != nullptr)
		{
			if (cur->data_ == val)
			{
				break;//找到待删除节点
			}
			else if (comp_(cur->data_, val))
			{
				parent = cur;
				cur = cur->right_;
			}
			else
			{
				parent = cur;
				cur = cur->left_;
			}
		}
		if (cur == nullptr)
		{
			return;//未找到待删除节点
		}
		//删除的节点有两个孩子节点
		if (cur->left_ != nullptr && cur->right_ != nullptr)
		{
			parent = cur;
			Node* pre = cur->left_;
			while (pre->right_ != nullptr)
			{
				parent = pre;
				pre = pre->right_;
			}
			cur->data_ = pre->data_;
			cur = pre;//让 cur 指向前驱节点（需删除节点），转化为没有或只有一个孩子的情况，后续进行统一处理
		}
		//统一处理 cur 指向的节点，没有或只有一个孩子的情况
		Node* child = cur->left_;
		if (child == nullptr)
		{
			child = cur->right_;
		}
		if (parent == nullptr)//特殊情况，删除的是根节点
		{
			root_ = child;
		}
		else
		{
			//把待删除节点的孩子（nullptr 或不空）写入其父节点相应对峙域中
			if (parent->left_ == cur)
			{
				parent->left_ = child;//绕过 cur ，将 parent 直接指向 cur 的孩子节点达到删除 cur 的操作
			}
			else
			{
				parent->right_ = child;
			}
		}
		delete cur;//删除当前节点
	}
	//非递归查询操作
	bool n_query(const T& val)
	{
		Node* cur = root_;
		while (cur != nullptr)
		{
			if (cur->data_ == val)
			{
				return true;
			}
			else if (comp_(cur->data_, val))
			{
				cur = cur->right_;
			}
			else
			{
				cur = cur->left_;
			}
		}
		return false;
	}
	//非递归前序遍历
	void n_preOrder()
	{
		cout << "非递归前序遍历：";
		if (root_ == nullptr)
		{
			return;
		}
		stack<Node*> s;
		s.push(root_);
		while (!s.empty())
		{
			Node* top = s.top();
			s.pop();
			cout << top->data_ << " ";//V
			if (top->right_ != nullptr)
			{
				s.push(top->right_);//R
			}
			if (top->left_ != nullptr)
			{
				s.push(top->left_);//L
			}
		}
		cout << endl;
	}
	//非递归中序遍历
	void n_inOrder()
	{
		cout << "非递归中序遍历：";
		if (root_ == nullptr)
		{
			return;
		}
		stack<Node*> s;
		Node* cur = root_;
		while (!s.empty() || cur != nullptr)
		{
			if (cur != nullptr)
			{
				s.push(cur);
				cur = cur->left_;
			}
			else
			{
				Node* top = s.top();
				s.pop();
				cout << top->data_ << " ";
				cur = top->right_;
			}
		}
		cout << endl;
	}
	//非递归后序遍历
	void n_postOrder()
	{
		cout << "非递归后序遍历：";
		if (root_ == nullptr)
		{
			return;
		}
		stack<Node*> s1;
		stack<Node*> s2;
		s1.push(root_);
		while (!s1.empty())//LRV -> VRL
		{
			Node* top = s1.top();
			s1.pop();
			s2.push(top);//V
			if (top->left_ != nullptr)
			{
				s1.push(top->left_);//L
			}
			if (top->right_ != nullptr)
			{
				s1.push(top->right_);//R
			}
		}
		while (!s2.empty())
		{
			cout << s2.top()->data_ << " ";
			s2.pop();
		}
		cout << endl;
	}
	//非递归层序遍历
	void n_levelOrder()
	{
		cout << "非递归层序遍历：";
		if (root_ == nullptr)
		{
			return;
		}
		queue<Node*> que;
		que.push(root_);
		while (!que.empty())
		{
			Node* front = que.front();
			que.pop();
			cout << front->data_ << " ";
			if (front->left_ != nullptr)
			{
				que.push(front->left_);
			}
			if (front->right_ != nullptr)
			{
				que.push(front->right_);
			}
		}
		cout << endl;
	}
	//递归插入操作
	void insert(const T& val)
	{
		root_ = insert(root_, val);
	}
	//递归删除操作
	void remove(const T& val)
	{
		root_ = remove(root_, val);
	}
	//递归查询操作
	bool query(const T& val)
	{
		return nullptr != query(root_, val);
	}
	//递归前序遍历接口
	void preOrder()
	{
		cout << "递归前序遍历：";
		preOrder(root_);
		cout << endl;
	}
	//递归中序遍历接口
	void inOrder()
	{
		cout << "递归中序遍历：";
		inOrder(root_);
		cout << endl;
	}
	//递归后序遍历接口
	void postOrder()
	{
		cout << "递归后序遍历：";
		postOrder(root_);
		cout << endl;
	}
	//递归求二叉树层数接口
	int high()
	{
		return high(root_);
	}
	//递归求二叉树节点个数接口
	int number()
	{
		return number(root_);
	}
	//递归层序遍历接口
	void levelOrder()
	{
		cout << "递归层序遍历：";
		int h = high();//有多少层就进行多少次递归遍历
		for (int i = 0; i < h; i++)
		{
			levelOrder(root_, i);//递归调用树的层数次
		}
		cout << endl;
	}
	//递归求满足区间的元素值[i, j]接口
	void findValues(vector<T>& vec, int i, int j)
	{
		findValues(root_, vec, i, j);
	}
	//递归判断二叉树是否是 BST 树接口
	bool isBSTree()
	{
		Node* pre = nullptr;
		return isBSTree(root_, pre);
	}
	//递归判断子树问题接口
	bool isChildTree(BSTree<T, Comp>& child)
	{
		//在当前二叉树上找 child 的根节点
		if (child.root_ == nullptr)
		{
			return true;
		}
		Node* cur = root_;
		while (cur != nullptr)
		{
			if (cur->data_ == child.root_->data_)
			{
				break;
			}
			else if (comp_(cur->data_, child.root_->data_))
			{
				cur = cur->right_;
			}
			else
			{
				cur = cur->left_;
			}
		}
		if (cur == nullptr)
		{
			return false;
		}
		return isChildTree(cur, child.root_);//cur 当前树的起始节点，child.root_ 判断子树的根节点
	}
	//递归求 LCA 最近公共祖先节点问题接口
	int getLCA(int val1, int val2)
	{
		Node *node = getLCA(root_, val1, val2);
		if (node == nullptr)
		{
			throw " no LCA!";
		}
		else
		{
			return node->data_;
		}
	}
	//递归求二叉树树镜像翻转问题接口
	void mirror_reverse()
	{
		mirror_reverse(root_);
	}
	//递归求二叉树树镜像对称问题接口
	bool mirror_symmetry()
	{
		if (root_ == nullptr)
		{
			return true;
		}
		return mirror_symmetry(root_->left_, root_->right_);
	}
	//递归重建二叉树问题接口
	void rebuild(int pre[], int i, int j, int in[], int m, int n)
	{
		root_ = _rebuild(pre, i, j, in, m, n);
	}
	//递归判断平衡树问题接口
	bool isBalance()
	{
		return isBalance(root_);
	}
	bool quickisBalance()
	{
		int l = 0;
		bool flag = true;//判断是否失衡
		quickisBalance(root_, l, flag);
		return flag;
	}
	//求中序遍历倒数第 K 个节点问题接口
	int getVal(int k)
	{
		Node* node = getVal(root_, k);
		if (node == nullptr)
		{
			string err = "no NO.";
			err += k;
		}
		else
		{
			return node->data_;
		}
	}
private:
	//节点定义
	struct Node
	{
		Node(T data = T())//T()	零构造，编译器内置类型就是 0，指针类型就是 nullptr，对于自定义类型就是调用默认构造
			: data_(data)
			, left_(nullptr)
			, right_(nullptr)
		{
		}
		T data_;//数据域
		Node* left_;//左孩子域
		Node* right_;//右孩子域
	};
	//递归插入操作实现
	Node* insert(Node* node, const T& val)
	{
		if (node == nullptr)
		{
			return new Node(val);//递归结束，找到插入 val 的位置，生成新节点并返回其节点地址
		}
		if (node->data_ == val)
		{
			return node;//不插入相同元素
		}
		else if (comp_(node->data_, val))
		{
			node->right_ = insert(node->right_, val);
			return node;
		}
		else
		{
			node->left_ = insert(node->left_, val);
			return node;
		}
	}
	//递归查询操作实现
	Node* query(Node* node, const T& val)
	{
		if (node == nullptr)
		{
			return nullptr;
		}
		if (node->data_ == val)
		{
			return node;
		}
		else if (comp_(node->data_, val))
		{
			return query(node->right_, val);
		}
		else
		{
			return query(node->left_, val);
		}
	}
	//递归删除操作实现
	Node* remove(Node* node, const T& val)
	{
		if (node == nullptr)
		{
			return nullptr;
		}
		if (node->data_ == val)//找到待删除节点
		{
			//删除的节点有两个孩子节点的情况
			if (node->left_ != nullptr && node->right_ != nullptr)
			{
				Node* pre = node->left_;
				while (pre->right_ != nullptr)
				{
					pre = pre->right_;
				}
				node->data_ = pre->data_;
				node->left_ = remove(node->left_, pre->data_);//通过递归直接删除前驱节点
			}
			else
			{
				if (node->left_ != nullptr)
				{
					//删除节点以后，把非空的做孩子返回，回溯时更新其父节点地址域
					Node* left = node->left_;
					delete node;
					return left;
				}
				else if (node->right_ != nullptr)
				{
					Node* right = node->right_;
					delete node;
					return right;
				}
				//删除的是没有孩子的叶子节点
				else
				{
					
					delete node;
					return nullptr;
				}
			}

		}
		else if (comp_(node->data_, val))
		{
			node->right_ = remove(node->right_, val);
		}
		else
		{
			node->left_ = remove(node->left_, val);
		}
		return node;//把当前节点返回给父节点，更新父节点相应的地址域
	}
	//递归前序变量实现
	void preOrder(Node* node)
	{
		if (node != nullptr)
		{
			cout << node->data_ << " ";//V
			preOrder(node->left_);//L
			preOrder(node->right_);//R
		}
	}
	//递归中序变量实现
	void inOrder(Node* node)
	{
		if (node != nullptr)
		{
			inOrder(node->left_);//L
			cout << node->data_ << " ";//V
			inOrder(node->right_);//R
		}
	}
	//递归后序变量实现
	void postOrder(Node* node)
	{
		if (node != nullptr)
		{
			postOrder(node->left_);//L
			postOrder(node->right_);//R
			cout << node->data_ << " ";//V
		}
	}
	//递归求二叉树层数实现
	int high(Node* node)
	{
		if (node == nullptr)
		{
			return 0;
		}
		//求以 node 为根节点的子树的高度并返回高度值
		int left = high(node->left_);//L
		int right = high(node->right_);//R
		return left > right ? left + 1 : right + 1;//V
	}
	//递归求二叉树节点个数实现
	int number(Node* node)
	{
		if (node == nullptr)
		{
			return 0;
		}
		//求以 node 为根节点的树的节点总数并返回
		int left = number(node->left_);//L
		int right = number(node->right_);//R
		return left + right + 1;//V
	}
	//递归层序变量实现
	void levelOrder(Node* node, int i)
	{
		if (node == nullptr)
		{
			return;
		}
		if (i == 0)
		{
			cout << node->data_ << " ";//打印对应层数的节点
			return;
		}
		levelOrder(node->left_, i - 1);
		levelOrder(node->right_, i - 1);

	}
	//递归求满足区间的元素值[i, j]实现
	void findValues(Node* node, vector<T>& vec, int i, int j)
	{
		if (node != nullptr)
		{
			//当前节点大于 i 才在其左子树进行搜索
			if (node->data_ > i)
			{
				findValues(node->left_, vec, i, j);//L
			}
			//V
			if (node->data_ >=i && node->data_ <= j)
			{
				vec.push_back(node->data_);
			}
			//当前节点小于 j 才在其右子树进行搜索
			if (node->data_ < j)
			{
				findValues(node->right_, vec, i, j);//R
			}
			
		}
	}
	//递归判断二叉树是否是 BST 树实现
	bool isBSTree(Node* node, Node*& pre)//pre 引用传递，如果不用引用，每个递归调用会创建 pre 的副本，上层 pre 不受影响
	{
		//错误，只关心的局部是否满足 BST 树
		//if (node == nullptr)
		//{
		//	return true;
		//}
		//if (node->left_ != nullptr && comp_(node->data_, node->left_->data_));
		//{
		//	return false;
		//}
		//if (node->right_ != nullptr && !comp_(node->data_, node->right_->data_));
		//{
		//	return false;
		//}
		//isBSTree(node->left_);
		//isBSTree(node->right_);
		if (node == nullptr)
		{
			return true;
		}
		if (!isBSTree(node->left_, pre))//L
		{
			return false;
		}
		//V
		if (pre != nullptr)
		{
			if (comp_(node->data_, pre->data_))//不满足 BST 树提前结束递归
			{
				return false;
			}
		}
		pre = node;//更新中序遍历的前一节点
		return isBSTree(node->right_, pre);//R
	}
	//递归判断子树问题实现
	bool isChildTree(Node* father, Node* child)
	{
		if (father == nullptr && child == nullptr)
		{
			return true;
		}
		if (father == nullptr)//子树里面有的节点，当前二叉树没有
		{
			return false;
		}
		if (child == nullptr)
		{
			return true;
		}
		//判断值不相同
		if (father->data_ != child->data_)//V
		{
			return false;
		}
		return isChildTree(father->left_, child->left_)//L
			&& isChildTree(father->right_, child->right_);//R
	}
	//递归求 LCA 最近公共祖先节点问题实现
	Node* getLCA(Node* node, int val1, int val2)
	{
		if (node == nullptr)
		{
			return nullptr;
		}
		if (comp_(node->data_, val1) && comp_(node->data_, val2))
		{
			return getLCA(node->right_, val1, val2);
		}
		else if (comp_(val1, node->data_) && comp_(val2, node->data_))
		{
			return getLCA(node->left_, val1, val2);
		}
		else
		{
			return node;
		}

	}
	//递归求二叉树树镜像翻转问题实现
	void mirror_reverse(Node* node)
	{
		if (node == nullptr)
		{
			return;
		}
		//V
		Node* temp = node->left_;
		node->left_ = node->right_;
		node->right_ = temp;
		mirror_reverse(node->left_);//L
		mirror_reverse(node->right_);//R
	}
	//递归求二叉树树镜像对称问题实现
	bool mirror_symmetry(Node* node1, Node* node2)
	{
		if (node1 == nullptr && node2 == nullptr)
		{
			return true;
		}
		if (node1 == nullptr || node2 == nullptr)
		{
			return false;
		}
		if (node1->data_ != node2->data_)
		{
			return false;
		}
		return mirror_symmetry(node1->left_, node2->right_)
			&& mirror_symmetry(node1->right_, node2->left_);
	}
	//递归重建二叉树问题实现
	Node* _rebuild(int pre[], int i, int j, int in[], int m, int n)
	{
		if (i > j || m > n)
		{
			return nullptr;
		}
		//创建当前子树的根节点
		Node* node = new Node(pre[i]);//拿前序的第一个数字创建子树的根节点
		for (int k = m; k <= n; k++)
		{
			if (in[k] == pre[i])//在中序遍历中找子树根节点的下标 k
			{
				node->left_ = _rebuild(pre, i + 1, i + (k - m), in, m, k - 1);
				node->right_ = _rebuild(pre, i + (k - m) + 1, j, in, k + 1, n);
				return node;
			}
		}
		return node;
	}
	//递归判断平衡树问题实现
	bool isBalance(Node* node)
	{
		if (node == nullptr)
		{
			return true;
		}
		if (!isBalance(node->left_))//L
		{
			return false;
		}
		if (!isBalance(node->right_))//R
		{
			return false;
		}
		//每个节点均进行了高度计算，效率低
		int left = high(node->left_);
		int right = high(node->right_);
		return abs(left - right) <= 1;//V，abs 计算一个数的绝对值
	}
	int quickisBalance(Node* node, int l, bool& flag)
	{
		//在递归过程中记录了节点高度值，效率高
		if (node == nullptr)
		{
			return l;
		}
		int left = quickisBalance(node->left_, l + 1, flag);//L
		if (!flag)//判断失衡直接退出，不再判断
		{
			return left;
		}
		int right = quickisBalance(node->right_, l + 1, flag);//R
		if (!flag)//判断失衡直接退出，不再判断
		{
			return right;
		}
		if (abs(left - right) > 1 )//节点失衡
		{
			flag = false;
		}
		return left > right ? left : right;//V 返回高度值大的
	}
	//递归求中序遍历倒数第 K 个节点
	int i = 1;//记录遍历个数
	Node* getVal(Node* node, int k)//const int& i 才能接收常量表达式
	{
		if (node == nullptr)
		{
			return nullptr;
		}
		Node* right = getVal(node->right_, k);//R
		if (right != nullptr)
		{
			return right;
		}
		//V
		if (i++ == k)
		{
			return node;
		}
		return getVal(node->left_, k);//L
	}
	Node* root_;//指向 BST 树根节点
	Comp comp_;//定义一个函数对象 
	friend void test_isChildTree();
	friend void test_mirror_symmetry();
	friend void test_rebuild();
};

//判断二叉树子树问题
void test_isChildTree()
{
	int ar[] = { 58,24,67,0,34,62,69,5,41,64,78 };
	BSTree<int> bst;
	for (int v : ar)
	{
		bst.insert(v);
	}
	using Node = BSTree<int>::Node;
	BSTree<int> bst1;
	bst1.root_ = new Node(67);
	Node* node1 = new Node(62);
	Node* node2 = new Node(69);
	Node* node3 = new Node(30);
	bst1.root_->left_ = node1;
	bst1.root_->right_ = node2;
	node1->left_ = node3;
	cout << bst.isChildTree(bst1) << endl;
}

//二叉树镜像对称问题
void test_mirror_symmetry()
{
	using Node = BSTree<int>::Node;
	BSTree<int> bst;
	bst.root_ = new Node(40);
	Node* node1 = new Node(20);
	Node* node2 = new Node(20);
	Node* node3 = new Node(10);
	Node* node4 = new Node(15);
	Node* node5 = new Node(15);
	Node* node6 = new Node(10);
	bst.root_->left_ = node1;
	bst.root_->right_ = node2;
	node1->left_ = node3;
	node1->right_ = node4;
	node2->left_ = node5;
	node2->right_ = node6;
	cout << bst.mirror_symmetry() << endl;
}

//前序遍历与中序遍历重建二叉树问题
void test_rebuild()
{
	BSTree<int> bst;
	int pre[] = { 58,24,0,5 ,34 ,41, 67 ,62 ,64 ,69 ,78 };
	int in[] = { 0, 5, 24, 34 ,41 ,58, 62 ,64 ,67, 69, 78 };
	bst.rebuild(pre, 0, 10, in, 0, 10);
	bst.postOrder();
	bst.inOrder();
}

//判断二叉树是否是平衡树
void test_isBalance()
{
	int ar[] = { 58,24,67,0,34,62,69,5,41,64,78 };
	BSTree<int> bst;
	for (int v : ar)
	{
		bst.insert(v);
	}
	cout << bst.isBalance() << " ";
	bst.insert(12);
	cout << bst.isBalance() << endl;
	bst.remove(12);
	cout << bst.quickisBalance() << " ";
	bst.insert(12);
	cout << bst.quickisBalance() << endl;
}

//求中序遍历倒数第 K 个节点
void test_getVal()
{
	int ar[] = { 58,24,67,0,34,62,69,5,41,64,78 };
	BSTree<int> bst;
	for (int v : ar)
	{
		bst.insert(v);
	}
	cout << bst.isBalance() << " ";
	bst.insert(12);
	cout << bst.isBalance() << endl;
	bst.inOrder();
	cout << bst.getVal(2) << endl;
}

int main()
{
//二叉树与 BST 树基础理论 2026.3.13
	//二叉树基础概念：
		//以 0 5 24 34 41 58 62 64 67 69 78 序列为例
		//     58（根节点）
		//    /       \
		//   24       67
		// /   \    /   \
		//0    34  62   69
		// \    \   \     \
		//  5   41  64    78
		//根节点、左孩子、右孩子、兄弟节点、叶子节点、
		//叔叔节点：爷节点的另一个孩子节点；双亲节点：父节点；祖先节点：父节点、爷节点
		//左子树：根节点的左边所有节点；右子树：根节点的右边所有节点
		//层数 L 与每层元素最大个数 n 的关系：n = 2^(L - 1)
		//层数 L 与元素个数 N 的关系：2^0 +2^1 + ... + 2^(L - 1) = N = 2^L - 1 -> L = log(N)
	//对于二叉树上的每一个节点，如果满足左孩子的值 < 父节点的值 < 右孩子的值的二叉树称为 BST(Binary Search/Sort Tree) 树
	//二叉树遍历：V（当前节点）L（当前节点左孩子）R（当前节点右孩子），规定 L 出现在 R 之前 
		//前序遍历：VLR，在每一个节点上都是以 VLR 的方式访问节点，58 24 0 5 34 41 67 62 64 69 78
		//中序遍历：LVR，在每一个节点上都是以 LVR 的方式访问节点，0 5 24 34 41 58 62 64 67 69 78
		//后序遍历：LRV，在每一个节点上都是以 LRV 的方式访问节点，5 0 41 34 24 64 62 78 69 67 58
		//递归遍历：void func(Node *node) { if(node != nullptr) { func(node->left_);func(node->right_); } }
		//层序遍历：广度与深度遍历，58 24 67 0 34 62 69 5 41 64 78
	//BST 树非递归插入：root 指针指向根节点
		//BST 如果为空，root 指针会指向新生成的节点
		//BST 如果不为空，从根节点进行比较，找到合适的位置，生成新的节点，并把节点的地址写入父节点相应的地址域中
	//BST 树非递归删除：
		//没有孩子的节点，父节点地址域置 nullptr
		//有一个孩子节点，孩子写入父节点地址域
		//有二个孩子节点，找待删除的前驱节点（或者后续节点），用前驱或后继节点的值把待删除节点的值覆盖掉，然后直接删除前驱或后继节点就可以了
		//前驱节点：当前节点左子树中值最大的节点，后继节点：当前节点右子树中值最小的节点
		//前驱节点或者后继节点，最多有一个孩子，或没有孩子

//BST 树算法实现 2026.3.14
	int ar[] = { 58,24,67,0,34,62,69,5,41,64,78 };
	BSTree<int> bst;
	for (int v : ar)
	{
		//bst.n_insert(v);
		bst.insert(v);
	}
	bst.preOrder();
	bst.n_preOrder();
	bst.inOrder();
	bst.n_inOrder();
	bst.postOrder();
	bst.n_postOrder();
	bst.levelOrder();
	bst.n_levelOrder();
	cout << bst.high() << endl;
	cout << bst.number() << endl;
	bst.n_insert(12);
	bst.n_remove(12);
	bst.n_remove(34);
	cout << bst.n_query(58) << endl;
	bst.n_remove(58);
	cout << bst.n_query(58) << endl;
	bst.n_insert(12);
	cout << bst.query(12) << endl;
	bst.n_remove(12);
	cout << bst.query(12) << endl;
	bst.inOrder();
	bst.remove(0);
	bst.inOrder();

//BST树区间元素搜索问题
	//利用中序遍历提取区间元素，因为中序遍历是升序遍历
	vector<int>vec;
	bst.findValues(vec, 10, 60);
	for (int v : vec)
	{
		cout << v << " ";
	}
	cout << endl;

//判断一棵二叉树是否是 BST 树问题
	//不能只判断局部（只关心节点与节点的左右孩子）是否是 BST 树，否则会错误判断下列非 BST 树
	//   40
	//20    60
	//    30   80
	//利用 BST 树中序遍历是升序的一个特点，前一个节点的值一定小于后一个节点的值
	cout << bst.isBSTree() << endl;

//判断二叉树子树问题
	test_isChildTree();

//求 LCA 最近公共祖先节点问题
	cout << bst.getLCA(24,67) << endl;

//二叉树镜像翻转问题
	bst.inOrder();
	bst.mirror_reverse();
	bst.inOrder();

//二叉树镜像对称问题
	test_mirror_symmetry();

//前序遍历与中序遍历重建二叉树问题
	//VLR:58（根节点 i） 24（左子树根节点 i + 1） 0 5 34 41（i + (k - m)） 67（i + (k - m) + 1） 62 64 69 78（j）
	//LVR:0（m） 5 24 34 41 58（k） 62（k + 1） 64 67 69 78（n）
	test_rebuild();

//判断二叉树是否是平衡树问题
	//平衡：任意节点的左右子树高度差，不超过 1
	//以下树为例：0 左右子树高度差超过了 1 ，此树不是平衡树
		//               58（根节点）
		//         24               67
		//    0        34     62         69
		//       5        41    64          78
		//         12
	test_isBalance();

//求中序遍历倒数第 K 个节点问题
	//LVR 倒数第 K 个节点 -> RVL 正数第 K 个节点
	test_getVal();

//BST 树的构造与析构
	//层序遍历思想释放 BST 树所有节点资源
	//初始化根节点和函数对象 + lambda 表达式
	using Elm = pair<int, string>;
	using Functor = function<bool(pair<int, string>, pair<int, string>)>;
	BSTree<Elm, Functor>bst([](Elm p1, Elm p2)->bool {
		return p1.first > p2.first;
		});

	system("pause");
	return 0;
}
*/