#pragma once
#include<iostream>
using namespace std;
#include "identity.h"
#include<string>
#include <fstream>
#include <vector>
#include "globalFile.h"
#include "teacher.h"
#include "student.h"
#include "computerRoom.h"
#include<algorithm>

class Manager :public Identity
{
public:
	Manager();//默认构造
	Manager(string name, string pwd);//有参构造  管理员姓名，密码
	virtual void operMenu();//选择菜单
	void addPerson();//添加账号 
	void showPerson();//查看账号
	void showComputer();//查看机房信息
	void cleanFile();//清空预约记录
	void initVector();//初始化容器
	bool checkRepeat(int id , int type);//检测重复，参数 1 为学号/职工号，参数 2 为检测类型
	vector<Student> vStu;//学生容器
	vector<Teacher> vTea;//教师容器
	vector<ComputerRoom>vCom;//机房信息
};
