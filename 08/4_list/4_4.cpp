/*https://leetcode.com/problems/intersection-of-two-linked-lists/description/
问题：两个链表找交点 单向链表找交点 (Leetcode 160)

分析:可以理解为y字形，一个链表长x，一个链表长y，x>=y.
    方法1：让第一个链表先走x-y步，再一起走，每步判断是否相交即可。
    方法2：如下，先一起走，当一方为空，便指向另一条的头节点，如此，来抵消长度差距。
*/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1=headA,*p2 = headB;
        if(p1 == NULL || p2==NULL ) return NULL;//特殊情况
        while(p1!=NULL&&p2!=NULL&&p1!=p2)//都非空且没相遇
        {
            p1=p1->next;
            p2 = p2->next;
            if(p1 == p2) return p1;//相遇返回节点
            if(p1==NULL) p1 = headB;//为空，p1指向另一条的头节点
            if(p2 == NULL) p2= headA;
        }
        return p1;
    }
};