//https://www.nowcoder.com/questionTerminal/abc3fe2ce8e146608e868a70efebf62e
//二维数组查找
class Solution {
public:
    /*
    思路：从右上角开始比，如果大于target，则列数减1，若小于target，则行数+1，若等于，，返回true
    */
    bool Find(int target, vector<vector<int> > array) {
            int row_num = array.size();
            int column_num = array[0].size();
            if(row_num == 0 or column_num == 0)
                return false;
            int i = 0,j = column_num -1;
            while(i < row_num && j >= 0)
            {
                if(array[i][j] > target)
                {
                    j--;
                    continue;
                }
                else if(array[i][j] < target)
                {
                    i++;
                    continue;
                }
                else
                    return true;
            }
            return false;
            
    }
};
