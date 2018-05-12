/*
问题： (PAT：Programming Ability Test）给定一个只包含P,A,T的串，求一共出现多少个“PAT” 子序列？

分析：这里只需要计数不需要统计，因此N时间复杂度就可以做。怎么做呢？
    p，pa，pat表示之前出现过得“P”，“PA","PAT"的个数，即
    s[i] == 'P',++p;
    s[i] == 'A',pa+=p;//这时因为之前出现过得所有”P",都可以与之形成"PA",因此计数加上之前p的个数
    s[i] == 'T',pat+=pa;

思考题：leetcode115
    https://leetcode.com/problems/distinct-subsequences/description/
分析：设dp[i+1][j+1]表示t[0,i]在s[0,j]中出现的次数。易得最后返回的应是dp[t.size()[s.size()]
    首先第一行，代表任意串包含空串的次数，均设为1.即dp[0][j] = 1;//这里如果t存在特殊情况，即空串，也能正确返回。
    然后第一列，代表空串包含任意串的次数，均设为0,即dp[i][0] = 0，注意dp[0][0] = 1.

    首先，如果t[i]!=s[j]，那么不使用s[j],dp[i+1][j+1] =dp[i+1][j];
        否则，使用s[j],dp[i+1][j+1] = dp[i+1][j]+dp[i][j]//注意到了没，后面这里相当于计算pat时，加上pa的统计
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int> > dp(t.size()+1,vector<int>(s.size()+1,0));
        for(int j = 0;j<=s.size();j++)//初始化第一行
            dp[0][j] = 1;

        for(int i = 0;i<t.size();i++)
        {
            for(int j = 0;j<s.size();j++)
            {
                if(t[i] == s[j])
                    dp[i+1][j+1] = dp[i+1][j]+dp[i][j];
                else
                    dp[i+1][j+1] = dp[i+1][j];
            }
        }
        return dp[t.size()][s.size()];
    }


};