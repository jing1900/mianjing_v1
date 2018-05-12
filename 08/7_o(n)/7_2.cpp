/*
问题：  Leetcode 42 给定每个块高度，求下雨后积水。 图对应[0,1,0,2,1,0,1,3,2,1,2,1]
https://leetcode.com/problems/trapping-rain-water/description/

分析：每一块积水高度（水高和原高加起来），其实等于它左边所有包括本身的最大值，和右边所有（包括本身）的最大值，里较小的。

    思路：利用前缀和后缀

*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int result = 0;
        vector<int> left(n),right(n);
        for(int i = 0;i<n;i++)//计算left,即包含自身在内，左边元素的最大值
            left[i] = i?max(height[i],left[i-1]):height[i];//i为0时就等于height[0]
        for(int i = n-1;i>=0;i--)//计算right，包含自身在内，右边元素的最大值
            right[i] = (i == n-1)?height[i]:max(height[i],right[i+1]);
        for(int i = 0;i<n;i++)
            result+=min(left[i],right[i]) - height[i];//取小的那个，再减去原高
        return result;
    }
};