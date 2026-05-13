#include<iostream>
using namespace std;
#include<string>
#include<fstream>
#include"Worker.h"
#include"WorkerManager.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"
#define FILENAME "empFile.text"

//创建职工管理类
WorkerManager::WorkerManager()//构造函数
{
//文件交互-读文件
	ifstream ifs;//文件不存在情况
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl; //测试输出
		this->m_EmpNum = 0;  //初始化人数
		this->m_FileIsEmpty = true; //初始化文件为空标志
		this->m_EmpArray = NULL; //初始化数组
		ifs.close(); //关闭文件
		return;
	}
	char ch;//文件存在，但为空
	ifs >> ch;//将 EOF 读到 ch 中
	if (ifs.eof())//eof 为真，文件为空
	{
		cout << "文件为空!" << endl;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}
	int num = this->get_EmpNum();//文件存在，并且记录数据
	cout << "职工个数为：" << num << endl;//测试代码
	this->m_EmpNum = num;//更新成员属性
	this->m_FileIsEmpty = false;
	this->m_EmpArray = new Worker * [this->m_EmpNum];//修复内存访问冲突
	this->init_Emp();
}
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;//根据不同的部门Id创建不同对象
		if (dId == 1)  // 1普通员工
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2) //2经理
		{
			worker = new Manager(id, name, dId);
		}
		else //总裁
		{
			worker = new Boss(id, name, dId);
		}
		//存放在数组中
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

//菜单功能实现
void WorkerManager::Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//退出功能实现
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);//退出程序
}

//添加职工功能实现
void WorkerManager::Add_Emp()
{
	cout << "请输入增加职工数量： " << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = this->m_EmpNum + addNum;//新空间人数 = 原来记录人数 + 新增人数
		Worker** newSpace = new Worker* [newSize + 8];//开辟新空间，+ 8 为了消除可能会产生的内存溢出
		if (this->m_EmpArray != NULL)//将原来空间下数据，拷贝到新空间下
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
			cin >> id;
			cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
			cin >> name;
			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1: //普通员工
				worker = new Employee(id, name, 1);
				break;
			case 2: //经理
				worker = new Manager(id, name, 2);
				break;
			case 3:  //老板
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;
		}
		delete[] this->m_EmpArray;//释放原有空间
		this->m_EmpArray = newSpace;//更改新空间的指向
		this->m_EmpNum = newSize;//更新新的个数
		this->m_FileIsEmpty = false;//更新职工不为空标志
		cout << "成功添加" << addNum << "名新职工！" << endl;//提示信息
		this->save();
	}
	else
	{
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}

//文件交互-写文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}

//文件交互-读文件
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)//依次读取 id name dId 数据，当ifs >> id 遇到空格（cin >> 读取数据时，遇到空白字符就会作为终止字符）就表示读取完毕，调到 ifs >> name 继续读取，以此类推
	{
		num++;//记录人数
	}
	ifs.close();
	return num;
}

//显示职工功能实现
void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{

		for (int i = 0; i < m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();//利用多态调用接口
		}
		system("pause");
		system("cls");
	}
}

//删除职工功能实现 2025.11.6
int WorkerManager::IsExist(int id)
{
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在" << endl;
	}
	else
	{
		cout << "请输入想要删除的职工号：" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1)//职工存在
		{
			for (int i = index; i < m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];//数据前移
			}
			this->m_EmpNum--;//更新数组记录人员个数
			this->save();
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}
	}
	system("pause");
	system("cls");
}

//修改职工功能实现
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号：" << endl;
		int id;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;
			cout << "查到： " << id << "号职工，请输入新职工号： " << endl;
			cin >> newId;
			cout << "请输入新姓名： " << endl;
			cin >> newName;
			cout << "请输入岗位： " << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}
			this->m_EmpArray[ret] = worker;//更改数据 到数组中
			cout << "修改成功！" << endl;
			this->save();//保存到文件中
		}
		else
		{
			cout << "修改失败，查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}

//查找职工功能实现
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)//按职工编号查找
		{
			int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功！该职工信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "请输入查找的姓名：" << endl;
			cin >> name;
			bool flag = false;//查找到的标志
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (name == this->m_EmpArray[i]->m_Name)
				{
					cout << "查找成功,职工编号为："
						<< m_EmpArray[i]->m_Id
						<< " 号的信息如下：" << endl;
					flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else
		{
			cout << "输入选项有误" << endl;
		}
	}
	system("pause");
	system("cls");
}

//按照职工编号进行排序功能实现
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式： " << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < m_EmpNum; j++)
			{
				if (select == 1) //升序
				{
					if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else  //降序
				{
					if (m_EmpArray[minOrMax]->m_Id < m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "排序成功,排序后结果为：" << endl;
		this->save();
		this->Show_Emp();
	}
}

//清空文件功能实现
void WorkerManager::Clean_File()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);//打开模式 ios::trunc 如果存在删除文件并重新创建
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()//析构函数
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
		}
	}
}
int main()
{
//需求分析以及案例展示 2025.11.3
	//职工管理系统可以用来管理公司内所有员工的信息
	//本教程主要利用C++来实现一个基于多态的职工管理系统
	//公司中职工分为三类：普通员工、经理、老板，显示信息时，需要显示职工编号、职工姓名、职工岗位、以及职责
		//普通员工职责：完成经理交给的任务
		//经理职责：完成老板交给的任务，并下发任务给员工
		//老板职责：管理公司所有事务
	//管理系统中需要实现的功能如下：
		//- 退出管理程序：退出当前管理系统
		//- 增加职工信息：实现批量添加职工功能，将信息录入到文件中，职工信息为：职工编号、姓名、部门编号
		//- 显示职工信息：显示公司内部所有职工的信息
		//- 删除离职职工：按照编号删除指定的职工
		//- 修改职工信息：按照编号修改职工个人信息
		//- 查找职工信息：按照职工的编号或者职工的姓名进行查找相关的人员信息
		//- 按照编号排序：按照职工编号，进行排序，排序规则由用户指定
		//- 清空所有文档：清空文件中记录的所有职工信息 （清空前需要再次确认，防止误删）

//创建职工管理类
	//管理类负责的内容如下：
		//与用户的沟通菜单界面
		//对职工增删改查的操作
		//与文件的读写交互

//菜单功能实现
	//功能描述：与用户的沟通界面
	/*Worker* worker;测试
	worker = new Employee(1, "张三", 1);
	worker->showInfo();
	Worker* manager;
	manager = new Manager(2, "李四", 2);
	manager->showInfo();
	Worker* boss;
	boss = new Boss(3, "王五", 3);
	boss->showInfo();*/

//退出功能实现
	//在main函数中提供分支选择，提供每个功能接口

//创建职工抽象类
	//职工的分类为：普通员工、经理、老板
	//将三种职工抽象到一个类（worker）中, 利用多态管理不同职工种类
	//职工的属性为：职工编号、职工姓名、职工所在部门编号
	//职工的行为为：岗位职责信息描述，获取岗位名称
	
//添加职工功能实现 2025.11.4
	//功能描述：批量添加职工，并且保存到文件中
	//用户在批量创建时，可能会创建不同种类的职工
	//如果想将所有不同种类的员工都放入到一个数组中，可以将所有员工的指针维护到一个数组里
	//如果想在程序中维护这个不定长度的数组，可以将数组创建到堆区，并利用Worker** 的指针维护

//文件交互-写文件
	//功能描述：对文件进行读写
	//在上一个添加功能中，我们只是将所有的数据添加到了内存中，一旦程序结束就无法保存了，因此文件管理类中需要一个与文件进行交互的功能，对于文件进行读写操作
	
//文件交互-读文件
	//功能描述：将文件中的内容读取到程序中
	//虽然我们实现了添加职工后保存到文件的操作，但是每次开始运行程序，并没有将文件中数据读取到程序中
	//而我们的程序功能中还有清空文件的需求，因此构造函数初始化数据的情况分为三种
		//1. 第一次使用，文件未创建
		//2. 文件存在，但是数据被用户清空
		//3. 文件存在，并且保存职工的所有数据

//显示职工功能实现
	//功能描述：显示当前所有职工信息

//删除职工功能实现 2025.11.6
	//功能描述：按照职工的编号进行删除职工操作

//修改职工功能实现
	//功能描述：能够按照职工的编号对职工信息进行修改并保存

//查找职工功能实现
	//功能描述：提供两种查找职工方式，一种按照职工编号，一种按照职工姓名

//按照职工编号进行排序功能实现
	//功能描述：按照职工编号进行排序，排序的顺序由用户指定

//清空文件功能实现
	//功能描述：将文件中记录数据清空

	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		//展示菜单
		wm.Show_Menu();
		cout << "请输入您的选择:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: 
			wm.ExitSystem();//退出功能实现
			break;
		case 1: 
			wm.Add_Emp();//添加职工功能实现
			break;
		case 2:
			wm.Show_Emp();//显示职工功能实现
			break;
		case 3:
			wm.Del_Emp();//删除职工功能实现
			break;
		case 4:
			wm.Mod_Emp();//修改职工功能实现
			break;
		case 5: 
			wm.Find_Emp();//查找职工功能实现
			break;
		case 6:
			wm.Sort_Emp();//排序职工功能实现
			break;
		case 7: 
			wm.Clean_File();//清空文件功能实现
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}