/*
问题：滑动窗口最大值：给定一个数组a［0..n],还有一个值k，计算数组b［i］ = max(a[i –(k-1),i-(k-2).. i-(k-k)])
    若i<k-1,认为负数下标对应值是无穷小

分析：即分析以i之前k个元素范围到i 这个范围的最大值，作为b[i]处的值，

    方法1：用一个最大堆存放这k个数，时间复杂度为n*logk,因为n个元素，然后每出入一次堆都为logk的时间复杂度
    如果计算好了b[i-1]，那么如何计算b[i]呢？
    首先， a[i-k]（即a[i-1 - (k-1)出堆
    然后a[i]入堆
    然后b[i] = 堆顶即可

    但这个时间复杂度还不是最理想的，我们可以做到线性
    方法2：我们可以使用一个双端队列，
    如果队尾的数<=将要入队的数a[i],则扔掉队尾的数，将a[i]放入队尾
    否则，如果入队元素小于队尾，不仍队尾的，直接诶放入队尾即可
    这样一来，队列的元素从队头到队尾是单减的，队头永远是窗口最大值
    队头何时过期呢？i>队头元素索引+k-1 比如队头为a[0],k=3,i= 3时，就过期了
    时间复杂度O(n)
*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> solution(vector<int> a,int k)
    {
        int n = a.size();
        vector<int> b(n,0);
        deque<int> q;//双端队列，存的是下标
        for(int i = 0;i<n;i++)
        {
            while(!q.empty()&&q.front()<=i-k) q.pop_front();//过期
            while(!q.empty()&&a[q.back()]<=a[i]) q.pop_back();//队尾太小
            q.push_back(i);//入队尾
            b[i] = a[q.front()];
        }
        return b;
    }
};

int main()
{
    int arr[6] = {4,2,7,6,5,8};
    vector<int> a(arr,arr+6);
    Solution so;
    vector<int> b = so.solution(a,3);
    for(vector<int>::iterator iter = b.begin();iter!=b.end();iter++)
        cout<<*iter<<endl;
    return 0;
}