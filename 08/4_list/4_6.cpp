/*
问题：	链表里存放整数，给定x把比x小的节点放到x之前  (Leetcode 86)
https://leetcode.com/problems/partition-list/description/
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
    //思路，维持两个链表，再合并即可
    ListNode* partition(ListNode* head, int x) {
        ListNode node1(0),node2(0);//两个链表前面的那个节点
        ListNode *p1 = &node1,*p2 = &node2;//指向两个链表的指针
        while(head)
        {
            if(head->val<x)
            {
                p1->next = head;
                p1 = p1->next;
            }
            else
            {
                p2->next = head;
                p2= p2->next;
            }
            head = head->next;
        }
        //将两个链表链接起来
        p2->next = NULL;
        p1->next = node2.next;
        return node1.next;
    }
};