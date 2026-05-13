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
//Trie 字典树算法实现
class TrieTree
{
public:
	TrieTree()
	{
		root_ = new TrieNode('\0', 0);
	}
	~TrieTree()
	{
		queue<TrieNode*> que;
		que.push(root_);
		while (!que.empty())
		{
			TrieNode* front = que.front();
			que.pop();
			//把当前节点的孩子节点全部入队列
			for (auto& pair : front->nodeMap_)
			{
				que.push(pair.second);
			}
			delete front;//释放当前节点资源
		}
	}
public:
	//添加单词
	void add(const string& word)
	{
		TrieNode* cur = root_;
		for (int i = 0; i < word.size(); i++)
		{
			auto childIt = cur->nodeMap_.find(word[i]);
			if (childIt == cur->nodeMap_.end())
			{
				//无相应的字符节点，创建
				TrieNode* child = new TrieNode(word[i], 0);
				cur->nodeMap_.emplace(word[i], child);
				cur = child;
			}
			else
			{
				//有相应的字符节点，移动 cur 指向对应的字符节点
				cur = childIt->second;
			}
		}
		//cur 指向了 word 单词的最后一个节点
		cur->freqs_++;
	}
	//查询单词
	int query(const string& word)
	{
		TrieNode* cur = root_;
		for (int i = 0; i < word.size(); i++)
		{
			auto childIt = cur->nodeMap_.find(word[i]);
			if (childIt == cur->nodeMap_.end())
			{
				return 0;
			}
			//移动 cur 指向下一个单词的字符节点上
			cur = childIt->second;
		}
		return cur->freqs_;
	}
	//递归前序遍历字典树
	void preOrder()
	{
		string word;
		vector<string> wordList;
		preOrder(root_, word, wordList);;
		for (auto word : wordList)
		{
			cout << word << endl;
		}
	}
	//串的前缀搜索
	vector<string> queryPrefix(const string& prefix)
	{
		TrieNode* cur = root_;
		for (int i = 0; i < prefix.size(); i++)
		{
			auto childIt = cur->nodeMap_.find(prefix[i]);
			if (childIt == cur->nodeMap_.end())
			{
				return {};//vector<string> vec{};
			}
			cur = childIt->second;
		}
		//cur 就指向了前缀的最后一个字符节点了
		vector<string> wordlist;
		preOrder(cur, prefix.substr(0, prefix.size() - 1), wordlist);
		return wordlist;
	}
	//删除单词
	void remove(const string& word)
	{
		TrieNode* cur = root_;
		TrieNode* del = root_;
		char delch = word[0];
		for (int i = 0; i < word.size(); i++)
		{
			auto childTt = cur->nodeMap_.find(word[i]);
			if (childTt == cur->nodeMap_.end())
			{
				return;
			}
			if (cur->freqs_ > 0 || cur->nodeMap_.size() > 1)
			{
				del = cur;
				delch = word[i];
			}
			cur = childTt->second;//移动到子节点
		}
		//word 单词存在，cur 指向了末尾字符节点
		if (cur->nodeMap_.empty())
		{
			//开始删除
			TrieNode* child = del->nodeMap_[delch];
			del->nodeMap_.erase(delch);
			//释放相应的节点内存
			queue<TrieNode*> que;
			que.push(child);
			while (!que.empty())
			{
				TrieNode* front = que.front();
				que.pop();
				for (auto& pair : front->nodeMap_)
				{
					que.push(pair.second);
				}
				delete front;
			}
		}
		else
		{
			cur->freqs_ = 0;//当前单词末尾字符节点后面还有字符节点，不做任何节点删除操作
		}
		
	}
private:
	//节点类型定义
	struct TrieNode
	{
		TrieNode(char ch, int freqs)
			: ch_(ch)
			, freqs_(freqs)
		{ }
		char ch_;//节点存储的字符数据
		int freqs_;//单词的末尾字符存储单词的数量（频率）
		map<char, TrieNode*> nodeMap_;//存储孩子节点字符数据和节点指针的对应关系
	};
	TrieNode* root_;//指向树的根节点
	//递归前序遍历字典树
	void preOrder(TrieNode* cur, string word, vector<string>& wordList)
	{
		//前序遍历 VLR
		if (cur != root_)//V
		{
			word.push_back(cur->ch_);//cur 不为根节点才记录
			if (cur->freqs_ > 0)
			{
				wordList.emplace_back(word);//已经遍历到一个有效的单词
			}
		}
		//递归处理孩子节点 LR
		for (auto pair : cur->nodeMap_)
		{
			preOrder(pair.second, word, wordList);
		}
	}
};

int main()
{
//Trie 树（字典树、前缀树、单词查找树）算法思想
	//基本性质：
		//1.根节点不包含字符，除根节点外每一个节点都只包含一个字符
		//2.从根节点到某一结点，路径上经过的字符连接起来，为该节点对应的字符串
		//3.每个节点的所有子节点包含的字符都不相同
	//适用范围：
		//1.单词检索
		//2.统计和排序字符串
		//3.字符串前缀检索
	//算法核心：利用字符串的公共前缀来减少查询时间，最大限度的减少无畏的字符串比较
	//复杂度：搜索的时间复杂度 O(m)，m 表示串的长度
	//以 pool、prize、preview、prepare、produce、progress 为例
		//            root
		//             |
		//             p
		//   /                   \
		// o                      r
		// |               /      |      \
		// o               i      e       o
		// |               |     / \     / \
		// l               z    p   v   d   g
		//pool             |    |   |   |   |
		//                 e    a   i   u   r
		//               prize  |   |   |   |
		//                      r   e   c   e
		//                      |   |   |   |
		//                      e   w   e   s
		//         prepare priview produce  |
		//                                  s
		//                           progress

//Trie 树算法实现
	//串排序应用：
		//给定 N 个互不相同的仅由一个单词构成的英文名，让你将他们按字典序从小到大输出，用字典树进行排序
		//这棵树的每个节点的所有儿子很明显地按照其字母大小排序，对这棵树进行前序遍历即可
	//空间换时间：对于有比较多的公共前缀，处理效率高，否则内存占用量比较大
	TrieTree trie;
	trie.add("hello");
	trie.add("hello");
	trie.add("hellooo");
	trie.add("hel");
	trie.add("hel");
	trie.add("hel");
	trie.add("china");
	trie.add("ch");
	trie.add("ch");
	trie.add("heword");
	trie.add("hellw");
	cout << trie.query("china") << endl;
	cout << trie.query("hello") << endl;
	cout << trie.query("hellooo") << endl;
	trie.preOrder();
	vector<string> words =  trie.queryPrefix("he");
	for (auto word : words)
	{
		cout << word << endl;
	}
	trie.remove("he");
	cout << trie.query("he") << endl;
	trie.remove("hel");
	cout << trie.query("hel") << endl;
	words = trie.queryPrefix("hel");
	for (auto word : words)
	{
		cout << word << endl;
	}

	system("pause");
	return 0;
}
*/