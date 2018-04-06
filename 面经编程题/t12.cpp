#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<string> arr;
//	arr.push_back("cb");
	arr.push_back("bc");
	//arr.push_back("ba");
	sort(arr.begin(),arr.end());
	vector<string>::iterator it;
	for(it = arr.begin();it!= arr.end();it++)
		cout<<*it<<endl;
	return 0;
}
