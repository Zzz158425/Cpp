//#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
#include<list>
#include<vector>
#include<algorithm>
#include<unordered_map>
#undef UNICODE
#include <Windows.h>
using namespace std;

/*
//利用倒排索引算法实现本地文档搜索引擎 2026.4.16
//倒排项
struct InvertTerm
{
	InvertTerm(string docid, int freqs, int locations)
		: docid_(docid)
		, freqs_(freqs)
	{
		locations_.emplace_back(locations);
	}
	bool operator==(const InvertTerm& term) const
	{
		return docid_ == term.docid_;
	}
	bool operator<(const InvertTerm & term) const
	{
		return docid_ < term.docid_;
	}
	string docid_;//单词所在的文档
	int freqs_;//单词出现的次数
	list<int> locations_;//单词出现的位置
};
//倒排列表
class InvertList
{
public:
	//添加倒排项
	void addTerm(string docid, int locations)
	{
		for (auto &term : termList_)
		{
			//docid 已经创建，更新对应倒排项的参数
			if (term.docid_ == docid)
			{
				term.freqs_++;
				term.locations_.emplace_back(locations);
				return;
			}
		}
		//docid 未创建，创建对应倒排项
		termList_.emplace_back(InvertTerm(docid, 1, locations));
	}
	//获取倒排列表内容
	const list<InvertTerm>& getInvertList() const
	{
		return termList_;
	}
private:
	list<InvertTerm> termList_;//存储当前倒排列表所有的倒排项
};
//倒排索引
class InvertIndex
{
public:
	//设置文档搜索的根路径
	void setSearchPath(string path)
	{
		cout << "搜索中...";
		getAllFile(path.c_str());//.c_str():string -> const char*
		cout << "搜索完成！" << endl;
		cout << "开始创建倒排索引";;
		createInvertIndex();
		cout << endl;
		cout << "创建完成！" << endl;
	}
	//设置文档搜索的后缀名过滤
	void setSuffix(string suffix)
	{
		suffix_ = suffix;
	}
	//查询接口
	void query(string phrase)
	{
		//对句子进行分词操作
		vector<string> wordList;
		char* word = strtok(const_cast<char*>(phrase.c_str()), " ");
		while (word != nullptr)
		{
			word = trim(word);
			if (strlen(word) > 0)
			{
				wordList.emplace_back(word);
			}
			word = strtok(nullptr, " ");
		}
		if (wordList.empty())
		{
			return;
		}
		//查询单个单词
		if (wordList.size() == 1)
		{
			auto it = invertMap_.find(wordList[0]);
			if (it == invertMap_.end())
			{
				cout << "未搜索到任何匹配的内容！" << endl;
				return;
			}
			for (auto& term : it->second.getInvertList())
			{
				cout << term.docid_ << " freqs_:" << term.freqs_ << endl;
			}
		}
		//查询句子
		else
		{
			//多个单词的搜索结果进行合并处理
			vector<InvertList> invertList;
			for (int i = 0; i < wordList.size(); i++)
			{
				auto it = invertMap_.find(wordList[i]);
				if (it != invertMap_.end())
				{
					invertList.emplace_back(it->second);
				}
			}
			//开始遍历所有的倒排列表，求里面倒排项的交集
			vector<InvertTerm> termShared;
			vector<InvertTerm> v1(invertList[0].getInvertList().begin(), invertList[0].getInvertList().end());
			for (int i = 1; i < invertList.size(); i++)
			{
				vector<InvertTerm> v2(invertList[i].getInvertList().begin(), invertList[i].getInvertList().end());
				sort(v1.begin(), v1.end());
				sort(v2.begin(), v2.end());
				set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(termShared));//将 v1 与 v2 的交集插入到 termShared，v1 与 v2 需有序，InvertTerm 需提供 <、== 运算符重载
				v1.swap(termShared);//将存入的交集放入 v1 中
				termShared.clear();
			}
			//得分排名比较高的倒排项
			for (auto& term : v1)
			{
				cout << term.docid_ << " freqs_:" << term.freqs_ << endl;
				cout << "location:";
				for (int pos : term.locations_)
				{
					cout << pos << " ";
				}
				cout << endl;
			}
		}
	}
private:
	//去掉分词后，单词前后多余的字符 \t\t\tsdfads\t\n
	char* trim(char* word)
	{
		int i = 0;
		while (word[i] != '\0')
		{
			if (word[i] == ' ' || word[i] == '\t' || word[i] == '\n')
			{
				i++;
			}
			else
			{
				break;
			}
		}
		int j = i;
		while (word[j] != '\0')
		{
			if (word[j] == ' ' || word[j] == '\t' || word[j] == '\n')
			{
				break;
			}
			j++;
		}
		word[j] = '\0';
		return word + i;
	}
	//递归倒排索引结构
	void createInvertIndex()
	{
		for (string& filePath : fileList_)
		{
			cout << ".";
			FILE* pf = fopen(filePath.c_str(), "r");
			if (pf == nullptr)
			{
				cout << filePath << " >>> 打开失败！" << endl;
				continue;
			}
			//按行读取文件里面的内容，按照 " " 空格进行分词
			vector<string> wordList;
			int location = 0;
			const int LINE_SIZE = 2048;
			char line[LINE_SIZE] = { 0 };
			while (!feof(pf))
			{
				fgets(line, LINE_SIZE, pf);//读一行文件内容
				//按照 " " 空格进行分词，split strtok
				char* word = strtok(line, " ");
				while (word != nullptr)
				{
					word = trim(word);//过滤一下 word 前后的多余的空格 \t \n
					if (strlen(word) > 0)
					{
						wordList.emplace_back(word);
					}
					word = strtok(nullptr, " ");//传 nullptr 即可，strtok 已记录 line
				}
			}
			//开始给 wordList 里面的单词创建或者修改倒排列表
			for (string& w : wordList)
			{
				location++;
				auto it = invertMap_.find(w);
				if (it == invertMap_.end())
				{
					//新建 w 单词的倒排列表
					InvertList list;
					list.addTerm(filePath, location);
					invertMap_.emplace(w, list);
				}
				else
				{
					it->second.addTerm(filePath, location);
				}

			}
			fclose(pf);
		}
	}
	//Windows 平台下用 C 语言 API 递归遍历指定目录下所有文件和子目录
	int getAllFile(const char* Path)
	{
		char szFind[MAX_PATH];//MAX_PATH：Windows 定义的宏，值是 260，表示路径的最大长度（经典限制）
		WIN32_FIND_DATA FindFileData;//WIN32_FIND_DATA：Windows 专门用来存文件信息的结构体，里面有文件名、文件属性、大小等
		strcpy(szFind, Path);//把传入的 Path 复制到 szFind
		strcat(szFind, "\\*.*");//拼接成 "路径\\*.*"（*.* 表示搜索所有文件/文件夹）
		//开始查找第一个文件/文件夹，如果查找失败返回 -1
		HANDLE hFind = FindFirstFile(szFind, &FindFileData);//FindFirstFile：Windows API 函数，用来开始查找文件/文件夹
		if (INVALID_HANDLE_VALUE == hFind)//INVALID_HANDLE_VALUE：Windows 定义的宏，表示无效的句柄（查找失败）
			return -1;
		//遍历所有文件 / 文件夹
		do
		{
			if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)//判断是不是文件夹
			{
				if (strcmp(FindFileData.cFileName, ".") != 0 && strcmp(FindFileData.cFileName, "..") != 0)//排除 "."（当前目录）和 ".."（上级目录）
				{
					//发现子目录，递归
					char szFile[MAX_PATH] = { 0 };
					strcpy(szFile, Path);//把父目录路径复制进去
					strcat(szFile, "\\");//拼接一个反斜杠
					strcat(szFile, FindFileData.cFileName);//拼接上子目录的名字
					getAllFile(szFile);
				}
			}
			else
			{
				//找到文件，处理
				string fileName(FindFileData.cFileName);
				int pos = fileName.find(suffix_);//找后缀在文件名里的位置，abcd.cpp -> pos:4 
				if (pos != string::npos && pos + suffix_.size() == fileName.size())//find 没找到 .cpp，返回 string::npos
				{
					//std::cout << Path << "\\" << FindFileData.cFileName << std::endl;
					string filePath(Path);
					filePath.append("\\");
					filePath.append(fileName);
					fileList_.emplace_back(filePath);
				}
			}
		} while (FindNextFile(hFind, &FindFileData));//FindNextFile 是 Windows API 函数，专门用来查找下一个文件/文件夹
		FindClose(hFind);//FindClose：Windows API 函数，用来关闭查找句柄，释放系统资源
		return 0;
	}
	string suffix_;//过滤文档后缀
	list<string> fileList_;//存储所有需要建立倒排的文件
	unordered_map<string, InvertList> invertMap_;//存储倒排索引
};

int main()
{
//倒排索引算法思想
	//倒排索引常使用在搜索引擎当中，是搜索引擎为文档内容建立索引，实现内容快速检索必不可少的数据结构
	//倒排索引是由单词的集合“词典”和倒排列表的集合“倒排文件”组成的
	//倒排索引的存储：内存索引和 B+ 树索引
	//倒排索引算法应用：
		//1.搜索引擎：Baidu,Google...
			//将 keywords 通过发送 http 请求	到搜索引擎公司的 server 上
			//搜索引擎公司的 server 启动后，在提供搜索服务之前，已经给全网搜到的 html 网页页面内容建立了倒排索引结构
		//2.搜索服务：Alibaba,JDG...
	//全文搜索：即对文档总的所有句子或词语建立索引，提供快速的检索功能
	//全文搜索两种方法：
		//1.全文本匹配搜索
		//2.利用索引进行全文搜索
	//正排索引结构与倒排索引结构
		//以 P1:i like search engines,P2:i search keywords in google 为例
			//正排索引结构：行为文档，列为单词
				//    i like search engine keyword in google
				//P1  1 1    1      1      0       0  0
				//P2  1 0    1      0      1       1  1
			//倒排索引结构：行为单词，列为文档，倒排索引 = 词典 + 倒排文件
				//词典     倒排文件	
				//         P1（倒排项）P2（倒排项）
				//engine   1          0          engine  p1（倒排列表）
				//google   0		  1          google  p2
				//i        1		  1          i       p1,p2
				//in	   0		  1   --->   in      p2
				//keyword  0		  1          keyword p2
				//like     1		  0          like    p1
				//search   1		  1          search  p1,p2

//利用倒排索引算法实现本地文档搜索引擎 2026.4.16
	InvertIndex index;
	index.setSuffix(".cpp");
	index.setSearchPath("D:\\Visual Studio2022SharedProject\\C ++\\Data Structure");
	for (;;)
	{
		char buf[128] = { 0 };
		cout << "搜索内容：";
		cin.getline(buf, 128);
		index.query(buf);
	}
	cout << endl;

	system("pause");
	return 0;
}
*/
