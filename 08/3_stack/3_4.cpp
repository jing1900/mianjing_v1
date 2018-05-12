/*
问题：支持查找最小元素的堆栈：一个堆栈除了支持push, pop以外还要支持一个操作getMin得到当前堆栈里所有元素的最小值

分析：方法1（笨方法）：用两个堆，1个正常使用，另一个一直是空，
    getmin的时候，将s1的元素一个一个弹出到s2,每弹出一个，顺便求当前的最小值，然后再从s2将元素一个一个倒回s1, O(n)

    方法2：还是两个堆，一个维护原来的值，s2维护当前最小值（它们元素个数一样多）

    push(x):O(1)
        s1.push(x)
        if(!s2.empty()&&s2.top()<x) s2.push(s2.pop());//如果非空，且x大于s2栈顶，那么直接push栈顶
        else s2.push(x);//否则push x

    pop():O(1)
        s1.pop();
        s2.pop();

    getMin():O(1);
        return s2.top();

    方法3：s2没必要放一样多的元素
    push(x):
        s1.push(x);
        if(s2.empty()|| x<=s2.top()) s2.push(x);//这里为何要等于的时候也放，是因为下面我们看到，pop最小值的情况下要出栈。

    pop():
        if(s1.top() == s2.top()) s2.pop();//pop最小值的情况下，s2也pop
        s1.pop();
*/