//最长公共子序列
//https://www.nowcoder.com/questionTerminal/c996bbb77dd447d681ec6907ccfb488a
class LCS {
public:
    int findLCS(string A, int n, string B, int m) {
        // write code here
        int table[n + 1][m + 1];//table长宽要加1
         
        for(int i = 0;i <= n;++i)table[i][0] = 0;//第0列和第0行初始化为0
        for(int i = 0;i <= m;++i)table[0][i] = 0;
         
        for(int i = 0;i < n;i++){//a[i] == b[j]，是条件1，否则是条件2,
            for(int j = 0;j < m;j++){
                if(A[i] == B[j])
                    table[i + 1][j + 1] = table[i][j] + 1;//这里注意，a[i],b[j]的公共子序列长度赋给table[i+1][j+1]
                else {
                    table[i + 1][j + 1] = max(table[i][j + 1],table[i + 1][j]);
                }
            }
        }
        return table[n][m];//返回的即a[n-1],b[m-1]整个序列的最长公共子序列
    }
};

