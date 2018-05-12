/*
问题：单链表的反转

分析：维持pre now next三个指针即可

思考题：反转m到n之间的部分，leetcode92
        每k个反转一次 leetcode25
*/

class Solution {
public:
    //二叉链表的翻转，有递归和非递归两种实现
    /*
    递归版本：需要维护三个指针，pre，head(当前节点),next
    不断更新三者的值，并将head的next指向pre即可。*/
     
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        while(head)
        {
            ListNode* next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;//这里肯定要返回pre，因为最后head = next为空时跳出while。
    }
    /*递归版本
    递归结束条件，递归处理head->next（以当前节点的下一个节点开始的后面部分）,reverse当前节点head和它的next节点。*/
    ListNode* reverseList(ListNode* head) {
       if(!head || !(head->next))
           return head;//递归停止条件
        ListNode *node = reverseList(head->next);
        (head->next)->next = head;
        head->next =NULL;
        return node;
    }
     
};
