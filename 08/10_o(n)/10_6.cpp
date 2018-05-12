/*
	单调队列

	问题1：滑动窗口最值  （栈和队列 例6 3_6.cpp）

	滑动窗口最大值：给定一个数组a［0..n],还有一个值k，计算数组b［i］ = max(a[i –(k-1),i-(k-2).. i-(k-k)])
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

	问题2：给定一个数组A和整数K,问有多少对下标i <= j满足max(A[i..j]) – min(A[i..j]) <= K
	分析：如果(i,j)满足条件，则子窗口(i + 1,j) (i + 2, j)…都满足条件。这是因为，窗口越小，最大值肯定越小，最小值肯定越大，因此差值定小于k
		对每个i，找到第一个不满足条件的j（此时这个窗口已经是从i开始的最大的窗口了）
		那么在计算i+1开始的窗口时，j是无需往左，只需从当前位置继续往右
		那么，如何求窗口[i..j]的最大最小值？
			用两个单调队列，一个队头维持窗口最大值，一个队头维持窗口最小值
			如果最大值-最小值<=k,j继续往右，直到不满足，那么有j-i对下标是满足条件的。

*/
#include<bits/stdc++.h>
using namespace std;
class Solution2
{
public:
    int solution(int k,vector<int> A)
    {
        deque<int> qmin,qmax;//存放窗口[i,j]中最小和最大值索引
        int answer = 0;
        for(int i = 0,j = 0;i<A.size();i++)
        {
            while(j<A.size())
            {
                while(!qmin.empty()&&(A[j]<=A[qmin.back()]))//如果队尾元素比a[j]要大or相等，没必要留
                    qmin.pop_back();
                qmin.push_back(j);
                while(!qmax.empty()&&A[j]>=A[qmax.back()])//如果队尾元素比a[j]要小or等于，没必要留
                    qmax.pop_back();
                qmax.push_back(j);
                if(A[qmax.front()]-A[qmin.front()]<=k)
                    ++j;
                else
                    break;
            }
            if(qmin.front() == i)//若是i，下一次循环变成了i+1,i这个位置上的元素应该过期掉
                qmin.pop_front();
            if(qmax.front() == i)
                qmax.pop_front();
            answer+=(j-i-1);//注意这里j多加了一个位置
        }
        return answer;
    }
};

int main()
{
    int a[6] = {3,4,6,7,9,8};
    int k = 3;
    vector<int> A(a,a+6);
    Solution2 s;
    cout<<s.solution(k,A)<<endl;
    return 0;
}