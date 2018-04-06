/*
二叉树的递归创建，和递归前中后序遍历
https://www.nowcoder.com/questionTerminal/4b91205483694f449f94c179883c1fef
*/
#include<iostream>
#include<string>
using namespace std;
int i;
string str;
struct tree
{
    char val;
    struct tree *l,*r;
    tree(char x):val(x),l(NULL),r(NULL){}
};
//创建树
tree* createTree()
{
    char c = str[i++];
    if(c == '#')
        return NULL;
    tree* root = new tree(c);
    root->l = createTree();
    root->r = createTree();
    return root;
}
//中序，先序和后序只需调换下这个的顺序
void inorderTraval(tree* root)
{
    if(!root)
        return;
    inorderTraval(root->l);
    cout<<root->val<<" ";
    inorderTraval(root->r);
}

int main()
{
    while(cin>>str)
    {
        i = 0;
        tree* root = createTree();
        inorderTraval(root);
        cout<<endl;
    }
}
