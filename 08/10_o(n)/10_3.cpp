/*
快排partition
	问题1：荷兰国旗问题 ( leetcode 75 ）https://leetcode.com/problems/sort-colors/description/
    给定一个带有红色，白色或蓝色的n个对象的数组，将它们就地排序，以便相同颜色的对象相邻，颜色顺序为红色，白色和蓝色。
    输入：[2,0,2,1,1,0]
    输出：[0,0,1,1,2,2]
    分析：类似快排的思路，维持两个索引，zero和second，用来记录0的最右位置和2的最左位置

	问题2：奇偶数分开， 正负数分开
	分析:利用partition，可以n时间复杂度，关键是维持一个分界点，然后从左往右扫，不符合的就交换，并更新分界点

	问题3：01交换排序 （字符串高频面试题 例1，1_1.cpp）
	分析：明显，排好序之后0在左边，1在右边，因此左边的0和右边的1都可以不考虑，
     维持两个指针，分别从左到右扫第一个1的位置，和从右往左扫第1个0的位置，交换即可


	问题4：交换星号 （字符串高频面试题 例3,1_3.cpp）
	分析：既有partition，又有倒着复制的思想
    (1)如果只有partition，那么数字的相对位置会发生变化,这个思想如下：设[0,i-1]都是*,[i,j-1]都是数字，[j,n-1]为未探测
    for(int i = 0,j = 0;j<n;j++)
        if(s[j] == '*') swap(s[i++],s[j]);//j在j到n的区间遍历，如果其是数字，不管，是*,就和i处交换，i同时++。
        i其实是*和数字的分界点
    (2)再加上倒着复制的思想，
    int j = n-1;//新索引
    for(int i = n-1;i>=0;i--)
        if(isdigit(s[i])) s[j--] = s[i];//倒着来，如果是数字，不管，直接放即可。这样结束，后面全是数字了
    //下面再将前面全赋值为*即可
    for(;j>=0;j--)
        s[j] = '*';

	问题5：第一个缺失的整数 （数组高频面试题 例2 leetcode 41 2_2.cpp）
	分析：将每个数字放至它正确的位置，比如我们找到5,将其和A[4]位置上的数交换。最后，找出第一个数不对的位置，返回该位置+1,即可，
	时复o(n)

	问题6：中位数、第k大（小）的数、最小的k个数
	    （1）找第k小的数关键
		    5数取中做分区元素，
		    Partition分三段（小于，等于，大于） (分两段有相同数会退化）

        （2）找到最小的k个数
		    基于partition的方法找到的数是无序的
		    如果有序建议用最大堆nlogk

*/
class Solution1 {
public:
    //类似快排的思路，维持两个索引，zero和second，用来记录0的最右位置和2的最左位置
    //进行两次快排，第一次从左到右遇到2，如果在second之前，则与second处交换，并将second往左移
    //第二次从左到右遇到0，且在zero之后，就和zero处交换，并zero++;
    void sortColors(vector<int>& nums) {
        int zero = 0,second = nums.size()-1;
        for(int i = 0;i<=second;i++)
        {
            while(nums[i] == 2 && i<second) swap(nums[i],nums[second--]);
            while(nums[i] == 0 && i>zero) swap(nums[i],nums[zero++]);
        }

    }
};