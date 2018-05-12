/*
问题：在单链表中插入/删除一个节点

分析：一般链表这种推荐画图。
    1,插入：首先哪些指针需要修改？插入位置之前的节点的next（指向插入节点),插入节点的next（指向之前节点的下一个节点）
    特殊情况：在head之前插入（包括head == NULL)
        now->next = head;
        head = now;
    一般情况：
        now->next = pre->next;
        pre->next = now;

    2,删除：首先哪些指针需要修改？前驱的next
    特殊情况：删除head
        temp = head->next;
        delete head;
        head = temp;
    一般情况：
        temp = pre->next;
        pre->next = temp->next;
        delete temp;

    思考题：双向链表的插入删除
           循环有序的插入删除（建议先断开，再连上）

*/