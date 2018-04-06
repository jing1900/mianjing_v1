#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i<n;i++)
    {
        cin>>a[i];
       // cout<<a[i]<<" ";
    }
    //cout<<a.reverse();
    if( n == 0)
    {
        cout<<a[0];
        return 0;
    }
    int c[n];
    int b[n];
    c[0] = b[0] = a[0];
    for(int i = 1;i<n;i++)
    {
        c[i] = a[i];
        for(int j = 0; j <= i;j++)
        {
            b[j] = c[i-j];
        }
        for(int j = 0;j <=i;j++)
        {
            c[j] = b[j];
        }
    }
    for(int i = 0;i<n-1;i++)
        cout<<b[i]<<" ";
    cout<<b[n-1];
}
