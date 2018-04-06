//判断一个数组是否是二叉搜索数的后序遍历结果
/*
二叉搜索树：最后一个为根节点，剩下的前部分小于根，后半部分大于根，即为二叉搜索树，
其中前后部分长度不一定相等，前后部分递归也是二叉搜索树
*/
//https://www.nowcoder.com/questionTerminal/a861533d45854474ac791d90e447bafd
class Solution {
public:
    bool judge(vector<int> s,int l, int r)
    {
        if(l>=r)
            return true;
	//从右往左，满足值大于根的最左节点索引
        int idx = r;
        while(idx>=l&&s[idx-1]>s[r])
            idx--;
	//遍历最左索引往左的部分，原本该都小于根，因此一旦发现大于根的，直接return false
        for(int i = idx-1; i>=l;i--)
        {
            if(s[i]>s[r])
                return false;
        }
	//递归左右部分，返回两者的结果的&&
        return judge(s,l,idx-1)&&judge(s,idx,r-1);
    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        int n = sequence.size();
        if(n == 0)
            return false;
        return judge(sequence,0,n-1);
    }
};
