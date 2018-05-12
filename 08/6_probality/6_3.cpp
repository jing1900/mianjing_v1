/*
问题：一个随机数发生器，不均匀，以概率p产生0，以(1-p)产生1， (0<p<1),构造一个均匀的随机数发生器 （算法导论）

分析：将不均匀的随机数发生器发生两次，产生01和10的概率均为p(1-p),是均匀的了

*/
class Solution
{
public:
    int gen()
    {
        int x,y;
        while((x = rand()) == (y=rand()));//产生00,11时继续重新产生。
        return x;//只有x=0，y=1和x=1,y=0两种情况，等概率。
    }
};