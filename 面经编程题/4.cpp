/*
一个严格递增的数组，将前缀取一部分放在后面，在修改后的数组上找到最小的数。
*/
/*#include<iostream>
#include<stdlib.h>
using namespace std;
class FindMin
{
public:
	int findMin(int a[],int size)
	{
		//为空，直接退出
		if(size == 0)
			exit(-1);
		//长度为1，或者左边元素小于后边，表示放置的部分长度为0，直接返回数组头部即可
		if(size == 1 || a[0]<a[size-1])
			return a[0];
		int L = 0,R = size-1,mid = 0;
		while(L<R)
		{
			mid = L +(R-L)/2;
			//左比中间大，一定在左区
			if(a[L]>a[mid])
				R = mid;
			//中间比右大，一定在右区
			else if(a[mid]>a[R])
				L = mid+1;
			else
				break;
		}
		if(L == R)
			return a[L];
		int min = a[0];
		for(int i = 0; i< size;i++)
		{
			if(a[i]<min)
				min = a[i];
		}
		return min;
	}
		
};
int main()
{
	int a[] = {2,3,4,5,1};
	FindMin F;
	cout<<F.findMin(a,5)<<endl;	
	return 0;
}*/

/*
思路：
	1，若数组长度为0，直接退
	若数组长度为1，或左边的值小于后边的，返回数组第一个元素
	2，初始化L，R，mid
	当L<R,二分搜索，
		当左>中，在左边
		当中>右，在右边
	3，当L=R时，return
	4，如果全部元素大部分相等的特殊情况，直接遍历
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
int find(int a[], int size)
{
	if(size == 0)
		exit(-1);
	if((size == 1) ||(a[0] < a[size-1]))
		return a[0];
	int L = 0, R = size-1,mid = 0,i = 0;
	while(L<R)
	{
		mid = L + (R-L)/2;
		if(a[L]>a[mid])
			R = mid;
		else if(a[mid] > a[R])
			L = mid +1;
		else
			break;
	}
	if(L == R)
		return a[L];
	int min = a[0];
	for(i = 0; i<size;i++)
	{
		if(a[i]<min)
			min = a[i];
	}
	return min;
}

int main()
{
	int *a ,i,n;
	cout<<"请输入数组长度N"<<endl;
	cin>>n;
	a = new int[n];
	for(i = 0; i< n;i++)
		cin>>a[i];
	//int a[] = {5,1,2,3,4};
	cout<<find(a,n)<<endl;
	return 0;
}
