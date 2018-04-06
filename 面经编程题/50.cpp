//二叉树的后序非递归
/*

将节点入栈，若左右子节点均无，直接访问，或者有左右节点，但都已访问过
否则，依次，将子节点按右左的顺序入栈，如此便可保证是先左后右再根的顺序打印。
*/
void postOrderTraval(treenode* root)
{
    if(!root)
        return;
    treenode* pre = NULL;
    treenode* cur;
    stack<treenode*> s;
    s.push(root);
    while(!s.empty())
    {
        cur = s.top();
        if((cur->l == NULL && cur->r == NULL) ||(pre != NULL &&(pre == cur->l || pre == cur->r)))
        {
            cout<<cur->val<<" ";
            s.pop();
            pre = cur;
        }
        else
        {
            if(cur->r !=NULL)
                s.push(cur->r);
            if(cur->l != NULL)
                s.push(cur->l);
        }
    }
}
