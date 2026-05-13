#include<iostream>
#include<typeinfo>
using namespace std;
//2026.2.28

/*
//C++ 运算符重载
class CComplex
{
public:
	CComplex(int r = 0, int i = 0)
		: mreal(r), mimage(i) { }
	//指导编译器怎么做 CComplex 类对象的加法操作
	CComplex operator+(const CComplex& src)
	{
		CComplex temp;
		temp.mreal = this->mreal + src.mreal;
		temp.mimage = this->mimage + src.mimage;
		return temp;
		//return CComplex(this->mreal + src.mreal, this->mimage + src.mimage);也可以这样
	}
	CComplex operator++(int)
	{
		CComplex comp = *this;
		mreal += 1;
		mimage += 1;
		return comp;
		//reurn CComplex(mreal++, mimage++);也可以这样
	}
	CComplex& operator++()//效率比后置 ++ 高，因为不产生临时对象
	{
		mreal += 1;
		mimage += 1;
		return *this;
	}
	void operator+=(const CComplex& src)
	{
		mreal += src.mreal;
		mimage += src.mimage;
	}
	void show() { cout << "real:" << mreal << "mimage" << mimage << endl; }
private:
	int mreal;
	int mimage;
	friend CComplex operator+(const CComplex& lhs, const CComplex& rhs);
	friend ostream& operator<<(ostream& out, const CComplex& src);
	friend istream& operator>>(istream& out, CComplex& src);
};
//全局加法运算符的重载函数
CComplex operator+(const CComplex& lhs, const CComplex& rhs)
{
	return CComplex(lhs.mreal + rhs.mreal, lhs.mimage + rhs.mimage);
}
//全局输出运算符的重载函数
ostream& operator<<(ostream& out, const CComplex& src)//流对象是不断变化的，不能加 const
{
	out << "real:" << src.mreal << "mimage" << src.mimage << endl;
	return out;
}
//全局输入运算符的重载函数
istream& operator>>(istream& in, CComplex& src)//流对象是不断变化的，不能加 const
{
	in >> src.mreal >> src.mimage;
	return in;
}

int main()
{
//C++ 运算符重载
	//使对象的运算表现得和编译器内置类型一样
	//编译器在做对象运算的时候，会调用对象的运算符重载函数（优先调用成员方法），如果没有成员方法，就在全局作用域找合适的运算符重载函数
	//前置 ++ 重载：operator++()，后置 ++ 重载：operator++(int)
	CComplex comp1(10, 10);
	CComplex comp2(20, 20);
	CComplex comp3 = comp1 + comp2;//comp1.operator+(comp2) 加法运算符的重载函数
	comp3.show();
	CComplex comp4 = comp1 + 20;//隐式类型转换，int -> CComplex
	comp4.show();
	CComplex comp5 = 30 + comp1;//需添加全局加法运算符的重载函数，::operator+(30, comp1)
	comp5.show();
	comp5 = comp1++;
	comp1.show();
	comp5.show();
	comp5 = ++comp1;
	comp1.show();
	comp5.show();
	comp1 += comp2;//需添加复合运算符的重载函数
	comp1.show();
	cout << comp1 << endl;//需提供全局输出运算符的重载函数，因为对象在右边，无法通过提供成员方法来实现
	cin >> comp1 >> comp2;//需提供全局输入运算符的重载函数
	cout << comp1 << comp2 << endl;

	system("pause");
	return 0;
}
*/
