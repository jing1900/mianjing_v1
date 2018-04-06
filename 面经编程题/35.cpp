#include<iostream>
using namespace std;
struct tree
{
	int val;
	struct tree *l,*r;
	tree(int x):val(x),l(NULL),r(NULL){}
};
class TreetoSequence
{
	string toSequence(tree* root)
	{
		if(!root)
			return "";
		else
		{
			return "("+toSequence(root->l)+toSequence(root->r)+")";
		}
	}
};
int main()
{
	return 0;
}
