/*
问题：把一个0-1串（只包含0和1的串）进行排序，你可以交换任意两个位置，问最少交换的次数？

分析：明显，排好序之后0在左边，1在右边，因此左边的0和右边的1都可以不考虑，
     维持两个指针，分别从左到右扫第一个1的位置，和从右往左扫第1个0的位置，交换即可
     这里甚至不需真的交换，只需记录下交换的次数即可
     时复:o(len)
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int count(string s)
    {

        int c = 0;
        for(int i = 0,j = s.size()-1;i<j;i++,j--)
        {
            for(;i<j && s[i] =='0';i++);
            for(;i<j && s[j] =='1';j--);
            if(i<j) c++;
        }
        return c;
    }
};

int main()
{
    string s = "010101";//1次
    Solution so;
    cout<<so.count(s)<<endl;
    return 0;
}