/*
问题：最小平均值子数组
 给定一个数组，求一个至少包含两个元素的子数组，满足平均值最小。输出子数组的起点，多个的时候输出最小的。


分析：我们先从结果倒推，如果最优解的长度为偶数，那么我们可以将最优解拆成长度为2的若干段，
   否则，如果是奇数，那么将其拆成若干年长度为2的和一个长度为3的
   最优解中，每一段的平均值都必须相等，为什么呢？
   如果有一段平均值比最优解小，那么肯定有一段比最优解大，那么为什么还要哪些比最优值大的部分？

   因此，我们要看最优解，只要看长度为2or3的段就可以了。
*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solution(vector<int> a)
    {
        int n= a.size();
        if(n<2) return -1;
        int total2 = a[1]+a[2];//2滑动窗口初始化。为了之后滑动的时候统一从3开始，这里将total2初始化为了1,2,并根据012处大小初始化了best和start
        int best2;
        int start2;
        if(a[0]<=a[2])
        {
            start2 = 0;
            best2 = a[0]+a[1];
        }
        else
        {
            start2 = 1;
            best2 = a[1]+a[2];
        }
        int total3 = a[0]+a[1]+a[2];//3大小滑动窗口初始化
        int best3 = total3;
        int start3 = 0;

        for(int i = 3;i<n;i++)
        {
            total2 += a[i] - a[i-2];//相当于窗口后移一位
            if(total2<best2)//这里发现了没，等于的时候并未修改start值
            {
                best2 = total2;
                start2 = i-1;//窗口开始位置
            }
            total3 += a[i]-a[i-3];
            if(total2<best3)
            {
                best3 = total3;
                start3 = i-2;
            }
        }
        //不要忘了，这里我们得到的best2,best3为累加值，而非平均。
        //因此我们需要对best2/2,best3/3,但这里可以用乘法代替除法，即比较 best2*3 和best3*2
        int cmp = best2*3-best3*2;
        if(cmp == 0)
            return min(start2,start3);
        return cmp<0?start2:start3;
    }
};
int main()
{
    int a[7] = {1,3,-8,-9,-10,11,2};
    vector<int> arr(a,a+7);
    Solution s;
    cout<<s.solution(arr)<<endl;
    return 0;
}