/*
		• 一个 N*M 的矩阵，从左上走到右下最小需要（N+M）步走完，问一共有多少种走法。 
		C(m+n,n)
*/
/*#include<iostream>
using namespace std;
class JieCheng
{
public:
	int jieCheng(int n)
	{
		if(n == 1)
			return 1;
		return n*jieCheng(n-1);
	}
};
int main()
{
	int n = 0, m = 0;
	cin>>n>>m;
	JieCheng J;
	int d = J.jieCheng(n+m)/(J.jieCheng(n)*J.jieCheng(m));
	cout<<d<<endl;
	
}*/
#include<iostream>
using namespace std;
int jie(int n)
{
	if(n == 1)
		return 1;
	return n*jie(n-1);
}
int main()
{
	int n,m;
	cout<<"请输入n，m"<<endl;
	cin>>n;
	cin>>m;
	cout<<(jie(n+m)/(jie(n)*jie(m)))<<endl;
	return 0;
}
