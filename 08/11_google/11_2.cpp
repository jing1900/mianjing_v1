/*问题： 字符串只有可能有A、B、C三个字母组成，如果任何紧邻的三个字母相同，就非法。求长度为n的合法字符串有多少个？
比如： ABBBCA是非法，ACCBCCA是合法的。

分析：这道题使用动态规划的思路，
dp[i][0]表示长度为i，最后两位不同的合法字符串个数
dp[i][1]表示长度为i，最后两位相同的合法字符串个数
则dp[i][0] = dp[i-1][0]*2 + dp[i-1][1]*2;//这里前面这块，i-2和i-1不同，因此i处的取法只要不和i-1一样就是合理的，两种取法
然后后面这块，首先i-1和i-2位置都是同一字母，为要求合法且不同，i这里也只有两种取法
dp[i][1] = dp[i-1][0];//这里dp[i-1][1]已经i-2,i-1相同了，再让i-1和i同，明显不合法。因此只有前面这个，然后前面这个是i-2和i-1不同，然后要求i与i-1同，只有一种选法

初值：从2开始好理解些
dp[1][0] = 3;
dp[1][1] = 0;
dp[2][0] = 6;
dp[2][1] = 3;

结果:dp[n][0]+dp[n][1]

时间复杂度On

*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solution(int n)
    {
        vector<vector<int> > dp(n+1,vector<int>(2));
        dp[2][0] = 6;
        dp[2][1] = 3;
        for(int i = 3;i<=n;i++)
        {
            dp[i][0] = 2*dp[i-1][0] + 2*dp[i-1][1];
            dp[i][1] = dp[i-1][0];
        }
        return dp[n][0]+dp[n][1];
    }
};

int main()
{
    int n = 3;
    Solution s;
    cout<<s.solution(n)<<endl;
    return 0;
}