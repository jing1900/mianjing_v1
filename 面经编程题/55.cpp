//单链表的翻转
//https://www.nowcoder.com/questionTerminal/75e878df47f24fdc9dc3e400ec6058ca?toCommentId=1205394
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL)
            return NULL;
        else
        {
            ListNode* pre = pHead;
            ListNode* p = pHead->next;
            pre->next = NULL;//先将第一个节点的next置NULL，是尾节点
            while(p!=NULL)
            {
                //pre 和p不断往后走,
                
                pre = p;
                p = p->next;
                //phead在被指向完后，也跟着往后走
                pre->next = pHead;
                pHead = pre;
            }
        }
        return pHead;//此时phead指向原链表的最后一个元素
    }
};


