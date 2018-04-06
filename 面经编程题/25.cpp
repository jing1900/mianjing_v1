/*两个同样 大小有序的数组求中位数，写代码*/
#include<iostream>
#include<vector>
using namespace std;
double findMedian(int A[], int m, int B[],int n)
{
	int mid = (m+n)/2 + 1;
	int i,j;
	vector<int> vec;
	//从小到大取数，取一半
	for(i = 0,j =0;i<m&&j<n;)
	{
		if(A[i]<B[j])
		{
			vec.push_back(A[i++]);
		}
		else
		{
			vec.push_back(B[j++]);
		}
		if(vec.size() == mid)
			break;
	}
	//如果还没取到一半，其中一个数组就空了，就继续从另一个非空的数组取数，直到一半
	while(vec.size() != mid)
	{
		if(i<m)
		{
			vec.push_back(A[i++]);
		}
		if(j<n)
		{
			vec.push_back(B[j++]);
		}
	}
	//判断两数组长度相加是奇数还是偶数，不同的有不同的中值计算方法。
	//注意这里是2.0
	if((m+n)%2 == 0)
		return (vec[vec.size()-1]+vec[vec.size()-2])/2.0;
	return *(vec.end()-1);
}

int main()
{
	int m,n,i;
	cout<<"请输入两个有序数组长度，用空格隔开"<<endl;
	cin>>m>>n;
	int *a,*b;
	a = new int[m];
	b = new int[n];
	cout<<"请输入有序数组1，用空格隔开"<<endl;
	for(i = 0; i < m;i++)
	{
		cin>>a[i];
	}
	cout<<"请输入有序数组2，用空格隔开"<<endl;
	for(i = 0; i<n;i++)
	{
		cin>>b[i];
	}
	//int a[] = {1,2,3,4};
	//int b[] = {2,3,4,5,6};
	double r = 0.0;
	r = findMedian(a,m,b,n);
	cout<<r<<endl;
	return 0;
}
