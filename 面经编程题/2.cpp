/*
*/
#include<iostream>
using namespace std;
int main()
{
	char a[4] = {'1','2','3','4'};
//	char a[4] = {1,2,3,4};
	char *b = a;
	b[0] = 100;
	for(int i = 0; i< 4;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
//char a[4] = {1, 2, 3, 4}; char *b = a; b[0] = 100;
