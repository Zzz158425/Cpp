#include<iostream>
#include<thread>
#include<mutex>
#include<list>
#include<memory>
using namespace std;

/*
//抽象类
class VideoSite
{
public:
	virtual void freeMovie() = 0;//免费电影
	virtual void vipMovie() = 0;//VIP 电影
	virtual void ticketMovie() = 0;//用卷观看电影
};
//委托类
class FixBugVideoSite : public VideoSite
{
public:
	virtual void freeMovie()
	{
		std::cout << "观看免费电影" << std::endl;
	}
	virtual void vipMovie()
	{
		std::cout << "观看 VIP 电影" << std::endl;
	}
	virtual void ticketMovie()
	{
		std::cout << "观看用券电影" << std::endl;
	}
};
//代理类
class FreeVideoSiteProxy : public VideoSite
{
public:
	FreeVideoSiteProxy() { pVideo = new FixBugVideoSite(); }////代理 FixBugVideoSite
	~FreeVideoSiteProxy() { delete pVideo; }
	void freeMovie()
	{
		pVideo->freeMovie();
	}
	void vipMovie()
	{
		std::cout << "您目前只是普通游客，需要升级成 VIP，才能观看 VIP 电影" << std::endl;
	}
	void ticketMovie()
	{
		std::cout << "您目前没有电影卷，需要购买电影券，才能观看电影" << std::endl;
	}
private:
	VideoSite* pVideo;
};
class VIPVideoSiteProxy : public VideoSite
{
public:
	VIPVideoSiteProxy() { pVideo = new FixBugVideoSite(); }////代理 FixBugVideoSite
	~VIPVideoSiteProxy() { delete pVideo; }
	void freeMovie()
	{
		pVideo->freeMovie();
	}
	void vipMovie()
	{
		pVideo->vipMovie();
	}
	void ticketMovie()
	{
		std::cout << "您目前没有电影卷，需要购买电影券，才能观看电影" << std::endl;
	}
private:
	VideoSite* pVideo;
};
void watchMovice(unique_ptr<VideoSite> &ptr)
{
	ptr->freeMovie();
	ptr->ticketMovie();
	ptr->vipMovie();
}

int main()
{
//结构性模式
	//这些设计模式关注类和对象的组合，继承的概念被用来组合接口和定义组合对象获得新功能的方式
	//适配器模式（Adapter Pattern），桥接模式（Bridge Pattern）
	//过滤器模式（Filter、Criteria Pattern），组合模式（Cposite Pattern）
	//装饰器模式（Decorator Pattern），外观模式（Facade Pattern）
	//享元模式（Flyweight Pattern），代理模式（Proxy Pattern）

//代理模式（Proxy Pattern）
	//通过代理类，来控制实际对象的访问权限
	//客户 -> 助理（Proxy）-> 老板 or 经理
	VideoSite* p1 = new FixBugVideoSite();
	p1->freeMovie();
	p1->ticketMovie();
	p1->vipMovie();
	cout << "----------代理访问----------" << endl;
	VideoSite* free = new FreeVideoSiteProxy();
	free->freeMovie();
	free->ticketMovie();
	free->vipMovie();
	VideoSite* vip = new VIPVideoSiteProxy();
	vip->freeMovie();
	vip->ticketMovie();
	vip->vipMovie();
	//智能指针
	cout << "----------智能指针----------" << endl;
	unique_ptr<VideoSite> p2(new FreeVideoSiteProxy());
	unique_ptr<VideoSite> p3(new VIPVideoSiteProxy());
	watchMovice(p2);
	watchMovice(p3);

	system("pause");
	return 0;
}
*/