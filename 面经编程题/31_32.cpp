/*二分查找有序序列
https://www.nowcoder.com/questionTerminal/28d5a9b7fc0b4a078c9a6d59830fb9b9
*/
#include<iostream>

class BinarySearch{
public:
    int getPos(vector<int> A,int n, int val)
    {
        if(A.size() == 0 or n == 0)
            return -1;
        int L = 0;
        int R = n-1;
        int mid = 0;
        while(L<R)
        {
            mid = L + (R-L)/2;
            if(A[mid]<val)
                L = mid+1;
            else if(A[mid] >val)
                R = mid-1;
            else
                R = mid;
        }
        if(A[L] == val)
            return L;
        return -1;
    }
};
