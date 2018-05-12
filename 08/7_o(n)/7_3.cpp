/*
问题：Leetcode 11 一个数组a[i]表示数轴上i的位置有一条高度为a[i]的竖直的线段，把两条线段当作一个容器左右边的高度，
问那两条线段组成的容器容积最大？
https://leetcode.com/problems/container-with-most-water/description/

分析：本质上是求max{min{a[i],a[j]}*(j-i)}, i<j
    思路:两头扫，i = 0,j = n-1,best = 0
    i<j
        best =max(best,min(a[i],a[j])*(j-i)
        if(a[i]<a[j]) i++;//i是较小的哪个，i++
        else j--;//j较小，j--

*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0,j =height.size()-1,best = 0;
        while(i<j)
        {
            best = max(best,min(height[i],height[j])*(j-i));//更新best
            if(height[i]<height[j]) i++;//更新索引，a[i]处小，i++
            else j--;//否则，j--
        }
        return best;
    }
};