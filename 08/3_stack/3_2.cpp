/*
问题：如何用两个队列实现一个堆栈？

分析：两个队列来回倒，保证一个队列是空的，用空队列来存贮除队尾外的所有元素

    比如，q1非空，q2为空，要出栈，实际上要出的是q1的最后一个元素，我们将q1的元素一个一个放入q2,剩下最后一个，让其出队即可。

    入栈：push(x): O(1)
        if(!q1.empty()) q1.push(x);
        else q2.push(x)
    出栈：pop():O(N)
        if(!q1.empty())
        {
            while(q1.size()>1)//剩最后一个元素
            {
                q2.push(q1.front());
                q1.pop();
            }
            q1.pop();
        }
        else
        {
            while(q2.size()>1)//剩最后一个元素
            {
                q1.push(q2.front());
                q2.pop();
            }
            q2.pop();
        }
*/