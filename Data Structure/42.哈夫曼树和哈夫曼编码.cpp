#include<iostream>
#include<stdlib.h>
#include<functional>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
//using unit = unsigned int;

/*
//哈夫曼树和哈夫曼编码实现 2026.4.17
class HuffmanTree
{
public:
	HuffmanTree()
		: minHeap_([](Node* n1, Node* n2)->bool {return n1->weight_ > n2->weight_; })
		, root_(nullptr)
	{ }
	~HuffmanTree()
	{
		if (root_ == nullptr)
		{
			return;
		}
		queue<Node*> q;
		q.push(root_);
		while (!q.empty())
		{
			Node* temp = q.front();
			q.pop();
			if (temp->left_ != nullptr)
			{
				q.push(temp->left_);
			}
			if (temp->right_ != nullptr)
			{
				q.push(temp->right_);
			}	
			delete temp;
		}
	}
	//创建哈夫曼树
	void create(string str)
	{
		//先统计字符的权值
		unordered_map<char, unit> dataMap;
		for (char ch : str)
		{
			dataMap[ch]++;
		}
		//生成节点，放入小根堆中
		for (auto& pair : dataMap)
		{
			minHeap_.push(new Node(pair.first, pair.second));
		}
		while (minHeap_.size() > 1)
		{
			//获取两个权值最小的
			Node* n1 = minHeap_.top();
			minHeap_.pop();
			Node* n2 = minHeap_.top();
			minHeap_.pop();
			//生成父节点
			Node* node = new Node('\0', n1->weight_ + n2->weight_);
			node->left_ = n1;
			node->right_ = n2;
			minHeap_.push(node);//把生成的父节点放回小根堆中
		}
		root_ = minHeap_.top();
	}
	//递归前序遍历输出哈夫曼编码接口
	void getHuffmanTreeCode()
	{
		string code;
		getHuffmanTreeCode(root_, code);
		//显示每个字符的哈夫曼编码
		//for (auto& pair : codeMap_)
		//{
		//	cout << pair.first << ":" << pair.second << endl;
		//}
		//cout << endl;
	}
	//编码
	string encode(string str)
	{
		getHuffmanTreeCode();
		string encode_str;
		for (char ch : str)
		{
			encode_str.append(codeMap_[ch]);
		}
		return encode_str;
	}
	//解码
	string decode(string encode)
	{
		string decode_str;
		Node* cur = root_;
		for (char ch : encode)
		{
			if (ch == '0')
			{
				cur = cur->left_;
			}
			else
			{
				cur = cur->right_;
			}
			if (cur->left_ == nullptr && cur->right_ == nullptr)
			{
				decode_str.push_back(cur->data_);
				cur = root_;
			}
		}
		return decode_str;
	}
private:
	struct Node
	{
		Node(char data, unit weight)
			: data_(data)
			, weight_(weight)
			, left_(nullptr)
			, right_(nullptr)
		{ }
		char data_;//字符数据
		unit weight_;//节点的权值
		Node* left_;//指向左孩子节点
		Node* right_;//指向右孩子节点
	};
	Node* root_;//指向根节点
	unordered_map<char, string> codeMap_;//存储字符对应的哈夫曼编码
	using MinHeap = priority_queue<Node*, vector<Node*>, function<bool(Node*, Node*)>>;
	MinHeap minHeap_;
	//递归前序遍历输出哈夫曼编码实现
	void getHuffmanTreeCode(Node* root, string code)
	{
		//VLR
		if (root->left_ == nullptr && root->right_ == nullptr)
		{
			codeMap_[root->data_] = code;
			return;
		}
		getHuffmanTreeCode(root->left_, code + "0");
		getHuffmanTreeCode(root->right_, code + "1");
	}
};

int main()
{
//哈夫曼树和哈夫曼编码
	//哈夫曼树又称为最佳判定树、最优二叉树和哈夫曼树，是一种带权路径长度最短的二叉树，常用于数据压缩：统计数据的出现频率（权值），出现频率高的（权值大）期望编码短一些；出现频率小的（权值小）期望编码的长度长一些
	//所谓树的带权路径长度，就是树中所有的叶子节点的权值乘以其到根节点的路径长度
	//因此树的带权路径长度记为 WPL = (W1 * L1 + W2 * L2 + W3 * L3 + ... + Wn * Ln)，N 个权值 Wi(i = 1, 2, ..., n) 构成一颗有 N 个叶子节点的二叉树，相应的叶子节点的路径的长度是 Li(i = 1, 2, ..., n)
	//构建哈夫曼树：
		//1.从权值里面选取两个最小的权值，构建一颗二叉树（生成的父节点的权值是两个孩子节点的权值只和）
		//2.再把当前生成的二叉树的根节点权值，放入原始的权值列表中，继续重复 1 的步骤，直到取值列表中知剩下一个节点
	//以一组权值 2 4 2 6 8 10 为例
		//4 6 8 10       6 8 10          8 10           -                        -
		//   4     --->    8     --->     14     --->   14         18 --->       32
		// /   \        /     \        /      \      /      \    /    \      0/      \1
		//2     2      4       4      8        6    8        6  8      10   14        18
 		//		     /   \          /   \         /   \                  0/    \1  0/    \1
		//          2     2        4     4       4     4                 8      6  8      10
		//                       /   \         /   \                  0/   \1
		//                      2     2       2     2                 4     4
		//                                                         0/   \1
		//                                                         2     2
	//应用场景：
		//哈夫曼编码：为给定的字符集合构建二进制编码，使得编码的期望长度达到最短
		//哈夫曼编码不同于 ASCII 和 Unicode 这些字符编码，这些字符集中的码长都采用的是长度相同的编码方案
		//而哈夫曼编码使用的是变长编码，而且哈夫曼编码满足立刻可解码性（就是说任一字符的编码都不会是另一个更长字符编码的前缀）
		//这样当一个字符的编码中的位被接收时，可以立即进行解码而无须等待之后的位来决定是否存在另一个合法的更长的编码
		//立刻可解码性：
			//不满足立刻可解码性（B 与 D 不满足）     满足立刻可解码性
			//A             01                     A             01
			//B           1000                     B           1000
			//C           1010                     C           1001
			//D            100                     D            001
			//E              0                     E              1  
	//以 ABACDAEFDEG 为例
		//1.统计字符的出现频率（权值），也可以用比值（合理即可）
			//A:3,B:1,C:1,D:2,E:2,F:1,G:1  
		//2.构建哈夫曼树      
			//                   11                    A:01
			//             0/          \1              B:0000
			//             7            4              C:0001
			// 	      0/       \1   0/      \1   --->  D:10	    ---> ABACDAEFDEG(11 byte):010000010001100111001010110011(4 byte)
			//        4        A:3  D:2    E:2         E:11
			//   0/       \1                           F:0010
			//   2         2                           G:0011
			//0/   \1   0/   \1
			//B:1 C:1   F:1 G:1
	//过小的文件压缩后文件大小不一定会减小，因为在压缩文件中不仅会存储原始文件的字节数据，还会存储权值以用于解压缩


//哈夫曼树和哈夫曼编码实现 2026.4.17
	string str = "ABACDAEFDEGFDGDFHFDGFDGERTDGFDGDSGSGFDGDFGJKHJK";
	HuffmanTree htree;
	htree.create(str);
	string encode = htree.encode(str);
	cout << "Encode:" << encode << endl;
	cout << "Decode:" << htree.decode(encode) << endl;

	system("pause");
	return 0;
}
*/





