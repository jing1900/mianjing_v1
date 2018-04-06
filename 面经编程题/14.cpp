/*#include <iostream>
#include <algorithm>
using namespace std;

void fun3(int *a,int n)
{
    if (NULL==a || n<=1)
    {
        return;
    }
    int *p=a;
    int *q=a;
    int *pos=q;
    while(p<a+n)
    {
	//p指向的内容小于0，则往前合适的位置交换，否则，放着不同，p继续往右移
	//如果是负数，往前交换的话，再把交换后的数，跟交换到之前的数的下一个数交换，
        if (*p>0)
        {
            swap(*p,*q);
            pos=q;
            while(pos<p)
            {
                ++pos;
                swap(*pos,*p);
            }
            q++;
        }
        p++;
    }
}

int main()
{
    int data[6]={-1,1,15,-3,-5,-12};
    fun3(data,6);
    for (int i=0;i<6;i++)
    {
        cout<<data[i]<<" ";
    }
	return 0;
}
*/
/*
问题：一个数组中存在负数和正数，将正数换到前面，负数换到后面
思路：两个指针，不改变数组内元素的相对顺序，将正数换到前面
*/

#include<iostream>
#include<algorithm>
using namespace std;
void func(int *a, int n)
{
	//p,初始化为指向数组头元素，并依次走下去，直到数组尾
	int *p = a;
	//q,初始化为指向数组头元素，如果遇到需要交换的数，则往后移，否则不动
	int *q = a;
	//pos,指向q指针
	int *pos = q;
	while(p < a+n)
	{
		//如果指向的是正数，则需要交换到前面
		if(*p>0)
		{
			//将正数交换到前面
			swap(*p,*q);
			pos = q;
			//如果前面交换位置的索引仍小于后面交换位置的索引，前面交换位置往后挪一，再和p处元素交换
			if(pos < p)
			{
				++pos;
				swap(*pos,*p);
			}
			//q处已经是正数，往右挪1
			q++;
		}
		p++;
		
	}
}

int main()
{
	int a[] = {-1,1,15,-3,-5,-12};
	func(a,6);
	for(int i = 0; i < 6;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
