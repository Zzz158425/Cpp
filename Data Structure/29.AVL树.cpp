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
//AVL 树算法实现
template<typename T>
class AVLTree
{
public:
	AVLTree() : root_(nullptr) { }
	~AVLTree()
	{
		if (root_ != nullptr)
		{
			queue<Node*> q;
			q.push(root_);
			while (!q.empty())
			{
				Node* front = q.front();
				if (front->left_ != nullptr)
				{
					q.push(front->left_);
				} 
				if (front->right_ != nullptr)
				{
					q.push(front->right_);
				}
				delete front;
			}
		}
	}
public:
	//递归插入操作接口
	void insert(const T& val)
	{
		root_ = insert(root_, val);
	}
	//递归删除操作接口
	void remove(const T& val)
	{
		root_ = remove(root_, val);
	}
private:
	struct  Node
	{
		Node(T data =T())
			: data_(data)
			, left_(nullptr)
			, right_(nullptr)
			,height_(1) { }
		T data_;
		Node* left_;
		Node* right_;
		int height_;//记录节点的高度值
	};
	//AVL 树的节点平衡算法实现
	//计算节点的高度值
	int height(Node* node)
	{
		return node == nullptr ? 0 : node->height_;
	}
	//右旋转操作，以参数 node 为轴做右旋转操作，并把新的根节点返回
	Node* rightRotate(Node* node)
	{
		//旋转操作
		Node* child = node->left_;
		node->left_ = child->right_;
		child->right_ = node;
		//高度更新
		node->height_ = max(height(node->left_), height(node->right_)) + 1;
		child->height_ = max(height(child->left_), height(child->right_)) + 1;
		return child;//返回旋转后的子树新的节点
	}
	//左旋转操作，以参数 node 为轴做左旋转操作，并把新的根节点返回
	Node* leftRotate(Node* node)
	{
		//旋转操作
		Node* child = node->right_;
		node->right_ = child->left_;
		child->left_ = node;
		//高度更新
		node->height_ = max(height(node->left_), height(node->right_)) + 1;
		child->height_ = max(height(child->left_), height(child->right_)) + 1;
		return child;//返回旋转后的子树新的节点
	}
	//左平衡操作，以参数 node 为轴做左-右旋转操作，并把新的根节点返回
	Node* leftBalance(Node* node)
	{
		node->left_ = leftRotate(node->left_);//以当前父节点为中心左旋转，将爷节点指向旋转后的根节点
		return rightRotate(node);//以当前爷节点为中心右旋转
	}
	//右平衡操作，以参数 node 为轴做右-左旋转操作，并把新的根节点返回
	Node* rightBalance(Node* node)
	{
		node->right_ = rightRotate(node->right_);//以当前父节点为中心右旋转，并将爷节点指向旋转后的根节点
		return leftRotate(node);//以当前爷节点为中心左旋转
	}
	//递归插入操作实现
	Node* insert(Node* node, const T& val)
	{
		if (node == nullptr)//找到插入位置
		{
			return new Node(val);
		}
		if (node->data_ > val)
		{
			node->left_ = insert(node->left_, val);
			//在递归回溯时判断节点是否失衡，node 的左子树太高，node 失衡了
			if (height(node->left_) - height(node->right_) > 1)
			{
				if (height(node->left_->left_) >= height(node->left_->right_))
				{
					//节点失衡，由于左孩子的左子树太高
					node = rightRotate(node);//右旋转操作，返回根节点
				}
				else
				{
					//节点失衡，由于左孩子的右子树太高
					node = leftBalance(node);//左平衡操作，返回根节点
				}
			}
		}
		else if (node->data_ < val)
		{
			node->right_ = insert(node->right_, val);
			//在递归回溯时判断节点是否失衡，node 的右子树太高，node 失衡了
			if (height(node->right_) - height(node->left_) > 1)
			{
				if (height(node->right_->right_) >= height(node->right_->left_))
				{
					//节点失衡，由于右孩子的右子树太高
					node = leftRotate(node);//左旋转操作，返回根节点
				}
				else
				{
					//节点失衡，由于右孩子的左子树太高
					node = rightBalance(node);//右平衡操作，返回根节点
				}
			}
		}
		else
		{
			;//空语句，不进行任何操作，找到相同节点，不再递归，直接向上回溯
		}
		//因为子树中增加了新的节点，在递归回溯时检测更新节点高度
		node->height_ = max(height(node->left_), height(node->right_)) + 1;
		return node;
	}
	//递归删除操作实现
	Node* remove(Node* node, const T& val)
	{
		if (node == nullptr)
		{
			return nullptr;
		}
		if (node->data_ > val)
		{
			node->left_ = remove(node->left_, val);
			if (height(node->right_) - height(node->left_) > 1)
			{
				//在递归回溯时判断节点是否失衡，node 的右子树太高，node 失衡了
				if (height(node->right_->right_) >= height(node->right_->left_))
				{
					//节点失衡，由于右孩子的右子树太高
					node = leftRotate(node);//左旋转操作，返回根节点
				}
				else
				{
					//节点失衡，由于右孩子的左子树太高
					node = rightBalance(node);//右平衡操作，返回根节点
				}
			}
		}
		else if (node->data_ < val)
		{
			node->right_ = remove(node->right_, val);
			if (height(node->left_) - height(node->right_) > 1)
			{
				//在递归回溯时判断节点是否失衡，node 的左子树太高，node 失衡了
				if (height(node->left_->left_) >= height(node->left_->right_))
				{
					//节点失衡，由于左孩子的左子树太高
					node = rightRotate(node);//右旋转操作，返回根节点
				}
				else
				{
					//节点失衡，由于左孩子的右子树太高
					node = leftBalance(node);//左平衡操作，返回根节点
				}
			}
		}
		else
		{
			//找到了，先处理有两个孩子的节点的情况，将其转换为只有一个孩子或无孩子的情况
			if (node->left_ != nullptr && node->right_ != nullptr)
			{
				//为了避免删除前驱或者后继节点造成节点失衡，谁高就删除谁
				if (height(node->left_) > height(node->right_))
				{
					//删除前驱节点
					Node* pre = node->left_;
					while (pre->right_ != nullptr)
					{
						pre = pre->right_;
					}
					node->data_ = pre->data_;
					node->left_ = remove(node->left_, pre->data_);
				}
				else
				{
					//删除后继节点
					Node* post = node->right_;
					while (post->left_ != nullptr)
					{
						post = post->left_;
					}
					node->data_ = post->data_;
					node->right_ = remove(node->right_, post->data_);
				}
			}
			else
			{
				//找到了，该节点只有一个孩子或无孩子
				if (node->left_ != nullptr)
				{
					//有左孩子
					Node* left = node->left_;
					delete node;
					return left;
				}
				else if (node->right_ != nullptr)
				{
					//有右孩子
					Node* right = node->right_;
					delete node;
					return right;
				}
				else
				{
					//无孩子
					delete node;
					return nullptr;
				}
			}
		}
		node->height_ = max(height(node->left_), height(node->right_)) + 1;//因为子树中增加了新的节点，在递归回溯时检测更新节点高度
		return node;//递归回溯过程中，把当前节点给父节点返回
	}
	Node* root_;//指向根节点
};

int main()
{
//AVL 树基础理论
	//二叉平衡搜索树：BST 树 + 节点平衡操作
	//平衡：任意节点的左右子树高度差，不超过 1
	//AVL 树为了维护节点平衡操作引入了四种节点旋转操作
	//AVL 树是绝对的平衡树，其增、删、查时间复杂度都是 O(logn)
	//节点失衡的原因：
		//1.左孩子的左子树太高了，应右旋转（右旋转操作）
			//      40 ----->     30
			//     /   右旋转     /  \
			//   30             20   40 
			//  /
			//20           
		//2.右孩子的右子树太高了，应左旋转（左旋转操作）
			//40       ----->     50
			//  \      左旋转    /   \
			//   50            40    60 
			//    \
			//     60 
		//3.左孩子的右子树太高了，应左（爷节点不动，以父节点为中心旋转）-右（以爷节点为中心旋转）旋转（左平衡操作）
			//   40 ----->     40 ----->     30
			//  /   左旋转      /  右旋转    /  \
			//20              30          20    40
			//  \           /
			//   30       20
		//4.右孩子的左子树太高了，应右（爷节点不动，以父节点为中心旋转）-左（以爷节点为中心旋转）旋转（右平衡操作）
			//40    -----> 40     ----->    50
			//  \   右旋转   \     左旋转   /  \
			//  60           50           40   60
			//  /             \
			//50               60 
	 
//AVL 树算法实现 2026.3.17
	AVLTree<int> avl;
	for (int i = 1; i <= 10; i++)
	{
		avl.insert(i);
	}
	avl.remove(9);
	avl.remove(10);
	avl.remove(6);
	avl.remove(1);
	avl.remove(2);
	avl.remove(3);

	system("pause");
	return 0;
}
*/