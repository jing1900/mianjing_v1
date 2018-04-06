#include<iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int l1 = -90;
        int l2 = 0;
        int r1 = 0;
        int r2 = 90;
        int mid;
        int k = 6;
        int c[6]={0};
        while(k--)
        {
            //cout<<k<<" ";
            //cout<<n<<" ";
            
            if( n>= l1 && n < l2)
            {
                //cout<<"1";
                c[5-k] = 0;
                mid = l1 + int((l2-l1)/2);
                l1 = l1;
                r2 = l2;
                l2 = mid;
                r1 = mid;
                //r2 = l2;
                cout<<l1<<" "<<l2<<" "<<r1<<" "<<r2<<"  |  ";
            }
            else
            {
                //cout<<"2";
                c[5-k] = 1;
                mid = r1 + int((r2-r1)/2);
                l1 = r1;
                r2 = r2;
                l2 = mid;
                r1 = mid;
                
                cout<<l1<<" "<<l2<<" "<<r1<<" "<<r2<<"  |  ";
            }
            //cout<<c[5-k]<<" ";
        }
        for(int i = 0; i<6;i++)
            cout<<c[i];
        cout<<endl;
    }
}
