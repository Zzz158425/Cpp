#include<iostream>
#include<thread>
#include<unordered_map>
#include<list>
#include<memory>
using namespace std;
//2026.4.30

/*
//观察者抽象类
class Observer
{
public:
	// 处理消息的接口
	virtual void handle(int msgid) = 0;
};
//观察者实例
class Observer1 : public Observer
{
public:
	void handle(int msgid)
	{
		switch (msgid)
		{
		case 1:
			std::cout << "Observer1 recv 1 msg!" << std::endl;
			break;
		case 2:
			std::cout << "Observer1 recv 2 msg!" << std::endl;
			break;
		default:
			std::cout << "Observer1 recv unknown msg!" << std::endl;
			break;
		}
	}
};
class Observer2 : public Observer
{
public:
	void handle(int msgid)
	{
		switch (msgid)
		{
		case 2:
			std::cout << "Observer2 recv 2 msg!" << std::endl;
			break;
		default:
			std::cout << "Observer2 recv unknown msg!" << std::endl;
			break;
		}
	}
};
class Observer3 : public Observer
{
public:
	void handle(int msgid)
	{
		switch (msgid)
		{
		case 1:
			std::cout << "Observer3 recv 1 msg!" << std::endl;
			break;
		case 3:
			std::cout << "Observer3 recv 3 msg!" << std::endl;
			break;
		default:
			std::cout << "Observer3 recv unknown msg!" << std::endl;
			break;
		}
	}
};
//主题类
class Subject
{
public:
	//给主题增加观察者对象
	void addObserver(Observer* obser, int msgid)
	{
		_subMap[msgid].push_back(obser);
		//auto it = _subMap.find(msgid);
		//if (it != _subMap.end())
		//{
		//	it->second.push_back(obser);
		//}
		//else
		//{
		//	list<Observer*> lis;
		//	lis.push_back(obser);
		//	_subMap.insert({ msgid, lis });
		//}
	}
	//主题检测发生改变，通知相应的观察者对象处理事件
	void dispatch(int msgid)
	{
		auto it = _subMap.find(msgid);
		if (it != _subMap.end())
		{
			for (Observer* pObser : it->second)
			{
				pObser->handle(msgid);
			}
		}
	}
private:
	unordered_map<int, list<Observer*>> _subMap;
};

int main()
{
//观察者模式（观察者-监听者模式、发布-顶阅模式）
	//行为型模式：主要关注的是对象之间的通信
	//主要关注的是对象的一对多的关系，也就是多个对象都依赖一个对象
	//当该对象的状态发生改变时，其它对象都能够接收到相应的通知
	Subject subject;
	subject.addObserver(new Observer1(), 1);
	subject.addObserver(new Observer1(), 2);
	subject.addObserver(new Observer2(), 2);
	subject.addObserver(new Observer3(), 1);
	subject.addObserver(new Observer3(), 3);
	subject.dispatch(1);
	subject.dispatch(2);
	subject.dispatch(3);
	int msgid = 0;
	for (;;)
	{
		cout << "输入消息 id：";
		cin >> msgid;
		if (msgid == -1)
		{
			break;
		}
		subject.dispatch(msgid);
	}

	system("pause");
	return 0;
}
*/