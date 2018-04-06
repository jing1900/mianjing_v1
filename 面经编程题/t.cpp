#include<iostream>
using namespace std;
int main()
{
    int n;//数列长度
    cin>>n;
    int a[n];
    for(int i = 0; i< n;i++)
    {
        cin>>a[i];
    }
    
    //sort
    int j = n;
    int flag = 0;
    while(j)
    {
        for(int i = 0; i<j-1;i++)
        {
            flag = 0;
            if(a[i]>a[i+1])
            {
                int temp = a[i];
                a[i] = a[i+1];
                a[i+1]= temp;
                flag = 1;
            }
        }
        if(flag == 0)
            break;
        j--;
    }
    
    int d = a[1]-a[0];
    for(int i = 1;i <n;i++)
    {
        cout<<a[i]<<" ";
        if(a[i] -a[i-1] != d)
        {
            cout<<"Impossible";
            return 0;
        }
    }
    cout<<"Possible";
    return 0;
}
