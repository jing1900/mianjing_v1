/*
问题1：给定一个1-n的排列，每次只能把一个数放到序列末尾，至少几次能排好顺序？
		为什么要移动1？其他都排好了，1自然就好了
		如果要移动x，则之后我们必须把(x + 1), (x + 2).. n都移动到末尾。
		因此，从1-(x-1)必须有序的
		因此我们的目的是找到尽可能大的一个x，让其前面的1-x-1的数都是有序的。

问题2：给定一个1-n的排列，每次可以把一个数放到序列开头，也可以放到结尾，至少几次能排好序？
	    分析
		我们可以把1..y移动到开头
		然后把x..n移动到末尾
		但要求[y + 1.. x － 1］必须按顺序出现，因此，我们仍需统计一下多少数是按顺序出现的，这里只不过不用从1开始
		dp[x]表示从x开始在原数组中往后按顺序出现的最长长度
			即dp[x]的值表示：x, x + 1, …x + dp[x] – 1按顺序出现
			倒着循环i， dp[a[i]] = dp[a[i] + 1] + 1

*/

class Solution1
{
public:
    int solution(vector<int> a)
    {
        int n = a.size(),want =1 ;//want为x的值,初始化为1
        for(int i = 0;i<n;i++)
        {
            if(a[i] == want)//这里want很精妙，相当于在数组范围内找到了所有有序的部分，
            //比如这里，找到了1,就该接着看1后面能不能找到2,一直看找到多少有序的数
                want++;
        }
        return n-want+1;//want,...,n-1都是要被移动的, 相当于n-(want-1)
    }
};

class Solution2
{
public:
    int solution(vector<int> a)
    int n = a.size(),m = 0;//m为最长有序的长度
    vector<int> dp(n+2,0);//使用1,...,n+1,因为数是从1-n的，我们统计的是以数x开头往后的有序长度
    for(int i = n-1;i>=0;i--)
    {
        m = max(m,dp[a[i]] = dp[a[i]+1]+1);//这个dp方程很奇妙，它计算每个以x开头的最大有序长度时，等于以x+1开头的最大有序长度+1。
        //当然这些有序长度最开始均初始化为0的，以 1 3 4 2为例，该方法算得dp2 = dp3 +1 = 1,dp4 = dp5+1 = 1,dp3 = dp4+1 = 2,dp1 = dp2+1 = 2
        //至于这里为什么以倒序的顺序计算，是因为这样，能在计算dpx时，dpx+1的值是有效的
    }
    return n-m;
};