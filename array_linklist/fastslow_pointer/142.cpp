

ListNode* detectCycle(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast !=NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) break;
    }
    // 上面的代码类似 hasCycle 函数
    if (fast == NULL || fast->next == NULL) {
        // fast 遇到空指针说明没有环
        return NULL;
    }

    // 重新指向头结点
    slow = head;
    // 快慢指针同步前进，相交点就是环起点
    while (slow != fast) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
