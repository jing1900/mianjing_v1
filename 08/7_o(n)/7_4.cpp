/*
问题： 给定数组a，求下标对儿（i, j）满足a[i] ≤ a[j]，并且j – i最大。

分析：假设目前最优解为d，那么对于j，则只需要检查i= j-d-1，即检查最优解范围外的部分，看会不会更优即可

    首先，我们记录下前缀最小值p[x] = min{p[0,..,x]}
    倒着循环j，对每个j看下a[j-d-1]是否<=a[j],如何判断?用p[j-d-1]是否<=a[j]，若是，肯定还能往前移。否则，不用移了，前面所有的都比a[j]要大

    建议画图分析
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int run(vector<int> a)
    {
        int n = a.size();
        int p[n];
        for(int i = 0;i<n;i++)
            p[i] = i?min(a[i],p[i-1]):a[i];
        int best = 0;
        for(int j = n-1;j>best;j--)//只需倒序检查最优解范围外的部分
        {
            while((j>best)&&(a[j]>=p[j-best-1]))    best++;//p指导了我们还能否再增大间隙best，能就一直增，不能就换j再试试
        }
        return best;
    }
};
int main()
{
    int a[7] = {1,2,4,5,7,2,2};
    vector<int> arr(a,a+7);
    Solution s;
    cout<<s.run(arr)<<endl;
    return 0;
}
