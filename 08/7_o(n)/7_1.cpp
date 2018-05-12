/*
问题：输入为n×n的邻接矩阵。第i行第j列代表i是否认识j，(1表示认识,0表示不认识)，并且A认识B并不意味着B认识A,对角线上的元素不关心（自身）
   名人定义为他不认识任何人且所有人都认识他的人。请求出所有名人。

分析：最多有几个名人呢？只有1个，因为有两个的话，它们互相认识不认识？

    笨方法：遍历i，检查每个j，看是否满足i不认识j但j认识i，时复为n^2

    O(n)的方法：对于两个人i，j，如果i认识j，那么i明显不是名人，删掉i
               如果i不认识j，则j也显然不是名人，删掉j。
            最终剩余1个人，检查其是否为名人即可

    实现1：用一个数组保存所有没检查人的编号。数组如何删除a[i]?不保证顺序的时候，只需让a[i] = a[--n]即可。
    为什么呢?是因为此时，将数组结尾的元素放到了需要删除的位置，同时数组的长度也-1了

    实现2：上面的空间也为N，那么可以将其优化为常数空间么。一头扫,ij一起扫，保证i<j，并且0-i-1没有名人，i-j-1也是没有名人的
    如果i认识j，那么i肯定不是名人，删掉,令i=j,j = j+1
    如果i不认识j，那么j肯定不是，j = j+1.
    i，j始终为可能是名人的两人

    实现3,两头扫的方法，让i = 0,j=n-1,i<j 则0-i-1是没名人，j+1,n-1是没有名人的。
        如果i认识j，则删掉i，i++。
        如果i认识j，则j--



*/
#include<bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    int findP(int know[][4],int k)
    {
        int n = k;
        int a[n];//没检查过的人
        for(int i =0;i<n;i++)
            a[i] = i;
        while(n>1)//直到没检查的人只有1个了
        {
            if(know[a[0]][a[1]])//0位置上的人知道1位置上的人，那么0不是，删除
                a[0] = a[--n];//注意，这里应该是--n
            else//0位置不知道1位置，删除1
                a[1] = a[--n];
        }

        for(int i = 0;i<k;i++)//检查最后一个元素是否是名人，这里不应该是n了，应该是know.size()
        {
            if((i!=a[0])&&(know[a[0]][i] || !know[i][a[0]]))//非a[0]的人，一旦a[0]关注了，or 没有关注a[0]，return-1即可
                return -1;
        }

        return a[0];//名人
    }
};


class Solution2
{
public:
    int findP(int know[][4],int k)
    {
        int i = 0,j =1;//维持两个指针，j始终比i大
        for(;j<k;j++)//遍历j
        {
            if(know[i][j])//如果i认识j，i肯定不是名人，令i = j，j继续++
                i = j;
            //这里隐含了一个判断，else，如果i不认识j，那么j肯定不是名人，j = j+1. 相当于j之前的都肯定不是名人，
            //因此上面才能直接让i = j
        }
        for(j = 0;j<k;j++)//i为可能的名人，遍历其余，判断其是否是真的名人
        {
            if((j!=i)&&(know[i][j] || !know[j][i]))
                return -1;
        }
        return i;
    }
};

class Solution3
{
public:
    int findP(int know[][4],int n)
    {
        int i = 0,j = n-1;
        while(i<j)
        {
            if(know[i][j])//i知道j，i++
                i++;
            else
                j--;
        }
        for(j = 0;j<n;j++)//i为可能的名人，遍历其余，判断其是否是真的名人
        {
            if((j!=i)&&(know[i][j] || !know[j][i]))
                return -1;
        }
        return i;
    }
};
int main()
{
    int k[4][4] ={
        {1,0,0,0},
        {1,1,0,0},
        {1,0,1,0},
        {1,0,0,1}
    };
    //vector<vector<int> > know(k,k+4);
    Solution3 s;
    cout<<s.findP(k,4)<<endl;
    return 0;
}