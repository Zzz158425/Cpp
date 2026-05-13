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
#include<cmath>
using namespace std;

/*
//红黑树算法实现
template<typename T>
class RBTree
{
public:
	RBTree() :root_(nullptr) { }
	~RBTree() { }
public:
	//非递归插入操作
	void insert(const T& val)
	{
		if (root_ == nullptr)
		{
			root_ = new Node(val);
			return;
		}
		Node* parent = nullptr;
		Node* cur = root_;
		while (cur != nullptr)
		{
			if (cur->data_ > val)
			{
				parent = cur;
				cur = cur->left_;
			}
			else if (cur->data_ < val)
			{
				parent = cur;
				cur = cur->right_;
			}
			else
			{
				return;//不插入重复的值
			}
		}
		Node* node = new Node(val, parent, nullptr, nullptr, RED);
		if (parent->data_ > val)
		{
			parent->left_ = node;
		}
		else
		{
			parent->right_ = node;
		}
		//如果新插入的红色节点，父节点也是红色，不满足红黑树性质，进行插入调整操作
		if (RED == color(parent))
		{
			fixAfterInsert(node);
		}
	}
	//非递归删除操作
	void remove(const T& val)
	{
		if (root_ == nullptr)
		{
			return;
		}
		Node* cur = root_;
		while (cur != nullptr)
		{
			if (cur->data_ > val)
			{
				cur = cur->left_;
			}
			else if (cur->data_ < val)
			{
				cur = cur->right_;
			}
			else
			{
				break;
			}
		}
		//没有找到需删除的节点
		if (cur == nullptr)
		{
			return;
		}
		//找到了需删除的节点，但有两个孩子节点，转化为只有一个或无孩子的情况
		if (cur->left_ != nullptr && cur->right_ != nullptr)
		{
			Node* pre = cur->left_;
			while (pre->right_ != nullptr)
			{
				pre = pre->right_;
			}
			cur->data_ = pre->data_;
			cur = pre;//cur 指向前驱节点
		}
		Node* child = cur->left_;
		if (child == nullptr)
		{
			child = cur->right_;
		}
		//被删节点有一个孩子
		if (child != nullptr)
		{
			child->parent_ = cur->parent_;
			if (cur->parent_ == nullptr)//cur 为根节点，根节点被删了
			{
				root_ = child;
			}
			else
			{
				if (cur->parent_->left_ == cur)//cur 在其父节点左侧
				{
					cur->parent_->left_ = child;
				}
				else//cur 在其父节点右侧
				{
					cur->parent_->right_ = child;
				}
			}
			Color c = color(cur);
			delete cur;
			if (c == BLACK)
			{
				fixAfterRemove(child);//删除的是黑色节点，要进行删除调整操作
			}
		}
		//被删节点无孩子
		else
		{
			//被删节点为根节点
			if (cur->parent_ == nullptr)
			{
				delete cur;
				root_ = nullptr;
				return;
			}
			//删除的节点为叶子节点
			else
			{
				if (color(cur) == BLACK)
				{
					fixAfterRemove(cur);//删除的是黑色节点，要进行删除调整操作，不急于删除 cur 节点，删除 cur 以后无节点递补上来
				}
				//先调整后删节点
				if (cur->parent_-> left_ == cur)
				{
					cur->parent_->left_ = nullptr;
				}
				else
				{
					cur->parent_->right_ = nullptr;
				}
				delete cur;
			}
		}
	}
private:
	//节点颜色
	enum Color
	{
		BLACK,
		RED
	};
	//节点类型
	struct Node
	{
		Node(T data = T(), Node* parent = nullptr
			, Node* left = nullptr, Node* right = nullptr
			, Color color = BLACK)
			: data_(data)
			, left_(left)
			, right_(right)
			, parent_(parent)
			, color_(color) { }
		T data_;
		Node* left_;
		Node* right_;
		Node* parent_;//指向当前节点的父节点
		Color color_;//节点的颜色
	};
	//获取节点颜色
	Color color(Node* node) 
	{
		return node == nullptr ? BLACK : node->color_;
	}
	//设置节点颜色
	void setColor(Node* node, Color color)
	{
		node->color_ = color;
	}
	//返回节点的左孩子节点
	Node* left(Node* node)
	{
		return node->left_;
	}
	//返回节点的右孩子节点
	Node* right(Node* node)
	{
		return node->right_;
	}
	//返回节点的父节点
	Node* parent(Node* node)
	{
		return node->parent_;
	}
	//左旋转
	void leftRotate(Node* node)
	{
		Node* child = node->right_;
		child->parent_ = node->parent_;
		//node 本身就是 root 节点
		if (node->parent_ == nullptr)
		{
			root_ = child;
		}
		//node 不是 root 节点
		else
		{
			if (node->parent_->left_ == node)
			{
				node->parent_->left_ = child;//node 在父节点的左孩子
			}
			else
			{
				node->parent_->right_ = child;//node 在父节点的右孩子
			}
		}
		node->right_ = child->left_;
		//child 左孩子不为 nullptr，修改 parent_
		if (child->left_ != nullptr)
		{
			child->left_->parent_ = node;
		}
		child->left_ = node;
		node->parent_ = child;
	}
	//右旋转
	void rightRotate(Node* node)
	{
		Node* child = node->left_;
		child->parent_ = node->parent_;
		//node 本身就是 root 节点
		if (node->parent_ == nullptr)
		{
			root_ = child;
		}
		//node 不是 root 节点
		else
		{
			if (node->parent_->left_ == node)
			{
				node->parent_->left_ = child;//node 在父节点的左孩子
			}
			else
			{
				node->parent_->right_ = child;//node 在父节点的右孩子
			}
		}
		node->left_ = child->right_;
		//child 右孩子不为 nullptr，修改 parent_
		if (child->right_ != nullptr)
		{
			child->right_->parent_ = node;
		}
		child->right_ = node;
		node->parent_ = child;
	}
	//红黑树的插入调整操作
	void fixAfterInsert(Node* node)
	{
		//如果当前红色节点鄂父节点也是红色，继续调整
		while (color(parent(node)) == RED)
		{
			if (left(parent(parent(node))) == parent(node))//爷节点的左孩子是当前节点的父亲
			{
				//插入的节点在左子树当中
				Node* uncle = right(parent(parent(node)));
				//情况 1
				if(RED == color(uncle))
				{
					setColor(parent(node), BLACK);
					setColor(uncle, BLACK);
					setColor(parent(parent(node)), RED);
					node = parent(parent(node));//有可能爷节点的父亲节点是红色，继续调整
				}
				else
				{
					//先处理情况 3
					if (right(parent(node)) == node)
					{
						node = parent(node);//防止情况 3 转为情况 2 之后 node 指向不一样
						leftRotate(node);
					}
					//统一处理情况 2
					setColor(parent(node), BLACK);
					setColor(parent(parent(node)), RED);
					rightRotate(parent(parent(node)));
					break;//调整完成
				}
			}
			else
			{
				//插入的节点在右子树当中
				Node* uncle = left(parent(parent(node)));
				//情况 1
				if (RED == color(uncle))
				{
					setColor(parent(node), BLACK);
					setColor(uncle, BLACK);
					setColor(parent(parent(node)), RED);
					node = parent(parent(node));//有可能爷节点的父亲节点是红色，继续调整
				}
				else
				{
					//先处理情况 3
					if (left(parent(node)) == node)
					{
						node = parent(node);//防止情况 3 转为情况 2 之后 node 指向不一样
						rightRotate(node);
					}
					//统一处理情况 2
					setColor(parent(node), BLACK);
					setColor(parent(parent(node)), RED);
					leftRotate(parent(parent(node)));
					break;//调整完成
				}
			}
		}
		setColor(root_, BLACK);//防止 parent 为根节点时被调整为红色
	}
	//红黑树的删除调整操作
	void fixAfterRemove(Node* node)
	{
		while (node != root_ && color(node) == BLACK)//node 为根节点就不用再调整了
		{
			//删除的黑色节点在左子树
			if (left(parent(node)) == node)
			{
				Node* brother = right(parent(node));
				//先处理情况 4
				if (color(brother) == RED)
				{
					setColor(parent(node), RED);
					setColor(brother, BLACK);
					leftRotate(parent(node));
					brother = right(parent(node));
				}
				//处理情况 3
				if (color(left(brother)) == BLACK
					&& color(right(brother)) == BLACK)
				{
					setColor(brother, RED);
					node = parent(node);//继续调整，直到找到红色节点
				}
				//处理情况 2
				else
				{
					if (color(right(brother)) != RED)
					{
						setColor(brother, RED);
						setColor(left(brother), BLACK);
						rightRotate(brother);
						brother = right(parent(node));
					}
				//处理情况 1
					setColor(brother, color(parent(node)));
					setColor(parent(node), BLACK);
					setColor(right(brother), BLACK);
					leftRotate(parent(node));
					break;
				}
			}
			//删除的黑色节点在右子树
			else
			{
				Node* brother = left(parent(node));
				//先处理情况 4
				if (color(brother) == RED)
				{
					setColor(parent(node), RED);
					setColor(brother, BLACK);
					rightRotate(parent(node));
					brother = left(parent(node));
				}
				//处理情况 3
				if (color(left(brother)) == BLACK
					&& color(right(brother)) == BLACK)
				{
					setColor(brother, RED);
					node = parent(node);//继续调整，直到找到红色节点
				}
				//处理情况 2
				else
				{
					if (color(left(brother)) != RED)
					{
						setColor(brother, RED);
						setColor(right(brother), BLACK);
						leftRotate(brother);
						brother = left(parent(node));
					}
					//处理情况 1
					setColor(brother, color(parent(node)));
					setColor(parent(node), BLACK);
					setColor(left(brother), BLACK);
					rightRotate(parent(node));
					break;
				}
			}
		}
		setColor(node, BLACK);//补上来的孩子是红色节点，直接把孩子涂成黑色，调整完成
	}
	Node* root_;//指向红黑树的根节点
};

int main()
{
//红黑树与 AVL 树
	//AVL 树：在BST树的基础上，引入了节点平衡的概念，任意一个节点的左右子树高度差不超过 1，为了维持节点的平衡，引入了四种旋转操作
		//1.左孩子左子树太高，做右旋转操作
		//2.右孩子的右子树太高，做左旋转操作
		//3.左孩子的右子树太高，做左 - 右旋转操作（也叫左平衡）
		//4.右孩子的左子树太高，做右 - 左旋转操作（也叫右平衡）
	//红黑树：不是一颗平衡树，节点的左右子树高度差，长的不超过短的 2 倍
		//1.树的每一个节点都有颜色，不是红色就是黑色
		//2.所有叶子节点都是黑色的，叶子节点是 NULL 节点，不存储实际的数据
		//3.根节点必须是黑色
		//4.每个红色节点必须有两个黑色的节点，即从每个叶子节点到根节点的所有路径上不能出现连续的红色节点
		//5.从根节点到每一个叶子节点的路径上，黑色节点的数量是相同的
	//操作                 AVL        红黑树
	//平衡树               是         否
	//增删查时间复杂度      O(logn)    O(logn)
	//insert 最多旋转次数   2          2
	//remove 最多旋转次数   O(logn)    3
	//红黑树插入操作
		//红黑树为空，插入黑色根节点
		//红黑树不为空，插入红色叶子节点（黑色会改变红黑树性质），检查父节点颜色，父节点为红色，开始做红黑树的插入调整
			//情况 1:  A(b)               A(r)                       
			//        /  \               /   \
			//     B(r)   D(r) -----> B(b)   D(b) 1.A(b->r),B(r->b),D(r->b)
			//     /                   /
			//  C(r)                C(r)
			//情况 2:  A(b)               B(b)                        
			//        /   \               /  \
			//     B(r)   D(b) -----> C(r)   A(r)  1.A(b->r),B(r->b)              
			//      /                          \   2.以 A 为中心右旋转
			//  C(r)                             D(b) 
			//情况 3:  A(b)   转为情况 2  A(b)              B(b)      
			//        /  \               /  \              /   \
			//     B(r)   D(b) -----> C(b)   D(B) -----> C(r)   A(r)   1.以 B 为中心左旋转
			//        \                /                          \    2.执行情况 2 处理
			//        C(r)         B(b)                            D(b) 
	//红黑树旋转操作          
		//情况 1: 80                        80
		//       /  \                     /   \
		//   40(n)  120 -------------> 60(c)  120 
		//  /   \       对 40 进行左旋  /   \
		//20    60(c)               40(n)  70
		//     /  \                 /  \
		//    50  70               20   50
		//情况 2:80                          80
		//      /  \                        /  \
		//     40  120(n)  -------------> 40   100(c)
		//         /    \  对 120 进行右旋      /  \
		//      100(c)  140                   90  120(n)
		//       /  \                             /  \
		//      90  110                          110  140
	//红黑树删除操作
		//删除一个节点有两种情况：
			//有两个孩子的节点：转化为无孩子节点或一个孩子节点情况
			//无孩子节点或一个孩子节点：删除前驱节点
		//删除一个红色节点：无影响，就是一个 BST 树节点的删除，不用做任何删除调整操作
		//删除一个黑色节点：
			//1.补上来的孩子是红色节点，直接把孩子涂成黑色，调整完成
			//2.补上来的孩子是黑色节点，只能从兄弟借调黑色节点
				//情况 1:   A(b/r)           C(b/r)
				//         /  \             /   \       1.C(b->b/r),A(b/r->b)
				//B(b/delete)  C(b) -----> A(b)  D(b)   2.以 A 为中心左旋转
				//              \                  \    3.D(r->b)
				//               D(r)               E(b)4.删除节点在左边，保证兄弟右孩子为红色
				//                \                     5.删除节点在右边，保证兄弟左孩子为红色
				//                 E(b) 
				//
				//情况 2:   A(b/r)           A(b/r)
				//         /  \             /   \                1.以 C 为中心右旋转
				//B(b/delete)  C(b) -----> B(b)  D(b) -----> ... 2.D(r->b),C(b->r)，转化为情况 1
				//            /   \               \              3.按照情况 1 进行处理
				//           D(r) E(b)             C(r)          
				//                                  \
				//                                   E(b) 
				// 
				//情况 3:   A(b)             D(b)<-node
				//         /  \             /   \        1.C(b->r)
				//B(b/delete)  C(b) -----> A(b)  C(r)    2.node 向上回溯，发现指向的第一个红色节点，直接把红色节点涂成黑色，调整结束
				//            /   \               \      3.向上回溯的过程中 node 指向的还是黑色节点，继续重复 2 步骤
				//           D(b) E(b)             E(b)                  
				//
				//情况 4:   A(b)             C(b)
				//         /  \             /   \                1.A(b->r),C(r->b)
				//B(b/delete)  C(r) -----> A(r)  E(b) -----> ... 2.以 A 为中心左旋转，转化为上述 3 种情况
				//            /   \       /  \                   3.按照上述 3 种情况进行处理
				//           D(b) E(b)  B(b)  E(b)    
				              
//红黑树算法实现 2026.3.18
	RBTree<int> rb;
	for (int i = 1; i <= 10; i++)
	{
		rb.insert(i);
	}
	rb.remove(9);
	rb.remove(10);
	rb.remove(5);
	rb.remove(3);

	system("pause");
	return 0; 
}
*/