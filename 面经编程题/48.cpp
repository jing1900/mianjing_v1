/*各种排序算法*/

#include<iostream>
using namespace std;
void Sort(int a[], int low ,int high);
int Patition(int a[],int low,int high);
/*
插入排序，假设该元素之前的所有元素都已经按从小到大排好序了，现在的任务就是把该元素插入合适的位置
*/
void insertSort(int a[],int n)
{
	for(int i = 1; i < n;i++)
	{
		//需要往前插入排序的情况
		if(a[i] < a[i-1])
		{
			int x = a[i];//待排序内容
			int j = i-1;
			//元素一直大于待排序内容，就一直往左挪
			while(j >= 0 && a[j]>x)
			{
				a[j+1] = a[j];//腾位置
				j--;
			}
			a[j+1] = x;
		}
	}
}

/*
冒泡排序：不断比较相邻元素，小的在前，大的在后，直到结尾，下一轮，只需比较前n-1个
改进，可以加入一个flag标记，如果在某轮比较过程中，发现所有的元素都已经是有序的了，就没必要继续进行往前个数-1的迭代，break掉即可
*/
#这个flag位还存在一些问题
void bubbleSort(int a[],int n)
{
	//新增的flag位
//	int flag = 0;
	int j = n-1;
	while(j>0)
	{
//		cout<<j<<" ";
		for(int i =1 ; i<= j;i++)
		{
			//每轮比较开始前，置flag=0,
//			flag = 0;
			if(a[i]<a[i-1])
			{
				int temp = a[i-1];
				a[i-1] = a[i];
				a[i] = temp;
				//如果有需交换元素
//				flag = 1;
			}
		}
//		if(flag == 0)
//			break;
		//cout<<j<<" ";
		j--;
	}
}
/*
快速排序：思想，选一个基准，将小于它的放左边，大于的放右边，再挨个对左右两边迭代这个过程，基准一般选第一个数or 最后一个
*/
void quickSort(int a[],int n)
{
	Sort(a,0,n-1);
}
void Sort(int a[], int low ,int high)
{
	//这里必须加一个low<high的界定
	if(low <high)
	{
		int n;//支点
		n = Patition(a,low,high);//结束后，支点处元素是排好序的，其左边的都比它小，右边的都比它大
		Sort(a,low,n-1);
		Sort(a,n+1,high);
	}
}
int Patition(int a[],int low,int high)
{
	int base = a[low];
	while(low < high)
	{
		//从右往左走，如果满足大于base的条件，一直往左，直到不满足，将其换至low处，不用担心low处元素被覆盖，因为base就是存的它
		while(low<high && a[high]>=base)
			high--;
		a[low] = a[high];
		//从左往右走，扫描左边的
		while(low <high && a[low]<=base)
			low++;
		a[high] = a[low];
		//这个过程中low和high不断往中间移，重叠时，意味着左右都交换好了
	}
	//结束时，low，high重合，此处应该放base
	a[low] = base;
	return low;//此处为支点位置
}
int main()
{
	cout<<"请输入数组长度:";
	int n;
	cin>>n;
	int *a =  new int[n];
	for(int i = 0; i <n;i++)
		cin>>a[i];
	bubbleSort(a,n);
	for(int i = 0; i <n ;i++)
		cout<<a[i]<<" ";
	delete []a;
}
