#include<iostream>
#include<string.h>

using namespace std;

//void findNext(char *p,int next[])
int main()
{
	char *p ="happy";
	int next[7];
	int len = strlen(p);
	next[0] = -1;
	int k = -1;//前缀下标
	int j = 0;//后缀下标
	while( j < len-1)
	{
		++j;
		cout<<j<<endl;
	}
}
