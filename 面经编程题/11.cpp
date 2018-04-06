/*
题：一个数组中某个数出现的次数大于一半，最快找出该数

思路：士兵守阵地
	第一个数字作为第一个士兵，守阵地，并设count = 1
	接下来遍历
	如果遇到相同数字，则++count；
	如果遇到不同数字，则--count；
	为0，则换人
	这样到最后，留下的就是那个数
*/
#include<iostream>
using namespace std;
int search(int a[], int n)
{
	//极端情况判断
	if(NULL == a || n<=0)
		return -1;
	//士兵，count
	int k = 0,c = 0;
	for(int i = 0; i<n;++i)
	{
		//计数为0，换人
		if(c == 0)
			k = a[i];
		//相同，则++c
		if(k == a[i])
			++c;
		//不同，则--c
		else
			--c;
	}
	return k;
}

int main()
{
	int n = 0;
	cout<<"请输入数组长度N"<<endl;
	cin>>n;
	int a[n];
	cout<<"请输入数组内容，以空格隔开"<<endl;
	for(int i = 0; i< n;i++)
		cin>>a[i];
	//int a[] = {1,1,1,1,2};
	cout<<search(a,n)<<endl;
	return 0;
}
