#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1 = "hello";
	string s2 = "world";
	string s3 = s1+s2;
	if(s3.find("") != string::npos)
		cout<<"yes";
	cout<<s3;
}
