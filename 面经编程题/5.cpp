/*
	• 一个大写字符串如ABABB（len<1000），代表游客进游乐场的顺序及从哪个入口进入，要求每个入口(不多于26个入口)从第一个游客直到该入口的最后一个游客，检票员都不能离开，问最少检票人数K。 

*/
/*
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<typeinfo>
using namespace std;


int main(){
	string s;
	map<char, int> beg;
	map<char, int> end;
	int i, temp;
	char l;
	bool flag=true;

	cin >> s;
	for (i = 0; i<s.length(); i++){
		l = s[i];
		if (beg.find(l)!=beg.end()){
			end[l] = i;
		}else{
			beg[l] = end[l] = i;
		}

	}
	///*
	//
	map<char, int>::iterator iter;
	vector<int> start,stop;

	for (iter = end.begin(); iter != end.end(); iter++){
		l = iter->first;
		cout << l << " " << beg[l] << " " << end[l] << endl;
		start.push_back(beg[l]);
		stop.push_back(end[l]);		
	}

	sort(start.begin(), start.end());
	sort(stop.begin(), stop.end());

	//for (int i = 0; i != start.size(); i++){
	//	cout << start[i] << " " << stop[i] << endl;
	//}
	//flag用来判断贪心之后，还需不需要再一轮的判断
	while(flag){
		//结束时间的第一个值
		temp = stop[0];
		//先设置为不需要再判断
		flag = false;
		//遍历从小到大排列的开始时间
		for (int i = 0; i != start.size(); i++){
			//如果开始时间大于结束时间，那么需要下一轮的判断
			if (temp < start[i]){
				flag = true;
				//删除当前结束时间
				stop.erase(stop.begin());
				//删除当前大于结束时间的开始时间
				start.erase(start.begin()+i);
				break;
			}
		}
	}
	cout << start.size() << endl;
	return 0;
}*/
/*
思路：
1,统计每个入口开始有人和没人的时刻
2，将其按顺序放入vector，并排序
3，使用贪心算法，去除那些可以使用之前的售票员的入口
*/
#include<algorithm>
#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main()
{
	//初始化变量
	string s;
	char l;
	int i;
	bool flag = true;
	map<char,int> start;
	map<char,int> stop;
	cout<<"请输入进入顺序字符串，如ABABB:"<<endl;
	cin>>s;
	//统计每个入口的开始有人和没人时刻
	for(i = 0; i< s.length();i++)
	{
		l = s[i];
		if(start.find(l) == start.end())
		{
			start[l] = stop[l] = i;
		}
		else
			stop[l] = i;
	}
	//将其放入vector，并排序
	vector<int> b,e;
	map<char,int>::iterator iter;
	for(iter = stop.begin();iter!=stop.end();iter++)
	{
		l = iter->first;
		e.push_back(stop[l]);
		b.push_back(start[l]);
	}
	sort(b.begin(),b.end());
	sort(e.begin(),e.end());
	//贪心算法
	int temp = 0;
	while(flag)
	{
		temp = e[0];
		flag = false;
		for(i = 0; i<b.size();i++)
		{
			if(b[i]>temp)
			{
				flag = true;
				e.erase(e.begin());
				b.erase(b.begin()+i);
			}	
		}
	}
	cout<<b.size()<<endl;
	return 0;
}
