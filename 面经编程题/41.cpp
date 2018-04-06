//这个是中序遍历的非递归代码,先序的只需把cout语句挪到注释的地方即可
//测试：https://www.nowcoder.com/questionTerminal/4b91205483694f449f94c179883c1fef
#include<iostream>
#include<string>
#include<stack>
using namespace std;
int i;
string str;
struct tree
{
    char val;
    struct tree *l,*r;
    tree(char x):val(x),l(NULL),r(NULL){}
};
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

void inorderTraval(tree* root)
{
    if(!root)
        return;
    stack<tree*> s;
    tree *p = root;
    while(!s.empty() || p != NULL)
    {
        while(p!=NULL)
        {
            //cout<<p->val<<" ";
            s.push(p);
            p = p->l;
        }
        if(!s.empty())
        {
            p = s.top();
            cout<<p->val<<" ";
            s.pop();
            p = p->r;
        }
    }
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
