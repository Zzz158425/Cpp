#include<iostream>
using namespace std;
#include"speechManager.h"
#include<ctime>


int main()
{
//需求分析以及案例展示 2026.1.10
	//比赛规则
		//学校举行一场演讲比赛，共有 12 个人参加。比赛共两轮，第一轮为淘汰赛，第二轮为决赛。
		//比赛方式：分组比赛，每组 6 个人；选手每次要随机分组，进行比赛
		//每名选手都有对应的编号，如 10001 ~10012
		//第一轮分为两个小组，每组 6 个人。 整体按照选手编号进行抽签后顺序演讲。
		//当小组演讲完后，淘汰组内排名最后的三个选手，前三名晋级，进入下一轮的比赛。
		//第二轮为决赛，前三名胜出
		//每轮比赛过后需要显示晋级选手的信息
	//程序功能
		//开始演讲比赛：完成整届比赛的流程，每个比赛阶段需要给用户一个提示，用户按任意键后继续下一个阶段
		//查看往届记录：查看之前比赛前三名结果，每次比赛都会记录到文件中，文件用.csv后缀名保存
		//清空比赛记录：将文件中数据清空
		//退出比赛程序：可以退出当前程序

//创建职工管理类
	//管理类负责的内容如下：
		//提供菜单界面与用户交互
		//对演讲比赛流程进行控制
		//与文件的读写交互

//菜单功能实现
	//功能描述：与用户的沟通界面

//退出功能实现
	//在speechManager.h中提供退出系统的成员函数 void exitSystem()

//演讲比赛功能
	//比赛流程分析：
		//抽签 → 开始演讲比赛 → 显示第一轮比赛结果 →
		//抽签 → 开始演讲比赛 → 显示前三名结果 → 保存分数

//创建选手类
	//选手类中的属性包含：选手姓名、分数

//成员属性添加
	//在speechManager.h中添加属性

//初始化属性
	//在 speechManager.h 中提供开始比赛的的成员函数 void initSpeech();
	//在 speechManager.cpp 中实现 void initSpeech();
	//SpeechManager 构造函数中调用 void initSpeech();
	
//创建选手
	//在 speechManager.h 中提供开始比赛的的成员函数 void createSpeaker();
	//在 speechManager.cpp 中实现 void createSpeaker();
	//SpeechManager 类的构造函数中调用 void createSpeaker();

//开始比赛成员函数添加
	//在 speechManager.h 中提供开始比赛的的成员函数 void startSpeech();
	//该函数功能是主要控制比赛的流程
	//在 speechManager.cpp 中将 startSpeech 的空实现先写入
	//我们可以先将整个比赛的流程写到函数中

//开始比赛
	//在 speechManager.h 中提供比赛的的成员函数 void speechContest();
	//在 speechManager.cpp 中实现成员函数 void speechContest();
	//在 startSpeech 比赛流程控制的函数中，调用比赛函数
	

//显示比赛分数
	//在 speechManager.h 中提供比赛的的成员函数 void showScore();
	//在 speechManager.cpp中实现成员函数 void  showScore();
	//在 startSpeech 比赛流程控制的函数中，调用显示比赛分数函数
 
//第二轮比赛
	//在 startSpeech 比赛流程控制的函数中，加入第二轮的流程

//保存分数
	//将每次演讲比赛的得分记录到文件中
	//在 speechManager.h 中添加保存记录的成员函数 void saveRecord();
	//在 speechManager.cpp 中实现成员函数 void saveRecord();
	//在 startSpeech 比赛流程控制的函数中，最后调用保存记录分数函数

//查看记录
	//读取记录分数
		//在 speechManager.h 中添加保存记录的成员函数 void loadRecord();
		//添加判断文件是否为空的标志 bool fileIsEmpty;
		//添加往届记录的容器 map<int, vector<string >> m_Record;
		//在 speechManager.cpp 中实现成员函数 void loadRecord();
		//在 SpeechManager 构造函数中调用获取往届记录函数
	//查看记录功能
		//在 speechManager.h 中添加保存记录的成员函数 void showRecord();
		//在 speechManager.cpp 中实现成员函数 void showRecord();
//Bug解决
	//1. 查看往届记录，若文件不存在或为空，并未提示
	//解决方式：在showRecord函数中，开始判断文件状态并加以判断
	//2. 若记录为空或不存在，比完赛后依然提示记录为空
	//解决方式：saveRecord中更新文件为空的标志
	//3. 比完赛后查不到本届比赛的记录，没有实时更新
	//解决方式：比赛完毕后，所有数据重置
	//4.在初始化时，没有初始化记录容器
	//解决方式：initSpeech中添加 初始化记录容器
	//5. 每次记录都是一样的
	//解决方式：在main函数一开始 添加随机数种子

	srand((unsigned int)time(NULL));//随机数种子 Bug 5
	SpeechManager sm;//创建管理类对象
	int choice = 0; //用来存储用户的选项
	while (true)
	{
		sm.show_Menu();
		cout << "请输入您的选择： " << endl;
		cin >> choice; //接受用户的选项
		switch (choice)
		{
		case 1:  
			sm.startSpeech();//开始比赛
			break;
		case 2:  
			sm.showRecord();//查看记录
			break;
		case 3:  
			sm.clearRecord();//清空记录
			break;
		case 0:  
			sm.exitSystem();//退出系统
			break;
		default:
			system("cls"); //清屏
			break;
		}
	}
	system("pause");
	return 0;
}