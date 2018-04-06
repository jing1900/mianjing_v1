/*
问题：大整数乘法
思路：分治
假设大整数x，y，位数为n
将x拆分为（A*10^n/2+B),y拆分为(C*10^n/2+D)
那么x*y = AC*10^n + (AD+BC)*10^n/2+BD
其中AD+BC = (A-B)(D-C)+AC+BD
故只需求AC，BD和(A-B)(D-C),再各自乘10的*次幂即可
*/

/*
该方法看似美好，却存在一些问题
1，时间复杂度降低的并不多
2，只能处理位数为偶数的情况
3，D-C后可能为负数，或者更改位数大小
*/
/*
#include<iostream>
#include<cmath>
using namespace std;
#define SIGN(x)((x>0)?1:-1)
//n为大整数位数
int mul(int x,int y,int n)
{
	//处理符号
	int sign = SIGN(x)*SIGN(y);
	x = abs(x);
	y = abs(y);
	//处理极端情况
	if(x == 0 || y == 0)
	{
		return 0;
	}
	else if(n == 1)
	{
		return sign*x*y;
	}
	else
	{
		//这里的n/2,如果是1.5的话，会自动转int，转为1，
		int A = (int)x/pow(10,(int)(n/2));
		int B = x - A*pow(10,(int)(n/2));
		int C = (int)y/pow(10,(int)(n/2));
		int D = y - C*pow(10,(int)(n/2));
		int AC = mul(A,C,(n/2));
		int BD = mul(B,D,n/2);
		int A_B_D_C = mul(A-B,D-C,n/2)+AC+BD;
		return sign*(AC*pow(10,n)+A_B_D_C*pow(10,n/2)+BD);
	}
}
int main()
{
	int n,x,y,r;
	cout<<"请输入大整数长度"<<endl;
	cin>>n;
	cout<<"请输入大整数1"<<endl;
	cin>>x;
	cout<<"请输入大整数2"<<endl;
	cin>>y;
	r = mul(x,y,n);
	cout<<"结果为："<<r<<endl;
	return 0;
}*/
/*
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
string multi(string x,string y)
{
	int n1 = x.length();
	int n2 = y.length();
	StringBuilder sb = new StringBuilder();
	int tem[] = new int[n1+n2];
	//从每个字符串的结尾，即个位开始，逐位相城，并存入
	//这里要利用一个神奇的性质，见表，i+y相等的处于同一列，应该累加计算结果
	for(int i = n1-1;i>=0;i--)
	{
		for(int j = n2-1;j>=0;j--)
		{
			tem[i+j+1] += (x.charAt(i)-'0')*(y.charAt(j)-'0');
		}
	}
	//计算每位的进位
	int carry = 0;
	for(int i = tem.length()-1;i>=0;i--)
	{
		//最开始的个位没有进位
		tem[i]+= carry;
		carry = tem[i] / 10;
		tem[i] = tem[i] % 10;
	}
	//计算从数组左边哪位开始
	int left = 0;
	while(left<temp.length-1&&tem[left] == 0)
		left++;
	for(;left<tem.length();left++)
		sb.append(tem[left]);
	return sb.toString();
}
*/
#include<iostream>
using namespace std;
string multi(string s1,string s2)
{
	//进位
	int carry = 0;
	//结果字符串
	string result(s1.size()+s2.size(),'0');
	for(int i = s1.size()-1;i>=0;--i)
	{
		//取s1中的数字，从个位到高位
		int a = s1[i]-'0';
		for(int j = s2.size()-1;j>=0;--j)
		{
			//取s2中的数字，从个位到高位
			int b = s2[j]-'0';
			//i+j相等的元素相乘，在同一列，需累加
			int c = result[i+j+1]-'0';
			//计算新的值，累加到c上
			int v = a*b+c+carry;
			//计算该位的值和进位
			result[i+j+1] = v%10 +'0';
			carry = v /10;
		}
		//这里如果还有进位的话，这里相当于放到result 的i+(j=0)+1 -1位置处，作为上一轮运算的进位
		if(carry)
		{
			result[i] = carry + '0';
			carry = 0;
		}
	}
	//这里i用来标记最开始有内容的位置
	int i = 0;
	while(i < result.size() && result[i] == '0')
		++i;
	return i==result.size()?"0":result.substr(i);
}
int main()
{
	string s1,s2;
	cout<<"请输入两个大数字，用空格隔开"<<endl;
	cin>>s1>>s2;
	string r= "";
	r = multi(s1,s2);
	cout<<r<<endl;
	return 0;
}
