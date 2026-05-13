#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include"globalFile.h"
#include<fstream>
#include<string>
#include"orderFile.h"
#include<vector>
#include"orderFile.h"

class Teacher :public Identity
{
public:
	Teacher();//默认构造
	Teacher(int empId, string name, string pwd);//有参构造 (职工编号，姓名，密码)
	virtual void operMenu();//菜单界面
	void showAllOrder();//查看所有预约
	void validOrder();//审核预约
	int m_EmpId; //教师编号
};
