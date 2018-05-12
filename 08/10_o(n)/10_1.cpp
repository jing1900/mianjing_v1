/*最大子数组和

问题1：给一个数组，求最大的连续子数组和。 （动态规划实战例2， leetcode 53)
        https://leetcode.com/problems/maximum-subarray/description/
		• 方法1 记录最小前缀和——两个前缀和的差就是一段连续的子数组
		• 方法2 动态规划，记录以每个位置结束的最大子数组的和。




问题2：给一个数组，求最大的连续子数组乘积 （leetcode 152)
        https://leetcode.com/problems/maximum-product-subarray/description/
		类似例1.1
		考虑的问题：
			溢出——没有溢出
			到当前项乘积最大:之前乘积绝对值大(因此即要保存之前的最小乘积（考虑负数的情况），也要保存之前最大乘积）
*/
class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        /*
        dp[i]为以第i个元素结尾的最大连续子序列和，那么dp[i] = max(0,dp[i-1])+nums[i];
        即，如果i之前的subarray和大于0时，是有帮助的，此时加上。否则，是负数，还不如从头来过，此时，其最大子序列和为其本身
        return max(dp[i])即可
        */
        int dp[nums.size()];
        dp[0] = nums[0];
        int res = dp[0];
        for(int i = 1;i<nums.size();i++)
        {
            dp[i] = max(0,dp[i-1])+nums[i];
            res = max(res,dp[i]);
        }
        return res;
    }
};

class Solution2 {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 1;//特殊情况
        int mini = nums[0],maxi = nums[0];//以i项结尾的最小or最大子数组积
        int ansmax=nums[0];//全局最大子数组积,
        for(int i = 1;i<n;i++)
        {
            int tempmin = min(nums[i],min(mini*nums[i],maxi*nums[i]));//此时mini，maxi记录的上一项为止的最小or最大子数组乘积
            int tempmax = max(nums[i],max(mini*nums[i],maxi*nums[i]));
            mini = tempmin;
            maxi = tempmax;
            ansmax = max(maxi,ansmax);
            //ansmin = min(mini,ansmin);//若求最小
        }
        return ansmax;
    }
};
