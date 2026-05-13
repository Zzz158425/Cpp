#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
#include<list>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include "md5.h"
using namespace std;

/*
//一致性哈希算法实现
//虚拟节点
using unit = unsigned int;//一致性哈希环的取值类型
class PhscialHost;//前置生命物理节点主机类型
class VirtualHost
{
public:
	VirtualHost(string ip, PhscialHost* p)
		: ip_(ip)
		, phscialHost_(p)
	{
		md5_ = ::getMD5(ip_.c_str());//string 转 const char*
	}
	//set 底层为红黑树，需对存放的数据进行排序，此时虚拟节点为自定义的对象无法进行 < 比较，需对 < 进行重载
	bool operator<(const VirtualHost& host) const
	{
		return md5_ < host.md5_;
	}
	//提供自定义对象的 = 重载
	bool operator==(const VirtualHost& host) const
	{
		return ip_ == host.ip_;//物理主机 ip 不一致
	}
	unit getMD5() const
	{
		return md5_;
	}
	const PhscialHost* getPhscialHost() const
	{
		return phscialHost_;
	}
private:
	string ip_;//虚拟节点的 ip 信息
	unit md5_;//虚拟节点在一致性哈希环上的位置
	PhscialHost* phscialHost_;//虚拟节点隶属的物理节点位置
};
//物理节点
class PhscialHost
{
public:
	PhscialHost(string ip, int vnumber)
		: ip_(ip)
	{
		for (int i = 0; i < vnumber; i++)
		{
			virtualHosts_.emplace_back(ip + "#" + ::to_string(i), this);//记录虚拟节点 ip 与其所属的物理节点
		}
	}
	string getIP()const
	{
		return ip_;
	}
	const list<VirtualHost>& getVirtualHosts() const
	{
		return virtualHosts_;
	}
private:
	string ip_;//物理机器的 ip 地址
	list<VirtualHost> virtualHosts_;//存储虚拟节点列表
};
//一致性哈希
class ConsistentHash
{
public:
	//在一致性哈希环上添加物理主机的虚拟节点
	void addHost(PhscialHost& host)
	{
		//获取物理主机所有的虚拟节点列表
		auto list = host.getVirtualHosts();
		for (auto host : list)
		{
			hashCircle_.insert(host);
		}
	}
	//在一致性哈希环上删除物理主机的虚拟节点
	void delHost(PhscialHost& host)
	{
		//获取物理主机所有的虚拟节点列表
		auto list = host.getVirtualHosts();
		for (auto host : list)
		{
			auto it = hashCircle_.find(host);
			//在一致性哈希环上删除所有物理主机对应的虚拟节点
			if (it != hashCircle_.end())
			{
				hashCircle_.erase(it);
			}
		}
	}
	//返回负载的真实物理节点的 ip 信息
	string getHost(string clinentip)
	{
		unit md5 = getMD5(clinentip.c_str());
		for (auto vhost : hashCircle_ )
		{
			if (vhost.getMD5() > md5)
			{
				return vhost.getPhscialHost()->getIP();
			}
		}
		//从 0 开始遇见的第一个虚拟节点
		return hashCircle_.begin()->getPhscialHost()->getIP();
	}
private:
	set<VirtualHost> hashCircle_;//一致性哈希环
};
//展示服务器与请求信息
void ShowConsistentHsh(ConsistentHash& chash)
{
	//请求 ip
	list<string> iplists{
		"192.168.1.123",
		"192.168.1.12",
		"192.168.1.13",
		"192.168.1.23",
		"192.168.1.54",
		"192.168.1.89",
		"192.168.1.21",
		"192.168.1.27",
		"192.168.1.49",
		"192.168.1.145",
		"192.168.2.34",
		"192.168.6.78",
		"192.168.2.90",
		"192.168.4.5"
	};
	map<string, list<string>> logMap;//string 物理主机，list<string> 映射到物理主机上的用户 ip
	for (auto clientip : iplists)
	{
		string host = chash.getHost(clientip);
		logMap[host].emplace_back(clientip);
	}
	for (auto pair : logMap)
	{
		cout << "物理主机：" << pair.first << endl;
		cout << "客户端映射的数量：" << pair.second.size() << endl;
		for (auto ip : pair.second)
		{
			cout << ip << endl;
		}
		cout << "----------------------------" << endl;
	}
}

int main()
{
//一致性哈希算法思想
	//分布式系统负载均衡的首选算法：一致性哈希算法(Consistent Hashing) 
	//服务器负载均衡环境下，可以配置的负载均衡算法有很多。如轮询算法、哈希算法、权重比算法、最少连接算法等等
	//一个良好的分布式哈希方案应该具有良好的单调性，即服务节点的增减不会造成大量哈希的重新定位
	//一致性哈希算法描述：
		//1.一致性哈希算法将整个哈希值空间理解成一个环，取值范围是0-2^32 - 1 (unsigned int) 共 4G 的整数空间
		//2.将所以服务器进行哈希，最终落在这个一致性哈希环上
		//3.进行负载时，先哈希输入值得到一致性哈希环上的一个哈希值，然后沿着顺时针，遇到的第一台服务器，就是最终负载到的服务器
		//当一台服务器出现异常后，只会影响到原先映射到问题服务器的请求，其余的请问映射并未改变，从而不会造成大量哈希的重新定位
		//当增加一台服务器后，只会影响到逆时针直到遇到上一台服务器间的请求，其余的请问映射并未改变，从而不会造成大量哈希的重新定位
	//一致性哈希环的虚拟节点
		//将每个服务器分为 100-200 个虚拟节点，均匀的分布在哈希环中
		//当请求映射到虚拟节点后，会映射到对应的物理节点服务器
		//防止物理节点过少，导致 hash 处理后，在一致性哈希环上分布不均匀，导致某一台服务器负载太多，其他服务器一直很空闲

//一致性哈希算法应用场景
	//负载场景
		//接入机负载均衡后端带 N 台服务器，接入机接收到请求，需要将请求平均分发到每台服务器上，每台服务器负责 1 / N 的服务处理
		//常见算法 hash(ip:port) mod N
		//IP address -----> 反向代理 ------> server1
		//                  负载均衡 ------> server2
		//                          ------> server3
		//会解决会话共享问题，需让同一客户端永远被映射到一台指定的 server 上
		//若当某一台服务器无法工作，或扩展服务器，普通的哈希函数会将客户端映射到与之前不同的 server 上，无法实现会话共享问题
	//缓存场景
		//常见算法 hash(ip:port) mod N
		//User data <-----> 缓存负载服务 <------> memcache1(redis)
		//                  负载均衡器   <------> memcache2(redis) <-----> DB
		//                              <------> memcache3(redis)
		//在高并发大流量情况下，redis 缓存会进行集群部署，用户的信息永远会被映射到一台指定的 memcache 上
		//若当某一 memcache 无法工作，或扩展 memcache，普通的哈希函数会将客户端映射到与之前不同的 memcache 上
		//此时，大量的用户信息查询请求因为无法获取存有其信息的 memcache 中，会将全部查询请求送到数据库中，可能会使数据库崩溃
	
//一致性哈希算法实现
	PhscialHost host1("10.117.124.10", 150);
	PhscialHost host2("10.117.124.20", 150);
	PhscialHost host3("10.117.124.30", 150);
	ConsistentHash chash;
	chash.addHost(host1);
	chash.addHost(host2);
	chash.addHost(host3);
	ShowConsistentHsh(chash);
	//模拟 host1 有故障
	chash.delHost(host1);
	ShowConsistentHsh(chash);

//MD5 算法与应用
	//应用：加密、哈希函数、验证、云盘大文件秒传
	cout << getMD5("110") << endl;
	cout << getMD5("111") << endl;
	cout << getMD5("192.168.1.100#0") << endl;
	cout << getMD5("192.168.1.100#1") << endl;

	system("pause");
	return 0;
}
*/