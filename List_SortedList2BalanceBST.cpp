struct BiTreeNode {
	int val;
	BiTreeNode* left;
	BiTreeNode* right;
	BiTreeNode() : val(0), left(nullptr), right(nullptr) {}
	BiTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	BiTreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* pre;

TreeNode* sortedListToBST(ListNode* head) {
    if (!head) return NULL;

    TreeNode* node = new TreeNode(-1);
    if (!head->next) {
        node->val = head->val;
        return node;
    }

    ListNode* mid = getMid(head);
    node->val = mid->val;

    if (mid->next) insertHead(mid->next, node);

    if (head != mid) {
        ListNode* nex = head;
        while (nex->next != mid) nex = nex->next;
        nex->next = NULL;

        insertHead(head, node);
    }


    return node;


}

void insertHead(ListNode* head, TreeNode* node) {

    ListNode* mid = getMid(head);

    if (mid) {
        insertTree(node, mid->val);

        if (mid->next) insertHead(mid->next, node);

        if (head != mid) {
            ListNode* nex = head;
            while (nex->next != mid) nex = nex->next;
            nex->next = NULL;

            insertHead(head, node);
        }
    }
    else insertTree(node, head->val);

}

void insertTree(TreeNode* node, int value) {
    if (value > node->val) {
        if (!node->right) {
            TreeNode* noderight = new TreeNode(value);
            node->right = noderight;
        }
        else insertTree(node->right, value);
    }
    else {
        if (!node->left) {
            TreeNode* nodeleft = new TreeNode(value);
            node->left = nodeleft;
        }
        else insertTree(node->left, value);
    }
}

ListNode* getMid(ListNode* head) {
    if (!head || !head->next) return NULL;
    ListNode* slow = head, * fast = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
