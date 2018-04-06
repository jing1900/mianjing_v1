#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> remove(vector<int> a,int n)
{
	if(n <=1)
		return a;
	bool flag = false;//是否有重
	int tmp;//最新的连续重复值位
	stack<int> s;
	vector<int> r;
	for(int i = 0;i<n;i++)
	{
		if(s.empty() == true)
		{
			if(flag == false)
				s.push(a[i]);
			else if(a[i]!= tmp)
				s.push(a[i]);
			else
				continue;
		}
		else
		{
			/*if(a[i] == s.top())
			{
				flag = true;
				tmp = s.top();
				s.pop();
			}*/
			if(flag == true)
			{
				if(a[i] == tmp)
				{
					continue;
				}
				else if(a[i] == s.top())
				{
					flag = true;
					tmp = a[i];
					s.pop();
				}
				else
				{
					s.push(a[i]);
					flag = false;
					//tmp = a[i];
				}
				
			}
			else
			{
				if(a[i] == s.top())
				{
					flag = true;
					tmp = s.top();
					s.pop();
				}
				else
				{
					s.push(a[i]);
					
			//		tmp = a[i];
				}
			}
		}
	}
	while(!s.empty())
	{
		r.push_back(s.top());
		s.pop();
	}
	return r;
}
int main()
{
	int N;
	cout<<"请输入元素个数N:"<<endl;
	cin>>N;
	vector<int> a;
	int j;
	for(int i = 0;i<N;i++)
	{
		cin>>j;
		a.push_back(j);
	}
	a = remove(a,N);
	reverse(a.begin(),a.end());
	vector<int>::iterator it;
	for(it = a.begin();it!=a.end();it++)
		cout<<*it<" ";
	return 0;
}
