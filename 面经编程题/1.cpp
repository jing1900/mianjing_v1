/*1~n这n个数现在去掉1个，如何找到去掉的数*/
/*思路1：异或
#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	//获取数组长度
	int n = 0;
	cin>>n;
	if(n == 1)
		return 1;
	//异或1-n，
	int num = 0;
	//
	for(int i = 1;i<=n;i++)
	{
		num = num ^ i;
	}
	//挑选处随机去掉的两个数
	int c1 = rand()%n;
	int c2 = rand()%n;
	//num先依次亦或1-n，再异火去除掉两个数后剩余的值
	for(int j = 1;j<=n;j++)
	{
		if(j == c1 || j == c2)
			continue;
		num = num ^ j;
		
	}
	//这种异火得出结果的前提是你已经知道了去除的是哪俩数，这种假设是不成立的	
	num = num ^ c2;
	cout<< num<<endl;
	
	num = num ^ c2 ;
	num = num ^ c1;
	cout<<num<<endl;
	return 0;
}
*/
/*思路2：统计*/
#include<iostream>
using namespace std;
int main()
{
	int *array,*temp,i,n;
	cout<<"请输出数组长度N:"<<endl;
	cin>>n;
	array = new int[n+1];
	temp = new int[n+1];
	cout<<"请输入去除掉两个数后的数组内容，长N-2，内容用空格隔开"<<endl;
	for(i = 1; i <= n-2;i++)
		cin>>array[i];
	for(i = 1;i <= n; i++)
		temp[i] = 0;
	for(i = 1;i <= n-2;i++)
		temp[array[i]] = 1;
	for(i = 1;i <=n; i++)
	{
		if(temp[i]==0)
			cout<<i<<" ";
	}
	cout<<endl;
}
