#include<iostream>
using namespace std;
//容易犯错的一点，数组下标应该-1
int main()
{
    int N,M;
    cin>>N>>M;
    int score[N];
    for(int i = 0; i< N;i++)
        cin>>score[i];
    char c[M];
    int id[M];
    int s[M];
    //cout<<M;
    for(int i = 0;i<M;i++)
    {
        cin>>c[i]>>id[i]>>s[i];
    }
    for(int i = 0;i<M;i++)
    {
        //int best = score[0];
        //cout<<c<<id<<s;
        if(c[i] == 'U')
        {
            score[id[i]-1] = s[i];
        }
        int data;
        if(c[i] == 'Q')
        {
            int best = score[id[i]-1];
            for(int j = id[i];j<=s[i];j++)
            {
                data = score[j-1];
                if(data>best)
                    best = data;
            }
            cout<<best;
            if(i !=M-1)
            	cout<<endl;
        }
    }
    return 0;
}
