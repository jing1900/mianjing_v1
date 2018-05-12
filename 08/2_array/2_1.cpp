/*
问题： 一个给定的不包含相同元素的整数数组，每个，局部极小值的定义是一个值比左右相邻的（如果存在）都小的值，求它的一个局部最小值

分析：首先，我们分析其是否存在?首先，全局最小值一定是一个局部极小值，因此一定存在。找最小值需整体扫一边，时间复杂度为o(n).

    能不能更少一点呢？我们规定数组下标为a[1...n],并定义a[0] = a[n+1] = 无穷大，因此，我们有a[1]<a[0],a[n]<a[n+1],
    则，我们得出结论，a[x,y],若a[x]<a[x-1],a[y]<a[y+1],则它包含一个局部极小值。
    为什么这么说呢，首先a[x,y]中一定有一个全局最小值，但如果在端点上，就需要结合上述条件限制，因此，只要保证有上述条件，局部最小一定存在

    因此，我们用二分法来确定局部最小值所在的区间，取mid = (l+r)/2,将数组分成a[l,mid]和a[mid+1,r]
    若a[mid]<a[mid+1],那么在[l,mid]满足条件，定存在一个局部极小值
    若a[mid+1]<a[mid],那么[mid+1,r]满足条件，一定存在一个局部最小值

    时复logn

    从这道题我们也了解到，二分不只可以超找有序的序列，其实是找逐步减小解空间的途径。

    思考题
		• 循环有序数组最小值、查找元素x （Leetcode 153,154)
		• 一个严格单增的数组，查找a[x] == x的位置

*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(vector<int> &s,int n)
    {
        if(n == 0) return -1;//三种特殊情况
        if(n == 1 || s[0]<s[1]) return s[0];
        if(s[n-1]<s[n-2]) return s[n-1];
        int l = 1,r = n-2;//去除端点的区间，这里经过上面的特殊情况，已知s[1]>s[0],s[n-2]>s[n-1]
        while(l<r)
        {
            int mid = (l+r)/2;
            if(arr[mid-1]<arr[mid])
                r = mid-1;
            else if(arr[mid]>arr[mid+1])//不用考虑相等的情况，因为题目中说了没重复元素
            {
                l = mid+1;
            }
            else//mid比两者都小
                return s[mid];
        }
        return s[l];
    }
};

int main()
{
    int a[7] = {5,4,7,8,5,2,3};
    vector<int> s(a,a+7);
    Solution so;
    cout<<so.solve(s,7)<<endl;
    return 0;
}