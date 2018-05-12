/*
滑动窗口
	问题1：Leetcode 209 给定一个数组，里面全是正整数，再给一个正整数s，求数组里面最少多少个连续的数，满足总和不小于s
		核心，大窗口不满足条件，它的任意小窗口也不满足条件
		窗口[i..j]
			过小——++j
			过大——--i

	问题2 子串变位词 （字符串高频面试题精讲例4， 1-4.cpp）
	○ 思考题1 最短子串包含全部字母 Leetcode 76 和问题2是一个问题
	○ 思考题2 无重复字符的最长子串 leetcode 3 类似问题1,这里是小窗口不满足，则大窗口也不满足，
	若太大了，则将左边界往右移。若窗口太小了（窗口元素都只出现1次），则扩大窗口。

*/
class Solution1 {
public:
    //核心：大窗口不满足条件，它的任意子窗口也不满足。窗口[i,j]，过小，则++j，过大,则减小它，i往右移
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();

        int answer = INT_MAX;
        for(int i = 0,j= 0,sum = 0;j<n;)//[i,..,j-1]
        {
            while(sum<s && j<n)//结束时，j为对的j位置+1
                sum+=nums[j++];
            if(sum>=s)//往右增大i，从而缩小窗口大小。
            {
                for(;sum>=s;sum-=nums[i++]);//结束后，i为对的位置+1
                answer= min(answer,j-i+1);
            }
        }
        return (answer==INT_MAX)?0:answer;//为了处理[1,1] 3 这种特殊情况。
    }
};