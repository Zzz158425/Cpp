#include<iostream>
using namespace std;
#include<ctime>
#include "globalFile.h"
#include "Identity.h"
#include <fstream>
#include <string>
#include "student.h"
#include "teacher.h"
#include "manager.h"
#include "computerRoom.h"

//教师子菜单搭建以及注销实现
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->operMenu();//调用管理员子菜单
		Teacher* tea = (Teacher*)teacher;//将父类指针转为子类指针，调用子类里其他接口
		int select = 0;
		cin >> select;
		if (select == 1)//查看所有预约
		{
			cout << "查看所有预约" << endl;
			tea->showAllOrder();
		}
		else if (select == 2)//审核预约
		{
			cout << "审核预约" << endl;
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//学生子菜单搭建以及注销实现
void studentMenu(Identity*& student)
{
	while (true)
	{
		student->operMenu();//调用管理员子菜单
		Student* stu = (Student*)student;//将父类指针转为子类指针，调用子类里其他接口
		int select = 0;
		cin >> select;
		if (select == 1)  //申请预约
		{
			cout << "申请预约" << endl;
			stu->applyOrder();
		}
		else if (select == 2) //查看我的预约
		{
			cout << "查看我的预约" << endl;
			stu->showMyOrder();
		}
		else if (select == 3) //查看所有预约
		{
			cout << "查看所有预约" << endl;
			stu->showAllOrder();
		}
		else if (select == 4) //取消预约
		{
			cout << "取消预约" << endl;
			stu->cancelOrder();
		}
		else
		{
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//管理员登录和注销
void managerMenu(Identity*& manager)
{
	while (true)
	{
		manager->operMenu();//调用管理员子菜单
		Manager* man = (Manager*)manager;//将父类指针转为子类指针，调用子类里其他接口
		int select = 0;
		cin >> select;
		if (select == 1)  //添加账号
		{
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2) //查看账号
		{
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3) //查看机房
		{
			cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4) //清空预约
		{
			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//登录函数封装
void LoginIn(string fileName, int type)
{
	Identity* person = NULL;//父类指针，指向子类对象
	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);
	//文件不存在情况
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	int id = 0;
	string name;
	string pwd;
	if (type == 1)//学生登录
	{
		cout << "请输入你的学号" << endl;
		cin >> id;
	}
	else if (type == 2)//教师登录
	{
		cout << "请输入你的职工号" << endl;
		cin >> id;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码： " << endl;
	cin >> pwd;
	if (type == 1)
	{
		//学生登录验证
		int fId;//从文件中读取的 id 号
		string fName;//从文件中获取的姓名
		string fPwd;//从文件中获取的密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//与用户输入的信息做对比
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				studentMenu(person);//进入管理员子菜单界面
				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师登录验证
		int fId;//从文件中读取 id 号
		string fName;//从文件中获取姓名
		string fPwd;//从文件中获取密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//与用户输入的信息做对比
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "教师验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				teacherMenu(person);//进入管理员子菜单界面
				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员登录验证
		string fName;//从文件中获取姓名
		string fPwd;//从文件中获取密码
		while (ifs >> fName && ifs >> fPwd)
		{
			//与用户输入的信息做对比
			if (fName == name && fPwd == pwd)
			{
				cout << "管理员验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);//进入管理员子菜单界面
				return;
			}
		}
	}
	cout << "验证登录失败!" << endl;
	system("pause");
	system("cls");
	return;
}

int main()
{
//机房预约系统需求 2026.1.14
	//系统简介：学校现有几个规格不同的机房，由于使用时经常出现"撞车"现象, 现开发一套机房预约系统，解决这一问题。
	//身份简介：分别有三种身份使用该程序
		//学生代表：申请使用机房
		//教师：审核学生的预约申请
		//管理员：给学生、教师创建账号
	//机房简介：机房总共有 3 间
		//1号机房 --- 最大容量 20 人
		//2号机房 --- 最多容量 50人
		//3号机房 --- 最多容量 100 人
	//申请简介
		//申请的订单每周由管理员负责清空。
		//学生可以预约未来一周内的机房使用，预约的日期为周一至周五，预约时需要选择预约时段（上午、下午）
		//教师来审核预约，依据实际情况审核预约通过或者不通过
		
//系统具体需求
	//首先进入登录界面，可选登录身份有：
		//学生代表
		//老师
		//管理员
		//退出
	//每个身份都需要进行验证后，进入子菜单
		//学生需要输入 ：学号、姓名、登录密码
		//老师需要输入：职工号、姓名、登录密码
		//管理员需要输入：管理员姓名、登录密码
	//学生具体功能
		//申请预约 --- 预约机房
		//查看自身的预约 --- 查看自己的预约状态
		//查看所有预约 --- 查看全部预约信息以及预约状态
		//取消预约 --- 取消自身的预约，预约成功或审核中的预约均可取消
		//注销登录 --- 退出登录
	//教师具体功能
		//查看所有预约 --- 查看全部预约信息以及预约状态
		//审核预约 --- 对学生的预约进行审核
		//注销登录 --- 退出登录
	//管理员具体功能
		//添加账号 --- 添加学生或教师的账号，需要检测学生编号或教师职工号是否重复
		//查看账号 --- 可以选择查看学生或教师的全部信息
		//查看机房 --- 查看所有机房的信息
		//清空预约 --- 清空所有预约记录
		//注销登录 --- 退出登录
		
//创建主菜单
	//功能描述：设计主菜单，与用户进行交互
	//接受用户的选择，搭建接口

//退出功能实现

//创建身份类
	//身份的基类
		//在整个系统中，有三种身份，分别为：学生代表、老师以及管理员
		//三种身份有其共性也有其特性，因此我们可以将三种身份抽象出一个身份基类 identity
		
//学生类
	//功能分析
		//学生类主要功能是可以通过类中成员函数，实现预约实验室操作
		//学生类中主要功能有：
			//显示学生操作的菜单界面
			//申请预约
			//查看自身预约
			//查看所有预约
			//取消预约

//老师类
	//功能分析
		//教师类主要功能是查看学生的预约，并进行审核
		//教师类中主要功能有：
			//显示教师操作的菜单界面
			//查看所有预约
			//审核预约

//管理员类
	//功能分析
		//管理员类主要功能是对学生和老师账户进行管理，查看机房信息以及清空预约记录
		//管理员类中主要功能有：
			//显示管理员操作的菜单界面
			//添加账号
			//查看账号
			//查看机房信息
			//清空预约记录

//全局文件添加
	//功能描述：不同的身份可能会用到不同的文件操作，我们可以将所有的文件名定义到一个全局的文件中

//登录函数封装
	//功能描述：根据用户的选择，进入不同的身份登录

//学生登录实现

//教师登录实现

//管理员登录实现

//管理员登录和注销

//添加账号
	//功能描述：给学生或教师添加新的账号
	//功能要求：添加时学生学号不能重复、教师职工号不能重复

//去重操作
	//功能描述：添加新账号时，如果是重复的学生编号，或是重复的教师职工编号，提示有误

//去重函数封装 2026.1.15

//去重 Bug 解决
	//Bug 描述：
		//虽然可以检测重复的账号，但是刚添加的账号由于没有更新到容器中，因此不会做检测
		//导致刚加入的账号的学生号或者职工编号，再次添加时依然可以重复
	//解决方案：在每次添加新账号时，重新初始化容器

//查看账号功能实现
	//功能描述：显示学生信息或教师信息

//查看机房信息功能实现

//清空预约
	//功能描述：清空生成的 order.txt 预约文件

//学生子菜单搭建以及注销实现

//申请预约
	//功能实现：申请预约时，学生可以看到机房的信息，因此我们需要让学生获取到机房的信息

//预约类的容器属性分析
	
//预约类中获取所有预约信息
	//功能描述：显示预约记录时，需要从文件中获取到所有记录，用来显示，创建预约的类来管理记录以及更新

//学生显示自身预约功能

//显示所有预约

//取消预约

//教师子菜单搭建以及注销

//教师显示所有预约功能实现

//教师审核预约功能实现

	int select = 0;
	while (true)
	{
		cout << "======================  欢迎来到传智播客机房预约系统  =====================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";
		cin >> select; //接受用户选择
		switch (select)
		{
		case 1:  
			LoginIn(STUDENT_FILE, 1);//学生身份
			break;
		case 2:  
			LoginIn(TEACHER_FILE, 2);//老师身份
			break;
		case 3:  
			LoginIn(ADMIN_FILE, 3);//管理员身份
			break;
		case 0:  
			cout << "欢迎下一次使用" << endl;//退出系统
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}

	}

	system("pause");
	return 0;
}