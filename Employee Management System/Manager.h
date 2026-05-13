#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"Worker.h"

class Manager :public Worker
{
public:
	Manager(int id, string name, int did);
	virtual void showInfo();//显示个人信息
	virtual string getDeptName();//获取岗位名称
};