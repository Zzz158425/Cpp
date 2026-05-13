#include<iostream>
#include<thread>
#include<mutex>
#include<list>
#include<memory>
using namespace std;

/*
//接口类
class VGA
{
public:
	virtual void play() = 0;
};
class HDMI
{
public:
	virtual void play() = 0;
};
//表示支持 VGA/HDMI 接口的投影仪
class TV01 : public VGA
{
public:
	void play()
	{
		std::cout << "通过VGA接口连接投影仪，进行视频播放" << std::endl;
	}
};
class TV02 : public HDMI
{
public:
	void play()
	{
		std::cout << "通过HDMI接口连接投影仪，进行视频播放" << std::endl;
	}
};
//电脑类（VGA）
class Computer
{
public:
	void playVideo(VGA* pVGA)
	{
		pVGA->play();
	}
};
//适配器类
class VGAToHDMIAdapter : public VGA
{
public:
	VGAToHDMIAdapter(HDMI* p) : pHdmi(p) {}
	void play() { pHdmi->play(); }//转换头
private:
	HDMI* pHdmi;
};

int main()
{
//适配器模式
	//让不兼容的接口可以在一起工作
	Computer computer;
	computer.playVideo(new TV01());
	//computer.playVideo(new TV02());接口不兼容
	computer.playVideo(new VGAToHDMIAdapter(new TV02()));

	system("pause");
	return 0;
}
*/