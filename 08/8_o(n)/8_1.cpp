/*
问题：1 (C++ STL) Next Permutation 找到字典序里的下一个排列。
12345的下一个是12354,而54321的下一个认为是12345。 （Leetcode 31)
https://leetcode.com/problems/next-permutation/description/

分析:如果目前排列为(A)a[x](B),那么下一个排列为（A)a[y](B'),中间a为数组
其中A是一个序列，它尽可能长，中间明显要a[x]大于a[y]的，后面b‘几乎是B里面所有数排好序的结果

    那么如何确定x呢？
    一个位置，只要右边有数比它大，它就是候选的x。
    同时，a[x]一定是最后一个这样的数
        1,a[x]右边的数，是按照降序or不升序排列的

    算法：二找，一交换，一翻转
    1,逆序从右到左，找到第一个不严格升序的首位，定义为x。x处以后从左往右都是降序的。x+1处最大
    2,找到y>x,a[y]>a[x],且a[y]最小
         因为a[x]后面的数都是降序，因此，从后往前找到第一个大于a[x]的位置就是y了
    3,交换a[x],a[y]处元素。
    4,交换完,新的a[x+1,...,n-1]仍然是降序，对这部分进行逆序，变成严格升序即可。

拓展：找上一个排序，
   从右到左，找第一个非严格降序的首位，
   然后从右到左，找到第一个a[y]<a[x]的位置
   交换
   对x+1后面的部分逆序即可
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int x;
        for(x = n-2;(x>=0)&&nums[x]>=nums[x+1];--x);//从右往左查找x，最后得到的x是从右往左，第一个不是严格升序的字母，后面x+1到最后都是严格递减的
        if(x<0)//特殊情况，说明整个串从左到右都是递减的，比如4321，那么整体逆序即可
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        int y;
        for(y = n-1;nums[y]<=nums[x];--y);//从右往左，找到第一个大于a[x]的位置
        swap(nums[x],nums[y]);//交换
        //交换完，将x后面的部分整体逆序变成升序即可
        reverse(nums.begin()+x+1,nums.end());
        return;

    }
};