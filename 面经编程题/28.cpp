/*
问题：中序遍历二叉树，要求空间复杂度为O（1）,统计遍历的每个节点的层次
思路：
1，如果当前节点的左孩子为空，那么输出当前节点，并将当前节点的右孩子设为新的 当前节点；
2，如果当前节点的左孩子非空，那么在当前节点的左子树中，找到当前节点在中序遍历下的前驱节点；在中序遍历中，即一直找右节点，在找到前驱节点之后
	a，如果前驱节点的右孩子为空，那么将 当前节点 设置为 前驱节点的右孩子，并把 当前节点的左孩子，设为新的当前节点
	b，如果前驱节点的右孩子为 当前节点，那么将前驱节点的右孩子重新设空（即恢复树的形状），然后输出当前节点，并将当前节点的右孩子设为新的当前节点
*/
#include<iostream>
using namespace std;
struct treenode
{
	int val;
	treenode *left,*right;
	treenode(int x):val(x),left(NULL),right(NULL){}
};
void *in_order_1_space(treenode *t)
{
	treenode *cur = t,*pre = NULL;
	while(cur != NULL)
	{
		if(cur->left == NULL)
		{
			cout<<cur->val<<" ";
			cur = cur->right;
		}
		else
		{
			//find pre node
			pre = cur->left;
			while(pre->right != NULL && pre->right != cur)
			{
				pre = pre->right;
			}
			//2a
			if(pre->right == NULL)
			{
				pre->right = cur;
				cur = cur->left;
			}
			else
			{
				pre->right = NULL;
				cout<<cur->val<<" ";
				cur = cur->right;
			}
		}
	}
	
}
int main()
{
	
	return 0;
}
