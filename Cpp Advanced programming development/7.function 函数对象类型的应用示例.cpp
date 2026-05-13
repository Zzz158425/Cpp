#include<iostream>
#include<map>
#include<functional>
#include<algorithm>
#include<string>
using namespace std;

/*
void hello1()
{
	cout << "hello world!" << endl;
}
void hello2(string str)
{
	cout << str << endl;
}
int sum(int a, int b)
{
	cout << a + b << endl;
	return a + b;
}
class Test
{
public:
	void hello(string str) { cout << str << endl; }//成员方法调用必须依赖对象
};

//function 应用
void doShowAllBooks() { cout << "查看所有书籍信息" << endl; }
void doBorrow() { cout << "借书" << endl; }
void doBack() { cout << "还书" << endl; }
void doQueryBooks() { cout << "查询书籍" << endl; }
void doLoginOut() { cout << "注销" << endl; }

int main()
{
//function：绑定器，函数对象，lambda 表达式，它们只能使用在一条语句中，function 可以将其类型记录下来
//从 function 类模板定义处可知，希望用一个函数类型实例化 function
//1.用函数类型实例化 function
//2.通过 function 调用 operator() 函数的时候，需要根据函数类型传入相应的参数
	function<void()> func1 = hello1;//function<返回值 + 参数列表>
	func1();//func1.operator()() -> hello1()
	function<void(string)> func2 = hello2;
	func2("hello hello2!");//func2.operator()(string str) -> hello2()
	function<int(int, int)> func3 = sum;
	func3(20, 30);
	function<int(int, int)> func4 = [](int a, int b)->int 
		{
			cout << a + b << endl;
			return a + b; 
		};
	function<void(Test*, string)> func5 = &Test::hello;//成员方法编译以后会多出 this 指针，有两个参数
	Test t;
	func5(&t, "call Test::hello!");//成员方法调用依赖一个对象，传入临时对象即可 Test()

//function 应用
	//跟函数指针相比，应用更广泛，可以接收lambda表达式，绑定器
	int choice = 0;
	map<int, function<void()>> actionMap;
	actionMap.insert({ 1, doShowAllBooks });
	actionMap.insert({ 2, doBorrow });
	actionMap.insert({ 3, doBack });
	actionMap.insert({ 4, doQueryBooks });
	actionMap.insert({ 5, doLoginOut });
	for (;;)
	{
		cout << "-------------------" << endl;
		cout << "1.查看所有书籍信息" << endl;
		cout << "2.借书" << endl;
		cout << "3.还书" << endl;
		cout << "4.查询书籍" << endl;
		cout << "5.注销" << endl;
		cout << "-------------------" << endl;
		cout << "请选择：";
		cin >> choice;
		auto it = actionMap.find(choice);
		if (it == actionMap.end())
		{
			cout << "输入数字无效，重新选择！" << endl;
		}
		else
		{
			it->second();//it->second 是对应的函数对象，可以直接调用
		}
		//switch (choice) // 不好，因为这块代码无法闭合  无法做到“开-闭”原则 不好增删改功能
		//{
		//case1:
		//	break;
		//case2:
		//	break;
		//case3:
		//	break;
		//case4:
		//	break;
		//case5:
		//	break;
		//default:
		//	break;
		//}
	}

	system("pause");
	return 0;
}
*/