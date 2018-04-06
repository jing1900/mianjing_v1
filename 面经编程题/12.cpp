/*
问题：一个数组中只有一个数字是单独出现，其他都出现了三次，请找出这个只出现一次的数

思路:对其二进制形式的每一位进行累加
	若该位整除3仍有余数，则证明所求数在该位为1*/
#include<iostream>
#include<string.h>
using namespace std;
int findNum(int a[], int n)
{
	int bits[32];
	int i,j;
	memset(bits,0,32*sizeof(int));
	//统计二进制数累加
	for(i = 0; i < n;i++)
		for(j = 0; j<32;j++)
			bits[j] += ((a[i]>>j)&1);
	//
	int result;
	for(i = 0; i < 32;i++)
	{
		if(bits[i] % 3 != 0)
			result += (1<<i);
	}
	return result;
}

int main()
{
	int *a,n,i;
	cout<<"请输入数组长度"<<endl;
	cin>>n;
	a = new int[n];
	cout<<"请输入数组内容，用空格隔开"<<endl;
	for(i = 0; i< n;i++)
		cin>>a[i];
	cout<<"单独出现的数为："<<findNum(a,n)<<endl;
	return 0;
}
