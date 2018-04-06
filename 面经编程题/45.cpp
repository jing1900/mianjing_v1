#include<iostream>
#include<limits.h>
using namespace std;

int main()
{
    int n;//数组中元素数
    while(cin>>n)
    {
        int a[n];
  
        for(int i = 0;i < n;i++)
        {
            cin>>a[i];
        }
        if(n == 0)
            return 0;
        if(n == 1)
            return a[0];
        //cout<<max<<endl;
        //定义最大连续和向量
        //cout<<a[0]<<endl;
        int dp[n];
        dp[0] = a[0];
        int pre[n];//连续序列中最左元素
        pre[0] = 0;
        int ret = a[0];//返回值
        int maxidx = 0;//最大连续序列最右索引。
        for(int i = 1; i < n;i++)//这里一定要以1开始，否则dp[i-1]= dp[-1]是一块还没开辟的空间
        {
            if(dp[i-1] > 0)
            {
                dp[i] = dp[i-1]+a[i];
                pre[i] = pre[i-1];
            }
            else
            {
                dp[i] = a[i];
                pre[i] = i;
            }
            if(dp[i]>ret)
            {
                //cout<<dp[i]<<endl;
                ret = dp[i];
                //cout<<ret<<endl;
                maxidx = i;
            }
        }
        //cout<<pre[maxidx]<<maxidx<<endl;
  //      cout<<dp[maxidx]<<endl;
        //计算连续序列中的最小值
	int min = INT_MAX;
	for(int i = pre[maxidx];i<maxidx;i++)
	{
		if(a[i]<min)
			min = a[i];
	}
        int max = INT_MIN;
	for(int i = 0; i< pre[maxidx];i++)
	{
		if(a[i]>max)
			max = a[i];
	}
	for(int i = maxidx+1;i<n;i++)
	{
		if(a[i]>max)
			max = a[i];
	}
	if(min>=max)
		cout<<ret<<endl;
	else
		cout<<ret+max-min<<endl;
    }
    return 0;
}
