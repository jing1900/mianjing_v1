//杨氏矩阵中第k大数
//http://www.lintcode.com/zh-cn/problem/kth-smallest-number-in-sorted-matrix/
class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: An integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // write your code here
        
        priority_queue<pair<int, pair<int,int> >,vector<pair<int, pair<int,int> > >,greater<pair<int, pair<int,int> > > > q;//使用优先级队列
        
        const int m = matrix.size();//行数
        const int n = matrix[0].size();
        bool visted[m][n];
        memset(visted,0,m*n);//设置visted数组
        
        q.push(make_pair(matrix[0][0],make_pair(0,0)));//放入左上角的元素
        visted[0][0]= true;
        
        while(k--)//执行逻辑，判断k--是否大于0，是（执行while体内，k的值已经减1）。否（执行while之后的，k的值也已减1）
        {
            pair<int, pair<int,int> > now = q.top();
            int v = now.first;
            int i = now.second.first;
            int j = now.second.second;
            if(k == 0)
                return v;
            q.pop();
            if(i+1<m && !visted[i+1][j])
            {
                q.push(make_pair(matrix[i+1][j],make_pair(i+1,j)));
                visted[i+1][j]= true;
            }
            if(j+1<n &&!visted[i][j+1])
            {
                q.push(make_pair(matrix[i][j+1],make_pair(i,j+1)));
                visted[i][j+1] = true;
            }
        }
        
    }
};
