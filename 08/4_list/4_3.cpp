/*https://leetcode.com/problems/linked-list-cycle-ii/description/
问题:单链表里是否有环？如果有起点是哪里？环长度是多大？  （最后一个节点next不是空，而是前面某个节点） (Leetcode 141, 142)

分析：方法1：用set存放每个被查找过得节点
    set<listNode*> have;
    for(;head;head = head->next)
    {
        if(have.find(head)!=have.end()) return ture;
        have.insert(head);
    }
    return false;

    方法2：但上面的方法存在一定的时间和空间复杂度。
    这里我们假设两个指针，p1,p2,p1一次走一步，p2一次走两步。如果有圈一定相遇，为什么呢？建议画图
    我们定义一些变量，首先圈长n，起点到圈起点的距离为a，即勺柄的长度，当p1到圈起点时，p2在圈中的位置为x(0<=x<n)
    假设相遇时距圈起点为b，那么p1走了a+b，p2走了a+b+k*n = 2(a+b) ,因此有a+b = k×n
    如何找圈的起点？
        把p1拉回起点，p2从相遇点（b)继续走,这时速率都是1步，a步后，p1到圈起点，p2也刚好到圈起点。
    如何找圈长？
        相遇后，p2再走一圈并统计长度就是圈长。比如p1不动，p2以1的速率走一圈，与p1相遇即是圈长
*/
//141,是否有环
/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        ListNode *walker = head;
        ListNode *runner = head;
        while(runner->next!=NULL &&runner->next->next!=NULL)
        {
            walker = walker->next;
            runner = runner->next->next;
            if(walker == runner)
                return true;
        }
        return false;
    }
};
//142,返回环起点和环长。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;//特殊情况
        ListNode *walker = head,*runner = head;
        bool iscycle = false;
        while(runner->next!=NULL && runner->next->next!=NULL)//判环，
        {
            walker = walker->next;
            runner = runner->next->next;
            if(walker == runner)
            {
                iscycle = true;
                break;
            }
        }
        if(iscycle)//有环，walker重新从起点出发，runner从相遇点出发，步速均为1，再相遇即为环起点。
        {
            for(walker = head;walker!=runner;walker= walker->next,runner = runner->next);
            return walker;
        }
        return NULL;//无环
    }
};