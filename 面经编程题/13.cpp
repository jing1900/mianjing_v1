/*

问题：一个数组存1-1000的连续整数，如果取出其中一个，如何快速找到*/
/*思路：
由于数组存储的是1,2,3,4这样的有规律的数组，所以这些数组中的元素和下标之间有着紧密的联系。所以没有移位的元素与下标之间相差1，移位了的差2.所以从头向后一次查找，找到第一个元素和下标相差2的位置，该下标加1就是被删除的数。*/
#include<iostream>
#include<cstdlib>
#include<string.h>
#include<time.h>
#include<stdio.h>
using namespace std;
int main()
{
	int i,*a;
	int n = 1000000000;
	a = new int[n];
	memset(a,0,n*sizeof(int));
	int r = rand()%n;
	time_t t1,t2;
	for(i = 0; i< n; i++)
	{
		if(i >= r)
		{
			if(i+2 <= n)
				a[i] = i+2;	
		}
		else
		{
			if(i+1<=n)
				a[i]= i+1;
		}
//		cout<<a[i]<<" ";
	}
/*方法1：遍历	
*/
	t1 = time(NULL);
	cout<<"删掉的数为:"<<r+1<<endl;
	for(i = 0; i< n;i++)
	{
		if(a[i] - i == 2)
		{
			cout<<"去掉的数是:"<<a[i]-1<<endl;
			break;
		}
	}
	t2 = time(NULL);
	printf("time:%.0f s\n",difftime(t2,t1));

/*方法2，类二分查找,还是要比上面那个快些
	*/
//	cout<<time(0)<<endl;
	
 	t1= time(NULL);
	cout<<"删掉的数为:"<<r+1<<endl;
	int l = 0,rt = n-1,mid = 0;
	while(l < r)
	{
		mid  = l+ (rt-l)/2;
		if(a[mid]>mid+1)
		{
			rt = mid;
		}
		else
		{
			l = mid+1;
		}
	}
	cout<<"去掉的数是:"<<a[l] -1 <<endl;
	t2 = time(NULL);
	printf("time:%.0f s\n",difftime(t2,t1));
	return 0;
}
