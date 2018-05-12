/*
问题：一个字符串只包含*和数字，请把它的*号都放开头。

分析：既有partition，又有倒着复制的思想
    如果只有partition，那么数字的相对位置会发生变化，这个思想如下：设[0,i-1]都是*,[i,j-1]都是数字，[j,n-1]为未探测
    for(int i = 0,j = 0;j<n;j++)
        if(s[j] == '*') swap(s[i++],s[j]);//j在j到n的区间遍历，如果其是数字，不管，是*,就和i处交换，i同时++。
        i其实是*和数字的分界点
    再加上倒着复制的思想，
    int j = n-1;//新索引
    for(int i = n-1;i>=0;i--)
        if(isdigit(s[i])) s[j--] = s[i];//倒着来，如果是数字，不管，直接放即可。这样结束，后面全是数字了
    //下面再将前面全赋值为*即可
    for(;j>=0;j--)
        s[j] = '*';
*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(string &s)
    {
        int n = s.size();
        int j = n-1;
        for(int i = n-1;i>=0;i--)
            if(isdigit(s[i])) s[j--] = s[i];
        for(;j>=0;j--)
            s[j] = '*';
    }
};

int main()
{
    string s = "*3*90*9932**";
    Solution so;
    so.solve(s);
    cout<<s<<endl;
    return 0;
}