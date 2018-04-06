#include<iostream>
#include<set>
#include<string>
using namespace std;
int main()
{
	set<string> s;
	s.insert("I");
	s.insert("love");
	s.insert("like");
	set<string>::iterator it;
	for(it = s.begin();it!=s.end();it++)
	{
		cout<<*it<<" ";
	}
	return 0;
}
