#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"Manager.h"

Manager::Manager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}
void Manager::showInfo()//显示个人信息
{
	cout << "职工编号： " << this->m_Id
		<< " \t职工姓名： " << this->m_Name
		<< " \t岗位：" << this->getDeptName()
		<< " \t岗位职责：完成老板交给的任务，并且下发任何给员工" << endl;
}
string Manager::getDeptName()//获取岗位名称
{
	return string("经理");
}