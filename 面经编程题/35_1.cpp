//二叉树的序列化和反序列化
//https://www.nowcoder.com/questionTerminal/cf7e25aa97c04cc1a68c8f040e71fb84
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
#include<vector>
class Solution {
    vector<int> buf;
    //序列化递归函数
    void dfs(TreeNode* p)
    {
        if(!p)
            buf.push_back(0x23333);
        else
        {
            buf.push_back(p->val);
            dfs(p->left);
            dfs(p->right);
        }
    }
    //非序列化递归函数
    TreeNode* dfs2(int* &p)
    {
        if(*p == 0x23333)
        {
            ++p;
            return NULL;
        }
        TreeNode* res = new TreeNode(*p);
        ++p;
        res->left = dfs2(p);
        res->right = dfs2(p);
        return res;
    }
public:
    char* Serialize(TreeNode *root) {   
        buf.clear();
        dfs(root);
        int* res = new int[buf.size()];
        for(unsigned int i = 0; i< buf.size();++i)
            res[i]=buf[i];
        return (char*)res;
        
    }
    TreeNode* Deserialize(char *str) {
        int *res = (int*)str;
        return dfs2(res);
    }
};
