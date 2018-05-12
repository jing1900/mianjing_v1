/*
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
问题：	给定二叉树前、中序遍历，构造二叉树 （Leetcode 105)

分析：首先，前序遍历的第一个节点是根节点x，
     然后在中序遍历中找到节点x，那么x左边序列为左子树的中序遍历，在前序遍历中对应长度的序列为左子树的前序遍历序列
     同样的，x右边的中序遍历为右子树的中序遍历，在前序遍历中对应长度的序列为右子树的前序遍历过程。
     然后递归该过程


*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder,inorder,0,0,preorder.size());
    }

private:
    TreeNode* dfs(vector<int>& preorder,vector<int>& inorder,int fromp,int fromi,int len)
    {
        if(len == 0) return NULL;
        TreeNode* root = new TreeNode(preorder[fromp]);
        int i;//在中序中找根节点的位置，定义在外边，是因为后面还要用
        for(i = fromi;inorder[i]!=preorder[fromp];i++);
        root->left = dfs(preorder,inorder,fromp+1,fromi,i-fromi);//左子树的前序开始位置，左子树的中序开始位置，和左子树的序列长度(根据中序来算)
        root->right =dfs(preorder,inorder,fromp+1+i-fromi,i+1,len-1-i+fromi);//建议画图
        return root;
    }
};