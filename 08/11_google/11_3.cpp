/*问题： 一个整数组里包含0-(n-1)的排列 (0到(n-1)恰好只出现一次）
，如果每次只允许把任意数和0交换，求排好顺序至少交换多少次。 （PAT 1067）

分析：这个问题是组合数学里的圈，比如0占了1的位置，1占了2的位置，2占了0的位置，总能划分为若干个不相交的圈
然后这个圈长度m，如果有0,则最少交换m-1次即可，若没有，则需交换m+1次

代码中我们如何找环呢？

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //bool visited
    int solution(vector<int> a,int n)
    {
        int res = 0;
        vector<bool> visited(n,false);//元素是否被访问过，记录的是元素本身，
        for(int i = 0;i<n;i++)
            res+=count(a[i],a,visited);
        return res;
    }
private:
    int count(int x,vector<int> &a,vector<bool> &visited)//计算每个元素交换次数
    {
        int r = 0;//所在环元素个数
        bool have = false;//环内是否有0
        for(;!visited[x];r++)
        {
            if(x == 0) have = true;
            visited[x] = true;
            x = a[x];//这里很巧妙，x取新的值。比如这里x为3,我们将3加入环中之后，再去取位置3上的值，依次循环，看是否已被加过环，
            //直到遍历到有被访问过得元素时停止，成环

        }
        return have?r-1:(r<=1)?0:r+1;
    }
};

int main()
{
    int n = 12;
    vector<int> a;
    for(int i = 0;i<n;i++)
        a.push_back(i);
    random_shuffle(a.begin(),a.end());
    Solution s;
    cout<<s.solution(a,n)<<endl;
    return 0;
}