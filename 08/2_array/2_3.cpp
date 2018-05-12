/*
https://leetcode.com/problems/maximum-gap/description/
问题：给定一个整数数组(n > 1)，求把这些整数表示在数轴上，相邻两个数差的最大值。（Leetcode 164)

分析：首先，最简单的思路是排序，那么有没有更好的思路呢？
    1 首先，我们找到最小值x 最大值y，若两者相等，返回0
    2 然后把数放进n+1个桶，每个桶的大小为double d = (x-y)/n+1
    每个桶区间为[x+i*d,x+(i+1)*d),i取0-n，是左闭右开区间，最后一个桶是双闭区间
    最小值在0号桶，最大值在n号桶，
    如，数r，放进((r-x)/d),这里进行下取整。注意r == y时，答案取n（即最大值特殊处理下）
    3 我们容易知道n个数，n+1个桶，定有一个桶非空，明显非0,n号桶，那么其一定在中间，
    中间有空桶，那么最大值的间隔是一定大于d的，这说明最大间隙的两个数定不出现在一个桶内。
    而是出现在一个非空桶的最大值和下一个非空桶的最小值之间。
    因此，我们记录每个桶的最大值和最小值即可。
    时间复杂度为O(n).
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n ==0 || n==1) return 0;//特殊情况，0个值or1个值无法求gap

        int x = nums[0],y = nums[0];//遍历，求得数组最小x最大值y
        for(auto num:nums)
        {
            x = min(x,num);
            y = max(y,num);
        }

        double d = double(y-x)/(n+1);//求桶距d
        vector<int> bucketsMin(n+1,INT_MAX);//存贮每号桶的最小值，初始化size,并且设置初始值
        vector<int> bucketsMax(n+1,INT_MIN);

        for(auto num:nums)//统计每号桶的最大值和最小值
        {
            int idx = n;//桶号，最大值的特殊情况为n
            if(num != y)//非最大值的情况
                idx = (num-x)/d;//正常向下取整
            bucketsMin[idx] = min(num,bucketsMin[idx]);
            bucketsMax[idx] = max(num,bucketsMax[idx]);
        }

        int maxGap = INT_MIN;
        int pre = x;//前一个桶的最大值，先随便初始化为数组最小值
        for(int i = 0;i<=n;i++)
        {
            if(bucketsMin[i] == INT_MAX && bucketsMax[i] == INT_MIN)//桶空
                continue;
            maxGap = max(maxGap,bucketsMin[i]-pre);
            pre = bucketsMax[i];
        }
        return maxGap;

    }
};
