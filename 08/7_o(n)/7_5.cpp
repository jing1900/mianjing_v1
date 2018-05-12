/*
问题：给定一个01串，求它一个最长的子串满足0和1的个数相等。

分析：我们将0看作-1,1看作+1,统计一个前缀和。
    若两个前置和相等，那么这两个前缀和之间的子串满足01个数相等。

    若前缀和算出之后对其进行排序，那么需要n×logn

    而这里不需要排序，
    首先，前缀和的范围为-n,n,我们加上n将其变成0,2n. 然后只需要记录这个前缀和第一次出现的位置即可

    本质：用hash代替排序


*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int run(string s)
    {
        int n = s.size();
        vector<int> hash(n*2+1,-1);//下标从0-2n.记录第一次出现某前缀和的位置
        hash[n] = 0;//表示长度为n（-n） = 0出现的位置，最开始在0出现
        int sum = n;//统计目前为止的前缀和，初始化为0（+n）即n
        int best = 0;
        for(int i = 0;i<n;i++)
        {
            sum+=(s[i] == '0')?(-1):1;//统计目前位置的前缀和
            if(hash[sum]>=0)//表示该前缀和已出现过，当前位置减去第一次出现该前缀和的位置
                best = max(best,i+1-hash[sum]);
            else//还没出现过，记录该前缀和值第一次出现的位置
                hash[sum] = i+1;//存的是位置，而非下标

        }
        return best;

    }
};

int main()
{
    string s = "0101010110";
    Solution so;
    cout<<so.run(s)<<endl;
    return 0;
}