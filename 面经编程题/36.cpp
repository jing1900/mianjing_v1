//二叉树的按层遍历
//https://www.nowcoder.com/questionTerminal/7fe2212963db4790b57431d9ed259701
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
#include<queue>
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            res.push_back(q.front()->val);
            if(q.front()->left != NULL)
                q.push(q.front()->left);
            if(q.front()->right != NULL)
                q.push(q.front()->right);
            q.pop();
        }
        return res;
    }
};
