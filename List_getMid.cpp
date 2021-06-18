// 找到链表的中点
ListNode* getMid(ListNode* head) {
    if (!head || !head->next) return NULL;

    ListNode* slow = head, * fast = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}