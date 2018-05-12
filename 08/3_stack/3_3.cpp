/*
问题：用两个堆栈实现一个队列

分析：s1负责入队，s2负责出队。入的话直接入s1,出的话如果s2非空，则先从s2出，否则，将s1全部元素亚入s2

push(x):O(1)
    s1.push(x);

pop(x):平均O(1)，因为每个元素出入两个栈各1次
    if(!s2.empty())
        s2.pop();
    else
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
*/