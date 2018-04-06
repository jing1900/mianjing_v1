//三数和
//http://www.lintcode.com/en/problem/3sum/
#include<algorithm>
class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @return: Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int>> threeSum(vector<int> &a) {
        // write your code here
        //先排序，再参照排序后的2数和来求解
        sort(a.begin(),a.end());
        vector<vector<int> > res;
        for(int i = 0; i< a.size()-2;i++)//这里是三数和，i是三者中最小的那个，因此是size-2
        {
            if(i>0 && (a[i] == a[i-1])) continue;//避免拍完序后的重复情况
            int l = i+1;//左指针
            int r = a.size()-1;//右指针
            while(l<r)
            {
                int s = a[i] + a[l]+a[r];
                if(s<0) 
                    l++;
                else if(s>0) 
                    r--;
                else
                {
                    res.push_back(vector<int>{a[i],a[l],a[r]});
                    while(l+1<r&&(a[l+1] == a[l])) l++;
                    while(l<r-1&&(a[r-1] == a[r])) r--;
                    l++;
                    r--;
                }
            }
        }
        return res;
        
        
        
    }
};
