/*
问题：给定浮点数组a,求一个数组b, b[i] = a[0] * a[1] *…*a[i – 1] * a[i + 1] * …*a[n – 1],跳过a[i]
    不能使用除法，不允许再开数组

分析：先求后缀积，从a[i]****a[n-1]
    for(int i = n-1;i>=0;i--)
        b[i] = a[i]*((i==n-1)?1:b[i+1])//注意，这里用了迭代的思想，乘的是b[i+1]
     顺便求前缀积，
    顺便求前缀积
    for(int i = 0,j =1;i<n;j*=a[i++])//j初始化为1,是因为累乘
        b[i]= j*((i==n-1)?1:b[i+1]);//注意，这里是先执行这个，然后才j*=a[i++]的，因此此时b[i] 就是b[i+1]*(前缀和a[i-1]，*a[i]还没来得及算

拓展：a[i] + a[i + 1] + … + a[j] = sum[j] – sum[i – 1]，易知，sum为前缀和

思考题：给定数组，求连续子数组和，绝对值最小，即和越接近0.
    结合上面，只需两两求前缀和的差，排个序

思考题2：	把一个数组从中间p位置分开，使得a[0] + ..+ a[p – 1]与a[p] + a[p + 1] + …+ a[n – 1]差值最小？
		提示：前缀和，与总和减去该前缀和（后面部分），的差最小，枚举

*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> solution(vector<int> a)
    {

        vector<int> b(4,0);//这里一定要初始化
        int n = a.size();

        for(int i = n-1;i>=0;i--)//求后缀和
        {
            if(i == n-1)
                b[i] = a[i];
            else
                b[i] = a[i]*b[i+1];
            //b[i] = a[i]*((i == n-1)?1:b[i+1]);
        }

        //更新b
        for(int i = 0,j=1;i<n;j*=a[i++])
        {
            b[i] = j*((i == n-1)?1:b[i+1]);
        }
        return b;
    }
};

int main()
{
    int arr[4] = {1,2,3,4};
    vector<int> a(arr,arr+4);
    Solution so;
    vector<int> b;
    b = so.solution(a);
    for(int i = 0;i<4;i++)
        cout<<b[i]<<endl;
    return 0;

}