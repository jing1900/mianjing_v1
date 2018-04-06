//排序的二数和
//https://www.nowcoder.com/questionTerminal/390da4f7a00f44bea7c2f3d19491311b
/*
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int i = 0;
        int j = array.size()-1;
        vector<int> res;
        //这道题的递增的特性决定我们可以这样做，
        while(i<j)
        {
            int s = array[i]+array[j];
            if(s == sum)
            {
                res.push_back(array[i]);
                res.push_back(array[j]);
                break;
            }
            else if(s<sum)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return res;
    }
};*/
//没排序的二数和，如果仅要元素本身，可以先排序再参照上述方法，但如果要索引，就用下面的方法
//http://www.lintcode.com/zh-cn/problem/two-sum/
#include<algorithm>
class Solution {
public:
    /**
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &numbers, int target) {
        // write your code here
        //排序后再输出，适合打印元素本身的题，而非打印下标的。这种情况下，我们可以用map
        vector<int> res;
        map<int,int> m;//前者存元素本身，后者存其下标+1
        for(int i = 0; i< numbers.size();i++)
        {
            if(m[target-numbers[i]]!= 0)
            {
                res.push_back(m[target-numbers[i]]-1);
                res.push_back(i);
                break;
            }
            else
            {
                m[numbers[i]] = i+1;
            }
        }
        return res;
    }
};
