/*两棵树相加，对应位置两棵树都有值则相加，对应位置只有一颗数有值则取该值
*/
/*
考察的是二叉树的遍历，遍历每个节点，如果重叠，新节点便为两者和，不重叠，新节点为不为空的值，全为空到达底部跳出。然后用迭代的思想

*/

#include<iostream>
using namespace std;
struct treenode
{
	int val;
	treenode *left;
	treenode *right;
	treenode(int x):val(x),left(NULL),right(NULL){}
};
treenode* mergetree(treenode *t1,treenode *t2)
{
	if(t1 == NULL)
		return t2;
	if(t2 == NULL)
		return t1;
	t1->val += t2->val;
	t1->left = mergetree(t1->left,t2->left);
	t1->right = mergetree(t1->right,t2->right);
	return t1;
}
int main()
{
	return 0;
}

