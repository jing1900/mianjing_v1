/*
问题：删除一个字符串所有的a,并且复制所有的b。注：字符数组足够大

分析：数组足够大，意味着无需新建数组，只需在原数组上做修改即可
    首先，删除a，只需重新维持一个idx（从0开始），不断将非a的元素放入即可，在这个过程中，同时统计b的数目有多少
    然后复制b，通过上一步，我们可以得到新数组的长度应为idx(更新后的)+nums(b),然后从后往前遍历，从新数组的末尾开始放即可

*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(string &s)
    {
        int n = s.size();
        int idx = 0;
        int numsb = 0;
        for(int i = 0;i<n;i++)//删除a，并统计b的数量
        {

            if(s[i] != 'a') s[idx++] = s[i];
            if(s[i] == 'b') numsb++;
        }
        int new_len = idx+numsb;//新索引
        for(int j = new_len-1,i=idx-1;i>=0;i--)//这里要注意索引都是从0开始的。
        {
            s[j--] = s[i];
            if(s[i] == 'b') s[j--] = s[i];
        }
    }
};

int main()
{
    string s ="aabbc";
    Solution so;
    so.solve(s);
    cout<<s<<endl;
    return 0;
}
