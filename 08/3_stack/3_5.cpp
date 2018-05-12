/*
https://leetcode.com/problems/largest-rectangle-in-histogram/description/
问题： 给出一个直方图，求最大面积矩形 （Leetcode 84)

分析：用堆栈分析每一块板能延伸到的左右边界（要求，这个延伸范围内的板高都大于等于当前），为让所有元素出栈，再人为的在最后加一块高为0的板

每块板i的高度h(i)入栈，高度比栈顶大入栈，该板的左边界定为之前栈顶元素的编号

高度比栈顶小，栈顶元素出栈，确定右边界为当前板号i。

左边界确定为当前板的下边板的编号（如果栈为空，则-1），有板比当前板小出栈，右边界确定为当前让其出栈的板号

时间复杂度为O(n)

//这个思路太精妙了
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(),res = 0;
        stack<int> s;
        for(int i = 0;i<n;++i)//遍历每块板
        {
            while(!s.empty()&&heights[s.top()]>=heights[i])//如果栈非空，且栈顶元素高于等于当前元素，右边界确定为i
            //原题这里>=和>都通过了，我猜是因为测试用例板高不重复，否则理论上应该是大于。
            {
                int h = heights[s.top()];
                s.pop();
                res = max(res,(i-1-(s.empty()?(-1):s.top()))*h);//右边界延伸到i-1，注意i是不满足高于之前板这个条件的。
            }
            s.push(i);//否则栈空or当前板高于之前板，直接入栈 板编号
        }
        while(!s.empty())//处理剩下的没出栈的，相当于在最后加了块高为0的板
        {
            int h = heights[s.top()];
            s.pop();
            res = max(res,(n-1-(s.empty()?(-1):s.top()))*h);//这些板的右边界都延伸到了n-1，这里s.top是栈顶元素的下一块板的编号，即左边界
        }
        return res;
    }
};