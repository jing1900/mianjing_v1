/*
问题：已知给定的N个整数存在绝对众数，以最低的是空复杂度计算该绝对众数。

见2_5.cpp

分析：众数出现的次数大于所有其余数出现次数之和。因此，当你每次删除两个不同的数，众数不变
    为什么呢? 如果扔掉一个众数一个非众，不变。扔掉两个非众，仍不变。

    整体的思想就是，维护一个x，再来一个y，不同，则都丢掉。相同，则记录x出现的次数
    int count = 0,x;
    for(int i = 0;i<n;i++)//士兵守阵地的思想
    {
        if(count == 0) { x = a[i],count = 1;}//count为0了，更新x
        else if(x == a[i]) ++count;//相同，则计数++
        else --count;//不相同，则count--,表示丢掉了一个x，同时a[i]也没存贮
    }//最后x就是我们想要的

    注意，有些题目要数一下x的出现次数是否真的大于1半，

    拓展题：如何找到出现次数严格大于1/k的数？（众数是1/2）
        提示：保留k-1个数，来一个数，和这k-1个数比较，相同的话，对应count+1,不同，每个数出现的次数减1.
        如何维持这k-1个数，用hash or map?
*/