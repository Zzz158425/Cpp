#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

/*
//利用分治算法思想实现二分搜索
bool binarySearch(vector<int>& vec, int i, int j, int val)
{
	if (i > j)//元素不存在
	{
		return false;
	}
	int mid = (i + j) / 2;
	if (vec[mid] == val)
	{
		return true;
	}
	if (vec[mid] > val)
	{
		return binarySearch(vec, i, mid - 1, val);
	}
	else
	{
		return binarySearch(vec, mid + 1, j, val);
	}
}

//利用分治算法思想实现快速排序
//快排划分
int partation(vector<int>& vec1, int i, int j)
{
	int val = vec1[i];//作为基准数
	int l = i;
	int r = j;
	while (l < r)
	{
		while (l < r && vec1[r] > val)//从右边一直找小于 val 的值
		{
			r--;
		}
		if (l < r)//找到了比 val 小的数，进行交换
		{
			vec1[l++] = vec1[r];
		}
		while (l < r && vec1[l] < val)//从右边一直找大于 val 的值
		{
			l++;
		}
		if (l < r)
		{
			vec1[r--] = vec1[l];//找到了比 val 大的数，进行交换
		}
	}
	vec1[l] = val;
	return l;//返回基准数的下标
}
//快速排序
void quickSort(vector<int>& vec1, int i, int j)
{
	if (i >= j)
	{
		return;
	}
	int pos = partation(vec1, i, j);
	quickSort(vec1, i, pos - 1);
	quickSort(vec1, pos + 1, j);
}

//利用分治算法思想的快速排序求 top-k 问题
//求第 top-10 大的元素
int max_select_topk(vector<int>& vec2, int i, int j, int k)
{
	int pos = partation(vec2, i, j);//pos 表示基准数的位置
	if (pos == vec2.size() - k)//表示基准数的位置和 top-k 的 k 值相等了
	{
		return vec2[pos];
	}
	else if (pos < vec2.size() - k)//top-k 在基准数右边 
	{
		return max_select_topk(vec2, pos + 1, j, k);
	}
	else//top-k 在基准数左边 
	{
		return max_select_topk(vec2, i, pos - 1, k);
	}
}
//求第 top-10 小的元素
int min_select_topk(vector<int>& vec2, int i, int j, int k)
{
	int pos = partation(vec2, i, j);//pos 表示基准数的位置
	if (pos == k - 1)//表示基准数的位置和 top-k 的 k 值相等了
	{
		return vec2[pos];
	}
	else if (pos < k - 1)//top-k 在基准数右边 
	{
		return min_select_topk(vec2, pos + 1, j, k);
	}
	else//top-k 在基准数左边 
	{
		return min_select_topk(vec2, i, pos - 1, k);
	}
}

//利用分治算法思想实现归并排序 2026.3.22
void merge(vector<int>& vec4, int low, int high, int mid)
{
	vector<int> temp;//定义额外的辅助空间，存储合并的子问题的有序数组
	temp.reserve(high - low + 1);
	int i = low;//[low, mid]
	int j = mid + 1;//[mid + 1, high]
	while (i <= mid && j <= high)
	{
		if (vec4[i] > vec4[j])
		{
			temp.push_back(vec4[j++]);
		}
		else
		{
			temp.push_back(vec4[i++]);
		}
	}
	//只添加完成一边，另一边继续添加
	while (i <= mid)
	{
		temp.push_back(vec4[i++]);
	}
	while (j <= high)
	{
		temp.push_back(vec4[j++]);
	}
	//将 temp 元素合并到 vec4 中
	for (int k = low; k <= high; k++)
	{
		vec4[k] = temp[k - low];
	}
}
void mergeSort(vector<int>& vec4, int i, int j)
{
	if (i == j)//子问题划分到只有一个元素结束
	{
		return;
	}
	int mid = (i + j) / 2;
	//先划分子问题，降低问题规模
	mergeSort(vec4, i, mid);
	mergeSort(vec4, mid + 1, j);
	//向上回溯，合并子问题的解
	merge(vec4, i, j, mid);
}

//利用分治算法思想实现合并 K 个有序单链表
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) { }
};
ListNode* init_link(initializer_list<int> list)//initializer_list<int> 是 C++11 用来接收{ 1,3,5,7 } 这种初始化列表的工具
{
	ListNode* head = nullptr;
	ListNode* p = nullptr;
	for (int v : list)
	{
		if (head == nullptr)
		{
			head = new ListNode(v);
			p = head;
		}
		else
		{
			p->next = new ListNode(v);
			p = p->next;
		}
	}
	return head;
}
ListNode* mergeTwoLink(ListNode* p1, ListNode* p2)
{
	ListNode* head = nullptr;
	if (p1 == nullptr)
	{
		return p2;
	}
	if (p2 == nullptr)
	{
		return p1;
	}
	if (p1->val < p2->val)
	{
		head = p1;
		p1 = p1->next;
	}
	else
	{
		head = p2;
		p2 = p2->next;
	}
	ListNode* p = head;
	while (p1 != nullptr && p2 != nullptr)
	{
		if (p1->val > p2->val)
		{
			p->next = p2;
			p = p2;
			p2 = p2->next;
		}
		else
		{
			p->next = p1;
			p = p1;
			p1 = p1->next;
		}
	}
	if (p1 != nullptr)
	{
		p->next = p1;
	}
	if (p2 != nullptr)
	{
		p->next = p2;
	}
	return head;
}
ListNode* mergeLink(vector<ListNode*>& vlink, int i, int j)
{
	if (i >= j)//子问题划分到只剩下一个链表了
	{
		return vlink[i];
	}
	int mid = (i + j) / 2;
	ListNode* left = mergeLink(vlink, i, mid);
	ListNode* right = mergeLink(vlink, mid + 1, j);
	return mergeTwoLink(left, right);//归结成合成两个有序链表
}

//利用分治算法思想对数时间求中位数算法
double middleValue(vector<int>& nums1, int length1, vector<int>& nums2, int length2)
{
	if (length1 > length2)//在短的数组中求解合适的 i 和 j 值
	{
		return middleValue(nums2, length2, nums1, length1);
	}
	//传入了一个空数列的情况
	if (length1 == 0)
	{
		int k = (length2 - 1) / 2;
		if (length2 % 2 == 0)
		{
			return (nums2[k] + nums2[k + 1]) * 1.0 / 2;
		}
		else
		{
			return nums2[k];
		}
	}
	int i = 0;
	int j = 0;
	int begin = 0;
	int end = length1;
	int k = (length1 + length2 + 1) / 2;
	//二分搜索，对数时间找到 i + j = k
	while (begin <= end)
	{
		i = (begin + end) / 2;
		j = k - i;
		if (i > 0 && j < length2 && nums1[i - 1] > nums2[j])
		{
			end = i - 1;
		}
		else if (j > 0 && i < length1 && nums2[j - 1] > nums1[i])
		{
			begin = i + 1;
		}
		else
		{
			break;//找到了
		}
	}
	int left = 0;
	int right = 0;
	if (i == 0)
	{
		left = nums2[j - 1];//nums1 特别短且元素的值都特别大，中位数落在了 nums2 这个数组中
	}
	else if (j == 0)
	{
		left = nums1[i - 1];//nums2 特别短且元素的值都特别大，中位数落在了 nums1 这个数组中
	}
	else
	{
		left = max(nums1[i - 1], nums2[j - 1]);
	}
	if (i == length1)
	{
		right = nums2[j];//nums1 特别短且元素的值都特别小，中位数落在了 nums2 这个数组中
	}
	else if (j == length2)
	{
		right = nums1[i];//nums2 特别短且元素的值都特别小，中位数落在了 nums1 这个数组中
	}
	else
	{
		right = min(nums1[i], nums2[j]);
	}
	//找到了合适的 i 和 j 的值
	if ((length1 + length2) % 2 == 0)
	{
		return (left + right) * 1.0 / 2;//偶数长度
	}
	else
	{
		return left;//奇数长度
	}
}

int main()
{
//分治算法思想 2026.3.21
	//规模为 n 的原问题的解无法直接求出，进行问题规模缩减，划分子问题（这里子问题相互独立而且和原问题解的性质是相同的，只是问题规模缩小了）
	//如果子问题的规模仍然不够小，再进行子问题划分，如此递归的进行下去，直到问题规模足够小，很容易求出其解为止
	//最后将求出的小规模的问题的解合并为一个更大规模的问题的解，自底向上逐步求出原问题的解
	//分治算法适用条件：分治法所能解决的问题一般具有以下几个特征:
		//1.原问题的规模缩小到一定的程度就可以容易地解决
		//2.原问题可以分解为若干个规模较小的相同问题，即原问题具有最优子结构性质
		//3.利用原问题分解出的子问题的解可以合并为原问题的解
		//4.原问题所分解出的各个子问题是相互独立的，即子问题之间不包含公共的子问题（这条特征涉及到分治法的效率，如果各个子问题不独立，也就是子问题划分有重合的部分，则分治法要重复的求解公共子问题的解，此时虽然也可用分治法，但采用动态规划更好）

//利用分治算法思想实现二分搜索
	vector<int> vec;
	for (int i = 0; i < 11; i++)
	{
		vec.push_back(rand() % 100);
	}
	sort(vec.begin(), vec.end());
	for (int v: vec)
	{
		cout << v << " ";
	}
	cout << endl;
	bool result = binarySearch(vec, 0, vec.size() - 1, 34);
	cout << "result:" << result << endl;

//利用分治算法思想实现快速排序
	vector<int> vec1;
	for (int i = 0; i < 11; i++)
	{
		vec1.push_back(rand() % 100);
	}
	for (int v : vec1)
	{
		cout << v << " ";
	}
	cout << endl;
	quickSort(vec1, 0, vec1.size() - 1);
	for (int v : vec1)
	{
		cout << v << " ";
	}
	cout << endl;

//利用分治算法思想的快速排序求 top-k 问题
	//常用的求 top-k 问题：大根堆/小根堆：优先级队列；快排划分
	//求第 top-10 大的元素
	vector<int> vec2;
	for (int i = 0; i < 20; i++)
	{
		vec2.push_back(rand() % 100);
	}
	int pos_max = max_select_topk(vec2, 0, vec2.size() - 1, 4);
	cout << "top-k_max:" << pos_max << endl;
	sort(vec2.begin(), vec2.end());
	for (int v : vec2)
	{
		cout << v << " ";
	}
	cout << endl;
	vector<int> vec3;
	for (int i = 0; i < 20; i++)
	{
		vec3.push_back(rand() % 100);
	}
	int pos_min = min_select_topk(vec3, 0, vec3.size() - 1, 4);
	cout << "top-k_min:" << pos_min << endl;
	sort(vec3.begin(), vec3.end());
	for (int v : vec3)
	{
		cout << v << " ";
	}
	cout << endl;

//利用分治算法思想实现归并排序 2026.3.22
	vector<int> vec4;
	for (int i = 0; i < 20; i++)
	{
		vec4.push_back(rand() % 100);
	}
	for (int v : vec4)
	{
		cout << v << " ";
	}
	cout << endl;
	mergeSort(vec4, 0, vec4.size() - 1);
	for (int v : vec4)
	{
		cout << v << " ";
	}
	cout << endl;

//利用分治算法思想实现合并 K 个有序单链表
	ListNode* p1 = init_link({ 3,6,8 });
	ListNode* p2 = init_link({ 2,4 });
	ListNode* p3 = init_link({ 1,5,9 });
	ListNode* p4 = init_link({ 0,7 });
	ListNode* p5 = init_link({ 10 });
	vector<ListNode*> vlink;
	vlink.push_back(p1);
	vlink.push_back(p2);
	vlink.push_back(p3);
	vlink.push_back(p4);
	vlink.push_back(p5);
	ListNode* p = mergeLink(vlink, 0, vlink.size() - 1);
	for (ListNode* c = p; c != nullptr; c = c->next)
	{
		cout << c->val << " ";
	}
	cout << endl;

//利用分治算法思想对数时间求中位数算法
	//直接将两链表合并或数组再去中位数，涉及到遍历链表/数组，时间复杂度为 O(n)
	//中位数（n 为序列个数）
		//偶数个数升序序列的中位数：(n / 2 + (n / 2) + 1) / 2
		//奇数个数升序序列的中位数：n / 2
	//有两个升序的数组，长度分别是 m 和 n，求两个数组所有元素的第 top-k 个元素
		//arr:    arr[0]  arr[1]  ...  arr[i - 1]  |  arr[i]  ...  arr[n]
		//                                         |
		//brr:    brr[0]  brr[1]  ...  brr[j - 1]  |  brr[j]  ...  brr[m]
		//使其满足 arr[i - 1] < brr[j] && brr[j - 1] < arr[j]，即左边元素的值全部小于右边元素的值
		//若左边元素的个数为 k，第 k 个元素的值 max(arr[i - 1], brr[j - 1])，即此时左边的元素为 top-k 个元素
		//若左边元素的个数大于 k，只需将 i 或 j 减小，直到 i + j = k
	//如果在上面两个升序数组中找中位数，就是找第 top-k 个元素，k 就是最中间的那个数字
		//其中 (m + n + 1) / 2 就是中位数的下标，即可求出中位值数的值 k
		//如果找到 k，总长度为偶数：(k + (k + 1)) / 2，总长度为奇数：k
		//关键：如何找到 i 和 j 
	vector<int> vec5;
	vector<int> vec6;
	for (int i = 0; i < 10; i++)
	{
		vec5.push_back(rand() % 100);
	}
	for (int i = 0; i < 5; i++)
	{
		vec6.push_back(rand() % 100);
	}
	sort(vec5.begin(), vec5.end());
	sort(vec6.begin(), vec6.end());
	vector<int> vec7 = vec5;
	for (int v : vec6)
	{
		vec7.push_back(v);
	}
	sort(vec7.begin(), vec7.end());
	for (int v : vec7 )
	{
		cout << v << " ";
	}
	cout << endl;
	double midval = middleValue(vec5, vec5.size(), vec6, vec6.size());
	cout << "midval:" << midval << endl;

	system("pause");
	return 0;
}
*/