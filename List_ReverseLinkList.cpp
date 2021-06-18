ListNode* reverseLink(ListNode* node) {
    if (!(node->next)) return node;
    ListNode* nex = reverseLink(node->next);
    nex->next = node;
    return node;
}

ListNode* reverseList(ListNode* head) {
    if (!head) return head;
    if (!(head->next)) return head;

    ListNode* last = head;
    while (last->next) last = last->next;

    ListNode* first = reverseLink(head);
    first->next = NULL;

    return last;
}