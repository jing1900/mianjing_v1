/*问题： 给定一个数n, 求不超过n的所有的能被3或者5整除的数的和。例如: n = 9，答案3 + 6 + 5 + 9 = 23。

分析：这是一个数学问题
    首先被3整除的数：3,6,9,...(n/3)*3.一直到n除3往下取整再乘3
    5同理：5,10,...,(n/5)*5
    但要减去重复的数，即同时是3和5的倍数，15,30,...,(n/15)×15
我们要注意的点是问面试官n的范围，是否超过int，要用longlong来存储

然后等差数列的求和公式为，设x为首项，y为项数，d为公差
(x + x+d(y-1))*y /2 ,即首项+尾项 × 项数 再处以2(该公式项数为0也适用）
这里我们关键是求得项数
x = 3,d = 3,y = n/3
x = 5,d = 5,y = n/5
x = 15,d = 15,y = n/15

*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long solution(int n)
    {
        long long res = 0;
        res = res + cal(3,n/3,3);
        res = res + cal(5,n/5,5);
        res = res - cal(15,n/15,15);
        return res;
    }
private:
    long long cal(int x,int y,int d)//首项，项数，公差
    {
        long long res = (x + x+d*(y-1))*y/2;
    }
};

int main()
{
    int n = 9;
    Solution s;
    cout<<s.solution(n)<<endl;
    return 0;
}