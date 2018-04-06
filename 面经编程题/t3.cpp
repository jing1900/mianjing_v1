#include<iostream>
#include<cmath>
using namespace std;
/*这道题的思想是，第一颗棋子，只需保证棋盘任意一个格子至少有1 个棋子，看走几步
第二个棋子，需要保证棋盘任意一个格子至少需要2个棋子，看走几步，这样依次类推。
最少的操作次数，需要对路线做规划，尽量选一个位子，让所有已有元素移动到其的距离最短。

对每一个范围内的数，遍历其x距离内的所有值，和y范围内的所有值，找到一个距离最小的点，设为最短距离点打印*/
int main()
{
    int n;
    cin>>n;
    int x[n];
    int y[n];
    for(int i = 0; i< n;i++)
        cin>>x[i];
    for(int i = 0;i<n;i++)
        cin>>y[i];
    int minx = 1^18;
    int maxx = 0;
    int miny = 10^18;
    int maxy = 0;
    int ix;
    int iy;
    int min_len = 1^18;
    int len;
    for(int i = 0; i < n;i++)
    {
        len = 0;
        //计算x,y边界
        for(int j = 0; j<= i; j++)
        {
            if(x[j] < minx )
                minx = x[j];
            if(x[j]> maxx)
                maxx = x[j];
            if(y[j]<miny)
                miny = y[j];
            if(y[j]>maxy)
                maxy = y[j];
            
        }
        //计算ix，iy
        if(minx == maxx)
        {
            ix = minx;
            int min_s = 10^19;
            int s;
            for(int r =miny;r<= maxy;r++ )
            {
                s = 0;
                for(int w = 0; w <=i;w++)
                {
                    s+= abs(ix-x[w]) + abs(r-y[w]);
                }
                if(s < min_s)
                {
                    min_s = s;
                    iy = r;
                    //ix = c;
                }
            }
            
        }
        else if(miny == maxy)
        {
            iy = miny;
            int min_s = 10^19;
            int s;
            for(int r =minx;r<= maxx;r++ )
            {
                s = 0;
                for(int w = 0; w <=i;w++)
                {
                    s+= abs(r-x[w]) + abs(iy-y[w]);
                }
                if(s < min_s)
                {
                    min_s = s;
                    ix = r;
                    //ix = c;
                }
            }
//	    cout<<ix<<" "<<iy<<endl;	
        }
        else
        {
            int min_s = 10^19;
            int s;
            for(int c = minx; c<= maxx;c++)
            {
                for(int r =miny;r<= maxy;r++ )
                {
                    s = 0;
                    for(int w = 0; w <=i;w++)
                    {
                        s+= abs(c-x[w]) + abs(r-y[w]);
                    }
                    if(s < min_s)
                    {
                        min_s = s;
                        iy = r;
                        ix = c;
                    }
                }
            }
        }
	cout<<ix<<" "<<iy<<endl;
        //计算当下的len
        for(int j = 0; j<=i;j++)
        {
            len += abs(ix-x[j])+abs(iy-y[j]);
        }
//        cout<<len<<" ";

    }
    return 0;
    
}
