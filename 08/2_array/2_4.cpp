/*
问题：	一个数组，所有元素都出现了两次，只有两个数只出现了一次，求这两个数。


分析：所有数做亦或，得到的结果为这俩数亦或的结果。然后我们找到这个结果中二进制表示第一个非0的位，

    然后将所有数根据该位是否为1分开，分别做亦或，得到的结果即为这两个数。

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<int> a)
    {
        int res = 0;
        for(int i = 0;i<a.size();i++)
        {
            res ^= a[i];
        }

        int temp = res;
        int flag = 0;//哪一位非0

        for(int i = 0;i<32;i++)
        {
            if((temp>>i) & 1 == 1)
            {
                flag = i;
                break;
            }
        }
        int res1 = 0;
        for(int i = 0;i<a.size();i++)
        {
            if((a[i]>>flag)&1 == 1)//只处理flag位为0的值
                res1^=a[i];
        }
        res = temp^res1;
        cout<<res<<" "<<res1<<endl;

    }
};

int main()
{
    int arr[6] = {1,2,4,5,2,1};
    vector<int> a(arr,arr+6);
    Solution so;
    so.solve(a);
    return 0;
}