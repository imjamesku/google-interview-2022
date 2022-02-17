

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *cur = head;
        for (int i = 0; i < n; i++) {
            cur = cur->next;
        }
        ListNode *prev = nullptr;
        ListNode *slow = head;
        while (cur != nullptr) {
            cur = cur->next;
            prev = slow;
            slow = slow->next;
        }
        if (prev == nullptr) {
            return slow->next;
        }
        prev->next = prev->next->next;
        return head;
    }
};