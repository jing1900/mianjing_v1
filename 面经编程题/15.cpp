/*
一个运算序列中只有加减乘除和数字，计算运算序列的结果
*/
/*
#include<iostream>
#include<stack>
#include<vector>
#include<stdlib.h>
using namespace std;
int main()
{
	
	int n;
	cout<<"请输入运算序列长度"<<endl;
	cin>>n;
	char c[n];
	cout<<"请输入序列，用空格隔开"<<endl;
	for(int i = 0; i<n;i++)
		cin>>c[i];
//	for(int i = 0;i<n;i++)
//		cout<<c[i]<<" ";
	stack<int> store;
	for(int i = 0; i< n;i++)
	{
		//遇到运算符，就取栈顶的两个元素进行运算，运算后的结果入栈
		if(c[i] == '+' || c[i] == '-'|| c[i] == '*'||c[i] == '/')
		{
			//如果站内的元素少于两个，直接返回0
			if(store.size()<2)
				return 0;
			//获取栈顶俩元素进行运算
			int a= store.top();
			store.pop();
			int b = store.top();
			store.pop();
			int r = 0;
			//根据不同运算符得到不同结果。
			if(c[i] == '+')
				r = a+b;
			else if(c[i] == '-')
				r = b-a;
			else if(c[i] == '*')
				r = b*a;
			else if(c[i] == '/')
				r = b/a;
			store.push(r);
		}
		else
		{
			//这里将字符类型转为int类型的数字
			store.push(c[i]-'0');
		}
	}
	//返回栈顶元素作为运算结果
	cout<<store.top()<<endl;
	return 0;
}*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main()
{
	int n,i;
	cout<<"请输入字符数组长度"<<endl;
	cin>>n;
	char ch[n];
	cout<<"请输入字符数组内容，用空格隔开"<<endl;
	for(i = 0; i< n;i++)
		cin>>ch[i];
	//存贮字符数组中的数字
	stack<int> store;
	for(i = 0; i < n;i++)
	{
		if(ch[i] == '+' || ch[i] == '-' || ch[i] == '*' || ch[i] == '/')
		{
			if(store.size()<2)
				return 0;
			int a = store.top();
			store.pop();
			int b = store.top();
			store.pop();
			int r = 0;
			if(ch[i] == '+')
				r = a + b;
			else if(ch[i] == '-')
				r = b - a;
			else if(ch[i] == '*')
				r = b * a;
			else if(ch[i] == '/')
				r = b / a;
			store.push(r);
		}
		else
		{
			store.push(ch[i]-'0');
		}
		
	}
	cout<<store.top()<<endl;
	return 0;
}
