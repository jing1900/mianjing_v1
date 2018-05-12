/*
问题：允许交换一次的最大子数组和
	 (codility) 给定一个数组，在允许交换两个数的前提下（只允许交换一次，可以不换），求最大子数组和。


分析：1,定义fi为两部分之和，以a[i]为结尾的最大字数组的和（可以为空），和a[0,i]里面任意一个单独元素的和。
注意，这两部分不能求交集,即fi其实是一段+一个孤立点，这个孤立点不能取在段上。
fi = max(fi-1 + ai,max(a[0,...,i]),这个表达式可以这样理解，fi可以取fi-1+ai,也可以取0+max(a[0,i]),两者取最大

这个fi有什么意义呢，这里面的孤立点，就是ai想要换掉的点

    2,定义gi为以a[i]开头的最大子数组和
    gi = max（gi+1,0）+ai


    3,如果ai和aj交换(j<i)，那么原来包含a[i]的最大字数组和变成g[i]-a[i]+f(i-1).
    即，要换掉的a[j]在f(i-1)里
    如果不交换，答案就是max{g[i]}

    4,我们值考虑j<i的情况，对于j>i，把a反转再做一次就好了


*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solution(vector<int> &a)
    {
        int res = help(a);
        reverse(a.begin(),a.end());
        res = max(res,help(a));
        return res;
    }
private:
    int help(vector<int> &a)
    {
        int n = a.size();
        vector<int> f(n),g(n);//分别是以ai结尾和开头的最大子序列和
        f[0] = a[0];
        int now = a[0];
        for(int i = 1;i<n;i++)//得到f，其含义就是a[i]要交换的位置的元素的值。（这个位置是在i左边的，因此后面发现要反转一次
        {
            now = max(now,a[i]);//a[i]之前包括a[i]的最大值
            f[i] = max(a[i]+f[i-1],now);//f取最大连续子序列和，和前面最大值中较大的那个
        }
        g[n-1] = a[n-1];
        int res = a[n-1];//统计g[i]最大值,即不交换的情况下的最大值
        for(int i = n-2;i>=0;i--)
        {
            g[i] = max(g[i+1],0)+a[i];
            res = max(res,g[i]);
        }
        for(int i = 1;i<n;i++)//交换情况下的最大值
        {
            res = max(res,g[i]-a[i]+f[i-1]);//这里为何是fi-1.是因为ai要和它之前的最大值交换
        }
        return res;
    }
};

int main()
{
    int a[4] = {10,-100,10,10};
    vector<int> arr(a,a+4);
    Solution s;
    cout<<s.solution(arr)<<endl;
    return 0;
}