/*题：数组中的数都是重复两次，只有两个数出现1次，找出这两个出现1次的数

思路：
	1，将数组中全部元素异或；
	2，从异或结果的二进制中，找出最先出现1的位置，记为第N位
	3，根据第N位是否为1，将数组划分为两部分，然后分别异或，得到的结果，即为两个出现1次的数
*/
#include<iostream>
using namespace std;
void find(int a[], int size)
{
	int num = 0;
	int num1 = 0;
	int num2 = 0;
	int N = 0;
	int i = 0;
	for(i = 0; i< size;i++)
		num ^= a[i];
	//找出亦或结果的二进制中，第一个不为1的位置
	for(i = 0; i< 32;i++)
	{
		if(((num>>i)&1) != 1)
			N++;
		else
			break;
	}
	//按第N位是否为1划分
	for(i = 0; i< size;i++)
	{
		if(((a[i]>>N)&1) != 1)
			num1 ^= a[i];
		else
			num2 ^= a[i];
	}
	cout<<num1<<" "<<num2<<endl;
}
int main()
{
	//初始化变量
	int *a ,n,i;
	//获取数组长度和数组本身
	cout<<"请输入数组长度N"<<endl;
	cin>>n;
	a = new int[n];
	cout<<"请输入一个长度为N，只有两个数字只出现一次，其他元素均出现两次的数组，元素用空格隔开"<<endl;
	for(i = 0; i< n;i++)
		cin>>a[i];
	//找单独出现的数字
	find(a,n);
	return 0;
}
