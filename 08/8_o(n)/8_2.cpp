/*
问题：给定一个01串，恰好包含2n个0和2n个1，你可以把它切成若干段，再把它们任意拼接，要求拼接出两部分，每部分恰好包含n个0，n个1,
如何使得切的段数最少？

比如0101,中间切，切为01,01,分别作为两部分
0011,切成0 01 1,把0 1组合形成一部分，剩下的是一部分

分析：下标从0开始，f(x),x=0,1,...,2n.表示原串在[x,x+2n-1]这个窗口（大小为2n)里，0和1个数差.(注意，串总长为4n）
    首先，f0+f2n = 0.为什么呢，它前后分别表示串前半段和后半段，整个串01之差自然为0
    1,如果f0 = f2n = 0,那么自然的，从中间切一刀即可。答案为2
    2,如果一个小于0一个大于0,那么首先它是奇数还是偶数呢?首先一定是偶数，不信可以试一下
    然后窗口滑动是如何滑动的呢?fx变成fx+1时，有三种可能，
        去掉1个0,补一个1,-2
        or去掉一个1,补一个0,+2
        or去0补0,去1补1,不变

    因此，窗口在滑动时，偶数由负数变正数or正变负过程中，一定能存在f（y) =0的点，那么
    把[y,2n+y-1]作为一段，它包含n个0n个1,剩下的[0,y-1]和[2n+y,4n-1]合并起来作为一段，
    因此，切三段即可

总之，三段or两段即可
*/
class Solution
{
    int solution(string s)
    {
        int n = s.size();
        int d = 0;
        for(int i = 0;i<n/2;i++)//窗口大小为总长的一半,这里相当于上面判断f0和fn是否相等。
        {
            if(s[i] == '0') ++d;
            else if(s[i] == '1') --d;
        }
        if(d == 0) return 2;
        else return 3;

    }
}