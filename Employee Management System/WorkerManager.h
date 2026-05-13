#pragma once
#include<iostream>
using namespace std;


class WorkerManager
{
public:
	WorkerManager();//构造函数
	void Show_Menu();//展示菜单
	void ExitSystem();//退出系统
	int m_EmpNum;//记录文件中的人数个数
	Worker ** m_EmpArray;//员工数组的指针
	void Add_Emp();//添加职工
	void save();//保存文件
	bool m_FileIsEmpty;//判断文件是否为空标志
	int get_EmpNum();//统计人数
	void init_Emp();//初始化员工
	void Show_Emp();//显示职工
	int IsExist(int id);//按照职工编号判断职工是否存在,若存在返回职工在数组中位置，不存在返回-1
	void Del_Emp();//删除职工
	void Mod_Emp();//修改职工
	void Find_Emp();//查找职工
	void Sort_Emp();//排序职工
	void Clean_File();//清空文件
	~WorkerManager();//析构函数
};