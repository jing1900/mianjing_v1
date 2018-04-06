/*
一个数据流中，如何采样得到100个数，保证采样得到的100个数是随机的
思路：这个问题可以被抽象为从N个元素中抽K个，其中N无法确定，且每个数据只能被读1次
这个是蓄水池问题的抽象，对于n，如果每次以k/i的概率决定是否将其放入蓄水池中，那么最后每个元素被选中的概率相等，为k/n；
具体的证明过程在面经上
*/
#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;
typedef vector<int> IntVec;
typedef typename IntVec::iterator iter;
typedef typename IntVec::const_iterator const_iter;
//返回m到n范围内的一个随机数
int randint(int m,int n)
{
	//如果前者比较大，交换
	if(m > n)
	{
		int t = m;
		m = n;
		n = t;
	}
	//得到n到m范围内的随机数
	int ret = m+ rand()%(n - m +1);
	return ret;
}

//蓄水池采样算法
bool sampling(const IntVec &input,IntVec &result,int m)
{
	//设置随机数种子
	srand(time(NULL));
	//如果输入数据流长度甚至没要抽取的m大，则直接返回false
	if(input.size() < m)
		return false;
	//重新设置输出的大小
	result.resize(m);
	const_iter iter = input.begin();
	//先顺序填满蓄水池
	for(int i = 0; i!=m;++i)
		result[i] = *iter++;
	//以逐渐减小的概率替换元素
	for(int i = m;iter != input.end();++i,++iter)
	{
		//因为i是从m开始，到input的长度结束，所以这个取随机数的范围从0-m，逐渐增加，一直到0-n，因此，取到m以内的随机数的概率越来越小，也就是
		//蓄水池内元素被替换的概率越来越小
		int j = randint(0,i);
		if(j < m)
			result[j] = *iter;
	}
	return true;
}

int main()
{
	int n = 100;
	const int m = 100;
	//
	cout<<"请数据流长度:"<<endl;
	cin>>n;
	IntVec input(n),result(m);
	for(int i = 0; i != n;++i)
		input[i] = i;
	//如果采样成功
	if(sampling(input,result,m))
	{
		for(int i = 0; i != m;++i)
			cout<<result[i]<<" ";
	}
	cout<<endl;
	return 0;
}

