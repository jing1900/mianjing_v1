/*https://leetcode.com/problems/copy-list-with-random-pointer/
问题：一个单链表除了next指针外还有一个random指针随机指向任何一个元素（可能为空），请复制它 (Leetcode 138)

分析：random指针指向随机一个固定的节点，但这个指向是没有规律的。

    一个比较好的解法如下：
    1,在每个旧节点的后面插入一个自身的副本
    2,复制randome指针
        一个旧节点a的副本为a->next;
        a->random的副本为a->random->next
        新节点的randome指针a->next->random = a->random->next;(空值单独判断）
    3,拆分：
        旧节点链表是奇数项，新节点链表是偶数项。

*/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /*
    	插入：每个旧节点后面插入一个自身的“复本”
		复制random指针
			一个旧节点a的复本是a->next
			a->random的复本是a->random->next
			新节点的random指针a->next->random ＝ a->random->next (空值单独判断）
		拆分
			旧节点链表是奇数项
			新节点链表是偶数项

    */
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;//特殊情况
        for(RandomListNode *now = head;now!=NULL;)//复制副本
        {
            RandomListNode *copy = new RandomListNode(now->label);
            copy->next = now->next;
            now->next = copy;
            now = copy->next;
        }
        for(RandomListNode *now = head;now!=NULL;now = now->next->next)//复制random指针
        {
            now->next->random = (now->random == NULL)?NULL:now->random->next;
        }
        RandomListNode *h = head->next,*t = h,*tail = head;//拆分,h为新复制链表的表头，t为新的链表的表尾，tail为旧的链表表尾
        for(;;)
        {
            tail = tail->next = t->next;//每次更新表尾,tail->next = t->next,因为t是tail的下一项，即副本（这里赋值时先执行右边的）
            if(tail == NULL)
                break;
            t = t->next = tail->next;//tail的下一项是t，
        }
        return h;
    }
};