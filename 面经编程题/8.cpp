/*广告，有id，上线时间和下线时间，给定一个时间判断有多少广告在线*/

#include<iostream>
#include<map>
using namespace std;
int main()
{
	int n = 0;
	//判断该时间多少个广告上线
	int t = 0;
	cout<<"请输入广告个数N"<<endl;
	cin>>n;
	map<int ,int> b;
	map<int ,int> e;
	int bg, ed;
	cout<<"请输入每个广告的上线和下线时间，用空格隔开"<<endl;
	for(int i = 0; i< n;i++)
	{
		cin>>bg>>ed;
		b.insert(make_pair(i,bg));
		e.insert(make_pair(i,ed));
	}
	cout<<"请输入需要判断的时间"<<endl;
	cin>>t;
	int count = 0;
	for(map<int,int>::iterator iter = b.begin();iter != b.end();iter++)
	{
		//遍历开始时间，根据id找到对应的结束时间，
		int id = iter->first;
		int d = (e.find(id))->second;
		//需要判断的时间是否在该广告的时间段内，若是，则计数++
		if(t>=iter->second && t <= d)
			++count;
	}
	cout<<"在线广告数为："<<count<<endl;
	
	return 0;
}


