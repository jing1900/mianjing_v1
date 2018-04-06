/*给定一个正数数组，里面有两个数相同，其他的都不同，请尽快找到这两个数*/
//思路：用map统计
#include<iostream>
#include<map>
using namespace std;
int main()
{
	int n= 0,i = 0;
	cout<<"请输入数组长度"<<endl;
	cin>>n;
	map<int,int> m;
	cout<<"请输入整形数组内容，用空格隔开"<<endl;
	int a = 0,count = 0;
	for(i = 0; i< n;i++)
	{
		cin>>a;
		//map中不存在，插入
		if(m.find(a) == m.end())
		{
			m.insert(make_pair(a,1));
		}
		//若存在，说明是相同的两个数
		else
		{
			m[a]++;
			cout<<a<<endl;
		}
	}
	/*
	map<int,int>::iterator iter;
	for(iter = m.begin();iter != m.end();iter++)
	{
		if(iter->second == 2)
		{
			cout<<iter->first<<endl;
			break;
		}
	}
	*/
}
