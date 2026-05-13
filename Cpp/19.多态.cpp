#include<iostream>
using namespace std;
#include<string>

/*
//多态的基本语法 2025.10.31
class Animal
{
public:
	void speak()//地址早绑定，在编译阶段确定了函数地址，无论传来的是什么，都执行 Animal
	{
		cout << "动物在说话" << endl;
	}
};
class Cat :public Animal
{
public:
	void speak()
	{
		cout << "小猫在说话" << endl;
	}
};
void doSpeak(Animal &animal)//Animal &animal = cat，父类引用指向子类对象
{
	animal.speak();
}
class Animal1
{
public:
	virtual void speak()//地址晚绑定
	{
		cout << "动物在说话" << endl;
	}
};
class Cat1 :public Animal1
{
public:
	virtual void speak()//子类 virtual 可写可不写
	{
		cout << "小猫在说话" << endl;
	}
};
class Dog :public Animal1
{
public:
	void speak()
	{
		cout << "小狗在说话" << endl;
	}
};
void doSpeak(Animal1& animal)
{
	animal.speak();
}
void test01()
{
	Cat cat;
	doSpeak(cat);
	Cat1 cat1;
	doSpeak(cat1);
	Dog dog;
	doSpeak(dog);//animal.speak()，speak 的地址不能确定，根据传入的对象，执行确定的函数
}

//多态的原理剖析
void test02()
{
	cout << "Animal sizeof = " << sizeof(Animal) << endl;
	cout << "Animal1 sizeof = " << sizeof(Animal1) << endl;
}

//计算器类案例1
class Calculator//普通写法
{
public:
	int getResult(string oper)//如果想扩展新功能，需修改源码，开发中提倡开闭原则：对扩展进行开放，对修改进行关闭
	{
		if (oper == "+")
		{
			return m_Num1 + m_Num2;
		}
		else if (oper == "-")
		{
			return m_Num1 - m_Num2;
		}
		else if (oper == "*")
		{
			return m_Num1 * m_Num2;
		}
	}
	int m_Num1;
	int m_Num2;
};
void test03()
{
	Calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 10;
	cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;
	cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;
	cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
}
class AbstractCalculator//多态写法
{
public:
	virtual int getResult()
	{
		return 0;
	}
	int m_Num1;
	int m_Num2;
};
class AddCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 + m_Num2;
	}
};
class SubCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 - m_Num2;
	}
};
class MulCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 * m_Num2;
	}
};
void test04()
{
	AbstractCalculator *abc = new AddCalculator;//父类指针或引用指向子类对象，发生多态
	abc->m_Num1 = 100;
	abc->m_Num2 = 100;
	cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;
	abc = new SubCalculator;
	abc->m_Num1 = 100;
	abc->m_Num2 = 100;
	cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;
	abc = new MulCalculator;
	abc->m_Num1 = 100;
	abc->m_Num2 = 100;
	cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;
}
	
//纯虚函数和抽象类
class Base
{
public:
	virtual void func() = 0;//纯虚函数，只要有一个纯虚函数，这个类就称为抽象类
};
class Son :public Base
{
public:

};
class Son1 :public Base
{
public:
	virtual void func()
	{
		cout << "Son1 func函数调用" << endl;
	}

};
void test05()
{
	//Base b;抽象类无法实例化对象
	//new Base;抽象类无法实例化对象
	//Son b;子类必须重写抽象类中的纯虚函数，否则也属于抽象类
	Son1 b;
	Base* base = new Son1;//父类指针或引用指向子类对象，发生多态
	base->func();
}

//制作饮品案例2
class AbstractDrinking
{
public:
	virtual void Boil() = 0;//煮水
	virtual void Brew() = 0;//冲泡
	virtual void PourInCup() = 0;//倒入杯中
	virtual void PutSomething() = 0;//加入辅料
	void makeDrink()
	{
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};
class Coffee :public AbstractDrinking//制作咖啡
{
public:
	virtual void Boil()//烧水
	{
		cout << "煮矿泉水!" << endl;
	}
	virtual void Brew()//冲泡
	{
		cout << "冲泡咖啡!" << endl;
	}
	virtual void PourInCup()//倒入杯中
	{
		cout << "将咖啡倒入杯中!" << endl;
	}
	virtual void PutSomething()	//加入辅料
	{
		cout << "加入糖和牛奶!" << endl;
	}

};
class Tea :public AbstractDrinking//制作茶水
{
public:
	virtual void Boil()//烧水
	{
		cout << "煮山泉水!" << endl;
	}
	virtual void Brew()//冲泡
	{
		cout << "冲泡茶叶!" << endl;
	}
	virtual void PourInCup()//倒入杯中
	{
		cout << "将茶叶倒入杯中!" << endl;
	}
	virtual void PutSomething()	//加入辅料
	{
		cout << "加入枸杞!" << endl;
	}
};
void doWork(AbstractDrinking* abs)
{
	abs->makeDrink();
	delete abs;
}
void test06()
{
	doWork(new Coffee);//AbstractDrinking* a = new coffee，实现多态
	doWork(new Tea);//AbstractDrinking* a = new Tea，实现多态
}

//虚析构和纯虚析构
class Animal2//非虚析构
{
public:
	Animal2()
	{
		cout << "Animal2 构造函数调用" << endl;
	}
	~Animal2()
	{
		cout << "Animal2 析构函数调用" << endl;
	}
	virtual void speak() = 0;
};
class Cat2 :public Animal2
{
public:
	Cat2(string name)
	{
		cout << "Cat2 构造函数调用" << endl;
		m_Name = new string(name);
	}
	virtual void speak()
	{
		cout << *m_Name << "小猫在说话" << endl;
	}
	string* m_Name;
	~Cat2()
	{
		if (m_Name != NULL)
		{
			cout << "Cat2 析构函数调用" << endl;
			delete m_Name;
			m_Name = NULL;
		}
	}
};
class Animal3//虚析构
{
public:
	Animal3()
	{
		cout << "Animal3 构造函数调用" << endl;
	}
	//virtual ~Animal3()利用虚析构可以解决，父类指针释放子类对象时不干净的问题
	//{
	//	cout << "Animal3 析构函数调用" << endl;代码实现
	//}
	virtual ~Animal3() = 0;//纯虚析构也可以解决，但是必须有代码实现
	virtual void speak() = 0;
};
Animal3::~Animal3()//Animal3 下的纯虚析构代码实现
{
	cout << "Animal3 析构函数调用" << endl;//既使用纯虚函数，又要释放父类在堆区中的数据，就需要使用纯虚析构
}
class Cat3 :public Animal3
{
public:
	Cat3(string name)
	{
		cout << "Cat3 构造函数调用" << endl;
		m_Name = new string(name);
	}
	virtual void speak()
	{
		cout << *m_Name << "小猫在说话" << endl;
	}
	string* m_Name;
	~Cat3()
	{
		if (m_Name != NULL)
		{
			cout << "Cat3 析构函数调用" << endl;
			delete m_Name;
			m_Name = NULL;
		}
	}
};
void test07()
{
	Animal2* animal1 = new Cat2("Tom");//没有运行 Cat2 析构函数调用，Cat2 不会释放，造成内存泄漏
	animal1->speak();
	delete animal1;
	Animal3* animal2 = new Cat3("Tom");//运行 Cat3 析构函数调用，Cat3 会释放，不会造成内存泄漏
	animal2->speak();
	delete animal2;
}

//电脑组装具体实现
class CPU
{
public:
	virtual void calculate() = 0;
};
class VideoCard
{
public:
	virtual void display() = 0;
};
class Memory
{
public:
	virtual void storage() = 0;
};
class IntelCPU : public CPU//IntelCPU
{
public:
	void calculate()
	{
		cout << "Intel 的 CPU 正在计算" << endl;
	}
};
class AMDCPU : public CPU//AMDCPU
{
public:
	void calculate()
	{
		cout << "AMD 的 CPU 正在计算" << endl;
	}
};
class NVIDIAGPU : public VideoCard//NVIDIAGPU
{
public:
	void display()
	{
		cout << "NVIDIA 的 GPU 正在显示" << endl;
	}
};
class AMDGPU : public VideoCard//AMDGPU
{
public:
	void display()
	{
		cout << "AMD 的 GPU 正在计算" << endl;
	}
};
class KingstonMemory : public Memory//KingstonMemory
{
public:
	void storage()
	{
		cout << "Kingston 的 Memory 正在存储" << endl;
	}
};
class CrucialMemory : public Memory//CrucialMemory
{
public:
	void storage()
	{
		cout << "Crucial 的 Memory 正在存储" << endl;
	}
};
class Computer
{
	
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	void work()
	{
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}
	~Computer()
	{
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_vc != NULL)
		{
			delete m_vc;
			m_vc = NULL;
		}
		if (m_mem != NULL)
		{
			delete m_mem;
			m_mem = NULL;
		}
	}
private:
	CPU* m_cpu;//CPU的零件指针
	VideoCard* m_vc;//显卡的零件指针
	Memory* m_mem;//内存的零件指针
};
void test08()
{
	CPU* intelCpu = new IntelCPU;
	VideoCard* nvidiaGpu = new NVIDIAGPU;
	Memory* kingstonMemory = new KingstonMemory;
	cout << "第一台电脑开始工作" << endl;//创建第一台电脑
	Computer* computer1 = new Computer(intelCpu, nvidiaGpu, kingstonMemory);
	computer1->work();
	delete computer1;
	cout << "第二台电脑开始工作" << endl;//创建第二台电脑
	Computer* computer2 = new Computer(new AMDCPU, new AMDGPU, new CrucialMemory);
	computer2->work();
	delete computer2;
	cout << "第三台电脑开始工作" << endl;//创建第三台电脑
	Computer* computer3 = new Computer(new AMDCPU, new NVIDIAGPU, new KingstonMemory);
	computer3->work();
	delete computer3;
}

int main()
{
//多态的基本语法 2025.10.31
	//多态是 C++ 面向对象三大特性之一：一个接口有多个形态
	//多态分为两类
		//静态多态: 函数重载和运算符重载属于静态多态，复用函数名
		//动态多态: 派生类和虚函数实现运行时多态
	//静态多态和动态多态区别：
		//静态多态的函数地址早绑定 - 编译阶段确定函数地址
		//动态多态的函数地址晚绑定 - 运行阶段确定函数地址
	//多态满足条件
		//有继承关系
		//子类重写父类中的虚函数，重写：函数返回值，函数名，参数列表完全相同
	//多态使用条件
		//父类指针或引用指向子类对象
	test01();

//多态的原理剖析
	//vfptr - 虚函数（表）指针，vftable - 虚函数表：v - virtual, f -function, ptr - pointer, table - table
	//Animal1 内部结构：vfptr -> vftable ->&Animal::speak
	//Cat1 内部结构：vfptr -> vftable ->&Cat1::speak，覆盖从 Animal1 继承下来的 &Animal::speak
	test02();

//计算器类案例
	//案例描述：分别利用普通写法和多态技术，设计实现两个操作数进行运算的计算器类
	//多态的优点：
		//代码组织结构清晰
		//可读性强
		//利于前期和后期的扩展以及维护
	test03();
	test04();

//纯虚函数和抽象类
	//在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容，因此可以将虚函数改为纯虚函数
	//纯虚函数语法：virtual 返回值类型 函数名 （参数列表） = 0;
	//当类中有了纯虚函数，这个类也称为抽象类
	//抽象类特点：
		//无法实例化对象
		//子类必须重写抽象类中的纯虚函数，否则也属于抽象类
	test05();

//制作饮品案例2
	//制作饮品的大致流程为：煮水 - 冲泡 - 倒入杯中 - 加入辅料
	//利用多态技术实现本案例，提供抽象制作饮品基类，提供子类制作咖啡和茶叶
	test06();

//虚析构和纯虚析构
	//多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码
	//解决方式：将父类中的析构函数改为虚析构或者纯虚析构
	//虚析构和纯虚析构共性：
		//可以解决父类指针释放子类对象
		//都需要有具体的函数实现
	//虚析构和纯虚析构区别：如果是纯虚析构，该类属于抽象类，无法实例化对象
	//虚析构语法：
		//virtual ~类名() {}
	//纯虚析构语法：
		//virtual ~类名() = 0; 
		//类名::~类名() {}
	//总结：
		//1. 虚析构或纯虚析构就是用来解决通过父类指针释放子类对象
		//2. 如果子类中没有堆区数据，可以不写为虚析构或纯虚析构
		//3. 拥有纯虚析构函数的类也属于抽象类，无法实例化对象
	test07();

//电脑组装需求分析
	//电脑主要组成部件为 CPU（用于计算），显卡（用于显示），内存条（用于存储），将每个零件封装出抽象基类，并且提供不同的厂商生产不同的零件，例如Intel厂商和Lenovo厂商
	//创建电脑类提供让电脑工作的函数，并且调用每个零件工作的接口，测试组装三台不同的电脑进行工作

//电脑组装具体实现
	test08();

	system("pause");
	return 0;
}
*/