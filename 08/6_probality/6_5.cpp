/*
问题：水库采样 流入若干个对象（整数），事先不知道个数。如何随机取出k个 （k小于总数）？


分析：算法：用一个数组a保存k个数 a[0..k -1]
		  对于第i个元素(i = 1,2,…)
			如果i <= k： 则a[i -1]存放这个元素，（前k个元素，直接放）
			否则：产生随机数x = rand() % i，（第i个时，1/i的概率产生一个随机数，随机替换a[0,k-1]范围内的数）
					若x < k,则用a[x]存放这个元素（扔掉之前的元素）

	证明：，假设目前已经流入n > k个元素，
	    第i( i <= k)个元素被选中的可能性
	    明显，最开始我们是要它的，其概率为1,然后每次替换被保留下的可能性为k/k+1,k+1/k+2一直到n-1/n，约分后变成k/n
		    1 * k / (k + 1) * (k + 1) / (k + 2) *…*(n -1) / n = k / n
	    第i (i > k)个元素被选中的可能性
	    什么情况下i会被留下？首先要它的可能性为k/i,以后每次被留下的可能分别为不被替换掉的可能，约分后也是k/n
		    k / i * i / (i + 1) * (i + 1) / (i + 2) *…* (n – 1) / n = k / n

    拓展：k == 1的特殊性
        1,用来在一个若干行的大文件中，随机选择一行
        2,在一个不知道长度的链表中，随机选择一个or多个元素

*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> poolsampling(vector<int> a,int k)
    {
        vector<int> res;
        int len = a.size();
        for(int i = 0;i<k;i++)//0-k-1直接放
            res.push_back(a[i]);
        for(int i = k;i<len;i++)//k及以后
        {
            int idx = rand()%(i+1);//产生0-i的随机数
            if(idx<k)//随机数在0-k-1范围内，替换，
                res[idx] = a[i];
        }
        return res;
    }
};
int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    vector<int> arr(a,a+10);
    Solution s;
    vector<int> b = s.poolsampling(arr,3);
    for(int i = 0;i<3;i++)
        cout<<b[i]<<endl;
    return 0;
}

