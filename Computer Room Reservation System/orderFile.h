#pragma once
#include<iostream>
using namespace std;
#include "globalFile.h"
#include <fstream>
#include <map>
#include<string>

class OrderFile
{
public:
	OrderFile();//构造函数
	void updataOrder();//更新预约记录
	int m_Size;//预约记录条数
	map<int, map<string, string>>m_orderData;;//记录的容器，key 记录的条数，value 具体记录的键值对信息
};
