/*不创建变量交换两个数*/
#include<iostream>
using namespace std;
int main()
{
	int A,B;
	cout<<"请输入要交换的两个数"<<endl;
	cin>>A;
	cin>>B;
	A = A^B;
	B =A^B;
	A = A^B;
	cout<<A<<" "<<B<<endl; 
	return 0;
}
