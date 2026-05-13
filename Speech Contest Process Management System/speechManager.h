#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include"speaker.h"
#include<algorithm>
#include<deque>
#include<functional>
#include<numeric>
#include<string>
#include<fstream>

//演讲管理类
class SpeechManager
{
public:
	SpeechManager();//构造函数
	void show_Menu();//菜单功能
	void exitSystem();//退出系统
	~SpeechManager();//析构函数
	void initSpeech();//初始化
	void createSpeaker();//创建12名选手
	void startSpeech();//开始比赛，比赛整个流程控制函数
	void speechDraw();//抽签
	void speechContest();//比赛
	void showScore();//显示比赛分数
	void saveRecord();//保存记录
	void loadRecord();//读取记录
	bool fileIsEmpty;//文件为空的标志
	map<int, vector<string>> m_Record;//往届记录
	void showRecord();//显示往届得分
	void clearRecord();//清空记录
	//成员属性
	vector<int>v1;//比赛选手容器 12 人
	vector<int>v2;//第一轮晋级容器 6 人
	vector<int>vVictory;//胜利前三名容器 3 人
	map<int, Speaker> m_Speaker;//存放编号以及对应的具体选手容器
	int m_Index;//存放比赛轮数
};
