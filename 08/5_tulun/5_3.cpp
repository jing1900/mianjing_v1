/*
问题：二叉树与链表转换，leetcode114
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
分析：二叉树的每个结点有两个指针，在不创建新结点的情况下，更改结点指针的指向可将二叉树转换为链表结构，
二叉树中的左右结点变为链表中的左右结点。使用两个每个结点的两个指针可转换为双链表结构，只使用每个结点的右指针可转换为单链表结构。
1、若要把二叉搜索树转换为排序的双向链表，只需中序遍历树中的每个结点，遍历的过程中始终保存已生成链表的最右端结点，
当遍历父亲结点的时候将父亲结点加入到左子树生成的链表的最右端结点的后面，
接着再遍历父亲结点的右子树，整个遍历完成后的最右端结点即是链表的最右端结点。
2.若要把一般二叉树转换为单链表结构，只需后序遍历每个结点，在遍历父亲结点的时候
将左子树形成的链表插入到父亲结点和右子树形成的链表中间。

右子树先跟得左子树转成的链，然后跟游子数
问题：链表转平衡二叉树 leetcode109
https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
*/

class Solution1 {
public:
    /*
    二叉树的每个结点有两个指针，在不创建新结点的情况下，更改结点指针的指向可将二叉树转换为链表结构，
    二叉树中的左右结点变为链表中的左右结点。使用两个每个结点的两个指针可转换为双链表结构，只使用每个结点的右指针可转换为单链表结构。
    1、若要把二叉搜索树转换为排序的双向链表，只需中序遍历树中的每个结点，遍历的过程中始终保存已生成链表的最右端结点，
    当遍历父亲结点的时候将父亲结点加入到左子树生成的链表的最右端结点的后面，
    接着再遍历父亲结点的右子树，整个遍历完成后的最右端结点即是链表的最右端结点。
    2.若要把一般二叉树转换为单链表结构，只需后序遍历每个结点，在遍历父亲结点的时候
    将左子树形成的链表插入到父亲结点和右子树形成的链表中间。
    */
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->left);
        flatten(root->right);
        if(root->left == NULL) return;

        //三方合并，将左子树形成的链表，插入到root和root->right之间
        TreeNode* p = root->left;
        while(p->right) p = p->right;//寻找左链表的最后一个节点
        p->right = root->right;
        root->right = root->left;
        root->left = NULL;//得到的结果为NULL root root->left pNode->right root->right
    }
};