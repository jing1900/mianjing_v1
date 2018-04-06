/*
给定一个字符串s，你可以从中删除一些字符，使得剩下的串是一个回文串。如何删除才能使得回文串最长呢？
输出需要删除的字符个数。
https://www.nowcoder.com/test/question/28c1dc06bc9b4afd957b01acdf046e69?pid=1725829&tid=14277410
*/
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    string s1;
    while(getline(cin,s1))
    {
        //构造s2为s1的反转字符串
        string s2 = s1;
        reverse(s2.begin(),s2.end());
        //cout<<s2;
         
        //最长公共子序列长度统计表
        int n = s1.size();
        int table[n+1][n+1];
        for(int i = 0;i<=n;i++)
        {
            table[i][0] = 0;
            table[0][i] = 0;
        }
         
        //填表
        for(int i = 0; i< n;i++)
        {
            for(int j = 0; j< n;j++)
            {
                if(s1[i] == s2[j])
                {
                    table[i+1][j+1] = table[i][j]+1;
                }
                else
                {
                    table[i+1][j+1] = max(table[i][j+1],table[i+1][j]);
                }
            }
        }
        cout<<n-table[n][n]-1<<endl;
    }
    return 0;
}
