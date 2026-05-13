#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

/*
//顺序栈
class SeqStack
{
public:
	SeqStack(int size = 10) : mtop(0),mCap(size)
	{
		mpStack = new int[mCap];
	}
	~SeqStack()
	{
		delete[] mpStack;
		mpStack = nullptr;
	}
public:
	//入栈
	void push(int val)
	{
		if (mtop == mCap)//判断栈是否满
		{
			expand(mCap * 2);//栈扩容
		}
		//入栈
		mpStack[mtop] = val;
		mtop++;
	}
	//出栈
	void pop()
	{
		if (mtop == 0)
		{
			throw "stack is empty!";//抛异常结束
		}
		mtop--;
	}
	//获取栈顶元素
	int top() const //只读操作加 const
	{
		if (mtop == 0)
		{
			throw "stack is empty!";//抛异常结束
		}
		return mpStack[mtop - 1];
	}
	//判断栈空
	bool empty() const
	{
		return mtop == 0;//判断 mtop 是否为 0 
	}
	//栈元素个数
	int size() const
	{
		return mtop;
	}
private:
	void expand(int size)
	{
		int* p = new int[size];
		memcpy(p, mpStack, mtop * sizeof(int));//memcpy 按字节扩容
		delete[]mpStack;
		mpStack = p;
		mCap = size;
	}
private:
	int* mpStack;
	int mtop;//栈顶位置
	int mCap;//栈空间大小
};

//链式栈
class LinkStack
{
public:
	LinkStack() : size_(0)
	{
		head_ = new Node;
	}
	~LinkStack()
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
	//入栈 O(1)
	void push(int val)
	{
		Node* node = new Node(val);
		//头插实现入栈
		node->next_ = head_->next_;
		head_->next_ = node;
		size_++;
	}
	//出栈 O(1)
	void pop()
	{
		if (head_->next_ == nullptr)
		{
			throw "stack is empty!";//抛异常结束 
		}
		//删除栈顶节点
		Node* p = head_->next_;
		head_->next_ = p->next_;
		delete p;
		size_--;
	}
	//获取栈顶元素
	int top() const
	{
		if (head_->next_ == nullptr)
		{
			throw "stack is empty!";//抛异常结束 
		}
		return head_->next_->data_;
	}
	//判断栈空
	bool empty() const
	{
		return head_->next_ == nullptr;
	}
	//返回栈元素个数
	int size() const
	{
		return size_;
	}
private:
	struct Node
	{
		Node(int data = 0) : data_(data), next_(nullptr) {}
		int data_;
		Node* next_;
	};
	Node* head_;
	int size_;
};

//括号匹配问题
bool isValid(string s)
{
	stack<char> cs;
	for (char ch : s)//对于字符串 s 中的每一个字符，依次赋值给变量 ch，执行循环体中的代码，直到遍历完 s 的所有字符
	{
		//遇到左括号
		if (ch == '(' || ch == '[' || ch == '{')
		{
			cs.push(ch);
		}
		//遇到右括号
		else
		{
			//右括号数量大于左括号数量
			if (cs.empty())
			{
				return false;
			}
			char cmp = cs.top();//获取栈顶字符
			cs.pop();//出栈
			if (ch == ')' && cmp != '('
				|| ch == ']' && cmp != '['
				|| ch == '}' && cmp != '{')
			{
				return false;
			}
		}
	}
	//直接 return true 会在当左括号数量大于右括号数量时，直接跳出了 if-else 循环从而进行错误的判断
	return cs.empty();//栈里面的括号处理完栈为空返回 true，栈里面的括号没处理完，即左括号数量大于右括号数量，返回 false
}

//逆波兰表达式求解 2026.2.1
int calc(int right, int left, char sign)
{
	switch (sign)
	{
	case'+':
		return left + right;
	case'-':
		return left - right;
	case'*':
		return left * right;
	case'/':
		return left / right;
	}
	throw "Operator Error";
}
int evalRPN(vector<string>& tokens)
{
	stack<int> intStack;//数字栈
	for (string &str : tokens)
	{
		if (str.size() == 1 && 
			(str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/'))//判断是否为运算符，其中需判断字符数量是否为 1，防止 "-11" 类似数字产生误判
		{
			//遇到运算符，开始运算
			int right = intStack.top();
			intStack.pop();
			int left = intStack.top();
			intStack.pop();
			intStack.push(calc(left, right, str[0]));//运算结果入栈
		}
		else
		{
			intStack.push(stoi(str));//stoi：string 转 int，stol：string 转 flow，to_string(int)：int 转 string
		}
	}
	return intStack.top();//计算完毕
}

//中缀转后缀表达式
bool Priority(char ch, char topch)
{
	if ((ch == '*' || ch == '/') && (topch == '+' || ch == '-'))
	{
		return true;
	}
	if (ch == ')')
	{
		return false;
	}
	if (topch == '(' && ch != ')')
	{
		return true;
	}
	return false;
}
string MiddleToEndExpr(string expr)
{
	string result;
	stack<char> s;//符号栈
	for (char ch : expr)
	{
		//遇数字直接输出
		if (ch >= '0' && ch <= '9')
		{
			result.push_back(ch);
		}
		else
		{
			for (;;)
			{
				//处理符号
				if (s.empty() || ch == '(')
				{
					s.push(ch);
					break;
				}
				//比较当前符号 ch 与栈顶符号 top 的优先级
				char topch = s.top();
				if (Priority(ch, topch))//比较符号优先级函数 Priority，true:ch > topch, false:ch <= topch
				{
					s.push(ch);//当前符号优先级大于栈顶符号，直接入栈
					break;
				}
				else
				{
					s.pop();//出栈
					if (topch == '(')//遇到 )，要一直出栈，直到遇见（ 为止
					{
						break;
					}
					result.push_back(topch);//输出
				}
			}
		}
	}
	//如果符号栈还存留符号，直接输出到后缀表达式里面
	while (!s.empty())
	{
		result.push_back(s.top());
		s.pop();
	}
	return result;
}

int main()
{
//栈 2026.2.1
	//特点：先进后出、后进先出
	//栈顶(top)：出入口，当 top = 0 时，意味栈为空，当 top = sizeof(arr)/sizeof(arr[0]) 时，意味栈满，访问栈顶元素，应为 arr[top - 1]
	//入栈：从栈顶增加栈元素，arr[top] = 10, top++
	//出栈：从栈顶减少栈元素，top--
	
//顺序栈
	//特点：依赖数组实现
	int arr[] = { 12,4,56,7,89,31,53,75 };
	SeqStack s_Seq;
	for (int v : arr)
	{
		s_Seq.push(v);
	}
	while (!s_Seq.empty())
	{
		cout << s_Seq.top() << " ";
		s_Seq.pop();
	}
	cout << endl;
	 
//链式栈
	//特点：依赖链表实现
	//把链表头节点后面，第一个有效节点的位置，当做栈顶位置
	LinkStack s_Link;
	for (int v : arr)
	{
		s_Link.push(v);
	}
	while (!s_Link.empty())
	{
		cout << s_Link.top() << " ";
		s_Link.pop();
	}
	cout << endl;
	
//括号匹配问题
	//描述：给定一个括号'(',')','{','}','[',']'的字符串 s，判断字符串是否有效，有效字符串需满足：1.左括号必须用同类型的有括号闭合；2.左括号必须以正确的顺序闭合
	//方法：遍历 s 字符串，遇到左括号直接入栈，如遇有括号，直接从栈顶取出一个左括号进行匹配，如果匹配继续重复此操作，若不匹配直接结束
	string str = "{{[()]}}";
	string str1 = "{{[(}]}}";
	string str2 = "{";
	string str3 = "]";
	if (isValid(str))
	{
		cout << "括号匹配 " << endl;

	}
	else
	{
		cout << "括号不匹配 " << endl;
	}

	//逆波兰表达式求解
	//逆波兰表达式：逆波兰表达式是一种后缀表达式，所谓后缀就是指算符写在后面。
		//平常使用的算式则是一种中缀表达式，如 (1 + 2)* (3 + 4) 。
		//该算式的逆波兰表达式写法为 ((1 2 + ) (3 4 + )*) 。
	//逆波兰表达式主要有以下两个优点：
		//1.去掉括号后表达式无歧义，上式即便写成 1 2 + 3 4 + * 也可以依据次序计算出正确结果。
		//2.适合用栈操作运算：遇到数字则入栈；遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中
	//方法：遇到数字则入栈，遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中
	vector<string> v_evalRPN = { "1", "2", "+", "3", "4", "+", "*" };
	cout << evalRPN(v_evalRPN) << endl;

	//中缀转后缀表达式
	//描述：2 + (4 + 6) / 2 + 6 / 3 ---> 2 4 6 + 2 / + 6 3 / +
	//方法：遇到数字直接输出，遇到符号：1.栈为空或遇左括号，直接入栈，2.栈不为空，用当前符号和栈顶符号比较其优先级，当前符号优先级大于栈顶符号，直接入栈，当前符号优先级小于等于栈顶符号，输出栈顶符号继续比较，3.继续比较：把栈里面的符号都出完了或者遇到 )，要一直出栈，直到遇见（ 为止
	cout << MiddleToEndExpr("(1+2)*(3+4)") << endl;
	cout << MiddleToEndExpr("2+(4+6)/2+6/3") << endl;
	cout << MiddleToEndExpr("2+6/(4-2)+(4+6)/2") << endl;

	system("pause");
	return 0;
}
*/