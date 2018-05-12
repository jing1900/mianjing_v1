/*
问题：给定n * n的01方阵，每一行都是降序的（即先连续的一段1，再连续的一段0），求1最多的那行中1的个数？

分析：我们可以二分出每一行01的分界线，这时时间复杂度为nlogn

     优化：如果某个位置上为1,则往右，否则往下，(我们只有找到比该行更多的1才有意义),时间复杂度为N

*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(vector<vector<int> > a)
    {
        int n = a.size();
        int best = 0;//每行1最多多少
        for(int i = 0;best<n&&i<n;i++)
        {

            while(best<n && a[i][best] == 1) ++best;

            //否则i++，统计下一行，若best处是1,继续往后统计，否则继续i++
        }
        return best;
    }
};
int main()
{
    int a[4][4]={
    {1,0,0,0},
    {1,0,0,0},
    {1,1,0,0},
    {1,0,0,0}
    };
    vector<vector<int> > arr(4,vector<int>(4));
    for(int i = 0;i<4;i++)
    {
        for(int j = 0;j<4;j++)
            arr[i][j] = a[i][j];
    }
    Solution s;
    cout<<s.solve(arr)<<endl;
    return 0;
}