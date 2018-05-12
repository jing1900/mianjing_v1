/*
问题：翻转句子中全部的单词，单词内容不变，例如I’m a student.  变为student. a I’m

分析：while(i<j) swap(s[i++],s[j--]);这种效果可以翻转整个句子 ： .tneduts a m’I，
再对每个单词单独反转，即可得到结果


拓展题：字符串循环移位abcd

如果长度为n，移位m，那么m=m%n; 前m位翻转，后n-m位翻转，再整体翻转。
比如这里m=1,那么a，dcb ->bcda
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void reverse(string &s)
    {
        int i = 0,j = s.size()-1;
        rev(s,i,j);

        i = 0;//i,j为一个单词的开始和结束位置
        for(int k = 0;k<s.size();k++)
        {
            if(s[k] == ' ')
            {
                j = k-1;
                rev(s,i,j);
                i = k+1;

            }

        }
        rev(s,i,s.size()-1);//反转最后一个单词
    }

    void rev(string& s,int i,int j)//反转s中从i到j位置的内容
    {
        while(i<j) swap(s[i++],s[j--]);
    }
};

int main()
{
    string s = "I'm a student.";
    Solution so;
    so.reverse(s);
    cout<<s<<endl;
    return 0;
}