/*
问题： 给定一些元素的入栈顺序和出栈顺序（不是入完再出那种，而是随时入随时出），问是否是可能的？（假设所有元素都不相同）
分析：直接用栈模拟该操作，如果栈顶元素和当前要出栈的元素相等的话，则必须出栈

    否则就入栈。注意判断两个vector size是否一样


//之后我分析了下，发现确实可行，想出这个方法的人是天才吧


*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPossible(vector<int> in,vector<int> out)
    {
        stack<int> s;
        for(int i = 0,j=0;j<out.size();j++)//遍历出栈队列
        {
            while(s.empty() || s.top() != out[j])//如果栈为空or出栈元素和栈顶不等，入栈。注意这里是while
            {
                if(i>=in.size()) return false;
                s.push(in[i++]);
            }
            s.pop();//出栈元素等于栈顶元素
        }
        return true;
    }
};
int main()
{
    int in_arr[6] = {3,4,5,1,2,3};
    int out_arr[6] = {3,5,4,3,2,1};
    vector<int> in(in_arr,in_arr+6);
    vector<int> out(out_arr,out_arr+6);
    Solution so;
    cout<<so.isPossible(in,out)<<endl;
    return 0;
}