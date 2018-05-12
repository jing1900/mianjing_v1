/*
https://leetcode.com/problems/first-missing-positive/description/
问题：	给一个数组，找到从1开始，第一个不在里面的正整数。
	例如［3,4,-1,1]输出2。 （Leetcode 41)

分析：将每个数字放至它正确的位置，比如我们找到5,将其和A[4]位置上的数交换。

    最后，找出第一个数不对的位置，返回该位置+1,即可，时复o(n)

*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i<n;i++)
        {
            while(nums[i]>0&&nums[i]<=n&&nums[nums[i]-1]!=nums[i])//需要交换要满足的条件，1，是1-n范围内的整数，2，该位置上放得不是对的数
                swap(nums[i],nums[nums[i]-1]);
        }

        for(int i = 0;i<n;i++)
        {
            if(nums[i] != i+1)
                return i+1;
        }
        return n+1;
    }
};