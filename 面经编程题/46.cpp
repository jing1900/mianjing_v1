#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
/*
这里我用了一个非常笨的解题思路，为什么这么说，我先是尝试了不排字典序的全排列，得到之后先视图
先排序原字符串，再输出，发现得到的全排并非字典序。没办法又换了种方法，将所有的全排存下来，
排序后再输出

这里且记传参时的传引用和复制的区别
*/
void swap(string &s,int i,int j)
{
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
}
bool isneedswap(string s,int b,int e)
{
    for(int i = b+1;i<e;i++)
    {
        if(s[i] == s[e])
            return false;
    }
    return true;
}
void getfullarray(vector<string> &arr,string &s,int b,int e)
{
    //int i = 0;
    //vector<string> v;
    if(b == e)
    {
        //cout<<s<<endl;
        arr.push_back(s) ;
        
    }    
    else
    {
        for(int i= b;i<e;i++)
        {
            //如果b之后到i位都是一样的，就不用处理，continue即可
            if(isneedswap(s,b,i))
            {
                swap(s,b,i);
                getfullarray(arr,s,b+1,e);
                swap(s,b,i);
            }

        }
    }
    
}
int main()
{
    string s;
    while(cin>>s)
    {
        //cout<<s<<endl;
        //string arr[2^(s.size())];
        //sort(s.begin(),s.end());//以字典序输出
        //int i = 0;
        vector<string> arr;
        getfullarray(arr,s,0,s.size());
        
        sort(arr.begin(),arr.end());
        vector<string>::iterator it;
        for(it = arr.begin();it!=arr.end();it++)
            cout<<*it<<endl;
        cout<<endl;
    }
    return 0;
}
