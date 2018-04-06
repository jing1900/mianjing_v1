/*#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;

int main(){
        string s;
        char l;
        map<char, int> m;
        cout << "Input the queue" << endl;
        cin >> s;
        for (int i = 0; i<s.length(); i++){
                l = s[i];
                if (m.find(l)==m.end()){
                        m[l] = 1;
                }else{
                        m[l] ++;
                }
        }
        map<char, int>::iterator it;
        for (it = m.begin(); it != m.end(); it++){
                if (it->second==2){
                        cout << it->first << endl;
                        break;
                }
        }
        return 0;
}*/

/*
问题：一个字符数组中，每个字符都出现了三次，只有1个出现两次，快速找出这个出现两次的

思路：
	1，统计每个字符出现的次数
	2，遍历map，找出出现2次的
*/
#include<iostream>
#include<map>
using namespace std;
int main()
{
	string s;
	map<char,int> m;
	int i;
	char c;
	cout<<"请输入字符数组，以字符串的形式:"<<endl;
	cin>>s;
	//统计
	for(i =0; i<s.length();i++)
	{
		c = s[i];
		if(m.find(c) == m.end())
			m[c] = 1;
		else
			m[c]++;
	}
	//
	map<char,int>::iterator iter;
	for(iter = m.begin();iter != m.end();iter++)
	{
		if(iter->second == 2)
		{
			cout<<iter->first<<endl;
			break;
		}
	}
	return 0;
}
