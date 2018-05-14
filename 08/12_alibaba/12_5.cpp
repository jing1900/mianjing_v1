/*
问题：有一个函数int getNum()，每运行一次可以从一个数组V[N]里面取出一个数，N未知，当数取完的时候，函数返回NULL。
现在要求写一个函数int get()，这个函数运行一次可以从V[N]里随机取出一个数，而这个数必须是符合1/N平均分布的，
也就是说V[N]里面任意一个数都有1/N的机会被取出，要求空间复杂度为O（1）。（数据结构与算法）

分析：蓄水池抽样算法

每个数，以1/i的概率选择它。这样每个被选择且不被替换的概率都是1/n

*/