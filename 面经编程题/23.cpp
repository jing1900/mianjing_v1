/*多位数用链表存贮，如123用1->2->3存贮，实现相加功能*/
/*这里假定链表中的内容是从各位开始存放的，返回的结果也为链表*/
/*
#include<iostream>
using namespace std;
//定义结构体
struct listnode
{
	int val;
	listnode *next;
	listnode(int x):val(x),next(NULL){}
};

listnode* add2num(listnode *l1,listnode *l2)
{
	//ret是返回链表的头节点，这里我们打算把相加后的值，放入链表1，
	//pre用来标记待计算节点的上一个节点，即计算完的最先节点。
	listnode *ret = l1,*pre = l1;
	int up = 0;//进位
	//顺序计算每个对应位相加的值
	while(l1 != NULL && l2 !=NULL)
	{
		l1->val = l1->val + l2->val + up;
		up = l1->val / 10;
		l1->val %= 10;
		pre = l1;
		l1 = l1->next;
		l2 = l2->next;
	}
	//处理其中一个链表结束了的情况
	if(l1->next == NULL)
	{
		pre->next = l2;
	}
	l1 = pre->next;
	while(l1 != NULL)
	{
		l1->val = l1->val + up;
		up = l1->val /10;
		l1->val %= 10;
		pre = l1;
		l1 = l1->next;
	}
	if(up != 0)
	{	
		listnode *temp = new listnode(up);
		pre->next = temp;
	}
	//ret最后指向的是链表1的头
	return ret;
}
int main()
{
	listnode *l1 = new listnode(1);
	listnode *l2 = new listnode(2);
	l1->next = l2;
	l2->next = NULL;
	listnode *l3 = new listnode(9);
	listnode *l4 = new listnode(8);
	l3->next = l4;
	l4->next = NULL;
	listnode *l3,*l4;
	l3->val = 2;
	l3->val = 8;
	l1->next = l3;
	l2->next = l4;
	l3->next = NULL;
	l4->next = NULL;
//	cout<<(l1->next)->val<<endl;
//	cout<<(add2num(l1,l3))->val<<endl;
//	add2num(l1,l3);
	add2num(l1,l3);
	return 0;
}*/
/*
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1 == NULL || l2 == NULL) return (l1 == NULL) ? l2 : l1;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int carry = 0,num;
        ListNode* res = new ListNode(-1);
        ListNode* p = res;
        while(p1 != NULL || p2 != NULL || carry) {
            num = (p1 ? p1->val : 0) + (p2 ? p2->val : 0) + carry;
            carry = num >= 10 ? 1 : 0;
            num %= 10;
            ListNode* tmp = new ListNode(num);
            p->next = tmp;
            p = p->next;
            if(p1) p1 = p1->next;
            if(p2) p2 = p2->next;
        }
        return res->next;
    }
};
*/
#include<iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};
class Solution
{
public:
	ListNode *add2num(ListNode *l1,ListNode *l2)
	{
		//如果有一个以上为空，直接返回即可
		if(l1 == NULL || l2 == NULL) return (l1 == NULL)?l2:l1;
		ListNode *p1 = l1;
		ListNode *p2 = l2;
		//进位
		int carry = 0, num;
		//存贮运算结果的链表
		ListNode *ret = new ListNode(-1);
		ListNode *p = ret;
		//只要链表1,2，或者carry有一个非空，就要while下去
		while(p1!=NULL ||p2 != NULL||carry)
		{
			//计算结果和进位
			num = (p1?p1->val:0)+(p2?p2->val:0)+carry;
			carry = num>=10?1:0;
			num %= 10;
			//新建存贮节点，并移动对应指针
			ListNode *temp = new ListNode(num);
			p->next = temp;
			p = p->next;
			//指向链表1,2的指针往后挪
			if(p1) p1= p1->next;
			if(p2) p2 = p2->next;
		}
		return ret->next;
	}
};

int main()
{
	Solution s;
	return 0;
}
