/*
问题：给定两个串a和b，问b是否是a的子串的变位词。例如输入a = hello, b = lel, lle, ello都是true,但是b = elo是false。

分析：这里涉及到滑动窗口和词频统计的思想
    定义一个和b长度大小相同的窗口，统计词频，分析和b是否一样，但这样的话，每滑动一次都要比较一次，有没有更好的方法呢？
    暂且假定我们的输入都是小写字母，因此我们定义一个[0,25]的数组表示b中每个单词出现多少次。同时，统计下b中多少个字母是非0的。
    int nonzero = 0;
    for(int i=0;i<lenb;i++)
        if(++nums[b[i]-'a'] == 1) ++nonzero;
    然后，我们用b中的次数，减去a中一个窗口内的字符种类，如果结果都为0,那么找到这样的字串了。注意，这里nums的含义变成了字符种类差
    第一个窗口为[0,lenb-1],（注意lena<lenb是无解的)
    for(int i =0;i<lenb;i++)
    {
        int c = a[i] - 'a';
        --nums[c];
        if(nums[c] == 0) --nonzero;
        else if(nums[c] == -1) ++nonzero;
    }
 if(nonzero == 0) return true;
*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool solve(string a,string b)
    {
        if(a.size()<b.size()) return false;
        int nonzero = 0;
        int nums[26];
        for(int i = 0;i<b.size();i++)//nums先统计b中词频
        {
            if(++nums[b[i]-'a'] == 1) nonzero++;
        }
        int temp = nonzero;
        //再来逐个和a中的每个窗口比对。这里窗口如何滑动呢？首先原窗口为[i-lenb,i-1],新窗口为[i-lenb+1,i],相当于扔掉最左边的，再加入a[i].
        //这个思想无比精妙，节省了很多时间复杂度
        for(int i = b.size();i<a.size();i++)//i为每个窗口的结束位置。第一个窗口为[0,lenb-1]
        {
            int c = a[i-b.size()] -'a';//原窗口最左边元素,不属于当前窗口了，还原回去，++
            ++nums[c];
            if(nums[c] == 1) nonzero++;
            else if(nums[c] == 0) nonzero--;

            c = a[i]-'a';//新窗口加入的元素
            --nums[c];
            if(nums[c] == 0) nonzero--;
            else if(nums[c] == -1) nonzero++;
            if(nonzero == 0) return true;
        }
        return false;
    }
};

int main()
{
    string a = "hello";
    string b = "elo";
    Solution so;
    cout<<so.solve(a,b)<<endl;
    return 0;
}