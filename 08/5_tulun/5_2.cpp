/*
问题1：	(Leetcode 124) 二叉树每个节点有一个整数，返回和最大的路径。
https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

分析：这个最大路径有三种可能：
    左子树延伸下去的最大路径，右子树延伸下去的最大路径，和通过根节点的路径

问题2：	二叉树最小深度 （从根到叶子最小经过的节点数）(Leetcode  111) 注意空子树
https://leetcode.com/problems/minimum-depth-of-binary-tree/description/

问题3：  判断平衡（a binary tree in which the depth of the two subtrees of
every node never differ by more than 1.），leetcode110
https://leetcode.com/problems/balanced-binary-tree/description/

问题4：  最大深度 leetcode104
https://leetcode.com/problems/maximum-depth-of-binary-tree/description/


问题5：  判断相同 leetcode100
https://leetcode.com/problems/same-tree/description/

问题6：  判断对称 leetcode101
https://leetcode.com/problems/symmetric-tree/description/

问题7：  判断二叉搜索 leetcode 98
https://leetcode.com/problems/validate-binary-search-tree/description/
有很多种方法，一种简单的思路是判断其中序遍历的结果是否是有序的，即可
并且无需存这个序列，只要当前值比上一个大即可。
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
class Solution1 {
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return NULL;
        int res = root->val;
        dfs(root,res);
        return res;//注意，这里返回的是参数res，而非dfs的返回值
    }
private:
    int dfs(TreeNode *root,int &m)//m传的引用,dfs的返回值为该条路上的最大值，而m为全局最大值
    {
        if(!root) return 0;
        int left = dfs(root->left,m);
        int right = dfs(root->right,m);
        int ret = max(max(left,right),0)+root->val;//左右子树延伸下去的最大路径
        m = max(max(m,ret),left+right+root->val);//左右子树延伸下去的最大路径，原来的m和l+r+root三者的最大值为，全局的
        return ret;
    }
};

class Solution2 {
public:
    //这里需注意的一点是如果左子树为空，那么它最小高度为右子树的高度，而非是1（只包含根节点）
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(root->left)
        {
            if(root->right)
                return min(minDepth(root->left),minDepth(root->right))+1;//左右子树都存在
            else//只有左子树
                return minDepth(root->left) +1;
        }
        else if(root->right)//左不在，右在
            return minDepth(root->right)+1;
        else//左不在，右不在
            return 1;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution3 {
public:
    bool isBalanced(TreeNode* root) {
        int h;//树高
        return help(root,h);
    }
private:
    bool help(TreeNode* root,int &h)
    {
        if(root == NULL)
        {
            h = 0;
            return true;
        }
        int h1,h2;
        if(!help(root->left,h1))//如果左子树非平衡
            return false;
        if(!help(root->right,h2))//如果右子树非平衡
            return false;
        h = max(h1,h2)+1;//更新树高
        return (h1>=h2-1)&&(h1<=h2+1);//这个条件很微妙
    }
};

class Solution4 {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};

class Solution5 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL || q ==NULL) return p == q;
        return (p->val == q->val) &&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);

    }
};

class Solution6 {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return help(root->left,root->right);
    }
private:
    bool help(TreeNode* r1,TreeNode* r2)
    {
        if(r1 == NULL || r2 == NULL) return r1 == r2;
        return (r1->val == r2->val)&&help(r1->left,r2->right)&&help(r1->right,r2->left);//注意，是对称，轴对称
    }
};

class Solution7 {
public:
    bool isValidBST(TreeNode* root) {
        bool mask = true;//是否为第一次访问的节点
        int val = 0;//中序遍历上一个值
        return help(root,mask,val);
    }
private:
    bool help(TreeNode* root,bool &first,int &last)
    {
        if(!root) return true;
        if(!help(root->left,first,last))//若左子树非，false
            return false;
        if(first)//如果左子树为空，那么first就是true，表示一个元素都没访问过，root为访问的第一个节点，更新first为false表示已经访问过节点了
        {
            first = false;
            last = root->val;
        }
        else if(last>= root->val)//first为false，说明左子树的确已经遍历过一些点了，那么last是有意义的，那么判断当前值与前值是否有序
            return false;
        last = root->val;//如果是有序的，上一个值就变成了root->val
        return help(root->right,first,last);//再遍历右子树就可以了

    }
};
