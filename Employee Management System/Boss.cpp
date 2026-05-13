#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"Boss.h"

Boss::Boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}
void Boss::showInfo()//显示个人信息
{
	cout << "职工编号： " << this->m_Id
		<< " \t职工姓名： " << this->m_Name
		<< " \t岗位：" << this->getDeptName()
		<< " \t岗位职责：管理公司所有事务" << endl;
}
string Boss::getDeptName()//获取岗位名称
{
	return string("总裁");
}